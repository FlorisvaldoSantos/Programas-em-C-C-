
#include"includes.h"


/*
Aluno: Florisvaldo Santos - 3º período
Curso: Ciência da Computação
*/
#define para() {printf("\n\n\n\n");system("pause");}

void cabecalho()
{ 
	printf("--------------------------------------------------------------------------------");
	printf("\t\t\tTrabalho - Fabricio \n");
	printf("\t\t\tAluno: Florisvaldo Santos 2 ano.\n");
	printf("--------------------------------------------------------------------------------\n");
}



void main()
{
	
	cabecalho();
	Avl *arvore = alocaAvl();
		
	long int tam = 0, tam_pesq = 0 , *vetor_pesq, elementos, *vetaux;
	float tempohash=0, 
		  temparvore=0, 
		  temp_pesq_hash = 0, 
		  temp_pesq_arvore = 0;
	// Variaveis para tempo
	clock_t temp_fim =0, temp_ini;

	//Planta sementinha, kkkk
	srand(time(NULL));

	printf("\n\tInforme o tamanho da Tabela Hash:");
		scanf("%d",&tam);
	printf("\n\tInforme a quantidade de elementos:");
		scanf("%d", &elementos);
	printf("\n\tInforme o tamanho do vetor de pesquisa:");
		scanf("%d",&tam_pesq);
	puts("");
	
	// as funções são do vetor de pesquisa onde é gerado elementos aleatorios e colocados no vetor
	vetaux = vetpesquisa(elementos);
	preenche_vetpesq(vetaux, elementos, elementos);
		
	//aloca "tabela"  hash, vetor de pesquisa, e preenche os valores no vetor    
	HASH *hash =  alocahash(tam);
	vetor_pesq = vetpesquisa(tam_pesq);
	preenche_vetpesq(vetor_pesq,tam_pesq,elementos);

	// Insere elementos na arvore e na tabela
	printf("\tInserindo elementos na arvore...");
	
	temparvore = insere_arvore(elementos, vetaux, &arvore->raiz);
	printf("\t\tPronto!\n");
	
	printf("\tInserindo na Tabela Hash...");
	tempohash = insere_hash_1(hash, vetaux, elementos);
	printf("\t\t\tPronto!\n");

	printf("\tPesquisando elementos...");
	// Pesquisa de elementos da Tabela Hash
	temp_ini =  clock();
	for(int i=0;i<tam_pesq;i++)
	{
		pesquisa_hash(hash,vetor_pesq[i]);
	}
	temp_fim =  clock();
	temp_pesq_hash =  (float)(temp_fim - temp_ini)/CLOCKS_PER_SEC;
	
	// Tempo de busca dos elementos da arvore binaria recursiva
	temp_ini = clock();
	for(int i=0; i<tam_pesq;i++)
	{	
		busca_elemento(arvore->raiz,vetor_pesq[i]);
	}
	temp_fim =  clock();
	temp_pesq_arvore = (float)(temp_fim - temp_ini)/CLOCKS_PER_SEC;
	
	printf("\t\t\tPronto!\n\n");
	printf("\tNumero de Colisoes: %d\n\n", hash->Colisao);
	// Imprime resultados 

	printf("\t|-----------------------------------------------|\n");
	printf("\t|       -  Insercao   |   Busca    |  Total     |\n");
	printf("\t|Hash	- %10.3fs |%10.3fs |%10.3fs | \n", tempohash,temp_pesq_hash,(tempohash+temp_pesq_hash));
	printf("\t|Arvore	- %10.3fs |%10.3fs |%10.3fs |\n", temparvore,temp_pesq_arvore,(temparvore+temp_pesq_arvore) );
	printf("\t|-----------------------------------------------|\n");

	
	para();
}





	


