#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "descompactador.h"

tArvore *DecodificaArvore(unsigned char *arvore, int *tam, int tam_max){
    tArvore *arv = NULL;

    if (*tam >= tam_max) {
        fprintf(stderr, "Erro: acesso fora do vetor da árvore em *tam=%d (limite=%d)\n", *tam, tam_max);
        return NULL;
    }

    if(arvore[*tam] == '1'){
        if (*tam + 1 >= tam_max) {
            fprintf(stderr, "Erro: tentativa de acessar arvore[%d] fora do limite %d\n", *tam+1, tam_max);
            return NULL;
        }

        arv = CriaFolhas(arvore[*tam+1]);
        //printf("%c\n", arvore[*tam+1]);
        *tam += 2;
        return arv;
    }

    else if(arvore[*tam] == '0'){
        tArvore *esq, *dir;

        *tam += 1;
        esq = DecodificaArvore(arvore, tam, tam_max);
        if (!esq) return NULL;
        dir = DecodificaArvore(arvore, tam, tam_max);
        if (!dir) return NULL;

        arv = CriaGalhos(esq, dir);
        //ImprimeArvore(arv);
        //printf("\n\n");
    }
    return arv;
}

int EscreveTextoDecodificado(unsigned char **buffer_descompactado, tArvore *arv, unsigned char *text, int tam){
    unsigned char *texto;
    
    *buffer_descompactado = ProcuraBinario(text, arv, tam);

    return strlen(*buffer_descompactado);
}