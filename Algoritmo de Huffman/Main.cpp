#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <string>
#include"Lista.h"
#include"Huffman.h"


using namespace std;

void main(){
	printf("1-Chama arquivo original\n");
	printf("2-Codifica arquivo\n");
	
	FILE *fp=fopen("texte.txt","r");
	Lista *l=alocaL();
	l = calculaFrequenciaElementos(fp,l);
	codigoHuffman(l);
	mostra_lista(l);
	geraArquivoCodificado(fp,l);
	//*************************************
	FILE *fp2=fopen("arquivoCodificado.txt","r+");
	geraDecodificacaoArquivo(fp2,l);

	
	system("pause");




}