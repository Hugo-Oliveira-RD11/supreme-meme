#include "mergesort.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define VETOR_A 100000
#define VETOR_B 200000
#define VETOR_C 300000
#define QTD_TESTES 1
#define SEED 974

#ifdef _WIN32
#include <direct.h>
#define CRIAR_DIRETORIO(dir) _mkdir(dir)
#else
#define CRIAR_DIRETORIO(dir) mkdir(dir, 0777)
#endif

void ImprimirArray(FILE *file, int arr[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    fprintf(file, "%d\n", arr[i]);
  }
}

void SalvarElementosVetor(int *vetor, int tamanho, const char *filename) {
  FILE *teste_existencia = fopen(filename, "r");
  if (teste_existencia != NULL) {
    fclose(teste_existencia);
    return;
  }

  FILE *arquivo = fopen(filename, "w");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo dos elementos do vetor: %s\n", filename);
    exit(1);
  }
  for (int i = 0; i < tamanho; i++) {
    fprintf(arquivo, "vetor[%d] = [%d]\n", i, vetor[i]);
  }

  fclose(arquivo);
}

int Gerar(int *vetor, int tamanho) {
  char *filename;
  char *pasta;

  if (vetor == NULL) {
    printf("Erro ao alocar memoria!\n");
    exit(1);
  }

  switch (tamanho) {
  case VETOR_A:
    pasta = "testes100";
    filename = "100mil.txt";
    break;
  case VETOR_B:
    pasta = "testes200";
    filename = "200mil.txt";
    break;
  case VETOR_C:
    pasta = "testes300";
    filename = "300mil.txt";
    break;
  default:
    pasta = "errors";
    filename = "error.txt";
    break;
  }

  CRIAR_DIRETORIO(pasta);
  srand(SEED);

  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand();
  }

  char caminho_vetor[150];
  snprintf(caminho_vetor, sizeof(caminho_vetor), "%s/%s", pasta, filename);

  printf("==== VETOR GERADO (%s) ====\n", pasta);
  printf("Confira os elementos gerados no arquivo '%s'\n", caminho_vetor);
  SalvarElementosVetor(vetor, tamanho, caminho_vetor);
  return 0;
}

int PesquisaSequencial(int *V, int N, int Chave, int *count) {
  for (int i = 0; i < N; i++) {
    (*count)++;
    if (Chave >= 0 && Chave < N && V[i] == V[Chave])
      return i;
    else if (Chave < 0) {
      // Caso especial para chave invalida/nao existente (-1)
      return -1;
    }
  }
  return -1; // O elemento não está no conjunto
}

int PesquisaBinaria(int *V, int N, int Chave, int *count) {
  if (Chave < 0 || Chave >= N)
    return -1;

  int Esquerda = 0;
  int Direita = N - 1;
  while (Esquerda <= Direita) {
    int Meio = (Esquerda + Direita) / 2;

    (*count)++;
    if (V[Meio] == V[Chave])
      return Meio;
    else if (V[Meio] < V[Chave])
      Esquerda = Meio + 1;
    else
      Direita = Meio - 1;
  }
  return -1; // O elemento não está no conjunto
}

int CriarRelatorio(char *pasta, int *vetor, int tamanho, int numero_teste, int target[],
                   int seq_encontrados[], int seq_comparacoes[], double seq_tempos[],
                   int bin_encontrados[], int bin_comparacoes[], double bin_tempos[]) {
  char caminho_relatorio[150];
  snprintf(caminho_relatorio, sizeof(caminho_relatorio),
           "%s/relatorio_teste%d.txt", pasta, numero_teste);

  FILE *relatorio = fopen(caminho_relatorio, "w");
  if (relatorio == NULL) {
    printf("Erro ao criar o arquivo de relatorio: %s\n", caminho_relatorio);
    exit(1);
  }

  fprintf(relatorio, "Relatorio %d para o vetor de tamanho %d (Analise de Comparacoes)\n\n", numero_teste, tamanho);

  fprintf(relatorio, "========== PESQUISAS SEQUENCIAIS ==========\n");
  for (int i = 0; i < 6; i++) {
    fprintf(relatorio, "--- Alvo (Indice): %d ---\n", target[i]);
    if (seq_encontrados[i] != -1)
      fprintf(relatorio, "Elemento encontrado no indice = %d\n", seq_encontrados[i]);
    else
      fprintf(relatorio, "Elemento nao encontrado\n");
    fprintf(relatorio, "Numero de comparacoes: %d\n", seq_comparacoes[i]);
    fprintf(relatorio, "Tempo de execucao: %lf segundos\n\n", seq_tempos[i]);
  }

  fprintf(relatorio, "========== PESQUISAS BINARIAS ==========\n");
  for (int i = 0; i < 6; i++) {
    fprintf(relatorio, "--- Alvo (Indice): %d ---\n", target[i]);
    if (bin_encontrados[i] != -1)
      fprintf(relatorio, "Elemento encontrado no indice = %d\n", bin_encontrados[i]);
    else
      fprintf(relatorio, "Elemento nao encontrado\n");
    fprintf(relatorio, "Numero de comparacoes: %d\n", bin_comparacoes[i]);
    fprintf(relatorio, "Tempo de execucao: %lf segundos\n\n", bin_tempos[i]);
  }

  fprintf(relatorio, "===== Array Ordenado ====\n");
  ImprimirArray(relatorio, vetor, tamanho);

  fclose(relatorio);
  printf("Relatorio salvo em '%s'\n\n", caminho_relatorio);

  return 0;
}

