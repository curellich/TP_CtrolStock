///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

WxfbPrincipal::WxfbPrincipal(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                             const wxSize &size, long style) : wxFrame(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer2;
    bSizer2 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer3;
    bSizer3 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText2 = new wxStaticText(this, wxID_ANY, wxT("Descripcion"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText2->Wrap(-1);
    bSizer3->Add(m_staticText2, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_busqueda = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_busqueda->SetMinSize(wxSize(450, -1));

    bSizer3->Add(m_busqueda, 1, wxALL, 5);

    m_btn_buscar = new wxButton(this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer3->Add(m_btn_buscar, 0, wxALL, 5);


    bSizer2->Add(bSizer3, 0, wxALIGN_RIGHT | wxEXPAND, 5);

    m_tabla = new wxGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0);

    // Grid
    m_tabla->CreateGrid(0, 6);
    m_tabla->EnableEditing(false);
    m_tabla->EnableGridLines(true);
    m_tabla->EnableDragGridSize(false);
    m_tabla->SetMargins(0, 0);

    // Columns
    m_tabla->SetColSize(0, 80);
    m_tabla->SetColSize(1, 343);
    m_tabla->SetColSize(2, 80);
    m_tabla->SetColSize(3, 80);
    m_tabla->SetColSize(4, 80);
    m_tabla->SetColSize(5, 80);
    m_tabla->EnableDragColMove(false);
    m_tabla->EnableDragColSize(true);
    m_tabla->SetColLabelValue(0, wxT("Codigo"));
    m_tabla->SetColLabelValue(1, wxT("Descripcion"));
    m_tabla->SetColLabelValue(2, wxT("Existencias"));
    m_tabla->SetColLabelValue(3, wxT("StockMin"));
    m_tabla->SetColLabelValue(4, wxT("StockMax"));
    m_tabla->SetColLabelValue(5, wxT("Precio"));
    m_tabla->SetColLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

    // Rows
    m_tabla->EnableDragRowSize(true);
    m_tabla->SetRowLabelSize(1);
    m_tabla->SetRowLabelAlignment(wxALIGN_CENTER, wxALIGN_CENTER);

    // Label Appearance

    // Cell Defaults
    m_tabla->SetDefaultCellAlignment(wxALIGN_LEFT, wxALIGN_TOP);
    bSizer2->Add(m_tabla, 1, wxALL | wxEXPAND, 5);

    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText3 = new wxStaticText(this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText3->Wrap(-1);
    bSizer4->Add(m_staticText3, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_btn_alta = new wxButton(this, wxID_ANY, wxT("Alta"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_alta, 0, wxALL, 5);

    m_btn_editar = new wxButton(this, wxID_ANY, wxT("Editar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_editar, 0, wxALL, 5);

    m_btn_baja = new wxButton(this, wxID_ANY, wxT("Baja"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_baja, 0, wxALL, 5);

    m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Operaciones:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText4->Wrap(-1);
    bSizer4->Add(m_staticText4, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_btn_compra = new wxButton(this, wxID_ANY, wxT("Compra"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_compra, 0, wxALL, 5);

    m_btn_venta = new wxButton(this, wxID_ANY, wxT("Venta"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_venta, 0, wxALL, 5);

    m_btn_listados = new wxButton(this, wxID_ANY, wxT("Listados"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer4->Add(m_btn_listados, 0, wxALL, 5);


    bSizer2->Add(bSizer4, 0, wxEXPAND | wxALIGN_RIGHT, 5);


    this->SetSizer(bSizer2);
    this->Layout();

    this->Centre(wxBOTH);

    // Connect Events
    this->Connect(wxEVT_SIZE, wxSizeEventHandler(WxfbPrincipal::OnCambiaTamanio));
    m_btn_buscar->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickBuscar), NULL,
                          this);
    m_busqueda->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(WxfbPrincipal::EnterBuscar), NULL, this);
    m_tabla->Connect(wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler(WxfbPrincipal::OnDobleClickTabla), NULL, this);
    m_tabla->Connect(wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler(WxfbPrincipal::OnClickTabla), NULL, this);
    m_btn_alta->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickAlta), NULL, this);
    m_btn_editar->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickEditar), NULL,
                          this);
    m_btn_baja->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickBaja), NULL, this);
    m_btn_compra->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickCompra), NULL,
                          this);
    m_btn_venta->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickVenta), NULL, this);
    m_btn_listados->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickListados), NULL,
                            this);
}

