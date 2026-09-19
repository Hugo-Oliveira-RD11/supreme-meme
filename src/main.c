// matricula 974
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VETOR_A 100000
#define VETOR_B 200000
#define VETOR_C 300000
#define SEED 974

int Gerar(int* v,int n){
  clock_t inicio = clock();
  srand(SEED);
  for(int i = 0; i < n; i++){
    v[i]=rand();
    printf("vetor[%d] = [%d] \n",i,v[i]);
  }
  clock_t termino = clock();
  printf("==TERMINO DO VETOR== \n");

  double tempo_total = ((double) termino-inicio)/CLOCKS_PER_SEC;
  printf("Inicio: %lf\nTermino: %lf\nTempo de execucao: %lf",(double)inicio/CLOCKS_PER_SEC, (double)termino/CLOCKS_PER_SEC, tempo_total);

}

int main(){
  /* int * V = (int *) malloc (N * sizeof(int)); */
  int v_a[VETOR_A];
  Gerar(v_a, VETOR_A);
  /* int v_b[VETOR_B]; */
  /* Gerar(v_b, VETOR_B); */
  /* int v_c[VETOR_C]; */
  /* Gerar(v_c, VETOR_C); */
  return 0;
}
