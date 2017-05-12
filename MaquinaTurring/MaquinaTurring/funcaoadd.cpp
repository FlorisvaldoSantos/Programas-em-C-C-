
#include"includes.h"



	
bool PegaTamanhoMemoria(FILE *fp,int  &numeroestados, int &tamAlf, int &tamInicial,int &tamFinal, int &tamLinha , int &QuanLinha)
{
	bool quit = true ,ret= false, ret2= false;
	int  tam=0, aux=0;
	char  gambis[3],maracutaia[3], alfabeto[20], estadosFinais[20], estadosInicial[10], transições[20], valida[20];

	// le numero de estados
	fscanf(fp,"%d",&numeroestados);

	// lé alfabeto da fita
	fscanf(fp,"%s", alfabeto);
	LimpaTrans(valida, alfabeto);
	//lé estados iniciais da maquina
	fscanf(fp,"%s", estadosInicial);

	//Lé estados finais
	fscanf(fp,"%s", estadosFinais);

	//lé transições
	while(!feof(fp))
	{
		fscanf(fp,"%s",transições);
		gambis[0]= transições[1];
		gambis[1]='\0';

		maracutaia[0] = transições[8];
		maracutaia[1]= '\0';
		if( transições[10]!='>' && transições[10]!='<' && transições[10]!='§' )
		{
			printf("\tErro: Direcao, linha %d do arquivo!\n", aux+1);
		}
		if(maracutaia[0]=='§')
		{		/* estado de parada*/}
		else if( atoi(maracutaia) >= numeroestados || atoi(maracutaia)<0)
		{
			printf("\tErro: numero proximos estados, linha %d do arquivo!\n", aux+1);
			quit = false;
		}
		if( atoi(gambis) >= numeroestados || atoi(gambis)<0)
		{
			printf("\tErro: numero estados, linha %d do arquivo!\n", aux+1);
			quit = false;
		}
		tam = strlen(valida);
		for(int i =0; i< tam ; i++)
		{
			if(transições[3]==valida[i]) 
			{
				ret = true;
			}
			if(transições[5]==valida[i])
			{
				ret2 = true;
			}
		}
		if(ret == false || ret2 == false)
		{
			printf("\tErro: linha transicoes %d do arquivo!\n", aux+1);
			quit = false;
		}
		ret = false;
		ret2 = false;
		aux++;
	}
	// se foi validado com sucesso !
	if(quit)
	{
		// Iniciaçiza as variaveis
		tamAlf = strlen(alfabeto);
		tamFinal = strlen(estadosFinais);
		QuanLinha = aux;
		tamInicial = strlen(estadosInicial);
		return quit;
	}
	return quit;
}
TURING *AlocaMAquina(int  &numeroestados, int &tamAlf,int &tamInicial , int &tamFinal, int &tamLinha , int &QaunLinha)
{
	// aloca estrutura 
	TURING *maquina = (TURING*) malloc (sizeof(TURING));
	if(maquina == NULL)
		return 0;
	maquina->NumeroEstados  = numeroestados;
	maquina->AlfabetoFita = (char*)malloc( tamAlf * sizeof(char));
	maquina->EstadosParada = (char*)malloc( tamFinal * sizeof(char));
	maquina->trans = (Transições*) malloc(QaunLinha*sizeof(Transições));
	maquina->Numerotrans = QaunLinha;
	maquina->Cabeçote = 0;
	// aloca fita com 100 para dizer que é Ilimitada
	maquina->Fita =  (char*) malloc(100 *sizeof(char));
	maquina->out = GetStdHandle(STD_OUTPUT_HANDLE);
		
	return maquina;
}
void LimpaTrans(char *string, char *buffer)
{
	int tam = strlen(buffer), j=0;
	for(int i =0;i<tam  ;i++)
	{
		if(buffer[i]!=',' && buffer[i]!='(' && buffer[i]!=')')
		{
			string[j]=buffer[i];
			j++;
		}
	}
	string[j]='\0';
}
void PreparaMaquina(FILE *fp, TURING *maq)
{
	char buffer[15];
	fseek(fp,0,0);
	// le numero de estados
	fscanf(fp,"%d",&maq->NumeroEstados);

	// lé alfabeto da fita
	fscanf(fp,"%s", buffer);
	LimpaTrans(maq->AlfabetoFita, buffer);

	//lé estados iniciais da maquina
	fscanf(fp,"%s",&maq->EstadoInicial);
	
	//Lé estados finais
	fscanf(fp,"%s",buffer);
	LimpaTrans(maq->EstadosParada, buffer);
	//lé transições
	int i =0;
	while(!feof(fp))
	{//(a,0,0)(b,>)
		fscanf(fp,"%s",buffer);
		maq->trans[i].estado = buffer[1];
		maq->trans[i].simbolido = buffer[3];
		maq->trans[i].simpgravar = buffer[5];
		maq->trans[i].proximoestado = buffer[8];
		maq->trans[i].direção = buffer[10];
		i++;
	}
}
bool validaCadeia(char *string, char *simbolos)
{
	int tam = strlen(string), aux = strlen(simbolos);
	bool quit= false, ret = false;

	for(int i=0; i< tam; i++)
	{
		for(int j=0; j< aux ;j++)
		{
			if(string[i] == simbolos[j])
			{
				quit = true;
			}
			else
			{
				quit = false;
			}
		}
	}
	return quit;
}
void Mostra(TURING *maq)
{
	
	printf("\n\tM = (K, ∑, §, S, H)\n");
	printf("\tK = %d\n",maq->NumeroEstados);
	printf("\tK = %s\n",maq->AlfabetoFita);
	int i =0;
	while(i< maq->Numerotrans)
	{
		printf("\t§ = %c %c %c %c %c\n",maq->trans[i].estado,maq->trans[i].simbolido,
			maq->trans[i].simpgravar,maq->trans[i].proximoestado,maq->trans[i].direção);
		i++;
	}
	printf("\tS = %c\n",maq->EstadoInicial);
	printf("\tH = %s\n",maq->EstadosParada);

}
void Limpa(char *string)
{
	int tam = strlen(string);
	for(int i =0; i<tam;i++)
	{
		string[i]='\0';
	}
}
void VerificaVazio(char *string)
{
	int tam = strlen(string);

	for(int i =0; i<tam ;i++)
	{
		if(string[i]==' ')
			string[i]='$';
	}
}

