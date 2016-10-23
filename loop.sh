#!/bin/sh
"set grid" | gnuplot
while true; do
 ./plot.sh | gnuplot
 sleep 1
done
