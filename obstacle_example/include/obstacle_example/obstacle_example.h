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
#include <moveit/move_group_interface/move_group_interface.h>

/**
 * example code for path planning with obstacles
 * Applied Robotics
 * Garrison Johnston
 */
class ObstacleExample : public rclcpp::Node
{
public:
    /**
     * Main constructor
     */
    ObstacleExample();

    /**
     * Destructor
     */
    ~ObstacleExample() = default;

    /**
     * Adds a box to the planning scene
     */
    void addBoxObstacle();

    /**
     * initializes the move group
     */
    void initMoveGroup();
    
    /**
     * plan the motion
     */
    void planMotion();

    /**
     * If the plan succeeded, visualizes the path plan before the robot moves
     */
    void visualizeMotion();

    /**
     * If the plan succeeded, executes the motion
     */
    void moveJoints();

private:
    moveit::planning_interface::PlanningSceneInterface psi_;

    moveit::planning_interface::MoveGroupInterface::Plan plan_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    std::vector<double> goal_angles_ = {0.0, 114.0*M_PI/180.0,  0.0, 0.0, 0.0, 0.0};

    rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_pub_;
    moveit_msgs::msg::DisplayTrajectory display_msg_;

    bool plan_succeeded_ = false;
    
};

#endif // OBSTACLE_EXAMPLE