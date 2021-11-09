/**
 * @archivo Deposito.h
 * @nota Declaraciones de lo nececsario para la clase Deposito
 *
 * Este archivo define la clase Deposito, las constantes que usan en
 * los argumentos de sus metodos, y un puntero para acceder a una instancia de la clase,
 * para que todos los que incluyan esta cabecera hagan referencia al mismo objeto
 */
#ifndef INC_000_TP_CTROLSTOCK_DEPOSITO_H
#define INC_000_TP_CTROLSTOCK_DEPOSITO_H

#include <vector>
#include <string>
#include "Producto.h"

///@nota constante que indica que la busqueda ha fallado
#define NO_ENCONTRADO -1

///@nota enumeracion de los criterios de ordenamiento, se van a pasar como argumento al metodos
enum criterioOrdenamiento {
    CODIGO,
    DESCRIPCION,
    EXISTENCIAS,
    PRECIO
};

/**
 * @nota Clase que va a contener y administrar a los productos.
 *
 * Contiene un vector de Productos, los metodos para realizar la alta,
 * baja y modificaciones de un producto,los metodos para buscar y ordenar,
 * listados de productos,compra y venta de un producto, lectura y guardado en archivo binario.
 *
 * Los datos permaneceran siempre en memoria, luego de modificarlos se debe llamar al metodo guardar()
 * para que el archivo permanezca coherente.
 */

class Deposito {
private:
    ///@nota Nombre del archivo para hacer la lectura y escritura de los productos.
    std::string nombreArchivo;

    ///@nota Estructura lineal "vector" para contener los productos de
    std::vector<Producto> listaProductos;
public:
    ///@nota Constructor de la clase deposito, emplea un archivo para cargar los datos en memoria
    Deposito(std::string nombreArchivo);

    ///@nota Guarda los datos en el archivo
    bool guardar();

    ///@nota Devuelve la cantidad de productos (registro_productos)s
    int cantidadProductos();

    //CRUD de un producto
    ///@nota Da de alta un producto
    void altaProducto(const Producto &producto);

    ///@nota Devuelve un registro para ver o modificar
    Producto &operator[](int i);

    ///@nota Devuelve un registro para ver o modificar
    Producto &getProducto(int i);

    ///@nota Elimina un producto de la listaProductos
    void eliminarProducto(int i);
/*

    //Listados todos tendran por salida archivos.
    ///@nota Lista las existencias de cada producto en un archivo
    void listarExistencias();

    ///@nota Lista los productos a reponer (exitencias menores al stockMin) en un archivo
    void listarProductorAReponer();

    ///@nota Lista las ventas realizadas en un archivo
    void listarVentas();

    ///@nota Lista las compras realizadas en un archivo
    void listarCompras();
*/

    //Extras
    ///@nota Ordena la listaProductos
    void ordenar(criterioOrdenamiento criterio);

    ///@nota Busqueda por codigo para validacion
    int buscarPorCodigoParaValidacionDuplicados(int codigo, int indice);


    ///@nota Busqueda por descripcion para validacion
    int buscarPorDescripcionParaValidacionDuplicados(std::string descripcion, int indice);

    //funciones para realizar la busqueda de un producto por campo
    ///@nota Buscar producto por codigo
    int buscarPorCodigo(int codigo, int posicionDesde);

    ///@nota Buscar producto por descripciones
    int buscarPorDescripcion(std::string parte_de_la_descripcion, int posicioDesde);

    ///@validcion de deposito "evita productos duplicados, por codigo o descripcion de
    std::string validacionDeDeposito(int codigo, std::string descripcion, int indice);
};


#endif //INC_000_TP_CTROLSTOCK_DEPOSITO_H
