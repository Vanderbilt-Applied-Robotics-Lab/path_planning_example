#ifndef OBSTACLE_EXAMPLE
#define OBSTACLE_EXAMPLE

#include <rclcpp/rclcpp.hpp>
#include <string>
#include <moveit_msgs/msg/collision_object.hpp>
#include <moveit_msgs/msg/display_trajectory.hpp>
#include <geometric_shapes/mesh_operations.h>
#include <shape_msgs/msg/solid_primitive.hpp>
#include <geometry_msgs/msg/pose.hpp>
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

    void addBoxObstacle();

    moveit::planning_interface::PlanningSceneInterface psi_;

    rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_pub_;
    moveit_msgs::msg::DisplayTrajectory display_msg_;

    bool plan_succeeded_ = false;
    
};

#endif // OBSTACLE_EXAMPLE