build for ubuntu 20 and ros noetic
  (1) multiscan... crash
    fix: remove a line in CMakeLists.txt about native
  (2) frame_id in cpp files fixed for noetic
    remove "/" in frame_id at various place

-------- pcl_example -------------------
pcl code example

-------build c c++ pkg for debugging-------------------------
     catkin_make --pkg loam_velodyne -DCMAKE_BUILD_TYPE=Debug

see readme_misc.txt for enable coredump
