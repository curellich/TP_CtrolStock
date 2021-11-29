/**
 * @archivo WinListar.cpp
 * @nota Implementa los eventos de la ventana para listar los productos
 */

#include "WinListar.h"
#include <wx/msgdlg.h>
#include "Deposito.h"
#include "Listado.h"


WinListar::WinListar(wxWindow *parent, Deposito *miDeposito) : WxListados(parent), miDeposito(miDeposito) {
    SetTitle("Listados");
}

WinListar::~WinListar() {

}

void WinListar::OnClickCancelarListado(wxCommandEvent &event) {
    EndModal(0);
}

void WinListar::OnClickGenerarListado(wxCommandEvent &event) {
    Listado listado(miDeposito);
    if (m_checkBox_list_reposicion->IsChecked() == true)
        listado.generarListadoProductosAReponer();
    if (m_checkBox_list_existencias->IsChecked() == true)
        listado.generarListadoExistencias();
    if (m_checkBox_list_compras->IsChecked() == true)
        listado.generarListadoCompras();
    if (m_checkBox_list_ventas->IsChecked() == true)
        listado.generarListadoVentas();
    EndModal(1);
}

