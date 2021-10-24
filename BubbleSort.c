/*
                    Referência:
    https://pt.wikipedia.org/wiki/Bubble_sort#C
*/

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