#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

void printTempo(double cronometro){
    printf("\n\033[0;37mTempo de processamento da ordenação: %lfms\n\n", ((double)cronometro)/((CLOCKS_PER_SEC/10000)));
}

int main(){
    struct vetor v;
    
	clock_t cronometro;

    printf("\n-- Algorítmo de ordenação --\n\n");

    qualTamanhoDoVetor(&v.tamanhoDoVetor);
    v.vetor = (int*) malloc(v.tamanhoDoVetor *sizeof(int)); // Alocação dinâmica de memória
    leDados(v.tamanhoDoVetor, v.vetor);
    
    int escolha;
    printf("\nQual algorítmo de ordenação você quer usar?\n\n1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n\nDigite: ");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("\n\n-- BUBBLE SORT --\n\n");
    } else if(escolha == 2){
        printf("\n\n-- INSERTION SORT --\n\n");
    } else if(escolha == 3){
        printf("\n\n-- MERGE SORT --\n\n");
    } else {
        printf("Erro! Opção Inválida!\n");
        exit(1);
    };

    printf("\n\033[1;31mArray antes da ordenação:\n");
    printVetor(v.vetor, v.tamanhoDoVetor);

    cronometro = clock(); // Inicia o cronometro
    if(escolha == 1){
        bubbleSort(v.vetor, v.tamanhoDoVetor - 1); // "-1" porque o ultimo elemento é um "\0" que indica o final do vetor.
    } else if(escolha == 2){
        insertionSort(v.vetor, v.tamanhoDoVetor);
    } else if(escolha == 3){
        mergeSort(v.vetor, 0, v.tamanhoDoVetor);
    } else  printf("Opção inválida!\n");
    
    cronometro - cronometro; // Finaliza o cronometro
    
    printf("\n\033[0;32mArray depois da ordenação:\n");
    if(escolha == 3){
        // bug do "0" do Merge Sort
        for(int i = 1; i <= v.tamanhoDoVetor; i++){
            printf("%d ", v.vetor[i]);
        }
        printf("\n");
    } else{ printVetor(v.vetor, v.tamanhoDoVetor);}

    printTempo(cronometro);
	
    return 0;
}