#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "main.h"

void branco(){
    printf("\033[0;37m");
}

void vermelho(){
    printf("\033[1;31m");
}

void verde(){
    printf("\033[0;32m");
}

int main() {
    // Acentuação
    setlocale(LC_ALL, "Portuguese");

    int acabou = 0;

    abertura(1);

    do{
        // main.h {
            ARRAY v;
        // }

        int escolha, escolhaCompararVal;

        // array.c {
            inicializaarray(&escolha, &v);
            organizaarray(&escolha, &v);
            comparaarrays(&escolhaCompararVal, &escolha, &v);
        // }
        
        printf("\nVocê deseja usar outro array?\n1) Sim\n2) Não\n\nEscolha: ");
        scanf(" %d", &acabou);
        acabou--;

        // array.c {
            liberaMem(&v);
        // }

    } while (!acabou);

    if(acabou == 1){
        printf("\nTudo bem, até mais! :3\n\n");
    } else {
        printf("\nValor invalido!\n\n");
    }
    
    return 0;
}