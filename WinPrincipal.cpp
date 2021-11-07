#include "WinPrincipal.h"
#include "Deposito.h"
#include "Producto.h"

/**
* Inicializa la ventana, asignandole un icono, llenando la m_grilla y definiendo
* las propiedades adicionales de la tabla.
**/

WinPrincipal::WinPrincipal(Deposito *deposito) : miDeposito(deposito) {
	int cantProductos = miDeposito->cantidadProductos(); //Determino la cantidad de productos
	m_tabla->AppendRows(cantProductos); //Agrego tantas filas como registro_producto tengo(la tabla estaba inicialmente vacia)
	for(int i=0;i<cantProductos;i++){ //Cargo los productos en las filas
		cargarFila(i);
	}
	m_tabla->SetSelectionMode(wxGrid::wxGridSelectRows); //De esta forma hago que la seleccion sea por fila y no por celda
}

/**
* Toma los datos de una persona desde la instancia de Agenda y los carga en su
* correspondiente fila de la m_grilla. Se usa al cargar por primera vez, al editar,
* o al agregar personas. La m_grilla ya debe tener lugar, es decir, debe existir el
* renglon (estara vacio o tendra basura).
* @param i el indice de la persona en el arreglo de la clase Agenda (en base 0)
**/
void WinPrincipal::cargarFila(int i){
	Producto &producto = (*miDeposito)[i];
	m_tabla->SetCellValue(i,0,std_to_wx(producto.getCodigo());
	m_tabla->SetCellValue(i,1,std_to_wx(producto.getDescripcion());
	m_tabla->SetCellValue(i,2,std_to_wx(producto.getExistencias());
	m_tabla->SetCellValue(i,3,std_to_wx(producto.getStockMin());
	m_tabla->SetCellValue(i,4,std_to_wx(producto.getStockMax());
	m_tabla->SetCellValue(i,5,std_to_wx(producto.getPrecio());
}

WinPrincipal::~WinPrincipal() {
	
}

void WinPrincipal::OnClickBuscar( wxCommandEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickTabla( wxGridEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickAlta( wxCommandEvent& event )  {
	WinAlta nuevaVentana(this,miDeposito); //Crear la ventana
	if(nuevaVentana.ShowModal()==1){ //Mostrar y esperar
		m_tabla->AppendRows(1); //Agregamos el lugar en la tabla
		int posicionNuevo = (int)(cantidadProductos()-1);
		cargarFila(posicionNuevo);//Copiar en la tabla en la ultima posicion
		m_tabla->SetGridCursor(posicionNuevo,0);//Selecciona el nuevo registro
		m_tabla->SelectRow(posicionNuevo);//Selecciona el nuevo registro
	}
}

void WinPrincipal::OnClickEditar( wxCommandEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickBaja( wxCommandEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickCompra( wxCommandEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickVenta( wxCommandEvent& event )  {
	event.Skip();
}

void WinPrincipal::OnClickListados( wxCommandEvent& event )  {
	event.Skip();
}

