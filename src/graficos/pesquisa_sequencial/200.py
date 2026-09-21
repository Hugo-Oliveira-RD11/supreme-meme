import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [103464, 7776, 102029, 78686, 198999]
y = [0.000033, 0.000003, 0.000068, 0.000051, 0.000125]

fig, ax = plt.subplots()
ax.scatter(x, y, color='blue', s=50)

ax.set_title("Pesquisa Sequencial em um vetor de 200 mil elementos")
ax.set_xlabel("Índice do elemento")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

plt.savefig("grafico_dispersao_200.png", dpi=300, bbox_inches="tight")