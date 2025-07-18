/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "compactador.h"
#include "arvore.h"

int main(){
    tArvore *arv1, *arv2;
    int tam;

    char *text1 = "bom esse bombom", *text2 = "arara azul";

    arv1 = Codifica(text1);

    ImprimeArvore(arv1);
    printf("\n");

    tam = strlen(text1);

    EscreveCodigoHuffman(arv1, text1, tam);

    EscreveTextoCodificado(text1, arv1);

    //////////////////////

    arv2 = Codifica(text2);

    ImprimeArvore(arv2);
    printf("\n");

    tam = strlen(text2);

    EscreveCodigoHuffman(arv2, text2, tam);

    EscreveTextoCodificado(text2, arv2);
}