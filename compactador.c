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

void Codifica(char *string){
    tArvore *arvores[256], *arv_completa;
    int tam, qnt = 0, existe;

    tam = strlen(string);

    for(int i = 0; i < tam; i++){
        if(qnt == 0){
            arvores[0] = CriaFolhas(string[0]);
            qnt++;
        }

        else{
            existe = 0;

            for(int j = 0; j < qnt; j++){

                if(string[i] == RetornaCaracter(arvores[j])){
                    AcrescimoDeCaracter(arvores[j]);

                    existe = 1;
                    break;
                }
            }

            if(existe == 0){
                arvores[qnt] = CriaFolhas(string[qnt]);
                qnt++;
            }

        }
    }

    for(int i = 0; i < qnt; i++){
        printf("'%c' ", RetornaCaracter(arvores[i]));
        printf("- %d\n", RetornaFrequencia(arvores[i]));
    }
    printf("\n");

    int total = 0;

    for(int i = 0; i < qnt; i++){
        total += RetornaFrequencia(arvores[i]);
    }

    printf("%d\n", total);

    arv_completa = CriaHuffman(arvores, qnt, total);

    //printf("'%c' - ", RetornaCaracter(arv_completa));
    printf("%d\n", RetornaFrequencia(arv_completa));

    printf("\n");
}

tArvore *CriaHuffman(tArvore **arv, int qnt, int total){
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
            if(RetornaFrequencia(arv[i]) <= menorFreq2 && menorFreq2 != menorFreq1){
                menorFreq2 = RetornaFrequencia(arv[i]);
                idFreq2 = i;
            }
        }

        arvore = CriaGalhos(arv[idFreq1], arv[idFreq2]);

        arv = RetiraLista(arv, idFreq1, qnt);
        qnt--;

        arv = RetiraLista(arv, idFreq2, qnt);
        qnt--;

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

tArvore **RetiraLista(tArvore **arv, int id, int qnt){
    for(int i = id; i < qnt; i++){
        if(i+1 < qnt) arv[i] = arv[i+1];

        else arv[i] = NULL;
    }

    return arv;
}

tArvore **AdicionaLista(tArvore **arv, tArvore *arvore, int qnt){
    arv[qnt] = arvore;

    return arv;
}