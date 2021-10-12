/*

                    Referência:
    https://pt.wikipedia.org/wiki/Merge_sort#C%C3%B3digo_em_C

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o vetor original
        vetor[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int vetor[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(vetor, comeco, meio);
        mergeSort(vetor, meio+1, fim);
        merge(vetor, comeco, meio, fim);
    }
}

void printVetor(int vetor[], int tamanhoDoVetor){
    for(int i = 0; i <= tamanhoDoVetor; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main(){
    clock_t cronometro;
    int tamanhoDoVetor, i, *vetor;

    printf("Algorítmo de ordenação\n--- MERGE SORT ---\n\n");
    printf("Insira a quantidade de números dentro do vetor:\n");
    scanf("%d", &tamanhoDoVetor);
    
    vetor = (int*) malloc(tamanhoDoVetor*sizeof(int));

    printf("\nInsira os valores dentro do vetor:\n");
    for(i = 0; i < tamanhoDoVetor; i++){
        scanf("%d", &vetor[i]);
    }

    printf("\n\033[1;31mArray antes da ordenação:\n");
    printVetor(vetor, tamanhoDoVetor);

    cronometro = clock(); // Inicia o cronometro
    mergeSort(vetor, 0, tamanhoDoVetor);
    cronometro = clock() - cronometro; // Finaliza o cronometro
    
    printf("\n\033[0;32mArray depois da ordenação:\n");
    printVetor(vetor, tamanhoDoVetor);
    
	printf("\n\033[0;37mTempo de processamento da ordenação: %lfms\n", ((double)cronometro)/((CLOCKS_PER_SEC/10000)));
    return 0;
}

