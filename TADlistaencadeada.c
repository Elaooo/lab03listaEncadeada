#include <stdio.h>
#include <stdlib.h>

#include "TADlistaencadeada.h"

void inicializaLista(Lista* lista)
{
    lista->primeiro = (Apontador) malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->prox = NULL;
    lista->tamanho = 0;
}
int listaVazia(Lista lista)
{
    return (lista.primeiro == lista.ultimo);
}
int tamanhoLista(Lista* lista)
{
    int tamanho = 0;
    Apontador p = lista->primeiro->prox;
    while(p != NULL)
    {
        p = p->prox;
        tamanho++;
    }
    return tamanho;
}
void insereFim(Lista* lista,Item chave)
{
    lista->ultimo->prox = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->elemento = chave;
    lista->ultimo->prox = NULL;
    lista->tamanho++;
}
void inserePosicao(Lista* lista,int posicao,int chave)
{
    if(posicao<1 || posicao>lista->tamanho)
    {
        printf("posicao invalida!\n");
        return 0;
    }
    Apontador antecessor = lista->primeiro;
    Apontador sucessor = antecessor->prox;
    for(int i = 0;i<posicao;i++ )
    {
        antecessor = sucessor;
        sucessor = antecessor->prox;
    }
    Celula *nova = (Celula*) malloc(sizeof(Celula));
    nova->elemento.valor = chave;
    antecessor->prox = nova;
    nova->prox = sucessor;
    if(nova->prox == NULL)
    {
        lista->ultimo = nova;
    }
}
void removePosicao(Lista *lista,int posicao)
{
    if(posicao<1 || posicao>lista->tamanho)
    {
        printf("posicao invalida!\n");
        return 0;
    }
    Apontador antecessor = lista->primeiro;
    Apontador sucessor = antecessor->prox;
    for(int i = 0;i<posicao;i++ )
    {
        antecessor = sucessor;
        sucessor = antecessor->prox;
    }
    if(sucessor == NULL)
    {
        lista->ultimo == antecessor;
    }
    else
    {
        antecessor->prox = sucessor->prox;
    }

}
void printaLista(Lista lista)
{
    Celula* atual = lista.primeiro->prox;

    if(listaVazia(lista))
    {
        printf("Lista vazia!\n");
        return;
    }
    while(atual!= NULL)
    {
        printf("%d\n",atual->elemento.valor);
        atual = atual->prox;
    }
}
void destroiLista(Lista* lista)
{
    Apontador atual = lista->primeiro->prox;
    while (atual!=NULL)
    {
        Apontador proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(lista->primeiro);

}
Apontador retornaLista(Lista lista, int posicao)
{
    if(posicao<1 || posicao>lista.tamanho)
    {
        printf("posicao invalida!\n");
        return;
    }
    Apontador atual = lista.primeiro->prox;
    for(int i = 1;i<posicao;i++)
    {
        atual = atual->prox;
    }
    return atual;
}
void trocaPosicoes(Lista* lista, int p1, int p2) {
    if (p1 < 1 || p1 > lista->tamanho || p2 < 1 || p2 > lista->tamanho) {
        printf("invalido!\n");
        return;
    }
    Apontador anterior1 = NULL;
    Apontador atual1 = lista->primeiro;
    for (int i = 0; i < p1; i++) {
        anterior1 = atual1;
        atual1 = atual1->prox;
    }

    Apontador anterior2 = NULL;
    Apontador atual2 = lista->primeiro;
    for (int i = 0; i < p2; i++) {
        anterior2 = atual2;
        atual2 = atual2->prox;
    }

    if (anterior1 != NULL) {
        anterior1->prox = atual2;
    } else {
        lista->primeiro = atual2;
    }

    if (anterior2 != NULL) {
        anterior2->prox = atual1;
    } else {
        lista->primeiro = atual1;
    }

    Apontador temp = atual1->prox;
    atual1->prox = atual2->prox;
    atual2->prox = temp;

    if (atual1->prox == NULL) {
        lista->ultimo = atual1;
    }

    if (atual2->prox == NULL) {
        lista->ultimo = atual2;
    }
}

