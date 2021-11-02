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

    //int tamanhoDoVetor;
    // inicia um conjunto de variáveis essenciais para um vetor (ela é declarada no main.h)
    VETOR v;
    //VETOR desordenado, ordenaddo;
    
    

    printf("\n-- Algorítmos de ordenação --\n\n");
    
    //função scanf (fica em vetor.c)
    qualTamanhoDoVetor(&v.tamanhoDoVetor);
    
    // Alocação dinâmica de memória
    v.vetor0 = (int*) malloc(v.tamanhoDoVetor *sizeof(int));
    v.vetor1 = (int*) malloc(v.tamanhoDoVetor *sizeof(int));
    v.vetor2 = (int*) malloc(v.tamanhoDoVetor *sizeof(int));
    

    // variável usada nas escolhas - tanto nos aleatórios ou específicos quanto em qual algoritmo irá ser usado.
    int escolha;
    printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
    scanf("%d", &escolha);

    
    // executa o comando de gerar Aleatórios ou escolher números específicos
    if(escolha == 1){
        // (função em vetor.c)
        geraAleatorio(v.tamanhoDoVetor, v.vetor0);
    } else if (escolha == 2){
        // (função em vetor.c)
        leDados(v.tamanhoDoVetor, v.vetor0);
    } else{
        // Finaliza o programa se digitar algo que não for 1 ou 2
        printf("Erro! Valor inválido!\n");
        exit(1);
    }


    //v.vetor2 = v.vetor1 = v.vetor0;

    for(int i = 0; i <=  v.tamanhoDoVetor; i++){
        v.vetor1[i] = v.vetor0[i];
    }
    for(int i = 0; i <=  v.tamanhoDoVetor; i++){
        v.vetor2[i] = v.vetor1[i];
    }


    printf("\nQual algorítmo de ordenação você deseja usar?\n1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n\nDigite: ");
    scanf("%d", &escolha);

    printf("\n\033[1;31mVetor antes da ordenação:\n");
    // (função em vetor.c)
    printVetor(v.vetor0, v.tamanhoDoVetor);

    printf("\n\033[0;32mVetor depois da ordenação:\n");

    switch (escolha) {
    case 1:
        printf("\n\n-- BUBBLE SORT --\n");
        executBubbleSort(v.vetor0, v.tamanhoDoVetor);
        printVetor(v.vetor0, v.tamanhoDoVetor);
        printTempo(escolha);
        break;
    case 2:
        printf("\n\n-- INSERTION SORT --\n");
        executInsertionSort(v.vetor0, v.tamanhoDoVetor);
        printVetor(v.vetor0, v.tamanhoDoVetor);
        printTempo(escolha);
        break;
    case 3:
        printf("\n\n-- MERGE SORT --\n");
        executMergeSort(v.vetor0, v.tamanhoDoVetor);
        printMerge(v.vetor0, v.tamanhoDoVetor);
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
            executInsertionSort(v.vetor1, v.tamanhoDoVetor);
            executMergeSort(v.vetor2, v.tamanhoDoVetor);
            printTempos();
            break;
        case 2:
            // insertion sort
            executBubbleSort(v.vetor1, v.tamanhoDoVetor);
            executMergeSort(v.vetor2, v.tamanhoDoVetor);
            printTempos();
            break;
        case 3:
            // merge sort
            executBubbleSort(v.vetor1, v.tamanhoDoVetor);
            executInsertionSort(v.vetor2, v.tamanhoDoVetor);
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