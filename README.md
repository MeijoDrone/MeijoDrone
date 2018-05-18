# MeijoDrone

Autopilotファームウェアを搭載したPixhawkを使用し，ubuntuマシン上でROSを走らせ，lightware SF10/Bによる高度計測，Simple URGを使用したSLAMによる水平位置推定を行うことを想定した構成になっています．また目標位置を入力するとRamp入力で目標位置を生成します．安全のためにプロポと併用して運用します．

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

hokuyo_nodeをmakeするためにros-driver/driver_commonをインストールする必要があります．\
$ sudo apt-get install ros-kinetic-driver-common

ワークスペースは個別に作成しています．\
lightware_wsを作成し，ros_lightwareとcereal_portをMakeして下さい（高度計測）．\
hokuyo_node_wsを作成し，hokuyo_nodeをMakeして下さい（測域計）．\
hector_slam_wsを作成し，hector_slamとhector_slam_exampleをMakeして下さい（SLAM）．\
またhector_hokuyo.launchでtfを発行しているため，コメントアウトします．\
$ emacs ./hector_slam_ws/src/hector-slam-example/launch/hector_hokuyo.launch\
以下をコメントアウト．
=-=-=-=-=\
\<node pkg="tf" type="static_transform_publisher" name="map_2_odom" args="0 0 0 0 0 0 /map /odom 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="map_2_odom" args="0 0 0 0 0 0 /map /odom 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="odom_2_base_footprint" args="0 0 0 0 0 0 /odom /base_footprint 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="base_footprint_2_base_link" args="0 0 0 0 0 0 /base_footprint /base_link 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="base_link_2_base_stabilized_link" args="0 0 0 0 0 0 /base_link /base_stabilized 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="base_stablized_2_base_frame" args="0 0 0 0 0 0 /base_stabilized /base_frame 100"/>\
\<node pkg="tf" type="static_transform_publisher" name="base_frame_2_laser_link" args="0 0 0 0 0 0 /base_frame /laser 100"/>\
=-=-=-=-=

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

sip_mavros_nodeはプロポの制御信号をPixhawk・MAVROSを経由して参照します．使用するプロポのスティックは7箇所です．プロポのスイッチ番号の設定を適切に行ってください．\
ロール（sw 0）：ロール操縦・緊急介入（デジタルで±50傾ける）\
ピッチ（sw 1）：ピッチ操縦・緊急介入（デジタルで±50傾ける）\
ヨー（sw 3）：ヨー操縦・緊急介入（デジタルで±50傾ける）\
右手トリム（sw 5）：目標高度割合R（Highest R = 1 ~ Lowest R = 0，目標高度 = 入力目標高度*R）\
任意スイッチ（sw 6）：HIGH=プログラム開始，LOW=プログラム終了\
任意スイッチ（sw 8）：HIGH=マニュアル操縦，LOW=自動操縦\
任意スイッチ：PixhawkのOffboard Mode切り替え（nodeは参照しません）

sip_mavros_nodeをターミナル上で開始すると，Offboard Modeへの切り替えを待機します．\
プロポでOffboard Modeに切り替えると，sw 6のプログラム開始を待機します．\
プログラムが開始するとプロペラが回転します．任意の目標位置を入力してください．\
sw 5で入力した目標高度を割合で減少することが可能です．\
自動操縦の状態でロール・ピッチ・ヨーで緊急介入すると，その後，常時マニュアル操縦になります．ただし高度は自動で制御されます．\
プログラムを終了させる場合は十分に高度を低くしてからsw 6を切り替えてください．sw 6はホバー状態でもプログラムを終了するので緊急停止としても使用できます．\
プログラム終了後にPixhawkが警告音を鳴らしますが，Offboard Modeの状態で制御信号が入力されていないためです．プロポでOffboard Modeを終了してください．


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

