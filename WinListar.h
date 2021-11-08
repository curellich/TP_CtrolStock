#ifndef WINLISTAR_H
#define WINLISTAR_H

#include "wxfb_project.h"

class WinListar : public WxListados {

private:

protected:
    void OnClickCancelarListado(wxCommandEvent &event) override;

    void OnClickGenerarListado(wxCommandEvent &event) override;

public:
    WinListar(wxWindow *parent = NULL);

    ~WinListar();
};

#endif

