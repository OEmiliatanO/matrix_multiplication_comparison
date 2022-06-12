import os
import matplotlib.pyplot as plt
import numpy as np
import re

directory = os.listdir()

dataGflops = [0] * 5
for i in range(5):
	dataGflops[i] = [0] * 5

for wdir in directory:
	if re.match("recordO[fast0-9]+", wdir) == None:
		continue

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
		dataGflops[oflag][n//192 - 1] = gflops

dataGflops = np.array(dataGflops)

for i in range(5):
	if i == 4:
		print('Ofast:')
	else:
		print('O' + str(i) + ':')
	for j in range(5):
		print('n = ' + str((j + 1) * 192) + ':')
		print('gflops=' + str(dataGflops[i][j]))
	print('')

width = 0.6
baseX = 0.5

for oflag in range(5):
	plt.figure(oflag)
	plt.title('vector matrix multiplication ver.2 -O' + ('fast' if oflag == 4 else str(oflag)))
	for n in range(5):
		plt.bar(baseX + width*n, dataGflops[oflag][n], width, edgecolor = 'black', label = 'n=' + str((n+1) * 192))
	#plt.bar(X, dataGflops[oflag], width, label = 'n='+str((n+1)*192))
	plt.ylabel('gflops')
	if oflag == 0:
		plt.yticks(np.arange(0, 1.25, 0.25))
	else:
		plt.yticks(np.arange(0, 13, 0.5))
	plt.xticks([0,3.5], ['',''])
	#plt.yticks(np.arange(0, 13, 0.5))
	plt.legend(loc = 'best')

plt.show()
