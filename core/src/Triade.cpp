#include "Triade.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////

void MontarTriade(Nota, char, Intervalo &, Intervalo &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////

Triade::Triade(){
}

Triade::Triade(int dificuldade){
	this->Randomizar(dificuldade);
}

Triade::Triade(Nota n,int tipoTriade){
	this->setTriade(n,tipoTriade);
}


Triade::Triade(Intervalo i1, Intervalo i2){
    this->setInt1(i1);
    this->setInt2(i2);
}

/////////////////////////////////////////
// Sets
/////////////////////////////////////////
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

/////////////////////////////////////////
// Gets
/////////////////////////////////////////

Intervalo Triade::getInt1(){
    return i1;
}//getInt1

Intervalo Triade::getInt2(){
    return i2;
}

Nota Triade::getFundamental(){
    return this->getInt1().getN1();
}

Nota Triade::getTerca(){
    return this->getInt1().getN2();
}

Nota Triade::getQuinta(){
    return this->getInt2().getN2();
}

/////////////////////////////////////////
// Padrão
/////////////////////////////////////////

void Triade::Randomizar(int dificuldade){

	char      tipoTriade=RandomizarTipoTriade();
	Nota      n(dificuldade);
	Intervalo i1,i2;
	
	MontarTriade(n,tipoTriade,i1,i2);
    
	this->setInt1(i1);
    this->setInt2(i2);

}//Randomizar

string Triade::GerarDescricao(){
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

void Triade::ImprimirEmTela(){
    cout << this->GerarDescricao();
}

/////////////////////////////////////////
// Implementações public
/////////////////////////////////////////

void Triade::ImprimirTipoTriadeEmTela(){
	cout << this->DeduzirTipoTriade();
}//ImprimirTipoTriadeEmTela

/////////////////////////////////////////
// Implementações privadas
/////////////////////////////////////////

void Triade::ImprimirFundamentalEmTela(){
    cout << this->getFundamental().Descricao();
}

char Triade::RandomizarTipoTriade(){
    int aleatorio=GerarInteiro(1,4);

	aleatorio--; //ajuste indice

	return this->tiposTriade[aleatorio];
}


string Triade::DeduzirTipoTriade(){
	string resp="";

	resp += this->getInt1().DeduzirTipoIntervalo();
	resp += this->getInt2().DeduzirTipoIntervalo();

	if      (resp=="3M3m") resp = "M";
	else if (resp=="3m3M") resp = "m";
	else if (resp=="3M3M") resp = "A";
	else if (resp=="3m3m") resp = "d";
	
	return resp;
}


/////////////////////////////////////////
// Implementações Internas
/////////////////////////////////////////
void MontarTriade(Nota n, char tipoTriade, Intervalo &i1, Intervalo &i2){

	Nota temp;

	i1.setN1(n);
	if (tipoTriade=='M'){
		i1.setN2("3M");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3m");
	}else if (tipoTriade=='m'){
		i1.setN2("3m");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3M");
	}else if (tipoTriade=='A'){
		i1.setN2("3M");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3M");
	}else if (tipoTriade=='d'){
		i1.setN2("3m");
		temp.setOitava(i1.getN2().getOitava());
		temp.setGrau(i1.getN2().getGrau());
		temp.setAcidente(i1.getN2().getAcidente());
		i2.setN1(temp);
		i2.setN2("3m");
	}

}

