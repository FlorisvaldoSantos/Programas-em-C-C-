

#include "lista.h"
#include"includes.h"

Lista *crialista()
{	
	Lista *L = (Lista*)malloc(sizeof(Lista));
	
	L->primeiro = NULL;
	L->ultimo = NULL;

	return L;

}

NO *alocano(int dado)
{
	NO *n = (NO*)malloc(sizeof(NO));

	n->dado = dado;
	n->prox = NULL;

	return n;

}

bool insere_inicio(Lista *l, int dado)
{
	NO *p = alocano(dado);
	bool quit=false;

	if(l->primeiro == NULL)
	{
		l->primeiro = p;
		l->ultimo = p;
		quit = true;
	}
	else
	{
		p->prox = l->primeiro;
		l->primeiro = p;
		quit = true;
	}

	return quit;
}

bool insere_fim (Lista *l, int dado)
{
	NO *n , *p = l->primeiro;
	bool quit = false;

	if(l->primeiro == NULL)
	{
		insere_inicio(l,dado);
		quit = true;
	}
	else
	{
		while(p!=NULL){
			n = p;
			p=p->prox;
		}
		insere_depois(n, dado);
		quit = true;
	}

	return quit;
}

NO* insere_depois(NO *n, int dado)
{
	NO *p = alocano(dado);

	p->prox = n->prox ;
	n->prox = p;
	
	return p; 
}
bool insere_ordenado(Lista *l, int dado, HASH *hash)
{
	bool quit = false;

	if(l->primeiro == NULL)
	{
		insere_inicio(l,dado);
		quit = true;
	}
	else if(dado < l->primeiro->dado)
	{
		insere_inicio(l,dado);
		quit = true;
	}
	else if(dado < l->ultimo->dado)
	{
		insere_fim(l,dado);
		quit = true;
	}
	else
	{
		NO *n,*p = l->primeiro;
		while( p!=NULL)
		{
			if(p->dado > dado)
			{
				break;
			}
			n = p;
			p=p->prox;
		}
		insere_depois(n,dado);
		hash->Colisao++;
		quit = true;
	}

	return quit;
}

int remove_inicio(Lista *l)
{
	int aux;

	if(vazia(l))
	{
		aux = -1 ;
	}
	else
	{
		NO *p = l->primeiro;
		aux =l->primeiro->dado;
		l->primeiro = l->primeiro->prox;
		free(p);
	}	
	
	return aux;
}

int remove_fim(Lista *l)
{
	int aux = 0;

	if(vazia(l))
	{
		aux = -1;//error
	}
	else{
		NO *n ,*p = l->primeiro;
		

		while( p->prox != NULL )
		{
			n=p;
			p = p->prox;
		}
		aux = p->dado;
		remove_depois(n);
		l->ultimo = n;
		free(p);
	}
	return aux;
}

void remove_depois(NO *n)
{
	NO *p;

	p = n->prox;
	n->prox = p->prox;  
	p->prox = n;
	
}

void mostra_lista(Lista *l)
{
	if(vazia(l))
	{
		printf("Lista esta vazia.\n");
	}
	else{
		NO *p = l->primeiro;
		while(p != NULL)
		{
			printf(" - %d", p->dado);
			p = p->prox;
		}
		puts("");
	}

}

bool vazia(Lista *l)
{
	bool quit = false;

	if(l->primeiro == NULL )
	{	
		quit= true;
	}

	return quit;
}

void libera(Lista *l)
{
	NO *n,*p = l->primeiro;
	
	while(p != NULL)
	{	
		n = p;
		remove_depois(n);
		p = p->prox;
		
	}
	
	free(p);
	free(l);
}





