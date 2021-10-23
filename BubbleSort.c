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



// int main(){
//     struct vetor v;
    
// 	clock_t cronometro;

//     printf("Algorítmo de ordenação\n--- BUBBLE SORT ---\n\n");

//     qualTamanhoDoVetor(&v.tamanhoDoVetor);
//     v.vetor = (int*) malloc(v.tamanhoDoVetor *sizeof(int)); // Alocação dinâmica de memória
//     leDados(v.tamanhoDoVetor, v.vetor);
    
//     printf("\n\033[1;31mArray antes da ordenação:\n");
//     printVetor(v.vetor, v.tamanhoDoVetor);
    
    
// 	cronometro = clock(); // Inicia o cronometro
//     bubbleSort(v.vetor, v.tamanhoDoVetor - 1); // "-1" porque o ultimo elemento é um "\0" que indica o final do vetor.
//     cronometro - cronometro; // Finaliza o cronometro
    
//     printf("\n\033[0;32mArray depois da ordenação:\n");
//     printVetor(v.vetor, v.tamanhoDoVetor);

//     printTempo(cronometro);
	
//     return 0;
// }