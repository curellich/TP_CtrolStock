#include "Operacion.h"
#include "Deposito.h"
#include "Producto.h"
#include <fstream>
#include <iostream>

std::string Operacion::nombreArchivo = "Operaciones.dat";

Operacion::Operacion(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada)
        : miDeposito(miDeposito), indiceProducto(indiceProducto), tipoOperacion(tipoOperacion),
          cantidadOperada(cantidadOperada) {
}

/**
 * Funcion que se encarga de almacenar una compra en un archivo binario.
 * @return
 */
bool Operacion::guardarCompraEnArchivoBinario() {
    std::ofstream archivo(this->nombreArchivo.c_str(), std::ios::binary | std::ios::app);
    if (archivo.is_open()) {
        Producto &producto = (*miDeposito)[indiceProducto];
        registro_operacion registro;
        registro.tipoOperacion = 'c';
        registro.codigoProductoOperacion = producto.getCodigo();
        strcpy(registro.descripcionProcutoOperacion, producto.getDescripcion().c_str());
        registro.cantidadOperada = this->cantidadOperada;
        archivo.write((char *) &registro, sizeof(registro));
        return true;
    } else {
        std::cout << "Hubo un error al abrir el archivo" << std::endl;
        return false;
    }
}

/**
 * Funcion que se encarga de almacenar una venta en un archivo binario.
 * @return
 */
bool Operacion::guardarVentaEnArchivoBinario() {
    std::ofstream archivo(this->nombreArchivo.c_str(), std::ios::binary | std::ios::app);
    if (archivo.is_open()) {
        Producto &producto = (*miDeposito)[indiceProducto];
        registro_operacion registro;
        registro.tipoOperacion = 'v';
        registro.codigoProductoOperacion = producto.getCodigo();
        strcpy(registro.descripcionProcutoOperacion, producto.getDescripcion().c_str());
        registro.cantidadOperada = this->cantidadOperada;
        archivo.write((char *) &registro, sizeof(registro));
        return true;
    } else {
        std::cout << "Hubo un error al abrir el archivo" << std::endl;
        return false;
    }
}


