#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

flag=("O0" "O1" "O2" "O3" "Ofast")

for ((f=0;f<5;f++))
do
	rm record${flag[$f]}/*record${flag[$f]}*
done
