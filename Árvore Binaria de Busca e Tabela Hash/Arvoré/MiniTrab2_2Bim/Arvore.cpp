
#include"includes.h"

Avl *alocaAvl()
{
	Avl*p=(Avl*)malloc(sizeof(Avl));
	p->raiz=NULL;
	return p;
}

NOavl *AlocaNoAvl(long int dado)
{
	NOavl *p = (NOavl*)malloc(sizeof(NOavl)); 
		
	p->direita = NULL;
	p->esqueda = NULL;
	p->VALOR = dado;	
	return p;
}

long int  *alocavet(long int tam)
{
	long int  *vet = (long int *)malloc(tam * sizeof(long int ));
	
	if(vet == NULL)
		return 0;
	
	return vet;
}


int busca_elemento(NOavl *a,long  int dado)
{
	if(a == NULL)
		return 0;

	else if(a->VALOR > dado)
		return (busca_elemento(a->esqueda, dado));

	else if(a->VALOR < dado)
		return (busca_elemento(a->direita, dado));
	
	if(a->VALOR == dado)
	{	
		return 1;//elemento encontrado
	}
	else 
	{
		return 0;//elemento encontrado
	}
}



void insere_arvore(NOavl **raiz, long int dado)
{
	if(*raiz == NULL)
	{
		NOavl *p;
		p = AlocaNoAvl(dado);
		*raiz = p;
	}
	else if((*raiz)->VALOR > dado)
	{
		if((*raiz)->esqueda == NULL)
		{
			NOavl *p;
			p = AlocaNoAvl(dado);
			(*raiz)->esqueda = p;
		}
		else
		{
			insere_arvore(&(*raiz)->esqueda, dado);
		}
	}
	else
	{
		if((*raiz)->direita == NULL)
		{
			NOavl *p;
			p = AlocaNoAvl(dado);
			(*raiz)->direita = p;
		}
		else
		{
			insere_arvore(&(*raiz)->direita, dado);
		}
	}
}

float insere_arvore(long int  tam, long int *vetor, NOavl **n)
{
	long int dado; 
	float ret = 0;
	clock_t tempo_fim =0, temp_ini = clock();
	srand( time(NULL));
	for(long int i=0; i<tam;i++)
	{
		insere_arvore(n,vetor[i]);
	}
	tempo_fim =  clock();
	ret = (float)(tempo_fim - temp_ini)/CLOCKS_PER_SEC;
	return ret;
}


void preordem(NOavl  *r, int *p)
{
	if(r != NULL)
	{
		p++;
		preordem(r->esqueda, p);
		printf("\n %d", r->VALOR);
		preordem(r->direita, p);
	}
}