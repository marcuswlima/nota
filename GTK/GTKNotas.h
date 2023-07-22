#include <gtkmm.h>
#include <iostream>

using namespace Gtk;


class GTKNotas
{
public:
//constructor
	GTKNotas(int, char**);
	~GTKNotas();
private:
	Window * pWindow;
	Entry * num_1, * num_2;
	Button * btn_soma;
};

