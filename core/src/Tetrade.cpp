#include "Tetrade.h"

//----------------------------------------
// construtores
//----------------------------------------
Tetrade::Tetrade(const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const char tipoTriade, const char tipoTetrade){
	this->setTetrade(n,tipoTriade, tipoTetrade);
}

//----------------------------------------
// Sets
//----------------------------------------

void Tetrade::setTetrade(const Nota n,const char tipoTriade, const char tipoTetrade){

	Nota temp;
	string novoIntervalo = "3M";
	cout << "novoIntervalo>"<< novoIntervalo<<'\n';

	this->setTriade(n,tipoTriade);
	temp = this->getQuinta();
	this->i3.setN1(temp);
	this->i3.setN2(novoIntervalo);
}

//----------------------------------------
// Gets
//----------------------------------------
Intervalo Tetrade::getInt3() const{
	return this->i3;
}

//----------------------------------------
// padrao
//----------------------------------------
string Tetrade::Descricao() const{
    string resposta="[", saida; 

	saida = this->getFundamental().Descricao() + "\t";
    if (saida!="") resposta+=saida;

    saida = this->getTerca().Descricao() + "\t";
    if (saida!="") resposta+=saida;

    saida = this->getQuinta().Descricao() + "\t";
    if (saida!="") resposta+=saida;
	
    saida = this->getInt3().getN2().Descricao() ;
    if (saida!="") resposta+=saida;
	
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
