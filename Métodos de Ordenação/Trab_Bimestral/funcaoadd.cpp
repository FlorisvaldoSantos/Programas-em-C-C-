
#include"includes.h"


long *AlocaVetor(long tam)
{
	long *vet = (long*)malloc( tam * sizeof(long));

	if(vet == NULL)
	{
		return 0;
	}
	return vet;
}

void Preenche_Vetor(long *vetor, long tam)
{
	srand(time(NULL));

	for(int i=0; i <tam; i++)
	{
		vetor[i] = (rand()*rand());
	}
}

void MostraVetor(long *vetor, long tam)
{
	for(long i =0; i<tam; i++)
	{
		printf("%ld\n", vetor[i]);
	}
}


void insere_dados(long &dado, long *vetorNumerico,  long *Outrovetor)
{
	for(long i =0; i<dado ; i++)
	{
		//Mesma entrada para todos os vetores
		Outrovetor[i] = vetorNumerico[i];
	}
}

long porcentagem(long tamanho)
{
	return  (tamanho * 0.05);
}


void desorganiza(long *vetor, long dado)
{
	srand(time(NULL));
	long tam =  porcentagem(dado) ,j,i=0;
	
	for(j =0; j<tam;j++)
	{	
		i = ((rand()*rand())%dado);
		vetor[i] = (rand()*rand());
	}
}


void inverte(long *vetor,long tamanho)
{
	long tam =  (tamanho -1), aux = 0, meio = (tamanho/2);
	
	for(long i =0; i<=meio; i++)
	{
			 aux = vetor[i];
			 vetor[i] = vetor[tam];
			 vetor[tam] = aux;
			 tam--;
	}
}

void print_linha(int valor)
{
	for(int i=0; i<valor; i++)
		printf("%c",205);
}

void Cabecalho()
{	
	printf("%c",201);// quina esquerda
	print_linha(78);
	printf("%c",187);// quina direita
	printf("%c Curso: Ciencia da Computacao - Trabalho Bimestral\t\t\t       %c",186,186);
	printf("%c Aluno: Florisvaldo Santos \t\t\t\t\t\t       %c",186,186);
	printf("%c",200);
	print_linha(78);
	printf("%c",188);
}

void Mostra_tabela(long &Qtdado,float &TmpQuickQuase, float &TmpQuickDesord, float &TmpQuickDecre
								,float &TmpHeapQuase, float &TmpHeapDesord, float &TmpHeapDecre
								,float &TmpShellQuase, float &TmpShellDesord, float &TmpShellDecre
								,float &TmpInsertQuase, float &TmpInsertDesord, float &TmpInsertDecre
								,float &TmpOutroQuase, float &TmpOutroDesord, float &TmpOutroDecre
								){

// Tabela Com os Valores a Serem Mostrados, tem o codigo da tebela ascii
	
	printf("\t%c",201);print_linha(60);printf("%c\n",187);// quina direita
	printf("\t%c Tamanho do Conjunto: %-12ld\t\t\t     %c",186,Qtdado,186);// Mostra dado
	printf("\n\t%c",204);print_linha(60);printf("%c",185);// Junção direita
	printf("\n\t%c\t    Tempos obtidos pelos algoritmos\t\t     %c",186,186);
	printf("\n\t%c",204); //Junção Esquerda
	print_linha(14);printf("%c",203);print_linha(13);printf("%c",203);print_linha(13);printf("%c",203);print_linha(17);
	printf("%c",185);// Junção direita
	printf("\n\t%c  Algoritmo   %c Q. Ordenado %c Desordenado %c Or. Decrescente %c",186,186,186,186,186);
	printf("\n\t%c",204);print_linha(14);printf("%c",206);print_linha(13);printf("%c",206);print_linha(13);printf("%c",206);print_linha(17);printf("%c",185);
	printf("\n\t%c Quicksort    %c  %10.3f %c %11.3f %c %15.3f %c",186,186,TmpQuickQuase,186,TmpQuickDesord,186,TmpQuickDecre,186);
	printf("\n\t%c",204);print_linha(14);printf("%c",206);print_linha(13);printf("%c",206);print_linha(13);printf("%c",206);print_linha(17);printf("%c",185);
	printf("\n\t%c Shellsort    %c  %10.3f %c %11.3f %c %15.3f %c",186,186,TmpShellQuase,186,TmpShellDesord,186,TmpShellDecre,186);
	printf("\n\t%c",204);print_linha(14);printf("%c",206);print_linha(13);printf("%c",206);print_linha(13);printf("%c",206);print_linha(17);printf("%c",185);
	printf("\n\t%c Heapsort     %c  %10.3f %c %11.3f %c %15.3f %c",186,186,TmpHeapQuase,186,TmpHeapDesord,186,TmpHeapDecre,186);
	printf("\n\t%c",204);print_linha(14);printf("%c",206);print_linha(13);printf("%c",206);print_linha(13);printf("%c",206);print_linha(17);printf("%c",185);
	printf("\n\t%c Insertion    %c  %10.3f %c %11.3f %c %15.3f %c",186,186,TmpInsertQuase,186,TmpInsertDesord,186,TmpInsertDecre,186);
	printf("\n\t%c",204);print_linha(14);printf("%c",206);print_linha(13);printf("%c",206);print_linha(13);printf("%c",206);print_linha(17);printf("%c",185);
	printf("\n\t%c Mergesort    %c  %10.3f %c %11.3f %c %15.3f %c",186,186,TmpOutroQuase,186,TmpOutroDesord,186,TmpOutroDecre,186);
	printf("\n\t%c",200);print_linha(14);printf("%c",202);print_linha(13);printf("%c",202);print_linha(13);printf("%c",202);print_linha(17);printf("%c",188);

}