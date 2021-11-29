/**
 * @archivo Deposito.cpp
 * @nota Declaraciones de lo nececsario para la clase Deposito
 *
 */

#include <algorithm>
#include "Utileria.h"
#include "Deposito.h"
#include <iomanip>
#include <iostream>

/**
 * Constructor de la clase deposito, que llena la lista de productos obteniendo la informacion desde un arhcivo binario.
 * @param nombreArchivo cadena con el nombre del archivo binario principal del programa "datos.dat"
 */
Deposito::Deposito(std::string nombreArchivo) {
    Deposito::nombreArchivo = nombreArchivo;

    std::ifstream archivo(nombreArchivo.c_str(), std::ios::binary | std::ios::ate);

    if (archivo.is_open()) {
        int tamanioArchivo = (int) (archivo.tellg());
        int cantidadProductos = (int) (tamanioArchivo / sizeof(registro_producto));

        listaProductos.resize(cantidadProductos);
        archivo.seekg(0, std::ios::beg);

        for (int i = 0; i < cantidadProductos; ++i) {
            listaProductos[i].leerDesdeUnArchivoBinario(archivo);
        }
        archivo.close();
    } else {
        std::cout << "Hubo un error al intentar abrir el archivo" << std::endl;
    };
}

/**
 * Funcion que devuelve la cantidad de productos del vector listaProductos
 * @return un entero con la cantidad de productos
 */
int Deposito::cantidadProductos() {
    return (int) listaProductos.size();
}

/**
 * Funcion que guarda un registro_produto en el archivo principal del programa, donde se almacenan los productos.
 * @return verdadero o falso para confirmar el guardado exitoso.
 */
bool Deposito::guardar() {
    std::ofstream archivo(nombreArchivo.c_str(), std::ios::binary | std::ios::trunc);
    int cantProductos = cantidadProductos();
    if (archivo.is_open()) {
        for (int i = 0; i < cantProductos; ++i) {
            listaProductos[i].guardarEnArchivoBinario(archivo);
        }
        archivo.close();
        return true;
    } else {
        std::cout << "Hubo un error al abrir el archivo" << std::endl;
        return false;
    }
}

/**
 * Funcion que agrega un producto a la lista de productos.
 * @param producto
 */
void Deposito::altaProducto(const Producto &producto) {
    listaProductos.push_back(producto);
}

/**
 * Funcion que sobre escribe el operador[] para poder acceder mediante indices en la clase deposito pasada pro referencia.
 * @param i es el indice del producto
 * @return
 */
Producto &Deposito::operator[](int i) {
    return listaProductos[i];
}

/**
 * Funcion que elimina un producto de la lista de productos
 * @param i es el indice del producto a eliminar
 */
void Deposito::eliminarProducto(int i) {
    listaProductos.erase(listaProductos.begin() + i);
}

/**
 * Funcion que permite ordenar el vector de lista de productos mediante diferentes criterios, emplea los criterios
 * de comparacion
 * @param criterio
 */
void Deposito::ordenar(criterioOrdenamiento criterio) {
    switch (criterio) {
        case CODIGO:
            sort(listaProductos.begin(), listaProductos.end(), criterio_comparacion_codigo);
            break;
        case DESCRIPCION:
            sort(listaProductos.begin(), listaProductos.end(), criterio_comparacion_descripcion);
            break;
        case EXISTENCIAS:
            sort(listaProductos.begin(), listaProductos.end(), criterio_comparacion_existencia);
            break;
        case PRECIO:
            sort(listaProductos.begin(), listaProductos.end(), criterio_comparacion_precio);
    }
}

/**
 * Funcion para buscar un produto por su descripcion o parte de ella.
 * @param parte_de_la_descripcion cadena con parte de la descripcion del producto
 * @param posicioDesde valor entero correspondiente al indice de la posicion actual en la grilla
 * @return valor entero correspondiente indice del producto encontrado
 */
int Deposito::buscarPorParteDeLaDescripcion(std::string parte_de_la_descripcion, int posicioDesde) {
    convertir_cadena_minusculas(parte_de_la_descripcion);
    int cantProductos = cantidadProductos();
    for (int i = posicioDesde; i < cantProductos; ++i) {
        Producto &producto = listaProductos[i];
        std::string descripcion = producto.getDescripcion();
        convertir_cadena_minusculas(descripcion);
        if (descripcion.find(parte_de_la_descripcion, 0) != std::string::npos) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

/**
 * Funcion para buscar un producto por codigo, esta funcion se emplea para comprobar si existen un producto duplicado.
 * @param codigo valor entero del codigo a buscar
 * @param posicionDesde valor entero correspondiente al indice de la posicion actual en la grilla
 * @return valor entero correspondiente al indice del producto encontrado
 */
int Deposito::buscarPorCodigo(int codigo, int indice) {
    int cantProductos = cantidadProductos();
    for (int i = 0; i < cantProductos; ++i) {
        if (i == indice) //Con esto evito que se considere un error el querer mantener el mismo codigo en el producto.
            continue;
        Producto &producto = listaProductos[i];
        int codigoProducto = producto.getCodigo();
        if (codigo == codigoProducto) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

/**
 * Funcion para buscar un producto por su descripcion completa
 * @param descripcion cadena que corresponde a la descricpion total del producto a buscar
 * @param indice valor entero que corresponde al indice de la posicion actual seleccionada en la grilla
 * @return valor entero correspondiente al indice del producto encontrado
 */
int Deposito::buscarPorDescripcionCompleta(std::string descripcion, int indice) {
    convertir_cadena_minusculas(descripcion);
    int cantProductos = cantidadProductos();
    for (int i = 0; i < cantProductos; ++i) {
        if (i == indice)// evito que se considere un error el querer mantener la misma descripcion en el producto.
            continue;
        Producto &producto = listaProductos[i];
        std::string descripcionProducto = producto.getDescripcion();
        convertir_cadena_minusculas(descripcionProducto);
        if (descripcion == descripcionProducto) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

/**
 * Funcion que permite validar que no existan productos duplicados por codigo o descripcion, ya sea para dar de alta
 * un producto o para modificar sus atributos.
 * @param codigo valor entero correspondiente al codigo del producto a validar
 * @param descripcion cadena correspondiente a la descripcion total del producto a validar
 * @param indice valor entero correspondiente a la posicion actual seleccionada en la grilla
 * @return un string con los errores encontrados
 */
std::string Deposito::validacionDeDeposito(int codigo, std::string descripcion, int indice) {
    std::string errores;
    if (this->buscarPorCodigo(codigo, indice) >= 0)
        errores += "Codigo de producto Duplicado\n";
    if (this->buscarPorDescripcionCompleta(descripcion, indice) >= 0)
        errores += "Descripcion de producto duplicada\n";

    return errores;
}

/**
 *Getter correspondiente a la lista de produtos de und de.posito
 * @return
 */
const std::vector<Producto> &Deposito::getListaProductos() const {
    return listaProductos;
}





