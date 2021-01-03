#include "ros/ros.h"
#include "bme_ros_tutorials/Test.h"             // Message type used in the node

int main(int argc, char **argv)
{
	ros::init(argc, argv, "publisher_custom"); // Init the node with name "publisher"
	ros::NodeHandle nh;                 // NodeHandle will fully initialze the node

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

	ros::Publisher pub = nh.advertise<bme_ros_tutorials::Test>("publisher_custom_topic", 10);
	
	ROS_INFO("Publisher C++ node has started and publishing data on publisher_custom_topic");
	
	ros::Rate loop_rate(1); // 1 Hz
	
	bme_ros_tutorials::Test test_message;  // Count is now a ROS Int32 type variable that is ready to be published
	test_message.first_name="David";           // Initializing count
    test_message.last_name="Dudas";           // Initializing count
    test_message.age=32;           // Initializing count
    test_message.score=0;           // Initializing count
	
    while (ros::ok())       // Run the node until Ctrl-C is pressed
    {		
		pub.publish(test_message); // Publishing data on topic "publisher_topic"
		test_message.score++;	
		loop_rate.sleep();  // The loop runs at 1Hz
	}
}
