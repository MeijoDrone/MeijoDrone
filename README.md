# MeijoDrone

Autopilotファームウェアを搭載したPixhawkを使用し，ubuntuマシン上でROSを走らせ，lightware SF10/Bによる高度計測，Simple URGを使用したSLAMによる水平位置推定を行うことを想定した構成になっています．また目標位置を入力するとRamp入力で目標位置を生成します．

PixhawkとPCをMAVLINKで接続するために，mavrosをインストールして下さい．\
$ sudo apt-get install ros-kinetic-mavros\
$ sudo apt-get install ros-kinetic-mavros-extras\
$ sudo apt-get install ros-kinetic-mavros-msgs\
mavrosで通信できるように以下を実行\
user:/opt/ros/kinetic/lib/mavros$ sudo ./install_geographiclib_datasets.sh

リポジトリに置かれているパッケージは以下の3つです．\
sip_mavros_ws （位置制御）\
sip_tf_manager_ws （TFの管理）\
sip_scenario_ws （Ramp目標位置を生成）

ROSでセンサとSLAMを制御するために以下のパッケージを各々ダウンロードして下さい．\
ros_lightware <https://github.com/wavelab/ros_lightware>\
cereal_port <https://github.com/wavelab/cereal_port>\
hokuyo_node <https://github.com/ros-drivers/hokuyo_node> (urg_nodeで代替可能)\
hector_slam <https://github.com/tu-darmstadt-ros-pkg/hector_slam>\
hector_slam_example <https://github.com/DaikiMaekawa/hector_slam_example>

lightware_wsを作成し，ros_lightwareとcereal_portをMakeして下さい（高度計測）．\
hokuyo_node_wsを作成し，hokuyo_nodeをMakeして下さい（測域計）．\
hector_slam_wsを作成し，hector_slamとhector_slam_exampleをMakeして下さい（SLAM）．

sip_mavros_nodeではPIDフィードバックで位置制御しています．\
sip_mavros_wsディレクトリ直下にPIDゲインを設定する\
param_hexa.xml\
があります．機体に合わせて調節する必要があります．\
Autopilotを含めたUAVシステムでは，Autopilot内の姿勢制御パラメータと本位置制御パラメータを調整する必要があります．
まず，Autopilotの姿勢制御パラメータを調整します．
オートチューニングを使用することをお勧めします．
次に位置制御パラメータを調整します．

また，リポジトリにnodeをまとめてrosrunするシェルスクリプトを置いています．上記のディレクトリ名にしているとそのまま使用することができます．ワークスペースや.shを同一のディレクトリに置き，tmuxを起動したのちに.shを走らせると自動でrosrunします．\
start_drone.sh

以下にtmux内で表示される各ウィンドウの役割をまとめます．\
0: sip_mavros_node\
1: hector SLAM\
2: Pixhawkとの通信メッセージ\
3: 目標位置入力"target: x:前 y:左 z:上”（入力する前に一度tab keyを押します）\
4: rosbagを走らせるコマンド\
5: hokuyo_node\
6: sip_tf_manager_node\
7: 高度（/altitude）を表示\
8: ros_scenario_node\
9: lightware_node\
10: roscoe\
11: sip_mavros_nodeを強制終了するコマンド

以下に各nodeのSubscriberおよびPublisherをまとめます．\
sip_mavros_node (in sip_mavros_ws)\
Subscriber:\
"mavros/state" <mavros_msgs::State> \
"/sip/target_point" <geometry_msgs::Point>\
"/sip/target_yaw" <std_msgs::Float64>\
"/sip/quit" <std_msgs::Empty>\
"/mavros/rc/in" <mavros_msgs::RCIn>\
"/mavros/battery" <sensor_msgs::BatteryState>\
"/slam_out_pose" <geometry_msgs::PoseStamped>\
"/altitude" <std_msgs::Float64>\
"/mavros/imu/data" <sensor_msgs::Imu>\
Publisher:\
"mavros/setpoint_raw/attitude" <mavros_msgs::AttitudeTarget>\
"mavros/cmd/arming" <mavros_msgs::CommandBool>\
"mavros/set_mode" <mavros_msgs::SetMode>


sip_tf_manager_node (in sip_tf_manager_ws)\
Subscriber:\
/altitude <std_msgs::Float64>\
/mavros/imu/data <sensor_msgs::Imu>\
/slam_out_pose <geometry_msgs::PoseStamped>\
Publisher:\
TF


sip_scenario_node (in sip_scenario_ws)\
Publisher:\
/sip/target_point <geometry_msgs::Point>


hokuyo_node (in hokuyo_ws)\
Publisher:\
/scan <sensor_msgs::LaserScan


hector_slam_node (hector_slam)\
Publisher:\
/slam_out_pose <geometry_msgs::PoseStamped>


lightware_node (in lightware_ws)\
Publisher:\
"/altitude" <std_msgs::Float64> (changed)

