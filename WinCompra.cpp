/**
 * @archivo WinCompra.cpp
 * @nota Implementa los eventos de la ventana para comprar productos existentes
 */
#include <wx/msgdlg.h>
#include "WinCompra.h"
#include "Producto.h"
#include "Deposito.h"
#include "Operacion.h"


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
/**
 * Funcion que al hacer click en "cancelar" regresa a la ventana principal sin alterar el archivo ni las existencias en
 * los productos
 * @param event
 */
void WinCompra::OnClickCancelarOperacion(wxCommandEvent &event) {
    EndModal(0);
}

/**
 * Funcion que al hacer click en "comprar" suma la cantidad comprada a las existencias del producto seleccionado,
 * valida la existencia de errores y regresa a la ventana principal
 * @param event
 */
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
        Operacion operacion(miDeposito, indiceProducto, 'c', cantidad);
        operacion.guardarCompraEnArchivoBinario();
//        operacion.guardarCompraEnArchivoTexto();
        miDeposito->guardar();//Actualizo el archivo
        EndModal(1);
    }
}




