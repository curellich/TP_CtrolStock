#ifndef WINPRINCIPAL_H
#define WINPRINCIPAL_H
#include "wxfb_project.h"
#include "Deposito.h"

class WinPrincipal : public WxfbPrincipal {
	
private:
	Deposito *miDeposito;
	//Funcion de Utileria
	///Copia los datos de un producto a la tabla
	void cargarFila(int i);
	
protected:
	void OnClickBuscar( wxCommandEvent& event )  override;
	void OnClickTabla( wxGridEvent& event )  override;
	void OnClickAlta( wxCommandEvent& event )  override;
	void OnClickEditar( wxCommandEvent& event )  override;
	void OnClickBaja( wxCommandEvent& event )  override;
	void OnClickCompra( wxCommandEvent& event )  override;
	void OnClickVenta( wxCommandEvent& event )  override;
	void OnClickListados( wxCommandEvent& event )  override;
	
public:
	WinPrincipal(Deposito miDeposito);
	~WinPrincipal();
};

#endif

