import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

nameFile = "ordenadas.txt"

file = pd.read_table(nameFile, header = -1, sep = '\t')
file = (np.matrix(file))
x_label = np.squeeze(np.array(file[:12,0]))
y_label = []
for k in range(3):
	y_label.append([])
	for i in range(len(x_label)):
		y_label[-1].append(np.mean(np.squeeze(np.array(file[k*len(x_label)+i,1:]))))

plt.figure()
plt.yscale('log')
plt.title('Escalabilidade entre as funções na busca ordenada')
plt.xlabel('Quantidade de peças [1]')
plt.ylabel('Tempo [ms]')
plt.plot(x_label, y_label[0], label="função 1")
plt.plot(x_label, y_label[1], label="função 2")
plt.plot(x_label, y_label[2], label="função 3")
plt.legend()
plt.show()
