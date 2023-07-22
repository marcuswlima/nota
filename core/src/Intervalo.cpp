#include "Intervalo.h"

/////////////////////////////////////////
// Prototipações
/////////////////////////////////////////
int distanciaEmSemiTons(Nota,Nota);
void SimplificarIntervalo(Nota, Nota &);

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Intervalo::Intervalo()
{
}

Intervalo::Intervalo(int dificuldade){
	this->Randomizar(dificuldade);
}

Intervalo::Intervalo(Nota n1, Nota n2)
{
    this->setN1(n1);
    this->setN2(n2);
}
    
/////////////////////////////////////////
// Sets
/////////////////////////////////////////
void Intervalo::setN1(Nota n){
    this->n1 = n;
}

void Intervalo::setN2(Nota in_n2){
    SimplificarIntervalo(this->n1,in_n2);
    this->n2 = in_n2;
}

void Intervalo::setN2(string descIntervalo, int orientacao){

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

/////////////////////////////////////////
// Gets
/////////////////////////////////////////

Nota Intervalo::getN1(){
    return n1;
}

Nota Intervalo::getN2(){
    return n2;
}

/////////////////////////////////////////
// Padrão
/////////////////////////////////////////
void Intervalo::Randomizar(int dificuldade){
    Nota n;

    n.Randomizar(dificuldade);
    this->setN1(n);
    n.Randomizar(dificuldade);
    this->setN2(n);
}

string Intervalo::Descricao(){
    string resposta="";

    if (this->getN1().Descricao()!=""){
        resposta += this->getN1().Descricao();
        resposta += ":";
        resposta += this->getN2().Descricao() + " ";
    }
    else
        resposta += "Primeira nota em branco";

    return resposta;

}//Intervalo::Descricao


void Intervalo::ImprimirEmTela(){
    cout << this->Descricao() << " ";
}


/////////////////////////////////////////
// Implementation public
/////////////////////////////////////////

string Intervalo::DeduzirTipoIntervalo(){
    string resposta="er";
    int qtdNotas = this->DeduzirQdtTons();
    int qtdSemiTons = this->DeduzirQtdSemiTons();

//	cout << endl;
//	cout << "qtdNotas->"<< qtdNotas<< endl;
//	cout << "qdtSemitons->"<< qtdSemiTons<< endl;

    for (int i=0; i<=15; i++){
        if ((DadosIntervalo[i].qtdNotasNaturais==qtdNotas) && (DadosIntervalo[i].qtdSemiTons==qtdSemiTons)){
            resposta = DadosIntervalo[i].tipoIntervalo;
            break; 
        }
    }
    return resposta;
}

bool Intervalo::strEhIntervalo(string str){
	regex regra("^[1-8](J|M|m|A|d)$");
	smatch match;
	return regex_search(str, match, regra);
}

string Intervalo::OrientacaoEmString(){
	string resposta;
    if (this->getN1()==this->getN2()){
		resposta = "Unissono";
    }else{
		(this->DeduzirOrientacao()==1) ? 
			resposta = "Asc"           : 
			resposta = "Desc"          ;
    }
	return resposta;
}

void Intervalo::getTiposIntervalo(string * const arr){
	for (int i=0; i<16; i++){
		arr[i]=this->DadosIntervalo[i].tipoIntervalo;
	}
}
/////////////////////////////////////////
// Implementation private
/////////////////////////////////////////

int Intervalo::DeduzirOrientacao(){
	return (this->getN1() < this->getN2())
                 ? 1
                 : -1;
}

int Intervalo::DeduzirQdtTons(){
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

int Intervalo::DeduzirQtdSemiTons(){

	Nota n1,n2;

	n1=this->getN1();
	n2=this->getN2();
	return distanciaEmSemiTons(n1,n2);
}


void Intervalo::ImprimirOrientacaoEmTela(){
	cout << this->OrientacaoEmString();
}

void Intervalo::ImprimirTipoIntervaloEmTela(){
	cout << this->DeduzirTipoIntervalo() ;
}

void Intervalo::ImprimirQdtTonsEmTela(){
    cout << this->DeduzirQdtTons() << " ";
}

void Intervalo::ImprimirQtdSemiTonsEmTela(){
    cout << this->DeduzirQtdSemiTons() << " ";
}

void Intervalo::QuantidadesIntervalo(string descricao, int &qdtNotasNaturais, int &qtdSemiTons){
    
	for (int i=0; i<=15; i++){
        if (this->DadosIntervalo[i].tipoIntervalo==descricao){
			qdtNotasNaturais=this->DadosIntervalo[i].qtdNotasNaturais;
			qtdSemiTons=this->DadosIntervalo[i].qtdSemiTons;
            break; 
        }
    }
}

/////////////////////////////////
// Implementações Internas
// //////////////////////////////

int umaoitava[13]={0,1,0,2,0,3,4,0,5,0,6,0,7};
int RetornarSubescrito(int n){
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

