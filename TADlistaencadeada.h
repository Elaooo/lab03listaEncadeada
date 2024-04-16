#ifndef TADLISTAENCADEADA_H
#define TADLISTAENCADEADA_H

typedef struct
{
    int valor;
}Item;

typedef struct Celula
{
  Item elemento;
  struct Celula* prox;
}Celula;

typedef Celula* Apontador;

typedef struct
{
    Apontador primeiro;
    Apontador ultimo;
    int tamanho;
}Lista;

void inicializaLista(Lista* lista);
int listaVazia(Lista lista);

#endif // TADLISTAENCADEADA_H
