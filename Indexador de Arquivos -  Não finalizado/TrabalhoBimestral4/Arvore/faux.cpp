#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "farvore.h"
estruturaArvore* criaArvore()
{
	estruturaArvore *novaAVL = (estruturaArvore*)malloc(sizeof(estruturaArvore));
	novaAVL->raiz = NULL;
	return novaAVL;
}
estruturaNo* alocanovoNo(int info)
{
	estruturaNo *novoNo = (estruturaNo*)malloc(sizeof(estruturaNo));
	novoNo->dado = info;
	novoNo->direita = NULL;
	novoNo->esquerda = NULL;
	return novoNo;
}
int calcula_FB(estruturaNo *No)
{
	int alturae;
	int alturad;
	if (No == NULL) 
      return -1; // altura de árvore vazia é -0
   else 
   {
		alturae = calcula_FB(No->esquerda);
		alturad = calcula_FB(No->direita);
		if (alturae < alturad) 
		{
			No->fb = alturae - alturad;
			return alturad + 1;
		}
		else 
		{
			No->fb = alturae - alturad;
			return alturae + 1;
		}
	}
}
void rotaciona_esquerda(estruturaNo *p, estruturaArvore *AVL)
{
	printf("rotacionar  %d ",p->dado);
	estruturaNo *q; 
	estruturaNo *aux;
	q = p->direita;
	aux = q->esquerda;
	q->esquerda = p;
	p->direita =aux;
	if(AVL->raiz == p)
		AVL->raiz = q;
	else
	{
		estruturaNo *aux = PegaAntecessor(AVL, p);
		if(aux->esquerda == p)
			aux->esquerda = q;
		else
			aux->direita = q;
	}
}
void rotaciona_direita(estruturaNo *p, estruturaArvore *AVL)
{
	printf("rotacionar  %d ",p->dado); 
	estruturaNo *q; 
	estruturaNo *aux;
	q = p->esquerda;
	aux = q->direita;
	q->direita = p;
	p->esquerda =aux;
	if(AVL->raiz == p)
		AVL->raiz = q;
	else
	{
		estruturaNo *aux = PegaAntecessor(AVL, p);
		if(aux->direita == p)
			aux->direita = q;
		else
			aux->esquerda = q;
	}
}
void Verifica( estruturaNo *aux, estruturaArvore *AVL )
{
	if( aux != NULL )
	{
		Verifica(aux->esquerda,AVL);
		Verifica(aux->direita,AVL);
		estruturaNo *ArvoreEsquerda = aux->esquerda;
		estruturaNo *ArvoreDireita = aux->direita;
		int x = 0;
		if( ArvoreEsquerda != NULL )
		{
			if( (aux->fb == 2 ) && ( ArvoreEsquerda->fb == -1 ) )
			{
				rotaciona_esquerda(ArvoreEsquerda,AVL);
				rotaciona_direita(aux,AVL);
				x=1;
				calcula_FB( AVL->raiz);
			}
			if( (aux->fb == -2 ) && ( ArvoreEsquerda->fb == 1 ) )
			{
				rotaciona_direita(ArvoreEsquerda,AVL);
				rotaciona_esquerda(aux,AVL);
				x=1;
				calcula_FB( AVL->raiz);
			}
		}
		if( ArvoreDireita != NULL )
		{
			
			if( (aux->fb == 2 ) && ( ArvoreDireita->fb == -1 ) )
			{
				rotaciona_esquerda(ArvoreDireita,AVL);
				rotaciona_direita(aux,AVL);
				x=1;
				calcula_FB( AVL->raiz);
			}
			if( (aux->fb == -2 ) && ( ArvoreDireita->fb == 1 ) )
			{
				rotaciona_direita(ArvoreDireita,AVL);
				rotaciona_esquerda(aux,AVL);
				x=1;
				calcula_FB( AVL->raiz);
			}
		}
		if( x == 0 )
		{
			if( aux->fb == -2)
			{
				rotaciona_esquerda(aux,AVL);
				calcula_FB( AVL->raiz);
			}
			else if ( aux->fb == 2 )
			{
				rotaciona_direita(aux,AVL);
				calcula_FB( AVL->raiz);
			}
		}
	}
}
estruturaNo* PegaAntecessor(estruturaArvore *AVL, estruturaNo *No)
{
	estruturaNo *aux = AVL->raiz;
	estruturaNo *aux2;
	while(aux->dado != No->dado)
	{
		aux2 = aux;
		if(aux->dado > No->dado)
		{
			aux = aux->esquerda;
		}
		else
			aux = aux->direita;
	}
	return aux2;
}