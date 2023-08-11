# Install script for directory: /home/goudan/srbot_ws-C/src/orbbec_camera

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/goudan/srbot_ws-C/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera/msg" TYPE FILE FILES
    "/home/goudan/srbot_ws-C/src/orbbec_camera/msg/DeviceInfo.msg"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/msg/Extrinsics.msg"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/msg/Metadata.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera/srv" TYPE FILE FILES
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetBool.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/SetBool.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetCameraInfo.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetCameraParams.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetDeviceInfo.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetInt32.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/GetString.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/SetInt32.srv"
    "/home/goudan/srbot_ws-C/src/orbbec_camera/srv/SetString.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera/cmake" TYPE FILE FILES "/home/goudan/srbot_ws-C/build/orbbec_camera/catkin_generated/installspace/orbbec_camera-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/devel/include/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/devel/share/roseus/ros/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/devel/share/common-lisp/ros/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/devel/share/gennodejs/ros/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/goudan/srbot_ws-C/devel/lib/python3/dist-packages/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/devel/lib/python3/dist-packages/orbbec_camera")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/goudan/srbot_ws-C/build/orbbec_camera/catkin_generated/installspace/orbbec_camera.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera/cmake" TYPE FILE FILES "/home/goudan/srbot_ws-C/build/orbbec_camera/catkin_generated/installspace/orbbec_camera-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera/cmake" TYPE FILE FILES
    "/home/goudan/srbot_ws-C/build/orbbec_camera/catkin_generated/installspace/orbbec_cameraConfig.cmake"
    "/home/goudan/srbot_ws-C/build/orbbec_camera/catkin_generated/installspace/orbbec_cameraConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera" TYPE FILE FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/goudan/srbot_ws-C/devel/lib/liborbbec_camera.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so"
         OLD_RPATH "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_calib3d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_core:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_features2d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_flann:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_highgui:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgcodecs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ml:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_photo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stitching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_video:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videoio:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_aruco:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bgsegm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bioinspired:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ccalib:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_datasets:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dpm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_face:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_freetype:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_fuzzy:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hdf:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hfs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_img_hash:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_line_descriptor:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_optflow:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_phase_unwrapping:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_plot:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_quality:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_reg:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_rgbd:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_saliency:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_shape:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stereo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_structured_light:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_surface_matching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_text:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_tracking:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videostab:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_viz:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ximgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xobjdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xphoto:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/liborbbec_camera.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera" TYPE EXECUTABLE FILES "/home/goudan/srbot_ws-C/devel/lib/orbbec_camera/orbbec_camera_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node"
         OLD_RPATH "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_calib3d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_core:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_features2d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_flann:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_highgui:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgcodecs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ml:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_photo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stitching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_video:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videoio:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_aruco:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bgsegm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bioinspired:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ccalib:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_datasets:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dpm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_face:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_freetype:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_fuzzy:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hdf:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hfs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_img_hash:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_line_descriptor:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_optflow:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_phase_unwrapping:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_plot:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_quality:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_reg:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_rgbd:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_saliency:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_shape:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stereo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_structured_light:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_surface_matching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_text:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_tracking:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videostab:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_viz:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ximgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xobjdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xphoto:/home/goudan/srbot_ws-C/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/orbbec_camera_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera" TYPE EXECUTABLE FILES "/home/goudan/srbot_ws-C/devel/lib/orbbec_camera/list_devices_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node"
         OLD_RPATH "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_calib3d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_core:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_features2d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_flann:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_highgui:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgcodecs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ml:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_photo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stitching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_video:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videoio:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_aruco:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bgsegm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bioinspired:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ccalib:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_datasets:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dpm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_face:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_freetype:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_fuzzy:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hdf:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hfs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_img_hash:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_line_descriptor:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_optflow:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_phase_unwrapping:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_plot:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_quality:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_reg:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_rgbd:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_saliency:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_shape:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stereo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_structured_light:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_surface_matching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_text:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_tracking:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videostab:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_viz:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ximgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xobjdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xphoto:/home/goudan/srbot_ws-C/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_devices_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera" TYPE EXECUTABLE FILES "/home/goudan/srbot_ws-C/devel/lib/orbbec_camera/ob_cleanup_shm_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node"
         OLD_RPATH "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_calib3d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_core:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_features2d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_flann:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_highgui:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgcodecs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ml:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_photo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stitching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_video:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videoio:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_aruco:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bgsegm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bioinspired:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ccalib:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_datasets:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dpm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_face:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_freetype:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_fuzzy:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hdf:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hfs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_img_hash:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_line_descriptor:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_optflow:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_phase_unwrapping:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_plot:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_quality:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_reg:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_rgbd:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_saliency:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_shape:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stereo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_structured_light:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_surface_matching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_text:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_tracking:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videostab:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_viz:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ximgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xobjdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xphoto:/home/goudan/srbot_ws-C/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/ob_cleanup_shm_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera" TYPE EXECUTABLE FILES "/home/goudan/srbot_ws-C/devel/lib/orbbec_camera/list_depth_work_mode_node")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node"
         OLD_RPATH "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_calib3d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_core:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_features2d:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_flann:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_highgui:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgcodecs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_imgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ml:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_photo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stitching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_video:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videoio:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_aruco:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bgsegm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_bioinspired:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ccalib:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_datasets:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_objdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dnn_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_dpm:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_face:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_freetype:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_fuzzy:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hdf:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_hfs:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_img_hash:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_line_descriptor:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_optflow:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_phase_unwrapping:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_plot:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_quality:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_reg:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_rgbd:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_saliency:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_shape:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_stereo:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_structured_light:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_superres:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_surface_matching:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_text:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_tracking:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_videostab:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_viz:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_ximgproc:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xobjdetect:/home/goudan/srbot_ws-C/src/orbbec_camera/opencv_xphoto:/home/goudan/srbot_ws-C/devel/lib:/opt/ros/noetic/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/orbbec_camera/list_depth_work_mode_node")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/orbbec_camera/" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/include")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/orbbec_camera/" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/launch")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/orbbec_camera" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/config")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/" TYPE DIRECTORY FILES "/home/goudan/srbot_ws-C/src/orbbec_camera/SDK/lib/x64/" FILES_MATCHING REGEX "/[^/]*\\.so$" REGEX "/[^/]*\\.so\\.[^/]*$")
endif()

