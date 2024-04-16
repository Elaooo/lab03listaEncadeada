#include <stdio.h>
#include <stdlib.h>

#include "TADlistaencadeada.h"

int main() {
    Lista L;
    inicializaLista(&L);

    insereFim(&L, 10);
    insereFim(&L, 20);
    insereFim(&L, 30);

    printf("Lista apos inserção:\n");
    printaLista(L);

    removePosicao(&L, 2);
    printf("Lista apos remover o segundo elemento:\n");
    printaLista(L);

    inserePosicao(&L, 2, 25);
    printf("Lista apos inserir 25 na posicao 2:\n");
    printaLista(L);

    Apontador e = retornaLista(L, 3);
    printf("Elemento na posicao 3: %d\n", e->elemento.valor);
    printf("\nTrocando os elementos nas posicoes 2 e 1:\n");
    trocaPosicoes(&L, 2, 1);
    printaLista(L);
    destroiLista(&L);

    return 0;
}
