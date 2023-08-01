#include "Tetrade.h"

//----------------------------------------
// construtores
//----------------------------------------
Tetrade::Tetrade(){
}

Tetrade::Tetrade(const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const char tipoTriade, const char tipoSetima){
	this->setTriade(n,tipoTriade);
}

//----------------------------------------
// Sets
//----------------------------------------

void Tetrade::setTetrade(const Nota n,const char tipoTriade, const char tipoTetrade){
	Nota temp;
	this->setTriade(n,tipoTriade);
	temp = this->getQuinta();
	this->i3.setN1(temp);
}

//----------------------------------------
// Gets
//----------------------------------------

//----------------------------------------
// padrao
//----------------------------------------
string Tetrade::Descricao() const{
    string resposta="[", temp; 

	temp = this->getFundamental().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = this->getTerca().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = this->getQuinta().Descricao() + "\t";
    if (temp!="") resposta+=temp;
	
//    temp = this->getInt3().getN2().Descricao() + "\t";
//    if (temp!="") resposta+=temp;
	
	resposta+="]";

    return resposta;
}//GerarDescricao

//----------------------------------------
// Public
//----------------------------------------

//----------------------------------------
// Private
//----------------------------------------

//----------------------------------------
// Internals
//----------------------------------------
