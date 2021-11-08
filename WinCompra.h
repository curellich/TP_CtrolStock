#ifndef WINCOMPRA_H
#define WINCOMPRA_H

#include "wxfb_project.h"

class WinCompra : public WxOperaciones {

private:

protected:
    void OnClickCancelarOperacion(wxCommandEvent &event) override;

    void OnClickRealizarOperacion(wxCommandEvent &event) override;

public:
    WinCompra(wxWindow *parent = NULL);

    ~WinCompra();
};

#endif

