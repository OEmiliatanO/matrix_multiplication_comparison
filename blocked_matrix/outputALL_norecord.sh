#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

testcase=("192" "384" "576" "768" "960")

make depO2 B=64
make all clean
for ((j=0;j<5;j++))
do
	cat ../TestData/n${testcase[$j]} | ./blocked-matrix 1>blocked_matrix_out_n${testcase[$j]}
done