WxfbPrincipal::~WxfbPrincipal() {
    // Disconnect Events
    this->Disconnect(wxEVT_SIZE, wxSizeEventHandler(WxfbPrincipal::OnCambiaTamanio));
    m_btn_buscar->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickBuscar), NULL,
                             this);
    m_busqueda->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(WxfbPrincipal::EnterBuscar), NULL, this);
    m_tabla->Disconnect(wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler(WxfbPrincipal::OnDobleClickTabla), NULL, this);
    m_tabla->Disconnect(wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler(WxfbPrincipal::OnClickTabla), NULL, this);
    m_btn_alta->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickAlta), NULL, this);
    m_btn_editar->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickEditar), NULL,
                             this);
    m_btn_baja->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickBaja), NULL, this);
    m_btn_compra->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickCompra), NULL,
                             this);
    m_btn_venta->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickVenta), NULL,
                            this);
    m_btn_listados->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(WxfbPrincipal::OnClickListados),
                               NULL, this);

}

WxfbProducto::WxfbProducto(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                           const wxSize &size, long style) : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);


    wxBoxSizer *bSizer4;
    bSizer4 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer5;
    bSizer5 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText4 = new wxStaticText(this, wxID_ANY, wxT("Codigo:        "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText4->Wrap(-1);
    bSizer5->Add(m_staticText4, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_codigo = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_codigo->SetMinSize(wxSize(400, -1));

    bSizer5->Add(m_codigo, 1, wxALL, 5);


    bSizer4->Add(bSizer5, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer6;
    bSizer6 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText5 = new wxStaticText(this, wxID_ANY, wxT("Descripcion:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText5->Wrap(-1);
    bSizer6->Add(m_staticText5, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_descripcion = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_descripcion->SetMinSize(wxSize(400, -1));

    bSizer6->Add(m_descripcion, 1, wxALL, 5);


    bSizer4->Add(bSizer6, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer7;
    bSizer7 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText6 = new wxStaticText(this, wxID_ANY, wxT("Existencias: "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText6->Wrap(-1);
    bSizer7->Add(m_staticText6, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_existencias = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_existencias->SetMinSize(wxSize(400, -1));

    bSizer7->Add(m_existencias, 1, wxALL, 5);


    bSizer4->Add(bSizer7, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer8;
    bSizer8 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText7 = new wxStaticText(this, wxID_ANY, wxT("StockMin:    "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText7->Wrap(-1);
    bSizer8->Add(m_staticText7, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_stockMin = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_stockMin->SetMinSize(wxSize(400, -1));

    bSizer8->Add(m_stockMin, 1, wxALL, 5);


    bSizer4->Add(bSizer8, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer9;
    bSizer9 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText8 = new wxStaticText(this, wxID_ANY, wxT("StockMax:   "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText8->Wrap(-1);
    bSizer9->Add(m_staticText8, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_stockMax = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_stockMax->SetMinSize(wxSize(400, -1));

    bSizer9->Add(m_stockMax, 1, wxALL, 5);


    bSizer4->Add(bSizer9, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer10;
    bSizer10 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText9 = new wxStaticText(this, wxID_ANY, wxT("Precio:         "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText9->Wrap(-1);
    bSizer10->Add(m_staticText9, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_precio = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_precio->SetMinSize(wxSize(400, -1));

    bSizer10->Add(m_precio, 1, wxALL, 5);


    bSizer4->Add(bSizer10, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer11;
    bSizer11 = new wxBoxSizer(wxHORIZONTAL);

    m_btn_cancelar_producto = new wxButton(this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer11->Add(m_btn_cancelar_producto, 0, wxALL, 5);

    m_btn_alta_producto = new wxButton(this, wxID_ANY, wxT("Alta"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer11->Add(m_btn_alta_producto, 0, wxALL, 5);


    bSizer4->Add(bSizer11, 0, wxALIGN_RIGHT, 5);


    this->SetSizer(bSizer4);
    this->Layout();
    bSizer4->Fit(this);

    this->Centre(wxBOTH);

    // Connect Events
    m_btn_cancelar_producto->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                     wxCommandEventHandler(WxfbProducto::OnClickCancelarProducto), NULL, this);
    m_btn_alta_producto->Connect(wxEVT_COMMAND_BUTTON_CLICKED,
                                 wxCommandEventHandler(WxfbProducto::OnClickAltaoEditarProducto), NULL, this);
}

WxfbProducto::~WxfbProducto() {
    // Disconnect Events
    m_btn_cancelar_producto->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                        wxCommandEventHandler(WxfbProducto::OnClickCancelarProducto), NULL, this);
    m_btn_alta_producto->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED,
                                    wxCommandEventHandler(WxfbProducto::OnClickAltaoEditarProducto), NULL, this);

}

WxOperaciones::WxOperaciones(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos,
                             const wxSize &size, long style) : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer12;
    bSizer12 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer13;
    bSizer13 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText10 = new wxStaticText(this, wxID_ANY, wxT("Codigo:           "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText10->Wrap(-1);
    bSizer13->Add(m_staticText10, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_codigo_operaciones = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_codigo_operaciones->SetMinSize(wxSize(400, -1));

    bSizer13->Add(m_codigo_operaciones, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);


    bSizer12->Add(bSizer13, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer14;
    bSizer14 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText11 = new wxStaticText(this, wxID_ANY, wxT("Descripcion:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText11->Wrap(-1);
    bSizer14->Add(m_staticText11, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_descripcion_operaciones = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_descripcion_operaciones->SetMinSize(wxSize(400, -1));

    bSizer14->Add(m_descripcion_operaciones, 1, wxALL, 5);


    bSizer12->Add(bSizer14, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer15;
    bSizer15 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText12 = new wxStaticText(this, wxID_ANY, wxT("Cantidad:      "), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText12->Wrap(-1);
    bSizer15->Add(m_staticText12, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_cantidad_operaciones = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    m_cantidad_operaciones->SetMinSize(wxSize(400, -1));

    bSizer15->Add(m_cantidad_operaciones, 1, wxALL, 5);


    bSizer12->Add(bSizer15, 1, wxEXPAND, 5);

    wxBoxSizer *bSizer16;
    bSizer16 = new wxBoxSizer(wxHORIZONTAL);

    m_btn_cancelar_compra_venta = new wxButton(this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer16->Add(m_btn_cancelar_compra_venta, 0, wxALL, 5);

    m_btn_confirmar_compra_venta = new wxButton(this, wxID_ANY, wxT("Realizar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer16->Add(m_btn_confirmar_compra_venta, 0, wxALL, 5);


    bSizer12->Add(bSizer16, 1, wxALIGN_RIGHT, 5);


    this->SetSizer(bSizer12);
    this->Layout();
    bSizer12->Fit(this);

    this->Centre(wxBOTH);
}

WxOperaciones::~WxOperaciones() {
}

WxListados::WxListados(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &pos, const wxSize &size,
                       long style) : wxDialog(parent, id, title, pos, size, style) {
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    wxBoxSizer *bSizer17;
    bSizer17 = new wxBoxSizer(wxVERTICAL);

    wxBoxSizer *bSizer18;
    bSizer18 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText13 = new wxStaticText(this, wxID_ANY, wxT("Listado de existencias por producto:"), wxDefaultPosition,
                                      wxDefaultSize, 0);
    m_staticText13->Wrap(-1);
    bSizer18->Add(m_staticText13, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_checkBox_list_existencias = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer18->Add(m_checkBox_list_existencias, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);


    bSizer17->Add(bSizer18, 1, wxALIGN_RIGHT, 5);

    wxBoxSizer *bSizer19;
    bSizer19 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText14 = new wxStaticText(this, wxID_ANY, wxT("Listado de productos a reponer:"), wxDefaultPosition,
                                      wxDefaultSize, 0);
    m_staticText14->Wrap(-1);
    bSizer19->Add(m_staticText14, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_checkBox_list_reposicion = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer19->Add(m_checkBox_list_reposicion, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);


    bSizer17->Add(bSizer19, 1, wxALIGN_RIGHT, 5);

    wxBoxSizer *bSizer20;
    bSizer20 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText15 = new wxStaticText(this, wxID_ANY, wxT("Listado de ventas:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText15->Wrap(-1);
    bSizer20->Add(m_staticText15, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_checkBox_list_ventas = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer20->Add(m_checkBox_list_ventas, 0, wxALL | wxEXPAND, 5);


    bSizer17->Add(bSizer20, 1, wxALIGN_RIGHT, 5);

    wxBoxSizer *bSizer21;
    bSizer21 = new wxBoxSizer(wxHORIZONTAL);

    m_staticText16 = new wxStaticText(this, wxID_ANY, wxT("Listado de compras:"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText16->Wrap(-1);
    bSizer21->Add(m_staticText16, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

    m_checkBox_list_compras = new wxCheckBox(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
    bSizer21->Add(m_checkBox_list_compras, 0, wxALL | wxALIGN_CENTER_VERTICAL | wxEXPAND, 5);


    bSizer17->Add(bSizer21, 1, wxALIGN_RIGHT, 5);

    wxBoxSizer *bSizer22;
    bSizer22 = new wxBoxSizer(wxHORIZONTAL);

    m_btn_cancelar_listados = new wxButton(this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer22->Add(m_btn_cancelar_listados, 0, wxALL, 5);

    m_btn_generar_listados = new wxButton(this, wxID_ANY, wxT("Generar"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer22->Add(m_btn_generar_listados, 0, wxALL, 5);


    bSizer17->Add(bSizer22, 1, wxALIGN_RIGHT, 5);


    this->SetSizer(bSizer17);
    this->Layout();
    bSizer17->Fit(this);

    this->Centre(wxBOTH);
}

WxListados::~WxListados() {
}
