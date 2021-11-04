#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "main.h"

void liberaMem(VETOR* v){
    // Não está funcionando corretamente
    for(int i = 0; i < sizeof(v->vetor)/sizeof(v->vetor[0]); i++){
        free(v->vetor[i]);
    }
    
}

int main() {
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    int acabou = 0;

    abertura(1);

    do{
        VETOR v;
        int escolha, escolhaCompararVal;

        inicializaVetor(&escolha, &v);
        organizaVetor(&escolha, &v);
        comparaVetores(&escolhaCompararVal, &escolha, &v);

        printf("\nVocê deseja usar outro vetor?\n1) Sim\n2) Não\n\nEscolha: ");
        scanf(" %d", &acabou);
        acabou--;

        liberaMem(&v);

    } while (!acabou);

    if(acabou == 1){
        printf("\nTudo bem, até mais! :3\n\n");
    } else {
        printf("\nValor invalido!\n\n");
    }
    
    return 0;
}