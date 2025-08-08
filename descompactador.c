#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descompactador.h"

tArvore *DecodificaArvore(unsigned char *arvore, int *tam){
    tArvore *arv;

    if(arvore[*tam] == '1'){
        arv = CriaFolhas(arvore[*tam+1]);
        printf("%c\n", arvore[*tam+1]);
        *tam += 2;
        return arv;
    }

    else if(arvore[*tam] == '0'){
        tArvore *esq, *dir;

        *tam += 1;
        esq = DecodificaArvore(arvore, tam);
        dir = DecodificaArvore(arvore, tam);

        arv = CriaGalhos(esq, dir);
        ImprimeArvore(arv);
        printf("\n\n");
    }

    return arv;
}

int EscreveTextoDecodificado(unsigned char **buffer_descompactado, tArvore *arv, unsigned char *text){
    unsigned char *texto;

    *buffer_descompactado = ProcuraBinario(text, arv);

    return strlen(*buffer_descompactado);
}