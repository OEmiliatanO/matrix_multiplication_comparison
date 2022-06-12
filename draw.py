import os
import matplotlib.pyplot as plt
import numpy as np
import re

directory = os.listdir()

BLOCK = [4,8,16,32,64,70,80,90,128,256]

dataGflops = [] * 5
for i in range(5):
	dataGflops[i] = [] * 10
	for j in range(10):
		dataGflops[i][j] = [] * 5

for wdir in directory:
	if re.match("B[0-9]+O[fast0-9]+", wdir) == None:
		continue

	block = int(wdir[1:wdir.index('O')])
	oflag = wdir[wdir.index('O') + 1:]
	if oflag[0] == 'f':
		oflag = 4
	else:
		oflag = int(oflag)

	datafiles = os.listdir(wdir)
	for data in datafiles:
		if data[-3:] != 'sta':
			continue
		f = open(wdir + '/' + data)
		s = f.readline()
		n = int(s[s.index('=') + 1:])
		while (s:=f.readline()).find('avg gflops') == -1: pass
		gflops = float(s[s.index(':') + 1:])
		dataGflops[oflag][BLOCK.index(block)][n//192 - 1] = gflops

