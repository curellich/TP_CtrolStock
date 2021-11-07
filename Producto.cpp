/**
 * @archivo Producto.cpp
 * @nota Implentaciones de  lo necesario para trabajar con una Clase producto.
 */

#include "Producto.h"
#include "string.h"
#include "Utileria.h"

//Constructor
Producto::Producto(int codigo, const std::string &descripcion, int existencias, int stockMin, int stockMax, int precio)
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

int Producto::getPrecio() const {
    return precio;
}

//setters
void Producto::setCodigo(int codigo) {
    Producto::codigo = codigo;
}

void Producto::setDescripcion(const std::string &descripcion) {
    Producto::descripcion = descripcion;
}

void Producto::setExistencias(int existencias) {
    Producto::existencias = existencias;
}

void Producto::setStockMin(int stockMin) {
    Producto::stockMin = stockMin;
}

void Producto::setStockMax(int stockMax) {
    Producto::stockMax = stockMax;
}

void Producto::setPrecio(int precio) {
    Producto::precio = precio;
}

/**
 * Se verigica que ningun atributo este vacio, que los atributos de los valores enteros
 * y double no sean negativos y se verifica que la descripcion no supere el tamanio del
 * registro_producto para poder almacenarlo en el archivo binario.
 * @return Una cadena vacia si no hay errores o una cadena con los mensajes de los errores.
 */
std::string Producto::validacionDeIngreso() {
    std::string errores;
    if (this->codigo < 0)
        errores += "El campo codigo no puede estar vacio y debe ingresar un valor mayor a cero\n";
    if (descripcion.size() == 0)
        errores += "El campo descripcion no puede estar vacia\n";
    if (descripcion.size() > 256)
        errores += "El campo descripcion es demasiado larga\n";
    if (this->existencias < 0)
        errores += "El campo existencias no pueden estar vacio y debe ingresar un valor mayor a cero\n";
    if (this->stockMin < 0)
        errores += "El campo stockMin no puede estar vacio y debe ingresar un valor mayor a cero\n";
    if (this->stockMax < 0)
        errores += "El campo stockMax no puede estar vacio y debe ingresar un valor mayor a cero\n";
    if (this->precio < 0)
        errores += "El campo stockMax no puede estar vacio y debe ingresar un valor mayor a cero\n";
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
