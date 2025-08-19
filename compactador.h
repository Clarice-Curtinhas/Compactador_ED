/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#ifndef COMPACTADOR_H
#define COMPACTADOR_H

#define ASCII 256

#include "arvore.h"
//#include "lista.h"
#include "bitmap/bitmap.h"

/*
 * Lê um texto e codifica uma arvore de Huffman
 * Inputs: uma string com o texto que será codificado, matriz para inserir o código de cada caracter
 * Outputs: um tipo "tArvore" com a codificação das letras usadas
 * Pre-condicao: string diferente de NULL
 * Pos-condicao: tipo "tArvore" diferente de NULL
*/
//tArvore *Codifica(unsigned char *text, long tam);
tArvore *Codifica(unsigned char *text, unsigned char matriz_codigo[ASCII][ASCII], int tam);

/*
 * Codifica uma arvore de Huffman
 * Inputs: um vetor de "tArvore" com cada letra e sua frequência na string e a quantidade de caracteres diferentes no texto
 * Outputs: um tipo "tArvore" com a codificação das letras usadas
 * Pre-condicao: tipo "tArvore" diferente de NULL, qnt e total maior que 0
 * Pos-condicao: tipo "tArvore" diferente de NULL
*/
tArvore *CriaHuffman(tArvore **arv, int qnt);

/*
 * Ordena uma lista de árvores em ordem crescente de frequência usando Quick Sort
 * Inputs: vetor de árvores, quantidade de árvores no vetor
 * Outputs: nenhum
 * Pre-condicao: vetor diferente de NULL
 * Pos-condicao: vetor ordenado
*/
void OrdenaLista(tArvore **arv, int qnt);

/*
 * Retira duas arvores do vetor de "tArvore"
 * Inputs: um vetor de "tArvore", dois ids para serem retirados e o tamanho atual do vetor
 * Outputs: vetor do tipo "tArvore" sem as árvores de id1 e id2
 * Pre-condicao: tipo "tArvore" diferente de NULL, ids válidos (que estejam dentro do vetor) e qnt maior ou igual a 2
 * Pos-condicao: nenhum
*/
tArvore **RetiraLista(tArvore **arv, int id1, int id2, int qnt);

/*
 * Adiciona uma arvore no vetor de "tArvore"
 * Inputs: um vetor de "tArvore", um tipo "tArvore" para ser adicionado e o tamanho atual do vetor
 * Outputs: vetor do tipo "tArvore" com a árvore adicionada no final do vetor
 * Pre-condicao: tipo "tArvore" diferente de NULL para ser adicionado no final do vetor
 * Pos-condicao: o vetor "tArvore" differente de NULL
*/
tArvore **AdicionaLista(tArvore **arv, tArvore *arvore, int qnt);

/*
 * Escreve um texto com o código criado
 * Inputs: texto que será codificado, matirz de códigos, buffer em que o código será armazenado, tamanho do texto
 * Outputs: nenhum
 * Pre-condicao: string diferente de NULL e um "tArvore" diferente de NULL
 * Pos-condicao: nenhuma
*/
int EscreveTextoCodificado(unsigned char *text, unsigned char matriz[ASCII][ASCII], unsigned char **buffer_compactado, int tam_texto);

#endif