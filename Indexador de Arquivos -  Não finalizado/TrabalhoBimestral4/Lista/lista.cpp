#pragma once
#include "lista.h"
//#include"..\Ordenação\auxiliarordenação.h"

LISTA::LISTA()
{
	this->primeiro = NULL;
	this->ultimo = NULL;
}
// Destrutor da lista seta primeiro e ultimo como NULOS
LISTA::~LISTA()
{
	NO *p;
	p = this->primeiro;
   while(p != NULL) {
	   primeiro = p->getnext();
	   delete p;
	   p = this->primeiro;
   }
   primeiro = ultimo = NULL;
}


void LISTA::quicksort( int *vetor, int inicio, int fim){

	if(fim - inicio >0)
	{
		int aux;
		int pivot = vetor[inicio];
		int left = inicio + 1;
		int right = fim;
		 while(left < right) {
		  if(vetor[left] <= pivot) {
			 left++;
		  } else {
			 aux = vetor[left];
			 vetor[left] = vetor[right];
			 vetor[right] = aux;
			  right--;
		  }
	   }
	   if(vetor[left] > pivot) {
		  left--;
	   }
	   aux = vetor[inicio];
	   vetor[inicio] = vetor[left];
	   vetor[left] = aux;
		
	   quicksort(vetor, inicio, left-1);
	   quicksort(vetor, right,fim);
	}
}

bool LISTA::Insere(string c)
{
	
	NO *no = new NO(c);

	if(this->primeiro == NULL){
		this->primeiro = no;
		this->ultimo = no;
		return true;
	}
	else
	{
		NO  *no,*p = this->primeiro;
		while(p  != NULL && p->getstring()!= c)
		{
			no = p;
			p =  p->getnext();
		}
		 //se o caracter for igaul 
		if(p==NULL)
		{
			inseredepois(no,c);
			this->ultimo = no->getnext();
			return true;
		}
		else if(p->getstring() == c){
			p->incrementa();
			return true;
		}

	}
}
int LISTA::tamlista()
{
	NO *p = this->primeiro;
	int i =0;

	while(p!=NULL)
	{
		p = p->getnext();
		i++;
	}
	return i;
}
bool LISTA::insereprimeiro(NO *c)
{
	 
	if(vazia())
	{
		this->primeiro = c;
		this->ultimo = c;
		return true;
	}
	else
	{
		c->setprox(this->primeiro);
		this->primeiro = c ;
		return true;
	}
}

bool LISTA::inserefim(NO *c)
{
	
	if (vazia()){
		this->primeiro = this->ultimo = c;
	}
	else{
		ultimo->setprox(c);
		c->setprox(NULL);
	    ultimo = c;
	}
	return true;
}


NO* LISTA::inseredepois(NO *no,string  c)
{
	NO *p;
	p = new NO(c);
	p->setprox(no->getnext());
	no->setprox(p);
	return p;
}

bool LISTA::inseredepois(NO *no, NO * novo)
{
	novo->setprox(no->getnext());
	no->setprox(novo);
	return true;
}

bool  LISTA::insereordenado(NO *novo)
{

	if(this->vazia())
	{
		insereprimeiro(novo);
		return true;
	}
	else if(this->primeiro->getincremento() >= novo->getincremento())
	{
		insereprimeiro(novo);
		return true;
	}
	else if(this->ultimo->getincremento() <= novo->getincremento())
	{
		inserefim(novo);
		return true;
	}
	else
	{
		NO  *no,*p = this->primeiro;
		while(p != NULL && p->getincremento() < novo->getincremento())
		{
			no = p;
			p =  p->getnext();
		}
		inseredepois(no,novo);
	}
	return false;
}
NO  *LISTA::removeinicio()
{
	NO *p;
	p = primeiro;
	this->primeiro = this->primeiro->getnext();
	
	return p;
}

