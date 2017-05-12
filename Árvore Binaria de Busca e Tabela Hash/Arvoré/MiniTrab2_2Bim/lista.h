#ifndef _lista_
#define _lista_


#include"includes.h"
#include"Hash.h"


Lista *crialista();
NO *alocano(int dado);
bool insere_inicio(Lista *l, int dado);
bool insere_fim (Lista *l, int dado);
NO* insere_depois(NO *n, int dado);
//bool insere_ordenado(Lista *l, int dado);
bool insere_ordenado(Lista *l, int dado, HASH *hash);
int remove_inicio(Lista *l);
int remove_fim(Lista *l);
void remove_depois(NO *n);
void mostra_lista(Lista *l);
bool vazia(Lista *l);
void libera(Lista *l);
void cabecalho();

#endif