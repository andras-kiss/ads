#!/bin/sh
echo set grid
while true; do
 #echo set yrange \[-2000:2000\]
 echo set xlabel \"time, s\"
 echo set ylabel \"E, mV\"
 sh ./plotline.sh
 #echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d'\)"\" with lines lc rgb \"red\" notitle
 #echo set xrange \[GPVAL_X_MIN:GPVAL_X_MAX\]
sleep 1
done

