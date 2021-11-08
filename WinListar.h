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
    void OnClickCancelarListado(wxCommandEvent &event) override;

    void OnClickGenerarListado(wxCommandEvent &event) override;

public:
    WinListar(wxWindow *parent, Deposito *miDeposito);

    ~WinListar();
};

#endif

