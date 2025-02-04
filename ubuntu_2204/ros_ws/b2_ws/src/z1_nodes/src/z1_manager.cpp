#include "unitree_arm_sdk/control/unitreeArm.h"
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>
#include <string>
#include <vector>
#include "z1_interfaces/msg/arm_control_command.hpp"
#include "z1_interfaces/srv/gripper_command.hpp"
#include "z1_interfaces/srv/move_circular_path_command.hpp"
#include "z1_interfaces/srv/move_linear_path_command.hpp"
#include "z1_interfaces/srv/move_joint_path_command.hpp"
#include "z1_interfaces/srv/no_input_command.hpp"

using namespace std::chrono_literals;
using namespace UNITREE_ARM;

class arm_sdk_manager
{
public:
    arm_sdk_manager() : commandThread() {}

    // Inicia a comunicação com o controlador
    void startUDPConnection()
    {
        const char *command = "cd /z1_controller/build; sudo ./z1_ctrl";
        int result = system(command);

        if (result == 0)
        {
            std::cout << "[INFO] z1_ctrl started" << std::endl;
        }
        else
        {
            std::cerr << "[ERROR] z1_ctrl not started" << std::endl;
        }
    }

    void startRecVConnection()
    {
        arm->sendRecv();
    }

    void setUDPConnection()
    {
        // Inicia a thread de comunicação
        commandThread = std::thread(&arm_sdk_manager::startUDPConnection, this);
        //responseThread = std::thread(&arm_sdk_manager::startRecVConnection, this);

        ctrlComp.dt = 0.002; // 500Hz
        ctrlComp.udp = new UDPPort("127.0.0.1", 8071, 8072, RECVSTATE_LENGTH, BlockYN::NO, 500000);
        ctrlComp.armModel = new Z1Model();
        ctrlComp.armModel->addLoad(0.03);
        arm = new unitreeArm(&ctrlComp);

        arm->sendRecvThread->start();
        arm->setFsm(ArmFSMState::PASSIVE);
        arm->setFsm(ArmFSMState::BACKTOSTART);
        arm->setWait(false);
    }

    ~arm_sdk_manager()
    {
        if (commandThread.joinable())
        {
            commandThread.join();
        }

        if (responseThread.joinable())
        {
            responseThread.join();
        }
        delete arm;
    }
    CtrlComponents ctrlComp;
    unitreeArm *arm;
    std::thread commandThread;
    std::thread responseThread;
};

/*
Nó para gerenciar o SDK do Z1
*/
class Z1ManagerNode : public rclcpp::Node
{
public:
    Z1ManagerNode()
        : Node("z1_manager_node"), z1(new arm_sdk_manager())
    {
        // Publisher
        publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("z1_joint_states", 10);

        // Subscriber
        subscription_ = this->create_subscription<z1_interfaces::msg::ArmControlCommand>( 
            "z1_control"
            , 10, std::bind(&Z1ManagerNode::control_callback, this, std::placeholders::_1));

        // Services
        backToStart_service_ = this->create_service<z1_interfaces::srv::NoInputCommand>(
            "z1_back_to_start"
            ,std::bind(&Z1ManagerNode::back_to_start_callback, this, std::placeholders::_1, std::placeholders::_2));

        setZero_service_ = this->create_service<z1_interfaces::srv::NoInputCommand>(
            "z1_set_zero"
            ,std::bind(&Z1ManagerNode::set_zero_callback, this, std::placeholders::_1, std::placeholders::_2));

        setPassive_service_ = this->create_service<z1_interfaces::srv::NoInputCommand>(
            "z1_set_passive"
            ,std::bind(&Z1ManagerNode::set_passive_callback, this, std::placeholders::_1, std::placeholders::_2));
            
        moveGripper_service_ = this->create_service<z1_interfaces::srv::GripperCommand>(
            "z1_move_gripper"
            ,std::bind(&Z1ManagerNode::gripper_control_callback, this, std::placeholders::_1, std::placeholders::_2));

        moveJointPath_service_ = this->create_service<z1_interfaces::srv::MoveJointPathCommand>(
            "z1_move_joint_path"
            ,std::bind(&Z1ManagerNode::move_joint_path_callback, this, std::placeholders::_1, std::placeholders::_2));

        moveLinearPath_service_ = this->create_service<z1_interfaces::srv::MoveLinearPathCommand>(
            "z1_move_linear_path"
            ,std::bind(&Z1ManagerNode::move_linear_path_callback, this, std::placeholders::_1, std::placeholders::_2));

        moveCircularPath_service_ = this->create_service<z1_interfaces::srv::MoveCircularPathCommand>(
            "z1_move_circular_path"
            ,std::bind(&Z1ManagerNode::move_circular_path_callback, this, std::placeholders::_1, std::placeholders::_2));

        // Configura timer para publicar os estados
        timer_ = this->create_wall_timer(
            1ms, std::bind(&Z1ManagerNode::publish_joint_states, this));

        // Configura comunicação UDP com o braço
        z1->setUDPConnection();
    }

