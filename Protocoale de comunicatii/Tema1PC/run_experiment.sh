#!/bin/bash


SPEED=1
DELAY=1
LOSS=0
CORRUPT=0

killall link
killall recv
killall send

./link_emulator/link speed=$SPEED delay=$DELAY loss=$LOSS corrupt=$CORRUPT &> /dev/null &
sleep 1
./recv $2 &
sleep 1

./send $1

sleep 2
echo "Finished transfer, checking files"
diff $1 $2
