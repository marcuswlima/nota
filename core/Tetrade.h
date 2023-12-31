#include "Triade.h"

#ifndef TETRADE_H 
#define TETRADE_H 

class Tetrade : public Triade{
public:
// Constructors
	Tetrade();
	Tetrade(const int);
	Tetrade(const Nota ,const char, const char);
//sets
	void setInt3(const Intervalo);
    void setTetrade(const Nota ,const char, const char);
//gets
	Intervalo getInt3() const;
// Operacoes
	friend ostream &operator<<(ostream &, const Tetrade&);
// Padrao
	void Randomizar(const int =1);
	string Descricao() const;
//Public
	bool setimaValida(const char);
	static char randomizarSetima();
	static void getSetimas(char *);
//---------------------------
	static const int QTDSETIMAS=3;
private:
//---------------------------
	Intervalo i3;
};
#endif
