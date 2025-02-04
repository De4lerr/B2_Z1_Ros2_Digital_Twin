#include <unistd.h>
#include <chrono>
#include <thread>
#include <termios.h>
#include <iostream>
#include <sstream> 
#include "rclcpp/rclcpp.hpp"
#include "unitree_api/msg/request.hpp"
#include "unitree_go/msg/sport_mode_state.hpp"
#include "common/ros2_sport_client.h"

using std::placeholders::_1;

// Função para capturar uma tecla pressionada
char get_key()
{
    char key;
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    key = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return key;
}

// Classe para controle do robô com teclado
class SportManager : public rclcpp::Node
{
public:
    SportManager() : Node("keyboard_controller")
    {
        // Inicializa o publicador no tópico "/api/sport/request"
        req_publisher = this->create_publisher<unitree_api::msg::Request>("/api/sport/request", 10);

        // Inicia a inscrição no tópico "sportmodestate"
        state_subscriber = this->create_subscription<unitree_go::msg::SportModeState>(
            "sportmodestate", 10, std::bind(&SportManager::state_callback, this, _1));

        // Timer para capturar teclas continuamente
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), std::bind(&SportManager::key_loop, this));

        RCLCPP_INFO(this->get_logger(), "Controlador iniciado. Use W/A/S/D para mover e Q/E para rotacionar. Ctrl+C para sair.");
    }

private:
    void key_loop()
    {
        char key = get_key();
        unitree_api::msg::Request request;
        PathPoint path_point_tmp;

        // Comandos para o 
        if (mode == 1) //Modo caminhada
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
            else if (key == 'x')
            {
                RCLCPP_INFO(this->get_logger(), "Altura Normal");

                sport_req.BodyHeight(request, 0);
            }
            else if (key == 'c')
            {
                RCLCPP_INFO(this->get_logger(), "Alto ");

                sport_req.BodyHeight(request, 0.2);
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

        if (key == 'l')
        {
            RCLCPP_INFO(this->get_logger(), "Euler");

            sport_req.Euler(request, 0.2, -0.2, 0.2);
        }

        if (key == 'p')
        {
            RCLCPP_INFO(this->get_logger(), "Euler");

            sport_req.Euler(request, 0.2, 0.2, 0.2);
        }

        if (key == 'o')
        {
            RCLCPP_INFO(this->get_logger(), "Euler");

            sport_req.Euler(request, 0.2, 0.2, -0.2);
        }

        if (key == 'k')
        {
            RCLCPP_INFO(this->get_logger(), "Euler");

            sport_req.Euler(request, 0.2, -0.2, -0.2);
        }

        else if (key == 'z')
        {
            RCLCPP_INFO(this->get_logger(), "Configuração de Altura, insira uma altura entre -0.2 e 0.2");

            std::string input;
            double height;

            std::getline(std::cin, input); // Lê a entrada como string

            // Converter para double
            std::stringstream ss(input);
            if (ss >> height) {
                std::cout << "O valor da nova altura é: " << height << std::endl;
            } else {
                std::cout << "Erro: a entrada não é um número válido." << std::endl;
            }

            sport_req.BodyHeight(request, height);
        }

        // Publica a mensagem no tópico
        req_publisher->publish(request);
    }

    void state_callback(unitree_go::msg::SportModeState::SharedPtr data)
    {
        mode = data->mode;
    }

    rclcpp::Subscription<unitree_go::msg::SportModeState>::SharedPtr state_subscriber;
    rclcpp::Publisher<unitree_api::msg::Request>::SharedPtr req_publisher;
    rclcpp::TimerBase::SharedPtr timer_;
    SportClient sport_req;
    uint mode = 7;
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