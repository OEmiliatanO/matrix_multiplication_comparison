import os
import re
import numpy

directory = os.listdir()

for File in directory:
	if re.match("recordO[0-9]+", File) != None:
		print("in ./" + File, "process data")
		ddir = File
		datafile = os.listdir(ddir)
		for data in datafile:
			if not data[-3:].isnumeric():
				continue
			print('process', data)
			n = int(data[-3:])
			f = open(ddir + '/' + data, 'r')
			fs = open(ddir + '/' + data + '_sta', 'w')
			times = []
			while True:
				s = f.readline()
				if s == '' or not s[0].isnumeric():
					break
				times.append(int(s))
			fs.write('n=%d\n'%n)
			fs.write('avg: %.5f s\n'%(sum(times)/len(times)*1e-9))
			fs.write('max: %.5f s\n'%(max(times)*1e-9))
			fs.write('min: %.5f s\n'%(min(times)*1e-9))
			fs.write('std: %.5f s\n'%(numpy.std(times)*1e-9))
			fs.write('avg gflops: %.5f\n\n'%(n ** 3 / (sum(times)/len(times))))
			f.close()
			fs.close()
