#include "lista.h"
#include <iostream>
#include <stdio.h>

using namespace std;

// Construtor padrão 
lista::lista(){
   head = tail = NULL;
}

// Construtor alternativo
lista::lista(string val){
    node *p = new node(val);
	head = tail = p;
}

// Destrutor - apaga a lista toda
lista::~lista(){
   node *p;
   p = head;
   while (p != NULL) {
	   head = p->getprox();
	   delete p;
	   p = head;
   }
   head = tail = NULL;
}

// Insere elemento no início da lista
bool lista::inserthead(string val){
	node *p = new node(val);
    if (p == NULL) return false;
	if (head == NULL)
		head = tail = p;
	else {
		p->setprox(head);
	    head = p;
	}
	return true;
}

// Remove elemento do início da lista
bool lista::removehead(){
     node *p;
	 if (head == NULL){
		 cout<<"Lista Vazia!";
		 return false;
	 }
	 p = head;
	 head = p->getprox();
	 delete p;
         if (head == NULL) tail = NULL;
         return true;
}
 
// Mostra a lista
void lista::show(){
	node *p;
	p = head;
	int i=1;
	if(p==NULL){
		cout<<"Lista Vazia!";
	}
	else{
		while (p != NULL){
			cout <<i <<". ";
			cout<< p->getinfo() << endl;
			p = p->getprox();
			i++;
		}
	}
}

void lista::showtwo(const lista &L){
	
	node *p;
	p = L.head;
	int i=1;

	if(p==NULL){
		cout<<"Lista Vazia!";
	}
	else{
		while (p != NULL){
			cout <<i <<". ";
			cout<< p->getinfo() << endl;
			p = p->getprox();
			i++;
		}
	}
}

// Insere no fim da lista
bool lista::inserttail(string val){
	
	node *p = new node(val);
	
	if (p == NULL){
		return false;
	}
	if (head == NULL){
		head = tail = p;
	}
	else{
		tail->setprox(p);
		p->setprox(NULL);
	    tail = p;
	}
	return true;
}

bool lista::removetail(){

	node *p, *aux;
	if (head == NULL){
		return false;
	}
	else if (head->getprox() == NULL){
		 delete head;
		 head = NULL;
		 tail = NULL;
	 }
	 else{
		
		 p = head;
		aux = tail;
		while(p->getprox() != tail){
			p = p->getprox();
		}
		
		p->setprox(NULL);
		delete aux;
		tail = p;
	 }

     return true;
}

//remove por valor
bool lista::removalue(string val){
  
	node *p, *aux;
	if (head == NULL){
		return false;
	}
	p = head;
	aux = NULL;
	while(p != NULL){
		
		if(p->getinfo() == val){
			if(aux == NULL) head = p->getprox();
			else aux->setprox(p->getprox());
			delete p;
			return true;
		}

		aux = p;
		p = p->getprox();

	 }

     return true;
}

// Consulta elemento dado o valor
bool lista::queryvalue(string val){
	
	bool cont = false;
	int i = 0;
	node *p;
	
	if (head == NULL){
		return false;
	}
	p = head;
	while (p != NULL){
		i++;
		if(p->getinfo() == val){
			cont = true;
			cout<<"\n" << i << ". " << p->getinfo() << endl;
		}
		p = p->getprox();
	}

	if (cont == false){
		cout <<" Elemennto enexistente.\n";
		return false;
	}

	return true;

}                                                                                                                                                                                                                              
// Consulta o e-nésimo termo
bool lista::queryterm(int a){
	
	bool cond = false;
	int cont = 0;
	node *p;
	
	if (head == NULL){
		return false;
	}
	p = head;
	
	while (p != NULL){
		cont++;
		if (cont == a){
			cond = true;
			cout << cont <<". "<< p->getinfo() << endl;
		}
		p = p->getprox();
	}

	if (cond == false){
		cout <<" Elemennto enexistente.\n";
	}

	return true;
}



lista lista::operator +(lista&A){
   
	lista Aux;

	node *ptr = this->head;
	
	while(ptr != NULL){
		Aux.inserttail(ptr->getinfo());
		ptr = ptr->getprox();
	}
	ptr = A.head;
    
	while(ptr!= NULL){
        Aux.inserttail(ptr->getinfo());
        ptr = ptr->getprox();
    }
    
	return Aux; 
}


bool lista::operator==(const lista &A){
	
	node *p, *q; 
	p = head; 
	q = A.head;

	if ((p == NULL && q != NULL) || (p != NULL && q == NULL)){
		return false;
	}

	while(p != NULL && q != NULL){

		if(p->getinfo() == q->getinfo()){
			p = p->getprox();
			q = q->getprox();
		}
		else{ 
			return false;//diferentes
		}
	}
	return true;//iguais
}


lista lista::operator = (lista &L){
 
	/*if(head != NULL){
		node *p = head;
		while(p!= NULL){
			removehead();
		}
	}*/
	node *ptr = L.head;
	
	while(ptr != NULL){	
		this->inserttail(ptr->getinfo());
		ptr = ptr->getprox();
	}
		
	return *this;
}
/*

lista lista: perator +(lista add){
    lista Aux;
	node *ptr = this->head;
	while(ptr != NULL){
		Aux.inserttail(ptr->getinfo());
		ptr = ptr->getprox();
	}
	ptr = add.head;
    while(ptr!= NULL){
        Aux.inserttail(ptr->getinfo());
        ptr = ptr->getprox();
    }
    return Aux; 
}

lista& lista: perator =(const lista add){
	if(head != NULL){
		node *p = head;
		while(p!= NULL){
			removehead();
		}
	}
	node *ptr = add.head;
	while(ptr != NULL){
		this->inserttail(ptr->getinfo());
		ptr = ptr->getprox();
	}	
		
	return *this;
}


*/