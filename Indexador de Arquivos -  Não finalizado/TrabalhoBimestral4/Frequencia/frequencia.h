#pragma once 
#include<ostream>
#include<string>

using namespace std;

class FREQUENCIA{

private:
	
	FREQUENCIA *proximo;
	char caracter;
	int frequencia;
	string value;
	string nomearquivo;

public:

	FREQUENCIA();
	void setchar(char c);
	void setfrequencia(float tam);
	void setnomearquivo(string nome);
	char getchar();
	float getfrequancia();
	void setstring(string value);
	string getstring();
	string getnomearquivo();
	FREQUENCIA *getproximo();
	bool setaproximo(FREQUENCIA *novo);
	
	
};
