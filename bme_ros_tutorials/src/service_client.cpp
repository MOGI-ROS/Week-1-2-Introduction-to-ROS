#include "bme_ros_tutorials/AddTwoInts.h"
#include "ros/ros.h"
#include <cstdlib>

int main(int argc, char **argv) {

  // First, check number of arguments
  if (argc != 3) {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  // Init the node with name "add_two_ints_client"
  ros::init(argc, argv, "add_two_ints_client");
  ros::NodeHandle nh; // NodeHandle will fully initialze the node

  // Create a ROS service client
  ros::ServiceClient client =
      nh.serviceClient<bme_ros_tutorials::AddTwoInts>("add_two_ints");

  bme_ros_tutorials::AddTwoInts srv;
  // Convert arguments to long long int
  srv.request.a = atoll(argv[1]);
  srv.request.b = atoll(argv[2]);

  // Execute service call and check true or false response
  if (client.call(srv)) {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  } else {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}