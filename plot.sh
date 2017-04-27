#!/bin/sh
echo set grid
while true; do
<<<<<<< HEAD
 #echo set yrange \[-2000:2000\]
 echo set xlabel \"time, s\"
 echo set ylabel \"E, mV\"
=======
>>>>>>> fefabb2232c32f82bd33edeeb9bb807e42c5014a
 sh ./plotline.sh
 #echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d'\)"\" with lines lc rgb \"red\" notitle
sleep 1
done

