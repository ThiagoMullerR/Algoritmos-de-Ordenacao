// Vetor
struct vetor{int tamanhoDoVetor, *vetor;};
typedef struct vetor VETOR;
void qualTamanhoDoVetor(int *tamanhoDoVetor);
void geraAleatorio(int tamanhoDoVetor, int vetor[]);
void leDados(int tamanhoDoVetor, int vetor[]);
void printVetor(int vetor[], int tamanhoDoVetor);
void printMerge(int vetor[], int tamanhoDoVetor);

// Cronômetro (vetor.c)
void printTempo(int escolha);

// BubbleSort
void bubbleSort(int *vetor, int tamanhoDoVetor);
void troca(int *a, int *b);

// Insertion Sort
void insertionSort(int vetor[], int tamanhoDoVetor);

// Merge Sort
void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);