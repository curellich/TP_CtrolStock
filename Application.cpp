#include <wx/image.h>
#include "Application.h"
#include "WinPrincipal.h"



//Constructor de la aplicacion donde le paso el nombre del archivo
Application::Application():miDeposito("datos.dat"){
	
}	
/**
* Este metodo hace las veces del main, y debe inicializar el programa. Esto es,
* crear una instancia de deposito, cargar la lista de productos desde el archivo 
* binario, crear la primer ventana y mostrarla.
**/	
bool Application::OnInit() {
	WinPrincipal *ventana  = new WinPrincipal(&miDeposito); //Creo la ventana
	ventana->Show();//Mostrar la ventana
	return true;
}

