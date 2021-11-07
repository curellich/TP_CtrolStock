#ifndef WINALTA_H
#define WINALTA_H
#include "wxfb_project.h"

//declaracion adelantada de la clase Deposito, para que me deje poner un puntero
//sin tener que hacer el include "Deposito.h"
class Deposito;

class WinAlta : public WxfbProducto {
	
private:
    Deposito *miDeposito;
	
protected:
    ///Cierra la ventana sin dar de alta un nuevo producto (boton "Cancelar")
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
    ///Guarda el nuevo producto y cierra la ventana (boton "Guardar")
	void OnClickAltaoEditarProducto( wxCommandEvent& event )  override;
	
public:
	WinAlta(wxWindow *parent,Deposito *deposito);
	~WinAlta();
};

#endif

