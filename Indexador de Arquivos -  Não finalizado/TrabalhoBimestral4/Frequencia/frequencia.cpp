

#include"frequencia.h"

FREQUENCIA::FREQUENCIA()
{
	this->caracter = NULL;
	this->frequencia =NULL;
}
void FREQUENCIA::setchar(char c)
{
	this->caracter = c; 
}
void FREQUENCIA::setfrequencia(float tam)
{
	this->frequencia = tam;
}
char FREQUENCIA::getchar()
{
	return this->caracter;
}
float FREQUENCIA::getfrequancia(){
	
	return this->frequencia;
}
void FREQUENCIA::setstring(string value)
{
	this->value = value;
}
string FREQUENCIA::getstring()
{
	return this->value;
}
void FREQUENCIA::setnomearquivo( string nome){
	
	this->nomearquivo =  nome;
}
string FREQUENCIA::getnomearquivo(){

	return this->nomearquivo;
}
FREQUENCIA* FREQUENCIA::getproximo(){
	
	return this->proximo;
}
bool FREQUENCIA::setaproximo(FREQUENCIA *novo){

	this->proximo = novo;
	return true;
}