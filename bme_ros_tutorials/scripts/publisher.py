#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32  # Message type used in the node

rospy.init_node('publisher')    # Init the node with name "publisher"

pub = rospy.Publisher('publisher_topic', Int32, queue_size=10)

rospy.loginfo("Publisher Python node has started and publishing data on publisher_topic")

rate = rospy.Rate(1)            # 1Hz

count = Int32()                 # Count is now a ROS Int32 type variable that is ready to be published

count.data = 0                  # Initializing count

while not rospy.is_shutdown():  # Run the node until Ctrl-C is pressed

	pub.publish(count)          # Publishing data on topic "publisher_topic"
  
	count.data += 1
	
	rate.sleep()                # The loop runs at 1Hz