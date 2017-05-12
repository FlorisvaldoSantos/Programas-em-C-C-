
#include"Main.h"

Avl *alocaAvl()
{
	Avl*p=(Avl*)malloc(sizeof(Avl));
	p->raiz=NULL;
	return p;
}

NOavl *AlocaNoAvl(int dado)
{
	NOavl *p = (NOavl*)malloc(sizeof(NOavl)); 
		
	p->direita = NULL;
	p->esqueda = NULL;
	p->VALOR = dado;	
	return p;
}

long int  *alocavet(int tam)
{
	long int  *vet = (long int *)malloc(tam * sizeof(long int ));
	
	if(vet == NULL)
		return 0;
	
	return vet;
}

int altura(NOavl *a){
	
	if(a==NULL)
		return 0;
	else
	{
		int alturaEsq = altura(a->esqueda);
		int alturaDir = altura(a->direita);
		
		if(alturaDir > alturaEsq)
			return alturaEsq+1;
		else
			return alturaDir+1;
	}
}

int busca_elemento(NOavl *a, int dado)
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

NOavl *insere_arvore(NOavl *n,int dado)
{	
	if(n == NULL)
	{	
		NOavl *p = AlocaNoAvl(dado);
		return p;
	}
	else
	{
		if(dado > n->VALOR)
		{	
			n->direita = insere_arvore(n->direita,dado);
			return n;
		}
		else if(dado < n->VALOR)
		{	
			n->esqueda = insere_arvore(n->esqueda, dado);
			return n;
		}

	}
}
