/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#ifndef COMPACTADOR_H
#define COMPACTADOR_H

#include "arvore.h"

void Codifica(char *string);

tArvore *CriaHuffman(tArvore **arv, int qnt, int total);

tArvore **RetiraLista(tArvore **arv, int id, int qnt);

tArvore **AdicionaLista(tArvore **arv, tArvore *arvore, int qnt);

#endif