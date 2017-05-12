#pragma once
#include<stdio.h>
#include<stdlib.h>



#include <string>
#include"No.h"

using namespace std;

No *alocaNO(char dado,float freq,No *direita,No *esquerda){
	No* node;
	
	node= new No;
		//(No*)malloc(sizeof(No));
	node->prox=NULL;
	node->direita=direita;
	node->esquerda=esquerda;
	node->caracter=dado;	
	node->freq=freq;
	node->qtd=NULL;
	//node->aux = "";
	node->codigo = "";
	return node;
}
