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
	Intervalo getInt1() const;
	Intervalo getInt2() const;
	Nota getFundamental() const;
	Nota getTerca() const;
	Nota getQuinta() const;
// Padrao
	void Randomizar(int dificuldade=1);
	string GerarDescricao() const;
	void ImprimirEmTela() const;
// ------------------------------------
	void ImprimirTipoTriadeEmTela() const;
private:
	Intervalo i1;
	Intervalo i2;
	char tiposTriade[4];
// ------------------------------------
	void ImprimirFundamentalEmTela() const;
	char RandomizarTipoTriade();
	string DeduzirTipoTriade() const;
	void getTiposTriade(const char *) const;
	void popularTipoTriade();
};
#endif
