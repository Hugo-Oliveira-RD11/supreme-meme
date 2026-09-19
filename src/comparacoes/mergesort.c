#include "mergesort.h"
#include <stdlib.h>

// Função auxiliar para mesclar os arrays (privada)
static void merge(int *vetor, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = vetor[left + i];
    for (int j = 0; j < n2; j++) R[j] = vetor[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k++] = L[i++];
        } else {
            vetor[k++] = R[j++];
        }
    }

    while (i < n1) vetor[k++] = L[i++];
    while (j < n2) vetor[k++] = R[j++];

    free(L);
    free(R);
}

// Função recursiva que faz o trabalho pesado (privada)
static void merge_sort_recursivo(int *vetor, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort_recursivo(vetor, left, mid);
        merge_sort_recursivo(vetor, mid + 1, right);

        merge(vetor, left, mid, right);
    }
}

// Implementação da função pública declarada no .h
void merge_sort(int *vetor, int tamanho) {
    // Verificação de segurança: se o ponteiro for nulo ou o tamanho for inválido/já ordenado
    if (vetor == NULL || tamanho <= 1) {
        return;
    }

    // Chama a função recursiva passando os índices iniciais e finais
    merge_sort_recursivo(vetor, 0, tamanho - 1);
}
