#include <ros/ros.h>
#include <nodelet/loader.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "rplidar_scan_node");


  nodelet::Loader nodelet;
  nodelet::M_string remap(ros::names::getRemappings());
  nodelet::V_string nargv;
  std::string nodelet_name = ros::this_node::getName();
  nodelet.load(nodelet_name, "integration/integrate_and_fire_nodelet", remap, nargv);

  //boost::shared_ptr<ros::MultiThreadedSpinner> spinner;
  //spinner.reset(new ros::MultiThreadedSpinner());

  ros::spin();
  return 0;

}
