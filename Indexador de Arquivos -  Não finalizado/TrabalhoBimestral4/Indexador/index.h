#pragma once

#include<iostream>
#include<string>
#include<fstream>
#include"..\Frequencia\frequencia.h"
#include"..\Hash\hash.h"

using namespace std;

class INDEX{

private:

	int colisao;
	FREQUENCIA *token;
	HASH *hash_index;
	
public:

	INDEX();
	INDEX(string palavra, int frequencia);
	~INDEX();
	bool inserehash(HASH *hash);
	bool revovehash(string nomehash);	
};
