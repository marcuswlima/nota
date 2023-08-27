#include "Intervalo.h"

//---------------------------------------
// Prototipations
//---------------------------------------
int distanciaEmSemiTons(Nota,Nota);
void SimplificarIntervalo(Nota, Nota &);
string iDescricao( Nota, Nota );
bool validarOrientacao(const int);
//---------------------------------------
// Constructors
//---------------------------------------
Intervalo::Intervalo()
{
}

Intervalo::Intervalo(const int dificuldade){
	string program="Intervalor::Intervalo(int)"; 
	if (!Nota::dificuldadeValida(dificuldade)){
		throw invalid_argument(program+" / dificuldade invalida / " + to_string(dificuldade));
	}
	this->Randomizar(dificuldade);
}

Intervalo::Intervalo(const Nota n, const char * tipoIntervalo){
	string program="Intervalo::Intervalo(Nota,const char *)"; 
	
	//validar tipo intervalo
	if (!this->strEhIntervalo(tipoIntervalo)){
		throw invalid_argument(program+" / intervalo invalida / " + tipoIntervalo);
	}
	
	setN1(n);
	setN2(tipoIntervalo,1); //1=ascendente
}


//---------------------------------------
// Sets
//---------------------------------------
void Intervalo::setN1(const Nota n){
	string program="Intervalo::setN1(Nota)"; 
	//validar nota
	if (!n.notaValida()){
		throw invalid_argument(program+" / Nota invalida / " + n.Descricao());
	}
    
	this->n1 = n;
}

void Intervalo::setN2(Nota p_n2){
	string program="Intervalo::setN2(Nota)"; 
	//validar nota
	if (!p_n2.notaValida()){
		throw invalid_argument(program+" / Nota invalida / " + p_n2.Descricao());
	}

	SimplificarIntervalo(this->n1,p_n2);
    this->n2 = p_n2;
}

void Intervalo::setN2(const string descIntervalo, const int orientacao){

	{//validacoes
		string program="Intervalo::setN2(string,int)"; 
		//tipo intervalo
		if (!this->strEhIntervalo(descIntervalo)){
			throw invalid_argument(program+" / intervalo invalido / " + descIntervalo);
		}
		
		//orientacao
		if (!validarOrientacao(orientacao)){
			throw invalid_argument(program+" / orientacao invalida / " + to_string(orientacao));
		}

	}

	Nota n1,n2;
    int qdtNotasDoIntervaloDesejado=0, 
		qtdSemiTonsDoIntervaloDesejado=0,
		qtdSemiTonsEntreAsDuasNotas, 
		novoAcidente=0;

    /// dados do intervalo desejado
    QuantidadesIntervalo(descIntervalo,qdtNotasDoIntervaloDesejado,qtdSemiTonsDoIntervaloDesejado);

    /// encontrar nova nota
    n1 = this->getN1();
    n2 = n1.qualRelativa(qdtNotasDoIntervaloDesejado,orientacao);
    //n2.ImprimirEmTela();

    /// encontrar novo acidente
    qtdSemiTonsEntreAsDuasNotas = distanciaEmSemiTons(n1,n2);
	//cout << endl << "qtdSemiTonsEntreAsDuasNotas:"<<qtdSemiTonsEntreAsDuasNotas<<endl;
    //cout << "qtdSemiTonsDoIntervaloDesejado:"<<qtdSemiTonsDoIntervaloDesejado<<endl;
    (orientacao==1)                                                                    ?
        novoAcidente = qtdSemiTonsDoIntervaloDesejado - qtdSemiTonsEntreAsDuasNotas    :
        novoAcidente = qtdSemiTonsEntreAsDuasNotas    - qtdSemiTonsDoIntervaloDesejado ;

    novoAcidente += n1.getAcidente();

    n2.setAcidente(novoAcidente);
    //cout << "novoAcidente:"<<novoAcidente<<endl;

    this->setN2(n2);

}

//---------------------------------------
// Gets
//---------------------------------------
Nota Intervalo::getN1() const{
    return n1;
}

