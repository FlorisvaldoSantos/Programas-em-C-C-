
#pragma once
#include<stdio.h>
#include<string>
#include<ctype.h>
#include"Lista.h"
#include"Huffman.h"

using namespace std;

void atualizaQtDado(Lista *l,char c){
	No *aux=l->primeiro;
	while(aux!=NULL){
		if(aux->caracter==c){
			aux->qtd+=1;
			return;
		}
		aux=aux->prox;
	}
}



int calculaTotalElementos(FILE *p,Lista *l){
	int qtTot=0;
	char c=0;
	while(!feof(p)){
		c=getc(p);
		if(c==-1)return qtTot;
		if(buscaElemento(l,c)==0){
			insere_primeiro(l,c,NULL,NULL,NULL); 
			atualizaQtDado(l,c);
			l->total=l->total+1;
			qtTot++;
		}
		else{
			atualizaQtDado(l,c);
			qtTot++;
		}
	}
	return qtTot;

}

Lista* calculaFrequenciaElementos(FILE *p,Lista *l){	
	char c;
	int total=calculaTotalElementos(p,l);
	No *aux=l->primeiro;

	fseek(p,0,SEEK_SET);
	c=getc(p);
	while(!feof(p)){
		while(aux!=NULL){
		
		if(aux->caracter==c){
			aux->freq=((aux->qtd)/(float)total)*100.0;
			c=getc(p);
		}
		aux=aux->prox;
		}
		aux=l->primeiro;
	}
	return ordena_lista(l);
}

void codigoHuffman(Lista *l){
	No *x,*y,*z;
 	for(int i=0;i<l->total-1;i++){
		x=retira_primeiro(l);
		y=retira_primeiro(l);
		z=alocaNO('\0',NULL,y,x);

		z->freq = x->freq + y->freq;		
		insere_ordenado(l,z->caracter,z->freq,x,y);
		
	}
	geraCodigosCodificacao(z);
}
//Gera codigo individual para caracteres
void percorreArvore(No *raiz,No *pai,bool esq){//gerar codigo
	if(raiz!=NULL){
		if(esq)
			raiz->codigo=pai->codigo+"0";
		else
			raiz->codigo=pai->codigo+"1";
	
		percorreArvore(raiz->esquerda,raiz,true);
		percorreArvore(raiz->direita,raiz,false);
	}
}

//Gera codigo individual para caracteres
void geraCodigosCodificacao(No *raiz){//preordem 
	int aux=0;
	if(raiz->caracter!=0)
		raiz->codigo=aux;
	else
		raiz->codigo="";

	percorreArvore(raiz->esquerda,raiz,true);
	percorreArvore(raiz->direita,raiz,false);
}

void retornaCodigo(No *raiz,No *pai,char c,string *str,bool esq){//preordem
	if(raiz!=NULL){

		if(raiz->caracter==c){
				*str=raiz->codigo;
				return;
		}
		if(raiz->caracter==c) return;
		if(raiz->caracter!=c)retornaCodigo(raiz->esquerda,raiz,c,str,true);
		if(raiz->caracter!=c)retornaCodigo(raiz->direita,raiz,c,str,false);
	}

}

string retornaCodigoGUI(No *raiz,char c){//preordem
	string str="";
	if(raiz->caracter==c)
		return raiz->codigo;

	retornaCodigo(raiz->esquerda,raiz,c,&str,true);
	if(str=="")
		retornaCodigo(raiz->direita,raiz,c,&str,false);

	return str;
}

void retornaCaractereDecodificado(No *raiz,No *pai,char *c,string str,bool esq){
		if(raiz!=NULL){
			if(raiz->codigo==str){
				if(raiz->caracter!=' ' /*&& raiz->caracter!=0*/)
					*c=raiz->caracter;
			}
		}
		else
		{
			retornaCaractereDecodificado(raiz->esquerda,raiz,c,str,true);
			retornaCaractereDecodificado(raiz->direita,raiz,c,str,false);
		}
}

char *retornaCaractereDecodificadoGUI(No *raiz,string str2){
	char *c = (char*)malloc(sizeof(char));
	if(raiz->codigo==str2)
		return (char*)raiz->caracter;

	retornaCaractereDecodificado(raiz->esquerda,raiz,c,str2,true);
	//if(str=="")
	retornaCaractereDecodificado(raiz->direita,raiz,c,str2,false);
}


FILE *geraArquivoCodificado(FILE *arq,Lista *l){
	FILE *saida=fopen("arquivoCodificado.txt","w");
	char c;
	string str="";
	fseek(arq,0,SEEK_SET);	
	while(!feof(arq)){
		c=fgetc(arq);
		str+=retornaCodigoGUI(l->primeiro,c);
		
	}
	fputs(str.c_str(),saida);
	fclose(saida);
	return saida;

}

void geraDecodificacaoArquivo(FILE *saida,Lista *l){
	FILE *saida2=fopen("arquivoDecodificado.txt","w");
	fseek(saida,0, SEEK_SET);
	string str="";
	string str2 ="";
	int i =0;
	char *vet = new char[10];
	//limpa char 
	for(int j=0;j<10;j++)
		vet[j]='\0';
	char *c=(char*)malloc(sizeof(char));
	char *ret=(char*)malloc(sizeof(char));
	
	while(!feof(saida)){
		

			//*c = fgetc(saida);
			
			vet[i] = fgetc(saida);
			str2=vet[i];
			i++;
		ret=retornaCaractereDecodificadoGUI(l->primeiro,str2);
		fputc(*ret,saida2);
		*c=fgetc(saida);
		str2="";
	}
}


