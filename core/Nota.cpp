#include "Nota.h"

//---------------------------------------
// Prototipacoes
//---------------------------------------
bool oitavaValida( int );
bool grauValido( int );
bool acidenteValido( int );
string iDescricao( int, int, int);
bool NotaIgual(int , int , int , int , int , int );
bool PrimeiraMaior(int, int , int , int , int , int );

//---------------------------------------
// construtores
//---------------------------------------
Nota::Nota()
{
} 

Nota::Nota(const int dificuldade)
{
	this->Randomizar(dificuldade);
} 

Nota::Nota(const int o, const int g, const int a)
{
	this->setNota( o, g, a );
} 

Nota::Nota(const Nota &n)
{
	this->setNota( n.getOitava(), n.getGrau(), n.getAcidente() );
} 

//---------------------------------------
// Sets
//---------------------------------------
void Nota::setOitava(const int o)
{
	if (oitavaValida(o)){
		oitava = o;
	}else{
		throw invalid_argument("setOitava()-> oitava invalida o:" + to_string(o));
	}

}

void Nota::setGrau(const int g)
{
	if (grauValido(g)){
		grau = g;
	}else{
		throw invalid_argument("setGrau()-> grau invalido g:" + to_string(g));
	}
}

void Nota::setAcidente(const int a){
	if (acidenteValido(a)){
		acidente = a;
	}else{
		throw invalid_argument("setAcidente()-> acidente invalido g:" + to_string(a));
	}
}

void Nota::setNota(const int o, const int g, const int a )
{
	setOitava(o);
	setGrau(g);
	setAcidente(a);
}

void Nota::setNota(string str){

	if (!strEhNota(str)){
		throw invalid_argument("strEhNota()->formatação de Nota invalida("+str+")");
	}


	int oitava=grau=acidente=0;
	
	//Oitava
	oitava = stoi(str.substr(0,1));


	// Grau
	const char * arrNotas[QTDNOTAS];
	getNotas(arrNotas);
	transform(str.begin(), str.end(), str.begin(), ::toupper);//toUpperCase
	smatch match;
	regex regra("DO");
	for(int i=0; i<QTDNOTAS;i++){
		regra = arrNotas[i];
		if ( regex_search(str, match, regra) ){
			grau = i+1;
			break;
		}
	}

	// acidente
	regra="#";
	if ( regex_search(str, match, regra) ){
		acidente=1;
	}else{
		regra="BB";
		if ( regex_search(str, match, regra) ){
			acidente=-2;
		}else{
			regra="B";
			if ( regex_search(str, match, regra) ){
				acidente = -1;
			}else{
				regra="\\*";
				if ( regex_search(str, match, regra) ){
					acidente = 2;
				}
			}
		}
	}
	
	this->setNota(oitava,grau,acidente);
}


//---------------------------------------
// Gets
//---------------------------------------
int Nota::getOitava() const{
    return oitava;
}

int Nota::getGrau() const{
    return grau;
}

int Nota::getAcidente() const{
    return acidente;
}

int Nota::getId() const{
	return (this->getOitava()*100)+ 
		   (this->getGrau()  *10 )+
		   (this->getAcidente()  )
			;
}

//---------------------------------------
// Operations
//---------------------------------------
bool Nota::operator==(const Nota & other)const{
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

bool Nota::operator>(const Nota & other)const{
	// this->  operador1
	// other.  operador2

	return PrimeiraMaior
			(
				 this->getOitava(),
				 this->getGrau(),
				 this->getAcidente(),
				 other.oitava,
				 other.grau,
				 other.acidente
			)&&
		   !NotaIgual
			(
				this->getOitava(),
				this->getGrau(),
				this->getAcidente(),
				other.oitava,
				other.grau,
				other.acidente
			);

}


bool Nota::operator<(const Nota & other)const{
	// this->  operador1
	// other.  operador2

	return !PrimeiraMaior
			(
				 this->getOitava(),
				 this->getGrau(),
				 this->getAcidente(),
				 other.oitava,
				 other.grau,
				 other.acidente
			)&&
		   !NotaIgual
			(
				this->getOitava(),
				this->getGrau(),
				this->getAcidente(),
				other.oitava,
				other.grau,
				other.acidente
			);
	
}

void Nota::operator=(const Nota & other){
	// this->  operador1
	// other.  operador2
	this->setOitava(other.getOitava());
	this->setGrau(other.getGrau());
	this->setAcidente(other.getAcidente());
}

// non-menber friend funcion
ostream &operator<<( ostream &output, const Nota &n ){
	output << iDescricao(n.getOitava()
			            ,n.getGrau()
						,n.getAcidente()
						); 
	return output;
}

//---------------------------------------
// Padrao
//---------------------------------------
void Nota::Randomizar(const int in_dificuldade){

	int oitava=grau=acidente=0;

	do{
		oitava = this->GerarInteiro(1,7);
		grau = this->GerarInteiro(1,7);

		switch (in_dificuldade)
		{
			case 1:acidente = 0;break;
			case 2:acidente = this->GerarInteiro(-1,1);break;
			case 3:acidente = this->GerarInteiro(-2,2);break;
			default:break;
		}

		this->setOitava(oitava);
		this->setGrau(grau);
		this->setAcidente(acidente);

	}while(!this->notaValida());

}

string Nota::Descricao() const{
	return iDescricao(this->getOitava()
	                 ,this->getGrau()
					 ,this->getAcidente()
					); 
}

//---------------------------------------
// Publics
//---------------------------------------
Nota Nota::qualRelativa(const int relativa, const int orientacao){
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

bool Nota::notaValida() const 
{

    int o=this->getOitava()
       ,g=this->getGrau()
       ,a=this->getAcidente();

    /* 
       1) Sete oitavas completas em um piano [1:7]
       2) graus validos [1:7]
       3) acidentes válidos[-2:2]
    */

    bool bValido=true;

    if ( !oitavaValida(o) ) //oitava
        bValido = false;
    else 
        if ( !grauValido(g) )    //grau
            bValido = false;
        else
            if ( !acidenteValido(a) )  //acidente
                bValido = false;

    return bValido;
}

bool Nota::strEhNota(string nota){
	regex regra("^[1-7](DO|RE|MI|FA|SOL|LA|SI)(#?|B?|BB?|\\*?)$");
	smatch match;
	transform(nota.begin(), nota.end(), nota.begin(), ::toupper);//toUpperCase
	return regex_search(nota, match, regra);
}

int Nota::GerarInteiro(const int menor, const int maior){

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}

void Nota::getNotas( const char ** arr ){
    //array de ponteiros para char
	static const char * notas[QTDNOTAS]={"DO","RE","MI","FA","SOL","LA","SI"};
	for (int i=0 ; i<QTDNOTAS ; i++){
		arr[i]=notas[i]; 
	}
}
//---------------------------------------
// Privates
//---------------------------------------

//---------------------------------------
// Internals
//---------------------------------------
bool oitavaValida( int o ){
	return o >= 1 and o <= 8;
}

bool grauValido( int g ){
	return g >= 1 and g <= 7;
}

bool acidenteValido( int a ){
	return a >= -2 and a <= 2;
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

bool NotaIgual(int o1, int g1, int a1, int o2, int g2, int a2){
	return (o1==o2)&&(g1==g2)&&(a1==a2);
}

bool NotaIgual(Nota n1, Nota n2){
	return ( n1.getOitava()   == n2.getOitava()   ) &&
		   ( n1.getGrau()     == n2.getGrau()     ) &&
		   ( n1.getAcidente() == n2.getAcidente() );
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
