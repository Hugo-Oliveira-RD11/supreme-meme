import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [0, 25000, 50000, 75000, 99999]

y_sequencial = [1, 25001, 50001, 75001, 100000]
y_binaria = [18, 2, 1, 2, 19]

fig, ax = plt.subplots(figsize=(8, 5))

ax.plot(x, y_sequencial, label='Pesquisa Sequencial', color='red', marker='o', linestyle='-')
ax.plot(x, y_binaria, label='Pesquisa Binária', color='blue', marker='s', linestyle='--')

ax.set_title("Comparação: Pesquisa Sequencial x Binária (300mil elementos)")
ax.set_xlabel("Índice do elemento procurado")
ax.set_ylabel("Total de Comparações")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

ax.legend()

ax.grid(True, linestyle=':', alpha=0.6)

plt.savefig("grafico_comparativo_pesquisas300.png", dpi=300, bbox_inches="tight")