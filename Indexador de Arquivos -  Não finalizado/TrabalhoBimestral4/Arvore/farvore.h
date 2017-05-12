typedef struct estruturaNo
{
       int dado; //informaçao contida na lista
	   int fb;
	   int altura;
	   struct estruturaNo *esquerda; 
       struct estruturaNo *direita; 
}estruturaNo;     
typedef struct
{
	estruturaNo *raiz; // ponteiro para localizar na lista.
}estruturaArvore;
//--------funçoes--------//
void insereNo(estruturaArvore *AVL, int valor);
void imprimePre(estruturaNo *No);
void imprimeIn(estruturaNo *No);
void imprimePos(estruturaNo *No);
bool existeElemento(estruturaArvore *AVL, int elemento);
void remove(estruturaArvore *AVL, int elemento);
int verificaaltura(estruturaNo *No);
//----------------//
estruturaNo* alocanovoNo(int info);
estruturaArvore* criaArvore();
int calcula_FB(estruturaNo *No);
void percorreAVL(estruturaNo *aux,estruturaNo *aux2, estruturaArvore *AVL);
void rotaciona_esquerda(estruturaNo *p, estruturaArvore *AVL);
void rotaciona_direita(estruturaNo *p, estruturaArvore *AVL);
void Verifica( estruturaNo *aux, estruturaArvore *AVL );
estruturaNo* PegaAntecessor(estruturaArvore *AVL, estruturaNo *No);
