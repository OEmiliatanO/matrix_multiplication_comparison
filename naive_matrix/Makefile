CC:=g++

all: matrix.o
	$(CC) -o matrix matrix.o
debug: matrix.cpp
	$(CC) -Wall -O3 -DOUTPUT -c matrix.cpp
dep: matrix.cpp
	$(CC) -Wall -O0 -c matrix.cpp
depO1: matrix.cpp
	$(CC) -Wall -O1 -c matrix.cpp
depO2: matrix.cpp
	$(CC) -Wall -O2 -c matrix.cpp
depO3: matrix.cpp
	$(CC) -Wall -O3 -c matrix.cpp
clean:
	-rm *.o
