#! /bin/bash

sudo chmod 666 /dev/ttyACM* /dev/ttyUSB*

name="drone"
tmux new-window -n ${name}

tmux split-window -h -t ${name}.0
tmux split-window -v -t ${name}.0
tmux split-window -h -t ${name}.0
tmux split-window -v -t ${name}.3
tmux split-window -v -t ${name}.1
tmux split-window -v -t ${name}.1
tmux split-window -h -t ${name}.6
tmux split-window -h -t ${name}.5
tmux split-window -v -t ${name}.5
tmux split-window -v -t ${name}.8
tmux split-window -v -t ${name}.0

#/home/${USER}/Documents/open_source/
tmux send-keys -t ${name}.0  'cd sip_mavros_ws' C-m
tmux send-keys -t ${name}.1  'cd hector_slam_test_ws' C-m
tmux send-keys -t ${name}.2  'cd sip_mavros_ws' C-m
tmux send-keys -t ${name}.3  'cd sip_scenario_ws' C-m
#tmux send-keys -t ${name}.4  'cd /home/${USER}/Documents/open_source/' C-m
tmux send-keys -t ${name}.5  'cd hokuyo_node_ws' C-m
tmux send-keys -t ${name}.6  'cd sip_tf_manager_ws' C-m
tmux send-keys -t ${name}.7  'cd lightware_ws' C-m
tmux send-keys -t ${name}.8  'cd sip_scenario_ws' C-m
tmux send-keys -t ${name}.9  'cd lightware_ws' C-m
#tmux send-keys -t ${name}.10 'cd /home/${USER}/Documents/open_source/' C-m
#tmux send-keys -t ${name}.11 'cd /home/${USER}/Documents/open_source/' C-m

tmux send-keys -t ${name}.0  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.1  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.2  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.3  'source devel/setup.bash' C-m
#tmux send-keys -t ${name}.4  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.5  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.6  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.7  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.8  'source devel/setup.bash' C-m
tmux send-keys -t ${name}.9  'source devel/setup.bash' C-m
#tmux send-keys -t ${name}.10 'source devel/setup.bash' C-m
#tmux send-keys -t ${name}.11 'source devel/setup.bash' C-m

tmux send-keys -t ${name}.10 'roscore' C-m

sleep 3

tmux send-keys -t ${name}.2  './runPX4Manager.sh /dev/ttyACM0' C-m
tmux send-keys -t ${name}.3  'rosservice call /lamp "target: x: 0.0 y: 0.0 z: 0.0"'
tmux send-keys -t ${name}.4  'echo "rosbag record -a"' C-m
tmux send-keys -t ${name}.5  'roslaunch hokuyo_node hokuyo_test.launch' C-m
tmux send-keys -t ${name}.6  'rosrun sip_tf_manager sip_tf_manager_node' C-m
tmux send-keys -t ${name}.7  'rostopic echo /altitude' C-m
tmux send-keys -t ${name}.8  'rosrun sip_scenario sip_scenario_node' C-m
tmux send-keys -t ${name}.9  'rosrun altitude_sensor altitude_sensor_node' C-m
tmux send-keys -t ${name}.11 'rostopic pub -1 /sip/quit std_msgs/Empty' C-m

sleep 3

tmux send-keys -t ${name}.1  'roslaunch hector_slam_example hector_hokuyo.launch' C-m

sleep 3

tmux send-keys -t ${name}.0  'rosrun sip_mavros sip_mavros_node'
