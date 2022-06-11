#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

testcase=("192" "384" "576" "768" "960")
flag=("O0" "O1" "O2" "O3" "Ofast")
BLOCK=("256" "128" "64" "32" "16" "8" "4" "70" "80" "90")

for ((f=0;f<5;f++))
do
	for ((b=0;b<10;b++))
	do
		make dep${flag[$f]} B=${BLOCK[$b]}
		make all clean
		for ((i=0;i<10;i++))
		do
			for ((j=0;j<5;j++))
			do
				cat ../TestData/n${testcase[$j]} | ./blocked-matrix 1>blocked_matrix_out_n${testcase[$j]} 2>>./B${BLOCK[$b]}${flag[$f]}/blocked_matrix_B${BLOCK[$b]}${flag[$f]}_record_n${testcase[$j]}
			done
		done
	done
done
