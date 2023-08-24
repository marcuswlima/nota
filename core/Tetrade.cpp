#include "Tetrade.h"

//----------------------------------------
// prototipacoes
//----------------------------------------
string iDescricao(Nota , Nota , Nota , Nota );
//----------------------------------------
// construtores
//----------------------------------------
Tetrade::Tetrade()
{
}

Tetrade::Tetrade(const int dificuldade)
{
	this->Randomizar(dificuldade);
}

Tetrade::Tetrade(const Nota n,const char tipoTriade, const char tipoSetima)
{
	this->setTetrade(n,tipoTriade, tipoSetima);
}

//----------------------------------------
// Sets
//----------------------------------------
void Tetrade::setTetrade(const Nota n,const char tipoTriade,const char tipoSetima)
{

	string program="Tetrade::setTetrade(Nota, char, char)"; 
	//validar nota
	if (!n.notaValida()){
		throw invalid_argument(program+" / Nota invalida / " + n.Descricao());
	}

	//validar tipoIntervalo
	if (!this->tipoTriadeValido(tipoTriade)){
		throw invalid_argument(program+" / tipo traide invalido / " + tipoTriade);
	}

	//validar tipoSetima
	if (!this->setimaValida(tipoTriade)){
		throw invalid_argument(program+" / tipo traide invalido / " + tipoSetima);
	}

	Intervalo i;

	//Montar triade
	this->setTriade(n,tipoTriade);//classe pai

	//Montar setima
	this->i3.setN1(this->getQuinta());
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
Intervalo Tetrade::getInt3() const
{
	return this->i3;
}

//----------------------------------------
// operacoes
//----------------------------------------
ostream &operator<<(ostream &output, const Tetrade &t)
{
	output << iDescricao(t.getFundamental()
		                ,t.getTerca()
					    ,t.getQuinta()
					    ,t.getInt3().getN2()
						);
	return output;
}

//----------------------------------------
// padrao
//----------------------------------------
string Tetrade::Descricao() const
{
    return iDescricao(this->getFundamental()
			         ,this->getTerca()
					 ,this->getQuinta()
					 ,this->getInt3().getN2()
					 );
}//GerarDescricao

void Tetrade::Randomizar(const int dificuldade){

	Nota n(dificuldade);//randimizar nota
	char triade = Triade::randomizarTriade();
	char setima = randomizarSetima();

	this->setTetrade(n,triade,setima);
}

//----------------------------------------
// Public
//----------------------------------------
bool Tetrade::setimaValida(const char setima){
	bool bAchou=false;
	char setimas[QTDSETIMAS];
	getSetimas(setimas);

	for (int i=0; i<QTDSETIMAS; i++){
		if (setima == setimas[i]){
			bAchou=true;
			break;
		}
	}

	return bAchou;
}

char Tetrade::randomizarSetima(){
	char setimas[QTDSETIMAS];
	getSetimas(setimas);
	int r=Nota::GerarInteiro(1,QTDSETIMAS);
	return setimas[r-1];
}

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
string iDescricao(Nota nf, Nota n3, Nota n5, Nota n7) 
{
    string resposta="[", saida; 

	saida = nf.Descricao() + '\t';
    if (saida!="") resposta+=saida;

    saida = n3.Descricao() + '\t';
    if (saida!="") resposta+=saida;

    saida = n5.Descricao() + '\t';
    if (saida!="") resposta+=saida;
	
    saida = n7.Descricao() ;
    if (saida!="") resposta+=saida;
	
	resposta+="]";

    return resposta;
}//GerarDescricao
