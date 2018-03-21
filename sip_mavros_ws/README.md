## Build ##
`$ catkin_make`


## Run ##
on a terminal

`$ ./runPX4Manager.sh <pxhawk port>`

on another terminal

`$ source devel/setup.bash`

`$ rosrun sip_mavros sip_mavros_para_accept_rc_node`


## End ##
`$ rostopic pub -1 /sip/quit std_msgs/Empty`


## Adjust PID parameter ##
`$ vi pid_param.xml`


## Help ##
`$ rosrun sip_mavros sip_mavros_para_accept_rc_node -h`

