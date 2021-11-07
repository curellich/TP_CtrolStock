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
* Toma los datos de una persona desde la instancia de Agenda y los carga en su
* correspondiente fila de la m_grilla. Se usa al cargar por primera vez, al editar,
* o al agregar personas. La m_grilla ya debe tener lugar, es decir, debe existir el
* renglon (estara vacio o tendra basura).
* @param i el indice de la persona en el arreglo de la clase Agenda (en base 0)
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


void WinPrincipal::OnClickBuscar(wxCommandEvent &event) {
    event.Skip();
}

void WinPrincipal::OnClickTabla(wxGridEvent &event) {
    event.Skip();
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



