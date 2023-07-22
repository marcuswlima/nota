#include "GTKNotas.h"


//constructor
GTKNotas::GTKNotas(int argc, char** argv){
	auto app = Application::create(argc, argv, "org.gtkmm.example");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("glade/notas.glade");
	refBuilder->get_widget( "window", pWindow );

	if ( pWindow ){
		refBuilder->get_widget( "num_1", num_1 );
		refBuilder->get_widget( "num_2", num_2 );
		refBuilder->get_widget( "btn_soma", btn_soma );
	}

	app->run( *pWindow );
}

GTKNotas::~GTKNotas(){
	delete pWindow;
}
