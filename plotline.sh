echo set yrange \[-1000:1000\]
#echo set yrange \[-512:512\]
echo set xlabel \"time, s\"
echo set ylabel \"E, mV\"
echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d' | sed -e '1 d'\)"\" with lines lc rgb \"red\" notitle

