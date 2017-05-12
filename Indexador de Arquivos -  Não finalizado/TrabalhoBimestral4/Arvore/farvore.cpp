#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "farvore.h"
void insereNo(estruturaArvore * AVL, int valor)
{
	estruturaNo *novoNo = alocanovoNo(valor);
	estruturaNo *p;
	estruturaNo *q;
	p = AVL->raiz;
	q = AVL->raiz;
	if(AVL->raiz == NULL)
		AVL->raiz = novoNo;
	else
	{
		while(p!=NULL)
		{
			q=p;
			if (valor >= p->dado)
				p=p->direita;
			else
				p=p->esquerda;
		}
		if (valor>=q->dado)
		{
			q->direita=novoNo;
			printf("Inseriu a direita de %d \n", q->dado);
		}
		else
		{
			q->esquerda = novoNo;
			printf("Inseriu a esquerda de %d \n", q->dado);
		}
	}
	calcula_FB(AVL->raiz);
	Verifica(AVL->raiz,AVL);
	printf("A raiz Atual e %d \n", AVL->raiz->dado);
}	
void imprimePre(estruturaNo *No)
{
	if((No != NULL))
	{
		printf(" %d,",No->dado);
		imprimePre(No->esquerda);
		imprimePre(No->direita);
	}
}
void imprimeIn(estruturaNo *No)
{
	if((No != NULL))
	{
		imprimeIn(No->esquerda);
		printf(" %d, ",No->dado);
		imprimeIn(No->direita);
	}
}
void imprimePos(estruturaNo *No)
{
	if((No != NULL))
	{
		imprimePos(No->esquerda);
		imprimePos(No->direita);
		printf(" %d, ",No->dado);
	}
}
bool existeElemento(estruturaArvore *AVL, int elemento)
{
	estruturaNo *p;
	estruturaNo *q;
	p = AVL->raiz;
	q = AVL->raiz;
	int b=0;
	if(AVL->raiz)
	{
		printf("Arvore Vazia.");
		return false;
	}
	else
	{
		while(b != 1)
		{
			q=p;
			if(elemento>=p->dado)
				p=p->direita;
			else
				p=p->esquerda;
			if(p==NULL)
				b = 1;
			if(q->dado == elemento)
				b = 1;
		}
		if(q->dado == elemento)
			return true;
		else 
			return false;
	}
}
void remove(estruturaArvore *AVL, int elemento)
{
	estruturaNo *AUX1;// antecessor
	estruturaNo *AUX2;// será removido
	estruturaNo *AUX3;// esquerda do AUX2
	estruturaNo *AUX4;// direita do AUX2
	estruturaNo *AUX5;// SERA TROCADO COM AUX2 NA ULTIMA CONDIÇÃO
	estruturaNo *AUX6;// ANTERIOR DO AUX2
	AUX1 = AVL->raiz;
	AUX2 = AVL->raiz;
	AUX3 = AUX4 = AUX5 = AUX6 = NULL;
	if(existeElemento(AVL, elemento))
	{
		while(AUX2->dado != elemento)
		{
			AUX1 = AUX2;
			if(AUX2->dado < elemento)
				AUX2 = AUX2->direita;
			else
				AUX2 = AUX2->esquerda;
		}
		if(AUX2->direita == NULL && AUX2->esquerda == NULL)// remove se for folha
		{
			if(elemento > AUX1->dado)
				AUX1->direita = NULL;
			else
				AUX1->esquerda = NULL;
			printf("Removeu Folha.");
			if(AVL->raiz == AUX2)// if caso o elemento é raiz
			{
				AVL->raiz =  NULL;
				printf("Removeu Raiz. Arvore Vazia.");
			}
		}
		else if(AUX2->direita == NULL || AUX2->esquerda == NULL)// remove se o nó tiver só um filho
		{
			if(AVL->raiz == AUX2)// if caso elemento é raiz
			{
				if(AUX2->esquerda == NULL)
					AVL->raiz = AUX2->direita;
				else
					AVL->raiz = AUX2->esquerda;
			}
			else if(elemento > AUX1->dado)
			{
				if(AUX2->esquerda == NULL)
					AUX1->direita = AUX2->direita;
				else
					AUX1->direita = AUX2->esquerda;
			}
			else
			{
				if(AUX2->esquerda == NULL)
					AUX1->esquerda = AUX2->direita;
				else
					AUX1->esquerda = AUX2->esquerda;
			}
			printf("Removeu No com 1 Filho.");
		}
		else// remove se o nó tiver dois filhos
		{
			AUX3 = AUX2->esquerda;
			AUX4 = AUX2->direita;
			if(elemento > AUX1->dado)
			{
				if(AUX4->esquerda == NULL)
				{
					AUX1->direita = AUX4;
					AUX4->esquerda = AUX3;
				}
				else
				{
					AUX5 = AUX2;
					AUX6 = AUX4;
					AUX2 = AUX4->esquerda;
					while(AUX2->esquerda != NULL)
					{
						AUX6 = AUX2;
						AUX2 = AUX2->esquerda;	
					}
					if(AUX2->direita != NULL)
						AUX6->esquerda = AUX2->direita;
					else
						AUX6->esquerda = NULL;
					AUX5->dado = AUX2->dado;
				}
			}
			else
			{
				if(AUX4->esquerda == NULL)
				{
					AUX1->esquerda = AUX4;
					AUX4->esquerda = AUX3;
					if(AUX2 == AVL->raiz)
						AVL->raiz = AUX4;
				}
				else
				{
					AUX5 = AUX2;
					AUX6 = AUX4;
					AUX2 = AUX4->esquerda;
					while(AUX2->esquerda != NULL)
					{
						AUX6 = AUX2;
						AUX2 = AUX2->esquerda;
					}
					if(AUX2->direita != NULL)
						AUX6->esquerda = AUX2->direita;
					else
						AUX6->esquerda = NULL;
					AUX5->dado = AUX2->dado;
				}
			}
			free(AUX2);
			printf("Removeu No com 2 Filhos.");
		}
	}
	if(AVL->raiz != NULL)
		printf("Raiz %d",AVL->raiz->dado);	
	calcula_FB(AVL->raiz);
	Verifica(AVL->raiz,AVL);
}
int verificaaltura(estruturaNo *No) 
{
	int alturae;
	int alturad;
	if (No == NULL) 
      return -1; // altura de árvore vazia é -1
   else 
   {
		alturae = verificaaltura(No->esquerda);
		alturad = verificaaltura(No->direita);
		if (alturae < alturad) 
			return alturad + 1;
		else 
			return alturae + 1;
   }
}