int ExecutarTestesPesquisa(int *vetor, int tamanho, int numero_teste) {
  char *pasta;
  int targetA[6] = {0, 25000, 50000, 75000, 99999, -1};
  int targetB[6] = {0, 50000, 100000, 150000, 199999, -1};
  int targetC[6] = {0, 74999, 149999, 224999, 299999, -1};
  int *target;

  switch (tamanho) {
  case VETOR_A:
    pasta = "testes100";
    target = targetA;
    break;
  case VETOR_B:
    pasta = "testes200";
    target = targetB;
    break;
  case VETOR_C:
    pasta = "testes300";
    target = targetC;
    break;
  default:
    pasta = "errors";
    target = targetA;
    break;
  }

  // Ordena o vetor primeiro
  merge_sort(vetor, tamanho);

  int seq_encontrados[6], seq_comparacoes[6];
  double seq_tempos[6];

  int bin_encontrados[6], bin_comparacoes[6];
  double bin_tempos[6];

  printf("=========== PESQUISAS SEQUENCIAIS (%s) ===========\n", pasta);
  for (int i = 0; i < 6; i++) {
    int comparacoes = 0;
    clock_t inicio = clock();
    seq_encontrados[i] = PesquisaSequencial(vetor, tamanho, target[i], &comparacoes);
    clock_t termino = clock();

    seq_comparacoes[i] = comparacoes;
    seq_tempos[i] = ((double)(termino - inicio)) / CLOCKS_PER_SEC;

    printf("==TERMINO DA PESQUISA SEQUENCIAL== \n");
    printf("Numero de comparacoes (sequencial) = %d\n", seq_comparacoes[i]);
    if (seq_encontrados[i] != -1)
      printf("Elemento encontrado\nIndice = %d\n", seq_encontrados[i]);
    else
      printf("Elemento nao encontrado\n");
    printf("Tempo de execucao: %lf\n\n", seq_tempos[i]);
  }

  printf("=========== PESQUISAS BINARIAS (%s) ===========\n", pasta);
  for (int i = 0; i < 6; i++) {
    int comparacoes = 0;
    clock_t inicio = clock();
    bin_encontrados[i] = PesquisaBinaria(vetor, tamanho, target[i], &comparacoes);
    clock_t termino = clock();

    bin_comparacoes[i] = comparacoes;
    bin_tempos[i] = ((double)(termino - inicio)) / CLOCKS_PER_SEC;

    printf("==TERMINO DA PESQUISA BINARIA== \n");
    printf("Numero de comparacoes (binario) = %d\n", bin_comparacoes[i]);
    if (bin_encontrados[i] != -1)
      printf("Elemento encontrado\nIndice = %d\n", bin_encontrados[i]);
    else
      printf("Elemento nao encontrado\n");
    printf("Tempo de execucao: %lf\n\n", bin_tempos[i]);
  }

  CriarRelatorio(pasta, vetor, tamanho, numero_teste, target,
                 seq_encontrados, seq_comparacoes, seq_tempos,
                 bin_encontrados, bin_comparacoes, bin_tempos);

  return 0;
}

int main() {
  int *v_a = (int *)malloc(VETOR_A * sizeof(int));
  int *v_a_copia = (int *)malloc(VETOR_A * sizeof(int));

  int *v_b = (int *)malloc(VETOR_B * sizeof(int));
  int *v_b_copia = (int *)malloc(VETOR_B * sizeof(int));

  int *v_c = (int *)malloc(VETOR_C * sizeof(int));
  int *v_c_copia = (int *)malloc(VETOR_C * sizeof(int));

  Gerar(v_a, VETOR_A);
  Gerar(v_b, VETOR_B);
  Gerar(v_c, VETOR_C);

  memcpy(v_a_copia, v_a, VETOR_A * sizeof(int));
  memcpy(v_b_copia, v_b, VETOR_B * sizeof(int));
  memcpy(v_c_copia, v_c, VETOR_C * sizeof(int));

  for (int i = 0; i < QTD_TESTES; i++) {
    ExecutarTestesPesquisa(v_a, VETOR_A, i + 1);
    ExecutarTestesPesquisa(v_b, VETOR_B, i + 1);
    ExecutarTestesPesquisa(v_c, VETOR_C, i + 1);

    memcpy(v_a, v_a_copia, VETOR_A * sizeof(int));
    memcpy(v_b, v_b_copia, VETOR_B * sizeof(int));
    memcpy(v_c, v_c_copia, VETOR_C * sizeof(int));
  }

  free(v_a);
  free(v_b);
  free(v_c);
  free(v_a_copia);
  free(v_b_copia);
  free(v_c_copia);

  return 0;
}




