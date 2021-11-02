#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int limiteCasasAleatorios = 100; // 100 = de 0 a 99.

void qualTamanhoDoVetor(int *tamanhoDoVetor) {
    printf("\nInsira a quantidade de números dentro do vetor:\n");
    scanf("%d", tamanhoDoVetor);
}

void geraAleatorio(int tamanhoDoVetor, int vetor[]) {
    srand(time(0)); // Função para gerar aleatório com base no tempo para não repetir os valores
    for (int i = 0; i < tamanhoDoVetor; i++) {
        // Aqui definimos até qual valor será gerado o aleatório
        // % 100 (restante da divisao de 100) 
        // significa que será gerado um valor de 0 até 99 (100 números)
        vetor[i] = rand() % limiteCasasAleatorios; 
    }
}

void leDados(int tamanhoDoVetor, int vetor[]) {
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

// O print do merge sort precisa ser diferente, pois a função sempre gera um número 0 no final do vetor
// e este valor é ordenado junto com os outros, ou seja, toda vez que printamos um merge usando o print
// de cima, é mostrado um valor 0 no início e o ultimo valor não é exibido. 
// Para corrigir, iniciamos a variável do loop em 1 para pular o primeiro valor e dizemos que o loop só vai 
// finalizar quando i <= que o tamanhoDoVetor
void printMerge(int vetor[], int tamanhoDoVetor) {
    for (int i = 1; i <= tamanhoDoVetor; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}