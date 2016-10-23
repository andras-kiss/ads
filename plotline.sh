echo plot \""<\(tail -n '-50000' data.dat | sed -e '$ d' | sed -e '1 d'\)"\" with lines lc rgb \"red\" notitle

