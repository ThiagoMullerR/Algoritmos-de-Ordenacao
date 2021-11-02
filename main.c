#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "main.h"

float algoritmos[3];

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

void executBubbleSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    bubbleSort(vetor, tamanhoDoVetor - 1);
    clock_t fimCronometro = clock();
    contagemCronometro(0, inicioCronometro, fimCronometro);
}

void executInsertionSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    insertionSort(vetor, tamanhoDoVetor);
    clock_t fimCronometro = clock();
    contagemCronometro(1, inicioCronometro, fimCronometro);
}

void executMergeSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    mergeSort(vetor, 0, tamanhoDoVetor);
    clock_t fimCronometro = clock();
    contagemCronometro(2, inicioCronometro, fimCronometro);
}

int main() {
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    int acabou = 0;

    printf("\n-- Algorítmos de ordenação --\n");

    do{
        VETOR v;

        qualTamanhoDoVetor(&v.tamanhoDoVetor);
        
        // Alocação dinâmica de memória
        for(int i = 0; i < sizeof(v.vetor)/sizeof(v.vetor[0]); i++){
            v.vetor[i] = (int*) malloc(v.tamanhoDoVetor *sizeof(int));
        }

        int escolha;
        printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
        scanf("%d", &escolha);
        
        switch (escolha){
        case 1:
            geraAleatorio(v.tamanhoDoVetor, v.vetor[0]);
            break;
        case 2:
            leDados(v.tamanhoDoVetor, v.vetor[0]);
            break;
        default:
            printf("Erro! Valor inválido!\n");
            exit(1);
        }

        for(int i = 0; i <=  v.tamanhoDoVetor; i++){
            v.vetor[2][i] = v.vetor[1][i] = v.vetor[0][i];
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
            printf("\nErro! Opção Inválida!\n");
            exit(1);
        };

        printf("\n\033[1;31mVetor antes da ordenação:\n");
        printVetor(v.vetor[0], v.tamanhoDoVetor);

        printf("\n\033[0;32mVetor depois da ordenação:\n");

        switch (escolha) {
        case 1:
            executBubbleSort(v.vetor[0], v.tamanhoDoVetor);
            printVetor(v.vetor[0], v.tamanhoDoVetor);
            printTempo(escolha);
            break;
        case 2:
            executInsertionSort(v.vetor[1], v.tamanhoDoVetor);
            printVetor(v.vetor[1], v.tamanhoDoVetor);
            printTempo(escolha);
            break;
        case 3:
            executMergeSort(v.vetor[2], v.tamanhoDoVetor);
            printMerge(v.vetor[2], v.tamanhoDoVetor);
            printTempo(escolha);
            break;
        default:
            break;
        }

        int escolhaCompararVal;
        printf("Você deseja comparar os valores?\n1) Sim\n2) Não\n\nEscolha: ");
        scanf("%d", &escolhaCompararVal);
        
        if (escolhaCompararVal == 1) {
            switch (escolha) {
            case 1:
                // bubble sort
                executInsertionSort(v.vetor[1], v.tamanhoDoVetor);
                executMergeSort(v.vetor[2], v.tamanhoDoVetor);
                printTempos();
                break;
            case 2:
                // insertion sort
                executBubbleSort(v.vetor[0], v.tamanhoDoVetor);
                executMergeSort(v.vetor[2], v.tamanhoDoVetor);
                printTempos();
                break;
            case 3:
                // merge sort
                executBubbleSort(v.vetor[0], v.tamanhoDoVetor);
                executInsertionSort(v.vetor[1], v.tamanhoDoVetor);
                printTempos();
                break;
            default:
                printf("\nErro! Opção Inválida!\n");
                exit(1);
                break;
            }
        }

        printf("\nVocê deseja usar outro vetor?\n1) Sim\n2) Não\n\nEscolha: ");
        scanf(" %d", &acabou);
        acabou--;
    } while (!acabou);

    if(acabou == 1){
        printf("\nTudo bem, até mais! :3\n\n");
    } else {
        printf("\nValor invalido!\n\n");
    }
    
    return 0;
}