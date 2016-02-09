all: Proj4

Proj4: main.o
	g++ -o Proj4 main.o

main.o: main.cpp multiset.h
	g++ -c main.cpp


clean:
	rm -rf *.o
	rm Proj4
