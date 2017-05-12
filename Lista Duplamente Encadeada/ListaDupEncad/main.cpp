
#include"ListaDupEncad.h"
#define para() {printf("\n\n\n");system("pause");}
#define limpa() {system("cls");}

void main()
{
	Lista *l = crialista();
	bool quit = true;
	int op, valor;

	while(quit)
	{

		cabecalho();
		menu_lista();
		printf("Digite a opcao:");
		scanf("%d", &op);

		switch(op)
		{
			case 1:
				{
					limpa();
					cabecalho();
					printf("\t 1.Insere Inicio\n");
					printf("Informe o valor:");
					scanf("%d", &valor);
					insere_primeiro(l,valor);
					para();
				}
			break;

			case 2:
				{
					limpa();
					cabecalho();
					printf("\t 2.Insere Fim\n");
					printf("Informe o valor:");
				    scanf("%d", &valor);
					insere_ultimo(l,valor);
					para();
				}
				break;
		
			case 3:
				{
					limpa();
					cabecalho();
					printf("\t 3.Insere Ordenado\n");
					printf("Informe o valor:");
				    scanf("%d", &valor);
					insere_ordenado(l,valor);
					para();
				}
				break;

			case 4:
				{
					limpa();
					cabecalho();
					printf("\t 4.Mostra\n");
					mostra_lista(l);
					para();
				}
				break;

			case 5:
				{
					limpa();
					cabecalho();
					printf("\t 5.Retira Inicio\n\n");
					printf("Valor removido: %d",remove_inicio(l));
					para();
				}
				break;

			case 6:
				{
					limpa();
					cabecalho();
					printf("\t 6.Retira Fim\n\n");
					printf("Valor removido: %d",remove_fim(l));
					para();

				}
				break;

			case 7:
				{
					limpa();
					cabecalho();
					printf("\t 7.Ultimo elemento\n\n");
					printf("O ultimo valor e: %d",ultimo_elemento(l));
					para();
				}
				break;

			case 8:
				{
					quit = false;
				}
				break;

		}

		limpa();
	}
	
}