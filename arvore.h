/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#ifndef ARVORE_H
#define ARVORE_H

typedef struct Arvore tArvore;

/*
 * Cria uma árvore nova com dois galhos (que podem ou não ser igual a NULL)
 * Inputs: a informação do nó, o que ficará no galho a esquerda e a direita do nó
 * Outputs: um tipo "tArvore" alocado e inicializado
 * Pre-condicao: info diferente de NULL e os galhos que podem ou não ser NULL
 * Pos-condicao: um tipo "tArvore" alocado e com os campos preenchidos
*/
tArvore *CriaArvore(char caracter, tArvore *esq, tArvore *dir);

/*
 * Aumenta a frequencia em que o caracter aparece
 * Inputs: Um tipo "tArvore"
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
void AcrescimoDeCaracter(tArvore *arv);

/*
 * Retorna a frequencia em que o caracter aparece
 * Inputs: Um tipo "tArvore" do carcter coorrespondente
 * Outputs: Um tipo int com a quantidade de vezes que o caracter aparece
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
int RetornaFrequencia(tArvore *arv);

/*
 * Retorna a frequencia em que o caracter aparece
 * Inputs: Um tipo "tArvore" do carcter coorrespondente
 * Outputs: Um tipo caracter
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
char RetornaCaracter(tArvore *arv);

/*
 * Desaloca uma arvore
 * Inputs: Um tipo "tArvore"
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
void DesalocaArvore(tArvore *arv);

#endif