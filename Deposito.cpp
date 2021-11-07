/**
 * @archivo Deposito.cpp
 * @nota Declaraciones de lo nececsario para la clase Deposito
 *
 */
#include <fstream>
#include <algorithm>
#include "Utileria.h"
#include "Deposito.h"

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




