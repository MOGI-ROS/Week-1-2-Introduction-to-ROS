#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32 # Message type used in the node

'''
"sub_callback" is the callback method of the subscriber. Argument "msg" contains the received data.
'''
def sub_callback(msg):
	rospy.loginfo("Received data from publisher_topic: %d", msg.data)

rospy.init_node('subscriber_py') # Init the node with name "subscriber_py"

rospy.Subscriber("publisher_topic", Int32, sub_callback, queue_size=10) 

rospy.loginfo("Subscriber_py node has started and subscribed to publisher_topic")

'''
rospy.spin() simply keeps your node from exiting until the node has been shutdown.
Unlike roscpp::spin(), rospy.spin() does not affect the subscriber callback functions,
as those have their own threads.
'''
rospy.spin() 