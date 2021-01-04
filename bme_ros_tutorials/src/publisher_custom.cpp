#include "ros/ros.h"
#include "bme_ros_tutorials/Test.h" // Our custom message type used in the node

int main(int argc, char **argv)
{
	ros::init(argc, argv, "publisher_custom"); // Init the node with name "publisher_custom"
	ros::NodeHandle nh;                        // NodeHandle will fully initialze the node

	ros::Publisher pub = nh.advertise<bme_ros_tutorials::Test>("publisher_custom_topic", 10);
	
	ROS_INFO("Custom publisher C++ node has started and publishing data on publisher_custom_topic");
	
	ros::Rate loop_rate(5); // 5 Hz
	
	bme_ros_tutorials::Test test_message; // test_message is now our custom ROS Test type variable that is ready to be published
	test_message.first_name = "David";    // Initializing first name string
    test_message.last_name  = "Dudas";    // Initializing last name string
    test_message.age        = 32;         // Initializing age
    test_message.score      = 0;          // Initializing score that we'll increment later
	
    while (ros::ok()) // Run the node until Ctrl-C is pressed
    {		
		pub.publish(test_message); // Publishing data on topic "publisher_custom_topic"
		test_message.score++;	
		loop_rate.sleep();         // The loop runs at 5Hz
	}
}
