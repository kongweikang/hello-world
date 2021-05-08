#include "ros/ros.h"
#include "std_msgs/String.h"
 

void StrCallback(const std_msgs::String::ConstPtr& msg)   //callback函数，收到msg时调用
{
  ROS_INFO("I heard msgs: [%s]", msg->data.c_str());
}
 
int main(int argc, char **argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("chatter", 1000, StrCallback);
  ros::spin();//程序运行到此进入等待，直到收到话题然后回调到主函数运行一边
 
  return 0;
}