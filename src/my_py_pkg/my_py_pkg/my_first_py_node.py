#!/usr/bin/env python3

import rclpy
from rclpy.node import Node

class MyNode(Node):

    def __init__(self):
        # Call Parent init
        super().__init__("py_test")
        # Display a message
        self.get_logger().info("Hello World from ROS2 Py node")
        # Create 1 Hz Timer
        self.create_timer(1, self.timer_callback)
        # Counter
        self.count = 0

    def timer_callback(self):
        self.get_logger().info("Hello World: " + str(self.count))
        self.count += 1

def main(args=None):
    # Initialize Ros tools
    rclpy.init(args=args)

    # Create node
    node = MyNode()

    # Spin, keep node alive
    rclpy.spin(node)

    # Shutdown communications
    rclpy.shutdown()


if __name__ == "__main__":
    main()

