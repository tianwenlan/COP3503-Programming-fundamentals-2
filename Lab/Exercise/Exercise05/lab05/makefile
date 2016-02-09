CXX = g++
CXXFLAGS = -c -Wall
LDFLAGS =

all: group

group: main.o group.o	
	$(CXX) $(LDFLAGS) -o graph main.o graph.o
main.o: main.cpp group.h
	$(CXX) $(CXXFLAGS) main.cpp
group.o: group.cpp group.h
	$(CXX) $(CXXFLAGS) group.cpp

clean:
	rm -rf *.o group
