#include "Tetrade.h"

//--------------------------------------
// Prototipations
//--------------------------------------
void TestarIntervalo();
void TestarTriade();
void TestarNota();
void TodosIntervalos();
void TodasTriades();
void ToShowParameters(int , char *[]);

//--------------------------------------
// Main
//--------------------------------------
int main(int argc, char *argv[] ){
    srand( time(0) );
//	ToShowParameters(argc, argv);
	TodosIntervalos();
//	TodasTriades();
//	cout << endl;
	return 0; //indica o fim do programa2

}//main

void TodasTriades(){

	Nota n(4,1,0);	
	Triade t;
	char tiposTriades[4];
	t.getTiposTriade(tiposTriades);

	for (int y=1;y<=12;y++){

		for (int i=0;i<=3;i++){
			t.setTriade(n,tiposTriades[i]);
			cout << t.Descricao();
			cout << "\t\t";
		}
		cout << '\n';

		n.up1SemiTom();

	}

	cout << '\n';

//	n.down1SemiTom();
	for (int y=1;y<=13;y++){

		for (int i=0;i<=3;i++){
			t.setTriade(n,tiposTriades[i]);
			cout << t.Descricao();
			cout << "\t\t";
		}
		cout << '\n';

		n.down1SemiTom();

	}

}
void ToShowParameters(int argc, char *argv[]){
	if (argc > 1){
		for (int i=0 ; i<argc ; i++){
			cout << "[" << i << "]=" << argv[i] << endl;
		}
	}
	else
		cout << "sem parametros" << endl;

}

void TestarTriade(){
	Nota n(3,1,0);
    Triade t;
	for (int i=1; i<=12; i++){

		for (int tt=1; tt<=4; tt++){
			t.setTriade(n,tt);
			t.ImprimirEmTela();
			t.ImprimirTipoTriadeEmTela();
			cout << "\t\t";
		}
		n.up1SemiTom();
		cout << endl;
	}

	cout << endl;
	for (int i=1; i<=13; i++){

		for (int tt=1; tt<=4; tt++){
			t.setTriade(n,tt);
			t.ImprimirEmTela();
			t.ImprimirTipoTriadeEmTela();
			cout << "\t\t";
		}
		n.down1SemiTom();
		cout << endl;
	}

}//TestarTriade

void TestarNota(){
    Nota n1;
	n1.setNota("3Do*");
	cout << n1.Descricao();
}


void TestarIntervalo(){
    Nota n1,n2;
    Intervalo i;

	n1.setNota(3,1,0);
	i.setN1(n1);
	i.setN2("5D");
	i.getN2().ImprimirEmTela();
}


void TodosIntervalos(){
    Nota n1,n2;
    Intervalo i;

	string intervalos[16];
	i.getTiposIntervalo(intervalos);

	cout << "Nota\t";
	for(int i=0; i<16; i++)
		cout << intervalos[i]<<'\t';
	cout << '\n';

	n1.setNota(3,1,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=0;iii<16;iii++){
			i.setN2(intervalos[iii]);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

	cout<<endl;
	n1.setNota(3,7,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=0; iii<16; iii++){
			i.setN2(intervalos[iii]);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}


	cout<<endl;
	n1.setNota(3,1,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=0;iii<16;iii++){
			i.setN2(intervalos[iii],-1);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

	cout<<endl;
	n1.setNota(3,7,0);
    for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		n1.ImprimirEmTela();
		cout << '\t' ;

		for (int iii=0;iii<16;iii++){
			i.setN2(intervalos[iii],-1);
			i.getN2().ImprimirEmTela();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}

}
