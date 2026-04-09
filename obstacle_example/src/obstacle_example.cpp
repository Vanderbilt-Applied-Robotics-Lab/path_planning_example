#include "obstacle_example/obstacle_example.h"


ObstacleExample::ObstacleExample()
    : Node("obstacle_example")
{
    
}


void ObstacleExample::publishObstacles()
{
    // addMeshObstacle();
    addBuiltInObstacle();
}

// void ObstacleExample::addMeshObstacle()
// {

// }

void ObstacleExample::addBuiltInObstacle()
{
    // INSERT CODE HERE
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ObstacleExample>();

    rclcpp::sleep_for(std::chrono::seconds(1));

    node->publishObstacles();

    rclcpp::sleep_for(std::chrono::seconds(2));
    rclcpp::shutdown();

    return 0;
}