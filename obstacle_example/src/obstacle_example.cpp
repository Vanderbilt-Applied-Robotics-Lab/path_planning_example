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

void ObstacleExample::addMeshObstacle()
{
    moveit_msgs::msg::CollisionObject obj;
    obj.header.frame_id = "world";
    obj.id = "mesh_obstacle";

    const std::string mesh_resource =
        "package://obstacle_example/meshes/obstacle_mitsubishi_meters.stl";

    std::unique_ptr<shapes::Mesh> mesh(
        shapes::createMeshFromResource(mesh_resource));

    if (!mesh)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to load mesh");
        return;
    }

    shapes::ShapeMsg shape_msg;
    shapes::constructMsgFromShape(mesh.get(), shape_msg);

    shape_msgs::msg::Mesh mesh_msg =
        boost::get<shape_msgs::msg::Mesh>(shape_msg);


    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.0;
    pose.position.y = 0.0;
    pose.position.z = 0.0;
    pose.orientation.w = 1.0;

    obj.meshes.push_back(mesh_msg);
    obj.mesh_poses.push_back(pose);
    obj.operation = obj.ADD;

    psi_.applyCollisionObject(obj);

    RCLCPP_INFO(this->get_logger(), "Mesh obstacle added");
}

void ObstacleExample::addBuiltInObstacle()
{
    moveit_msgs::msg::CollisionObject obj;
    obj.header.frame_id = "world";
    obj.id = "box_obstacle";

    shape_msgs::msg::SolidPrimitive primitive;
    primitive.type = primitive.BOX;
    primitive.dimensions = {0.5, 0.5, 0.5};

    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.6;
    pose.position.y = 0.0;
    pose.position.z = 0.2;
    pose.orientation.w = 1.0;

    obj.primitives.push_back(primitive);
    obj.primitive_poses.push_back(pose);
    obj.operation = obj.ADD;

    psi_.applyCollisionObject(obj);

    RCLCPP_INFO(this->get_logger(), "Box obstacle added");
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