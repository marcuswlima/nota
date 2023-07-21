#include "Janela.h"

void Moldurar(WINDOW *);

Janela::Janela(){
}

Janela::Janela(int lines, int cols, int begin_y, int begin_x){
	this->janela = newwin(lines, cols, begin_y, begin_x);
	refresh();
	Moldurar(this->janela);
	refresh();
}//construtor

void Janela::Instanciar(int lines, int cols, int begin_y, int begin_x){
	this->janela = newwin(lines, cols, begin_y, begin_x);
	refresh();
	Moldurar(this->janela);
	refresh();
}//

void Janela::Centralizar(string mensagem){

	int yMax, xMax, tamanhoMensagem;
	char *prtMensagem = &mensagem[0];
	getmaxyx(this->janela,yMax, xMax);
	tamanhoMensagem=mensagem.length();


	werase(this->janela);
	Moldurar(this->janela);
	wmove(this->janela,yMax/2, (xMax/2)-(tamanhoMensagem/2));
	wprintw(this->janela,prtMensagem);
	wrefresh(this->janela);

}

void Janela::Imprimir(int y, int x, string str){
	wmove(this->janela,y, x);
	wprintw(this->janela,&str[0]);
	wrefresh(this->janela);
}

void Janela::Imprimir(string str){
	wprintw(this->janela,&str[0]);
	wrefresh(this->janela);
}

void Janela::Limpar(){
	werase(this->janela);
	Moldurar(this->janela);
}

string Janela::CapturarPalavra(int n){
	//n - quantidade de caracteres permitidos
	char digitado[80];
	
	echo();
	wgetnstr(this->janela,digitado,n);
	noecho();
	
	return digitado;
}

void Moldurar(WINDOW *janela){
	char v = '|';
	char h = '-';
	wborder(janela,v,v,h,h,'/','\\','\\','/');
	wrefresh(janela);
}


