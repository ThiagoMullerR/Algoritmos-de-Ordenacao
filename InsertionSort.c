/* 
                    Referência:
    https://pt.wikipedia.org/wiki/Insertion_sort#C
*/

void insertionSort(int array[], int tamanhoDoarray){
    int i, j, valorDoarray;
    for (i = 1; i < tamanhoDoarray; i++) {
        valorDoarray = array[i];
        j = i - 1;
        
        while (j >= 0 && array[j] > valorDoarray) { // Enquanto j >= 0 e o numero j do array > valorDoarray, faça:
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = valorDoarray;
    }
}