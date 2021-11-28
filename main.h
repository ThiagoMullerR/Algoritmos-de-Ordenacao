void abertura();

struct array{int *array[3], tamanhoDoarray;};
typedef struct array array;

void inicializaarray(int* escolha, array* v);
void organizaarray(int* escolha, array* v);
void comparaarrays(int* escolhaCompararVal, int* escolha, array* v);

void liberaMem(array* v);