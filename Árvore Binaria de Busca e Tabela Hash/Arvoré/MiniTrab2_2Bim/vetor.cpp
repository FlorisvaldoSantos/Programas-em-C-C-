
#include"includes.h"


long int *vetpesquisa(int tam)
{
	long int *vet = (long int*)malloc( tam * sizeof(long int));
	
	if(vet == NULL)
		return 0;
	
	return vet;
}

void preenche_vetpesq( long int *vet,long  int tam,long  int range)
{
	srand(time(NULL));
	long int dado=0;

	for(int i=0; i<tam;i++)
	{
		dado = (rand()%tam)*(rand()%tam);
		vet[i]= dado;
	}
}


