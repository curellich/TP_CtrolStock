//
// Created by Jonathan Curellich on 08/11/2021.
//

#include "Operacion.h"
#include "Deposito.h"
#include "Producto.h"
#include <fstream>
#include <iostream>

std::string Operacion::nombreArchivo = "Operacion.dat";

Operacion::Operacion(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada)
        : miDeposito(miDeposito), indiceProducto(indiceProducto), tipoOperacion(tipoOperacion),
          cantidadOperada(cantidadOperada) {
}

bool Operacion::guardarCompraEnArchivoTexto() {
    Producto &producto = (*miDeposito)[indiceProducto];
    std::ofstream archivo("compras.txt", std::ios::app | std::ios::out);
    if (archivo.is_open()) {
        archivo << this->tipoOperacion << "," << producto.getCodigo() << "," << producto.getDescripcion()
                << "," << this->cantidadOperada << std::endl;
        archivo.close();
        return true;
    } else {
        return false;
    }
}

bool Operacion::guardarVentaEnArchivoTexto() {
    Producto &producto = (*miDeposito)[indiceProducto];
    std::ofstream archivo("ventas.txt", std::ios::app | std::ios::out);
    if (archivo.is_open()) {
        archivo << this->tipoOperacion << "," << producto.getCodigo() << "," << producto.getDescripcion()
                << "," << this->cantidadOperada << std::endl;
        archivo.close();
        return true;
    } else {
        return false;
    }
}


bool Operacion::guardarCompraEnArchivoBinario() {
    std::ofstream archivo(this->nombreArchivo.c_str(), std::ios::binary | std::ios::trunc);
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

bool Operacion::guardarVentaEnArchivoBinario() {
    std::ofstream archivo(this->nombreArchivo.c_str(), std::ios::binary | std::ios::trunc);
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
