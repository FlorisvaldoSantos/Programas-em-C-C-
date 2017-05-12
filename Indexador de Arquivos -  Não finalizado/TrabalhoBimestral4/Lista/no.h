#pragma once
#include<iostream>
#include<string>
#include<string>

using namespace std;

class NO
{
private:

	string palavra;
	float frequencia; 
	NO *direita;
	NO *esquerda;
	NO *proximo;
	bool visitado;

public:

	NO(string c);
	~NO();
	/////////////////////////////
	NO *getnext();
	NO *getesquerda();
	NO *getdireita();
	void setdireita(NO *value);
	void setesquerda(NO *value);
	void setprox(NO *n);
	void setavisita(bool value);
	////////////////////////////
	
	void incrementa();
	int getincremento();
	void setstring(string c);
	string getstring();
	bool vazio();
	
	
};