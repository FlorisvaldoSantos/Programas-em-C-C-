#include "node.h"

// Definiçao da classe lista, a qual é composta de nodes
class lista {
private:
   node *head;
   node *tail;
public:
	lista();
	lista(string);
	~lista();
	bool inserthead(string);
	bool removehead();
   	void show();
	bool lista::inserttail(string val);
	bool lista::removalue(string val);
	bool lista::queryvalue(string val);
	bool lista::queryterm(int a);
	bool lista::removetail();
	void lista::sobrecargas(lista &A);
	lista lista::operator+(lista &A);
	bool lista::operator==(const lista &A);
	lista lista::operator=(lista&A);
	void lista::showtwo(const lista &L);
};