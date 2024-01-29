// Importing rclcpp library
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);   //  Initiate ros2
    rclcpp::spin(std::make_shared<rclcpp::Node>("knock_cpp_pub"));  // Creating the node
    rclcpp::shutdown();     // Close ros2
    return 0;
}