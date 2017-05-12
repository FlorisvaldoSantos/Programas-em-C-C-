
#include"includes.h"

void shellSort(long *vet, long size)
{  
    long i , j , value;
    long gap = 1;
    do {
        gap = 3*gap+1;
    } while(gap < size);
    do {
        gap /= 3;
        for(i = gap; i < size; i++) {
            value =vet[i];
            j = i - gap;
            while (j >= 0 && value < vet[j]) {
                vet [j + gap] =vet[j];
                j -= gap;
            }
            vet [j + gap] = value;
        }
    } while ( gap > 1);
}

