#! /bin/bash

if [ $# -lt 1 ]
then
	echo "Usage: ${0} <device port>"
	echo "Ex: ${0} /dev/ttyACM0"
	exit 31
fi

DEVICE="${1}"

roslaunch mavros px4.launch fcu_url:="${DEVICE}:57600"
