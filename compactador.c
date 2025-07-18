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

tArvore *Codifica(char *text){
    tArvore *arvores[256], *arv_completa;
    int tam, qnt = 0, existe;

    tam = strlen(text);

    for(int i = 0; i < tam; i++){
        if(qnt == 0){
            arvores[0] = CriaFolhas(text[0]);
            qnt++;
        }

        else{
            existe = 0;

            for(int j = 0; j < qnt; j++){

                if(text[i] == RetornaCaracter(arvores[j])){
                    AcrescimoDeCaracter(arvores[j]);

                    existe = 1;
                    break;
                }
            }

            if(existe == 0){
                arvores[qnt] = CriaFolhas(text[qnt]);
                qnt++;
            }

        }
    }

    int total = 0;

    for(int i = 0; i < qnt; i++){
        total += RetornaFrequencia(arvores[i]);
    }

    printf("%d\n", total);

    arv_completa = CriaHuffman(arvores, qnt);

    return arv_completa;
}

tArvore *CriaHuffman(tArvore **arv, int qnt){
    tArvore *arvore;
    int menorFreq1, idFreq1, menorFreq2, idFreq2;

    while(qnt != 1){
        menorFreq1 = RetornaFrequencia(arv[0]);
        idFreq1 = 0;

        for(int i = 0; i < qnt; i++){
            if(RetornaFrequencia(arv[i]) <= menorFreq1){
                menorFreq1 = RetornaFrequencia(arv[i]);
                idFreq1 = i;
            }
        }

        if(idFreq1 != 0){
            menorFreq2 = RetornaFrequencia(arv[0]);
            idFreq2 = 0;
        }

        else{
            menorFreq2 = RetornaFrequencia(arv[1]);
            idFreq2 = 1;
        }

        for(int i = 0; i < qnt; i++){
            if(RetornaFrequencia(arv[i]) <= menorFreq2 && i != idFreq1){
                menorFreq2 = RetornaFrequencia(arv[i]);
                idFreq2 = i;
            }
        }

        arvore = CriaGalhos(arv[idFreq1], arv[idFreq2]);

        arv = RetiraLista(arv, idFreq1, idFreq2,  qnt);
        qnt -= 2;

        arv = AdicionaLista(arv, arvore, qnt);
        qnt++;

        for(int i = 0; i < qnt; i++){
            printf("'%c' ", RetornaCaracter(arv[i]));
            printf("- %d\n", RetornaFrequencia(arv[i]));
        }
        printf("\n");
    }

    return arvore;
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

void EscreveTextoCodificado(char *text, tArvore *arv){
    int tam;

    tam = strlen(text);

    for(int i = 0; i < tam; i++){
        EncontraCaracter(arv, text[i]);
        printf(" ");
    }

    printf("\n");
}