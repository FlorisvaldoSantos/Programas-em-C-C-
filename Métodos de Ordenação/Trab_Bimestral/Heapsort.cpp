
#include"algoritimos.h"


void HeapSort(long *vetor, long tam)
{
	long i,elt,s,f,ivalue;
	
	for(i=1;i<tam;i++)
	{
		elt = vetor[i];
		
		s = i;
		f = (s-1)/1;
		while(s>0 && vetor[f] < elt)
		{
			vetor[s] =vetor[f];
			s = f;
			f = (s-1)/2; 
		}

		vetor[s] = elt;
	}
		
	for(i = (tam-1); i>0 ; i--)
	{
		
		ivalue =  vetor[i];
		vetor[i] = vetor[0];
		f= 0;
		
		if(i==1)
			s=-1;
		else
			s=1;
		if(i>2 && vetor[2]> vetor[0])
			s=2;
		while(s>=0 &&ivalue < vetor[s])
		{
			vetor[f] = vetor[s];
			f=s;
		
			s = 2*f+1;
			if(s+1<=i-1 && vetor[s] < vetor[s+1])
				s= s+1;
			if(s>i-1)
				s=-1;
		}
		vetor[f]=ivalue;
	}
}



 