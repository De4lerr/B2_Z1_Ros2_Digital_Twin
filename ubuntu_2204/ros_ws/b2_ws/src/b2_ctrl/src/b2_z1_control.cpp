#include <unistd.h>
#include <chrono>
#include <thread>
#include <pthread.h>
#include <termios.h>
#include <iostream>
#include <atomic>
#include <ncurses.h>
#include <rclcpp/rclcpp.hpp>
#include "unitree_api/msg/request.hpp"
#include "unitree_go/msg/sport_mode_state.hpp"
#include "z1_interfaces/msg/arm_control_command.hpp"
#include "common/ros2_sport_client.h"

using std::placeholders::_1;

// Função para capturar uma tecla pressionada
std::atomic<char> key_pressed{0};
std::atomic<bool> running(true);

void set_thread_priority() {
    struct sched_param sch_params;
    sch_params.sched_priority = sched_get_priority_max(SCHED_FIFO);  // Prioridade máxima
    pthread_setschedparam(pthread_self(), SCHED_FIFO, &sch_params);
}

void get_key()
{
    initscr();             // Inicializa ncurses
    cbreak();              // Captura teclas sem precisar de ENTER
    noecho();              // Evita que a tecla apareça no terminal
    nodelay(stdscr, TRUE); // Não bloqueia esperando entrada
    keypad(stdscr, TRUE);  // Habilita teclas especiais como setas
    set_thread_priority();

    while (running) {
        int ch = wgetch(stdscr);
        if (ch != ERR) {
            key_pressed.store(static_cast<char>(ch), std::memory_order_relaxed);
        } else {
            key_pressed.store(0, std::memory_order_relaxed);  // Nenhuma tecla pressionada
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5));  
    }

    endwin(); // Finaliza ncurses corretamente
}

// Classe para controle do robô com teclado
class SportManager : public rclcpp::Node
{
public:
    SportManager() : Node("keyboard_controller")
    {
        // Inicializa o publicador no tópico "/api/sport/request"
        req_publisher = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);

        // Publicador para o controle do braço no tópico "z1_cartesian_control"
        arm_publisher = this->create_publisher<z1_interfaces::msg::ArmControlCommand>("z1_control", 10);

        // Inicia a inscrição no tópico "sportmodestate"
        state_subscriber = this->create_subscription<unitree_go::msg::SportModeState>(
            "sportmodestate", 10, std::bind(&SportManager::state_callback, this, _1));

        // Timer para capturar teclas continuamente
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(5), std::bind(&SportManager::key_loop, this));

        // Inicia a thread de captura de teclas (somente uma vez)
        key_thread = std::thread(get_key);

        RCLCPP_INFO(this->get_logger(), "Controlador iniciado. Use as teclas para mover o robô e o braço. Ctrl+C para sair.");
    }

    ~SportManager()
    {
        running = false;
        if (key_thread.joinable()) {
            key_thread.join();
        }
    }

