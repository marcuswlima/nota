#include "Nota.h"

#ifndef INTERVALO_H
#define INTERVALO_H
class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(int);
    Intervalo(Nota,Nota);
// Sets
    void setN1(Nota);
    void setN2(Nota);
    void setN2(string ,int =1);
    void SetIntervalo(Nota,Nota);
// Gets
    Nota getN1();
    Nota getN2();
// Padrão
    void Randomizar(int =1);
    string Descricao();
    void ImprimirEmTela();
//----------------------------------	
    string DeduzirTipoIntervalo();
	bool strEhIntervalo(string);
	string OrientacaoEmString();
	void getTiposIntervalo(string * const);
private:
    Nota n1;
    Nota n2;

	struct tRecDadosIntervalo {
		string tipoIntervalo;
		int qtdNotasNaturais;
		int qtdSemiTons;
	};

	tRecDadosIntervalo DadosIntervalo[16]={  //0-15
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
                                        {"7m",7,11},
                                        {"7M",7,12},
                                        {"8J",8,13}
                                    };


// ---------------------------------------
    int DeduzirQdtTons();
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	void QuantidadesIntervalo(string, int &, int &);
};
#endif
