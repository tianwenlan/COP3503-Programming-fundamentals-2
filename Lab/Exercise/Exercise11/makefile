all: shape

shape: main.o shape.o
	g++ -o shape main.o shape.o

main.o: main.cpp defs.h
	g++ -c main.cpp

shape.o: shape.cpp defs.h
	g++ -c shape.cpp


clean:
	rm -rf *.o shape
