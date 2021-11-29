#ifndef WINLISTAR_H
#define WINLISTAR_H

#include "wxfb_project.h"
//declaracion adelantada de la clase Deposito, para que me deje poner un puntero
//sin tener que hacer el include "Deposito.h"
class Deposito;

class WinListar : public WxListados {

private:
    Deposito *miDeposito;

protected:
    ///Cierra la ventana sin generar nuevos listados (boton "Cancelar")
    void OnClickCancelarListado(wxCommandEvent &event) override;

    ///Genera nuevos listados de acuerdo a los Checkbox marcardos (boton "Guardar")
    void OnClickGenerarListado(wxCommandEvent &event) override;

public:
    WinListar(wxWindow *parent, Deposito *miDeposito);

    ~WinListar();
};

#endif

