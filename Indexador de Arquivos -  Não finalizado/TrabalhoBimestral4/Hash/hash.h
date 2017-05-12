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
	// ideia � ser como uma matriz, onde eu indexo as palavras por um valor inteiro 
	// e dentro da hash tenho outra que 
	FREQUENCIA *hash;
	// id�ia e ser como � uma lista quando cheio a hash evitar colis�o
	HASH *proximo;
	int tamanho;
	int colisao;
	string nomearquivo;
	
public:
	// passa a quantidade de arquivos no diretorio
	HASH(int tamanho);
	~HASH();
	
	// fun��es principais
	bool inserepalavras(char *arquivo,int frequencia, string nome);
	bool removedocumento(string arquivo);
	bool mostradocumento();
	bool pesquisa(char *vetor);
	double cosseno(FREQUENCIA *vetpesquisa, int tam, FREQUENCIA *vetarquivo);
	// fun��o que posiciona a chave na hash
	// est� fun��o so aceita char para posicionar e n�o sinalizado ex: unsigned char *string = "valor";
	int sdbm(char  *str);

	// 
	HASH *getproximo();
	string getname();
	bool setanomedocumento(string nome);
	bool setproximo(HASH *hash);
	void incrementacolisao();
	string palavraindexadora();
};