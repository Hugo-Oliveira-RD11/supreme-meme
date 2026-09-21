import matplotlib.pyplot as plt
import matplotlib.ticker as ticker

x = [0, 74999, 149999, 224999, 299999]

y_sequencial = [0.000002, 0.000024, 0.000046, 0.000069, 0.000091]
y_binaria = [0.000001, 0.000001, 0.000001, 0.000001, 0.000001]

fig, ax = plt.subplots(figsize=(8, 5))

ax.plot(x, y_sequencial, label='Pesquisa Sequencial', color='red', marker='o', linestyle='-')
ax.plot(x, y_binaria, label='Pesquisa Binária', color='blue', marker='s', linestyle='--')

ax.set_title("Comparação: Pesquisa Sequencial x Binária (300mil elementos)")
ax.set_xlabel("Índice do elemento procurado")
ax.set_ylabel("Tempo decorrido (segundos)")
ax.xaxis.set_major_locator(ticker.MaxNLocator(integer=True))

ax.legend()

ax.grid(True, linestyle=':', alpha=0.6)

plt.savefig("grafico_comparativo_pesquisas_tempo.png", dpi=300, bbox_inches="tight")