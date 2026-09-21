import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [786, 4793, 8761, 52062, 5554]
y = [0.000002, 0.000001, 0.000001, 0.000001, 0.000001 ]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Binária em um vetor de 100 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_dispersao_100.png", dpi=300, bbox_inches="tight")