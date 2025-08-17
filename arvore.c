/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arvore.h"

#define CARACTER 1
#define NUMERO 2

#define TAM_MAX_BITS 100

typedef struct Arvore{
    unsigned char carac;
    int freq;
    tArvore *esq;
    tArvore *dir;
} tArvore;

tArvore *CriaFolhas(unsigned char caracter){
    tArvore *arv;

    arv = (tArvore*) calloc(1, sizeof(tArvore));

    arv->carac = caracter;
    arv->freq = 1;

    arv->esq = NULL;
    arv->dir = NULL;

    return arv;
}

tArvore *CriaGalhos(tArvore *esq, tArvore *dir){
    tArvore *arv;

    arv = (tArvore*) calloc(1, sizeof(tArvore));

    arv->freq = RetornaFrequencia(dir) + RetornaFrequencia(esq);

    arv->esq = esq;
    arv->dir = dir;

    return arv;
}

void AcrescimoDeCaracter(tArvore *arv){
    if(arv != NULL) arv->freq++;
}

int RetornaFrequencia(tArvore *arv){
    if(arv != NULL) return arv->freq;
}

unsigned char RetornaCaracter(tArvore *arv){
    if(arv != NULL) return arv->carac;
}

unsigned char* ArvoreCompactada(tArvore *arv, unsigned char *buffer, int *tam){
    if(arv->carac){
        buffer[*tam] = '1';
        buffer[*tam+1] = arv->carac;
        buffer[*tam+2] = '\0';

        *tam += 2;
    }

    else{
        buffer[*tam] = '0';
        buffer[*tam+1] = '\0';
        *tam += 1;

        buffer = ArvoreCompactada(arv->esq, buffer, tam);
        buffer = ArvoreCompactada(arv->dir, buffer, tam);
    }

    return buffer;
}

void ImprimeArvore(tArvore *arv){

    if(arv == NULL){
        printf(" < > ");
    }

    else{
        if(arv->carac){
            if(arv->carac != '\n') printf(" < '%c'", arv->carac);
            else printf(" < quebra de linha");
        }
        
        else{
            printf(" < %d", arv->freq);
        }

        ImprimeArvore(arv->esq);
        ImprimeArvore(arv->dir);

        printf(" >");
    }
}

unsigned char* ProcuraBinario(unsigned char *vect, tArvore *arv){
    tArvore *aux;
    int qnt = 0, i = 0;
    unsigned char *texto;

    texto = (unsigned char*) calloc(strlen((char *)vect), sizeof(unsigned char));


    while (vect[i] != '\0'){
        aux = arv;

        while(aux->esq != NULL || aux->dir != NULL){
            if(vect[i] == '0'){
                aux = aux->esq;
            }

            else if(vect[i] == '1'){
                aux = aux->dir;
            }

            else break;
            i++;
        }

        texto[qnt] = aux->carac;
        texto[qnt+1] = '\0';
        qnt++;
    }

    return texto;
}

void DesalocaArvore(tArvore *arv){
    if(arv == NULL) return;

    else{
        DesalocaArvore(arv->esq);
        DesalocaArvore(arv->dir);

        free(arv);
    }
}

int EscreveCodigoHuffman(tArvore *arv, unsigned char *text, int tam){
    unsigned char caracter[tam], codigoHuffman[TAM_MAX_BITS];
    int qntAnalisados = 0, tamHuffman = 0, jaFoi;

    printf("%d\n", tam);

    for(int i = 0; i < tam; i++){
        jaFoi = 0;

        if(i != 0){
            for(int j = 0; j < qntAnalisados; j++){

                if(caracter[j] == text[i]){
                    jaFoi = 1;
                    break;
                }
            }
        }

        if(jaFoi == 0){
            printf("SCII: %d - %c - ", text[i], text[i]);

            if(EncontraCaracter(arv, text[i], codigoHuffman, 0) == 0)
                printf("Erro! caracter não encontrado");
            
            else{
                tamHuffman += strlen(codigoHuffman);
                printf("%s", codigoHuffman);
                printf(";\n");
            }

            caracter[qntAnalisados] = text[i];
            qntAnalisados++;
        }
    }

    printf("\n");

    return tamHuffman; // Tamnho a ser alocado para o buffer compactado no "compacta.c"
}

int EncontraCaracter(tArvore *arv, unsigned char carac, unsigned char *codigoHuffman, int tamCodigo){

    if(arv->carac){
        if(carac == arv->carac) {
            codigoHuffman[tamCodigo] = '\0';
            return 1;
        }
    }

    else{

        codigoHuffman[tamCodigo] = '0';
        if(EncontraCaracter(arv->esq, carac, codigoHuffman, tamCodigo + 1) == 1){
            return 1;
        }

        codigoHuffman[tamCodigo] = '1';
        if(EncontraCaracter(arv->dir, carac, codigoHuffman, tamCodigo + 1) == 1){
            return 1;
        }

        return 0;
    }
}