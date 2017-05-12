#ifndef _FUNCTION_
#define _FUNCTION_

#include"matesparca.h"
#include"lista.h"
#include"no.h"
#include<stdlib.h>
#include<stdio.h>


// Aloca a estrutura da matriz 
MAT *alocaMatriz(int Linhas);	

// Retorna o elemento na posi��o (i, j) da matriz esparsa M (retorna 0 se n�o houver valor v�lido);
int returnvalor(MAT *M,int i,int j);

// SetaValor(M,i,j,V): atribui o valor V para a posi��o (i, j) da matriz esparsa M;
bool setaValor(MAT *M,int i,int j,int Valor);

// Seta o elemento (i, j) da matriz como nulo;
bool setaNulo(MAT *M,int i,int j);

// Imprime a matriz
void imprimeMatriz(MAT *M);

// Retorna o n�mero de valores v�lidos de uma matriz esparsa M.
int contaValores(MAT *M);

// Retorna o maior incide entre todas as listas
int pega_maior_indice(MAT *M);

//Cabe�alho
void cabecalho();

//Menu
void menu();

#endif