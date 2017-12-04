import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

nameFile = "memoria.txt"

file = pd.read_table(nameFile, header = -1, sep = '\t')
file = (np.matrix(file))
x_label = np.squeeze(np.array(file[:12,0]))
y_label = []
for k in range(4):
	y_label.append([])
	for i in range(len(x_label)):
		y_label[-1].append(np.mean(np.squeeze(np.array(file[k*len(x_label)+i,1:]))))

plt.figure()
plt.yscale('log')
plt.title('Escalabilidade de memória dos métodos não informados')
plt.xlabel('Quantidade de peças [1]')
plt.ylabel('Itens em Listas [1]')
plt.plot(x_label, y_label[0], label="Backtracking")
plt.plot(x_label, y_label[1], label="Largura")
plt.plot(x_label, y_label[2], label="Profundidade")
plt.plot(x_label, y_label[3], label="Ordenada (função 2)")
plt.legend()
plt.show()
