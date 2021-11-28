/*
                    Referência:
    https://pt.wikipedia.org/wiki/Bubble_sort#C
*/

void troca(int *a, int *b){ 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
}

void bubbleSort(int *array, int tamanhoDoarray){ 
    
    if (tamanhoDoarray < 1){
        return;
    }
 
    for (int i = 0; i < tamanhoDoarray; i++){
        if (array[i] > array[i + 1]){
            troca(&array[i], &array[i + 1]);
        }
    }
    bubbleSort(array, tamanhoDoarray - 1); 
} 