#include"no.h"

NO::NO(string c)
{
	this->frequencia = NULL;
	this->frequencia++;
	this->palavra = c;
	this->proximo = NULL;
	this->direita = NULL;
	this->esquerda = NULL;
	this->visitado = false;
}

NO::~NO()
{
	// ainda não sei o que precisa 
	delete this->proximo;
	delete this->direita;
	delete this->proximo;
}
	// funções que se aplicam a lista
NO* NO::getnext()
{
	return this->proximo;
}
NO* NO::getesquerda()
{
	return this->esquerda;
}
NO* NO::getdireita()
{
	return this->direita;
}
void NO::setdireita(NO *value)
{
	this->direita = value;
}
void NO::setesquerda(NO *value)
{
	this->esquerda = value;
}
void NO::setprox(NO *n)
{
	this->proximo = n;
}
void NO::incrementa()
{
	this->frequencia++;
}

//********************************************
//*********************************************
int NO::getincremento()
{
	return this->frequencia;
}
void NO::setstring(string c)
{
	this->palavra = c;
}
string NO::getstring()
{
	return this->palavra;
}
void NO::setavisita(bool value)
{
	this->visitado = value;
}


	