#include "WinCompra.h"

WinCompra::WinCompra(wxWindow *parent) : WxOperaciones(parent) {

}

WinCompra::~WinCompra() {

}

void WinCompra::OnClickCancelarOperacion(wxCommandEvent &event) {
    event.Skip();
}

void WinCompra::OnClickRealizarOperacion(wxCommandEvent &event) {
    event.Skip();
}


