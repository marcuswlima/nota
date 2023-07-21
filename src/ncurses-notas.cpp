#include "ncurses-notas.h"

NcursesNotas::NcursesNotas(){
	this->iniciar(0);
}

NcursesNotas::NcursesNotas(int dificuldade){
	this->iniciar(dificuldade);
}

NcursesNotas::~NcursesNotas(){
	endwin();
}

void NcursesNotas::iniciar(int dificuldade){
	initscr();				
	getmaxyx(stdscr, this->yMax, this->xMax);
	jUp.Instanciar(3,xMax,0,0);
	jUp.Centralizar("Exercicios para os alunos da EMUFPA");
//	getch();
	menuInicial();
}

void NcursesNotas::menuInicial(){

	cbreak();
	noecho();
	
	vector<string> choices;
	int choice;
	
	while( true ){
		ClearScreen(3);
		choices={"Intervalo","Triade","Tetrade","Configuracoes","Sair"};
		choice=montaMenu(choices,3);

		if( choice==4 )
			break;

		switch( choice )
		{
			case 0:
				this->MenuIntervalo();
				break;
			case 1:
				this->MenuTriade();
				break;

			case 3:
				int dificuldade;
				do
				{
					dificuldade = this->ObterNumero("Informe a nova dificulade: " ,11,10,1);
				}while( (dificuldade < 1) || (dificuldade>3) );
				this->dificuldade = dificuldade;
				break;
			default:
				break;
		}//switch

	}//while

}//menuInicial

void NcursesNotas::ClearScreen(int begin_y){
	WINDOW *clsWin = newwin((this->yMax - begin_y)-4, this->xMax, begin_y, 0);
	refresh();
	wrefresh(clsWin);
	werase(clsWin);
	clsWin=NULL;
}//nCursesClearScreen

int NcursesNotas::montaMenu(vector <string> &choices, int begin_y){
	size_t maiorTamanhoItem=0;
	const int qtdOpcoes=choices.size();

	for (int i=0; i<qtdOpcoes; i++){
		if ( choices[i].length() > maiorTamanhoItem ){
			maiorTamanhoItem = choices[i].length();
		}

	}

	begin_xMainMenu = (xMax/2)-(maiorTamanhoItem/2);
	
	WINDOW *menuWin = newwin(qtdOpcoes+2, maiorTamanhoItem+2, begin_y,begin_xMainMenu);
	refresh();
//	box(menuWin, (int)'|', (int)'-');
	box(menuWin,0,0);
	wrefresh(menuWin);
	keypad(menuWin,true);
	


	int choice;
	int highligth=0;
	while(1){
		for (int i=0; i<qtdOpcoes; i++){
			if (i==highligth)
				wattron(menuWin,A_REVERSE);
			mvwprintw(menuWin, i+1, 1, choices[i].c_str());
			wattroff(menuWin,A_REVERSE);
		}

		choice = wgetch(menuWin);

		switch (choice)
		{
			case KEY_UP:
				highligth--;
				if( highligth == -1 )
					highligth=0;
				break;
			case KEY_DOWN:
				highligth++;
				if( highligth == (qtdOpcoes) )
					highligth = qtdOpcoes - 1;
				break;
			default:
				break;
		}

		if( choice == 10 )
			break;
	}

	menuWin=NULL;

	return highligth;

}//montaMenu



