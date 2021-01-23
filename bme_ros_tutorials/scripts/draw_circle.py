#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist      # We'll use Twist message in the node

rospy.init_node('turtlesim_draw_circle') # Init the node with name "turtlesim_draw_circle"

pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=1)

rospy.loginfo("Turtlesim draw circle node has started!")

rate = rospy.Rate(20) # 20Hz

msg = Twist()
msg.linear.x  = 1
msg.angular.z = 1

while not rospy.is_shutdown(): # Run the node until Ctrl-C is pressed

    pub.publish(msg)           # Publishing twist message on topic "/turtle1/cmd_vel"
    #msg.linear.x += 0.005     # Uncomment this line to draw a spiral instead of circle
    rate.sleep()               # The loop runs at 20Hz