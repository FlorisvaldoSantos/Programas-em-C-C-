#pragma once
#include<stdlib.h>
#include<stdio.h>
#include"Lista.h"


Lista *alocaL(){
	Lista *l;
	l=(Lista*)malloc(sizeof(Lista));
	l->primeiro=NULL;
	l->ultimo=NULL;
	l->total=0;
	return l;
}



int vazia(Lista *l){
	if(l->primeiro == NULL)
		return 1;
	else return 0;
}

void insere_primeiro(Lista *l, char dado,float freq,No *dir,No *esq){
	No *node;
	node=alocaNO(dado,freq,dir,esq);
	if(vazia(l)){
		l->primeiro=node;
		l->ultimo=node;
	}else{
		node->prox=l->primeiro;
		l->primeiro=node;

	}

}  
void insere_depois(Lista *l,No *n, char dado,float freq,No *dir,No *esq){
	if(vazia(l))
		insere_primeiro(l,dado,freq,dir,esq);
	else if(n==l->ultimo)
		insere_ultimo(l,dado,freq,dir,esq);
	No *node;
	node=alocaNO(dado,freq,dir,esq);
	node->prox=n->prox;
	n->prox = node;
	

}
void insere_ultimo(Lista *l, char dado,float freq,No *dir,No *esq){
	No *n;
	n=alocaNO(dado,freq,dir,esq);
	if(l->primeiro==NULL)
		insere_primeiro(l,dado,freq,dir,esq);
	else{
		l->ultimo->prox=n;
		l->ultimo=n;
		n->prox=NULL;

	}

}
void insere_ordenado(Lista *l, char dado,float freq,No *esq,No *dir){
	No *node;
	node=alocaNO(dado,freq,dir,esq);	

	if(l->primeiro==NULL)
		insere_primeiro(l,dado,freq,node->esquerda,node->direita);
	else if(node->freq < l->primeiro->freq)
		insere_primeiro(l,dado,freq,node->esquerda,node->direita);
	else if(node->freq > l->ultimo->freq)
		insere_ultimo(l,dado,freq,node->direita,node->esquerda);
	else{ 
		No *p;
		p=l->primeiro;
		while(p->prox->freq < freq){
			p=p->prox;
		}
		insere_depois(l,p,dado,freq,node->direita,node->esquerda);
	}

}

void mostra_lista(Lista *l){
	No *node = l->primeiro;
	while(node!=NULL){
		//imprime
		printf("Elemento:%c Frequencia:%f Codigo:%d \n\n",node->caracter,node->freq,node->codigo);
		node=node->prox;
	}
}
No *retira_primeiro(Lista *l){
	if(vazia(l))
		return 0;
	//else if(l->primeiro==l->ultimo){
	//	l->primeiro=NULL;
	//	l->ultimo=NULL;
	//}

	//else{
		No *aux=l->primeiro;
		l->primeiro=l->primeiro->prox;
		//char dado = aux->caracter;
		//free(aux);
		return aux;
	//}


}
void esvazia_lista(Lista *l){
	while(!vazia(l)){
		retira_primeiro(l);
	}
}
char retira_ultimo(Lista *l){
	char dado;
	if(vazia(l))
		return 0;
	else if(l->primeiro==l->ultimo)
		retira_primeiro(l);
	else{
		No *anterior = l->primeiro,*atual;
		atual= l->primeiro;
		while(atual!=l->ultimo){
			anterior=atual;
			atual=atual->prox;
			//No fim do while,anterior se torna o penultimo elemento
	}
		dado = anterior->caracter;
		l->ultimo = anterior;
		l->ultimo->prox = NULL;
		return dado;		
	}
}

char retira_depois(Lista *l,No *node){
	if(vazia(l))
		return 0;
	else if(l->primeiro==l->ultimo)
		retira_primeiro(l);
	else{
		char aux;
		aux=node->caracter;
		node->prox=node->prox->prox;
		return aux;
		

	}
}


char ultimo_elemento(Lista *l){
	return l->ultimo->caracter;
}

int buscaElemento(Lista *l,char elem){
	int freq=0;
	No *aux =l->primeiro;
	while(aux!=NULL){
		if(aux->caracter==elem){
			return 1;
		}
		aux=aux->prox;
	}
	return 0;
}


Lista *ordena_lista(Lista *l){
	No *aux = retira_primeiro(l);
	
	Lista *p=alocaL();
	p->total=l->total;
	while(aux !=NULL){
		
		insere_ordenado(p,aux->caracter,aux->freq,aux->esquerda,aux->direita);
		aux=retira_primeiro(l);
	}
	
	return p;
}


void emOrdem(No *n){
 if(n!=NULL){
   emOrdem(n->esquerda);
   printf("%c ",n->codigo);
   emOrdem(n->direita);
 }
}


