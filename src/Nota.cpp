#include "Nota.h"

/////////////////////////////////////////
// Prototipacoes
/////////////////////////////////////////
bool notaValida( int, int, int);
string iDescricao( int, int, int);
void MensagemErro( int,int, int, bool);
bool NotaIgual(int , int , int , int , int , int );
bool PrimeiraMaior(int, int , int , int , int , int );
bool SegundaMaior(int, int , int , int , int , int );

/////////////////////////////////////////
// construtores
/////////////////////////////////////////
Nota::Nota()
{
} 

Nota::Nota(int dificauldade)
{
    this->Randomizar(dificauldade);
} 

Nota::Nota(int o, int g, int a)
{
    this->setNota( o, g, a );
} 

/////////////////////////////////////////
// Sets
/////////////////////////////////////////

//Setar atributo oitava
void Nota::setOitava(int o){
    oitava = o;
}

void Nota::setGrau(int g){
    grau = g;
}

void Nota::setAcidente(int a){
    acidente = a;
}

void Nota::setNota( int o, int g, int a )
{
    if (notaValida(o,g,a)){
        setOitava(o);
        setGrau(g);
        setAcidente(a);
    }
    else
        MensagemErro(o,g,a, true);

}

void Nota::setNota(string str){
	int o, g=0, a;
	o = stoi(str.substr(0,1));
	transform(str.begin(), str.end(), str.begin(), ::toupper);//toUpperCase
	smatch match;
	
	regex regra("DO");
	for(int i=0; i<=7;i++){
		regra = this->DescNota[i];
		if ( regex_search(str, match, regra) ){
			g = i+1;
			break;
		}
	}
	a=0;
	regra="#";
	if ( regex_search(str, match, regra) ){
		a=1;
	}else{
		regra="BB";
		if ( regex_search(str, match, regra) ){
			a=-2;
		}else{
			regra="B";
			if ( regex_search(str, match, regra) ){
				a = -1;
			}else{
				regra="\\*";
				if ( regex_search(str, match, regra) ){
					a = 2;
				}
  	             }
		     }
	    }
	
	this->setNota(o,g,a);

}//setNota


/////////////////////////////////////////
// Gets
/////////////////////////////////////////

int Nota::getOitava(){
    return oitava;
}

int Nota::getGrau(){
    return grau;
}

int Nota::getAcidente(){
    return acidente;
}

int Nota::getId(){
	return (this->getOitava()*100)+ 
		   (this->getGrau()  *10 )+
		   (this->getAcidente()  )
			;
}

//////////////////////////////////////
//Operacoes 
//////////////////////////////////////
bool Nota::operator==(Nota const& other){
	// this->  operador1
	// other.  operador2

	return NotaIgual(
			         this->getOitava(),
			         this->getGrau(),
					 this->getAcidente(),
					 other.oitava,
					 other.grau,
					 other.acidente
					 );

}

bool Nota::operator>(Nota const& other){
	// this->  operador1
	// other.  operador2

	return PrimeiraMaior(
			             this->getOitava(),
			             this->getGrau(),
					     this->getAcidente(),
					     other.oitava,
					     other.grau,
					     other.acidente
						 );

}

bool Nota::operator<(Nota const& other){
	// this->  operador1
	// other.  operador2
	
	return SegundaMaior(
			            this->getOitava(),
			            this->getGrau(),
					    this->getAcidente(),
					    other.oitava,
					    other.grau,
					    other.acidente
						);

}

/////////////////////////////////////////
// Padrão
/////////////////////////////////////////

// Randomizar uma nota
void Nota::Randomizar(int in_dificuldade){

	int oitava, grau, acidente=0;

	do{
		oitava = GerarInteiro(1,7);
		grau = GerarInteiro(1,7);

		switch (in_dificuldade)
		{
			case 1:acidente = 0;break;
			case 2:acidente = GerarInteiro(-1,1);break;
			case 3:acidente = GerarInteiro(-2,2);break;
			default:break;
		}

	}while(!notaValida(oitava, grau, acidente));

	this->setOitava(oitava);
	this->setGrau(grau);
	this->setAcidente(acidente);

}

string Nota::Descricao(){
    string strNota;
    int o = this->getOitava();
    int g = this->getGrau();
    int a = this->getAcidente();
    if (notaValida(o,g,a))
        strNota = iDescricao(o,g,a);
    else 
        MensagemErro(o,g,a,true);

    return strNota;

}

void Nota::ImprimirEmTela(){

    cout << this->Descricao()<< " ";

}

/////////////////////////////////////////
// Implementações publics
/////////////////////////////////////////


