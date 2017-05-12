
#include"includes.h"
#include"lista.h"

HASH *alocahash(long int tam)
{

	HASH *hash =  (HASH*)malloc(sizeof (HASH));
	
	hash->vetlistas = (Lista**)malloc( tam * sizeof(Lista*));
	
	for(long int i=0; i<tam;i++)
	{
		hash->vetlistas[i] = crialista();
	}

	hash->tam_vetorHash = (tam-1);
	hash->Colisao=0;
	
	return hash;

}

bool posiciona_hash(HASH *hash,long  int dado)
{
	int long i = (dado % hash->tam_vetorHash);// valor onde será inserido o elemento 

	if(i > hash->tam_vetorHash)// se o valor do indice for maior que o valor da tabela ele retorna erro
		return false;
	else
	{
		insere_ordenado(hash->vetlistas[i],dado,hash);
		return  true;
	}
}

float insere_hash_1(HASH *hash, long int *vetor,long int range)
{
	long int dado;
	float ret=0;
	clock_t fim =0, inicio = clock();
	srand (time (NULL));
	for(long int i=0; i< range; i++)
	{
		posiciona_hash(hash,vetor[i]);
	}
	fim = clock();
	ret = (float)(fim - inicio)/ CLOCKS_PER_SEC;
	return ret;
}
bool pesquisa_hash(HASH *hash,long int tam)
{
	
	int i = (tam % hash->tam_vetorHash);
	if(vazia(hash->vetlistas[i]))
	{
		NO *n = hash->vetlistas[i]->primeiro; 
	
		while(n != NULL)
		{
			if(tam = n->dado)
				return true;

			n->prox;	
		}
	}

	return false;

}

void montra_hash(HASH *hash)
{
	long int i = 0;
	
	printf("\n\tMostra a tabela hash:\n\n");
	printf("Tamanho da tabela: %d \n\n", hash->tam_vetorHash);

	while(i< hash->tam_vetorHash)
	{
		printf("Indice %d:   ", i);
		mostra_lista(hash->vetlistas[i]);
		
		i++;
	}
		


}



