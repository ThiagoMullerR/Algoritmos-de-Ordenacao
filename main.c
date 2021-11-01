// o vetor ja chega ordenado na hora que ele vai comparar os tempos
// criei um array do tipo VETOR. precisa passar o array desorganizado como entrada para os 3 VETOR[i] e organizar um por um.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
//#include <windows.h>
#include "main.h"

float algoritmos[3];

void printTempo(int escolha){
    printf("\n\033[0;37mTempo de processamento da ordenação: %.4lfms\n\n", algoritmos[escolha - 1]);
}

void printTempos(){
    printf("\n");
    printf("Tempo de processamento da ordenação bubble: %.4lfms\n", algoritmos[0]);
    printf("Tempo de processamento da ordenação insertion: %.4lfms\n", algoritmos[1]);
    printf("Tempo de processamento da ordenação merge: %.4lfms\n", algoritmos[2]);
}
void contagemCronometro(int escolha, float tempo){
    algoritmos[escolha] = ((double)clock() - tempo)/(CLOCKS_PER_SEC/10000);
}

void executBubbleSort(int vetor[], int tamanhoDoVetor) {
    clock_t cronometro = clock();
    bubbleSort(vetor, tamanhoDoVetor - 1);
    contagemCronometro(0, cronometro);
}

void executInsertionSort(int vetor[], int tamanhoDoVetor) {
    clock_t cronometro = clock();
    insertionSort(vetor, tamanhoDoVetor);
    contagemCronometro(1, cronometro);
}

void executMergeSort(int vetor[], int tamanhoDoVetor) {
    clock_t cronometro = clock();
    mergeSort(vetor, 0, tamanhoDoVetor);
    contagemCronometro(2, cronometro);
}

int main() {
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    // inicia um conjunto de variáveis essenciais para um vetor (ela é declarada no main.h)
    VETOR vetor[3];
    //VETOR desordenado, ordenaddo;
    
    printf("\n-- Algorítmos de ordenação --\n\n");
    
    //função scanf (fica em vetor.c)
    qualTamanhoDoVetor(&vetor[1].tamanhoDoVetor);
    
    // Alocação dinâmica de memória
    for(int i = 0; i < sizeof(vetor)/sizeof(vetor[0]); i++){
        vetor[i].vetor = (int*) malloc(vetor[i].tamanhoDoVetor *sizeof(int));
    }
    

    // variável usada nas escolhas - tanto nos aleatórios ou específicos quanto em qual algoritmo irá ser usado.
    int escolha;
    printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
    scanf("%d", &escolha);

    
    // executa o comando de gerar Aleatórios ou escolher números específicos
    if(escolha == 1){
        // (função em vetor.c)
        geraAleatorio(vetor[1].tamanhoDoVetor, vetor[1].vetor);
    } else if (escolha == 2){
        // (função em vetor.c)
        leDados(vetor[1].tamanhoDoVetor, vetor[1].vetor);
    } else{
        // Finaliza o programa se digitar algo que não for 1 ou 2
        printf("Erro! Valor inválido!\n");
        exit(1);
    }
    
    printf("\nQual algorítmo de ordenação você deseja usar?\n1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n\nDigite: ");
    scanf("%d", &escolha);

    printf("\n\033[1;31mVetor antes da ordenação:\n");
    // (função em vetor.c)
    printVetor(vetor[1].vetor, vetor[1].tamanhoDoVetor);

    printf("\n\033[0;32mVetor depois da ordenação:\n");

    //int *valVetor;
    //valVetor = vetor[1].vetor;
    //int valTamanho = vetor[1].tamanhoDoVetor;
    switch (escolha) {
    case 1:
        printf("\n\n-- BUBBLE SORT --\n");
        executBubbleSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printVetor(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printTempo(escolha);
        break;
    case 2:
        printf("\n\n-- INSERTION SORT --\n");
        executInsertionSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printVetor(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printTempo(escolha);
        break;
    case 3:
        printf("\n\n-- MERGE SORT --\n");
        executMergeSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printMerge(vetor[1].vetor, vetor[1].tamanhoDoVetor);
        printTempo(escolha);
        break;
    default:
        printf("\nErro! Opção Inválida!\n");
        exit(1);
        break;
    }
    
    
    // (função declarada acima do main() )
    int escolha2;
    printf("Você deseja comparar os valores?\n1) Sim\n2) Não\nEscolha: ");
    scanf("%d", &escolha2);
    
    if (escolha2 == 1) {
        switch (escolha) {
        case 1:
            // bubble sort
            executInsertionSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            executMergeSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            printTempos();
            break;
        case 2:
            // insertion sort
            executBubbleSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            executMergeSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            printTempos();
            break;
        case 3:
            // merge sort
            executBubbleSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            executInsertionSort(vetor[1].vetor, vetor[1].tamanhoDoVetor);
            printTempos();
            break;
        default:
            printf("\nErro! Opção Inválida!\n");
            exit(1);
            break;
        }
    }
	
    return 0;
}