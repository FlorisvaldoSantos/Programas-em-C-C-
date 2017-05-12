#ifndef _MAIN_
#define _MAIN_


#include"NOavl.h"
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
   


Avl *alocaAvl();
NOavl *AlocaNoAvl(int dado);
NOavl *insere_arvore(NOavl *n,int dado);
NOavl *insere_arvore(int  tam, NOavl *n,float &temparvore);
int altura(NOavl *a);
long int  *alocavet(int tam);
int busca_elemento(NOavl *a, int dado);
//float insere_arvore(int  tam, NOavl *n);
float insere_vetor(long int *vetor, long int tam);
void quicksort(long int *vetor, int inicio, int fim);
void cabecalho();

#endif 