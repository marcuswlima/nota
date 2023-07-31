#include "Nota.h"

#ifndef INTERVALO_H
#define INTERVALO_H
class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(const int);
    Intervalo(const Nota, const Nota);
// Sets
    void setN1(const Nota);
    void setN2(Nota);
    void setN2(const string , const int =1);
// Gets
    Nota getN1() const;
    Nota getN2() const;
// Operacoes
	void operator=(Intervalo const&);
// Padrão
    void Randomizar(const int =1);
    string Descricao() const;
    void ImprimirEmTela() const;
//----------------------------------	
	string DeduzirTipoIntervalo() ;
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
	const tRecDadosIntervalo DadosIntervalo[16]={
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
    int DeduzirQdtTons() ;
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	void QuantidadesIntervalo(const string, int &, int &);
};
#endif