void InsereVazio(char *string)
{
	int tam = strlen(string);

	for(int i =0; i < tam ; i++)
	{
		if(string[i]==NULL)
			string[i]='$';
	}
}
void MostraCompFita(TURING *maq )
{	
	
	int tam = strlen(maq->Fita);
	SetConsoleTextAttribute(maq->out, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("Fita %c",16);
	for(int j =0; j< tam; j++)
	{	
		SetConsoleTextAttribute(maq->out, FOREGROUND_INTENSITY);
		
		if(maq->Cabeçote == j)
		{
			SetConsoleTextAttribute(maq->out, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN| BACKGROUND_RED | BACKGROUND_GREEN |FOREGROUND_INTENSITY);
			printf("%c",maq->Fita[maq->Cabeçote]);
		}else
			printf("%c",maq->Fita[j]);
	}
	printf("\n");
}
// M(estadoatual, direção, fita)
	
bool MaquinaTuring(TURING *maq, char *cadeia)
{
	bool quit =  true, ret = false;
	int i=0, cabeçote=0;
	char aux[5], buffer[5], simblido;
	
	
	Limpa(maq->Fita);
	maq->Fita[0]='#';
	strcat(maq->Fita,cadeia);
	maq->Fita[strlen(maq->Fita)]='#';
	// termina a fita
	maq->Fita[strlen(maq->Fita)]='\0';
	
	VerificaVazio(maq->Fita);
	
	// estado atual é inicializado
	maq->EstadoAutal = maq->EstadoInicial;
	maq->Cabeçote++;

	SetConsoleTextAttribute(maq->out, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("\n\n\t\t Computacao:\n\n");
		while(quit)
		{
			
			for(int i =0 ; i< maq->Numerotrans; i++)
			{
				if(maq->EstadoAutal == maq->trans[i].estado && maq->trans[i].simbolido == maq->Fita[maq->Cabeçote] )
				{
					ret = true;
					// muda de estado
					maq->EstadoAutal = maq->trans[i].proximoestado;
					// grava na fita
					//puts(maq->Fita);

					maq->Fita[maq->Cabeçote] = maq->trans[i].simpgravar;
					// mostra a fita
					MostraCompFita(maq);

					if(maq->trans[i].estado == '§')
					{
						return 1;
					}
					else if(maq->trans[i].direção == '<')
					{
						maq->Cabeçote--;
					}
					else if(maq->trans[i].direção == '>')
					{
						maq->Cabeçote++;
					}
					//puts(maq->Fita);
					
				}

			}
			if(ret == false)
			{
				quit = false;
			}
			ret = false;
			//i++;
		}
	
		return true;
}
void print_linha(int valor)
{
	for(int i=0; i<valor; i++)
		printf("%c",205);
}
void cabecalho()
{
	system("cls");
	printf("%c",201);// quina esquerda
	print_linha(78);
	printf("%c",187);// quina direita
	printf("%c  Pontificia Universidade Catolica do Parana - Ciencia da Computacao\t       %c",186,186);
	printf("%c  Linguagens Formais - 2011 - Turma U - Prof. Fabio Vinicius Binder           %c",186,186);
	printf("%c  Trabalho Pratico -  Maquina de Turing    \t\t\t\t       %c",186,186);
	printf("%c  Aluno: Florisvaldo Santos  Ano: 2011.    \t\t\t\t       %c",186,186);
	printf("%c  Aluno: Guilherme Kloss Mendes  \t\t\t\t\t       %c",186,186);
	printf("%c",200);
	print_linha(78);
	printf("%c",188);
}

