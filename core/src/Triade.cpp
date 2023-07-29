#include "Triade.h"

//---------------------------------------
// Prototipations
//---------------------------------------
void MontarTriade(Nota, char, Intervalo &, Intervalo &);

//---------------------------------------
// Constructors
//---------------------------------------
Triade::Triade(){
	this->popularTipoTriade();
}

Triade::Triade(int dificuldade){
	this->popularTipoTriade();
	this->Randomizar(dificuldade);
}

Triade::Triade(Nota n,int tipoTriade){
	this->popularTipoTriade();
	this->setTriade(n,tipoTriade);
}


Triade::Triade(Intervalo i1, Intervalo i2){
	this->popularTipoTriade();
    this->setInt1(i1);
    this->setInt2(i2);
}

//---------------------------------------
// Sets
//---------------------------------------
void Triade::setInt1(Intervalo i){
    i1 = i;
}

void Triade::setInt2(Intervalo i){
    i2 = i;
}

void Triade::setTriade(Nota n,int tipoTriade){
	Intervalo i1, i2;

	MontarTriade(n,tipoTriade,i1,i2);
    
	this->setInt1(i1);
    this->setInt2(i2);
}//setTriade(Nota n,int tipoTriade)

//---------------------------------------
// Gets
//---------------------------------------
Intervalo Triade::getInt1()const{
    return i1;
}//getInt1

Intervalo Triade::getInt2()const
{
    return i2;
}

Nota Triade::getFundamental() const{
    return this->getInt1().getN1();
}

Nota Triade::getTerca() const{
    return this->getInt1().getN2();
}

Nota Triade::getQuinta()const{
    return this->getInt2().getN2();
}

//---------------------------------------
// Padrao
//---------------------------------------
void Triade::Randomizar(int dificuldade){

	char      tipoTriade=RandomizarTipoTriade();
	Nota      n(dificuldade);
	Intervalo i1,i2;
	
	MontarTriade(n,tipoTriade,i1,i2);
    
	this->setInt1(i1);
    this->setInt2(i2);

}//Randomizar

string Triade::GerarDescricao() const{
    string resposta="[", temp; 

	temp = this->getFundamental().Descricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getTerca().Descricao() + "-";
    if (temp!="") resposta+=temp;

    temp = this->getQuinta().Descricao();
    if (temp!="") resposta+=temp;
	
	resposta+="]";

    return resposta;
}//GerarDescricao

void Triade::ImprimirEmTela() const{
    cout << this->GerarDescricao();
}

//---------------------------------------
// Publics
//---------------------------------------
void Triade::ImprimirTipoTriadeEmTela() const{
	cout << this->DeduzirTipoTriade();
}//ImprimirTipoTriadeEmTela

//---------------------------------------
// Privates
//---------------------------------------
void Triade::ImprimirFundamentalEmTela() const{
    cout << this->getFundamental().Descricao();
}

char Triade::RandomizarTipoTriade(){
    int aleatorio=GerarInteiro(1,4);

	aleatorio--; //ajuste indice

	return this->tiposTriade[aleatorio];
}

string Triade::DeduzirTipoTriade() const{
	string resp="";

	resp += this->getInt1().DeduzirTipoIntervalo();
	resp += this->getInt2().DeduzirTipoIntervalo();

	if      (resp=="3M3m") resp = "M";
	else if (resp=="3m3M") resp = "m";
	else if (resp=="3M3M") resp = "A";
	else if (resp=="3m3m") resp = "d";
	
	return resp;
}

void Triade::popularTipoTriade(){
	this->tiposTriade[0]='M';
	this->tiposTriade[1]='m';
	this->tiposTriade[2]='d';
	this->tiposTriade[3]='A';
}

//---------------------------------------
// Internals
//---------------------------------------
void MontarTriade(Nota n, char tipoTriade, Intervalo &i1, Intervalo &i2){

	Nota temp;

	i1.setN1(n);
	
	if (tipoTriade=='M' || tipoTriade=='A')
		i1.setN2("3M");
	else if (tipoTriade=='m' || tipoTriade=='d')
		i1.setN2("3m");
	
	temp = i1.getN2();//Default Memberwise assignment
	i2.setN1(temp);

	if (tipoTriade=='m' || tipoTriade=='A')
		i2.setN2("3M");
	else if (tipoTriade=='M' || tipoTriade=='d')
		i2.setN2("3m");

}

