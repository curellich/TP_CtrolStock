#include "WinListar.h"

WinListar::WinListar(wxWindow *parent) : WxListados(parent) {

}

WinListar::~WinListar() {

}

void WinListar::OnClickCancelarListado(wxCommandEvent &event) {
    event.Skip();
}

void WinListar::OnClickGenerarListado(wxCommandEvent &event) {
    event.Skip();
}