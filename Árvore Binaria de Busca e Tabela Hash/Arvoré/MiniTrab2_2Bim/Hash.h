#ifndef _estrutura_
#define _estrutura_

#include"includes.h"

typedef struct NO 
{
	long  int dado;
	NO *prox;
	
};

typedef struct Lista
{
	NO *primeiro;
	NO *ultimo;

};


typedef struct HASH
{
	long int tam_vetorHash, Colisao;
	Lista **vetlistas;
};

HASH *alocahash(long int tam);
bool posiciona_hash(HASH *hash,long  int dado);
float insere_hash_1(HASH *hash, long int *vetor,long int range);
bool pesquisa_hash(HASH *hash,long  int tam);
void montra_hash(HASH *hash);


#endif