/**
 * @archivo WinModificar.h
 * @nota Implementa los eventos de la ventana para modificar los productos existentes
 */
#include <wx/msgdlg.h>
#include "WinModificar.h"
#include "Producto.h"
#include "Deposito.h"

/**
* Carga los datos de un Producto del deposito en los campos de la ventana
* @param deposito Puntero a la instancia de Deposito que gestiona todos los datos
* @param parent La ventana de la cual se desprende esta, siempre sera la principal
* @param indice el indice en la lista de productos (base 0) del producto a modificar
**/
WinModificar::WinModificar(wxWindow *parent, Deposito *deposito, int indice) : WxfbProducto(parent),
                                                                               miDeposito(deposito),
                                                                               indiceProducto(indice) {
    Producto &producto = (*miDeposito)[indice];
    m_codigo->SetValue(wxString() << producto.getCodigo());
    m_descripcion->SetValue(producto.getDescripcion());
    m_existencias->SetValue(wxString() << producto.getExistencias());
    m_stockMin->SetValue(wxString() << producto.getStockMin());
    m_stockMax->SetValue(wxString() << producto.getStockMax());
    m_precio->SetValue(wxString() << producto.getPrecio());
    m_btn_cancelar_producto->SetLabel("Volver");
    m_btn_alta_producto->SetLabel("Guardar");
    SetTitle("Modificar Producto");
}

void WinModificar::OnClickCancelarProducto(wxCommandEvent &event) {
    EndModal(0);
}

void WinModificar::OnClickAltaoEditarProducto(wxCommandEvent &event) {
    int codigo, existencias, stockMin, stockMax;
    std::string descripcion;
    double precio;
    codigo = wxAtoi(m_codigo->GetValue());
    descripcion = (std::string)(m_descripcion->GetValue());
    existencias = wxAtoi(m_existencias->GetValue());
    stockMin = wxAtoi(m_stockMin->GetValue());
    stockMax = wxAtoi(m_stockMax->GetValue());
    precio = wxAtof(m_precio->GetValue());

    Producto producto(codigo, descripcion, existencias, stockMin, stockMax, precio);
    std::string errores = producto.validacionDeIngreso();
    if(errores.size()){
        wxMessageBox((errores), "Errores",wxICON_ERROR,this);//Muestro los errores
    }else{
        miDeposito->altaProducto(producto);//Lo doy de alta
        miDeposito->guardar();//Actualizo el archivo
        EndModal(1);
    }
}
