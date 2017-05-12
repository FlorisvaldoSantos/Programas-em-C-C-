#pragma once 
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <string>


#include "lista.h"


/*Descrição do programa a ser implementado (3.0 pontos)
•	O programa a ser elaborado deve conter as seguintes funcionalidades:
- inclusão de elemento no início da lista **
- inclusão de elemento no final da lista **
- exclusão de elemento do início da lista **
- exclusão de elemento do final da lista**
- exclusão de elemento dado o valor**
- consulta dado o valor***
- consulta ao n-ésimo termo***
- mostra os elementos da lista***
- sobrecarga de operadores (adição, atribuição e igualdade)
•	Diretivas:
a)	a lista deve ser simplesmente encadeada; ***
b)	alocar cada node dinamicamente (usando ponteiros); **
c)	utilizar as classes Node e Lista passadas como exemplo. **
*/

int main() {
	
	lista A,B,C;
	
	C.inserthead("Lucas");
	C.inserthead("Fernando");
	C.inserthead("Florisvaldo");

	B.inserthead("Cicero");
	B.inserthead("Jean");
	B.inserthead("Alceu");
	
	int escolha;
	bool cond = true, quit = false;
	char pega[50], tempEntreada[50];

	do{
		cout << "--------------------------------------------------------------------------------" 
		<< "\t\t   Bacharelado em Ciencia da computacao\n" 
		<< "\t\t       Florisvaldo Santos - 1U - 2010\n" 
		<< "--------------------------------------------------------------------------------\n"
		<< "\t1. Inclusao de elemento no inicio da lista.\n"
		<< "\t2. Inclusao de elemento no final da lista.\n" 
		<< "\t3. Exclusao de elemento do inicio da lista.\n"
		<< "\t4. Exclusao de elemento do final da lista.\n" 
		<< "\t5. Exclusao de elemento dado o valor(palavra).\n"
		<< "\t6. Consulta dado o valor(palavra).\n"
		<< "\t7. Consulta ao n-esimo termo.\n"
		<< "\t8. Mostra os elementos da lista.\n"
		<< "\t9. Sobrecarga de operadores.\n"
		<< "\t10. Sair\n"
		<< "\t\t\nDigite uma das opcoes:";
		
		cin>>escolha;
							
			switch(escolha){
					
				case 1:
					system("cls");
					cout << "--------------------------------------------------------------------------------\n"
					<< "\t1. Insere no inicio da lista.\n\n"
					<< "Digite o nome:";
					fflush(stdin);
					cin>>pega;
					//while(strlen(pega)!=0){
						A.inserthead(pega);
						cout << "Digite o nome:";
						fflush(stdin);
						//cin>>(pega);
					//}
				break;
				
				case 2:
					system("cls");
					cout << "--------------------------------------------------------------------------------\n"
					<< "\t2.Inclusao de elemento no final da lista.\n\n"
					<< "Digite o nome:";
					fflush(stdin);
					cin>>(pega);
					//while(strlen(pega)!=0){
						A.inserttail(pega);
						cout << "Digite o nome:";
						fflush(stdin);
						cin>>(pega);
					//}
				break;

				case 3:
					system("cls");
					cout << "--------------------------------------------------------------------------------\n"
  					<< "\t3. Exclusao de elemento do inicio da lista.\n\n"
					<<"\n\tlista atual.\n";
					A.show();
					cout << endl;
					system("pause");
					A.removehead();
					cout << "\n\Excluido elemento.\n";
					A.show();
					cout << endl;
					system("pause");
					
				break;
				
				case 4:
					system("cls");
					cout << "--------------------------------------------------------------------------------"
  					<< "\t4. Exclusao de elemento do final da lista.\n\n"
					<< "Lista atual\n";
					A.show();
					cout << endl;
					system ("pause");
					A.removetail();
					cout << "\n\Excluido elemento.\n";
					A.show();
					cout << endl;
					system("pause");
				break;

				case 5:
					system("cls");
					cout << "--------------------------------------------------------------------------------"
  					<< "\t5. Exclusao de elemento dado o valor(palavra).\n\n"
					<< "\nInforme o valor:";
					fflush(stdin);
					cin >> pega;
					A.removalue(pega);
					system("pause");

				break;
				
				case 6:
					system("cls");
					cout << "--------------------------------------------------------------------------------"
  					<< "\t6. Consulta dado o valor (palavra).\n\n"
					<< "Informe a palavra:";
					fflush(stdin);
					cin >> (pega);
					A.queryvalue(pega);
					system("pause");

				break;
				
				case 7:
					system("cls");
					cout << "--------------------------------------------------------------------------------"
					<< "\t7. Consulta ao n-esimo termo(valor inteiro).\n\n"
					<< "Informe o valor:";
					fflush(stdin);
					cin >> (pega);
					A.queryterm(atoi(pega));
					cout << endl;
					system("pause");
				break;
				
				case 8:
					system("cls");
					cout << "--------------------------------------------------------------------------------"
					<< "\t Elementos da lista.\n\n";
					A.show();
					cout <<"\n\n" <<endl;
					system("pause");
				break;
				
				case 9:
										
					system("cls");
					cout << "--------------------------------------------------------------------------------"
						<<"\t1. Sobrecarga de adicao (+).\n"
						<<"\t2. Sobrecarga de atribuicao.\n"
						<<"\t3. Sobrecarga de igualdade.\n\n";
						
					cout<<"lista A.\n" << endl;	
					A.show();

					//B=A);


					//A=B;
						
					cout<<"\nlista A+B.\n";	
					
						
					cout << "\n\nA==B\n"
						<<"resultado (treu or false):";
					if(A==B){
							cout << "True\n\n";
					}
					else
						cout <<"False\n\n";
						
						//cout<<"Lista B\n";
					B.showtwo(C);
						
						cout<<endl;
						system("pause");
				break;
				case 10:
					system("cls");
					cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\tEncerrando programa..." << endl;
					Sleep(350);
					cond= false;
				break;

				default:
					cout << "\n\t\tOpcao incorreta." << endl;
					Sleep(500);
				break;
			} 

		system("cls");
	}while(cond);

	return 0;
}