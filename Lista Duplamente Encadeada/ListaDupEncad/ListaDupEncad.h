#ifndef _ListaDupla_
#define _ListaDupla_

#include"NO.h"
#include"Lista.h"
#include<stdlib.h>
#include<stdio.h>


// Verifica se a lista L est� vazia
bool vazia(Lista *l); 
// Insere o elemento info como primeiro na lista L
bool insere_primeiro(Lista *l, int dado);  
// Insere o elemento info depois do n� No
NO *insere_depois(NO *p, int dado);  
// Insere o elemento info como �ltimo na lista L
bool insere_ultimo(Lista *l, int dado);	
// Insere o elemento info de maneira ordenada na lista
bool insere_ordenado(Lista *l, int dado);
// Mostra em Tela os Elementos da Lista L
void mostra_lista(Lista *l);	
// Retira o primeiro elemento da Lista e retorna o valor da info do No
int remove_inicio(Lista *l); 
// Retira o �ltimo elemento da Lista e retorna a informa��o do N�
int remove_fim(Lista *l); 	
// Retira o elemento posterior ao n� No e retorna a sua informa��o
void remove_depois(NO *n);	
// Retorna a informa��o do �ltimo elemento da Lista
int ultimo_elemento(Lista *l); 	
//cabe�alho
void cabecalho();
//Menu da lista
void menu_lista();

 
#endif