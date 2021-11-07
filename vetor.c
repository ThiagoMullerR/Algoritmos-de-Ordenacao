#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

// Recebe qual será o tamanho do vetor
void qualTamanhoDoVetor(int *tamanhoDoVetor) {
    printf("\nInsira a quantidade de números dentro do vetor:\n");
    scanf("%d", tamanhoDoVetor);
}

void geraAleatorio(int tamanhoDoVetor, int vetor[]) {
    int limiteCasasAleatorios = 100; // 100 = de 0 a 99.
    srand(time(0)); // Função para gerar aleatório com base no tempo para não repetir os valores
    for (int i = 0; i < tamanhoDoVetor; i++) {
        vetor[i] = rand() % limiteCasasAleatorios; 
    }
}

// Caso for selecionada a opção de escolher os valores do vetor,
// a função irá receber os valores que o usuário fornecerá
void leDados(int tamanhoDoVetor, int vetor[]) {
    printf("\nInsira os valores dentro do vetor:\n");
    for(int i = 0; i < tamanhoDoVetor; i++){
        scanf("%d", &vetor[i]);
    }
}

// Print padrão de vetores
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

void executaBubbleSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    bubbleSort(vetor, tamanhoDoVetor - 1); // (função em BubbleSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(0, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}

void executaInsertionSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    insertionSort(vetor, tamanhoDoVetor); // (Função em InsertionSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(1, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}

void executaMergeSort(int vetor[], int tamanhoDoVetor) {
    clock_t inicioCronometro = clock();
    mergeSort(vetor, 0, tamanhoDoVetor); // (Função em MergeSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(2, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}


void inicializaVetor(int* escolha, VETOR* v){

    qualTamanhoDoVetor(&v->tamanhoDoVetor);
    
    // Alocação dinâmica de memória
    for(int i = 0; i < sizeof(v->vetor)/sizeof(v->vetor[0]); i++){
        v->vetor[i] = (int*) malloc(sizeof(int) * v->tamanhoDoVetor + 1);
    }

    printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
    scanf("%d", escolha);
    
    switch (*escolha){
    case 1:
        geraAleatorio(v->tamanhoDoVetor, v->vetor[0]);
        break;
    case 2:
        leDados(v->tamanhoDoVetor, v->vetor[0]);
        break;
    default:
        printf("Erro! Valor inválido!\n");
        exit(1);
    }

    // Aqui, irá haver uma cópia do vetor desordenado para os outros 2 vetores. Por exemplo:
    // o vetor foi definido para ter o tamanho de 5 valores e esses valores foram gerados aleatóriamente
    // (Lembrando que começa em [0] e o valor do último [5] é um "\0").
    // Então, na memória, o primeiro vetor ficará:
    // vetor[0][5] = {21, 23, 43, 2, 5} 
    // o vetor[0][5] será copiado para os vetores vetor[1][5] e vetor[2][5]
    

    // A sintaxe é do vetor é mais ou menos assim:
    // int vetor[0][tamanhoDoVetor];

    // - O vetor[0] sempre será ordenado pelo BubbleSort
    // - O vetor[1] sempre será ordenado pelo InsertionSort
    // - O vetor[2] sempre será ordenado pelo MergeSort
    for(int i = 0; i <=  v->tamanhoDoVetor; i++){
        v->vetor[2][i] = v->vetor[1][i] = v->vetor[0][i];
    }
}

void organizaVetor(int* escolha, VETOR* v){
    printf("\nQual algorítmo de ordenação você deseja usar?\n1) Bubble Sort\n2) Insertion Sort\n3) Merge Sort\n\nDigite: ");
    scanf("%d", escolha);

    if(*escolha == 1){
        printf("\n\n-- BUBBLE SORT --\n");
    } else if(*escolha == 2){
        printf("\n\n-- INSERTION SORT --\n");
    } else if(*escolha == 3){
        printf("\n\n-- MERGE SORT --\n");
    } else {
        printf("\nErro! Opção Inválida!\n");
        exit(1);
    };

    printf("\n\033[1;31mVetor antes da ordenação:\n");
    printVetor(v->vetor[0], v->tamanhoDoVetor);

    printf("\n\033[0;32mVetor depois da ordenação:\n");

    switch (*escolha) {
    case 1:
        executaBubbleSort(v->vetor[0], v->tamanhoDoVetor);
        printVetor(v->vetor[0], v->tamanhoDoVetor);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    case 2:
        executaInsertionSort(v->vetor[1], v->tamanhoDoVetor);
        printVetor(v->vetor[1], v->tamanhoDoVetor);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    case 3:
        executaMergeSort(v->vetor[2], v->tamanhoDoVetor);
        printMerge(v->vetor[2], v->tamanhoDoVetor);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    }
}

void comparaVetores(int* escolhaCompararVal, int* escolha, VETOR* v){
    printf("Você deseja comparar os valores?\n1) Sim\n2) Não\n\nEscolha: ");
    scanf("%d", escolhaCompararVal);

    if (*escolhaCompararVal == 1) {
        switch (*escolha) {
        // Se quiser comparar os valores, será executado a ordenação dos outros vetores
        // sem os printar, apenas será salvo os tempos no vetor algoritmos[] do arquivo cronometro.c
        // e serão exibidos os seus tempos
        case 1:
            // Caso tenha escolhido o bubble sort
            executaInsertionSort(v->vetor[1], v->tamanhoDoVetor);
            executaMergeSort(v->vetor[2], v->tamanhoDoVetor);
            printTempos(); // (Função em cronometro.c)
            break;
        case 2:
            // Caso tenha escolhido o insertion sort
            executaBubbleSort(v->vetor[0], v->tamanhoDoVetor);
            executaMergeSort(v->vetor[2], v->tamanhoDoVetor);
            printTempos(); // (Função em cronometro.c)
            break;
        case 3:
            // Caso tenha escolhido o merge sort
            executaBubbleSort(v->vetor[0], v->tamanhoDoVetor);
            executaInsertionSort(v->vetor[1], v->tamanhoDoVetor);
            printTempos(); // (Função em cronometro.c)
            break;
        default:
            printf("\nErro! Opção Inválida!\n");
            exit(1);
        }
    }
}

// Libera a memória alocada dinâmicamente
void liberaMem(VETOR* v){
    for(int i = 0; i < sizeof(v->vetor)/sizeof(v->vetor[0]); i++){
        free(v->vetor[i]);
    }
}