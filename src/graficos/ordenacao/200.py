import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

fig, ax = plt.subplots()
ax.plot([1, 2, 3, 4], [0.021060, 0.020022, 0.019758, 0.019722 ])

ax.set_title("Medição de tempo para a ordenação de um vetor de 200mil elementos")

ax.set_xlabel("Número da Execução")
ax.set_ylabel("Tempo decorrido em segundos")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_200mil.png", dpi=300, bbox_inches="tight")