/**
 * @archivo WinCompra.cpp
 * @nota Implementa los eventos de la ventana para comprar productos existentes
 */
#include <wx/msgdlg.h>
#include "WinCompra.h"
#include "Producto.h"
#include "Deposito.h"


WinCompra::WinCompra(wxWindow *parent, Deposito *miDeposito, int indice) : WxOperaciones(parent),
                                                                           miDeposito(miDeposito),
                                                                           indiceProducto(indice) {
    Producto &producto = (*miDeposito)[indice];
    m_codigo_operaciones->SetValue(wxString() << producto.getCodigo());
    m_codigo_operaciones->Disable();
    m_descripcion_operaciones->SetValue(producto.getDescripcion());
    m_descripcion_operaciones->Disable();
    m_btn_cancelar_compra_venta->SetLabel("Cancelar");
    m_btn_confirmar_compra_venta->SetLabel("Comprar");
    SetTitle("Comprar Producto");
}

WinCompra::~WinCompra() {

}

void WinCompra::OnClickCancelarOperacion(wxCommandEvent &event) {
    EndModal(0);
}

void WinCompra::OnClickRealizarOperacion(wxCommandEvent &event) {
    event.Skip();
}




