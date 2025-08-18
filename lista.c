
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

typedef struct Celula{
    unsigned char *codigo;
    tCelula *prox;
} tCelula;

typedef struct Lista{
    tCelula *prim;
    tCelula *ult;
}tLista;

tLista* CriaLista(){
    tLista *lista;

    lista = (tLista*) calloc(1, sizeof(tLista));

    lista->prim = NULL;
    lista->ult = NULL;

    return lista;
}

void InsereLista(unsigned char *codigo, tLista *l){
    //celula nova que vai ser colocada na lista
    tCelula *cel;

    cel = (tCelula*) calloc(1, sizeof(tCelula));

    if(l->ult == NULL){
        l->prim = l->ult = cel;
    }

    else{
        l->ult->prox = cel;
        l->ult = l->ult->prox;
    }

    l->ult->codigo = codigo;
    l->ult->prox = NULL;
}

int ImprimeCodigo(unsigned char *text, tLista *l, int tamCodigo){
    tCelula *cel;
    int i = 0;

    for(cel = l->prim; cel != NULL; cel = cel->prox){
        text[i] = cel->codigo;
        i++;
    }

    text[i] = '\0';
}

void DesalocaLista(tLista *l){
    if(l != NULL){
        tCelula *aux, *outro;

        for(aux = l->prim; aux != NULL;){
            outro = aux->prox;
            free(aux);
            aux = outro;
        }

        free(l);
    }
}