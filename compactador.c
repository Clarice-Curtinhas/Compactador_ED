/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compactador.h"

#define CARACTER 1
#define NUMERO 2

tArvore *Codifica(unsigned char *text, long tam){
    tArvore *arvore;
    tLista *lista = CriaLista();
    int qnt = 0, total = 0;

    if(text == NULL){
        printf("ERRO: texto não lido");
        return NULL;
    }

    for(int i = 0; i < tam; i++){
        if(qnt == 0){
            InsereLista(lista, CriaFolhas(text[0]));
            qnt++;
        }

        else{
            tCelula *cel = ProcuraLista(lista, text[i]);

            if(cel != NULL){
                AcrescimoDeCaracter(RetornaArvore(cel));
            }

            else{
                InsereLista(lista, CriaFolhas(text[i]));
                qnt++;
            }
        }
    }

    OrdenaLista(lista, qnt);
    total = FrequenciaLista(lista);

    printf("func, codifica: %d\n", total);

    arvore = CriaHuffman(lista, total);

    LiberaLista(lista);

    return arvore;
}

tArvore *CriaHuffman(tLista *lista, int qnt){
    tArvore *arvore;
    int total = 0;

    do{
        arvore = CriaArvores(lista);

        total = RetornaFrequencia(arvore);
    }while(total != qnt);

    return arvore;
}

int EscreveTextoCodificado(unsigned char *text, tArvore *arv, unsigned char **buffer_compactado){
    int tam, tamCodigo = 0;
    unsigned char *codigoHuffman;

    tam = strlen(text);

    for(int i = 0; i < tam; i++){
        EncontraCaracter(arv, text[i], codigoHuffman, 0);
        tamCodigo += strlen(codigoHuffman);

        printf("%s", codigoHuffman);
        printf(" ");
    }
    printf("\n");

    *buffer_compactado = (unsigned char *) calloc(tamCodigo, sizeof(unsigned char));
    
    for(int i = 0; i < tam; i++){
        EncontraCaracter(arv, text[i], codigoHuffman, 0);
        strcat(*buffer_compactado, codigoHuffman);
    }

    return tamCodigo;
}