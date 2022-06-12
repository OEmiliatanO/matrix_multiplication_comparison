import os
import matplotlib.pyplot as plt
import numpy as np
import re

directory = os.listdir()

BLOCK = [4,8,16,32,64,70,80,90,128,256]

dataGflops = [0] * 5
for i in range(5):
	dataGflops[i] = [0] * 10
	for j in range(5):
		dataGflops[i][j] = [0] * 10

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
		f = open(wdir + '/' + data, 'r')
		s = f.readline()
		n = int(s[s.index('=') + 1:])
		while (s:=f.readline()).find('avg gflops') == -1: pass
		gflops = float(s[s.index(':') + 1:])
		dataGflops[oflag][n//192 - 1][BLOCK.index(block)] = gflops

dataGflops = np.array(dataGflops)

for i in range(5):
	if i == 4:
		print('Ofast:')
	else:
		print('O' + str(i) + ':')
	for j in range(5):
		print('n = ' + str((j + 1) * 192) + ':')
		for k in range(10):
			print('block=' + str(BLOCK[k]))
			print('gflops=' + str(dataGflops[i][j][k]))
		print('')
	print('')

X = np.arange(len(BLOCK))
width = 0.1

for oflag in range(5):
	plt.figure(oflag)
	plt.title('blocked matrix ver.2 -O' + ('fast' if oflag == 4 else str(oflag)))
	for n in range(5):
		plt.bar(X+width*(n-2), dataGflops[oflag][n], width, label = 'n='+str((n+1)*192))
	plt.ylabel('gflops')
	plt.xlabel('block size')
	plt.xticks(X, BLOCK)
	if oflag == 0:
		plt.yticks(np.arange(0, 1.25, 0.25))
	elif oflag <= 4:
		plt.yticks(np.arange(0, 5, 0.5))
	else:
		plt.yticks(np.arange(0, 12, 0.5))
	#plt.yticks(np.arange(0, 12, 0.5))
	plt.legend(loc = 'best')

plt.show()
