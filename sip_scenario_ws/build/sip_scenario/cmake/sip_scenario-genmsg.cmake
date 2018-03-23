# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "sip_scenario: 0 messages, 5 services")

set(MSG_I_FLAGS "-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(sip_scenario_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv" NAME_WE)
add_custom_target(_sip_scenario_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sip_scenario" "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv" ""
)

get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv" NAME_WE)
add_custom_target(_sip_scenario_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sip_scenario" "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv" ""
)

get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv" NAME_WE)
add_custom_target(_sip_scenario_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sip_scenario" "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv" "geometry_msgs/Point"
)

get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv" NAME_WE)
add_custom_target(_sip_scenario_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sip_scenario" "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv" ""
)

get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv" NAME_WE)
add_custom_target(_sip_scenario_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "sip_scenario" "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages

### Generating Services
_generate_srv_cpp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
)
_generate_srv_cpp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
)
_generate_srv_cpp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
)
_generate_srv_cpp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
)
_generate_srv_cpp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
)

### Generating Module File
_generate_module_cpp(sip_scenario
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(sip_scenario_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(sip_scenario_generate_messages sip_scenario_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_cpp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_cpp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_cpp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_cpp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_cpp _sip_scenario_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sip_scenario_gencpp)
add_dependencies(sip_scenario_gencpp sip_scenario_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sip_scenario_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages

### Generating Services
_generate_srv_lisp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
)
_generate_srv_lisp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
)
_generate_srv_lisp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
)
_generate_srv_lisp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
)
_generate_srv_lisp(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
)

### Generating Module File
_generate_module_lisp(sip_scenario
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(sip_scenario_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(sip_scenario_generate_messages sip_scenario_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_lisp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_lisp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_lisp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_lisp _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_lisp _sip_scenario_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sip_scenario_genlisp)
add_dependencies(sip_scenario_genlisp sip_scenario_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sip_scenario_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages

### Generating Services
_generate_srv_py(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
)
_generate_srv_py(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
)
_generate_srv_py(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
)
_generate_srv_py(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
)
_generate_srv_py(sip_scenario
  "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
)

### Generating Module File
_generate_module_py(sip_scenario
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(sip_scenario_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(sip_scenario_generate_messages sip_scenario_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/NearToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_py _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/AccessToFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_py _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LampInput.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_py _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/StopScenario.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_py _sip_scenario_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/ikeda/editing_ros/open_source/open_source/sip_scenario_ws/src/sip_scenario/srv/LeaveFromFloor.srv" NAME_WE)
add_dependencies(sip_scenario_generate_messages_py _sip_scenario_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(sip_scenario_genpy)
add_dependencies(sip_scenario_genpy sip_scenario_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS sip_scenario_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/sip_scenario
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(sip_scenario_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(sip_scenario_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/sip_scenario
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(sip_scenario_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(sip_scenario_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/sip_scenario
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(sip_scenario_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(sip_scenario_generate_messages_py geometry_msgs_generate_messages_py)
endif()
