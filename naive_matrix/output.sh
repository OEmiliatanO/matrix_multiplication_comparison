#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

testcase=("192" "384" "576" "768" "960")

for ((i=0;i<10;i++))
do
	for ((j=0;j<5;j++))
	do
		cat ../TestData/n${testcase[$j]} | ./matrix 1>matrix_out_n${testcase[$j]} 2>>matrix_record_n${testcase[$j]}
	done
done
