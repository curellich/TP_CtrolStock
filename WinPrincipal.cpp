#include "WinPrincipal.h"
#include "Deposito.h"
#include "Producto.h"
#include "WinAlta.h"
#include "WinModificar.h"
#include <wx/msgdlg.h>

/**
* Inicializa la ventana, asignandole un icono, llenando la m_grilla y definiendo
* las propiedades adicionales de la tabla.
**/
WinPrincipal::WinPrincipal(Deposito *miDeposito) : WxfbPrincipal(nullptr),
                                                   miDeposito(miDeposito) {
    int cantProductos = miDeposito->cantidadProductos(); //Determino la cantidad de productos
    m_tabla->AppendRows(
            cantProductos); //Agrego tantas filas como registro_producto tengo(la tabla estaba inicialmente vacia)
    for (int i = 0; i < cantProductos; i++) { //Cargo los productos en las filas
        cargarFila(i);
    }
    m_tabla->SetSelectionMode(
            wxGrid::wxGridSelectRows); //De esta forma hago que la seleccion sea por fila y no por celda
}

/**
* Toma los datos de un producto desde la instancia de Deposito y los carga en su
* correspondiente fila de la m_tabla. Se usa al cargar por primera vez, al editar,
* o al agregar productos. La m_tabla ya debe tener lugar, es decir, debe existir la
* fila (estara vacio o tendra basura).
* @param i el indice de del producto en el vector de la clase Deposito
**/
void WinPrincipal::cargarFila(int i) {
    Producto &producto = (*miDeposito)[i];
    m_tabla->SetCellValue(i, 0, wxString() << producto.getCodigo());
    m_tabla->SetCellValue(i, 1, wxString() << producto.getDescripcion());
    m_tabla->SetCellValue(i, 2, wxString() << producto.getExistencias());
    m_tabla->SetCellValue(i, 3, wxString() << producto.getStockMin());
    m_tabla->SetCellValue(i, 4, wxString() << producto.getStockMax());
    m_tabla->SetCellValue(i, 5, wxString() << producto.getPrecio());
}

/**
 * Cuando se hace click en buscar, se busca desde el producto que esta seleccionada en la tabla, si desde la posicion
 * seleccionada hacia adelante hay alguna coincidencia, se posiciona sobre la fila, si hay mas de una coincidencia,
 * cada vez que apretamos buscar se posiciona en la proxima conincidencia.
 * Si no hay coincidencia indica que no se encontro el producto.
 */
void WinPrincipal::OnClickBuscar(wxCommandEvent &event) {
    //Buscar desde la fila filaSeleccionada
    int filaSeleccionada = m_tabla->GetGridCursorRow(); //Obtenemos el indice del Producto
    if (m_tabla->GetSelectedRows().GetCount() == 0) {
        filaSeleccionada = -1;
    }
    int respuesta = miDeposito->buscarPorDescripcion((std::string) (m_busqueda->GetValue()), filaSeleccionada + 1);
    //Si no lo encontro buscar nuevamente desde el principio
    if (respuesta == NO_ENCONTRADO) {
        respuesta = miDeposito->buscarPorDescripcion((std::string) m_busqueda->GetValue(), 0);
    }
    if (respuesta == NO_ENCONTRADO) {
        wxMessageBox("No se encontró el producto");
    } else {
        m_tabla->SetGridCursor(respuesta, 0);//Posiciono el cursor en la fila donde se encontró el producto
        m_tabla->SelectRow(respuesta);//Selecciono la fila completa donde se encontró el producto
    }
}

/**
 * Si se hace click en el encabezado de algun campo de la tabla, la tabla se ordena segun ese dato.
 * Para esto se ordena el vector, se almacena en el archvio y por ultimo se vuelve a cargar los datos
 * en todas las filas
 */
void WinPrincipal::OnClickTabla(wxGridEvent &event) {
    int columna = event.GetCol();
    int cantidadProductos = miDeposito->cantidadProductos();
    //ordeno el deposito
    switch (columna) {
        case 0:
            miDeposito->ordenar(CODIGO);
            break;
        case 1:
            miDeposito->ordenar(DESCRIPCION);
            break;
        case 2:
            miDeposito->ordenar(EXISTENCIAS);
            break;
        case 5:
            miDeposito->ordenar(PRECIO);
            break;
    }
    for (int i = 0; i < cantidadProductos; ++i) {
        cargarFila(i); //actualizo la vista de la tabla
    }
}

