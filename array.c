#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"
#include "array.h"
#include "cronometro.h"
#include "algoritmos.h"

// Recebe qual será o tamanho do array
void qualTamanhoDoarray(int *tamanhoDoarray) {
    printf("\nInsira a quantidade de números dentro do array:\n");
    scanf("%d", tamanhoDoarray);
}

void geraAleatorio(int tamanhoDoarray, int array[]) {
    int limiteCasasAleatorios = 100; // 100 = de 0 a 99.
    srand(time(0)); // Função para gerar aleatório com base no tempo para não repetir os valores
    for (int i = 0; i < tamanhoDoarray; i++) {
        array[i] = rand() % limiteCasasAleatorios; 
    }
}

// Caso for selecionada a opção de escolher os valores do array,
// a função irá receber os valores que o usuário fornecerá
void leDados(int tamanhoDoarray, int array[]) {
    printf("\nInsira os valores dentro do array:\n");
    for(int i = 0; i < tamanhoDoarray; i++){
        scanf("%d", &array[i]);
    }
}

// Print padrão de arrays
void printarray(int array[], int tamanhoDoarray){
    for(int i = 0; i < tamanhoDoarray; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

// O print do merge sort precisa ser diferente, pois a função sempre gera um número 0 no final do array
// e este valor é ordenado junto com os outros, ou seja, toda vez que printamos um merge usando o print
// de cima, é mostrado um valor 0 no início e o ultimo valor não é exibido. 
// Para corrigir, iniciamos a variável do loop em 1 para pular o primeiro valor e dizemos que o loop só vai 
// finalizar quando i <= que o tamanhoDoarray
void printMerge(int array[], int tamanhoDoarray) {
    for (int i = 1; i <= tamanhoDoarray; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void executaBubbleSort(int array[], int tamanhoDoarray) {
    clock_t inicioCronometro = clock();
    bubbleSort(array, tamanhoDoarray - 1); // (função em BubbleSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(0, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}

void executaInsertionSort(int array[], int tamanhoDoarray) {
    clock_t inicioCronometro = clock();
    insertionSort(array, tamanhoDoarray); // (Função em InsertionSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(1, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}

void executaMergeSort(int array[], int tamanhoDoarray) {
    clock_t inicioCronometro = clock();
    mergeSort(array, 0, tamanhoDoarray); // (Função em MergeSort.c)
    clock_t fimCronometro = clock();
    contagemCronometro(2, inicioCronometro, fimCronometro); // (Função em cronometro.c)
}


void inicializaarray(int* escolha, ARRAY* v){

    qualTamanhoDoarray(&v->tamanhoDoarray);
    
    // Alocação dinâmica de memória
    for(int i = 0; i < sizeof(v->array)/sizeof(v->array[0]); i++){
        v->array[i] = (int*) malloc(sizeof(int) * v->tamanhoDoarray + 1);
    }

    printf("\nVocê deseja usar números aleatórios ou escolher os valores a serem ordenados?\n1) Aleatórios\n2) Escolher os valores\n\nDigite: ");
    scanf("%d", escolha);
    
    switch (*escolha){
    case 1:
        geraAleatorio(v->tamanhoDoarray, v->array[0]);
        break;
    case 2:
        leDados(v->tamanhoDoarray, v->array[0]);
        break;
    default:
        printf("Erro! Valor inválido!\n");
        exit(1);
    }

    // Aqui, irá haver uma cópia do array desordenado para os outros 2 arrays. Por exemplo:
    // o array foi definido para ter o tamanho de 5 valores e esses valores foram gerados aleatóriamente
    // (Lembrando que começa em [0] e o valor do último [5] é um "\0").
    // Então, na memória, o primeiro array ficará:
    // array[0][5] = {21, 23, 43, 2, 5} 
    // o array[0][5] será copiado para os arrays array[1][5] e array[2][5]
    

    // A sintaxe do array é mais ou menos assim:
    // int array[0][tamanhoDoarray];

    // - O array[0] sempre será ordenado pelo BubbleSort
    // - O array[1] sempre será ordenado pelo InsertionSort
    // - O array[2] sempre será ordenado pelo MergeSort
    for(int i = 0; i <=  v->tamanhoDoarray; i++){
        v->array[2][i] = v->array[1][i] = v->array[0][i];
    }
}

void organizaarray(int* escolha, ARRAY* v){
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

    printf("\n\033[1;31marray antes da ordenação:\n");
    printarray(v->array[0], v->tamanhoDoarray);

    printf("\n\033[0;32marray depois da ordenação:\n");

    switch (*escolha) {
    case 1:
        executaBubbleSort(v->array[0], v->tamanhoDoarray);
        printarray(v->array[0], v->tamanhoDoarray);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    case 2:
        executaInsertionSort(v->array[1], v->tamanhoDoarray);
        printarray(v->array[1], v->tamanhoDoarray);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    case 3:
        executaMergeSort(v->array[2], v->tamanhoDoarray);
        printMerge(v->array[2], v->tamanhoDoarray);
        printTempo(*escolha); // (Função em cronometro.c)
        break;
    }
}

void comparaarrays(int* escolhaCompararVal, int* escolha, ARRAY* v){
    printf("Você deseja comparar os tempos de cada algoritmo para o mesmo array?\n1) Sim\n2) Não\n\nEscolha: ");
    scanf("%d", escolhaCompararVal);

    if (*escolhaCompararVal == 1) {
        switch (*escolha) {
        // Se quiser comparar os tempos, será executado a ordenação dos outros arrays
        // sem os printar, apenas será salvo os tempos no array algoritmos[] do arquivo cronometro.c
        // e serão exibidos os seus tempos
        case 1:
            // Caso tenha escolhido o bubble sort
            executaInsertionSort(v->array[1], v->tamanhoDoarray);
            executaMergeSort(v->array[2], v->tamanhoDoarray);
            printTempos(); // (Função em cronometro.c)
            break;
        case 2:
            // Caso tenha escolhido o insertion sort
            executaBubbleSort(v->array[0], v->tamanhoDoarray);
            executaMergeSort(v->array[2], v->tamanhoDoarray);
            printTempos(); // (Função em cronometro.c)
            break;
        case 3:
            // Caso tenha escolhido o merge sort
            executaBubbleSort(v->array[0], v->tamanhoDoarray);
            executaInsertionSort(v->array[1], v->tamanhoDoarray);
            printTempos(); // (Função em cronometro.c)
            break;
        default:
            printf("\nErro! Opção Inválida!\n");
            exit(1);
        }
    }
}

// Libera a memória alocada dinâmicamente
void liberaMem(ARRAY* v){
    for(int i = 0; i < sizeof(v->array)/sizeof(v->array[0]); i++){
        free(v->array[i]);
    }
}
