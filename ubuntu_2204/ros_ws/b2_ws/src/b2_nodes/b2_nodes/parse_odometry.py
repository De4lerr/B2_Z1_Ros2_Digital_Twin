import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
import tf2_ros
from nav_msgs.msg import Odometry
from tf_transformations import quaternion_multiply, quaternion_from_euler

class OdomPublisher(Node):
    def __init__(self):
        super().__init__('odom_publisher')

        self.subscription = self.create_subscription(
            Odometry,  
            '/dog_odom',
            self.odom_callback,
            10
        )

        # Broadcaster para publicar transformações
        self.tf_broadcaster = tf2_ros.TransformBroadcaster(self)

    def odom_callback(self, msg):
        # Extraindo posição e orientação da mensagem
        position = msg.pose.pose.position
        orientation = msg.pose.pose.orientation

        # Criando a transformação do frame odom para o frame base_link
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = 'odom'
        t.child_frame_id = 'base'

        # Posição
        t.transform.translation.x = position.x
        t.transform.translation.y = position.y
        t.transform.translation.z = position.z

        # Orientação corrigida
        t.transform.rotation.x = orientation.x
        t.transform.rotation.y = orientation.y
        t.transform.rotation.z = orientation.z
        t.transform.rotation.w = orientation.w

        # Publica a transformação
        self.tf_broadcaster.sendTransform(t)

def main(args=None):
    rclpy.init(args=args)
    node = OdomPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()