void NcursesNotas::MenuIntervalo(){
	vector<string> choices;
	int choice, quantidade;
	
	choices.push_back("Duas Notas. Qual orientação? Qual o intervalo simples?");
	choices.push_back("Primeira Nota, uma orientacao(asc, desc) e um intervalo simples. Qual a segunda nota?");
	choices.push_back("Segunda Nota, uma orientacao(asc, desc) e um intervalo simples. Qual a primeira nota?");
	choices.push_back("Montagem de Intervalo");
	choices.push_back("Voltar!");

	while( true ){
		this->ClearScreen(3);
		choice=this->montaMenu(choices,3);
		if (choice==4){
			//jDown.Limpar();
			//jDown.Imprimir(1,1,"Escolha a sua opção");
			break;
		}

		// perguntar a quantidade
		do
		{
			quantidade = ObterNumero("Digite a quantidade de exercicios [1-10]: ",10,0, 2);
		}while( (quantidade < 1) || (quantidade > 10) );

		switch( choice ){	
			case 0:this->UC01(quantidade);break;
			case 1:this->UC02(quantidade);break;
			case 2:this->UC03(quantidade);break;
			case 3:this->UC04(quantidade);break;
			default:
				   break;
		}

	}//while

}//MenuIntervalo

int NcursesNotas::ObterNumero(string mensagem, int begin_y, int begin_x, int n){	
	string resposta=this->ObterString(mensagem, begin_y, begin_x, n);
	char *ptrResposta=&resposta[0];
	return atoi(ptrResposta);
}//ObterNumero


string NcursesNotas::ObterString(string mensagem, int begin_y, int begin_x, int n){	
	// mensagem - mensagem a ser apresentada
	// begin_y - posicao y que inicial a winodws
	// begin_x - posicao x que inicial a winodws. se 0, será centralizado
	// n - quantiade de caracteres que poderao ser digitado
	int tamanhoMensagem = mensagem.length();
	int tamanhoJanela = tamanhoMensagem+n+3;
	int iBegin_x;
	char *prtMensagem = &mensagem[0];
	char digitado[80];

	if( begin_x == 0){
		iBegin_x=(this->xMax/2)-(tamanhoJanela/2);
	}else{
		iBegin_x=begin_x;
	}
/*	
	WINDOW *limparWin = newwin(3, xMax, begin_y, iBegin_x);
	box(limparWin,0,0);
	werase(limparWin);
	wrefresh(limparWin);
	refresh();
//	limparWin=NULL;
*/
	WINDOW *obterNumeroWin = newwin(3, tamanhoJanela, begin_y, iBegin_x); 
	box(obterNumeroWin,0,0);
	mvwprintw(obterNumeroWin,1,1,prtMensagem);
	refresh();
	wrefresh(obterNumeroWin);
	echo();
	wgetnstr(obterNumeroWin,digitado,n);
	noecho();
	obterNumeroWin=NULL;

	return digitado;
}//nCursesObterString



