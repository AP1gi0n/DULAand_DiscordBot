CFLAGS=-g -Wfatal-errors

Lab1: main.cpp ArrayList.h LinkedList.h build/ArrayList.o build/LinkedList.o
	g++ main.cpp ${CFLAGS} build/ArrayList.o build/LinkedList.o -o Lab1

build/ArrayList.o: ArrayList.h ArrayList.cpp
	mkdir -p build
	g++ ${CFLAGS} -c -o build/ArrayList.o ArrayList.cpp

build/LinkedList.o: LinkedList.h LinkedList.cpp
	mkdir -p build
	g++ ${CFLAGS} -c -o build/LinkedList.o LinkedList.cpp

.PHONY: clean

clean:
	rm -rf build
	rm -f Lab1
