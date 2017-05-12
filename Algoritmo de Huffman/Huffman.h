
void atualizaQtDado(Lista *l,char c);
int calculaTotalElementos(FILE *p,Lista *l);
Lista* calculaFrequenciaElementos(FILE *p,Lista *l);
void codigoHuffman(Lista *l);
void geraCodigosCodificacao(No *raiz);
//Cria Codigos e seta nos nos individualmente
void percorreArvore(No *raiz,No *pai,bool esq);
void retornaCodigo(No *raiz,No *pai,char c,string *str,bool esq);

//Funcoes para codificacao arquivo
string retornaCodigo(No *raiz,No *pai,char c,bool esq);
string retornaCodigoGUI(No *raiz,char c);
FILE *geraArquivoCodificado(FILE *arq,Lista *l);

//Funcoes para decodificacao arquivo
void retornaCaractereDecodificado(No *raiz,No *pai,char *c,string str,bool esq);
char *retornaCaractereDecodificadoGUI(No* raiz,string str2);
void geraDecodificacaoArquivo(FILE *arq,Lista *l);