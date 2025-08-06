#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descompactador.h"

tArvore *DecodificaArvore(char *arvore){
    tArvore *arv;

    if(arvore[0] == '1'){
        arv = CriaFolhas(arvore[1]);
        printf("%c\n", arvore[1]);
        return arv;
    }

    else if(arvore[0] == '0'){
        tArvore *esq, *dir;

        esq = DecodificaArvore(&arvore[1]);
        dir = DecodificaArvore(&arvore[3]);

        arv = CriaGalhos(esq, dir);
    }

    return arv;
}

int EscreveTextoDecodificado(unsigned char **buffer_compactado, tArvore *arv, char *text);