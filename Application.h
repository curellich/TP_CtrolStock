#ifndef APPLICATION_H
#define APPLICATION_H

#include <wx/app.h>
#include "Deposito.h"

class Application : public wxApp {
private:
	Deposito miDeposito;
	
public:
	Application();//ctor, para incializar el deposito
	///Inicializa el programa
	virtual bool OnInit(); //Primer Evento del Programa

};

IMPLEMENT_APP(Application)

#endif
