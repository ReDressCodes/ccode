#!/bin/bash

# Replace 'redress' with your username with `sed -i 's/redress/<username>/g' overlay.sh`
#

LOWER="/home/redress/lower.ext4"
UPPER="/home/redress/upper.ext4"

LOWER_FILE="/home/redress/lower/lower-file"
UPPER_FILE="/home/redress/upper/upper-file"
OVERLAY_FILE="/home/redress/overlay/overlay-file"

OVERLAY_DIR="/home/redress/overlay"
UPPER_DIR="/home/redress/upper/upper"
LOWER_DIR="/home/redress/lower"
WORK_DIR="/home/redress/upper/work"

if [ ! -d $OVERLAY_DIR ]; then
	mkdir $OVERLAY_DIR
fi

if [ ! -d $LOWER_DIR ]; then
	mkdir $LOWER_DIR
fi

if [ ! -d "/home/redress/upper" ]; then
	mkdir "/home/redress/upper"
fi

if [ ! -f $LOWER ]; then
	dd if=/dev/zero of=$LOWER count=2000 bs=1024
fi

if [ ! -f $UPPER ]; then
	dd if=/dev/zero of=$UPPER count=2000 bs=1024
fi

sudo mount lower.ext4 $LOWER_DIR
sudo mount upper.ext4 "/home/redress/upper"

printf lower-content > $LOWER_FILE

if [ ! -d $UPPER_DIR ]; then
	mkdir "/home/redress/upper/upper"
fi

if [ ! -d $WORK_DIR ]; then
	mkdir "/home/redress/upper/work"
fi

printf upper-content > $UPPER_FILE
sudo mount -o remount,ro lower.ext4 $LOWER_DIR

sudo mount \
  -t overlay \
  -o lowerdir=$LOWER_DIR,upperdir=$UPPER_DIR,workdir=$WORK_DIR \
  none \
  $OVERLAY_DIR \
;

printf "overlay-content" > $OVERLAY_FILE 
ls $LOWER_DIR $UPPER_DIR $WORK_DIR $OVERLAY_DIR
