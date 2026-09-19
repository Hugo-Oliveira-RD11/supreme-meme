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

int main(){
  /* int * v_a = (int *) malloc (VETOR_A * sizeof(int)); */
  /* Gerar(v_a, VETOR_A); */
  /* int tamanho = VETOR_A; */

  /* clock_t inicio = clock(); */
  /* merge_sort(v_a,tamanho); */
  /* clock_t termino = clock(); */

  /* imprimir_array(v_a, VETOR_A); */

  /* printf("==TERMINO DA ORDENACAO== \n"); */
  /* double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC; */
  /* printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* free(v_a); */

  // ========================================= //

  /* int * v_b = (int *) malloc (VETOR_B * sizeof(int)); */
  /* Gerar(v_b, VETOR_B); */
  /* int tamanho = VETOR_B; */

  /* clock_t inicio = clock(); */
  /* merge_sort(v_b,tamanho); */
  /* clock_t termino = clock(); */

  /* imprimir_array(v_b, VETOR_B); */

  /* printf("==TERMINO DA ORDENACAO== \n"); */
  /* double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC; */
  /* printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total); */

  /* free(v_b); */

  // =========================================== //

  int * v_c = (int *) malloc (VETOR_C * sizeof(int));
  Gerar(v_c, VETOR_C);
  int tamanho = VETOR_C;

  clock_t inicio = clock();
  merge_sort(v_c,tamanho);
  clock_t termino = clock();

  imprimir_array(v_c, VETOR_C);

  printf("==TERMINO DA ORDENACAO== \n");
  double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC;
  printf("Inicio: %.3lf\nTermino: %.3lf\nTempo de execucao: %.3lf",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total);

  free(v_c);

}
