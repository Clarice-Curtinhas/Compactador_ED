/**
* Created by Clarice Curtinhas Santos on 10/7/25
* Copyright © 2025 Clarice Curtinhas Santos, Ana Luisa Casotti de Andrade. All rights reserved.
*/

#ifndef ARVORE_H
#define ARVORE_H

typedef struct Arvore tArvore;

/*
 * Cria uma árvore nova com dois galhos NULLs
 * Inputs: a informação do nó e os galhos NULLs
 * Outputs: um tipo "tArvore" alocado e inicializado
 * Pre-condicao: info diferente de NULL
 * Pos-condicao: um tipo "tArvore" alocado e com os campos preenchidos
*/
tArvore *CriaFolhas(unsigned char caracter);

/*
 * Cria uma árvore nova com dois galhos
 * Inputs: a informação do nó, o que ficará no galho a esquerda e a direita do nó
 * Outputs: um tipo "tArvore" alocado e inicializado
 * Pre-condicao: os galhos da esquerda e da direita da arvore
 * Pos-condicao: um tipo "tArvore" alocado e com os campos preenchidos
*/
tArvore *CriaGalhos(tArvore *esq, tArvore *dir);

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
unsigned char RetornaCaracter(tArvore *arv);

/*
 * Cria uma versão compactada da arvore
 * Inputs: Um tipo "tArvore", um unsigned char para guardar a arvore, e um ponteiro para a posição do buffer escrita pela última vez
 * Outputs: um unsigned char com as informações da árvore
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
unsigned char* ArvoreCompactada(tArvore *arv, unsigned char *buffer, int *tam);

/*
 * Imprime uma arvore
 * Inputs: Um tipo "tArvore"
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
void ImprimeArvore(tArvore *arv);

/*
 * Desaloca uma arvore
 * Inputs: Um tipo "tArvore"
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
void DesalocaArvore(tArvore *arv);

/*
 * Escreve o código Huffman criado
 * Inputs: Um tipo "tArvore" com o código Huffman, string com o texto e o tam do texto
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
void EscreveCodigoHuffman(tArvore *arv, unsigned char *text, int tam);

/*
 * Encontra caracter e escreve seu código
 * Inputs: Um tipo "tArvore" e um caracter a ser encontrado
 * Outputs: nenhum
 * Pre-condicao: nenhuma 
 * Pos-condicao: nenhuma
*/
int EncontraCaracter(tArvore *arv, unsigned char carac, unsigned char *codigoHuffman, int tamCodigo);

#endif