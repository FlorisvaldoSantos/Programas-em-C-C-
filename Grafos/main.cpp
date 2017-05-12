#pragma once
#include"includes.h"
/*
  Aluno: Florisvaldo Santos
  Curso: Ciência da Computação
  Turma: 4º período  U
*/

void main()
{
	GRAFO *grafo;
	int buffer, no1, no2 , op, auxiliar;
	bool quit = true;
	string aux;

	//cout<<"Informe a quantidade de nos:";
	//cin>> buffer;
	limpa
		// seis
	

	grafo = new GRAFO(5);
	grafo->cabeçalho();
	
		grafo->seta_adjacencia(0,1);
	grafo->seta_adjacencia(2, 1);
	grafo->seta_adjacencia(3, 1);
	grafo->seta_adjacencia(4, 3);
	grafo->seta_adjacencia(3, 0);
	grafo->seta_adjacencia(1, 4);
	while(quit)
	{
		grafo->cabeçalho();
	
		op = grafo->menu();
		
			switch(op)
			{
				case 1:
					limpa // macro de limpa tela
					cout<< "\n\n\t 1. cira adjacência\n\n";
					cout<< "informe o NO 1:";
					cin>> no1;
					cout<< "informe o NO 2:";
					cin	>>no2;
					if(no1 > grafo->gettam() || no2 < grafo->gettam())
					{
						// pega o tamanho que o cara informou:
						grafo->seta_adjacencia(no1, no2);
					}
					else
						cout<< "parametros incorretos!";
					 break;

				case 2: 
					limpa // macro de limpa tela
					cout<< "\n\n\t 2. destroi adjacencia\n\n"
						<< "Informe o NO 1:";
						cin>> no1;
						cout<<"Informe o NO 2:";
						cin	>>no2;

						if(no1 > grafo->gettam() || no2 < grafo->gettam())
						{
							grafo->destroi_adjacencia(no1, no2);
						}
						else
						cout<< "parametros incorretos!";
					break;
				case 3:
						limpa // macro de limpa tela
						cout<< "\n\n\t 3. Mostra adjacencia\n\n";
						cout<< "\tMatriz: "<< endl;
						grafo->mostra(grafo->getmat());
						cout<<"\tMatriz de feichamento trasitivo:";
						grafo->warshall();
						grafo->mostra(grafo->getmatwarshall());
						// inicializa os valores com false;
						
						para
							grafo->inicializa(grafo->getmatwarshall());
					break;

				case 4:
					limpa
					
					cout << "\t 4. seta informação no\n\n";
					cout<< "Numero do NO:";
					cin>> buffer;
					cout<<"Digite a string:";
					cin>> aux;
					if(buffer < grafo->gettam())
					{
						//grafo->vetorno[buffer].setname(aux);
					}
									
					break;
				
				case 5:
					limpa
					cout << "\t 5. Mostra informação no\n\n";
					grafo->mostranos(grafo->gettam());
					para
					break;
				case 6:
					limpa
					cout<< "\t 5. retorna o numero de adjacencias\n\n";
					cout<< "Informe o NO:";
					cin>> buffer;
					auxiliar = grafo->num_adacencia(buffer);
					if(auxiliar != 0)
					{
						cout<< "numero de adjacencias do no " << buffer<<" :  "<<  auxiliar<< endl;
						cout<< "vetor de adjacencias: ";
						grafo->mostraadj(auxiliar);
						// delete nos adjacentes do grafo, 
						grafo->deletenos();
						para
					}
					else
					{	
						cout<< "\n\n\tNo nao possui adjacencias\n\n";
						para
					}
					break;

				
				case 7:
						quit = false;
						break;

				default :
					cout<<"\n\n\topcao incorreta!!!";
					para
					break;
			}// switch
			limpa
	}// while
	
}

	
