#include <iostream>
#include <regex>
using namespace std;

#ifndef NOTA_H
#define NOTA_H
class Nota {
public:
// Constructors
	Nota() ; 
	Nota(const int);//randomizar 
	Nota(const int, const int, const int ); 
	Nota(const Nota&);
// Sets
	void setOitava(const int);
	void setGrau(const int);
	void setAcidente(const int);
	void setNota(const int, const int, const int);
	void setNota(string);//separa string em 3
//Gets
	int getOitava() const;
	int getGrau() const;
 	int getAcidente() const;
	int getId() const;
// Operacoes
	bool operator==(const Nota &)const;
	bool operator>(const Nota &)const;
	bool operator<(const Nota &)const;
	void operator=(const Nota &);
	friend ostream &operator<<( ostream &, const Nota & );
// Padrao
	void Randomizar(const int =1);
	string Descricao() const;
// Public
	Nota qualRelativa(const int, const int =1);
	void up1SemiTom();
	void up1Tom();
	void down1SemiTom();
	void down1Tom();
	bool notaValida() const;
	static bool dificuldadeValida(const int) ;
	static bool strEhNota( string );//analisa 3 itens
	static int GerarInteiro( const int menor, const int maior );
	static void getNotas( const char ** );
//----------------------------------
	static const int QTDNOTAS=7;
private:
//----------------------------------
	int oitava;   // 0--8 
	int grau;     // 1--7 
	int acidente; // [-2,0,2] [bb,b,0,#,*]
	int clave;    // [5-sol,4-fa]
}; 
#endif
