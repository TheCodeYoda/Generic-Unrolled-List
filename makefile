a.out: unroll_list.o
	g++ unroll_list.o
unroll_list.o : unroll_list.cpp unroll_list.hpp
	g++ -c unroll_list.cpp
clean:
	rm -rf unroll_list.o
	rm -rf *~
