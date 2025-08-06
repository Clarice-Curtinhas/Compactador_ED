/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#ifndef COMPACTADOR_H
#define COMPACTADOR_H

#include "arvore.h"
#include "lista.h"
#include "bitmap/bitmap.h"

/*
 * Lê um texto e codifica uma arvore de Huffman
 * Inputs: uma string com o texto que será codificado
 * Outputs: um tipo "tArvore" com a codificação das letras usadas
 * Pre-condicao: string diferente de NULL
 * Pos-condicao: tipo "tArvore" diferente de NULL
*/
tArvore *Codifica(char *text);

/*
 * Codifica uma arvore de Huffman
 * Inputs: um vetor de "tArvore" com cada letra e sua frequência na string e a quantidade de caracteres diferentes no texto
 * Outputs: um tipo "tArvore" com a codificação das letras usadas
 * Pre-condicao: tipo "tArvore" diferente de NULL, qnt e total maior que 0
 * Pos-condicao: tipo "tArvore" diferente de NULL
*/
tArvore *CriaHuffman(tLista *lista, int qnt);

/*
 * Escreve um texto com o código criado
 * Inputs: uma string com o texto que será escrito usando o código existente no "tArvore" e um ponteiro para o buffer em que o código será armazenado
 * Outputs: nenhum
 * Pre-condicao: string diferente de NULL e um "tArvore" diferente de NULL
 * Pos-condicao: nenhuma
*/
int EscreveTextoCodificado(char *text, tArvore *arv, unsigned char **buffer_compactado);

#endif