#ifndef _LISTA_
#define _LISTA_

#include"no.h"

typedef struct Lista
{
	NO *primeiro;
	NO *ultimo;
};

//Aloca o NO da Lista
NO *alocano(int dado, int indice);

// INsere no inicio da lista
bool insere_inicio(Lista *l, int dado, int indice);

// INsere no fim da Lista 
bool insere_fim (Lista *l, int dado,  int indice);

// Insere depois do No desejado
NO* insere_depois(NO *n, int dado, int indice);

// Insere o valor ordenadamente
bool insere_ordenado(Lista *l, int dado);

// Remove do inico da lista 
int remove_inicio(Lista *l);

//Remove do Final da Lista 
int remove_fim(Lista *l);

// Remove depois no No
void remove_depois(NO *n);

//Verifica se a Lista está vazia 
bool vazia(Lista *l);

//Libera a memoria da matriz
void libera(Lista *l);


#endif