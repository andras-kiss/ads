screen -d -m -S ads /dev/ttyUSB0 115200
screen -S ads -X logfile data.dat
screen -S ads -X log
./loop.sh