Nota Intervalo::getN2() const{
    return n2;
}

string Intervalo::getTipoIntervalo() const
{
    string resposta="er";
    int qtdNotas = this->getQtdTons();
    int qtdSemiTons = this->getQtdSemiTons();

//	cout << endl;
//	cout << "qtdNotas->"<< qtdNotas<< endl;
//	cout << "qdtSemitons->"<< qtdSemiTons<< endl;
//
	tRecDadosIntervalo intervalos[QTDINTERVALOS];
	getIntervalos(intervalos);

    for (int i=0; i<QTDINTERVALOS; i++){
        if ((intervalos[i].qtdNotasNaturais==qtdNotas) && (intervalos[i].qtdSemiTons==qtdSemiTons)){
            resposta = intervalos[i].tipoIntervalo;
            break; 
        }
    }
    return resposta;
}

int Intervalo::getQtdTons() const
{
    int resposta=0,
		g1 = this->getN1().getGrau(),
		g2 = this->getN2().getGrau()
		;

	bool bAscendente = (n1 < n2) ,
		 bMesmaOitava = this->getN1().getOitava() == this->getN2().getOitava()
		 ;


	if      ( (bAscendente) && (bMesmaOitava) ){
		resposta = g2 - g1 + 1;
	}else if( (bAscendente) &&!(bMesmaOitava) ){
		if (g1==g2){
			resposta = 8;
		}
		else{
			resposta = (7 - g1) +  g2 +1 ;
		}
	}else if(!(bAscendente) && (bMesmaOitava) ){
		resposta = g1 - g2 + 1;
	}else if(!(bAscendente) &&!(bMesmaOitava) ){
		resposta = (7 - g2) +  g1 + 1;
	}

    return resposta;
}

//---------------------------------------
// Padrao
//---------------------------------------
void Intervalo::Randomizar(const int dificuldade){
	//randimizar nota
    Nota n(dificuldade);

	//randomizar intervalo
	tRecDadosIntervalo intervalos[QTDINTERVALOS];
	getIntervalos(intervalos);
	int aleatorio = Nota::GerarInteiro(1,QTDINTERVALOS);

    this->setN1(n);
    this->setN2(intervalos[aleatorio-1].tipoIntervalo);
}

string Intervalo::Descricao() const{
	return iDescricao(this->getN1(),this->getN2());
}

//---------------------------------------
// Operacoes
//---------------------------------------
void Intervalo::operator=(Intervalo const& other){
	// this->  operador1
	// other.  operador2
	
	this->n1 = other.n1;
	this->n2 = other.n2;
}

// non-menber friend funcion
ostream &operator<<( ostream &output, const Intervalo &i ){
	output << iDescricao(i.getN1()
			            ,i.getN2()
						); 
	return output;
}

//---------------------------------------
// Publics
//---------------------------------------
bool Intervalo::intervaloValido()const
{
	return getN1().notaValida() && getN2().notaValida();
}

bool Intervalo::strEhIntervalo(const string str)const
{
	regex regra("^[1-8](J|M|m|A|d)$");
	smatch match;
	return regex_search(str, match, regra);
}

string Intervalo::OrientacaoEmString()const
{
	string resposta;
    if (this->getN1()==this->getN2()){
		resposta = "Unissono";
    }else{
		(this->getOrientacao()==1) ? 
			resposta = "Asc"           : 
			resposta = "Desc"          ;
    }
	return resposta;
}

