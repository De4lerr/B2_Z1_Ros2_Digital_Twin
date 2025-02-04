#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/joint_state.hpp>

class JointStateRepublisher : public rclcpp::Node
{
public:
    JointStateRepublisher()
        : Node("joint_state_republisher")
    {
        // Assina o tópico de entrada
        subscription_ = this->create_subscription<sensor_msgs::msg::JointState>(
            "z1_joint_states", 10,
            std::bind(&JointStateRepublisher::callback, this, std::placeholders::_1));

        // Cria o publisher para o tópico `joint_states`
        publisher_ = this->create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    }

private:
    void callback(const sensor_msgs::msg::JointState::SharedPtr msg)
    {
        // Cria uma nova mensagem baseada na entrada
        auto joint_state_msg = std::make_shared<sensor_msgs::msg::JointState>();
        joint_state_msg->header = msg->header;
        joint_state_msg->name = msg->name;
        joint_state_msg->position = msg->position;
        joint_state_msg->velocity = msg->velocity;
        joint_state_msg->effort = msg->effort;

        // Publica no tópico `joint_states`
        publisher_->publish(*joint_state_msg);
    }

    rclcpp::Subscription<sensor_msgs::msg::JointState>::SharedPtr subscription_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr publisher_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JointStateRepublisher>());
    rclcpp::shutdown();
    return 0;
}