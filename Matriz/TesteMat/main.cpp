#include"function.h"

#define para() {printf("\n\n\n");system("pause");}
#define cabe() {system("cls");cabecalho();}

void main()
{
	int op, linha, coluna, valor;
	bool quit = true;

	cabecalho();
	printf("\n\n\tInforme a quantidade de linhas: ");
	scanf("%d",&linha);
	
	MAT *mat = alocaMatriz(linha);

	while(quit)
	{
		cabe();
		menu();
		printf("\n\n\tInforme a opcao:");
		scanf("%d",&op);

		switch(op)
		{
			case 1:
				cabe();
				printf("\n\t 1.Seta Valor\n");
				printf("Informe a linha:");
				scanf("%d", &linha);
				printf("Informe a coluna:");
				scanf("%d",&coluna);
				printf("Informe o valor:");
				scanf("%d",&valor);

				if(linha < mat->tam && valor != 0 && coluna >= 0)
				{
					setaValor(mat, linha, coluna, valor);
					printf("\n\tO valor foi inserido.");
				}
				else
					printf("\n\tO valor ñao pode ser inserido.");
				para();
				break;
				
			case 2:
				cabe();
				printf("\n\t 2.Seta Nulo\n");
				printf("Informe a linha:");
				scanf("%d", &linha);
				printf("Informe a coluna:");
				scanf("%d",&coluna);
				
				if(linha < mat->tam && !vazia(mat->vet[linha]))
				{
					setaNulo(mat, linha ,coluna);
					printf("O valor foi remivido");
				}
				else
					printf("O valor da linha nao e valido\n");
				para();
				break;


			case 3:
				cabe();
				printf("\n\t 3. Mostra\n\n");
				imprimeMatriz(mat);
				para();
				break;
				
			case 4:
				cabe();
				printf("Informe a linha:");
				scanf("%d", &linha);
				printf("Informe a coluna:");
				scanf("%d",&coluna);
				if(linha < mat->tam)
					printf("\n\n\tO valor e:%d", returnvalor(mat, linha, coluna));
			
				para();
				break;

			case 5:
				cabe();
				printf("\n\t 5. Conta valores.");
				printf("\n\n\tO numero de Valores Validos e: %d ", contaValores(mat));
				para();
				break;


			case 6:
				quit = false;
				break;
		}
	}
	free(mat);
}