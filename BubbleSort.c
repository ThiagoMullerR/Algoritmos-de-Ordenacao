/*

                    Referência:
    https://pt.wikipedia.org/wiki/Bubble_sort#C

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void troca(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubbleSort(int *vetor, int tamanhoDoVetor){ 
    
    if (tamanhoDoVetor < 1){
        return;
    }
 
    for (int i = 0; i < tamanhoDoVetor; i++){
        if (vetor[i] > vetor[i + 1]){
            troca(&vetor[i], &vetor[i + 1]);
        }
    }
    bubbleSort(vetor, tamanhoDoVetor - 1); 
} 

void printVetor(int vetor[], int tamanhoDoVetor){
    for(int i = 0; i < tamanhoDoVetor; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}


int main(){
	clock_t cronometro;
    int tamanhoDoVetor, i, *vetor;
    
    printf("Algorítmo de ordenação\n--- BUBBLE SORT ---\n\n");
    printf("Insira a quantidade de números dentro do vetor:\n");
    scanf("%d", &tamanhoDoVetor);
    
    vetor = (int*) malloc(tamanhoDoVetor *sizeof(int));
    
    printf("\nInsira os valores dentro do vetor:\n");
    for(i = 0; i < tamanhoDoVetor; i++){
        scanf("%d", &vetor[i]);
    }
    
    printf("\n\033[1;31mArray antes da ordenação:\n");
    printVetor(vetor, tamanhoDoVetor);
    
	cronometro = clock(); // Inicia o cronometro
    bubbleSort(vetor, tamanhoDoVetor - 1); // "-1" porque o ultimo elemento é um "\0" que indica o final do vetor.
    cronometro = clock() - cronometro; // Finaliza o cronometro
    
    printf("\n\033[0;32mArray depois da ordenação:\n");
    printVetor(vetor, tamanhoDoVetor);
    
	printf("\n\033[0;37mTempo de processamento da ordenação: %lfms\n", ((double)cronometro)/((CLOCKS_PER_SEC/10000)));
    return 0;
}