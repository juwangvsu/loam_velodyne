build for ubuntu 20 and ros noetic
  (1) multiscan... crash
    fix: remove a line in CMakeLists.txt about native
  (2) frame_id in cpp files fixed for noetic
    remove "/" in frame_id at various place

----------test rosbag file----------------
roslaunch loam_velodyne loam_velodyne.launch
rosbag play 2011_09_30_0018.bag --topic velodyne_points

slow, registered lidar point 0.2 hz, did not publish map?

------ test pcap data -------------
roslaunch velodyne_pointcloud VLP16_points.launch pcap:="$HOME/Documents/datasets/loam/2014-11-10-10-36-54_Velodyne-VLP_10Hz-County-Fair.pcap"
roslaunch loam_velodyne loam_velodyne.launch

-------- pcl_example -------------------
pcl code example

-------build c c++ pkg for debugging-------------------------
     catkin_make --pkg loam_velodyne -DCMAKE_BUILD_TYPE=Debug

see readme_misc.txt for enable coredump
