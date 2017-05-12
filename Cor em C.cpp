
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

void main()
{
	int escolha = 0;
	HANDLE hOut;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN);
	printf("Instrucao => %s %s %s\n\n"/*,print[0], print[1], print[2]*/);
	
	SetConsoleTextAttribute(hOut,FOREGROUND_RED | 
                            FOREGROUND_GREEN | 
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);

	printf("REGISTRADORES:\n");
	printf("-----------------------\n\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_RED  | FOREGROUND_INTENSITY);

	/*printf("AL => %d \t AH => %d\n",(char)eu->regs->al, (char)eu->regs->ah);
	printf("AX => %d\n" , (char)converte(eu->regs->ah, eu->regs->al));
	printf("BL => %d \t BH => %d\n",(char)eu->regs->bl, (char)eu->regs->bh);
	printf("CL => %d \t CH => %d\n",(char)eu->regs->cl, (char)eu->regs->ch);
	printf("DL => %d \t DH => %d\n\n",(char)eu->regs->dl, (char)eu->regs->dh);*/

	SetConsoleTextAttribute(hOut,FOREGROUND_RED | 
                            FOREGROUND_GREEN | 
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);
	
	printf("FLAGS:\n");
	printf("-----------------------\n\n");
	SetConsoleTextAttribute(hOut,FOREGROUND_GREEN  | FOREGROUND_INTENSITY);
	printf("Overflow=>\t%d \nCarry =>\t%d\n"/*,eu->flags->OF, eu->flags->CF*/);
	printf("Sinal=>\t%d\nZero =>\t%d\n"/*,eu->flags->SF, eu->flags->ZF*/);
	printf("Execucao passo-a-passo=>\t%d\n\n"/*,eu->flags->TF*/);

    SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	
	printf("IP => %hd\n\n"/*, biu->ip*/);

	/*if(eu->regs->sp < eu->regs->bp)
		printf("PILHA => VAZIA\n");
	else
		printf("PILHA => %d\n\n", converte(memory[eu->regs->sp],memory[eu->regs->sp+1]));

	if(v.topo>0)
	{
		printf("Variaveis\n");
		printf("Endereco de memoria  Valor Atual:\n");
		for(int i=0; i<v.topo; i++)
			if(v.var[i]%2 != 0)
				printf("\t@%d\t\t%d\n", v.var[i], (char)memory[v.var[i]]);
			else
				printf("\t@%d\t\t%d\n",v.var[i], (char)converte(memory[v.var[i]], memory[v.var[i]+1]));

	}*/
	SetConsoleTextAttribute(hOut,FOREGROUND_RED | 
                            FOREGROUND_GREEN | 
                            FOREGROUND_BLUE |
                            FOREGROUND_INTENSITY);

	system("pause");
}