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
        
        # Publisher para o tópico /joint_states
        self.joint_state_publisher = self.create_publisher(JointState, '/joint_states', 10)
        
        # Lista com os nomes das juntas (ajuste de acordo com o seu robô)
        self.joint_names = [
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

    def motor_callback(self, msg):
        joint_state = JointState()
        joint_state.header.stamp = self.get_clock().now().to_msg()  

        # Atribuindo nomes, posições, velocidades e torques das juntas

        #Trocando lado direito pelo esquerdo
        motors_corrected=[msg.motor_state[3],msg.motor_state[4],msg.motor_state[5],
                            msg.motor_state[0],msg.motor_state[1],msg.motor_state[2],   #trocando lado direito pelo esquerdo
                            msg.motor_state[9],msg.motor_state[10],msg.motor_state[11],
                            msg.motor_state[6],msg.motor_state[7],msg.motor_state[8]]
        
        #Corrigindo rotação do quadril
        # motors_corrected[0].q = -motors_corrected[0].q
        # motors_corrected[3].q = -motors_corrected[3].q 
        # motors_corrected[6].q = -motors_corrected[6].q 
        # motors_corrected[9].q = -motors_corrected[9].q    

        joint_state.name = self.joint_names
        joint_state.position = [motor.q for motor in motors_corrected]      
        joint_state.velocity = [motor.dq for motor in motors_corrected]     
        joint_state.effort = [motor.tau_est for motor in motors_corrected]
        
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