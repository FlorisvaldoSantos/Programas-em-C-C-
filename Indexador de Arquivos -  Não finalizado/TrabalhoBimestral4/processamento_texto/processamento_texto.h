#pragma once

#include<iostream>
#include<fstream>
#include<string>
#include<ctype.h>
#include"..\Hash\hash.h"
#include"..\Lista\lista.h"



using namespace std;


class processamento_texto{

// Preciso de Um  Nó como retorno, ( é um nó de uma lista simplesmetenencadeada) 
// isto é a primeira etapa da "filtragem das palavras.
private:
	
	char asciivector[255];
	string vetorstop[235];
	
public:

	processamento_texto();
	
	char equivalente(unsigned char value);
	void mostrachar();
	bool limpastring(ifstream &arq_entrada);
	string reconhecetoken(ifstream &arq_entrada);
	void loadstopwords();
	bool buscabinaria(string valor);
	HASH *removestopwords(ifstream &leitura, string nome);
		
};