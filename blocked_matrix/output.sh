#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

make dep B=$1
make all
make clean

testcase=("192" "384" "576" "768" "960")

for ((i=0;i<10;i++))
do
	for ((j=0;j<5;j++))
	do
		cat ../TestData/n${testcase[$j]} | ./blocked-matrix 1>blocked_matrix_out_n${testcase[$j]} 2>>./B$1/blocked_matrix_B$1_record_n${testcase[$j]}
	done
done

