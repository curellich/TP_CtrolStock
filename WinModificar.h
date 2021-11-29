#ifndef WINMODIFICAR_H
#define WINMODIFICAR_H

#include "wxfb_project.h"
#include "Deposito.h"

/**
* @nota Ventana para ver y/o modificar los datos de una Producto existente
**/
class WinModificar : public WxfbProducto {

private:
    Deposito *miDeposito;
    int indiceProducto; //Aqui se almacena el indice del producto por si hay que modificarlo

protected:
    /// Cierra la ventana sin modificar los datos (boton "Volver")
    void OnClickCancelarProducto(wxCommandEvent &event);

    ///Guarda los cambios y cierra la ventana (boton "Guardar")
    void OnClickAltaoEditarProducto(wxCommandEvent &event);

public:
    ///Carga los datos de un Producto en los campos de la ventana
    WinModificar(wxWindow *parent, Deposito *deposito, int indice);
};

#endif

