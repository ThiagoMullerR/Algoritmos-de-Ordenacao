#include <stdio.h>
#include <time.h>
#include "main.h"

void printTempo(int escolha){
    printf("\n\033[0;37mTempo de processamento da ordenação: %.5lfms\n\n", algoritmos[escolha - 1]);
}

void printTempos(){
    printf("\nTempo de processamento da ordenação Bubble Sort: %.5lfms\n", algoritmos[0]);
    printf("Tempo de processamento da ordenação Insertion Sort: %.5lfms\n", algoritmos[1]);
    printf("Tempo de processamento da ordenação Merge Sort: %.5lfms\n", algoritmos[2]);
}
void contagemCronometro(int escolha, unsigned long inicio, unsigned long fim){
    algoritmos[escolha] = (double)(fim - inicio)/(CLOCKS_PER_SEC / 1000);
}