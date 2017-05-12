#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "farvore.h"

#define para system("pause");
int funarvoremain()
{
	estruturaArvore *AVL;
	int valor,menu;
	int altura;
	AVL = criaArvore();
	insereNo(AVL,5);
	insereNo(AVL,10);
	insereNo(AVL,18);
	insereNo(AVL,20);
	insereNo(AVL,35);
	insereNo(AVL,50);
	insereNo(AVL,60);
	insereNo(AVL,58);



	while(1)
	{
		system("cls");
		printf("Digite Escolha a opcao desejada\n");
		printf("Digite {1}Para Inserir\n");
		printf("Digite {2}Para Remover\n");
		printf("Digite {3}Para Imprimir PRE ORDEM\n");
		printf("Digite {4}Para Imprimir IN ORDEM\n");
		printf("Digite {5}Para Imprimir POS ORDEM\n");
		printf("Digite {6}Para Altura\n");
		printf("Digite {7}Para Buscar Elemento\n");
		printf("Digite {8}Para Sair\n");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:
				{
					printf("\nDigite o elemento a ser inserido\n");
					scanf("%d",&valor);
					insereNo(AVL,valor);
					para
				}break;
			case 2:
				{
					printf("\nDigite o elemento a ser excluido\n");
					scanf("%d",&valor);
					remove(AVL, valor);
					para
				}break;
			case 3:
				{
					printf("\nPre: ");
					imprimePre(AVL->raiz);
					para
				}break;
			case 4:
				{
					printf("\nIn: ");
					imprimeIn(AVL->raiz);
					para
				}break;
			case 5:
				{
					printf("\nPos: ");
					imprimePos(AVL->raiz);
					para
				}break;

			case 6:
				{
					altura = verificaaltura(AVL->raiz);
					printf("Altura: %d\n", altura);
					para
				}break;
			case 7:
				{
					printf("\nDigite o elemento a ser procurado:\n");
					scanf("%d",&valor);
					if(existeElemento(AVL, valor))
						printf("Existe!");
					else
						printf("Nao Existe");
				}break;
			case 8:
				{
					exit(0);
				}break;
		}
	}
	return 1;;
}
