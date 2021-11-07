#include <stdio.h>
#include <time.h>
#include "main.h"


// - O algoritmos[0] sempre guardará o tempo do Bubble Sort
// - O algoritmos[1] sempre guardará o tempo do Insertion Sort
// - O algoritmos[2] sempre guardará o tempo do Merge Sort
float algoritmos[3];

void printTempo(int escolha){
    printf("\n\033[0;37mTempo de processamento da ordenação: %.5lfms\n\n", algoritmos[escolha - 1]);
}

void printTempos(){
    printf("\nTempo de processamento da ordenação Bubble Sort: %.5lfms\n", algoritmos[0]);
    printf("Tempo de processamento da ordenação Insertion Sort: %.5lfms\n", algoritmos[1]);
    printf("Tempo de processamento da ordenação Merge Sort: %.5lfms\n", algoritmos[2]);
}

// Calcula o tempo gasto pela função de ordenação
// com base nos tempos de início e fim
void contagemCronometro(int escolha, unsigned long inicio, unsigned long fim){
    algoritmos[escolha] = (double)(fim - inicio)/(CLOCKS_PER_SEC / 1000);
}