private:
    void key_loop()
    {
        char key = key_pressed.load(std::memory_order_relaxed);
        unitree_api::msg::Request request;
        PathPoint path_point_tmp;
        uint mode = mode_;

        //Verifica se alguma tecla foi pressionada
        if(key == 0){return;}

        // Comandos para o 
        if (mode == 1 || mode ==3) //Modo caminhada
        {
            if (key == 'w')
            {
                RCLCPP_INFO(this->get_logger(), "Avançar");
                path_point_tmp.vx = 0.3;
                path_point_tmp.vy = 0.0;
                path_point_tmp.vyaw = 0.0;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 's')
            {
                RCLCPP_INFO(this->get_logger(), "Recuar");
                path_point_tmp.vx = -0.3;
                path_point_tmp.vy = 0.0;
                path_point_tmp.vyaw = 0.0;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 'a')
            {
                RCLCPP_INFO(this->get_logger(), "Esquerda");
                path_point_tmp.vx = 0.0;
                path_point_tmp.vy = 0.4;
                path_point_tmp.vyaw = 0.0;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 'd')
            {
                RCLCPP_INFO(this->get_logger(), "Direita");
                path_point_tmp.vx = 0.0;
                path_point_tmp.vy = -0.4;
                path_point_tmp.vyaw = 0.0;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 'q')
            {
                RCLCPP_INFO(this->get_logger(), "Rotacionar anti-horário");
                path_point_tmp.vx = 0.0;
                path_point_tmp.vy = 0.0;
                path_point_tmp.vyaw = 0.4;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 'e')
            {
                RCLCPP_INFO(this->get_logger(), "Rotacionar horário");
                path_point_tmp.vx = 0.0;
                path_point_tmp.vy = 0.0;
                path_point_tmp.vyaw = -0.4;
                sport_req.Move(request, path_point_tmp.vx, path_point_tmp.vy, path_point_tmp.vyaw);
            }
            else if (key == 'f')
            {
                RCLCPP_INFO(this->get_logger(), "Parando");

                sport_req.StopMove(request);

            }
            else if (key == 'z')
            {
                RCLCPP_INFO(this->get_logger(), "Altura --");
                
                if(height<=0.2 || height>=0.2)
                {
                    height=height-0.03;
                }
                sport_req.BodyHeight(request, height);
            }
            else if (key == 'x')
            {
                RCLCPP_INFO(this->get_logger(), "Altura ++");

                if(height<=0.2 || height>=0.2)
                {
                    height=height+0.03;
                }
                sport_req.BodyHeight(request, height);
            }
            else if (key == '!')
            {
                RCLCPP_INFO(this->get_logger(), "RecoveryStand");

                sport_req.RecoveryStand(request);
            }
            else if (key == '@')
            {
                RCLCPP_INFO(this->get_logger(), "Deitando");

                sport_req.StandDown(request);
            } 
        }
        else if (mode == 2 || mode == 6)
        {
            if (key == '@')
            {
                RCLCPP_INFO(this->get_logger(), "Deitando");

                sport_req.StandDown(request);
            } 
            else if (key == '!')
            {
                RCLCPP_INFO(this->get_logger(), "BalanceStand");

                sport_req.BalanceStand(request);
            }

        }
        else if (mode == 7)
        {
            if (key == '@')
            {
                RCLCPP_INFO(this->get_logger(), "Levantando");

                sport_req.StandUp(request);
            }
        } 
        
        if (key == '"')
        {
                RCLCPP_INFO(this->get_logger(), "Damp");

                sport_req.Damp(request);
        }

        if (key == '?')
        {
            int count = 10;

            while(count > 0)
            {
            RCLCPP_INFO(this->get_logger(), "Dance");

            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            sport_req.BodyHeight(request, 0);
            req_publisher->publish(request);
            
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            sport_req.Euler(request, 0.2, -0.2, 0.2);
            req_publisher->publish(request);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            sport_req.Euler(request, 0.2, 0.2, 0.2);
            req_publisher->publish(request);

            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            sport_req.BodyHeight(request, -0.1);
            req_publisher->publish(request);

            std::this_thread::sleep_for(std::chrono::milliseconds(250));

            sport_req.Euler(request, 0.2, 0.2, -0.2);
            req_publisher->publish(request);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            sport_req.Euler(request, 0.2, -0.2, -0.2);
            req_publisher->publish(request);

            std::this_thread::sleep_for(std::chrono::milliseconds(500));

            count = count-1;
            }
        }

        if (key == 'k')
        {
            RCLCPP_INFO(this->get_logger(), "Euler 1");

            sport_req.Euler(request, 0.2, -0.2, 0.2);
        }

        if (key == 'i')
        {
            RCLCPP_INFO(this->get_logger(), "Euler 2");

            sport_req.Euler(request, 0.2, 0.2, 0.2);
        }

        if (key == 'u')
        {
            RCLCPP_INFO(this->get_logger(), "Euler 3");

            sport_req.Euler(request, 0.2, 0.2, -0.2);
        }

        if (key == 'j')
        {
            RCLCPP_INFO(this->get_logger(), "Euler 4");

            sport_req.Euler(request, 0.2, -0.2, -0.2);
        }

        // Comandos para o braço Z1
        if(key == '/')
        {
            if (arm_command.cartesian == true)
            {
                arm_command.cartesian = false;
                std::cout << "Comando da garra alterado para Controle de Juntas" << std::endl;
            }
            else
            {
                arm_command.cartesian = true;
                std::cout << "Comando da garra alterado para Controle Cartesiano" << std::endl;
            }
        }

        arm_command.directions = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0}; // roll, pitch, yaw, x, y, z, gripper

        if(arm_command.cartesian)
        {
            arm_command.speed_1 = 0.5; // Velocidade de orientação
            arm_command.speed_2 = 0.3; // Velocidade de posição
            float arm_delta = 0.5;
            float arm_wdelta = 0.5;

            if (key == '[') // Roll +
            {
                RCLCPP_INFO(this->get_logger(), "Roll +");
                arm_command.directions[0] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ']') // Roll -
            {
                RCLCPP_INFO(this->get_logger(), "Roll -");
                arm_command.directions[0] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == 'l') // Pitch +
            {
                RCLCPP_INFO(this->get_logger(), "Pitch +");
                arm_command.directions[1] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ';') // Pitch -
            {
                RCLCPP_INFO(this->get_logger(), "Pitch -");
                arm_command.directions[1] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ',') // Yaw +
            {
                RCLCPP_INFO(this->get_logger(), "Yaw +");
                arm_command.directions[2] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == '.') // Yaw -
            {
                RCLCPP_INFO(this->get_logger(), "Yaw -");
                arm_command.directions[2] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == '8') // Para frente (eixo X)
            {
                std::cout << "frente";
                RCLCPP_INFO(this->get_logger(), "Braço indo para frente (X+)");
                arm_command.directions[3] = arm_delta; // X+
                arm_publisher->publish(arm_command);
            }
            else if (key == '2') // Para trás (eixo X)
            {
                RCLCPP_INFO(this->get_logger(), "Braço indo para trás (X-)");
                arm_command.directions[3] = -arm_delta; // X-
                arm_publisher->publish(arm_command);
            }
            else if (key == '6') // Para direita (eixo Y)
            {
                RCLCPP_INFO(this->get_logger(), "Braço indo para direita (Y+)");
                arm_command.directions[4] = -arm_delta; // Y+
                arm_publisher->publish(arm_command);
            }
            else if (key == '4') // Para esquerda (eixo Y)
            {
                RCLCPP_INFO(this->get_logger(), "Braço indo para esquerda (Y-)");
                arm_command.directions[4] = arm_delta; // Y-
                arm_publisher->publish(arm_command);
            }
            else if (key == '7') // Para cima (eixo Z)
            {
                RCLCPP_INFO(this->get_logger(), "Braço subindo (Z+)");
                arm_command.directions[5] = arm_delta; // Z+
                arm_publisher->publish(arm_command);
            }
            else if (key == '1') // Para baixo (eixo Z)
            {
                RCLCPP_INFO(this->get_logger(), "Braço descendo (Z-)");
                arm_command.directions[5] = -arm_delta; // Z-
                arm_publisher->publish(arm_command);
            }
            else if (key == '+') // Abrir gripper
            {
                RCLCPP_INFO(this->get_logger(), "Abrindo o gripper");
                arm_command.directions[6] = arm_delta; // Gripper aberto
                arm_publisher->publish(arm_command);
            }
            else if (key == '-') // Fechar gripper
            {
                RCLCPP_INFO(this->get_logger(), "Fechando o gripper");
                arm_command.directions[6] = -arm_delta; // Gripper fechado
                arm_publisher->publish(arm_command);
            }
        }
        else
        {
            arm_command.speed_1 = 2;
            float arm_wdelta = 1;

            if (key == '[') // J1 +
            {
                RCLCPP_INFO(this->get_logger(), "J1 +");
                arm_command.directions[0] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ']') // J1 -
            {
                RCLCPP_INFO(this->get_logger(), "J1 -");
                arm_command.directions[0] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == 'l') // J2 +
            {
                RCLCPP_INFO(this->get_logger(), "J2 +");
                arm_command.directions[1] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ';') // J2 -
            {
                RCLCPP_INFO(this->get_logger(), "J2 -");
                arm_command.directions[1] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == ',') // J3 +
            {
                RCLCPP_INFO(this->get_logger(), "J3 +");
                arm_command.directions[2] = arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == '.') // J3 -
            {
                RCLCPP_INFO(this->get_logger(), "J3 -");
                arm_command.directions[2] = -arm_wdelta; 
                arm_publisher->publish(arm_command);
            }
            else if (key == '8') // J4 +
            {
                std::cout << "frente";
                RCLCPP_INFO(this->get_logger(), "J4 +");
                arm_command.directions[3] = arm_wdelta; // X+
                arm_publisher->publish(arm_command);
            }
            else if (key == '7') // J4 -
            {
                RCLCPP_INFO(this->get_logger(), "J4 -");
                arm_command.directions[3] = -arm_wdelta; // X-
                arm_publisher->publish(arm_command);
            }
            else if (key == '5') // J5 +
            {
                RCLCPP_INFO(this->get_logger(), "J5 +");
                arm_command.directions[4] = -arm_wdelta; // Y+
                arm_publisher->publish(arm_command);
            }
            else if (key == '4') // J5 -
            {
                RCLCPP_INFO(this->get_logger(), "J5 -");
                arm_command.directions[4] = arm_wdelta; // Y-
                arm_publisher->publish(arm_command);
            }
            else if (key == '2') // J6 +
            {
                RCLCPP_INFO(this->get_logger(), "J6 +");
                arm_command.directions[5] = arm_wdelta; // Z+
                arm_publisher->publish(arm_command);
            }
            else if (key == '1') // J6 -
            {
                RCLCPP_INFO(this->get_logger(), "J6 -");
                arm_command.directions[5] = -arm_wdelta; // Z-
                arm_publisher->publish(arm_command);
            }
            else if (key == '+') // Abrir gripper
            {
                RCLCPP_INFO(this->get_logger(), "Abrindo o gripper");
                arm_command.directions[6] = arm_wdelta; // Gripper aberto
                arm_publisher->publish(arm_command);
            }
            else if (key == '-') // Fechar gripper
            {
                RCLCPP_INFO(this->get_logger(), "Fechando o gripper");
                arm_command.directions[6] = -arm_wdelta; // Gripper fechado
                arm_publisher->publish(arm_command);
            }
        arm_command.directions = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
        arm_publisher->publish(arm_command);       
        }

        // Publica a mensagem no tópico do robô
        req_publisher->publish(request);
    }

    void state_callback(unitree_go::msg::SportModeState::SharedPtr data)
    {
        mode_ = data->mode;
    }

    rclcpp::Subscription<unitree_go::msg::SportModeState>::SharedPtr state_subscriber;
    rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_publisher;
    rclcpp::Publisher<z1_interfaces::msg::ArmControlCommand>::SharedPtr arm_publisher; // Publicador do braço
    rclcpp::TimerBase::SharedPtr timer_;
    z1_interfaces::msg::ArmControlCommand arm_command;
    SportClient sport_req;
    uint mode_ = 7;
    float height = 0.0;
    std::thread key_thread;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv); // Inicializa o rclcpp
    auto node = std::make_shared<SportManager>();

    try
    {
        rclcpp::spin(node); // Executa o nó
    }
    catch (const std::exception &e)
    {
        RCLCPP_ERROR(node->get_logger(), "Erro: %s", e.what());
    }

    rclcpp::shutdown(); // Finaliza o rclcpp
    return 0;
}
