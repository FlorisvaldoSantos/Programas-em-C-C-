#pragma once
#include"includes.h"
/*
  Aluno: Florisvaldo Santos
  Curso: Ci�ncia da Computa��o
  Turma: 4� per�odo  U
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