/**
 * Al hacer click en "Agregar" se abre de forma modal la ventana para ingresar los datos de un producto nuevo.
 * Cuando finaliza la ventana modal, ya sea porque se hizo click en "Cancelar" o "Agregar", existe un retorno
 * que permite identificar si hay que agregar el producto a la tabla o no hacer nada.
 * @param event
 */
void WinPrincipal::OnClickAlta(wxCommandEvent &event) {
    WinAlta nuevaVentana(this, miDeposito); //Crear la ventana
    if (nuevaVentana.ShowModal() == 1) { //Mostrar y esperar
        m_tabla->AppendRows(1); //Agregamos el lugar en la tabla
        int posicionNuevo = (int) (miDeposito->cantidadProductos() - 1);
        cargarFila(posicionNuevo);//Copiar en la tabla en la ultima posicion
        m_tabla->SetGridCursor(posicionNuevo, 0);//Selecciona el nuevo registro
        m_tabla->SelectRow(posicionNuevo);//Selecciona el nuevo registro
    }
}

/**
 * Al hacer click en "Modificar", se abre de forma modal la ventana para ver y/o modificar los datos de un producto.
 * Cuando termina la ventana modal, el codigo de retorno indica si se modifico o no los datos.
 * En caso de ser afirmativo la ventana debe actualizar la m_tabla
 * @param event
 */
void WinPrincipal::OnClickEditar(wxCommandEvent &event) {
    int filaSeleccionada = m_tabla->GetGridCursorRow(); //Obtenemos el indice del Producto
    WinModificar nuevaVentana(this, miDeposito, filaSeleccionada);
    if (nuevaVentana.ShowModal()) { //Mostrar y esperar
        cargarFila(filaSeleccionada); //actulizar en la m_tabla
    }
}

/**
 * Cuando se hace click en "Baja", primero se pide confirmacion, y en caso afirmativo se elimina
 * el producto seleccionado de la tabla y del archivo.
 * @param event
 */
void WinPrincipal::OnClickBaja(wxCommandEvent &event) {
    int filaSeleccionada = m_tabla->GetGridCursorRow(); //Obtenemos el indice del Producto
    int respuesta = wxMessageBox(wxString() << ("¿Eliminar Producto?"), m_tabla->GetCellValue(filaSeleccionada, 0),
                                 wxYES_NO);
    if (respuesta == wxYES) {
        m_tabla->DeleteRows(filaSeleccionada, 1);
        miDeposito->eliminarProducto(filaSeleccionada);
        miDeposito->guardar();
    }
}

void WinPrincipal::OnClickCompra(wxCommandEvent &event) {
    event.Skip();
}

void WinPrincipal::OnClickVenta(wxCommandEvent &event) {
    event.Skip();
}

void WinPrincipal::OnClickListados(wxCommandEvent &event) {
    event.Skip();
}

/**
 * El doble click en una fila de la table es lo mismo que hacer click en modificar
 */
void WinPrincipal::OnDobleClickTabla(wxGridEvent &event) {
    int filaSeleccionada = m_tabla->GetGridCursorRow(); //Obtenemos el indice del Producto
    WinModificar nuevaVentana(this, miDeposito, filaSeleccionada); //Creamos la ventana
    if (nuevaVentana.ShowModal()) { //mostrar y dejar en espera
        cargarFila(filaSeleccionada); //Actualizamos en la m_tabla
    }

}

/**
 * El enter en el cuadro de texto equivale a hacer click en el boton "Buscar"
 */
void WinPrincipal::EnterBuscar(wxCommandEvent &event) {
    OnClickBuscar(event);
}

/**
 * Las columnas de la tabla no se ajustan solas cuando se redimensiona la ventana.
 * Este metodo calcula los nuevos tamanios proporcionalmente a los viejas valores
 * para que ocupen el espacio posible
 * @param event
 */
void WinPrincipal::OnCambiaTamanio(wxSizeEvent &event) {
    Layout();//Primero que ajuste la ventana, asi tengo el nuevo tamanio de la m_tabla
    int tamanios[6];
    int anchoTotalViejo = 0;
    for (int i = 0; i < 6; ++i) {
        tamanios[i] = m_tabla->GetColSize(i);
        anchoTotalViejo += tamanios[i];
    }
    int anchoTotalNuevo = m_tabla->GetSize().GetWidth(); //obtengo el ancho nuevo de la tabla
    m_tabla->BeginBatch(); //Permite que cuando cambiamos varias cosas, solo redibuje al final
    for (int i = 0; i < 6; ++i) {
        m_tabla->SetColSize(i,tamanios[i]*anchoTotalNuevo/anchoTotalViejo);
    }
    m_tabla->EndBatch();

}




