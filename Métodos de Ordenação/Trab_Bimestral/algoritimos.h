#ifndef _algoritimos_
#define _algoritimos_

//Cocktail_sort.cpp
void cocktail_sort(int list[10]);

//Comb_sort.cpp
void combsort(long *arr, long size);

//Heapsort .cpp
void HeapSort(long *vetor, long tam);
float tempovetorHeap(long *vetorheap, long &tamanho);

//MergeSort
void mergeSort(long *vetor, long tamvetor, long *vetoraux);
void merge(long *vetor, long tamvetor,long *vetoraux);
float tempoVetorMerge(long *vetorMerge, long &tamanho);

//Insertionsort.cpp
void insertsort(long *vetor, long tam);
float tempoVetorInsert(long *vetorMerge, long &tamanho);

// Quicksort.cpp
void quicksort(long int *vetor, int inicio, int fim);
float tempovetorQuick(long *vetorQuick, long &tamanho);

// Selection_sort.cpp
void selection_sort(long *num, long tam);



//Shellsort .cpp
void shellSort(long * vet, long size);
float tempoVetorShell(long *vetorShell, long &tamanho);

#endif 