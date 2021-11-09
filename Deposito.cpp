/**
 * @archivo Deposito.cpp
 * @nota Declaraciones de lo nececsario para la clase Deposito
 *
 */
#include <fstream>
#include <algorithm>
#include "Utileria.h"
#include "Deposito.h"
#include <fstream>
#include <iomanip>


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
    }
}

int Deposito::cantidadProductos() {
    return (int) listaProductos.size();
}

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
        return false;
    }
}


void Deposito::altaProducto(const Producto &producto) {
    listaProductos.push_back(producto);
}

Producto &Deposito::operator[](int i) {
    return listaProductos[i];
}

Producto &Deposito::getProducto(int i) {
    return listaProductos[i];
}

void Deposito::eliminarProducto(int i) {
    listaProductos.erase(listaProductos.begin() + i);
}

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

int Deposito::buscarPorCodigo(int codigo, int posicionDesde) {
    int cantProductos = cantidadProductos();
    for (int i = posicionDesde; i < cantProductos; ++i) {
        Producto &producto = listaProductos[i];
        int codigoProducto = producto.getCodigo();
        if (codigo == codigoProducto) {
            return i;
        }
    }
    return NO_ENCONTRADO;
}

int Deposito::buscarPorDescripcion(std::string parte_de_la_descripcion, int posicioDesde) {
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

int Deposito::buscarPorCodigoParaValidacionDuplicados(int codigo, int indice) {
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

int Deposito::buscarPorDescripcionParaValidacionDuplicados(std::string descripcion, int indice) {
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

std::string Deposito::validacionDeDeposito(int codigo, std::string descripcion, int indice) {
    std::string errores;
    if (this->buscarPorCodigoParaValidacionDuplicados(codigo, indice) >= 0)
        errores += "Codigo de producto Duplicado\n";
    if (this->buscarPorDescripcionParaValidacionDuplicados(descripcion, indice) >= 0)
        errores += "Descripcion de producto duplicada\n";

    return errores;
}

bool Deposito::listarExistencias() {
    std::ofstream archivo("listadoDeProductos.txt", std::ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < this->cantidadProductos(); ++i) {
            archivo << std::fixed << std::left << "- Codigo: " << std::setw(5) << listaProductos[i].getCodigo()
                    << " Descripcion: " << std::setw(15) << listaProductos[i].getDescripcion()
                    << " Existencias: " << std::setw(5) << listaProductos[i].getExistencias()
                    << std::endl;
        }
        archivo.close();
        return true;
    } else {
        return false;
    }
}

bool Deposito::listarProductorAReponer() {
    std::ofstream archivo("listaProductosAReponer.txt", std::ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < this->cantidadProductos(); ++i) {
            if (listaProductos[i].getExistencias() < listaProductos[i].getStockMin()) {
                archivo << std::fixed << std::left << "- Codigo: " << std::setw(5) << listaProductos[i].getCodigo()
                        << " Descripcion: " << std::setw(15) << listaProductos[i].getDescripcion()
                        << " Cantidad a reponer: "
                        << std::setw(5) << (listaProductos[i].getStockMin() - listaProductos[i].getExistencias())
                        << " Precio de reposicion: "
                        << std::setprecision(02) << std::setw(10)
                        << (listaProductos[i].getStockMin() - listaProductos[i].getExistencias()) *
                           listaProductos[i].getPrecio()
                        << std::endl;
            }
        }
        archivo.close();
        return true;
    } else {
        return false;
    }
}





