import os
import numpy

files = os.listdir()
files.remove('dataProcess.py')

for File in files:
	if not File[-3:].isnumeric():
		continue
	print(File)
	n = int(File[-3:])
	f = open(File, 'r')
	fs = open(File + '_sta', 'w')
	times = []
	while True:
		s = f.readline()
		if s == '' or not s[0].isnumeric():
			break
		times.append(int(s))
	fs.write("n=%d\n"%n)
	fs.write('avg: %.5f s\n'%(sum(times)/len(times)*1e-9))
	fs.write('std: %.5f s\n'%(numpy.std(times)*1e-9))
	fs.write('avg gflops: %.5f\n\n'%(n ** 3 / (sum(times)/len(times))))
	f.close()
	fs.close()
