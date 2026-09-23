import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [298540, 244287, 192764, 76508, 99998]
y = [0.000002, 0.000001, 0.000001, 0.000001, 0.000001]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Binária em um vetor de 300 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")

ax.ticklabel_format(style='sci', axis='x', scilimits=(0, 0))

ax.xaxis.set_major_formatter(ticker.ScalarFormatter(useMathText=True))

plt.savefig("grafico_dispersao_300.png", dpi=300, bbox_inches="tight")