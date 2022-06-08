CC:=g++

all: blocked-matrix.o
	$(CC) -o blocked-matrix blocked-matrix.o
dep: blocked-matrix.cpp
	$(CC) -Wall -DBLOCK=$(B) -c blocked-matrix.cpp
clean:
	-rm *.o
