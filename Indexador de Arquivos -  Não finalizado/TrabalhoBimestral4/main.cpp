
#include<iostream>
#include"includes\dirent.h"
#include"processamento_texto\processamento_texto.h"
#include"Lista\lista.h"
#include"indexador.h"

#define PATH_INDEXADOR				"./noticias"
#define PARA system("pause");

int main()
{
	cout<<"Bem vindo ao programa de Indexacao.	"<<endl;
	ifstream entrada;
	//entrada.open("RAIZ_lista.txt");
	std::string valor;
	int i=0;
	LISTA *lista = new LISTA();
	INDEXADOR *in = new INDEXADOR(140000);
	
	in->carregatabela();
	
	/*FREQUENCIA vetpes[2], vetarq[2];
	vetpes[0].setfrequencia(3);
	vetpes[1].setfrequencia(1);

	vetarq[0].setfrequencia(3);
	vetarq[1].setfrequencia(1);

	HASH *hash = new HASH(12);
	double var =0;
	var = hash->cosseno(vetpes, 2, vetarq);
*/

	//hash->inseredocumento(stringinsere, 1, "arquivo1.txt");

	processamento_texto *process = new processamento_texto();
	DIR *diretorio;//= opendir("\\noticias");
	struct dirent* oi;
	
	if(diretorio = opendir(PATH_INDEXADOR)){
		while(oi = readdir(diretorio)){

			
			if(strcmp(oi->d_name, ".") != 0 && strcmp(oi->d_name, "..") != 0){
				
				valor = oi->d_name;
				valor = "noticias\\" + valor;
				i++;
				cout<<"\t\t"<<oi->d_name<<"\t"<<i<<endl;
					cout<<valor<<endl;
					entrada.open(valor);

				/*	if(oi!=NULL){
						process->removestopwords(entrada, valor);
						entrada.close();
					}*/
					entrada.close();
					//system("pause");
			}
			//delete process;
		}
	 	closedir(diretorio);
	}
	//lista->gravalista("minhalista.txt");
	cout<<i;
	system("pause");
	return 1;
	


		
		
	
	system("pause");
}