#include <ros/ros.h>

int main(int argc, char **argv) {

  // Init the node with name "basic_node"
  ros::init(argc, argv, "basic_node");
  ros::NodeHandle nh; // NodeHandle will fully initialze the node

  ros::Rate loop_rate(1); // 1Hz

  int count = 0;
  while (ros::ok()) // run the node until Ctrl-C is pressed
  {
    // print info to std out
    ROS_INFO("basic_node cpp is running. count = %d", count);

    count++;

    loop_rate.sleep(); // The loop runs at 1Hz
  }
}