/**
 * @archivo WinVenta.cpp
 * @nota Implementa los eventos e la ventana para vender productos existentes
 */
#include <wx/msgdlg.h>
#include "WinVenta.h"
#include "Producto.h"
#include "Deposito.h"


WinVenta::WinVenta(wxWindow *parent, Deposito *miDeposito, int indice) : WxOperaciones(parent), miDeposito(miDeposito),
                                                                         indiceProducto(indice) {
    Producto &producto = (*miDeposito)[indice];
    m_codigo_operaciones->SetValue(wxString() << producto.getCodigo());
    m_codigo_operaciones->Disable();
    m_descripcion_operaciones->SetValue(producto.getDescripcion());
    m_descripcion_operaciones->Disable();
    m_btn_cancelar_compra_venta->SetLabel("Cancelar");
    m_btn_confirmar_compra_venta->SetLabel("Vender");
    SetTitle("Vender Producto");
}

WinVenta::~WinVenta() {

}

void WinVenta::OnClickCancelarOperacion(wxCommandEvent &event) {
    EndModal(0);
}

void WinVenta::OnClickRealizarOperacion(wxCommandEvent &event) {
    event.Skip();
}

