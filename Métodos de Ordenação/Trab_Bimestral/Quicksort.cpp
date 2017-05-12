
#include"includes.h"


void quicksort(long int *vetor, int inicio, int fim)
{
	 long  pivo, aux, i, j, meio;

	i = inicio;
	j = fim;

	meio = (i + j) / 2 ;
	pivo = vetor[meio];

	do
	{
		while (vetor[ i ] < pivo) i = i + 1;
		while (vetor[j] > pivo) j = j - 1;
      
		if(i <= j)
		{
			aux = vetor[ i ];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i = i + 1;
			j = j - 1;
		}
   } while(j > i);

   if(inicio < j) quicksort(vetor, inicio, j);
   if(i < fim) quicksort(vetor, i, fim);
}

