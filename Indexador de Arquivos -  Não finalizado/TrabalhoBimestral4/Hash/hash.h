#pragma once

#include<iostream>
#include<string>
#include<math.h>
#include"..\Frequencia\frequencia.h"
#include"..\Lista\lista.h"

using namespace std;
// diretiva
#define PI 3.141592653589793238466546498976163131

class HASH{

private:
	// ideia é ser como uma matriz, onde eu indexo as palavras por um valor inteiro 
	// e dentro da hash tenho outra que 
	FREQUENCIA *hash;
	// idéia e ser como é uma lista quando cheio a hash evitar colisão
	HASH *proximo;
	int tamanho;
	int colisao;
	string nomearquivo;
	
public:
	// passa a quantidade de arquivos no diretorio
	HASH(int tamanho);
	~HASH();
	
	// funções principais
	bool inserepalavras(char *arquivo,int frequencia, string nome);
	bool removedocumento(string arquivo);
	bool mostradocumento();
	bool pesquisa(char *vetor);
	double cosseno(FREQUENCIA *vetpesquisa, int tam, FREQUENCIA *vetarquivo);
	// função que posiciona a chave na hash
	// está função so aceita char para posicionar e não sinalizado ex: unsigned char *string = "valor";
	int sdbm(char  *str);

	// 
	HASH *getproximo();
	string getname();
	bool setanomedocumento(string nome);
	bool setproximo(HASH *hash);
	void incrementacolisao();
	string palavraindexadora();
};