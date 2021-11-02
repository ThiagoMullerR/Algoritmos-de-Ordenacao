#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "main.h"

float algoritmos[3];

void printTempo(int escolha){
    printf("\n\033[0;37mTempo de processamento da ordenação: %.4lfms\n\n", algoritmos[escolha - 1]);
}

void printTempos(){
    printf("\nTempo de processamento da ordenação Bubble Sort: %.4lfms\n", algoritmos[0]);
    printf("Tempo de processamento da ordenação Insertion Sort: %.4lfms\n", algoritmos[1]);
    printf("Tempo de processamento da ordenação Merge Sort: %.4lfms\n", algoritmos[2]);
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
        
        // executa o comando de gerar Aleatórios ou escolher números específicos
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
            executInsertionSort(v.vetor[0], v.tamanhoDoVetor);
            printVetor(v.vetor[0], v.tamanhoDoVetor);
            printTempo(escolha);
            break;
        case 3:
            executMergeSort(v.vetor[0], v.tamanhoDoVetor);
            printMerge(v.vetor[0], v.tamanhoDoVetor);
            printTempo(escolha);
            break;
        default:
            printf("\nErro! Opção Inválida!\n");
            exit(1);
            break;
        }

        int escolha2;
        printf("Você deseja comparar os valores?\n1) Sim\n2) Não\nEscolha: ");
        scanf("%d", &escolha2);
        
        if (escolha2 == 1) {
            switch (escolha) {
            case 1:
                // bubble sort
                executInsertionSort(v.vetor[1], v.tamanhoDoVetor);
                executMergeSort(v.vetor[2], v.tamanhoDoVetor);
                printTempos();
                break;
            case 2:
                // insertion sort
                executBubbleSort(v.vetor[1], v.tamanhoDoVetor);
                executMergeSort(v.vetor[2], v.tamanhoDoVetor);
                printTempos();
                break;
            case 3:
                // merge sort
                executBubbleSort(v.vetor[1], v.tamanhoDoVetor);
                executInsertionSort(v.vetor[2], v.tamanhoDoVetor);
                printTempos();
                break;
            default:
                printf("\nErro! Opção Inválida!\n");
                exit(1);
                break;
            }
        }

        printf("\nVocê deseja usar outro vetor?\n1) Sim\n2) Não\nEscolha: ");
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