void Intervalo::getIntervalos( tRecDadosIntervalo * const arr){

	static const tRecDadosIntervalo intervalos[QTDINTERVALOS]={
                               {"1J",1, 1},
                               {"2m",2, 2},
                               {"2M",2, 3},
                               {"3m",3, 4},
                               {"3M",3, 5},
                               {"4d",4, 5},
                               {"4J",4, 6},
                               {"4A",4, 7},
                               {"5d",5, 7},
                               {"5J",5, 8},
                               {"5A",5, 9},
                               {"6m",6, 9},
                               {"6M",6,10},
                               {"7d",7,10},
                               {"7m",7,11},
                               {"7M",7,12},
                               {"8J",8,13}

	};

	for (int i=0 ; i<QTDINTERVALOS ; i++){
		arr[i].tipoIntervalo    = intervalos[i].tipoIntervalo; 
		arr[i].qtdNotasNaturais = intervalos[i].qtdNotasNaturais; 
		arr[i].qtdSemiTons      = intervalos[i].qtdSemiTons; 
	}
}

//---------------------------------------
// Privates
//---------------------------------------
int Intervalo::getQtdSemiTons() const
{

	Nota n1,n2;

	n1=this->getN1();
	n2=this->getN2();
	return distanciaEmSemiTons(n1,n2);
}

int Intervalo::getOrientacao()const
{
	return (this->getN1() < this->getN2())
                 ? 1
                 : -1;
}

void Intervalo::QuantidadesIntervalo(const string descricao, int &qdtNotasNaturais, int &qtdSemiTons)const
{
    
	tRecDadosIntervalo intervalos[QTDINTERVALOS];
	getIntervalos(intervalos);

	for (int i=0; i<QTDINTERVALOS; i++){
        if (intervalos[i].tipoIntervalo==descricao){
			qdtNotasNaturais=intervalos[i].qtdNotasNaturais;
			qtdSemiTons=intervalos[i].qtdSemiTons;
            break; 
        }
    }
}

//---------------------------------------
// Internals
//---------------------------------------
int RetornarSubescrito(int n){
	int umaoitava[13]={0,1,0,2,0,3,4,0,5,0,6,0,7};
    int resposta=0;
    for (int i=1;i<=12;i++){
        if (umaoitava[i]==n){
            resposta = i;
            break; 
        }
    }
    return resposta;
}

void SimplificarIntervalo(Nota n1, Nota &n2){
	
    if (n1.getOitava()!=n2.getOitava()){

		if ( n1 < n2 ){//Ascendente
			if (n2.getGrau()>n1.getGrau()){
				n2.setOitava(n1.getOitava());
			}else{
				n2.setOitava(n1.getOitava()+1);
			}
		}else{//Decrscente
			if (n2.getGrau()>n1.getGrau()){
				n2.setOitava(n1.getOitava()-1);
			}else{
				n2.setOitava(n1.getOitava());
			}
		}
	}

}

int distanciaEmSemiTons(Nota n1,Nota n2){
    int g1   = n1.getGrau()          ,
        g2   = n2.getGrau()          ,
        i1   = RetornarSubescrito(g1),
        i2   = RetornarSubescrito(g2),
        resp = 0                     ;

//	cout << endl;
//	cout << "i1:" << i1 << endl;
//	cout << "i2:" << i2 << endl;
//	n1.ImprimirEmTela();
//	n2.ImprimirEmTela();
   
   	if (n1 < n2){ // intervalo ascendente
        if(g1 < g2){          // primeira nota com grau menor
            resp = (i2-i1+1);
        }
        else if(g1 > g2) {    // segunda nota com grau menor
            resp = (12-i1+1)+i2 ;
		}
		else if(g1==g2){
			resp=13;
        };
    }else if (n1 > n2){ // intervalo descendente
        if(g1 < g2){           // primeira nota com grau menor
            resp = (12-i2+1)+i1 ;
        }
        else if(g1 > g2) {     // segunda nota com grau menor
            resp = (i1-i2+1);
        };
    }else {  // notas idênticas
        resp=1;

    }

	resp -= n1.getAcidente();
	resp += n2.getAcidente();
    return resp;

}//distanciaEmSemitons

string iDescricao( const Nota n1 , const Nota n2){
    string resposta="";

	resposta += n1.Descricao();
	resposta += ":";
	resposta += n2.Descricao() + " ";

    return resposta;
}

bool validarOrientacao(const int o )
{
	return o == -1 || o == 1;
}
