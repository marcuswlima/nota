#include <gtkmm.h>
#include <iostream>
#include "../../core/src/Triade.h"

using namespace Gtk;

class GTKNotas
{
public:
//constructor
	GTKNotas(int, char**);
	~GTKNotas();
private:
	Window * pWindow;
	Entry * e_num_1, * e_num_2;
	Button * btn_soma;
//-------------------
	void on_btn_soma_clicked(); 
};

