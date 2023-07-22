#include <gtkmm.h>
#include <iostream>
using namespace Gtk;

/////////////////////////////////////////
// Main
/////////////////////////////////////////
/*
#include "GTKNotas.h"
int main(int argc, char *argv[] ){
	GTKNotas gtk(argc, argv);
	return 0; //indica o fim do programa2
}//main
*/

Window * pWindow;
Entry * e_num_1, * e_num_2, * e_result;
Button * btn_soma;

void on_btn_soma_clicked(){
	std::string a = e_num_1->get_text();
	std::string b = e_num_2->get_text();

	int num1=std::stoi(a);
	int num2=std::stoi(b);

	e_result->set_text( std::to_string(num1+num2));

	e_num_1->set_text("");
	e_num_2->set_text("");

}

int main (int argc, char** argv){

	auto app = Application::create(argc, argv, "org.gtkmm.example");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("glade/notas.glade");
	refBuilder->get_widget( "window", pWindow );

	if ( pWindow ){
		refBuilder->get_widget( "e_num_1", e_num_1 );
		refBuilder->get_widget( "e_num_2", e_num_2 );
		refBuilder->get_widget( "btn_soma", btn_soma );
		refBuilder->get_widget( "e_result", e_result );
	}

	if ( btn_soma ){
		btn_soma->signal_clicked().connect( sigc::ptr_fun(on_btn_soma_clicked ) );
	}

	app->run( *pWindow );
	
	delete pWindow;
}

