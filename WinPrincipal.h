#ifndef WINPRINCIPAL_H
#define WINPRINCIPAL_H

#include "wxfb_project.h"
#include "Deposito.h"

class WinPrincipal : public WxfbPrincipal {

private:
    Deposito *miDeposito;

    //Funcion de Utileria
    ///Copia los datos de un producto a la tabla
    void cargarFila(int i);

protected:
    //eventos
    ///Busca la descripcion del producto cuando hacemos click en el boton "Buscar"
    void OnClickBuscar(wxCommandEvent &event) override;

    ///Reordena la Tabla cuando se hace click en el encabezado de laguna columna
    void OnClickTabla(wxGridEvent &event) override;

    ///Abre la ventana de edicion para editar un producto cuando se hace doble click sobre el mismo.
    void OnDobleClickTabla(wxGridEvent &event) override;

    ///Abre un dialogo para agregar un nuevo producto al deposito
    void OnClickAlta(wxCommandEvent &event) override;

    ///Abre un dialogo para editar los datos de un producto existente y seleccionado en el deposito
    void OnClickEditar(wxCommandEvent &event) override;

    ///Elimina un producto seleccionado del deposito
    void OnClickBaja(wxCommandEvent &event) override;

    ///Abre el cuadro de compra para realizarla operacion de compra actualizando
    /// las existencias de un producto existente seleccionado del deposito
    void OnClickCompra(wxCommandEvent &event) override;

    ///Abre el cuadro de venta para realizarla operacion de venta, actualizando
    /// las exitencias de un producto existente seleccionado del deposito.
    void OnClickVenta(wxCommandEvent &event) override;

    ///Abre el cuadro de listados, para generar listados varios
    void OnClickListados(wxCommandEvent &event) override;

public:
    ///Inicializa la ventana llenando la tabla con los datos que hay en el deposito
    WinPrincipal(Deposito *miDeposito);
};

#endif

