
#pragma once
#include"includes.h"

/*
  Aluno: Florisvaldo Santos
  Curso: Ciência da Computação
  Turma: 4º período  U
*/
void GRAFO::inicializa(bool **mat)
{
	for(int i =0; i<this->tam; i++)
	{
		for(int j=0;j<this->tam; j++)
		{
			// valor default 
			mat[i][j] = false;
		}
	}
}
GRAFO::GRAFO(int tam)
{
	this->tam = tam;
	this->vetorno = new NO[this->tam];
	// mat principal 
	this->mat = new bool*[this->tam];
	for(int i=0;i<this->tam; i++)
	{
		this->mat[i] = new bool[this->tam];
	}
	// mat warshall
	this->matwarshall = new bool*[this->tam];
	for(int i=0;i<this->tam; i++)
	{
		this->matwarshall[i] = new bool[this->tam];
	}
	// inicaliza os valores com 
	inicializa(this->mat);
	// 
	inicializa(this->matwarshall);
}
int  GRAFO::gettam()
{
	return this->tam;
}

GRAFO::~GRAFO()
{
	delete this->vetorno;
	//
	for(int i =0; i< this->tam; i++)
	{
		delete this->mat[i];
	}
	delete this->mat;
	// deleta warshall
	for(int i =0; i< this->tam; i++)
	{
		delete this->matwarshall[i];
	}
	delete this->matwarshall;
}

bool **GRAFO::getmat()
{
	return this->mat;
}
bool **GRAFO::getmatwarshall()
{
	return this->matwarshall;
}
void GRAFO::mostra(bool **mat)
{
	// for para mostrar numeros 
	cout<<"     ";
	for(int k=0; k<this->tam; k++)
	{
		cout.width(5);
		cout<<k;
	}
	cout<<"\n\n";
	for(int i=0;i<this->tam; i++)
	{
		cout.width(5);
		cout<<i;
		for(int j=0;j<this->tam;j++)
		{
			cout.width(5);
			if(mat[i][j])
			{
				cout<<"T";
			}
			else
				cout<<"F";
		}
		cout<<endl;
	}
}

bool GRAFO::seta_adjacencia(int linha, int coluna)
{
	this->mat[linha][coluna] = true;
	return true;
}

bool GRAFO::destroi_adjacencia(int linha, int coluna)
{
	// recebe o valor default
	this->mat[linha][coluna] = false;
	return true;
}
void  GRAFO::mostranos(int tam)
{
	for(int i =0; i < tam; i++)
	{
		cout<<this->vetorno[i].getname();
	}
}

int GRAFO::num_adacencia(int linha)
{
	int ret = 0, k=0;
	
	for(int i=0; i<this->tam;i++)
	{
		// lembrando que zero é o valor default
		if(this->mat[linha][i] != 0)
			ret++;
	}
	// aloca vetor com o tamanho necessario
	vetor = new vet[ret];
	// pega os valores da coluna e pso
	for(int j=0; j<this->tam;j++)
	{
		if(this->mat[linha][j] != 0)
		{
			this->vetor[k].indice = j; 
			this->vetor[k].logico = this->mat[linha][j];
			k++;
		}
	}
	
	return ret;
}
void GRAFO::mostraadj(int ret)
{
	for(int i=0; i<ret;i++)
		cout<<"["<<vetor[i].indice<<"] "<<vetor[i].logico<<" - ";

}
void GRAFO::deletenos()
{
	delete this->vetorno;
}
void GRAFO::warshall()
{
	this->matwarshall = this->mat;

	for(int k=0; k<this->tam;k++)
	{
		for(int i=0; i<this->tam;i++)
		{
			if(this->matwarshall[i][k])
			{
				for(int j=0; j< this->tam; j++)
					this->matwarshall[i][j] = this->matwarshall[i][j] || this->matwarshall[k][j];
			}
		}
	}
}


int GRAFO::menu()
{
	int escolha;

	cout<< "\n\n\t 1. cria adjacencia\n"
		<< "\t 2. destroi adjacencia\n"
		<< "\t 3. imprime adjacencia\n"
		<< "\t 4. seta informacao no\n"
		<< "\t 5. Mostra informacao no\n"
		<< "\t 6. retorna o numero de adjacencias\n"
		<< "\t 7. Sair\n"
		<< "Informe a opcao:";

	cin>> escolha;

	return escolha; 
}

void GRAFO::cabeçalho()
{
	cout<< "\tBem vindo ao programa de grafos!\n"
		<< "\tAluno: Florisvaldo Santos\n";

}
