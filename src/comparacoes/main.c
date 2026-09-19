#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mergesort.h"

#define VETOR_A 100000
#define VETOR_B 200000
#define VETOR_C 300000
#define SEED 974

void imprimir_array(int arr[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d \n", arr[i]);
  }
  printf("\n");
}

int Gerar(int* v,int n){
  srand(SEED);
  for(int i = 0; i < n; i++){
    v[i]=rand();
  }
}

int PesquisaSequencial(int *V, int N, int Chave, int *count) {
  for (int i = 0; i < N; i++) {
    (*count)++;
    if (V[i] == V[Chave]) return i;
  }
  return -1; // O elemento não está no conjunto
}

int PesquisaBinaria(int * V, int N, int Chave, int *count) {
  int Esquerda = 0;
  int Direita = N - 1;
  while (Esquerda <= Direita) {
    int Meio = (Esquerda + Direita) / 2;

    (*count)++;
    if (V[Meio] == V[Chave]) return Meio;

    else if (V[Meio] < V[Chave]) Esquerda = Meio + 1;
    else Direita = Meio - 1;
  }
  return -1; // O elemento não está no conjunto
}

int main(){
  int * v_a = (int *) malloc (VETOR_A * sizeof(int));
  Gerar(v_a, VETOR_A);
  int tamanho = VETOR_A;
  int target[6] = {0,24999,49999,74999,99999,-1};
  int encontrou=0;
  int comparacoes = 0;

  merge_sort(v_a,tamanho);

  imprimir_array(v_a, VETOR_A);

  for(int i =0; i<6;i++){
    clock_t inicio_sequencial = clock();
    encontrou = PesquisaSequencial(v_a, VETOR_A, target[i], &comparacoes);
    clock_t termino_sequencial = clock();

    printf("==TERMINO DA PESQUISA== \n");
    printf("numero de comparacoes (sequencial)= %d\n", comparacoes);
    if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou);
    else printf("elemento nao encontrado\n");

    double tempo_total_sequencial = ((double) termino_sequencial-inicio_sequencial)/CLOCKS_PER_SEC;

    printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf\n\n\n",(double)inicio_sequencial/CLOCKS_PER_SEC, (double)termino_sequencial/CLOCKS_PER_SEC, tempo_total_sequencial);

    comparacoes = 0;

  }
  printf("===========TERMINO DAS PESQUISAS SEQUENCIAIS==============\n\n\n");

  comparacoes = 0;

  for(int i =0; i<6;i++){

    clock_t inicio_binaria = clock();
    encontrou = PesquisaBinaria(v_a, VETOR_A, target[i], &comparacoes);
    clock_t termino_binaria = clock();

    printf("==TERMINO DA PESQUISA== \n");
    printf("numero de comparacoes (binario)= %d\n", comparacoes);
    if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou);
    else printf("elemento nao encontrado\n");

    double tempo_total_binario = ((double) termino_binaria-inicio_binaria)/CLOCKS_PER_SEC;

    printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf\n\n\n",(double)inicio_binaria/CLOCKS_PER_SEC, (double)termino_binaria/CLOCKS_PER_SEC, tempo_total_binario);

    comparacoes = 0;
  }

  free(v_a);

  // ========================================= //

  /* int * v_b = (int *) malloc (VETOR_B * sizeof(int)); */
  /* Gerar(v_b, VETOR_B); */
  /* int tamanho = VETOR_B; */
  /* int target[6] = {1111381307,84434356,1096188887,846248342,2136419159,73}; */
  /* int encontrou=0; */

  /* merge_sort(v_b,tamanho); */

  /* imprimir_array(v_b, VETOR_B); */

  /* for(int i =0; i<6;i++){ */
  /*   clock_t inicio = clock(); */
  /*   encontrou = PesquisaBinaria(v_b, VETOR_B, target[i]); */
  /*   clock_t termino = clock(); */


  /*   printf("==TERMINO DA PESQUISA== \n"); */
  /*   if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou); */
  /*   else printf("elemento nao encontrado\n"); */
  /*   double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC; */
  /*   printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf\n\n\n",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* } */

  /* free(v_b); */


  // =========================================== //

  /* int * v_c = (int *) malloc (VETOR_C * sizeof(int)); */
  /* Gerar(v_c, VETOR_C); */
  /* int tamanho = VETOR_C; */
  /* int target[6] = {2136720149,1749524285,1380923657,545800645,714204102,73}; */
  /* int encontrou=0; */

  /* merge_sort(v_c,tamanho); */

  /* imprimir_array(v_c, VETOR_C); */

  /* for(int i =0; i<6;i++){ */
  /*   clock_t inicio = clock(); */
  /*   encontrou = PesquisaBinaria(v_c, VETOR_C, target[i]); */
  /*   clock_t termino = clock(); */


  /*   printf("==TERMINO DA PESQUISA== \n"); */
  /*   if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou); */
  /*   else printf("elemento nao encontrado\n"); */
  /*   double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC; */
  /*   printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf\n\n\n",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* } */

  /* free(v_c); */

}
