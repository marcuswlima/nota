#include "Intervalo.h"

#ifndef TRIADE_H
#define TRIADE_H
class Triade{
public:
// Constructors
	Triade();
	Triade(const int);
	Triade(const Nota,const char);
	Triade(const Intervalo, const Intervalo);
// Sets
	void setInt1(const Intervalo);
	void setInt2(const Intervalo);
	void setTriade(const Nota, const char);
//Gets
	Intervalo getInt1() const;
	Intervalo getInt2() const;
	Nota getFundamental() const;
	Nota getTerca() const;
	Nota getQuinta() const;
// Padrao
	void Randomizar(int dificuldade=1);
	string Descricao() const;
	void ImprimirEmTela() const;
// ------------------------------------
	void ImprimirTipoTriadeEmTela() const;
	void getTiposTriade(char * const);
private:
	Intervalo i1;
	Intervalo i2;
	const char tiposTriade[4]={'M','m','d','A'};
// ------------------------------------
	void ImprimirFundamentalEmTela() const;
	char RandomizarTipoTriade();
	string DeduzirTipoTriade() const;
	void getTiposTriade(const char *) const;
};
#endif
