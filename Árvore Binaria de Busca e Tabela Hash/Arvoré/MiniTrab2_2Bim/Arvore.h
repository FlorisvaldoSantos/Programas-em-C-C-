#ifndef _NOavl_
#define _NOavl_

#include"includes.h"


typedef struct NOavl
{

	int VALOR;
	NOavl *esqueda, *direita;
	
};

typedef struct Avl
{
	NOavl *raiz;
};

Avl *alocaAvl();
NOavl *AlocaNoAvl(long int dado);
long int  *alocavet(long int tam);
int busca_elemento(NOavl *a,long  int dado);
void insere_arvore(NOavl **raiz, long int dado);
float insere_arvore(long int  tam, long int *vetor, NOavl **n);
void preordem(NOavl  *r, int *p);


#endif 