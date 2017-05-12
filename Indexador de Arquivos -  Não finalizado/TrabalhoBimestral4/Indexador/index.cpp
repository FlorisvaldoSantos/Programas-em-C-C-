
#include"index.h"


INDEX::INDEX(){
	
	this->hash_index = NULL;
	this->colisao =NULL;
}
INDEX::INDEX(string palavra, int frequencia){

	this->token->setstring(palavra);
	this->token->setfrequencia(frequencia);
	this->hash_index = NULL;
	this->colisao =NULL;
	
}
INDEX::~INDEX(){

	delete this->token;
	delete this->hash_index;
}
bool INDEX::inserehash(HASH *hash){
	
	if(this->hash_index == NULL){
		this->hash_index = hash;
		return true;
	}
	else{
		this->hash_index->setproximo(hash);
		this->colisao++;
		return true;
	}
}
bool INDEX::revovehash(string nomehash){
	
	if(this->hash_index== NULL){
		return false;
	}
	else if(this->hash_index->getname() == nomehash){
		delete this->hash_index;
		return true;
	}
	else{
		HASH *aux = this->hash_index;
		while(aux != NULL && aux->getname() != nomehash){
			aux = aux->getproximo();
			// fazer um remove depois;
			return true;
		}
	}
}