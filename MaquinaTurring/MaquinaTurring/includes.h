#ifndef _include_
#define _include_


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

typedef struct Transições
{		//(a,0,0)(b,>)
		char estado,
		 simbolido, 
		 simpgravar,
		 proximoestado,
		 direção;
};

typedef struct TURING
{
	int NumeroEstados,
		Numerotrans,
		Cabeçote;
	char 
		*Fita,
		*AlfabetoFita,
	    EstadoInicial,
		*EstadosParada,
		EstadoAutal;
	Transições *trans;
	HANDLE out;
};


#define para() printf("\n\n\n");system("pause")
	
bool PegaTamanhoMemoria(FILE *fp,int  &numeroestados, int &tamAlf, int &tamInicial,int &tamFinal, int &tamLinha , int &QuanLinha);
TURING *AlocaMAquina(int  &numeroestados, int &tamAlf,int &tamInicial , int &tamFinal, int &tamLinha , int &QaunLinha);
void PreparaMaquina(FILE *fp, TURING *maq);
bool validaCadeia(TURING *maq, char *string);
void Mostra(TURING *maq);
void Limpa(char *string);
void VerificaVazio(char *string);
bool MaquinaTuring(TURING *maq, char *cadeia);
void print_linha(int valor);
void cabecalho();
void LimpaTrans(char *string, char *buffer);

void MostraCompFita(TURING *maq );

#endif