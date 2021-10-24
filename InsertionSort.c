/* 
                    Referência:
    https://pt.wikipedia.org/wiki/Insertion_sort#C
*/

void insertionSort(int vetor[], int tamanhoDoVetor){
    int i, j, valorDovetor;
    for (i = 1; i < tamanhoDoVetor; i++) {
        valorDovetor = vetor[i];
        j = i - 1;
        
        while (j >= 0 && vetor[j] > valorDovetor) { // Enquanto j >= 0 e o numero j do vetor > valorDovetor, faça:
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = valorDovetor;
    }
}