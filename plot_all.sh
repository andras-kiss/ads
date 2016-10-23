#!/bin/sh
echo set grid
while true; do
 echo set yrange \[-2000:2000\]
 echo set xlabel \"time, s\"
 echo set ylabel \"E, mV\"
 echo plot \""<\(sed -e '$ d' data.dat\)"\" with lines lc rgb \"black\" notitle
 #echo plot \""<\(tail -n '-5000' data.dat\)"\" with lines lc rgb \"red\" notitle
 sleep 2
done

