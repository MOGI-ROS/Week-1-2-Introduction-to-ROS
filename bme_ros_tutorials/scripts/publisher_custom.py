#!/usr/bin/env python3

import rospy
from bme_ros_tutorials.msg import Test # Our custom message type used in the node

rospy.init_node('publisher_custom')    # Init the node with name "publisher_custom"

pub = rospy.Publisher('publisher_custom_topic', Test, queue_size=10)

rospy.loginfo("Custom publisher Python node has started and publishing data on publisher_custom_topic")

rate = rospy.Rate(5) # 5Hz

testMessage = Test()
testMessage.first_name = "David"
testMessage.last_name  = "Dudas"
testMessage.age        = 34
testMessage.score      = 0

while not rospy.is_shutdown(): # Run the node until Ctrl-C is pressed

    pub.publish(testMessage)   # Publishing data on topic "publisher_custom_topic"
    
    testMessage.score += 1
    
    rate.sleep()               # The loop runs at 5Hz