#include "ros/ros.h"
#include "std_msgs/Int32.h" // Message type used in the node

int main(int argc, char **argv) {
  // Init the node with name "publisher"
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh; // NodeHandle will fully initialze the node

  /**
   * The advertise() function is how you tell ROS that you want to
   * publish on a given topic name. This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing. After this advertise() call is made, the master
   * node will notify anyone who is trying to subscribe to this topic name,
   * and they will in turn negotiate a peer-to-peer connection with this
   * node.  advertise() returns a Publisher object which allows you to
   * publish messages on that topic through a call to publish().  Once
   * all copies of the returned Publisher object are destroyed, the topic
   * will be automatically unadvertised.
   *
   * The second parameter to advertise() is the size of the message queue
   * used for publishing messages.  If messages are published more quickly
   * than we can send them, the number here specifies how many messages to
   * buffer up before throwing some away.
   */

  ros::Publisher pub = nh.advertise<std_msgs::Int32>("publisher_topic", 10);

  ROS_INFO(
      "Publisher C++ node has started and publishing data on publisher_topic");

  ros::Rate loop_rate(1); // 1 Hz

  std_msgs::Int32 count; // Count is now a ROS Int32 type variable that is ready
                         // to be published
  count.data = 0;        // Initializing count

  // Run the node until Ctrl+C is pressed
  while (ros::ok()) {
    pub.publish(count); // Publishing data on topic "publisher_topic"

    count.data++;
    loop_rate.sleep(); // The loop runs at 1Hz
  }
}