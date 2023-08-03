#include "Triade.h"

#ifndef TETRADE_H 
#define TETRADE_H 

class Tetrade : public Triade{
public:
// Constructors
	Tetrade(const int =1);
	Tetrade(const Nota,const int =1);
	Tetrade(const Nota ,const char, const char);
//sets
	void setInt3(const Intervalo);
    void setTetrade(const Nota ,const char, const char);
//gets
	Intervalo getInt3() const;
// Padrao
	void Randomizar(const int =1);
	string Descricao() const;
	void ImprimirEmTela() const;
//---------------------------
	void getTiposSetima(char *);
private:
	Intervalo i3;
	const char tiposSetima[3]={'M','m','d'};
//---------------------------
};
#endif
