CC:=g++

all: blocked-matrix.o
	$(CC) -o blocked-matrix blocked-matrix.o
dep: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O0 -c blocked-matrix.cpp
depO1: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O1 -c blocked-matrix.cpp
depO2: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O2 -c blocked-matrix.cpp
depO3: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -O3 -c blocked-matrix.cpp
depOfast: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -Ofast -c blocked-matrix.cpp
clean:
	-rm *.o
