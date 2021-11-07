#include "WinModificar.h"

WinModificar::WinModificar(wxWindow *parent) : WxfbProducto(parent) {
	
}

WinModificar::~WinModificar() {
	
}

void WinModificar::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void WinModificar::OnClickAltaoEditarProducto( wxCommandEvent& event )  {
	event.Skip();
}

