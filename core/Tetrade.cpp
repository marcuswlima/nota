#include "Tetrade.h"

//----------------------------------------
// construtores
//----------------------------------------
Tetrade::Tetrade(const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const int dificuldade){
}

Tetrade::Tetrade(const Nota n,const char tipoTriade, const char tipoSetima){
	this->setTetrade(n,tipoTriade, tipoSetima);
}

//----------------------------------------
// Sets
//----------------------------------------
void Tetrade::setTetrade(const Nota n,const char tipoTriade, const char tipoSetima){

	Intervalo i;

	//Montar triade
	this->setTriade(n,tipoTriade);


	//Primeira nota terceiro intervalo
	this->i3.setN1(this->getQuinta());

	//Segunda nota terceiro intervalo
	i.setN1(n);
	switch (tipoSetima){
		case 'M':
			i.setN2("7M");
			break;
		case 'm':
			i.setN2("7m");
			break;
		case 'd':
			i.setN2("7d");
			break;
	}
	this->i3.setN2(i.getN2());
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

	saida = this->getFundamental().Descricao() + '\t';
    if (saida!="") resposta+=saida;

    saida = this->getTerca().Descricao() + '\t';
    if (saida!="") resposta+=saida;

    saida = this->getQuinta().Descricao() + '\t';
    if (saida!="") resposta+=saida;
	
    saida = this->getInt3().getN2().Descricao() ;
    if (saida!="") resposta+=saida;
	
	resposta+="]";

    return resposta;
}//GerarDescricao

//----------------------------------------
// Public
//----------------------------------------
void Tetrade::getSetimas(char * arr){
	static const char setimas[QTDSETIMAS]={'M','m','d'};

	for (int i=0; i<QTDSETIMAS; i++)
		arr[i]=setimas[i];
}


//----------------------------------------
// Private
//----------------------------------------

//----------------------------------------
// Internals
//----------------------------------------