// Retornar a relativa
Nota Nota::qualRelativa(int relativa, int orientacao){
    Nota resposta;

    int o=this->getOitava()
       ,g=this->getGrau()
       ,a=this->getAcidente();

    if (orientacao==1){
        g = g + relativa - 1;
        if (g>=8){
            g -= 7;
            o++;
        }
    }else if (orientacao==-1){
        g = g - relativa + 1;
        if (g<=0){
            g += 7;
            o--;
        }

    }

    resposta.setOitava(o);
    resposta.setGrau(g);
    resposta.setAcidente(a);

    return resposta;

}

//////////////////////////////////////
// Transformar em operacao unaria ++
// Nota n(3,1,0);
// n++
//////////////////////////////////////
void Nota::up1SemiTom(){
    int acidente=this->getAcidente();
    int grau=this->getGrau();
    int oitava=this->getOitava();

    if (acidente==-1){
        this->setAcidente(0);
    }else if((acidente==0)){
        if (grau==3){
            this->setGrau(++grau);
        }else if (grau==7){
            this->setOitava(++oitava);
            this->setGrau(1);
        }else{
            this->setAcidente(1);
        }
    }else if((acidente==1)){
        this->setAcidente(0);
        this->setGrau(++grau);
    }

}

//////////////////////////////////////
// Transformar em operacao unaria 
// Nota n(3,1,0);
// n--
//////////////////////////////////////
void Nota::down1SemiTom(){
    int acidente=this->getAcidente();
    int grau=this->getGrau();
    int oitava=this->getOitava();
    if (acidente==1){
        this->setAcidente(0);
    }else if((acidente==0)){
        if (grau==4){
            this->setGrau(--grau);
        }else if (grau==1){
            this->setOitava(--oitava);
            this->setGrau(7);
        }else{
            this->setAcidente(-1);
        }
    }else if((acidente==-1)){
        this->setAcidente(0);
        this->setGrau(--grau);
    }
}

void Nota::up1Tom(){
    this->up1SemiTom();
    this->up1SemiTom();
}
void Nota::down1Tom(){
    this->down1SemiTom();
    this->down1SemiTom();
}

bool Nota::strEhNota(string nota){
	regex regra("^[1-7](DO|RE|MI|FA|SOL|LA|SI)(#?|B?|BB?|\\*?)$");
	smatch match;
	transform(nota.begin(), nota.end(), nota.begin(), ::toupper);//toUpperCase
	return regex_search(nota, match, regra);
}



/////////////////////////////////////////
// Implementações privates
/////////////////////////////////////////

bool Nota::EhNota(string nota){	
	bool resposta = false;
	for (int i=0; i<=7; i++){
		if ( this->DescNota[i] == nota){
			resposta=true;
			break;
		}

	}

	return resposta;
}


/////////////////////////////////////////
// Implementações internas
/////////////////////////////////////////

// Validar uma nota
bool notaValida( int o, int g, int a ){

    /* 
       1) Sete oitavas completas em um piano [1:7]
       2) graus validos [1:7]
       3) acidentes válidos[-2:2]
    */

    bool bValido=true;

    if ( o < 1 || o > 8 ) //oitava
        bValido = false;
    else 
        if ( g < 1 || g > 7 )    //grau
            bValido = false;
        else
            if ( a < -2 || a > 2 )  //acidente
                bValido = false;

    return bValido;
}


string iDescricao( int o, int g, int a ){
    string strNota;

    strNota = to_string(o);

    switch (g)
    {
        case 1:strNota+="Do" ;break;
        case 2:strNota+="Re" ;break;
        case 3:strNota+="Mi" ;break;
        case 4:strNota+="Fa" ;break;
        case 5:strNota+="Sol";break;
        case 6:strNota+="La" ;break;
        case 7:strNota+="Si" ;break;
    default:
        break;
    }

    switch (a)
    {
        case -2:strNota += "bb";break;
        case -1:strNota += "b";break;
        case  1:strNota += "#";break;
        case  2:strNota += "*";break;
    default:
        break;
    }

    return strNota;

}

void MensagemErro( int o, int g, int a, bool mostraValores ){
//        cout << "Oitava, nota e/ou acidente invalido\t";
        if (mostraValores){
             cout << o << '/';
             cout << g << '/';
             cout << a;
        }
//        cout << endl;
}

bool NotaIgual(int o1, int g1, int a1, int o2, int g2, int a2){
	return (o1==o2)&&(g1==g2)&&(a1==a2);
}

bool PrimeiraMaior(int o1, int g1, int a1, int o2, int g2, int a2){

	bool resposta=false;

	if (!NotaIgual(o1, g1, a1, o2, g2, a2)){
		if      (o1 != o2) resposta = o1 > o2;
		else if (g1 != g2) resposta = g1 > g2;
		else if (a1 != a2) resposta = a1 > a2;
	}
    return resposta;
}


bool SegundaMaior(int o1, int g1, int a1, int o2, int g2, int a2){

	return !NotaIgual(o1, g1, a1, o2, g2, a2) && !PrimeiraMaior(o1, g1, a1, o2, g2, a2);

}
