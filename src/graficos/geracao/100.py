import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4], [0.000850, 0.000677, 0.000692, 0.000675 ])

ax.set_title("Medição de tempo para a geração de um vetor de 100mil elementos")

ax.set_xlabel("Número da Execução")
ax.set_ylabel("Tempo decorrido em segundos")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_100mil.png", dpi=300, bbox_inches="tight")