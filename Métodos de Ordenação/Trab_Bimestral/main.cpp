
#include"includes.h"
#include"funcaoadd.h"



void main()
{
	long dado, *vetorNumerico,*vetorQuick, *vetorHeap, *vetorShell, *vetorInsert, *vetorMerge;
	// Variaveis para guardar o tempo das operações e assim possibilitando mostrar na tabela
	float tempQuickOrdena = 0,tempQuickQuaseOrdena = 0,tempQuickDecresente = 0,
		  tempHeapOrdena = 0,tempHeapQuaseOrdena = 0,tempHeapDecresente = 0,	
		  tempShellpOrdena = 0,tempShellQuaseOrdena = 0,tempShellDecresente = 0,	
		  tempInsertOrdena = 0,tempInsertQuaseOrdena = 0,tempInsertDecresente = 0,	
		  tempMergeOrdena = 0,tempMergeQuaseOrdena = 0,tempMergeDecresente = 0;	
	
	
	// Cabeçalho com o Meu nome
	Cabecalho();

	printf("\n\n\tInforme o tamanho do valor do Vetor:");
	scanf("%ld", &dado);


	// Aloca Vetor de Entrada
	vetorNumerico = AlocaVetor(dado);
	Preenche_Vetor(vetorNumerico,dado);
	

	// Para cada Tipo de Ordenação E feito todas as contagens, ou seja, epga os 3 tempos do primeiro vetor e assim por diante
	// o processo é repitido para todos os algoritmos!

	// Aloca a memoria dos outros Vetores 
	vetorQuick =  AlocaVetor(dado);
	
	// Copia entrada para o Vetor 
	printf("\n\tInserindo Elementos nos vetores...");
	insere_dados(dado, vetorNumerico,vetorQuick);
	
	// Pega tempos dos vetores totalmente desordenados
	printf("\n\tPegando os tempos de Ordenacao...\n");
	printf("\n\tQuicksort Ordena...");
	tempQuickOrdena =  tempovetorQuick(vetorQuick,dado);
	printf("\t\t\t\tPronto!");
	printf("\n\tQuicksort Embaralha elementos...");
	desorganiza(vetorQuick,dado);
	printf("\t\tPronto!");
	printf("\n\tQuicksort quanse ordenado...");
	tempQuickQuaseOrdena = tempovetorQuick(vetorQuick, dado);	
	printf("\t\t\tPronto!");
	printf("\n\tQuicksort decresente...");
	inverte(vetorQuick,dado);
	tempQuickDecresente = tempovetorQuick(vetorQuick, dado);
	printf("\t\t\t\tPronto!");

	// Após oegar os tempos de execução e liberado o espaço de memoria do vetor
	//free(vetorQuick);


	// Copia a entrada para o vetor Heap
	vetorHeap = AlocaVetor(dado);
	insere_dados(dado, vetorNumerico,vetorHeap);

	// Pega tempos dos vetores totalmente desordenados
	printf("\n\tHeapsort Ordena...");
	tempHeapOrdena =  tempovetorHeap(vetorHeap,dado);
	printf("\t\t\t\tPronto!");
	printf("\n\tHeapsort Embaralha elementos...");
	desorganiza(vetorHeap,dado);
	printf("\t\t\tPronto!");
	printf("\n\tHeapsort quanse ordenado...");
	tempHeapQuaseOrdena = tempovetorHeap(vetorHeap, dado);	
	printf("\t\t\tPronto!");
	printf("\n\tHeapsort decresente...");
	inverte(vetorHeap,dado);
	tempHeapDecresente = tempovetorHeap(vetorHeap, dado);
	printf("\t\t\t\tPronto!");
	// Libera memoria
	free(vetorHeap);

	// Aloca o vetor Shell e cópia a entrada
	vetorShell = AlocaVetor(dado);
	insere_dados(dado, vetorNumerico,vetorShell);
	
	printf("\n\tShellsort Ordena...");
	tempShellpOrdena =  tempoVetorShell(vetorShell,dado);
	printf("\t\t\t\tPronto!");
	printf("\n\tShellsort Embaralha  elementos...");
	desorganiza(vetorShell,dado);
	printf("\t\tPronto!");
	printf("\n\tShellsort quanse ordenado...");
	tempShellQuaseOrdena = tempoVetorShell(vetorShell, dado);	
	printf("\t\t\tPronto!");
	printf("\n\tShellsort decresente...");
	inverte(vetorShell,dado);
	tempShellDecresente = tempoVetorShell(vetorShell, dado);
	printf("\t\t\t\tPronto!");
	free(vetorShell);

	// Aloca cópia entrada 
	vetorInsert = AlocaVetor(dado);
	insere_dados(dado, vetorNumerico,vetorInsert);
	
	printf("\n\tInsertsort Ordena...");
	tempInsertOrdena =  tempoVetorInsert(vetorInsert,dado);
	printf("\t\t\t\tPronto!");
	printf("\n\tInsertsort Embaralha  elementos...");
	desorganiza(vetorInsert,dado);
	printf("\t\tPronto!");
	printf("\n\tInsertsort quanse ordenado...");
	tempInsertQuaseOrdena = tempoVetorInsert(vetorInsert, dado);	
	printf("\t\t\tPronto!");
	printf("\n\tInsertsort decresente...");
	inverte(vetorInsert,dado);
	tempInsertDecresente = tempoVetorInsert(vetorInsert, dado);
	printf("\t\t\tPronto!");
	free(vetorInsert);
	
	// Vetor Merge
	vetorMerge = AlocaVetor(dado);
	insere_dados(dado, vetorNumerico,vetorMerge);

	printf("\n\tMergesort Ordena...");
	tempMergeOrdena =  tempoVetorMerge(vetorMerge,dado);
	printf("\t\t\t\tPronto!");
	printf("\n\tMergesort Embaralha  elementos...");
	desorganiza(vetorMerge,dado);
	printf("\t\tPronto!");
	printf("\n\tMergesort quanse ordenado...");
	tempMergeQuaseOrdena = tempoVetorMerge(vetorMerge, dado);	
	printf("\t\t\tPronto!");
	printf("\n\tMergesort decresente...");
	inverte(vetorMerge,dado);
	tempMergeDecresente = tempoVetorMerge(vetorMerge, dado);
	printf("\t\t\t\tPronto!");
	free(vetorMerge);

	
	// Mostra a tabela com os valores 
	system("cls");
	Cabecalho();
	printf("\n\n");
	Mostra_tabela(dado,tempQuickQuaseOrdena, tempQuickOrdena,tempQuickDecresente,
						  tempHeapQuaseOrdena,tempHeapOrdena,tempHeapDecresente,	
						  tempShellQuaseOrdena,tempShellpOrdena,tempShellDecresente,	
						  tempInsertQuaseOrdena,tempInsertOrdena,tempInsertDecresente,	
						  tempMergeQuaseOrdena,tempMergeOrdena,tempMergeDecresente);
	
	// Diretiva pra interronper o programa
	para();
	
}
