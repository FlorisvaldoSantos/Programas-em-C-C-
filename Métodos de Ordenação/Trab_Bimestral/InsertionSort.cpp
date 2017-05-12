
#include"includes.h"


void insertsort(long *vetor, long tam)
{
		long i, k, y;

		for(k=1;k< tam;k++)
		{
			y = vetor[k];

			for(i = k-1; i>= 0 && y< vetor[i];i--)
			{
				vetor[i+1] = vetor[i];
			}
			vetor[i+1]=y;
		}
}
