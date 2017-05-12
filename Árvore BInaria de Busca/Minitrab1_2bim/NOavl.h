#ifndef _NOavl_
#define _NOavl_

#include"Main.h"


typedef struct NOavl
{

	int VALOR;
	NOavl *esqueda, *direita;
	
};

typedef struct Avl
{
	NOavl *raiz;
};



#endif 