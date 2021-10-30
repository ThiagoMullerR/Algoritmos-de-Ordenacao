#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "main.h"

void printTempo(double cronometro){
    printf("\n\033[0;37mTempo de processamento da ordenação: %.4lfms\n\n", ((double)cronometro)/(CLOCKS_PER_SEC/10000));
}

int main(){
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    // inicia um conjunto de variáveis essenciais para um vetor (ela é declarada no main.h)
    struct vetor v;
	
    clock_t cronometro; 

    // variável usada nas escolhas - tanto nos aleatórios ou específicos quanto em qual algoritmo irá ser usado.
    int escolha;
    
    printf("\n-- Algorítmos de ordenação --\n\n");
    
    //função scanf (fica em vetor.c)
    qualTamanhoDoVetor(&v.tamanhoDoVetor);
    
    // Alocação dinâmica de memória
    v.vetor = (int*) malloc(v.tamanhoDoVetor *sizeof(int));

    printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
    scanf("%d", &escolha);
    
    // executa o comando de gerar Aleatórios ou escolher números específicos
    if(escolha == 1){
        // (função em vetor.c)
        geraAleatorio(v.tamanhoDoVetor, v.vetor);
    } else if (escolha == 2){
        // (função em vetor.c)
        leDados(v.tamanhoDoVetor, v.vetor);
    } else{
        // Finaliza o programa se digitar algo que não for 1 ou 2
        printf("Erro! Valor inválido!\n");
        exit(1);
    }
    
    printf("\nQual algorítmo de ordenação você deseja usar?\n1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n\nDigite: ");
    scanf("%d", &escolha);

    if(escolha == 1){
        printf("\n\n-- BUBBLE SORT --\n");
    } else if(escolha == 2){
        printf("\n\n-- INSERTION SORT --\n");
    } else if(escolha == 3){
        printf("\n\n-- MERGE SORT --\n");
    } else {
        // Finaliza o programa se digitar algo que não for 1, 2 ou 3
        printf("\nErro! Opção Inválida!\n");
        exit(1);
    };

    printf("\n\033[1;31mVetor antes da ordenação:\n");
    // (função em vetor.c)
    printVetor(v.vetor, v.tamanhoDoVetor);

    cronometro = clock(); // Inicia o cronometro

    if(escolha == 1){
        // (função em BubbleSort.c)
        bubbleSort(v.vetor, v.tamanhoDoVetor - 1); // "-1" porque o ultimo elemento é um "\0" que indica o final do vetor.
    } else if(escolha == 2){
        // (função em InsertionSort.c)
        insertionSort(v.vetor, v.tamanhoDoVetor);
    } else if(escolha == 3){
        // (função em MergeSort.c)
        mergeSort(v.vetor, 0, v.tamanhoDoVetor);
    };
    
    cronometro = clock() - cronometro; // Finaliza o cronometro
    
    printf("\n\033[0;32mVetor depois da ordenação:\n");
    if(escolha == 3){
        // (função em vetor.c)
        printMerge(v.vetor, v.tamanhoDoVetor);
    } else{
        // (função em vetor.c)
        printVetor(v.vetor, v.tamanhoDoVetor);
    }
    
    // (função declarada acima do main() )
    printTempo(cronometro);
	
    return 0;
}