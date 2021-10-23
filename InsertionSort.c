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

// int main(){
//     clock_t cronometro;
//     int tamanhoDoVetor;
    
//     printf("Algorítmo de ordenação\n--- INSERTION SORT ---\n\n");
//     printf("Insira a quantidade de números dentro do vetor:\n");
//     scanf("%d", &tamanhoDoVetor);
    
//     int vetor[tamanhoDoVetor];
//     //vetor = (int*) malloc(tamanhoDoVetor *sizeof(int));
    
//     printf("\nInsira os valores dentro do vetor:\n");
//     for(int i = 0; i < tamanhoDoVetor; i++){
//         scanf("%d", &vetor[i]);
//     }
    
//     printf("\n\033[1;31mvetor antes da ordenação:\n");
//     printVetor(vetor, tamanhoDoVetor);
    
//     cronometro = clock(); // Inicia o cronometro
//     insertionSort(vetor, tamanhoDoVetor);
//     cronometro = clock() - cronometro; // Finaliza o cronometro
    
//     printf("\n\033[0;32mvetor depois da ordenação:\n");
//     printVetor(vetor, tamanhoDoVetor);
    
//     printf("\n\n\033[0;37mTempo de processamento da ordenação: %lfms\n", ((double)cronometro)/((CLOCKS_PER_SEC/10000)));
//     return 0;
// }