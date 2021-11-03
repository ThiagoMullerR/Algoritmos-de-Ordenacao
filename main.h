// Vetor
float algoritmos[3];
void abertura();
struct vetor{int *vetor[3], tamanhoDoVetor;};
typedef struct vetor VETOR;
void qualTamanhoDoVetor(int *tamanhoDoVetor);
void geraAleatorio(int tamanhoDoVetor, int vetor[]);
void leDados(int tamanhoDoVetor, int vetor[]);
void printVetor(int vetor[], int tamanhoDoVetor);
void printMerge(int vetor[], int tamanhoDoVetor);
void executaBubbleSort(int vetor[], int tamanhoDoVetor);
void executaInsertionSort(int vetor[], int tamanhoDoVetor);
void executaMergeSort(int vetor[], int tamanhoDoVetor);
void inicializaVetor(int* escolha, VETOR* v);
void organizaVetor(int* escolha, VETOR* v);
void comparaVetores(int* escolhaCompararVal, int* escolha, VETOR* v);

// Cronômetro
void printTempo(int escolha);
void printTempos();
void contagemCronometro(int escolha, unsigned long inicio, unsigned long fim);

// BubbleSort
void bubbleSort(int *vetor, int tamanhoDoVetor);
void troca(int *a, int *b);

// Insertion Sort
void insertionSort(int vetor[], int tamanhoDoVetor);

// Merge Sort
void merge(int vetor[], int comeco, int meio, int fim);
void mergeSort(int vetor[], int comeco, int fim);