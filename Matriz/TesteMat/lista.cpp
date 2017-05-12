#include"function.h"

NO *alocano(int dado, int indice)
{
	NO *n = (NO*)malloc(sizeof(NO));

	n->dado = dado;
	n->indice = indice;
	n->prox = NULL;

	return n;

}

bool insere_inicio(Lista *l, int dado, int indice)
{
	NO *p = alocano(dado, indice);
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

bool insere_fim (Lista *l, int dado, int indice)
{
	bool quit = false;

	if(l->primeiro == NULL)
	{
		insere_inicio(l, dado, indice);
		quit = true;
	}
	else
	{
		NO *n, *p = l->primeiro;
		while(p!=NULL){
			n = p;
			p = p->prox;
		}
		insere_depois(n, dado, indice);
		quit = true;
	}

	return quit;
}

NO* insere_depois(NO *n, int dado, int indice)
{
	NO *p = alocano(dado, indice);

	p->prox = n->prox ;
	n->prox = p;
	
	return p; 
}

bool insere_ordenado(Lista *l, int dado, int indice)
{
	bool quit = false;

	if(l->primeiro == NULL)
	{
		insere_inicio(l,dado, indice);
		quit = true;
	}
	else if(indice < l->primeiro->indice)
	{
		insere_inicio(l, dado, indice);
		quit = true;
	}
	else if(indice < l->ultimo->indice)
	{
		insere_fim(l,dado,indice);
		quit = true;
	}
	else
	{
		NO *n,*p = l->primeiro;
		while( p!=NULL)
		{
			if(p->indice > indice)
			{
				n = p;
				p=p->prox;
			}
		}
		insere_depois(n,dado, indice);
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



