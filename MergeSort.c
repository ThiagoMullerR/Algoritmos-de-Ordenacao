/*
                    Referência:
    https://pt.wikipedia.org/wiki/Merge_sort#C%C3%B3digo_em_C
*/
#include <stdio.h>
#include <stdlib.h>

void merge(int array[], int comeco, int meio, int fim) {
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim){
        if(array[com1] < array[com2]) {
            vetAux[comAux] = array[com1];
            com1++;
        } else {
            vetAux[comAux] = array[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio){  //Caso ainda haja elementos na primeira metade
        vetAux[comAux] = array[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {   //Caso ainda haja elementos na segunda metade
        vetAux[comAux] = array[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){    //Move os elementos de volta para o array original
        array[comAux] = vetAux[comAux-comeco];
    }
    
    free(vetAux);
}

void mergeSort(int array[], int comeco, int fim){
    if (comeco < fim) {
        int meio = (fim+comeco)/2;

        mergeSort(array, comeco, meio);
        mergeSort(array, meio+1, fim);
        merge(array, comeco, meio, fim);
    }
}