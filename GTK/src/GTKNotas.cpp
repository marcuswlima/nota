#include "GTKNotas.h"


//constructor
GTKNotas::GTKNotas(int argc, char** argv){
	auto app = Application::create(argc, argv, "org.gtkmm.example");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("glade/notas.glade");
	refBuilder->get_widget( "window", pWindow );

	if ( pWindow ){
		refBuilder->get_widget( "e_num_1", e_num_1 );
		refBuilder->get_widget( "e_num_2", e_num_2 );
		refBuilder->get_widget( "btn_soma", btn_soma );
	}

	if ( btn_soma ){
//		btn_soma->signal_clicked().connect( sigc::ptr_fun(on_btn_soma_clicked() ) );
	}

	app->run( *pWindow );
}

GTKNotas::~GTKNotas(){
	delete pWindow;
}

void GTKNotas::on_btn_soma_clicked(){
}
