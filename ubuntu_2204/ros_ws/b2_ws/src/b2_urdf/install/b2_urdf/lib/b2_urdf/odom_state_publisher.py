import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_msgs.msg import Header

# Supondo que você tenha a seguinte mensagem personalizada do tipo SportModeState que é semelhante à estrutura fornecida
from unitree_sdk2_py.sport_client import SportModeState  # Ajuste para o nome correto do seu tipo de mensagem

class OdomToJointStatePublisher(Node):

    def __init__(self):
        super().__init__('odom_to_joint_state_publisher')

        # Cria um subscriber para o tópico /odommodestate
        self.odom_subscriber = self.create_subscription(
            SportModeState,  # Tipo de mensagem baseado no seu exemplo
            '/odommodestate',  # Tópico correto de onde virão as informações de odometria
            self.odom_callback,
            10
        )

        # Cria um publisher para o tópico /joint_states
        self.joint_state_publisher = self.create_publisher(
            JointState,
            '/joint_states',  # Tópico de destino para as informações de estado das juntas
            10
        )

    def odom_callback(self, msg):
        # Extrai a posição da odometria do campo 'position'
        position = msg.position
        # Cria a mensagem de JointState
        joint_state = JointState()
        
        # Atribui o header
        joint_state.header = Header()
        joint_state.header.stamp = self.get_clock().now().to_msg()
        joint_state.header.frame_id = 'base_link'  # Exemplo, pode mudar de acordo com o seu sistema

        # Adiciona os nomes das juntas (ajuste conforme o seu caso)
        joint_state.name = ['joint1', 'joint2', 'joint3']  # Exemplo de nomes das juntas

        # Aqui estamos usando a posição do corpo (x, y, z) como as posições das juntas
        joint_state.position = [position[0], position[1], position[2]]  # Usando posição [x, y, z]

        # Publica o estado das juntas
        self.joint_state_publisher.publish(joint_state)
        self.get_logger().info(f'Published joint state: {joint_state.position}')

def main(args=None):
    rclpy.init(args=args)
    node = OdomToJointStatePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
