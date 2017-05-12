#pragma once
#include"indexador.h"

// numero de linhas hash tem que ser contado fora
INDEXADOR::INDEXADOR(int tamanho){

	this->tamanho =  tamanho;
	this->index_main = new INDEX[this->tamanho];
	
}
INDEXADOR::~INDEXADOR(){

	delete this->index_main;
}

int INDEXADOR::sdbm(char  *str){

        unsigned int hash = 0;
        unsigned int c;

        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

       return hash;
 }
//funções de busca
void INDEXADOR::carregatabela(){

	ifstream hash_main;
	hash_main.open("hash_main.txt");
	unsigned int posição =0;
	string value;
	hash_main.clear();
	hash_main.seekg(ios::beg);
	posição = hash_main.good();
	while(hash_main.good()){
		getline(hash_main, value);
		cout<<"oi";
	}
	
	
}
bool INDEXADOR::pesquisa(){
	return true;
}
bool INDEXADOR::remove(){
	return true;
}