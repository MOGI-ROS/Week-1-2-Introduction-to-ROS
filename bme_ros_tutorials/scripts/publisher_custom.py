#!/usr/bin/env python

import rospy
from bme_ros_tutorials.msg import Test  # Message type used in the node

rospy.init_node('publisher_custom')    # Init the node with name "publisher"

pub = rospy.Publisher('publisher_custom_topic', Test, queue_size=10)

rospy.loginfo("Publisher Python node has started and publishing data on publisher_topic")

rate = rospy.Rate(1)            # 1Hz

testMessage = Test()
testMessage.first_name = "David"
testMessage.last_name  = "Dudas"
testMessage.age        = 8
testMessage.score      = 0

while not rospy.is_shutdown():  # Run the node until Ctrl-C is pressed

	pub.publish(testMessage)          # Publishing data on topic "publisher_topic"
  
	testMessage.score += 1
	
	rate.sleep()                # The loop runs at 1Hz