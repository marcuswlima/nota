#include <string>
#include <ncurses.h>
using namespace std;

class Janela {
public:
//constructor
	Janela();
	Janela(int, int, int , int);
//------------------------------
	void Instanciar(int, int, int , int);
	void Centralizar(string);
	void Limpar();
	void Imprimir(int, int, string);
	void Imprimir(string);
	string CapturarPalavra(int);
private:
	WINDOW *janela;
};