    ~Z1ManagerNode()
    {
        delete z1;
    }

private:
/*
Serviços
*/
    // Voltar para o inicio
    void back_to_start_callback(const std::shared_ptr<z1_interfaces::srv::NoInputCommand::Request> request,
                                    std::shared_ptr<z1_interfaces::srv::NoInputCommand::Response> response)
    {
        try
        {
            z1->arm->backToStart();
            response->success = true;
            response->message = "Back to start.";
        }
        catch (const std::exception &e)
        {
            request; //Aqui so para evitar avisos no console
            response->success = false;
            response->message = "Error getting back to start.";
            RCLCPP_ERROR(this->get_logger(), "Failed to get back to start: %s", e.what());
        }
    }

    // Ajustar origem
    void set_zero_callback(const std::shared_ptr<z1_interfaces::srv::NoInputCommand::Request> request,
                                std::shared_ptr<z1_interfaces::srv::NoInputCommand::Response> response)
    {
        try
        {
            z1->arm->calibration();
            response->success = true;
            response->message = "Back to start.";
        }
        catch (const std::exception &e)
        {
            request; //Aqui so para evitar avisos no console
            response->success = false;
            response->message = "Error getting calibrating.";
            RCLCPP_ERROR(this->get_logger(), "Failed to calibrate: %s", e.what());
        }
    }

    // Ajustar para passivo
    void set_passive_callback(const std::shared_ptr<z1_interfaces::srv::NoInputCommand::Request> request,
                                    std::shared_ptr<z1_interfaces::srv::NoInputCommand::Response> response)
    {
        try
        {
            z1->arm->setFsm(ArmFSMState::PASSIVE);
            response->success = true;
            response->message = "Passive state.";
        }
        catch (const std::exception &e)
        {
            request; //Aqui so para evitar avisos no console
            response->success = false;
            response->message = "Error getting passive.";
            RCLCPP_ERROR(this->get_logger(), "Failed to be passive: %s", e.what());
        }
    }

    // Move em um caminho de junta
    void move_joint_path_callback(const std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand::Request> request,
                                std::shared_ptr<z1_interfaces::srv::MoveJointPathCommand::Response> response)
    {
        try
        {
            // if(z1->arm->_ctrlComp->recvState.state != ArmFSMState::MOVEJ)
            // {
            //     z1->arm->setFsm(ArmFSMState::MOVEJ);
            // }

            // Verifica a consistência dos dados recebidos
            if (request->posture.size() != 6) {
                RCLCPP_ERROR(this->get_logger(), "Invalid posture vector size. Expected 6 elements.");
                return;
            }

            // Converte os dados para os tipos esperados
            Vec6 posture = Vec6::Zero();
            std::copy(request->posture.begin(), request->posture.end(), posture.data());

            double gripperPos = request->gripper_pos;
            double maxSpeed = request->max_speed;

            // Invoca o comando para controlar o braço num caminho de juntas
            z1->arm->MoveJ(posture, gripperPos, maxSpeed);


            std::ostringstream posture_str;
            posture_str << "[";
            for (int i = 0; i < posture.size(); ++i) {
                posture_str << posture(i);
                if (i != posture.size() - 1) {
                    posture_str << ", ";
                }
            }
            posture_str << "]";

            // Define a resposta
            response->success = true;
            response->message = "Arm moved to " + posture_str.str();
        }
        catch (const std::exception &e)
        {
            response->success = false;
            response->message = "Error moving.";
            RCLCPP_ERROR(this->get_logger(), "Failed to move: %s", e.what());
        }
    }

