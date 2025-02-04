import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from unitree_go.msg import LowState

class MotorToJointStatePublisher(Node):
    def __init__(self):
        super().__init__('motor_to_joint_state_publisher')
        
        # Subscriber para o tópico com os dados dos motores
        self.subscription = self.create_subscription(
            LowState,  
            '/lowstate',      
            self.motor_callback,
            10                 
        )
        
        # Subscriber para o tópico com os dados das juntas do Z1
        self.z1_subscription = self.create_subscription(
            JointState,
            '/z1_joint_states',
            self.z1_joint_callback,
            10
        )
        
        # Publisher para o tópico /joint_states
        self.joint_state_publisher = self.create_publisher(JointState, '/joint_states', 10)
        
        # Lista com os nomes das juntas do B2
        self.b2_joint_names = [
            "FL_hip_joint",  # Frente esquerda - quadril
            "FL_thigh_joint",  # Frente esquerda - coxa
            "FL_calf_joint",  # Frente esquerda - panturrilha
            "FR_hip_joint",  # Frente direita - quadril
            "FR_thigh_joint",  # Frente direita - coxa
            "FR_calf_joint",  # Frente direita - panturrilha
            "RL_hip_joint",  # Traseira esquerda - quadril
            "RL_thigh_joint",  # Traseira esquerda - coxa
            "RL_calf_joint",  # Traseira esquerda - panturrilha
            "RR_hip_joint",  # Traseira direita - quadril
            "RR_thigh_joint",  # Traseira direita - coxa
            "RR_calf_joint",  # Traseira direita - panturrilha
        ]
        
        # Lista com os nomes das juntas do Z1
        self.z1_joint_names = [
            "joint1",
            "joint2",
            "joint3",
            "joint4",
            "joint5",
            "joint6",
            "jointGripper"
        ]

        # Variáveis para armazenar as mensagens de estados
        self.motor_state = None
        self.z1_joint_state = None

    def motor_callback(self, msg):
        self.motor_state = msg

        # Verifica se temos os dois estados (motor e z1)
        if self.motor_state and self.z1_joint_state:
            self.publish_joint_state()

    def z1_joint_callback(self, msg):
        self.z1_joint_state = msg

        # Verifica se temos os dois estados (motor e z1)
        if self.motor_state and self.z1_joint_state:
            self.publish_joint_state()

    def publish_joint_state(self):
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()  

        # Combina as informações das juntas dos dois tópicos
        motors_corrected = [
            self.motor_state.motor_state[3], self.motor_state.motor_state[4], self.motor_state.motor_state[5],
            self.motor_state.motor_state[0], self.motor_state.motor_state[1], self.motor_state.motor_state[2],
            self.motor_state.motor_state[9], self.motor_state.motor_state[10], self.motor_state.motor_state[11],
            self.motor_state.motor_state[6], self.motor_state.motor_state[7], self.motor_state.motor_state[8]
        ]

        # Garantir que a posição, velocidade e esforço sejam listas
        joint_state.name = self.b2_joint_names + self.z1_joint_names
        joint_state.position = [motor.q for motor in motors_corrected] + list(self.z1_joint_state.position)  # Conversão para lista
        joint_state.velocity = [motor.dq for motor in motors_corrected] + list(self.z1_joint_state.velocity)  # Conversão para lista
        joint_state.effort = [motor.tau_est for motor in motors_corrected] + list(self.z1_joint_state.effort)  # Conversão para lista
        
        # Publica a mensagem no tópico /joint_states
        self.joint_state_publisher.publish(joint_state)
        self.get_logger().info(f'Published JointState: {joint_state}')

def main(args=None):
    rclpy.init(args=args)
    node = MotorToJointStatePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
