#echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d' | sed -e '1 d'\)"\" u \(\$1\):\(\$2/2\) with lines lc rgb \"red\" notitle
echo plot \""<\(tail -n '-10000' $\(ls -t | head -n1\) | sed -e '$ d' | sed -e '1 d'\)"\" with lines lc rgb \"red\" notitle
#ls -t | head -n1
#echo set yrange \[343:343.5\]
echo set yrange \[-1100:1100\]
