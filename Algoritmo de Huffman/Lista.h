#include<stdio.h>
#include<stdlib.h>
#include"No.h"

typedef struct {
	No *primeiro;
	No *ultimo;
	int total;

}Lista;

Lista *alocaL();

int vazia(Lista *l);
void esvazia_lista(Lista *l);
void insere_primeiro(Lista *l, char dado,float freq,No *esq,No *dir); 
void insere_depois(Lista *l,No *n, char dado,float freq,No *esq,No *dir);
void insere_ultimo(Lista *l, char dado,float freq,No *esq,No *dir);
void insere_ordenado(Lista *l, char dado,float freq,No *esq,No *dir);
void mostra_lista(Lista *l);
No *retira_primeiro(Lista *l);
char retira_ultimo(Lista *p);
char retira_depois(Lista *l,No *n);
char ultimo_elemento(Lista *p);
int buscaElemento(Lista *l,char elem);
Lista *ordena_lista(Lista *l);
void emOrdem(No *n);
