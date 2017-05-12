
#include"ListaDupEncad.h"
	

Lista *crialista()
{	
	Lista *L = (Lista*)malloc(sizeof(Lista));
	
	L->ultimo = NULL;

	return L;

}

NO *alocano(int dado)
{
	NO *n = (NO*)malloc(sizeof(NO));

	n->dado = dado;
	n->anterior = NULL;
	n->proximo = NULL;

	return n;

}

bool insere_primeiro(Lista *l, int dado)
{
	
	bool quit=false;

	if(l->ultimo == NULL)
	{
		NO *p = alocano(dado);
		l->ultimo = p; 
		p->proximo = p;
		p->anterior = p;
		quit = true;
	}
	else
	{
		insere_depois(l->ultimo,dado);
		quit = true;
	}

	return quit;
}

NO* insere_depois(NO *p, int dado)
{
	NO *n = alocano(dado);
		
	n->proximo = p->proximo;
	p->proximo->anterior = n;
	n->anterior = p;
	p->proximo = n;

	return n; 
}

bool insere_ultimo(Lista *l, int dado)
{
	bool quit = false;

	if(l->ultimo == NULL)
	{
		NO *p = alocano(dado);
		l->ultimo = p;
		p->proximo = p;
		p->anterior = p;
		quit = true;
	}
	else
	{
		l->ultimo = insere_depois(l->ultimo,dado);
		quit = true;
	}
	return quit;
}

bool insere_ordenado(Lista *l, int dado)
{
	bool quit = false, exit = true;
	
	if(vazia(l))
	{
		insere_primeiro(l,dado);
		quit = true;
	}
	else if(dado > l->ultimo->dado)
	{
		insere_primeiro(l,dado);
		quit = true;
	}
	else
	{
		NO *n,*p = l->ultimo->proximo;
		while( p!=l->ultimo && (p->dado < dado))
		{
			n=p;
			p=p->proximo;
		}
		insere_depois(n,dado);
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
	else if(l->ultimo == l->ultimo->proximo)
	{
		aux = l->ultimo->dado;
		l->ultimo = NULL;
	}
	else
	{
		aux =l->ultimo->proximo->dado;
		remove_depois(l->ultimo);
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
		NO *n ,*p = l->ultimo->proximo;
		
		while( p != l->ultimo )
		{
			n=p;
			p = p->proximo;
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

	n->proximo = n->proximo->proximo;
	n->proximo->proximo->anterior = n;
}



void mostra_lista(Lista *l)
{
	if(vazia(l))
	{
		printf("\n\n\tLista esta vazia.");
	}
	else{
		NO *p = l->ultimo->proximo;
		int i=0;
		while(p != l->ultimo)
		{
			printf(" -[%d]%d ",i, p->dado);
			p = p->proximo;
			i++;
		}
		printf(" - %d[Ultimo] ", p->dado);
	}

}

int ultimo_elemento(Lista *l)
{
	int aux;
	if(vazia(l))
	{
		aux = -1;
	}
	else
	{
		aux = l->ultimo->dado;
	}

	return aux;
}
void menu_lista()
{

	printf("\t 1.Insere Inicio\n");
	printf("\t 2.Insere Fim\n");
	printf("\t 3.Insere Ordenado\n");
	printf("\t 4.Mostra\n");
	printf("\t 5.Retira Inicio\n");
	printf("\t 6.Retira Fim\n");
	printf("\t 7.Ultimo elemento\n");
	printf("\t 8.Sair\n\n");

}
 
bool vazia(Lista *l)
{
	bool quit = false;

	if(l->ultimo == NULL )
	{	
		quit= true;
	}

	return quit;
}


void cabecalho()
{ 
	printf("--------------------------------------------------------------------------------");
	printf("\t\t\tTrabalho - Fabricio \n");
	printf("\t\t\tAluno: Florisvaldo Santos 2 ano.\n");
	printf("--------------------------------------------------------------------------------\n");
}

