#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

typedef struct celula{
    tArvore *arv;
    tCelula *prox;
    tCelula *ant;
} tCelula;

typedef struct lista{
    tCelula *prim;
    tCelula *ult;
} tLista;

tLista *CriaLista(){
    tLista *lista;

    lista = (tLista*) calloc(sizeof(tLista), 1);

    lista->prim = lista->ult = NULL;

    return lista;
}

void InsereLista(tLista *lista, tArvore *arv){
    tCelula *cel;

    cel = (tCelula*) calloc(sizeof(tCelula), 1);

    cel->arv = arv;
    cel->ant = cel->prox = NULL;

    if(lista->prim == NULL && lista->ult == NULL){
        lista->prim = cel;
        lista->ult = cel;
    }

    else{
        lista->ult->prox = cel;
        cel->ant = lista->ult;
        lista->ult = cel;
    }
}

void OrdenaLista(tLista *lista, int qnt){
    if (qnt <= 1) return;

    tArvore *x = lista->prim;
    int freq_x = RetornaFrequencia(lista->prim->arv);
    int a = 1;
    int b = qnt - 1;
    tCelula auxA, auxB;

    auxA = lista->prim->prox;
    auxB = lista->ult;

    do {
        while (a < qnt && RetornaFrequencia(auxA->arv) <= freq_x){
            auxA = auxA->prox;
            a++;
        }
        while (RetornaFrequencia(auxB->arv) > freq_x){
            auxB = auxB->ant;
            b--;
        }

        if (a < b){
            tArvore *aux = auxA->arv;
            auxA->arv = auxB->arv;
            auxB->arv = aux;
            auxA = auxA->prox;
            auxB = auxB->ant;
            a++;
            b--;
        } 
    } while (a <= b);

    lista->prim = auxB;
    auxB = x;

    OrdenaLista(lista, b);
    OrdenaLista(, qnt - a);
}

void RetiraLista(tLista *lista, int id1, int id2, int qnt);