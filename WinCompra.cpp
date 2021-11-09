/**
 * @archivo WinCompra.cpp
 * @nota Implementa los eventos de la ventana para comprar productos existentes
 */
#include <wx/msgdlg.h>
#include "WinCompra.h"
#include "Producto.h"
#include "Deposito.h"
#include "LogOperaciones.h"


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
    int cantidad = wxAtoi(m_cantidad_operaciones->GetValue());

    //Instanciamos el producto
    Producto producto = (*miDeposito)[indiceProducto];
    //Compro mas cantidades de un producto.
    producto.comprar(cantidad);
    //Valido la operacion de compra
    std::string errores = producto.validacionOperacionesDeCompra();
    if (errores.size()) {
        wxMessageBox((errores), "Errores", wxICON_ERROR, this);//Muestro los errores
    } else {
        (*miDeposito)[indiceProducto] = producto;
        Operaciones operacion(miDeposito, indiceProducto, 'c', cantidad);
        operacion.guardarCompra();
        miDeposito->guardar();//Actualizo el archivo
        EndModal(1);
    }
}




