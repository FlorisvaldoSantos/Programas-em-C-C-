#include"hash.h"
#include"..\processamento_texto\processamento_texto.h"


HASH::HASH(int tamanho){

	this->tamanho = tamanho;
	this->nomearquivo.clear();
	this->hash = new FREQUENCIA[tamanho];
	this->proximo = NULL;
	this->colisao =NULL;
	///
	
}
HASH::~HASH(){

	delete this->hash;
}
	
// funções principais
bool HASH::inserepalavras(char *arquivo, int frequencia, string nome){

	string palavra;
	unsigned int posicao = sdbm(arquivo);
	posicao = (posicao % this->tamanho);
	palavra = arquivo;
	// insere o primeiro elemento na tabela
	if(this->hash[posicao].getstring().length() == NULL){
		this->hash[posicao].setstring(palavra);
		this->hash[posicao].setfrequencia(frequencia);
		cout<<posicao<<this->hash[posicao].getstring()<<"-"<<this->hash[posicao].getfrequancia()<<endl;
		return true;
	}
	else{// quando colide valores 
		FREQUENCIA *novo =  new FREQUENCIA();
		novo->setstring(palavra);
		novo->setfrequencia(frequencia);
		this->hash[posicao].setaproximo(novo);
		//cout<<posicao<<this->hash[posicao].getstring()<<"-"<<this->hash[posicao].getfrequancia()<<"\t - \t";
		//cout<<novo->getstring()<<"-"<<novo->getfrequancia()<<endl;
		incrementacolisao();
		return true;
	}
	return false;
}
bool HASH::removedocumento(string arquivo){
	
	// verificar se há um arquivo que esteja a área de stouro
	if(this->nomearquivo == arquivo){
	/*	if(){
		
		}*/
	}
	return true;
}
bool HASH::mostradocumento(){
	return true;
}
bool HASH::pesquisa(char *arquivo){

	unsigned int posicao = sdbm(arquivo);
	posicao = (posicao % this->tamanho);
	if(strcmp(this->hash[posicao].getstring().c_str(),arquivo)==0){
		//calculo do coseno
	}
	return true;
}
double HASH::cosseno(FREQUENCIA *vetpesquisa, int tam, FREQUENCIA *vetarquivo){


	double  produto =0,somatorio =0, similaridade =0;
	//similaridade = cosseno( produtovetorial( X, Y ) / raiz((somatorio(Xi²) + ( somatorio(Xi²)) )
	for(int i=0; i<tam;i++){
		produto += vetpesquisa[i].getfrequancia() * vetarquivo[i].getfrequancia();
	}
	for(int i=0; i<tam;i++){
		somatorio += ((pow(vetpesquisa[i].getfrequancia(), 2)) *(pow(vetarquivo[i].getfrequancia(),2)));
	}
	similaridade = cos(( produto / sqrt(somatorio)) *PI/180);
	
	return similaridade;
}
int HASH::sdbm(char  *str){

        unsigned int hash = 0;
        unsigned int c;

        while (c = *str++)
            hash = c + (hash << 6) + (hash << 16) - hash;

       return hash;
 }
// 
bool HASH::setanomedocumento(string nome){

	if(this->nomearquivo.length() != NULL){
		this->nomearquivo = nome;
		return true;
	}
	else
		return false;
}
bool HASH::setproximo(HASH *hash){
	
	if(this->proximo == NULL){
		this->proximo = hash;
		return true;
	}
	else
		return false;
}
void HASH::incrementacolisao(){
	
	this->colisao++;
}
HASH *HASH::getproximo(){
	
	return this->proximo;
}
string HASH::getname(){
	
	return this->nomearquivo;
}
string HASH::palavraindexadora(){
	
	string palavra;
	int var=this->hash->getfrequancia();
	for(int i=1; i< this->tamanho-1; i++){
		if(this->hash->getfrequancia() > var){
			var = this->hash->getfrequancia();
		}
	}
	return palavra;
}