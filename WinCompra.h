#ifndef WINCOMPRA_H
#define WINCOMPRA_H

#include "wxfb_project.h"

//declaracion adelantada de la clase Deposito, para que me deje poner un puntero
//sin tener que hacer el include "Deposito.h"
class Deposito;

class WinCompra : public WxOperaciones {

private:
    Deposito *miDeposito;
    int indiceProducto; //Aqui se almacena el indice del producto por si hay que modificarlo

protected:
    void OnClickCancelarOperacion(wxCommandEvent &event) override;

    void OnClickRealizarOperacion(wxCommandEvent &event) override;

public:
    WinCompra(wxWindow *parent, Deposito *miDeposito, int indice);

    ~WinCompra();
};

#endif

