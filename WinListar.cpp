/**
 * @archivo WinListar.cpp
 * @nota Implementa los eventos de la ventana para listar los productos
 */

#include "WinListar.h"
#include <wx/msgdlg.h>
#include "Deposito.h"


WinListar::WinListar(wxWindow *parent, Deposito *miDeposito) : WxListados(parent), miDeposito(miDeposito) {
    SetTitle("Listados");
}

WinListar::~WinListar() {

}

void WinListar::OnClickCancelarListado(wxCommandEvent &event) {
    EndModal(0);
}

void WinListar::OnClickGenerarListado(wxCommandEvent &event) {
    miDeposito->listarProductorAReponer();
    miDeposito->listarExistencias();
    EndModal(1);
}