    //Move em um caminho linear
    void move_linear_path_callback(const std::shared_ptr<z1_interfaces::srv::MoveLinearPathCommand::Request> request,
                                std::shared_ptr<z1_interfaces::srv::MoveLinearPathCommand::Response> response)
    {
        try
        {
            if(z1->arm->_ctrlComp->recvState.state != ArmFSMState::MOVEL)
            {
                z1->arm->setFsm(ArmFSMState::MOVEL);
            }

            // Verifica a consistência dos dados recebidos
            if (request->posture.size() != 6) {
                RCLCPP_ERROR(this->get_logger(), "Invalid posture vector size. Expected 6 elements.");
                return;
            }

            // Converte os dados para os tipos esperados
            Vec6 posture = Vec6::Zero();
            std::copy(request->posture.begin(), request->posture.end(), posture.data());

            double gripperPos = request->gripper_pos;
            double maxSpeed = request->max_speed;

            // Invoca o comando para controlar o braço num caminho linear
            if(gripperPos<-6.2831 || gripperPos>=0.0)
            {
                z1->arm->MoveL(posture, gripperPos, maxSpeed);
            }
            else
            {
                z1->arm->MoveL(posture, maxSpeed);
            }
            std::ostringstream posture_str;
            posture_str << "[";
            for (int i = 0; i < posture.size(); ++i) {
                posture_str << posture(i);
                if (i != posture.size() - 1) {
                    posture_str << ", ";
                }
            }
            posture_str << "]";

            // Define a resposta
            response->success = true;
            response->message = "Arm moved to " + posture_str.str();
        }
        catch (const std::exception &e)
        {
            response->success = false;
            response->message = "Error moving.";
            RCLCPP_ERROR(this->get_logger(), "Failed to move: %s", e.what());
        }
    }

    // Move em um caminho circular
    void move_circular_path_callback(const std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand::Request> request,
                                std::shared_ptr<z1_interfaces::srv::MoveCircularPathCommand::Response> response)
    {
        try
        {
            if(z1->arm->_ctrlComp->recvState.state != ArmFSMState::MOVEC)
            {
                z1->arm->setFsm(ArmFSMState::MOVEC);
            }

            // Verifica a consistência dos dados recebidos
            if (request->middle_posture.size() != 6) {
                RCLCPP_ERROR(this->get_logger(), "Invalid middle_posture vector size. Expected 6 elements.");
                return;
            }
            if (request->end_posture.size() != 6) {
                RCLCPP_ERROR(this->get_logger(), "Invalid end_posture vector size. Expected 6 elements.");
                return;
            }

            // Converte os dados para os tipos esperados
            Vec6 middlePosture = Vec6::Zero();
            std::copy(request->middle_posture.begin(), request->middle_posture.end(), middlePosture.data());

            Vec6 endPosture = Vec6::Zero();
            std::copy(request->end_posture.begin(), request->end_posture.end(), endPosture.data());

            double gripperPos = request->gripper_pos;
            double maxSpeed = request->max_speed;

            // Invoca o comando para controlar o braço num caminho linear
            if(gripperPos<-6.2831 || gripperPos>=0.0)
            {
                z1->arm->MoveC(middlePosture, endPosture, gripperPos, maxSpeed);
            }
            else
            {
                z1->arm->MoveC(middlePosture, endPosture, maxSpeed);
            }

            std::ostringstream posture_str;
            posture_str << "[";
            for (int i = 0; i < endPosture.size(); ++i) {
                posture_str << endPosture(i);
                if (i != endPosture.size() - 1) {
                    posture_str << ", ";
                }
            }
            posture_str << "]";

            // Define a resposta
            response->success = true;
            response->message = "Arm moved to " + posture_str.str();
        }
        catch (const std::exception &e)
        {
            response->success = true;
            response->message = "Error moving.";
            RCLCPP_ERROR(this->get_logger(), "Failed to move: %s", e.what());
        }
    }

