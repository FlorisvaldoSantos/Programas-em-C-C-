
#include"includes.h"



int main(int argc, char *argv[])
{
	bool quit = true, quit2 = true;
	char fim[5]={"FIM"};
	char string[30], cadeia[100];
	int  numeroestados,tamAlf,tamInicial, tamFinal, tamLinha , QuanLinha;
	TURING *maquina;
	
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	
	
	while(quit)
	{
		system("cls");
		SetConsoleTextAttribute(out,FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED| FOREGROUND_INTENSITY);
		cabecalho();
		
		printf("\n\tPara sair digite FIM: ");
		printf("\n\nDigite o nome do arquivo:");
		gets(string);
		if(strcmp(fim,string)==0)
		{
			quit = false;
			return 0;
		}
		// abre o arquivo 
		FILE *fp =  fopen(string,"r");
		if(fp == NULL)
		{
			SetConsoleTextAttribute(out,FOREGROUND_RED|FOREGROUND_INTENSITY);
			puts("\n\tErro ao abrir o arquivo.");
			para();
		}
		else if(PegaTamanhoMemoria(fp, numeroestados, tamAlf,tamInicial, tamFinal, tamLinha , QuanLinha))
		{		
			// valido com sucesso o arquivo
			while(quit2)
			{
				SetConsoleTextAttribute(out,FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
				maquina = AlocaMAquina(numeroestados, tamAlf,tamInicial, tamFinal, tamLinha , QuanLinha);
				PreparaMaquina(fp,maquina);
				Limpa(maquina->Fita);
				Mostra(maquina);
				printf("\n\n\tDigite a cadeia:");
				gets(cadeia);
				if(strcmp(fim,cadeia)==0)
				{
					quit2 = false;
					system("cls");
				}
				else
				{
					MaquinaTuring(maquina, cadeia);
				}
			}
		}
	}
}// facha main