CC:=g++
FLAG:=-msse -msse2 -msse3 -mssse3 -msse4 -msse4a -msse4.1 -msse4.2

all: vector-matrix.o
	$(CC) -o vector-matrix vector-matrix.o
depO0: vector-matrix.cpp
	$(CC) -Wall -O0 -c vector-matrix.cpp
depO1: vector-matrix.cpp
	$(CC) -Wall -O1 -c vector-matrix.cpp
depO2: vector-matrix.cpp
	$(CC) -Wall -O2 -c vector-matrix.cpp
depO3: vector-matrix.cpp
	$(CC) -Wall -O3 -c vector-matrix.cpp
depOfast: vector-matrix.cpp
	$(CC) -Wall -Ofast -c vector-matrix.cpp
clean:
	-rm *.o
