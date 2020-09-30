CXX = g++
CXXFLAGS = -Wall -g

main: main.o me.o
	$(CXX) $(CXXFLAGS) -o main main.o me.o
main.o: main.cpp me.h
	$(CXX) $(CXXFLAGS) -c main.cpp
me.o: me.h
