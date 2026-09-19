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

int PesquisaSequencial(int *V, int N, int Chave) {
  for (int i = 0; i < N; i++) {
    if (V[i] == Chave) return i;
  }
  return -1; // O elemento não está no conjunto
}

int PesquisaBinaria(int * V, int N, int Chave) {
  int Esquerda = 0;
  int Direita = N - 1;
  while (Esquerda <= Direita) {
    int Meio = (Esquerda + Direita) / 2;
    if (V[Meio] == Chave) return Meio;
    else if (V[Meio] < Chave) Esquerda = Meio + 1;
    else Direita = Meio - 1;
  }
  return -1; // O elemento não está no conjunto
}

int main(){
  /* int * v_a = (int *) malloc (VETOR_A * sizeof(int)); */
  /* Gerar(v_a, VETOR_A); */
  /* int tamanho = VETOR_A; */
  /* int target[6] = {16660986,104177966,187920493,1123118252,120736693,73}; */
  /* int encontrou=0; */

  /* merge_sort(v_a,tamanho); */

  /* imprimir_array(v_a, VETOR_A); */

  /* for(int i =0; i<6;i++){ */
  /*   clock_t inicio = clock(); */
  /*   encontrou = PesquisaBinaria(v_a, VETOR_A, target[i]); */
  /*   clock_t termino = clock(); */


  /*   printf("==TERMINO DA PESQUISA== \n"); */
  /*   if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou); */
  /*   else printf("elemento nao encontrado\n"); */
  /*   double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC; */
  /*   printf("Inicio: %lf\nTermino: %lf\nTempo de execucao: %lf\n\n\n",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* } */

  /* free(v_a); */

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
  /*   printf("Inicio: %lf\nTermino: %lf\nTempo de execucao: %lf\n\n\n",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* } */

  /* free(v_b); */


  // =========================================== //

  int * v_c = (int *) malloc (VETOR_C * sizeof(int));
  Gerar(v_c, VETOR_C);
  int tamanho = VETOR_C;
  int target[6] = {2136720149,1749524285,1380923657,545800645,714204102,73};
  int encontrou=0;

  merge_sort(v_c,tamanho);

  imprimir_array(v_c, VETOR_C);

  for(int i =0; i<6;i++){
    clock_t inicio = clock();
    encontrou = PesquisaBinaria(v_c, VETOR_C, target[i]);
    clock_t termino = clock();


    printf("==TERMINO DA PESQUISA== \n");
    if(encontrou != -1) printf("elemento encontrado\nindice = %d\n",encontrou);
    else printf("elemento nao encontrado\n");
    double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC;
    printf("Inicio: %lf\nTermino: %lf\nTempo de execucao: %lf\n\n\n",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total);

  }

  free(v_c);

}
