///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class WxfbPrincipal
///////////////////////////////////////////////////////////////////////////////
class WxfbPrincipal : public wxFrame {
private:

protected:
    wxStaticText *m_staticText2;
    wxTextCtrl *m_busqueda;
    wxButton *m_btn_buscar;
    wxGrid *m_tabla;
    wxStaticText *m_staticText3;
    wxButton *m_btn_alta;
    wxButton *m_btn_editar;
    wxButton *m_btn_baja;
    wxStaticText *m_staticText4;
    wxButton *m_btn_compra;
    wxButton *m_btn_venta;
    wxButton *m_btn_listados;

    // Virtual event handlers, override them in your derived class
    virtual void OnCambiaTamanio(wxSizeEvent &event) { event.Skip(); }

    virtual void OnEnterBuscar(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickBuscar(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickTabla(wxGridEvent &event) { event.Skip(); }

    virtual void OnDobleClickTabla(wxGridEvent &event) { event.Skip(); }

    virtual void OnClickAlta(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickEditar(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickBaja(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickCompra(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickVenta(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickListados(wxCommandEvent &event) { event.Skip(); }


public:

    WxfbPrincipal(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Deposito"),
                  const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxSize(750, 500),
                  long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);

    ~WxfbPrincipal();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxfbProducto
///////////////////////////////////////////////////////////////////////////////
class WxfbProducto : public wxDialog {
private:

protected:
    wxStaticText *m_staticText4;
    wxTextCtrl *m_codigo;
    wxStaticText *m_staticText5;
    wxTextCtrl *m_descripcion;
    wxStaticText *m_staticText6;
    wxTextCtrl *m_existencias;
    wxStaticText *m_staticText7;
    wxTextCtrl *m_stockMin;
    wxStaticText *m_staticText8;
    wxTextCtrl *m_stockMax;
    wxStaticText *m_staticText9;
    wxTextCtrl *m_precio;
    wxButton *m_btn_cancelar_producto;
    wxButton *m_btn_alta_producto;

    // Virtual event handlers, override them in your derived class
    virtual void OnClickCancelarProducto(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickAltaoEditarProducto(wxCommandEvent &event) { event.Skip(); }


public:

    WxfbProducto(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Producto"),
                 const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
                 long style = wxDEFAULT_DIALOG_STYLE);

    ~WxfbProducto();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxOperaciones
///////////////////////////////////////////////////////////////////////////////
class WxOperaciones : public wxDialog {
private:

protected:
    wxStaticText *m_staticText10;
    wxTextCtrl *m_codigo_operaciones;
    wxStaticText *m_staticText11;
    wxTextCtrl *m_descripcion_operaciones;
    wxStaticText *m_staticText12;
    wxTextCtrl *m_cantidad_operaciones;
    wxButton *m_btn_cancelar_compra_venta;
    wxButton *m_btn_confirmar_compra_venta;

    // Virtual event handlers, override them in your derived class
    virtual void OnClickCancelarOperacion(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickRealizarOperacion(wxCommandEvent &event) { event.Skip(); }

public:

    WxOperaciones(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Operaciones"),
                  const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
                  long style = wxDEFAULT_DIALOG_STYLE);

    ~WxOperaciones();

};

///////////////////////////////////////////////////////////////////////////////
/// Class WxListados
///////////////////////////////////////////////////////////////////////////////
class WxListados : public wxDialog {
private:

protected:
    wxStaticText *m_staticText13;
    wxCheckBox *m_checkBox_list_existencias;
    wxStaticText *m_staticText14;
    wxCheckBox *m_checkBox_list_reposicion;
    wxStaticText *m_staticText15;
    wxCheckBox *m_checkBox_list_ventas;
    wxStaticText *m_staticText16;
    wxCheckBox *m_checkBox_list_compras;
    wxButton *m_btn_cancelar_listados;
    wxButton *m_btn_generar_listados;

    // Virtual event handlers, override them in your derived class
    virtual void OnClickCancelarListado(wxCommandEvent &event) { event.Skip(); }

    virtual void OnClickGenerarListado(wxCommandEvent &event) { event.Skip(); }

public:

    WxListados(wxWindow *parent, wxWindowID id = wxID_ANY, const wxString &title = wxT("Listados"),
               const wxPoint &pos = wxDefaultPosition, const wxSize &size = wxDefaultSize,
               long style = wxDEFAULT_DIALOG_STYLE);

    ~WxListados();

};

