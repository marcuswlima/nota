#include "Tetrade.h"

//--------------------------------------
// Prototipations
//--------------------------------------
void TestarIntervalo();
void TestarTriade();
void TestarNota();
void TodosIntervalos();
void TodasTriades();
void TestarTetrade();
void ToShowParameters(int , char *[]);

//--------------------------------------
// Main
//--------------------------------------
int main(int argc, char *argv[] ){
    srand( time(0) );

	//Nota
	cout << endl << "Nota...."<< endl;
	Nota n1(3,4,0); //terceira oitava, Dó, sem acidente
	Nota n2(1);//nota randomizada
	cout << n1 << endl;
	cout << n2 << endl;

	//Intervalo
	cout << endl << "Intervalo...."<< endl;
	Intervalo i1(n1,"7M"); //Nota fundamental e terceira Maior
	Intervalo i2(1); // Randomizar fundamental e tipoIntervalo
	cout << i1 << endl;
	cout << i2 << endl;

	//Triade
	cout << endl << "Triade...."<< endl;
	Triade tr1(n1,'M');//Fundamental e tipoTriade
	Triade tr2(1); //Randomizar fundamental e tipoTriade
	cout << tr1 << endl;
	cout << tr2 << endl;
	
	//Tetrade
	cout << endl << "Tetrade...."<< endl;
	Tetrade te1(n1,'M','m');//fundamental, tipoTriade, tipoSetima
	Tetrade te2(1);//randomizar fundamental, tipoTriade, tipoSetima
	cout << te1 << endl;
	cout << te2 << endl;
	
	return 0; //indica o fim do programa2

}//main


void TestarTetrade(){
	Nota n(3,4,0);
	Tetrade te;
	char tipoTriade[Triade::QTDTRIADES];
	char tipoSetima[Tetrade::QTDSETIMAS];
	Triade::getTriades(tipoTriade);
	Tetrade::getSetimas(tipoSetima);

	for (int ni=1; ni<=12; ni++){
		for (int tri=0; tri<4; tri++){
			for (int tei=0; tei<3; tei++){
				te.setTetrade(n,tipoTriade[tri],tipoSetima[tei]);
				cout << te.Descricao();
			}
			cout << '\n';
		}
		cout << '\n'; 
		n.up1SemiTom();
	}
}

void TodasTriades(){

	Nota n(4,1,0);	
	Triade t;
	char tiposTriades[Triade::QTDTRIADES];
	Triade::getTriades(tiposTriades);

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
			cout << t;
			//t.ImprimirTipoTriadeEmTela();
			cout << "\t\t";
		}
		n.up1SemiTom();
		cout << endl;
	}

	cout << endl;
	for (int i=1; i<=13; i++){

		for (int tt=1; tt<=4; tt++){
			t.setTriade(n,tt);
			cout << t;
			//t.ImprimirTipoTriadeEmTela();
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
	cout << i.getN2();
}


void TodosIntervalos(){
    Nota n1,n2;
    Intervalo i;

	static const int qtdIntervalos = Intervalo::QTDINTERVALOS;
	static const int qtdTeclas     = 12;

	tRecDadosIntervalo intervalos[qtdIntervalos];
	Intervalo::getIntervalos(intervalos);

	//titulo
	cout << "Nota\t";
	for(int i=0; i<qtdIntervalos; i++)
		cout << intervalos[i].tipoIntervalo <<'\t';
	cout << '\n';

	cout << "de Do a Si ascendente todos 17 intervalos" << endl;
	n1.setNota(3,1,0);
    for (int ii=1; ii<=qtdTeclas; ii++){
		i.setN1(n1);
		cout << n1;
		cout << '\t' ;

		for (int iii=0;iii<qtdIntervalos;iii++){
			i.setN2(intervalos[iii].tipoIntervalo);
			cout << i.getN2();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

	cout<<endl;
	cout << "de Si a Do ascendente todos 17 intervalos" << endl;
	n1.setNota(3,7,0);
    for (int ii=1; ii<=qtdTeclas; ii++){
		i.setN1(n1);
		cout << n1;
		cout << '\t' ;

		for (int iii=0; iii<qtdIntervalos; iii++){
			i.setN2(intervalos[iii].tipoIntervalo);
			cout << i.getN2();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}

	cout<<endl;
	cout << "de Si a Do descendente todos 17 intervalos" << endl;
	n1.setNota(3,1,0);
    for (int ii=1; ii<=qtdTeclas; ii++){
		i.setN1(n1);
		cout << n1;
		cout << '\t' ;

		for (int iii=0;iii<qtdIntervalos;iii++){
			i.setN2(intervalos[iii].tipoIntervalo,-1);
			cout << i.getN2();
			cout << '\t' ;
		}
		cout << endl;
		n1.up1SemiTom();
	}

/*

	cout<<endl;
	n1.setNota(3,7,0);
	for (int ii=1; ii<=12; ii++){
		i.setN1(n1);
		cout << n1;
		cout << '\t' ;

		for (int iii=0;iii<17;iii++){
			i.setN2(intervalos[iii].tipoIntervalo,-1);
			cout << i.getN2();
			cout << '\t' ;
		}
		cout << endl;
		n1.down1SemiTom();
	}
	*/

}
