#include "Nota.h"

struct tRecDadosIntervalo {
	const char * tipoIntervalo;
	int qtdNotasNaturais;
	int qtdSemiTons;
};

#ifndef INTERVALO_H
#define INTERVALO_H
class Intervalo {
public:
// Constructors
    Intervalo();
    Intervalo(const int);
	Intervalo(const Nota, const char *);
// Sets
    void setN1(const Nota);
    void setN2(Nota);
    void setN2(const string , const int =1);
// Gets
    Nota getN1() const;
    Nota getN2() const;
// Operacoes
	void operator=(Intervalo const&);
	friend ostream &operator<<( ostream &, const Intervalo & );
// Padrao
    void Randomizar(const int =1);
    string Descricao() const;
//public	
	bool intervaloValido() const;
	string DeduzirTipoIntervalo() ;
	bool strEhIntervalo(string);
	string OrientacaoEmString();
	static void getIntervalos( tRecDadosIntervalo * const );
// ---------------------------------------
	static const int QTDINTERVALOS=17;
private:
    int DeduzirQdtTons() ;
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	void QuantidadesIntervalo(const string, int &, int &);
// ---------------------------------------
    Nota n1;
    Nota n2;
};
#endif
