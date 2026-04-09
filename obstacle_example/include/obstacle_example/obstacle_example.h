#ifndef OBSTACLE_EXAMPLE
#define OBSTACLE_EXAMPLE

#include <string>
#include <rclcpp/rclcpp.hpp>

// ADD INCLUDES HERE

class ObstacleExample : public rclcpp::Node
{
public:
    /**
     * Main constructor
     * @param options Node options
     */
    ObstacleExample();

    /**
     * Destructor
     */
    ~ObstacleExample() = default;


    void publishObstacles();
    
private:

    // void addMeshObstacle();

    void addBuiltInObstacle();

    // PLANNING SCENE INTERFACE
    
};

#endif // OBSTACLE_EXAMPLE