    // Controla a garra
    void gripper_control_callback(const std::shared_ptr<z1_interfaces::srv::GripperCommand::Request> request,
                                std::shared_ptr<z1_interfaces::srv::GripperCommand::Response> response)
    {
        try
        {
            // Converte os dados para os tipos esperados
            double gripperPos = request->gripper_pos;
            double gripperW = request->gripper_w;
            double gripperTau = request->gripper_tau;

            // Invoca o comando 
            z1->arm->setGripperCmd(gripperPos, gripperW, gripperTau);
            response->success = true;
            response->message = "Arm moved.";
        }
        catch (const std::exception &e)
        {
            response->success = false;
            response->message = "Error moving gripper.";
            RCLCPP_ERROR(this->get_logger(), "Failed to move gripper: %s", e.what());
        }
    }

/*
Callback para controle do Z1
*/
    void control_callback(const z1_interfaces::msg::ArmControlCommand::SharedPtr msg) {

        try {

            // Verifica a consistência dos dados recebidos
            if (msg->directions.size() != 7) {
                RCLCPP_ERROR(this->get_logger(), "Invalid directions vector size. Expected 7 elements.");
                return;
            }

            // Converte os dados para os tipos esperados
            Vec7 directions = Vec7::Zero();
            std::copy(msg->directions.begin(), msg->directions.end(), directions.data());

            if(msg->cartesian) //Controle de juntas
            {
                if(z1->arm->_ctrlComp->recvState.state != ArmFSMState::CARTESIAN)
                {
                    z1->arm->setFsm(ArmFSMState::CARTESIAN);
                }

                if (msg->speed_1 < 0 || msg->speed_1 > 0.6) {
                    RCLCPP_ERROR(this->get_logger(), "Invalid oriSpeed. Must be in range [0, 0.6].");
                    return;
                }

                if (msg->speed_2 < 0 || msg->speed_2 > 0.3) {
                    RCLCPP_ERROR(this->get_logger(), "Invalid posSpeed. Must be in range [0, 0.3].");
                    return;
                }
                z1->arm->setWait(true);
                double oriSpeed = msg->speed_1;
                double posSpeed = msg->speed_2;

                // Invoca o comando para controlar o braço no espaço cartesiano
                z1->arm->cartesianCtrlCmd(directions, oriSpeed, posSpeed);
            }
            else
            {
                // Verifica estado do braço
                if(z1->arm->_ctrlComp->recvState.state != ArmFSMState::JOINTCTRL)
                {
                    z1->arm->setFsm(ArmFSMState::JOINTCTRL);
                }

                if (msg->speed_1 < 0 || msg->speed_1 > 3.1415) {
                    RCLCPP_ERROR(this->get_logger(), "Invalid jointSpeed. Must be in range [0, pi].");
                    return;
                }
                double jointSpeed = msg->speed_1;
                z1->arm->jointCtrlCmd(directions, jointSpeed);
            }

        } catch (const std::exception &e) {
            RCLCPP_ERROR(this->get_logger(), "Failed to process control command: %s", e.what());
        }
    }

/*
Publica o estado das juntas
*/
    void publish_joint_states()
    {
        auto arm_q = z1->arm->lowstate->getQ();
        auto arm_qd = z1->arm->lowstate->getQd();
        auto arm_tau = z1->arm->lowstate->getTau();
        auto gripper_q = z1->arm->lowstate->getGripperQ();
        auto gripper_qd = z1->arm->lowstate->getGripperQd();
        auto gripper_tau = z1->arm->lowstate->getGripperTau();

        auto message = sensor_msgs::msg::JointState();
        message.header.stamp = this->now();
        message.name = {"joint1", "joint2", "joint3", "joint4", "joint5", "joint6", "jointGripper"};
        message.position = {arm_q[0], arm_q[1], arm_q[2], arm_q[3], arm_q[4], arm_q[5], gripper_q};
        message.velocity = {arm_qd[0], arm_qd[1], arm_qd[2], arm_qd[3], arm_qd[4], arm_qd[5], gripper_qd};
        message.effort = {arm_tau[0], arm_tau[1], arm_tau[2], arm_tau[3], arm_tau[4], arm_tau[5], gripper_tau};

        publisher_->publish(message);
    }

    rclcpp::Subscription<z1_interfaces::msg::ArmControlCommand>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;

    rclcpp::Service<z1_interfaces::srv::NoInputCommand>::SharedPtr backToStart_service_;
    rclcpp::Service<z1_interfaces::srv::NoInputCommand>::SharedPtr setZero_service_;
    rclcpp::Service<z1_interfaces::srv::NoInputCommand>::SharedPtr setPassive_service_;
    rclcpp::Service<z1_interfaces::srv::GripperCommand>::SharedPtr moveGripper_service_;
    rclcpp::Service<z1_interfaces::srv::MoveJointPathCommand>::SharedPtr moveJointPath_service_;
    rclcpp::Service<z1_interfaces::srv::MoveLinearPathCommand>::SharedPtr moveLinearPath_service_;
    rclcpp::Service<z1_interfaces::srv::MoveCircularPathCommand>::SharedPtr moveCircularPath_service_;

    rclcpp::TimerBase::SharedPtr timer_;

    std::string fsm_initial_state_;
    arm_sdk_manager *z1;
};

int main(int argc, char *argv[])
{
    // Inicializa o ROS 2
    rclcpp::init(argc, argv);

    // Cria uma instância do nó
    auto node = std::make_shared<Z1ManagerNode>();

    // Mantém o nó ativo até ser interrompido
    rclcpp::spin(node);

    // Finaliza o ROS 2
    rclcpp::shutdown();

    return 0;
}