
#include <std_msg/string> //there may be conflict between std::String and std_msg/string. 
#include "ros/ros.h"
#include "std_srvs/Empty.h"
#include "UHFDriver.h"
#include "DummyDevice.h"
#include <memory>


bool Connect(std::shared_ptr<UHFDriver> drv)
{
drv->connect();// call the connect fucntion,.
if(drv->IsConnected())
{
return true;

}

else
{
 return false;
}

}

bool Disconnect(std::shared_ptr<UHFDriver> drv);
{

drv->Disconnect();//disconect function is called;
if(!(drv->IsConnected()))
{
return true;

}

else
{
 return false;
}

}



bool StartScan(GetData::Request &req,
                              GetData::Response &res)
{
if(isConnected())
//start scan.


}
bool StopScan(std_srvs::Empty::Request &req,
                               std_srvs::Empty::Response &res)
{


if (IsConnected())
{

//stop the scan.
return true;
}

}

bool WriteDataToTag(write_on_tag::Request &req,write_on_tag::Response &res)
{
if(IsConnected())
{
res.status_of_write_data=WriteToTag(int port, req.write_data);
return res.status_of_write_data;

}

}

bool GetDataFromReader(ros::Publisher *pub, bool synchrous/ansynchousmode, bool fromalltags/onetag)
{

if(Readalltag is called)
{
std::vector<std::string>data_from_all_tags=ReadAllTags();
}

else if( ReadSpecificTag is called )

{

string data_of_specific_tag=ReadSpecificTag(int tag_id);		
static int specific_tag_read_count=0;
scan_data msg;
//msg.header=
msg.length=sizeof(data_of_specific_tag.data);
msg.EPC=data;
msg.port=data_of_specific_tag.port);
//msg.count=
	specific_tag_read_count++;
pub->publish(msg);
}
return true;
}

int main(int argc, char**argv)
{

//Initializing the Node
    ros::init(argc, argv, "uhf_node_server");

//Node Handle   
 ros::NodeHandle nh;

//Services
    ros::ServiceServer start_scan_service = nh.advertiseService("StartScan", StartScan);
    ros::ServiceServer stop_scan_service = nh.advertiseService("StopScan", StopScan);

//Publisher
    ros::Publisher scan_pub = nh.advertise<scan_data>("readUHFTag", 1000);

while(ros::ok())
{
std::vector<msg> recieved_data=GetDataFromReader(&scan_pub, bool mode(????synchrous/ansynchousmode), bool fromalltags/onetag)

for(auto x:recieved_data)
{

ROSOUT("%s,x.EPC.c_str());
//print more values
}
}

}

