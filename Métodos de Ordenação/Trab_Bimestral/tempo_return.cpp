
#include"includes.h"


float tempovetorQuick(long *vetorQuick, long &tamanho)
{
	float tempo=0;
	clock_t tempo_fim,tempo_ini = clock();
	// Inicio é o parametro onde se inicia com 0 (primeira posição)
	quicksort(vetorQuick, 0,tamanho);
	tempo_fim = clock();
	tempo = (float)(tempo_fim - tempo_ini)/CLOCKS_PER_SEC;
	
	return tempo;
}


float tempovetorHeap(long *vetorheap, long &tamanho)
{
	float tempo=0;
	clock_t tempo_fim,tempo_ini = clock();
	HeapSort(vetorheap,tamanho);
	tempo_fim = clock();
	tempo = (float)(tempo_fim - tempo_ini)/CLOCKS_PER_SEC;
	
	return tempo;
}

float tempoVetorShell(long *vetorShell, long &tamanho)
{
	float tempo=0;
	clock_t tempo_fim,tempo_ini = clock();
	shellSort(vetorShell,tamanho);	
	tempo_fim = clock();
	tempo = (float)(tempo_fim - tempo_ini)/CLOCKS_PER_SEC;
	
	return tempo;
}

float tempoVetorInsert(long *vetorInsert, long &tamanho)
{
	float tempo=0;
	clock_t tempo_fim,tempo_ini = clock();
	insertsort(vetorInsert,tamanho);
	tempo_fim = clock();
	tempo = (float)(tempo_fim - tempo_ini)/CLOCKS_PER_SEC;
	
	return tempo;
}


float tempoVetorMerge(long *vetorMerge, long &tamanho)
{
	long *aux = AlocaVetor(tamanho);
	float tempo=0;
	clock_t tempo_fim,tempo_ini = clock();
	mergeSort(vetorMerge,tamanho,aux);
	tempo_fim = clock();
	tempo = (float)(tempo_fim - tempo_ini)/CLOCKS_PER_SEC;
	
	return tempo;
}
