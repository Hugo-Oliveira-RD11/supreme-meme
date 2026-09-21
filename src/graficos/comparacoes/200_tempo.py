import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [0, 50000, 100000, 150000, 199999]

y_sequencial = [0.000001, 0.000022, 0.000038, 0.000054, 0.000070]
y_binaria = [0.000001, 0.000001, 0.000001, 0.000001, 0.000001]

fig, ax = plt.subplots(figsize=(8, 5))

ax.plot(x, y_sequencial, label='Pesquisa Sequencial', color='red', marker='o', linestyle='-')
ax.plot(x, y_binaria, label='Pesquisa Binária', color='blue', marker='s', linestyle='--')

ax.set_title("Comparação: Pesquisa Sequencial x Binária (200mil elementos)")
ax.set_xlabel("Índice do elemento procurado")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

ax.legend()

ax.grid(True, linestyle=':', alpha=0.6)

plt.savefig("grafico_comparativo_pesquisas_tempo.png", dpi=300, bbox_inches="tight")