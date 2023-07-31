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
	void operator=(Nota const&);
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
	tRecDadosIntervalo DadosIntervalo[16];
// ---------------------------------------
    int DeduzirQdtTons() ;
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	void QuantidadesIntervalo(const string, int &, int &);
	void popularDadosIntervalo(const int,const string,const int,const int);
	void popularDadosIntervalo();
};
#endif
