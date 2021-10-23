// Vetor
struct vetor{int tamanhoDoVetor, *vetor;};
void qualTamanhoDoVetor(int *tamanhoDoVetor);
void leDados(int tamanhoDoVetor, int vetor[]);
void printVetor(int vetor[], int tamanhoDoVetor);

// Cronômetro (vetor.c)
void printTempo(double cronometro);

// BubbleSort
void bubbleSort(int *vetor, int tamanhoDoVetor);
void troca(int *a, int *b);

// Insertion Sort
void insertionSort(int vetor[], int tamanhoDoVetor);

// Merge Sort
void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);