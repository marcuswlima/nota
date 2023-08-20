#include "Triade.h"

//---------------------------------------
// Prototipations
//---------------------------------------
void MontarTriade(Nota, char, Intervalo &, Intervalo &);

//---------------------------------------
// Constructors
//---------------------------------------
Triade::Triade(){
}

Triade::Triade(const int dificuldade){
	this->Randomizar(dificuldade);
}

Triade::Triade(const Nota n,const char tipoTriade){
	this->setTriade(n,tipoTriade);
}

//---------------------------------------
// Sets
//---------------------------------------
void Triade::setInt1(const Intervalo i){
    i1 = i;
}

void Triade::setInt2(const Intervalo i){
    i2 = i;
}

void Triade::setTriade(const Nota n,const char tipoTriade){
	Intervalo i1, i2;
	MontarTriade(n,tipoTriade,i1,i2);

	setTriade(i1,i2);
}

void Triade::setTriade(const Intervalo i1, const Intervalo i2){
	this->setInt1(i1);
    this->setInt2(i2);
}

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
void Triade::Randomizar(const int dificuldade){

	//randomizar nota
	Nota n(dificuldade);
	
	//randomizar triade
	char triades[QTDTRIADES];
	getTriades(triades);
    int r=Nota::GerarInteiro(1,QTDTRIADES);
	Intervalo i1,i2;
	MontarTriade(n,triades[r-1],i1,i2);
	
	setTriade(i1,i2);
}

string Triade::Descricao() const{
    string resposta="[", temp; 

	temp = this->getFundamental().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = this->getTerca().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = this->getQuinta().Descricao();
    if (temp!="") resposta+=temp;
	
	resposta+="]";

    return resposta;
}//GerarDescricao

void Triade::ImprimirEmTela() const{
    cout << this->Descricao();
}

//---------------------------------------
// Publics
//---------------------------------------
void Triade::ImprimirTipoTriadeEmTela() const{
	cout << this->DeduzirTipoTriade();
}//ImprimirTipoTriadeEmTela
 //

void Triade::getTriades( char * arr ) {
	static const char triades[QTDTRIADES]={'M','m','d','A'};
	for (int i=0; i<QTDTRIADES; i++)
		arr[i] = triades[i];
}

//---------------------------------------
// Privates
//---------------------------------------
void Triade::ImprimirFundamentalEmTela() const{
    cout << this->getFundamental().Descricao();
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

