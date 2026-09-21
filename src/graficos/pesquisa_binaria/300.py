import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [298540, 244287, 192764, 76508, 99998]
y = [0.000002, 0.000001, 0.000001, 0.000001, 0.000001]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Sequencial em um vetor de 300 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_dispersao_300.png", dpi=300, bbox_inches="tight")