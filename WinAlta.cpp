/**
* @archivo WinAlta.cpp
* @nota Implementa los eventos de la ventana para dar de alta nuevos Productos
**/
#include "WinAlta.h"
#include <wx/msgdlg.h>
#include "Producto.h"
#include "Deposito.h"
#include <string>

WinAlta::WinAlta(wxWindow *parent, Deposito *deposito) : WxfbProducto(parent), miDeposito(deposito) {
    SetTitle("Dar de Alta un Producto"); //Titulo de la ventana
    m_btn_cancelar_producto->SetLabel("Cancelar");//Rotulo el boton de cancelar product
    m_btn_alta_producto->SetLabel("Alta");//Rotulo el boton de alta de producto
}

WinAlta::~WinAlta() {

}

void WinAlta::OnClickCancelarProducto(wxCommandEvent &event) {
    EndModal(0);
}

void WinAlta::OnClickAltaoEditarProducto(wxCommandEvent &event) {
    int codigo, existencias, stockMin, stockMax;
    std::string descripcion;
    double precio;
    codigo = wxAtoi(m_codigo->GetValue());
    descripcion = (m_descripcion->GetValue());
    existencias = wxAtoi(m_existencias->GetValue());
    stockMin = wxAtoi(m_stockMin->GetValue());
    stockMax = wxAtoi(m_stockMax->GetValue());
    precio = wxAtof(m_precio->GetValue());

    Producto producto(codigo, descripcion, existencias, stockMin, stockMax, precio);
    //Validamos los datos por su consistencia
    std::string errores = producto.validacionDeConsistenciaDatos();
    //Validacion de deposito (colocamos indice -1 ya que en el alta no interesa el indice)
    errores += miDeposito->validacionDeDeposito(producto.getCodigo(),producto.getDescripcion(),-1);

    if(errores.size()){
        wxMessageBox((errores), "Errores",wxICON_ERROR,this);//Muestro los errores
    }else{
        miDeposito->altaProducto(producto);//Lo doy de alta
        miDeposito->guardar();//Actualizo el archivo
        EndModal(1);
    }
}

