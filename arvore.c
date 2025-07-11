/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

#define CARACTER 1
#define NUMERO 2

typedef struct Arvore{
    char carac;
    int freq;
    tArvore *esq;
    tArvore *dir;
} tArvore;

tArvore *CriaArvore(char caracter, tArvore *esq, tArvore *dir){
    tArvore *arv;

    arv = (tArvore*) calloc(1, sizeof(tArvore));

    arv->carac = caracter;
    arv->freq = 1;

    arv->esq = esq;
    arv->dir = dir;

    return arv;
}

void AcrescimoDeCaracter(tArvore *arv){
    arv->freq++;
}

int RetornaFrequencia(tArvore *arv){
    return arv->freq;
}

char RetornaCaracter(tArvore *arv){
    return arv->carac;
}

void DesalocaArvore(tArvore *arv){
    if(arv == NULL) return;

    else{
        DesalocaArvore(arv->esq);
        DesalocaArvore(arv->dir);

        free(arv);
    }
}