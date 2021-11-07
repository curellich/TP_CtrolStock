#ifndef WINMODIFICAR_H
#define WINMODIFICAR_H
#include "wxfb_project.h"

class WinModificar : public WxfbProducto {
	
private:
	
protected:
	void OnClickCancelarProducto( wxCommandEvent& event )  override;
	void OnClickAltaoEditarProducto( wxCommandEvent& event )  override;
	
public:
	WinModificar(wxWindow *parent=NULL);
	~WinModificar();
};

#endif

