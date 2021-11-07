#include "WinAlta.h"

WinAlta::WinAlta(wxWindow *parent) : WxfbProducto(parent) {
	
}

WinAlta::~WinAlta() {
	
}

void WinAlta::OnClickCancelarProducto( wxCommandEvent& event )  {
	event.Skip();
}

void WinAlta::OnClickAltaoEditarProducto( wxCommandEvent& event )  {
	event.Skip();
}

