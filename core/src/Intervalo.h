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
    Nota getN1() const;
    Nota getN2() const;
// Padrão
    void Randomizar(int =1);
    string Descricao() const;
    void ImprimirEmTela() const;
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
	tRecDadosIntervalo DadosIntervalo[16];
// ---------------------------------------
    int DeduzirQdtTons();
    int DeduzirQtdSemiTons();
    int DeduzirOrientacao();
    void ImprimirQdtTonsEmTela();
    void ImprimirQtdSemiTonsEmTela();
	void ImprimirOrientacaoEmTela();
    void ImprimirTipoIntervaloEmTela();
	void QuantidadesIntervalo(string, int &, int &);
	void popularDadosIntervalo();
	void popularDadosIntervalo(int, string , int , int);
};
#endif
