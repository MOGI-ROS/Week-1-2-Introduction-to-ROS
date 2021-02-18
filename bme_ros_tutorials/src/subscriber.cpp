#include "ros/ros.h"
#include "std_msgs/Int32.h" // Message type used in the node

/*
"sub_cb" is the callback method of the subscriber. Argument "msg" contains the
received data with type Int32.
*/
void sub_cb(const std_msgs::Int32::ConstPtr &msg) {
  ROS_INFO("Received data from publisher_topic: [%ld]", (long int)msg->data);
}

int main(int argc, char **argv) {
  // Init the node with name "subscriber"
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nh; // NodeHandle will fully initialze the node

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the
   * Subscriber object go out of scope, this callback will automatically be
   * unsubscribed from this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to
   * throw away the oldest ones.
   */
  ros::Subscriber sub = nh.subscribe("publisher_topic", 10, sub_cb);

  ROS_INFO("Subscriber C++ node has started and subscribed to publisher_topic");

  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).
   * ros::spin() will exit when Ctrl-C is pressed, or the node is shutdown by
   * the master.
   */
  ros::spin();

  return 0;
}
