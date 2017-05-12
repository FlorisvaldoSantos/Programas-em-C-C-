#pragma once
#include"includes.h"


/*
  Aluno: Florisvaldo Santos
  Curso: Ciência da Computação
  Turma: 4º período  U
*/

class GRAFO{

private:
	
	NO *vetorno;
	bool **mat, **matwarshall;
	int tam;
	vet *vetor;

public:
	
	GRAFO(int tam);
	void inicializa(bool **mat);
	void mostra(bool **mat);
	bool seta_adjacencia(int linha, int coluna);
	bool destroi_adjacencia(int linha, int coluna);
	int num_adacencia(int linha);
	int menu();
	void cabeçalho();
	void warshall();
	bool **getmat();
	bool **getmatwarshall();
	int gettam();
	void mostraadj(int ret);
	void mostranos(int tam);
	void deletenos();
	// meu destrutor
	~GRAFO();
	
};