all: ff

ff: ff.o
	g++ -std=c++11 main.cpp ff.o -g -o ff -O3

ff.o: ff.cpp
	g++ -std=c++11 ff.cpp -g -c -o ff.o -O3

clean:
	rm ff
	rm ff.o
