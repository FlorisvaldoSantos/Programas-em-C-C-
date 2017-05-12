
#pragma once
#include<fstream>
#include<string>
#include"Indexador\index.h"

using namespace std;

class INDEXADOR{

private:
	int tamanho;
	INDEX *index_main;

public:

	INDEXADOR(int tamanho);
	~INDEXADOR();
	//
	int sdbm(char  *str);
	//funções de busca
	void carregatabela();
	bool pesquisa();
	bool remove();

};