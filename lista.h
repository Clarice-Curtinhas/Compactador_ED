#ifndef LISTA_H
#define LISTA_H

typedef struct Celula tCelula;
typedef struct Lista tLista;

tLista* CriaLista();

void InsereLista(unsigned char *codigo, tLista *l);

void ImprimeCodigo(unsigned char *text, tLista *l, int tamCodigo);

void DesalocaLista(tLista *l);

#endif