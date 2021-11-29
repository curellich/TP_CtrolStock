/**
 * @archivo Producto.cpp
 * @nota Implentaciones de  lo necesario para trabajar con una Clase producto.
 */

#include "Producto.h"
#include <string>
#include "Utileria.h"

//Constructor
Producto::Producto(int codigo, const std::string &descripcion, int existencias, int stockMin, int stockMax,
                   double precio)
        : codigo(codigo), descripcion(descripcion), existencias(existencias), stockMin(stockMin), stockMax(stockMax),
          precio(precio) {}

//Getters
int Producto::getCodigo() const {
    return codigo;
}

const std::string &Producto::getDescripcion() const {
    return descripcion;
}

int Producto::getExistencias() const {
    return existencias;
}

int Producto::getStockMin() const {
    return stockMin;
}

int Producto::getStockMax() const {
    return stockMax;
}

double Producto::getPrecio() const {
    return precio;
}



/**
 * Se verigica que ningun atributo este vacio, que los atributos de los valores enteros
 * y double no sean negativos y se verifica que la descripcion no supere el tamanio del
 * registro_producto para poder almacenarlo en el archivo binario.
 * @return Una cadena vacia si no hay errores o una cadena con los mensajes de los errores.
 */
std::string Producto::validacionDeConsistenciaDatos() {
    std::string errores;
    if (this->codigo == 0)
        errores += "Codigo incorrecto o vacio\n";
    if (this->codigo < 0)
        errores += "El codigo no puede ser negativo\n";
    if (descripcion.size() == 0)
        errores += "El campo descripcion no puede estar vacia\n";
    if (descripcion.size() > 256)
        errores += "El campo descripcion es demasiado larga\n";
    if (this->existencias == 0)
        errores += "Existencia incorrecta o vacia \n";
    if (this->existencias < 0)
        errores += "Las existencias no pueden ser negativas \n";
    if (this->existencias < this->stockMin)
        errores += "Las existencias no pueden ser menores que el stock Min \n";
    if (this->existencias > this->stockMax)
        errores += "Las existencias no pueden ser mayores que el stock Max \n";
    if (this->stockMin == 0)
        errores += "StockMin incorrecto o vacio\n";
    if (this->stockMin < 0)
        errores += "El strocMin no puede ser negativo\n";
    if (this->stockMax == 0)
        errores += "Stockmax incorrecto o vacio\n";
    if (this->stockMax < 0)
        errores += "El StockMax no puede ser negativo\n";
    if (this->precio == 0)
        errores += "Precio incorrecto o vacio\n";
    if (this->precio < 0)
        errores += "El precio no puede ser negativo\n";
    return errores;
}

/**
 * Guarda todos los atributos de un Producto en un archivo binario. El formato dentro de
 * del archivo binario es el del struct registro_producto.
 * !!!El archivo debe estar abierto y posicionado en el lugar donde guardar el registro.
 * @param archivo un archivo abierto en modo binario y modo escritura
 */
void Producto::guardarEnArchivoBinario(std::ofstream &archivo) {
    registro_producto registro;
    registro.codigo = this->codigo;
    strcpy(registro.descripcion, this->descripcion.c_str());
    registro.existencias = this->existencias;
    registro.stockMin = this->stockMin;
    registro.stockMax = this->stockMax;
    registro.precio = this->precio;
    archivo.write((char *) &registro, sizeof(registro));
}

/**
 * Lee todos los atributos de un producto desde un archivo binario. El formato dentro del
 * archivo binario es el de un struct registro_producto. El archivo debe estar abierto y
 * posicionado en el lugar donde se va a leer el registro.
 * @param archivo un archivo abierto en modo binario y lectura
 */
void Producto::leerDesdeUnArchivoBinario(std::ifstream &archivo) {
    registro_producto registro;
    archivo.read((char *) &registro, sizeof(registro));
    this->codigo = registro.codigo;
    this->descripcion = registro.descripcion;
    this->existencias = registro.existencias;
    this->stockMin = registro.stockMin;
    this->stockMax = registro.stockMax;
    this->precio = registro.precio;
}

///
void Producto::vender(int cantidadAVender) {
    Producto::existencias -= cantidadAVender;
}

///
void Producto::comprar(int cantidadAComprar) {
    Producto::existencias += cantidadAComprar;
}

/**
 * Se verigica que la compra no supere al stock maximo
 * @return Una cadena vacia si no hay errores o una cadena con los mensajes de los errores.
 */
std::string Producto::validacionOperacionesDeCompra() {
    std::string errores;
    if (this->existencias > this->stockMax) {
        errores += "La compra no puede superar el Stock Maximo\n";
        errores += "Stock Maximo: " + std::to_string(this->stockMax) + "\n";
    }
    return errores;

}

/**
 * Se verigica que las existencias no sean negativas
 * @return Una cadena vacia si no hay errores o una cadena con los mensajes de los errores.
 */
std::string Producto::validacionOperacionesDeVenta() {
    std::string errores;
    if (this->existencias < 0) {
        errores += "La venta no puede ser mayor a las existencias: \n";

    }
    return errores;
}

/**
 * Devuelve true si el codigo del producto1 es menor que el codigo del producto 2.
 * Se usa como argumento para la funcion sort para ordenar una listaProductos.
 */
bool criterio_comparacion_codigo(const Producto &producto1, const Producto &producto2) {
    int codigo1 = producto1.getCodigo();
    int codigo2 = producto2.getCodigo();
    return codigo1 < codigo2;
}

/**
 * Devuelve true si la descripcion del producto1 es menor que la descripcion del producto 2.
 * Se usa como argumento para la funcion sort para ordenar una listaProductos.
 */
bool criterio_comparacion_descripcion(const Producto &producto1, const Producto &producto2) {
    std::string descripcion1 = producto1.getDescripcion();
    std::string descripcion2 = producto2.getDescripcion();

    convertir_cadena_minusculas(descripcion1);
    convertir_cadena_minusculas(descripcion2);

    return descripcion1 < descripcion2;
}

/**
 * Devuelve true si las existencias del producto1 es menor que las existencias del producto 2.
 * Se usa como argumento para la funcion sort para ordenar una listaProductos.
 */
bool criterio_comparacion_existencia(const Producto &producto1, const Producto &producto2) {
    int existencias1 = producto1.getExistencias();
    int existencias2 = producto2.getExistencias();

    return existencias1 < existencias2;
}

/**
 * Devuelve true si el precio del producto1 es menor que el precio del producto 2.
 * Se usa como argumento para la funcion sort para ordenar una listaProductos.
 */
bool criterio_comparacion_precio(const Producto &producto1, const Producto &producto2) {
    double precio1 = producto1.getPrecio();
    double precio2 = producto2.getPrecio();

    return precio1 < precio2;
}
