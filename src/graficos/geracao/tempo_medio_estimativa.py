import matplotlib.pyplot as plt
import numpy as np

tamanhos_conhecidos = [100000, 200000, 300000]
tempos_conhecidos = [
    0.0007235, 
    0.0014835, 
    0.00219675 
]

coeficientes = np.polyfit(tamanhos_conhecidos, tempos_conhecidos, 1)
polinomio = np.poly1d(coeficientes)

tamanho_estimado = 500000
tempo_estimado = polinomio(tamanho_estimado)


tamanhos_totais = ["100000", "200000", "300000", "500000 (Estimado)"]
tempos_totais = [
    tempos_conhecidos[0], 
    tempos_conhecidos[1], 
    tempos_conhecidos[2], 
    tempo_estimado
]

cores = ["#1f77b4", "#1f77b4", "#1f77b4", "#ff7f0e"]

fig, ax = plt.subplots(figsize=(8, 5))

barras = ax.bar(
    tamanhos_totais, tempos_totais, color=cores, width=0.6, edgecolor="black"
)

ax.set_xlabel("Tamanho do Vetor", fontsize=12)
ax.set_ylabel("Tempo Médio (segundos)", fontsize=12)
ax.set_title("Tempo Médio por Tamanho de Vetor", fontsize=14)


for barra in barras:
    altura = barra.get_height()
    ax.annotate(
        f"{altura:.6f}",
        xy=(barra.get_x() + barra.get_width() / 2, altura),
        xytext=(0, 3),
        textcoords="offset points",
        ha="center",
        va="bottom",
        fontsize=9,
    )

plt.savefig("grafico_estimativa.png", dpi=300, bbox_inches="tight")