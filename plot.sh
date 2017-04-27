#!/bin/sh
echo set grid
while true; do
 sh ./plotline.sh
 #echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d'\)"\" with lines lc rgb \"red\" notitle
sleep 1
done

