CXX = g++
CXXFLAGS = -c -Wall
LDFLAGS =

all: mergesort

mergesort: COP3503su14_HW02_G6_main.o COP3503su14_HW02_G6_mergesort.o COP3503su14_HW02_G6_data.o
	$(CXX) $(LDFLAGS) -o mergesort COP3503su14_HW02_G6_main.o COP3503su14_HW02_G6_mergesort.o COP3503su14_HW02_G6_data.o
COP3503su14_HW02_G6_main.o: COP3503su14_HW02_G6_main.cpp COP3503su14_HW02_G6_mergesort.h COP3503su14_HW02_G6_data.h
	$(CXX) $(CXXFLAGS) COP3503su14_HW02_G6_main.cpp
COP3503su14_HW02_G6_mergesort.o: COP3503su14_HW02_G6_mergesort.cpp COP3503su14_HW02_G6_mergesort.h 
	$(CXX) $(CXXFLAGS) COP3503su14_HW02_G6_mergesort.cpp
COP3503su14_HW02_G6_data.o: COP3503su14_HW02_G6_data.cpp COP3503su14_HW02_G6_data.h 
	$(CXX) $(CXXFLAGS) COP3503su14_HW02_G6_data.cpp

clean:
	rm -rf *.o mergesort
