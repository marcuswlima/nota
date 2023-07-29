#include "Mathematics.h"

/*Apresenta o resto da divisão de 2 números*/
int GetRemainder(int divisor, int dividendo){
    return divisor % dividendo;
}

bool HasRemainder(int divisor, int dividendo){
    return GetRemainder(divisor,dividendo)>0;
}

bool IsEven(int numero){
    return !HasRemainder(numero,2);
}

bool multiple (int n1, int n2){

    if ( n2 > n1 )
        return false;
    else {
        return GetRemainder(n1,n2)==0;
    }
}


int CalcMdc(int x, int y){
    int maior=0,menor=0;

	if (x<0) x *= -1;
	if (y<0) y *= -1;

    if (x>y){
        maior=x;
        menor=y;
    }else if (x<y){
        maior=y;
        menor=x;
    };

    if (menor==0)
        return maior;
    else {
        return CalcMdc(menor, maior % menor);
    }

}


bool IsPrime(int entrou){
    bool isPrime=true;

    if (entrou!= 0 && entrou!=1){
        for (int i=2 ; i<=entrou/2 ; ++i){

            if (GetRemainder(entrou,i)==0){ 
                isPrime = false;
                break;
            }
        };
    }
    return isPrime;
} 

/*Calcula a potência (recursividade)*/
int CalcPower(int base, int expoent){

    if (expoent==0) 
        return 1;
    else
        return base * CalcPower(base,expoent-1);

}

double CalcHypotenuse(double c1, double c2){

    return sqrt ( CalcPower(c1,2) + CalcPower(c2,2) );

}

long CalcFatorial(long numero){
    long produto=1;
    for (long i=1;i<=numero;i++){
        produto *= i;
    }
    return produto;
}

double CalcCatalan(long numero){
    return CalcFatorial(2*numero)/(CalcFatorial(numero+1)*CalcFatorial(numero));
}

int CalcDiscriminant(int a, int b, int c){
    return ((b*b) - (4*a*c));
}

string CalcRealRoots(int a, int b, int c){
    int d=CalcDiscriminant(a,  b, c);
    string resposta=to_string(d)+"\t";

    if (d<0)
        resposta += "no real roots";
    else if (d==0)
        resposta += to_string((-1)*b/(a*2))+"\t";   //transforma int/double para string
    else if (d>0)
        resposta += to_string(((-1)*b)+(sqrt(d)) / (2*a)) + "\t" + 
                    to_string(((-1)*b)-(sqrt(d)) / (2*a)) + "\t";

    return resposta;
}


int GerarInteiro(int menor, int maior) {

    if (maior > menor){
        int faixa  = (maior - menor + 1);
        int gerado = (1 + rand() % faixa);
        return menor + (gerado-1);
    }
    else
        return 0;

}

double GerarDouble(int menor, int maior){

    return GerarInteiro(menor, maior)+ static_cast< double >(GerarInteiro(0,9999))/10000;

}
