echo plot \""<\(tail -n '-10000' $\(ls -t | head -n1\) | sed -e '$ d' | sed -e '1 d'\)"\" with lines lc rgb \"red\" notitle
echo set yrange \[-1100:1100\]
echo set xlabel \"time, s\" 
echo set ylabel \"E, mV\" 
