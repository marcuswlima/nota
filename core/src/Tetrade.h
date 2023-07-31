#include "Triade.h"

#ifndef TETRADE_H 
#define TETRADE_H 

class Tetrade : public Triade{
public:
// Constructors
	Tetrade();
	Tetrade(const int =1);
	Tetrade(const Nota,const int =1);
//sets
	void setInt3(const Intervalo);
//gets
	Intervalo getInt3() const;
// Padrao
	void Randomizar(const int =1);
	string GerarDescricao() const;
	void ImprimirEmTela() const;
//---------------------------
private:
	Intervalo i3;
	const char tiposSetima[3]={'M','m','d'};
//---------------------------
};
#endif
