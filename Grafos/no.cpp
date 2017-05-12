#pragma once
#include"includes.h"
/*
  Aluno: Florisvaldo Santos
  Curso: Ciência da Computação
  Turma: 4º período  U
*/

NO::NO()
{
	this->nome = "NO";
}
string NO::getname()
{
	return this->nome;
}
void NO::setname(string cmd)
{
	this->nome = cmd;
}
NO::~NO()
{
	//delete;
}