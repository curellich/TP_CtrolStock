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
    //Convertimos las cadenas a numeros
    int codigo, existencias, stockMin, stockMax;
    std::string descripcion;
    double precio;
    codigo = wxAtoi(m_codigo->GetValue());
    descripcion = (std::string) (m_descripcion->GetValue());
    existencias = wxAtoi(m_existencias->GetValue());
    stockMin = wxAtoi(m_stockMin->GetValue());
    stockMax = wxAtoi(m_stockMax->GetValue());
    precio = wxAtof(m_precio->GetValue());

    //Instanciamos un producto
    Producto producto(codigo, descripcion, existencias, stockMin, stockMax, precio);
    //Validamos los datos por su consistencia
    std::string errores = producto.validacionDeConsistenciaDatos();
    //Validamos que no se intente usar una descripcion o codigo existente(duplicado).
    errores += miDeposito->validacionDeDeposito(producto.getCodigo(),producto.getDescripcion(),indiceProducto);


    if (errores.size()) {
        wxMessageBox((errores), "Errores", wxICON_ERROR, this);//Muestro los errores
    } else {
        (*miDeposito)[indiceProducto] = producto;
        miDeposito->guardar();//Actualizo el archivo
        EndModal(1);
    }
}
