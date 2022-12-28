#!/usr/bin/env python3

import rospy
from geometry_msgs.msg import Twist # We'll use Twist message in the node
import turtlesim.srv                # This contains the service for changing the pen
import std_srvs.srv                 # Clear service is a standard ROS service
import random

# This service call can clear the canvas
def clear():
    rospy.wait_for_service('clear')
    try:
        clear_s = rospy.ServiceProxy('clear', std_srvs.srv.Empty)
        clear_s()
        return
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

# This service call can turn on or off the pen and change its color to a random one
def set_pen(off):
    rospy.wait_for_service('turtle1/set_pen')
    try:
        set_pen_s = rospy.ServiceProxy('turtle1/set_pen', turtlesim.srv.SetPen)
        set_pen_s(random.randint(0,255),random.randint(0,255),random.randint(0,255),3,off)
        return
    except rospy.ServiceException as e:
        print("Service call failed: %s"%e)

rospy.init_node('turtlesim_draw_circle_services') # Init the node with name "turtlesim_draw_circle_services"

pub = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=1)

rospy.loginfo("Turtlesim draw circle - with service calls - node has started!")

rate = rospy.Rate(20) # 20Hz

msg = Twist()
msg.linear.x = 1
msg.angular.z = 1

counter = 0
pen_off = False
set_pen(pen_off)               # Initialize pen

while not rospy.is_shutdown(): # Run the node until Ctrl-C is pressed

    pub.publish(msg)           # Publishing twist message on topic "/turtle1/cmd_vel"

    counter+=1                 # Change pen state in every 0.5s
    if counter%10 == 0:
        pen_off = not pen_off
        set_pen(pen_off)

    rate.sleep()               # The loop runs at 20Hz