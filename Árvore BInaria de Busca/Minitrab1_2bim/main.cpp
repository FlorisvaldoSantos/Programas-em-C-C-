
#include"Main.h"



float insere_vetor(long int *vetor, long int tam)
{
	printf("\tIserindo elementos no vetor...");
	clock_t tempo_inicio, tempo_fim;
	tempo_inicio = clock();
	srand(time(NULL));
	int dado=0;
	float tempoexecução=0;

	for(int i=0; i<tam;i++)
	{	
		dado = rand()%(tam);
		vetor[i]= dado;
	}
	tempo_fim =  clock();
	
	tempoexecução =(float)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\tPronto!\n");
	return tempoexecução;
}

NOavl *insere_arvore(int  tam, NOavl *n,float &temparvore)
{
	printf("\tInserindo elementos na arvore...");
	clock_t tempo_inicio, tempo_fim;
	tempo_inicio = clock();
	srand( time(NULL));
	int dado; 
	for(long int  i=0; i<tam;i++)
	{
		dado = rand()%(tam);
		n = insere_arvore(n,dado);
	}
	tempo_fim =  clock();
	
	temparvore =(float)(tempo_fim - tempo_inicio)/CLOCKS_PER_SEC;
	printf("\tPronto!\n");
	return n;
}

void quicksort(long int *vetor, int inicio, int fim)
{
	if(fim - inicio >0)
	{
		int aux;
		int pivot = vetor[inicio];
		int left = inicio + 1;
		int right = fim;
		 while(left < right) {
		  if(vetor[left] <= pivot) {
			 left++;
		  } else {
							// Troca o valor de array[left] com array[right]
			 aux = vetor[left];
			 vetor[left] = vetor[right];
			 vetor[right] = aux;
							// Fim da troca ( equivale a função swap(array[left], array[right]) )
			  right--;
		  }
	   }
	   if(vetor[left] > pivot) {
		  left--;
	   }
			// Troca o valor de array[begin] com array[left]
	   aux = vetor[inicio];
	   vetor[inicio] = vetor[left];
	   vetor[left] = aux;
			// Fim da troca ( equivale a função swap(array[begin], array[left]) )
			// Faz as chamadas recursivas para as duas partes da lista
	   quicksort(vetor, inicio, left-1);
	   quicksort(vetor, right,fim);

	}
}


void cabecalho()
{ 
	printf("--------------------------------------------------------------------------------");
	printf("\t\t\tTrabalho - Fabricio \n");
	printf("\t\t\tAluno: Florisvaldo Santos 2 ano.\n");
	printf("--------------------------------------------------------------------------------\n");
}

long int *vetpesquisa(int tam)
{
	long int *vet = (long int*)malloc( tam * sizeof(long int));
	
	if(vet == NULL)
		return 0;
	
	return vet;
}

void preenche_vetpesq( long int *vet, int tam, int range)
{
	srand(time(NULL));
	int dado=0;

	for(int i=0; i<tam;i++)
	{
		dado = rand()%range;
		vet[i]= dado;
	}
}

float BB(long int *vet,long int tam, long int dado)
{
	int inicio = 0, fim = tam-1, meio = 0;

	while(inicio<=fim)
	{
		meio = ((inicio + fim)/2);

		if(vet[meio] == dado)
		{
			return 1;
		}
		else if(dado < vet[meio])
		{
			fim = meio - 1;
		}
		else
		{
			inicio = meio + 1;
		}
	}
	return 0;
}

void main()
{
	
	cabecalho();
	Avl *arvore = alocaAvl();
	long int *vetor, tam = 0, *vetor_pesq, tam_pesq = 0;
	float tempovetor=0, temparvore=0, ordenaçãovetor=0, temp_pesq_vetor = 0, temp_pesquisa_arvore = 0;
	
	printf("\n\tInforme o tamanho do vetor:");
		scanf("%d",&tam);
	printf("\n\tInforme o tamanho do vetor de pesquisa:");
		scanf("%d",&tam_pesq);
	puts("");
	
	vetor = alocavet(tam);
	
	tempovetor = insere_vetor(vetor,tam);
	arvore->raiz = insere_arvore(tam,arvore->raiz,temparvore);
	printf("\tOrdenando vetor...");
	//pega tempo de ordenação
	clock_t temp_fim, temp_ini;
	temp_ini = clock();	
	quicksort(vetor,0,tam);
	temp_fim = clock();
	ordenaçãovetor = (float) (temp_fim - temp_ini)/CLOCKS_PER_SEC;
	printf("\t	Pronto!\n");
	// Aloca vetor de pesquisa e ordena para facilitar a procura
	vetor_pesq = vetpesquisa(tam);
	preenche_vetpesq(vetor_pesq,tam_pesq,tam);
	quicksort(vetor_pesq,0,tam_pesq);

	// Busca Elementos
	//Pesquisa no vetor
	temp_ini = clock();
	printf("\tPesquisando elementos...");
	
	for(int i=0;i<tam_pesq;i++)
	{
		 BB(vetor,tam,vetor_pesq[i]);
	}
	temp_fim =  clock();
	temp_pesq_vetor =  (float)(temp_fim - temp_ini)/CLOCKS_PER_SEC;
	
	temp_ini = clock();
	for(int i=0; i<tam_pesq;i++)
	{	
		busca_elemento(arvore->raiz,vetor_pesq[i]);
	}
	temp_fim =  clock();
	temp_pesquisa_arvore = (float)(temp_fim - temp_ini)/CLOCKS_PER_SEC;
	printf("\t	Pronto!");
	
	// Imprime resultados 
	system("cls");
	cabecalho();
	puts("");
	printf("\t|------------------------------------------------------------|\n");
	printf("\t|       -  Insercao   | Busca      |  Ordenacao |Total       |\n");
	printf("\t|Vetor	- %10.3fs |%10.3fs |%10.3fs |%10.3fs | \n", tempovetor,temp_pesq_vetor,ordenaçãovetor,(tempovetor+temp_pesq_vetor+ordenaçãovetor));
	printf("\t|Arvore	- %10.3fs |%10.3fs |%10.3fs |%10.3fs |\n", temparvore,temp_pesquisa_arvore,0.0 , (temparvore+temp_pesquisa_arvore+0) );
	printf("\t|------------------------------------------------------------|\n");



	puts("");
	system("pause");
}

