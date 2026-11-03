#include "obstacle_example/obstacle_example.h"

ObstacleExample::ObstacleExample() : Node("obstacle_example")
{
    display_pub_ = this->create_publisher<moveit_msgs::msg::DisplayTrajectory>("/display_planned_path",10);
}

void ObstacleExample::addBoxObstacle()
{
    moveit_msgs::msg::CollisionObject obj;
    obj.header.frame_id = "world";
    obj.id = "box_obstacle";

    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions = {0.5, 0.5, 0.25};

    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.6;
    pose.position.y = 0.0;
    pose.position.z = 0.6;
    pose.orientation.w = 1.0;

    obj.primitives.push_back(primitive);
    obj.primitive_poses.push_back(pose);
    obj.operation = obj.ADD;

    psi_.applyCollisionObject(obj);

    RCLCPP_INFO(this->get_logger(), "Box obstacle added");
}

void ObstacleExample::initMoveGroup()
{
    // initialize movegroup
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "rv_3s_arm");

    move_group_ ->setNumPlanningAttempts(100);
    move_group_ ->setPlanningTime(20.0);
}

void ObstacleExample::planMotion()
{
    move_group_->setJointValueTarget(goal_angles_);
    plan_succeeded_ = move_group_->plan(plan_) == moveit::core::MoveItErrorCode::SUCCESS;
}

void ObstacleExample::visualizeMotion()
{
    if (plan_succeeded_)
    {
        display_msg_.trajectory_start = plan_.start_state_;
        display_msg_.trajectory.push_back(plan_.trajectory_);
        display_pub_->publish(display_msg_);
    }
}

void ObstacleExample::moveJoints()
{
    // if move plan succeeded, move robot
    if (plan_succeeded_)
    {
        if (move_group_->execute(plan_) != moveit::core::MoveItErrorCode::SUCCESS)
            RCLCPP_INFO(this->get_logger(), "Execution failed");
    }
    else // print error otherwise
    {
        RCLCPP_INFO(this->get_logger(), "Plan failed");
    }
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<ObstacleExample>();

    node->initMoveGroup();
    node->addBoxObstacle();
    rclcpp::spin_some(node);

    node->planMotion();
    node->visualizeMotion();

    rclcpp::sleep_for(std::chrono::seconds(10));

    node->moveJoints();

    rclcpp::shutdown();

    return 0;
}