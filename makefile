all: max_flow

max_flow: max_flow.o
	g++ -std=c++11 main.cpp max_flow.o -g -o max_flow -O3

max_flow.o: max_flow.cpp
	g++ -std=c++11 max_flow.cpp -g -c -o max_flow.o -O3

clean:
	rm max_flow
	rm max_flow.o
