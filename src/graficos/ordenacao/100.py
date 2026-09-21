import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4], [0.009948, 0.009576, 0.009445, 0.009464 ])

ax.set_title("Medição de tempo para a ordenação de um vetor de 100mil elementos")

ax.set_xlabel("Número da Execução")
ax.set_ylabel("Tempo decorrido em segundos")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_100mil.png", dpi=300, bbox_inches="tight")