#include <stdio.h>

void qualTamanhoDoVetor(int *tamanhoDoVetor){
    printf("Insira a quantidade de números dentro do vetor:\n");
    scanf("%d", tamanhoDoVetor);
}

void leDados(int tamanhoDoVetor, int vetor[]){
    printf("\nInsira os valores dentro do vetor:\n");
    for(int i = 0; i < tamanhoDoVetor; i++){
        scanf("%d", &vetor[i]);
    }
}

void printVetor(int vetor[], int tamanhoDoVetor){
    for(int i = 0; i < tamanhoDoVetor; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}