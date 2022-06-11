#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

testcase=("192" "384" "576" "768" "960")
flag=("O0" "O1" "O2" "O3" "Ofast")

for ((f=0;f<5;f++))
do
	make dep${flag[$f]} B=$1
	make all clean
	for ((i=0;i<10;i++))
	do
		for ((j=0;j<5;j++))
		do
			cat ../TestData/n${testcase[$j]} | ./blocked-cache-matrix 1>blocked_cache_matrix_out_n${testcase[$j]} 2>>./B$1${flag[$f]}/blocked_cache_matrix_B$1${flag[$f]}_record_n${testcase[$j]}
		done
	done
done
