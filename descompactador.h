#ifndef DESCOMPACTADOR_H
#define DESCOMPACTADOR_H


#include "arvore.h"
#include "bitmap/bitmap.h"

/*
 * Um texto com a codificação da arvore
 * Inputs: um ponteiro para um unsigened char com a árvore que será decodificado e outro ponteiro para onde acessar o próximo caracter do unsigned char
 * Outputs: um tipo "tArvore" com a codificação das letras usadas
 * Pre-condicao: string diferente de NULL
 * Pos-condicao: tipo "tArvore" diferente de NULL
*/
tArvore *DecodificaArvore(unsigned char *arvore, int *tam);

/*
 * Escreve um texto com o código existente na arvore dentro do arquivo
 * Inputs: um buffer com o texto em binário que será escrito usando o código existente no "tArvore" e um ponteiro para um vetor onde o texto decodificado será armazenado
 * Outputs: nenhum
 * Pre-condicao: string diferente de NULL e um "tArvore" diferente de NULL
 * Pos-condicao: nenhuma
*/
int EscreveTextoDecodificado(unsigned char **buffer_descompactado, tArvore *arv, unsigned char *text, int tam);

#endif