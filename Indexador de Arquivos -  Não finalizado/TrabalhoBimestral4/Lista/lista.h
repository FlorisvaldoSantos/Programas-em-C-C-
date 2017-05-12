#pragma once 

//#include"..\Ordenação\auxiliarordenação.h"
#include"no.h"
#include<fstream>
#include<string>

using namespace std;

class LISTA
{

private:

	NO *primeiro;
	NO *ultimo;

public:
	LISTA();
	~LISTA();
	bool Insere(string c);
	//bool insereprimeiro(NO *c);
	bool insereprimeiro(NO *c);
	bool inserefim(NO *c);
	
	bool insereordenado(NO *no);
	NO *removeinicio();
	NO *getlista();
	NO* inseredepois(NO *no,string c);
	
	int removefim();
	int removedepois(NO *n);
	bool removenomeio(int meio);
	void mostra();
	bool vazia();
	bool ordena(int total);
	int tamlista();
	
	
	bool inseredepois(NO *no, NO *novo);
	/////////////////////////////////////////////////////
	void inordem(NO *raiz, float total);
	void preordem(NO *raiz);
	//////////////////////////////////////////////////////
	void posordemcodifica(NO *raiz, string value);
	void mostracodificação(NO *raiz);
	///////////////////////////////////////////////////
	bool gravalista(string valor);

	//////////////////////////////////////
	//////////////////////////////////////
	void quicksort( int *vetor, int inicio, int fim);

	//copia 
	//void copiavet(vetoraux *vetor, int tam);
	
};