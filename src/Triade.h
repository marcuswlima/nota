#include "Intervalo.h"

#ifndef TRIADE_H
#define TRIADE_H
class Triade{
public:
// Constructors
	Triade();
	Triade(int);
	Triade(Nota,int);
	Triade(Intervalo, Intervalo);
// Sets
	void setTriade(Intervalo, Intervalo);
	void setTriade(Nota, int);
	void setInt1(Intervalo);
	void setInt2(Intervalo);
//Gets
	Intervalo getInt1();
	Intervalo getInt2();
	Nota getFundamental();
	Nota getTerca();
	Nota getQuinta();
// Padrao
	void Randomizar(int dificuldade=1);
	string GerarDescricao();
	void ImprimirEmTela();
// ------------------------------------
	void ImprimirTipoTriadeEmTela();
private:
	Intervalo i1;
	Intervalo i2;
	char tiposTriade[4]={'M','m','d','A'};
// ------------------------------------
	void ImprimirFundamentalEmTela();
	char RandomizarTipoTriade();
	string DeduzirTipoTriade();
	void getTiposTriade(const char *);
};
#endif