void NcursesNotas::UC01(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	this->ClearScreen(10);
	int tamanhoJanela=40;
	this->jResultado.Instanciar(quantidade+6,tamanhoJanela,10,(this->xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(this->dificuldade);
		questao = intervalo.getN1().Descricao();
		questao += " e ";
		questao += intervalo.getN2().Descricao();
		questao += " : ";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(2);
		}while (!intervalo.strEhIntervalo(resposta));

		if( resposta == intervalo.DeduzirTipoIntervalo() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.DeduzirTipoIntervalo();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,20,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//UC01
 

void NcursesNotas::UC02(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	this->ClearScreen(10);
	int tamanhoJanela=45;
	jResultado.Instanciar(quantidade+6,tamanhoJanela,10,(this->xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(this->dificuldade);
		questao = intervalo.getN1().Descricao();
		questao += "-? ";
		questao += intervalo.DeduzirTipoIntervalo()+" ";
		questao += intervalo.OrientacaoEmString();
		questao += ":";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!intervalo.getN1().strEhNota(resposta));

		if( resposta == intervalo.getN2().Descricao() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.getN2().Descricao();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,30,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//UC02

void NcursesNotas::UC03(int quantidade){
	Intervalo intervalo;
	string questao, resposta;
	int qtdCertas=0, qtdErradas=0;
	string linha;
	
	this->ClearScreen(10);
	int tamanhoJanela=48;
	jResultado.Instanciar(quantidade+6,tamanhoJanela,10,(this->xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Questoes:");

	//perguntas
	for(int i=0; i<=(quantidade-1); i++){
		intervalo.Randomizar(this->dificuldade);
		questao = "? - ";
		questao += intervalo.getN2().Descricao()+" ";
		questao += intervalo.DeduzirTipoIntervalo()+" ";
		questao += intervalo.OrientacaoEmString();
		questao += ": ";

		linha = to_string(i+1)+") "+questao;

		jResultado.Imprimir(i+2,1,linha);
		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!intervalo.getN1().strEhNota(resposta));

		if( resposta == intervalo.getN1().Descricao() ){
			linha = " Certa";
			qtdCertas++;
		}else{
			linha = " Errada";
			linha += "->";
			linha += intervalo.getN1().Descricao();
			qtdErradas++;
		}

		jResultado.Imprimir(i+2,33,linha);
	}
	
	//resumo resultado
	jResultado.Imprimir(quantidade+3,1,"Certas: "+to_string(qtdCertas));
	jResultado.Imprimir(quantidade+4,1,"Erradas: "+to_string(qtdErradas));
	getch();
}//uc03

void NcursesNotas::UC04(int quantidade){
	int tamanhoJanela=60;
	string linha, resposta;
	Nota nota;
	Intervalo intervalo;

	this->ClearScreen(10);
	jResultado.Instanciar(quantidade+6,tamanhoJanela,10,(this->xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Montagens:");
	
	for(int i=0; i<=(quantidade-1); i++){
		linha = to_string(i+1)+") Nota: ";
		jResultado.Imprimir(i+2,1,linha);

		do{
			resposta = jResultado.CapturarPalavra(6);
		}while (!Nota::strEhNota(resposta));

		nota.setNota(resposta);
		intervalo.setN1(nota);

		linha = " Intervalo: ";
		jResultado.Imprimir(i+2,15," Intervalo:");
		
		do{
			resposta = jResultado.CapturarPalavra(2);
		}while (!intervalo.strEhIntervalo(resposta));
		
		intervalo.setN2(resposta,1); //intervalo ascendente
		jResultado.Imprimir(i+2,30,"Asc:"+intervalo.getN2().Descricao());
		
		intervalo.setN2(resposta,-1); //intervalo descendente
		jResultado.Imprimir(i+2,40,"Desc:"+intervalo.getN2().Descricao());
	}
	getch();
}//UC04

void NcursesNotas::MenuTriade(){
	int choice, quantidade;
	vector<string> choices;
	
	choices.push_back("Uma nota e uma triade (M,m,A,d). Qual a terca e a quinta?");
	choices.push_back("Uma fundamental e uma triada(M,m,A,d). Qual a terça e quinta?");
	choices.push_back("Uma terça e uma triade(M,m,A,d). Qual a fundamental e quinta?");
	choices.push_back("Uma quinta e uma triade(M,m,A,d). Qual a fundamental e quinta?");
	choices.push_back("Triade estado fundamental. Qual 1º e 2º inversão?");
	choices.push_back("Uma traide invertida. Qual o Estado Fundamental?");
	choices.push_back("Montagem de Triade");
	choices.push_back("Voltar!");
	
	while( true ){
		this->ClearScreen(3);
		choice=this->montaMenu(choices,3);
		if (choice==5){
			break;
		}

		// perguntar a quantidade
		do
		{
			quantidade = this->ObterNumero("Digite a quantidade de exercicios [1-10]: ",11,0, 2);
		}while( (quantidade < 1) || (quantidade > 10) );
		
		switch( choice ){	
			case 0:UC05(quantidade);break;
			default:
				   break;
		}
	}
}//MenuTriade

void NcursesNotas::UC05(int quantidade){
	int tamanhoJanela=60;
	jResultado.Instanciar(quantidade+6,tamanhoJanela,14,(xMax/2)-(tamanhoJanela/2));
	jResultado.Imprimir(1,1,"Perguntas:");
	getch();
}

