import matplotlib.pyplot as plt
import csv

with open('../output/TraceData.csv', 'rt') as f:
	reader = csv.reader(f)
	traces = list(reader)
	time = list(range(2500))

for samples in traces:
	samples = [float(i) for i in samples]
	with plt.style.context('seaborn-poster'):
		plt.plot(time, samples, linewidth = 0.1,color="red", label = 'x')

plt.xlabel('Time  (μs)')
plt.ylabel('Data Sample')
plt.tick_params(top='off', bottom='off', left='off', right='off', labelleft='on', labelbottom='on')
fig = plt.gcf()
#plt.show()

fig.savefig('../output/tracedata.png') 

	

