CC:=g++

all: blocked-cache-matrix.o
	$(CC) -o blocked-cache-matrix blocked-cache-matrix.o
dep: blocked-cache-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O0 -c blocked-cache-matrix.cpp
depO1: blocked-cache-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O1 -c blocked-cache-matrix.cpp
depO2: blocked-cache-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O2 -c blocked-cache-matrix.cpp
depO3: blocked-cache-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O3 -c blocked-cache-matrix.cpp
clean:
	-rm *.o
