#include "Triade.h"

//---------------------------------------
// Prototipations
//---------------------------------------
string iDescricao( Intervalo, Intervalo );
void MontarTriade(Nota, char, Intervalo &, Intervalo &);

//---------------------------------------
// Constructors
//---------------------------------------
Triade::Triade(){
}

Triade::Triade(const int dificuldade){
	this->Randomizar(dificuldade);
}

Triade::Triade(const Nota n,const char tt){
	this->setTriade(n,tt);
}

//---------------------------------------
// Sets
//---------------------------------------
void Triade::setInt1(const Intervalo i){
	string program="Triade::setN1(Intervalo)"; 
	if (!i.intervaloValido()){
		throw invalid_argument(program+" / intervalo invalido / " + i.Descricao());
	}

    i1 = i;
}

void Triade::setInt2(const Intervalo i){
	string program="Triade::setN2(Intervalo)"; 
	if (!i.intervaloValido()){
		throw invalid_argument(program+" / intervalo invalido / " + i.Descricao());
	}
    
	i2 = i;
}

void Triade::setTriade(const Nota n,const char tipoTriade){
	string program="Triade::setTriade(Nota, const char)"; 
	//validar nota
	if (!n.notaValida()){
		throw invalid_argument(program+" / Nota invalida / " + n.Descricao());
	}

	//validar tipoIntervalo
	if (!this->tipoTriadeValido(tipoTriade)){
		throw invalid_argument(program+" / tipo traide invalido / " + tipoTriade);
	}

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

string Triade::getTipoTriade()const
{
	string resp;

	resp += this->getInt1().DeduzirTipoIntervalo();
	resp += this->getInt2().DeduzirTipoIntervalo();

	if      (resp=="3M3m") resp = "M";
	else if (resp=="3m3M") resp = "m";
	else if (resp=="3M3M") resp = "A";
	else if (resp=="3m3m") resp = "d";
	
	return resp;
}

//---------------------------------------
// operadores
//---------------------------------------
// non-menber friend funcion
ostream &operator<<( ostream &output, const Triade &tri ){
	output << iDescricao(tri.getInt1()
			            ,tri.getInt2()
						); 
	return output;
}

//---------------------------------------
// Padrao
//---------------------------------------
void Triade::Randomizar(const int dificuldade){

	//randomizar nota
	Nota n(dificuldade);
	
	//randomizar triade
	char triade=randomizarTriade();

	MontarTriade(n,triade,i1,i2);
	setTriade(i1,i2);
}

string Triade::Descricao() const{
	return iDescricao(this->getInt1(), this->getInt2());
}

//---------------------------------------
// Publics
//---------------------------------------

bool Triade::tipoTriadeValido(const char tt)
{
	bool bAchou=false;
	char triades[QTDTRIADES];
	getTriades(triades);

	for (int i=0; i<QTDTRIADES; i++){
		if (tt == triades[i]){
			bAchou=true;
			break;
		}
	}

	return bAchou;
}

char Triade::randomizarTriade(){
	char triades[QTDTRIADES];
	getTriades(triades);
    int r=Nota::GerarInteiro(1,QTDTRIADES);
	return triades[r-1];
}

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

string iDescricao( Intervalo i1, Intervalo i2){
    string resposta="[", temp; 

	temp = i1.getN1().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = i1.getN2().Descricao() + "\t";
    if (temp!="") resposta+=temp;

    temp = i2.getN2().Descricao();
    if (temp!="") resposta+=temp;
	
	resposta+="]";

    return resposta;
}

