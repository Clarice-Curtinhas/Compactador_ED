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

    else if(lista->ult != NULL){
        cel->ant = lista->ult;
        lista->ult->prox = cel;
        lista->ult = cel;
    }
}

tCelula *ProcuraLista(tLista *lista, char caracter){
    tCelula *aux;

    for(aux = lista->prim; aux != NULL; aux = aux->prox){
        if(caracter == RetornaCaracter(aux->arv)){
            return aux;
        }
    }

    return NULL;
}

tArvore* RetornaArvore(tCelula *cel){
    return cel->arv;
}

int FrequenciaLista(tLista *lista){
    tCelula *aux;
    int qnt = 0;

    for(aux = lista->prim; aux != NULL; aux = aux->prox){
        qnt += RetornaFrequencia(aux->arv);
    }

    return qnt;
}

tArvore *CriaArvores(tLista *lista){
    tArvore *arvore;
    tCelula *prim, *seg, *aux;

    prim = lista->prim;
    seg = prim->prox;

    arvore = CriaGalhos(prim->arv, seg->arv);

    RetiraLista(lista, seg);
    RetiraLista(lista, prim);

    InsereLista(lista, arvore);

    //para checar se ele estava fazendo a arvore certinha eu pedi para imprimir aqui em baixo
    //use para caso esteja dando problema

    /*for(aux = lista->prim; aux != NULL; aux = aux->prox){
        ImprimeArvore(aux->arv);
        printf("\n");
    }*/

    return arvore;
}

tLista *RetornaSubLista(tCelula *prim, tCelula *ult){
    tLista *nova;

    nova = CriaLista();

    nova->prim = prim;

    nova->ult = ult;

    return nova;
}

void OrdenaLista(tLista *lista, int qnt){
    if (qnt <= 1) return;

    tArvore *x = lista->prim->arv;
    int freq_x = RetornaFrequencia(x);
    int a = 1;
    int b = qnt - 1;

    tLista *subLista1, *subLista2;

    tCelula *auxA = lista->prim->prox;
    tCelula *auxB = lista->ult;

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

    lista->prim->arv = auxB->arv;
    auxB->arv = x;

    if(auxB != lista->prim){
        subLista1 = RetornaSubLista(lista->prim, auxB->ant);
        OrdenaLista(subLista1, b);
    }

    if(auxA != NULL){
        subLista2 = RetornaSubLista(auxA, lista->ult);
        OrdenaLista(subLista2, qnt - a);
    }
}

void RetiraLista(tLista *lista, tCelula *cel){
    if(cel == NULL) return;

    else{
        if(lista->prim == cel && lista->ult == cel){
            lista->prim = lista->ult = NULL;
        }

        else if(lista->prim == cel){
            lista->prim = lista->prim->prox;
            lista->prim->ant = NULL;
        }

        else if(lista->ult == cel){
            lista->ult = lista->ult->ant;
            lista->ult->prox = NULL;
        }

        else{
            if(cel->ant != NULL){
                cel->ant->prox = cel->prox;
            }

            if(cel->prox != NULL){
                cel->prox->ant = cel->ant;
            }
        }

        free(cel);
    }
}

void ImprimeLista(tLista *lista){
    /*tCelula *aux;

    for(aux = lista->prim; aux != NULL; aux = aux->prox){
        ImprimeArvore(aux->arv);
    }*/
}

void LiberaLista(tLista *lista){
    tCelula *aux, *prox;

    aux = lista->prim;

    while(aux != NULL){
        prox = aux->prox;
        free(aux);
        aux = prox;
    }
}