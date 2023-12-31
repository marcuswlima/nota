#include "Tetrade.h"

//----------------------------------------
// construtores
//----------------------------------------
Tetrade::Tetrade()
{
}

Tetrade::Tetrade(const int dificuldade)
{
	string program="Tetrade::Tetradee(int)"; 
	if (!Nota::dificuldadeValida(dificuldade)){
		throw invalid_argument(program+" / dificuldade invalida / " + to_string(dificuldade));
	}
	this->Randomizar(dificuldade);
}

Tetrade::Tetrade(const Nota n,const char tipoTriade, const char tipoSetima)
{
	this->setTetrade(n, tipoTriade, tipoSetima);
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
	if (!this->setimaValida(tipoSetima)){
		throw invalid_argument(program+" / tipo tetrade invalida / " + tipoSetima);
	}

	//Montar triade
	this->setTriade(n,tipoTriade);//classe pai

	//Montar setima temporaria
	const char intervaloSetima[2] = {'7',tipoSetima};
	Intervalo i(n,intervaloSetima);
	
	//montar ultimo intervalo
	this->i3.setN1(this->getQuinta());
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
	output << t.Descricao();
	return output;
}

//----------------------------------------
// padrao
//----------------------------------------
string Tetrade::Descricao() const
{
    string resposta="[", saida; 

	saida = this->getFundamental().Descricao() + '\t';
    if (saida!="") resposta+=saida;

    saida = this->getTerca().Descricao()  + '\t';
    if (saida!="") resposta+=saida;

    saida = this->getQuinta().Descricao() + '\t';
    if (saida!="") resposta+=saida;
	
    saida = this->getInt3().getN2().Descricao()  ;
    if (saida!="") resposta+=saida;
	
	resposta+="]";

    return resposta;
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
