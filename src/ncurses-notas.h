#include <vector>
#include "Janela.h"
#include "Tetrade.h"

class NcursesNotas{
public:
	NcursesNotas();
	NcursesNotas(int);
	~NcursesNotas();
private:
	Janela jUp;
	Janela jResultado;
	int dificuldade=0;
	int xMax;
	int yMax;
	int begin_xMainMenu;
//-----------------------
	void iniciar(int);
	void menuInicial();
	void ClearScreen(int);
	int montaMenu(vector <string> &, int);
	int ObterNumero(string, int , int , int );	
	string ObterString(string, int , int, int);	
	void MenuIntervalo();
	void UC01(int quantidade);
	void UC02(int quantidade);
	void UC03(int quantidade);
	void UC04(int quantidade);
	void MenuTriade();
	void UC05(int quantidade);
};
