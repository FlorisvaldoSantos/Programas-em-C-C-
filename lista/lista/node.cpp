#include "node.h"
#include <iostream>

// Construtor padr�o 
node::node(){
   prox = NULL;
   info = "Vazio";
}

// Construto alternativo
node::node(string valor) {
   prox = NULL;
   info = valor;
}

// Retorna informa��o contida no node
string node::getinfo() {
   return info;
}

// Retorna endere�o pr�ximo elemento
node * node::getprox() {
   return prox;
}

// Atribui valor para atributo info
void node::setinfo(string valor){
   info = valor;
}

// Atribui valor para atributo pr�ximo
void node::setprox(node *p){
   prox = p;
}
