#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "main.h"

int main() {
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    int acabou = 0;

    abertura();

    do{
        VETOR v;
        int escolha, escolhaCompararVal;

        inicializaVetor(&escolha, &v);
        organizaVetor(&escolha, &v);
        comparaVetores(&escolhaCompararVal, &escolha, &v);

        printf("\nVocê deseja usar outro vetor?\n1) Sim\n2) Não\n\nEscolha: ");
        scanf(" %d", &acabou);
        acabou--;
    } while (!acabou);

    if(acabou == 1){
        printf("\nTudo bem, até mais! :3\n\n");
    } else {
        printf("\nValor invalido!\n\n");
    }
    
    return 0;
}