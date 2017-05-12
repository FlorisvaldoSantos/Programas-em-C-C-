

#include"includes.h"

void selection_sort(long *num, long tam) 
{ 
  long i, j, min;
 
	  for (i = 0; i < (tam-1); i++) 
	  {
			min = i;
			for (j = (i+1); j < tam; j++)
			{
			  if(num[j] < num[min])
			  {
				min = j;
			  }
			}
			if (i != min)
			{
			  long swap = num[i];
			  num[i] = num[min];
			  num[min] = swap;
			}
	  }
}