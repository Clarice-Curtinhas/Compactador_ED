#ifndef LISTA_H
#define LISTA_H

#include "arvore.h"

typedef struct celula tCelula;

typedef struct lista tLista;

tLista *CriaLista();

void InsereLista(tLista *lista, tArvore *arv);

tCelula *ProcuraLista(tLista *lista, char caracter);

tArvore* RetornaArvore(tCelula *cel);

int FrequenciaLista(tLista *lista);

tArvore *CriaArvores(tLista *lista);

tLista *RetornaSubLista(tCelula *prim, tCelula *ult);

void OrdenaLista(tLista *lista, int qnt);

void RetiraLista(tLista *lista, tCelula *cel);

void ImprimeLista(tLista *lista);

#endif