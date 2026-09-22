import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [103464, 7776, 102029, 78686, 198999]
y = [0.000001, 0.000001, 0.000001, 0.000001, 0.000001]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Binária em um vetor de 200 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_dispersao_200.png", dpi=300, bbox_inches="tight")