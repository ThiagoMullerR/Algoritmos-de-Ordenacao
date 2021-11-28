void abertura();

struct array{int *array[3], tamanhoDoarray;};
typedef struct array ARRAY;

void inicializaarray(int* escolha, ARRAY* v);
void organizaarray(int* escolha, ARRAY* v);
void comparaarrays(int* escolhaCompararVal, int* escolha, ARRAY* v);

void liberaMem(ARRAY* v);

void branco();
void verde();
void vermelho();