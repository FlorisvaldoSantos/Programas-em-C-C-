
#include"function.h"

MAT *alocaMatriz(int Linhas)
{
	
	MAT *mat = (MAT*)malloc(sizeof(MAT));
	
	mat->vet = (Lista**)malloc(Linhas * sizeof(Lista*));

	for(int i=0; i < Linhas; i++)
	{	
		mat->vet[i] = (Lista*)malloc(sizeof(Lista));
		mat->vet[i]->primeiro = NULL;
		mat->vet[i]->ultimo = NULL;
	}

	mat->tam = Linhas;
	
	return mat;
}	

int returnvalor(MAT *M, int i, int j)
{
	int quit = 0;
	NO *n;

	if(M->tam < i || vazia(M->vet[i]))
	{
		quit = 0;
	}
	else
	{	
		n = M->vet[i]->primeiro;
		while(j != n->indice)
		{
			n = n->prox;
		}
		quit = n->dado;
	}
	return quit;
}

bool setaValor(MAT *M,int i,int j,int Valor)
{
	bool quit;
	
	if(i > M->tam)
	{
		quit =  false;
	}
	else{
			if(M->vet[i]->primeiro == NULL)
			{
				insere_inicio(M->vet[i],Valor, j);
				quit = true;
			}
			else if(j < M->vet[i]->primeiro->indice)
			{
				insere_inicio(M->vet[i], Valor, j);
				quit = true;
			}
			else if(j > M->vet[i]->ultimo->indice)
			{
				insere_fim(M->vet[i],Valor, j);
				quit = true;
			}
			else
			{
				NO *p = M->vet[i]->primeiro;
				while( p->indice > j)
				{
					p = p->prox;
				}
				insere_depois(p,Valor,j);
				quit = true;
			}
	}
	return quit;
	
}

bool setaNulo(MAT *M,int i,int j)
{
	bool quit;
	NO *n ;

	if(M->tam < i)
	{
		 quit =false;
	}
	else 
	{
		if(j == M->vet[i]->primeiro->indice)
		{
			remove_inicio(M->vet[i]);
			quit = true;
		}
		else
		{
			n = M->vet[i]->primeiro;
		
			while(n->indice != j)
			{
				n = n->prox;
			}
			remove_depois(n);
			quit = true;
		}
	}
		
	return quit;
}

void imprimeMatriz(MAT *M)
{
	int valcoluna = pega_maior_indice(M);
	
	printf("       ");
	for(int i =0; i <= valcoluna ;i++)
	{
		printf(" %3d",i);
	}
	printf("\n");

	for ( int i = 0; i < M->tam; i ++)
	{
		NO *p = M->vet[i]->primeiro;
		printf("\n   %3d ", i);
		
		int indice = -1, zero = 0;
		if(p != NULL) 
			indice = p->indice;
		while (zero <= valcoluna)
		{
			if(p != NULL) 
				indice = p->indice;

			if (zero != indice)
				printf("%4d", 0);
			else
			{
				printf("%4d", p->dado);
				p = p->prox;
			}	
			zero++;
		}
		printf("\n");
	}
}

int contaValores(MAT *M)
{
	int quit = 0;

	NO *p;

	for(int i = 0; i< M->tam ; i++)
	{
		p = M->vet[i]->primeiro;


		while( p != NULL)
		{
			quit++;
			p = p->prox;

		}

	}

	return quit;
}

int pega_maior_indice(MAT *M)
{
	int quit = 0, i;
	NO *p; 

	for(i = 0; i < M->tam; i++){

		p = M->vet[i]->primeiro;

		while(p != NULL)
		{
			if(p->indice >0 && p->indice > quit){
				quit = p->indice;
				}
			p = p->prox;
		
		}

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

void menu()
{
	printf("\t 1. Seta Valor\n");
	printf("\t 2. Seta Nulo\n");
	printf("\t 3. Mostra\n");
	printf("\t 4. Retorna valor ex:( 0, 0)\n");
	printf("\t 5. Conta valores.\n");
	printf("\t 6. Sair");

}