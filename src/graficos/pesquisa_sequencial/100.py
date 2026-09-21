import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [786, 4793, 8761, 52062, 5554]
y = [0.000002, 0.000004, 0.000006, 0.000036, 0.000005]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Sequencial em um vetor de 100 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_dispersao_100.png", dpi=300, bbox_inches="tight")