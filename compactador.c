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


tArvore *Codifica(unsigned char *text, unsigned char matriz_codigo[ASCII][ASCII], int tam){
    tArvore *arvores[ASCII], *arv_completa, *vetor_arv[ASCII];
    int qnt = 0, existe, h;

    //printf("%s", text);

    for(int i = 0; i < ASCII; i++){
        arvores[i] = NULL;
    }

    //coloca os caracteres dentro de um vetor de arvores de acordo com o ASCII para
    //não ter fazer diversas buscas lineares (otimizando o código)

    for(int i = 0; i < tam; i++){
        h = text[i];

        if(arvores[h] == NULL){
            arvores[h] = CriaFolhas(text[i]);
        }

        else{
            AcrescimoDeCaracter(arvores[h]);
        }
    }

    //cria outro vetor que não terá mais indices NULLs para facilitar quicksort

    for(int i = 0; i < ASCII; i++){
        if(arvores[i] != NULL){
            vetor_arv[qnt] = arvores[i];
            qnt++;
        }
    }

    //printf("%s", text);

    OrdenaLista(vetor_arv, qnt);

    int total = 0;

    for(int i = 0; i < qnt; i++){
        total += RetornaFrequencia(vetor_arv[i]);
    }

    //printf("%d\n", total);

    arv_completa = CriaHuffman(vetor_arv, qnt);

    for(int i = 0; i < ASCII; i++){
        if(arvores[i] != NULL){
            EncontraCaracter(arv_completa, RetornaCaracter(arvores[i]), matriz_codigo[i], 1);

            /*//printf("codigo: %c\n", i);

            for (int j = 1; matriz_codigo[i][j] != '\0'; j++){
                //printf("%u ", matriz_codigo[i][j]); //teste
            }
            //printf("\n");*/
            qnt++;
        }
    }

    return arv_completa;
}

tArvore *CriaHuffman(tArvore **arv, int qnt){
    tArvore *arvore;
    int menorFreq1, idFreq1, menorFreq2, idFreq2;

    while(qnt != 1){
        idFreq1 = 0;
        idFreq2 = 1;

        arvore = CriaGalhos(arv[idFreq1], arv[idFreq2]);

        arv = RetiraLista(arv, idFreq1, idFreq2,  qnt);
        qnt -= 2;

        arv = AdicionaLista(arv, arvore, qnt);
        qnt++;

        /*for(int i = 0; i < qnt; i++){
            printf("'%c' ", RetornaCaracter(arv[i]));
            printf("- %d\n", RetornaFrequencia(arv[i]));
        }
        printf("\n");*/
    }

    return arvore;
}

void OrdenaLista(tArvore **arv, int qnt){
    
    if (qnt <= 1) return;

    tArvore *x = arv[0];
    int freq_x = RetornaFrequencia(arv[0]);
    int a = 1;
    int b = qnt - 1;

    do {
        while (a < qnt && RetornaFrequencia(arv[a]) <= freq_x) a++;
        while (RetornaFrequencia(arv[b]) > freq_x) b--;

        if (a < b){
            tArvore *aux = arv[a];
            arv[a] = arv[b];
            arv[b] = aux;
            a++;
            b--;
        } 
    } while (a <= b);

    arv[0] = arv[b];
    arv[b] = x;

    OrdenaLista(arv, b);
    OrdenaLista(&arv[a], qnt - a);
}

tArvore **RetiraLista(tArvore **arv, int id1, int id2, int qnt){
    int id[2];

    if(id1 > id2){
        id[0] = id1;
        id[1] = id2;
    }

    else{
        id[0] = id2;
        id[1] = id1;
    }

    for(int j = 0; j < 2; j++){
        for(int i = id[j]; i < qnt; i++){
            if(i+1 < qnt) arv[i] = arv[i+1];

            else arv[i] = NULL;
        }
    }

    return arv;
}

tArvore **AdicionaLista(tArvore **arv, tArvore *arvore, int qnt){
    arv[qnt] = arvore;

    return arv;
}

int EscreveTextoCodificado(unsigned char *text, unsigned char matriz[ASCII][ASCII], unsigned char **buffer_compactado, int tam_texto){
    int tam_codigo = 0, index;

    *buffer_compactado = (unsigned char *) calloc(tam_texto * 8, sizeof(unsigned char));

    for(int i = 0; i < tam_texto; i++){
        index = text[i];
        //printf("\n\nCod. ASCII: %d\nletra %c\n", index, text[i]); //teste
        //printf("Cod. Huffman: "); //teste

        for (int j = 1; matriz[index][j] != '\0'; j++){
            (*buffer_compactado)[tam_codigo] = matriz[index][j];
            //printf("%c ", (*buffer_compactado)[tam_codigo]); //teste
            tam_codigo++;
        }
    }

    tam_codigo++;
    //(*buffer_compactado)[tam_codigo] = '\0';

    return tam_codigo;
}