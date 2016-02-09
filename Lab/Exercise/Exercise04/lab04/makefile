CXX = g++
CXXFLAGS = -c -Wall
LDFLAGS =

all: graph

graph: graphmenu.o graph.o	
	$(CXX) $(LDFLAGS) -o graph graphmenu.o graph.o
graphmenu.o: graphmenu.cpp graph.h
	$(CXX) $(CXXFLAGS) graphmenu.cpp
graph.o: graph.cpp graph.h
	$(CXX) $(CXXFLAGS) graph.cpp

clean:
	rm -rf *.o graph
