#include "Triade.h"

#ifndef TETRADE_H 
#define TETRADE_H 

class Tetrade : public Triade{
public:
// Constructors
	Tetrade();
	Tetrade(int =1);
	Tetrade(Nota,int =1);
//sets
	void setInt3(Intervalo);
//gets
	Intervalo getInt3() const;
// Padrao
	void Randomizar(int =1);
	string GerarDescricao() const;
	void ImprimirEmTela() const;
//---------------------------
private:
	Intervalo i3;
//---------------------------
};
#endif
