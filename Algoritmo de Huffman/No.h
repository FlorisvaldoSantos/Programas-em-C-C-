#include <iostream>
#include <string>

using namespace std;

typedef struct No  {
	float freq;
	int qtd;
	char caracter;
	string aux;
	string codigo;
	No *prox;
	No *direita;
	No *esquerda;
};

No *alocaNO(char dado,float freq,No *esquerda,No *direita);
