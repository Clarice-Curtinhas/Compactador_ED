/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "compactador.h"
#include "arvore.h"

#define CARACTER 1
#define NUMERO 2

void Codifica(char *string){
    tArvore *arvores[256];
    int tam, qnt = 0, existe;

    tam = strlen(string);

    for(int i = 0; i < tam; i++){
        if(qnt == 0){
            arvores[0] = CriaArvore(string[0], NULL, NULL);
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
                arvores[qnt] = CriaArvore(string[qnt], NULL, NULL);
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
}

/*tArvore *CriaHuffman(tArvore **arv, int qnt){
    //tArvore *arvCod[100];
    int total, count = 0, acha1 = -1, acha2 = -1;

    for(int i = 0; i < qnt; i++){
        total += RetornaFrequencia(arv[i]);
    }

    printf("%d\n", total);

    /*while(count < total){
        while(acha1 < total)
        count++;
    }*/

    /*return NULL;//arvCod;
}*/