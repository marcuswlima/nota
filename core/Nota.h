#include <regex>
#include "Mathematics.h"

#ifndef NOTA_H
#define NOTA_H
class Nota {
public:
// Constructors
	Nota() ; 
	Nota(const int); 
	Nota(const int, const int, const int ); 
// Sets
	void setOitava(const int);
	void setGrau(const int);
	void setAcidente(const int);
	void setNota(const int, const int, const int);
	void setNota(string);
//Gets
	int getOitava() const;
	int getGrau() const;
 	int getAcidente() const;
	int getId() const;
// Operacoes
	bool operator==(Nota const&);
	bool operator>(Nota const&);
	bool operator<(Nota const&);
	void operator=(Nota const&);
// Padrao
	void Randomizar(const int =1);
	string Descricao() const;
	void ImprimirEmTela() const;
// Public
	Nota qualRelativa(const int, const int =1);
	void up1SemiTom();
	void up1Tom();
	void down1SemiTom();
	void down1Tom();
	static bool strEhNota(string);
private:
	int oitava;   // 0--8 
	int grau;     // 1--7 
	int acidente; // [-2,0,2] [bb,b,0,#,*]
	int clave;    // [5-sol,4-fa]
	const string NomeNota[7]={"DO","RE","MI","FA",
	                          "SOL","LA","SI"};
//----------------------------------
	bool EhNota(const string nota) const;	
}; 
#endif