import matplotlib.pyplot as plt
import numpy as np

tamanhos = [100000, 200000, 300000]

tempos_100k = [0.009948, 0.009576, 0.009445, 0.009464]
tempos_200k = [0.021060, 0.020022, 0.019758, 0.019722]
tempos_300k = [0.031581, 0.030315, 0.030426, 0.030482]

medias = [
    np.mean(tempos_100k),
    np.mean(tempos_200k),
    np.mean(tempos_300k)
]

for tam, med in zip(tamanhos, medias):
    print(f"Média para {tam} elementos: {med:.6f} segundos")

fig, ax = plt.subplots(figsize=(8, 5))


ax.plot(tamanhos, medias, marker='o', linestyle='-', color='b', linewidth=2, markersize=6, label='Merge Sort')


ax.set_title("Desempenho do Algoritmo por Tamanho de Vetor", fontsize=12, pad=12)
ax.set_xlabel("Tamanho do Vetor (número de elementos)", fontsize=10)
ax.set_ylabel("Tempo Médio Decorrido (segundos)", fontsize=10)

ax.set_xticks(tamanhos)
ax.set_xticklabels([f"{t//1000} mil" for t in tamanhos])

ax.grid(True, linestyle='--', alpha=0.6)
ax.legend()

plt.savefig("grafico_comparativo_medias.png", dpi=300, bbox_inches="tight")