now=$(date +"%Y%m%d_%I%M%p")
file="$now.dat"
screen -d -m -S ads /dev/ttyUSB0 115200
screen -S ads -X logfile "$file"
screen -S ads -X log
./plot.sh | gnuplot
