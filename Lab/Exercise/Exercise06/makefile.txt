all: debugfun

debugfun: broken.o strstuff.o
	g++ -g broken.o strstuff.o -o debugfun

broken.o: broken.cpp strstuff.h
	g++ -c -g broken.cpp

strstuff.o: strstuff.cpp strstuff.h
	g++ -c -g strstuff.cpp