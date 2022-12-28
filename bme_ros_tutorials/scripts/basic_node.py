#!/usr/bin/env python

import rospy

count=0
rospy.init_node('basic_node')  # Init the node with name "basic_node"
rate = rospy.Rate(1)           # 1Hz

while not rospy.is_shutdown(): # run the node until Ctrl-C is pressed

    # print info to std out
    rospy.loginfo("basic_node python is running. count= %d",count)
    
    count+=1
    
    rate.sleep() # The loop runs at 1Hz