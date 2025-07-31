#ifndef LISTA_H
#define LISTA_H

#include "arvore.h"

typedef struct celula tCelula;

typedef struct lista tLista;

tLista *CriaLista();

void InsereLista(tLista *lista, tArvore *arv);

void OrdenaLista(tLista *lista, int qnt);

void RetiraLista(tLista *lista, int id1, int id2, int qnt);

#endif