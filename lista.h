#ifndef LISTA_H
#define LISTA_H

#include "arvore.h"

typedef struct celula tCelula;

typedef struct lista tLista;

/*
 * Cria uma nova lista, alocando memória para ela.
 * Inputs: nenhum
 * Outputs: um tipo "tLista" alocado. Primeira e última posições vazias
 */
tLista *CriaLista();

/*
 * Insere um novo elemento no final da lista.
 * Inputs: ponteiro para a lista onde será inserido o elemento
 * ponteiro para o elemento a ser inserido, tipo do elemento
 * Outputs: nenhum
 */
void InsereLista(tLista *lista, tArvore *arv);

/*
 * Procura um caracter dentro da lista.
 * Inputs: ponteiro para a lista onde o caracter vai ser perocurado 
 * e um char com o caracter que estamos procurando
 * Outputs: ponteiro para a celula onde o caracter se encontra
 */
tCelula *ProcuraLista(tLista *lista, unsigned char caracter);

/*
 * Retorna a arvore dentro da celula
 * Inputs: ponteiro para a celula onde a arvore está
 * Outputs: a arvore dentro da celula
 */
tArvore* RetornaArvore(tCelula *cel);

/*
 * Soma das frequências dentro da lista
 * Inputs: ponteiro para a lista em que serão somadas as frequências
 * Outputs: um int com a soma de todas as frequências da lista
 */
int FrequenciaLista(tLista *lista);

/*
 * Cria uma árvore com as informaçoes existentes na lista
 * Inputs: ponteiro para a lista onde se encontra as informações 
 * para criar a árvore binária
 * Outputs: árvore binária completa
 */
tArvore *CriaArvores(tLista *lista);

/*
 * Cria uma sublista de acordo com as primeira e última celulas dessas sublistas.
 * Inputs: ponteiro para duas celulas
 * Outputs: uma sublista que começa com a celula prim e termina com a celula ult
 */
tLista *RetornaSubLista(tCelula *prim, tCelula *ult);

/*
 * Ordena a lista de acordo com as frequencias de cada caracter das celulas.
 * Inputs: ponteiro para a lista que será ordenada, um int com a quantidade de letras
 * Outputs: nenhum
 */
void OrdenaLista(tLista *lista, int qnt);

/*
 * Retira uma celula de uma lista qunado sua árvore já foi agrupada.
 * Inputs: ponteiro para a lista onde a celula será retirada, um tipo celula que será retirada
 * Outputs: nenhum
 */
void RetiraLista(tLista *lista, tCelula *cel);

/*
 * Imprime uma lista.
 * Inputs: ponteiro para a lista que será impressa
 * Outputs: nenhum
 */
void ImprimeLista(tLista *lista);

/*
 * Libera a memória da lista completa.
 * Inputs: ponteiro para a lista que será liberada
 * Outputs: nenhum
 */
void LiberaLista(tLista *lista);

#endif