NO *LISTA::getlista()
{
	return this->primeiro;
}
void LISTA::inordem(NO *raiz, float total)
{
	if(raiz!=NULL)
	{
		inordem(raiz->getesquerda(), total);
		//if(raiz->getcaracter() != NULL)
		//	cout<<"\n carc:"<<raiz->getcaracter()<<"\tfreq: "<<raiz->getfrequencia(total);
		inordem(raiz->getdireita(), total);
	}
}
void LISTA::preordem(NO *raiz)
{

	if(raiz !=NULL)
	{
	/*	if(raiz->getcaracter()!=NULL)
			cout<<"\n carc:"<<raiz->getcaracter()<<"\tcod::"<<raiz->getcodificação();
		if(raiz->getesquerda()!=NULL){
			raiz->setcodificação("0");
			preordem(raiz->getesquerda());
		}
		if(raiz->getdireita()!=NULL){
			raiz->setcodificação("1");
			preordem(raiz->getdireita());*/
		//}
	}
}

void LISTA::mostracodificação(NO * raiz)
{
	if(raiz !=NULL)
	{
		mostracodificação(raiz->getesquerda());
		mostracodificação(raiz->getdireita());
		//if(raiz->getcaracter()!=NULL)
		//	cout<<"\n carc:"<<raiz->getcaracter()<<"\tcod::"<<raiz->getcodificação();
	}
}

void LISTA::posordemcodifica(NO *raiz, string value)
{
	if(raiz->getdireita()==NULL || raiz->getesquerda()== NULL){
		//	raiz->setcodificação(value);
	}
	else
	{
		posordemcodifica(raiz->getesquerda(),value +"0");
		posordemcodifica(raiz->getdireita(), value +"1");
	}
}

//void LISTA::gravacodificação(NO *raiz, ofstream &of)
//{
//	if(raiz !=NULL)
//	{
//		gravacodificação(raiz->getesquerda(), of);
//		gravacodificação(raiz->getdireita(), of);
//		//if(raiz->getcaracter()!=NULL){
//		//	of <<raiz->getcaracter()<<raiz->getcodificação()<<endl;
//		//}
//	}
//}
int  LISTA::removefim()
{
	if (this->primeiro == this->ultimo)
		removeinicio();
	else
	{
		NO *p;
		p = this->primeiro;
		while( p->getnext() != this->ultimo )
		{
			p = p->getnext();
		}
		int aux;
		aux = removedepois(p);
		this->ultimo = p;
		return aux;
	}
}

int  LISTA::removedepois(NO *n)
{
	NO *aux;
	int ret=0;
	aux = n->getnext();
	/*ret = aux->getinfo();*/
	n->setprox(aux->getnext());
	delete(aux);
	return ret;
}

void  LISTA::mostra()
{
	if(this->primeiro == NULL){
		cout<<"Lista Vazia!";
	}
	else{
		NO *p = primeiro;
		while (p != NULL && !vazia()){
			cout<<"Caracter: "<<p->getstring()<<"  -  "<<"Numero de vz: "<< p->getincremento()<<endl;
			cout.precision(4);
		//	cout<<"  Frequencia: "<<p->getfrequencia(total)<<endl;
			p = p->getnext();
		}
	}
}
bool  LISTA::vazia()
{
	if(this->primeiro == NULL)
		return true;
	else
		return false;
}

bool LISTA::gravalista(string valor){

	ofstream arquivo;
	
	arquivo.open("RAIZ_lista.txt", ios::app);

	if(vazia())
		return false;
	else{
		NO *no = this->primeiro;
		arquivo<<valor<<" - ";
		while(no != NULL){
			arquivo<<no->getstring()<<"-"<<no->getincremento()<<" ";
			//arquivo<<no->getstring()<<"-"<<no->getincremento()<<endl;
			no = no->getnext();
		}
		arquivo<<endl;
		arquivo.close();
		return true;
	}
}



bool LISTA::removenomeio(int meio)
{
	NO *no,*n = this->primeiro;
	no = n;
	/*while(n!=NULL && n->getcoluna()!=meio)
	{
		no = n;
		n = n->getnext();
	}*/
	if(n== NULL)
		return false;
	else if (n == this->primeiro)
	{
		this->removeinicio();
		return true;
	}
	else if(n == this->ultimo) 
	{
		this->removefim();
		return true;
	}
	else
	{
		this->removedepois(no);
		return true;	
	}
}

