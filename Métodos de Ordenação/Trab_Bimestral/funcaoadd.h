#ifndef _funcao_
#define _funcao_

// Cabeçalho das Funções do funcaoadd.cpp
void Preenche_Vetor(long *vetor, long tam);
long *AlocaVetor(long tam);
void MostraVetor(long *vetor, long tam);
void insere_dados(long &dado, long *vetorNumerico,  long *Outrovetor);
void desorganiza(long *vetor, long dado);
void Cabecalho();
void inverte(long *vetor,long tamanho);

long porcentagem(long tamanho);


// Função que cria a linha da tabela 
void print_linha(int valor);
void Mostra_tabela(long &Qtdado,float &TmpQuickQuase, float &TmpQuickDesord, float &TmpQuickDecre
								,float &TmpHeapQuase, float &TmpHeapDesord, float &TmpHeapDecre
								,float &TmpShellQuase, float &TmpShellDesord, float &TmpShellDecre
								,float &TmpMergeQuase, float &TmpMergeDesord, float &TmpMergeDecre
								,float &TmpOutroQuase, float &TmpOutroDesord, float &TmpOutroDecre
								);
// Fim dos parametros da Função


#endif