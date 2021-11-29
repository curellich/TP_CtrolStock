#ifndef WINVENTA_H
#define WINVENTA_H

#include "wxfb_project.h"

//declaracion adelantada de la clase Deposito, para que me deje poner un puntero
//sin tener que hacer el include "Deposito.h"
class Deposito;

class WinVenta : public WxOperaciones {

private:
    Deposito *miDeposito;
    int indiceProducto; //Aqui se almacena el indice del producto por si hay que modificarlo

protected:
    ///Cierra la ventana sin vender un producto (boton "Cancelar")
    void OnClickCancelarOperacion(wxCommandEvent &event) override;

    ///Guarda las nuevas cantidades en existencias luego de la venta y cierra la ventana (boton "Guardar")
    void OnClickRealizarOperacion(wxCommandEvent &event) override;

public:
    WinVenta(wxWindow *parent, Deposito *miDeposito, int indice);

    ~WinVenta();
};

#endif

