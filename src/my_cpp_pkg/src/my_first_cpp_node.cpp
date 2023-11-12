
#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
private:
    int count;

    void timerCallback()
    {
        RCLCPP_INFO(this->get_logger(), "Hello World : %d", count);
        count++;
    }

    rclcpp::TimerBase::SharedPtr timer;

public:
    MyNode() : Node("cpp_test")
    {
        count = 0;
        // Display a message
        RCLCPP_INFO(this->get_logger(), "Hello World from ROS2 CPP Node");

        timer = this->create_wall_timer(std::chrono::seconds(1),
                                        std::bind(&MyNode::timerCallback, this));
    }
};


int main(int argc, char **argv)
{
    // Initialize ROS communications
    rclcpp::init(argc, argv);

    // Create Node
    auto node = std::make_shared<MyNode>();

    // Spin, keep node alive
    rclcpp::spin(node);

    // Shutdown
    rclcpp::shutdown();

    return 0;
}
