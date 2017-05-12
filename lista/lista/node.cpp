#include "node.h"
#include <iostream>

// Construtor padrão 
node::node(){
   prox = NULL;
   info = "Vazio";
}

// Construto alternativo
node::node(string valor) {
   prox = NULL;
   info = valor;
}

// Retorna informação contida no node
string node::getinfo() {
   return info;
}

// Retorna endereço próximo elemento
node * node::getprox() {
   return prox;
}

// Atribui valor para atributo info
void node::setinfo(string valor){
   info = valor;
}

// Atribui valor para atributo próximo
void node::setprox(node *p){
   prox = p;
}
