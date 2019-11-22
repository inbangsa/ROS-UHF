
#include <std_msg/string> //there may be conflict between std::String and std_msg/string. 
#include "ros/ros.h"



void scanCallback(const scan_data *data)
{
ROS_INFO("Scan DAta : EPC", data->EPC);

}
int main(int argc, char**argv)
{

ros::init(argc, argv,"uhf_node_client");
ros::NodeHandle n; 
ros::Subscriber sub=n.advertise<scan_data>("/readUHFTag", 1000,scanCallback);
ros::spin();
}
