#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int
main ()
{
  pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2 ());
  pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2 ());

  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud1_output(new pcl::PointCloud<pcl::PointXYZI>);
  pcl::PointCloud<pcl::PointXYZI>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZI>);
pcl::VoxelGrid<pcl::PointXYZI> downSizeFilter; 

  // Fill in the cloud data
  pcl::PCDReader reader;
  // Replace the path below with the path where you saved your file
  reader.read ("table_scene_lms400.pcd", *cloud1); // Remember to download the file first!

  std::cerr << "PointCloud before filtering: " << cloud1->width * cloud1->height 
       << " data points (" << pcl::getFieldsList (*cloud1) << ")." << std::endl;
/*
  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloud);
  sor.setLeafSize (0.01f, 0.01f, 0.01f);
  sor.filter (*cloud_filtered);

  std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height 
       << " data points (" << pcl::getFieldsList (*cloud_filtered) << ")." << std::endl;

  pcl::PCDWriter writer;
  writer.write ("table_scene_lms400_downsampled.pcd", *cloud_filtered, 
         Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);
*/
  downSizeFilter.setInputCloud (cloud1);
  downSizeFilter.setLeafSize (0.01f, 0.01f, 0.01f);
  downSizeFilter.filter (*cloud1_output);
  std::cerr << "PointCloud after filtering: " << cloud1_output->width * cloud1_output->height 
       << " data points (" << pcl::getFieldsList (*cloud1_output) << ")." << std::endl;

  pcl::PCDWriter writer;
  writer.write ("table_scene_lms400_downsampled.pcd", *cloud1_output, 
         false);
  return (0);
}
