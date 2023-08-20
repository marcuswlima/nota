#include "Intervalo.h"

#ifndef TRIADE_H
#define TRIADE_H
class Triade{
public:
// Constructors
	Triade();
	Triade(const int);
	Triade(const Nota,const char);
// Sets
	void setInt1(const Intervalo);
	void setInt2(const Intervalo);
	void setTriade(const Nota, const char);
	void setTriade(const Intervalo, const Intervalo);
//Gets
	Intervalo getInt1() const;
	Intervalo getInt2() const;
	Nota getFundamental() const;
	Nota getTerca() const;
	Nota getQuinta() const;
// Padrao
	void Randomizar(const int dificuldade=1);
	string Descricao() const;
	void ImprimirEmTela() const;
// Public
	void ImprimirTipoTriadeEmTela() const;
	static void getTriades( char *);
// ------------------------------------
	static const int QTDTRIADES=4;
private:
	Intervalo i1;
	Intervalo i2;
// ------------------------------------
	void ImprimirFundamentalEmTela() const;
	string DeduzirTipoTriade() const;
};
#endif
