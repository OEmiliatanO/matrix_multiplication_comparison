#!/bin/bash
PATH=/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin:~/bin
export PATH

testcase=("192" "384" "576" "768" "960")
flag=("O0" "O1" "O2" "O3" "Ofast")

for ((f=0;f<5;f++))
do
	make dep${flag[$f]} all clean
	for ((i=0;i<10;i++))
	do
		for ((j=0;j<5;j++))
		do
			cat ../TestData/n${testcase[$j]} | ./matrix 1>matrix_out_n${testcase[$j]} 2>>record${flag[$f]}/matrix_record${flag[$f]}_n${testcase[$j]}
		done
	done
done
