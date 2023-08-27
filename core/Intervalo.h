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
	string getTipoIntervalo() const;
	int getQtdTons() const;
// Operacoes
	void operator=(Intervalo const&);
	friend ostream &operator<<( ostream &, const Intervalo & );
// Padrao
    void Randomizar(const int =1);
    string Descricao() const;
//public	
	bool intervaloValido() const;
	bool strEhIntervalo(const string)const;
	string OrientacaoEmString()const;
	static void getIntervalos( tRecDadosIntervalo * const );
// ---------------------------------------
	static const int QTDINTERVALOS=17;
private:
	int getQtdSemiTons() const;
	int getOrientacao()const;
	void QuantidadesIntervalo(const string, int &, int &)const;
// ---------------------------------------
    Nota n1;
    Nota n2;
};
#endif
