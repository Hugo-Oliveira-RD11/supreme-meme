// matricula 974
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define VETOR_A 100000
#define VETOR_B 200000
#define VETOR_C 300000
#define QTD_TESTES 4
#define SEED 974

#ifdef _WIN32
#include <direct.h>
#define CRIAR_DIRETORIO(dir) _mkdir(dir)
#else
#define CRIAR_DIRETORIO(dir) mkdir(dir, 0777)
#endif

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

int Gerar(int *vetor, int tamanho, int numero_teste) {
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

  clock_t inicio = clock();
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = rand();
  }
  clock_t termino = clock();

  double tempo_total = ((double)termino - inicio) / CLOCKS_PER_SEC;

  char caminho_vetor[150];
  snprintf(caminho_vetor, sizeof(caminho_vetor), "%s/%s", pasta, filename);

  printf("==== VETOR GERADO (%s) ====\n", pasta);
  printf("Confira os elementos gerados no arquivo '%s'\n", caminho_vetor);
  SalvarElementosVetor(vetor, tamanho, caminho_vetor);

 char caminho_relatorio[150];
  snprintf(caminho_relatorio, sizeof(caminho_relatorio),
           "%s/relatorio_teste%d.txt", pasta, numero_teste);

  FILE *relatorio = fopen(caminho_relatorio, "w");
  if (relatorio == NULL) {
    printf("Erro ao criar o arquivo de relatorio: %s\n", caminho_relatorio);
    exit(1);
  }

  fprintf(relatorio, "Relatorio %d para o vetor de tamanho %d\n", numero_teste,
          tamanho);
  fprintf(relatorio, "Tempo Inicio: %lf\n", (double)inicio / CLOCKS_PER_SEC);
  fprintf(relatorio, "Tempo Termino: %lf\n", (double)termino / CLOCKS_PER_SEC);
  fprintf(relatorio, "Tempo do Teste: %lf\n", tempo_total);

  fclose(relatorio);
  printf("Relatorio salvo em '%s'\n\n", caminho_relatorio);

  return 0;
}

int main() {
  int *v_a = (int *)malloc(VETOR_A * sizeof(int));
  int *v_b = (int *)malloc(VETOR_B * sizeof(int));
  int *v_c = (int *)malloc(VETOR_C * sizeof(int));
  for (int i = 0; i < QTD_TESTES; i++) {
    Gerar(v_a, VETOR_A, i + 1);
    Gerar(v_b, VETOR_B, i + 1);
    Gerar(v_c, VETOR_C, i + 1);
  }
  free(v_a);
  free(v_b);
  free(v_c);

  return 0;
}
