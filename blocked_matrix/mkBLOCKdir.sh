#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

block=("128" "8" "4" "16" "256" "32" "64" "70" "80" "90")
flag=("O0" "O1" "O2" "O3" "Ofast")

for((b=0;b<10;b++))
do
	for((f=0;f<5;f++))
	do
		mkdir B${block[$b]}${flag[$f]}
	done
done
