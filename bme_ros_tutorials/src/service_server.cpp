#include "bme_ros_tutorials/AddTwoInts.h"
#include "ros/ros.h"

bool add(bme_ros_tutorials::AddTwoInts::Request &req,
         bme_ros_tutorials::AddTwoInts::Response &res) {

  res.sum = req.a + req.b;

  ROS_INFO("request: x=%ld, y=%ld", (long int)req.a, (long int)req.b);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv) {
  // Init the node with name "add_two_ints_server"
  ros::init(argc, argv, "add_two_ints_server");
  ros::NodeHandle nh; // NodeHandle will fully initialze the node

  // Advertise the ROS service
  ros::ServiceServer service = nh.advertiseService("add_two_ints", add);
  ROS_INFO("Ready to add two ints.");

  // Run until Ctrl+C is pressed
  ros::spin();

  return 0;
}