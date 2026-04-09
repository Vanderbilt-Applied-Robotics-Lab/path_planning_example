#ifndef OBSTACLE_EXAMPLE
#define OBSTACLE_EXAMPLE

#include <string>

#include <moveit_msgs/msg/collision_object.hpp>

#include <geometric_shapes/shape_operations.h>
#include <geometric_shapes/mesh_operations.h>

#include <shape_msgs/msg/mesh.hpp>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <rclcpp/rclcpp.hpp>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

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

    void addMeshObstacle();

    void addBuiltInObstacle();

    moveit::planning_interface::PlanningSceneInterface psi_;
    
};

#endif // OBSTACLE_EXAMPLE