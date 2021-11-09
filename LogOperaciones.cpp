//
// Created by Jonathan Curellich on 08/11/2021.
//

#include "LogOperaciones.h"
#include "Deposito.h"
#include "Producto.h"
#include <fstream>

Operaciones::Operaciones(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada)
        : miDeposito(miDeposito), indiceProducto(indiceProducto), tipoOperacion(tipoOperacion),
          cantidadOperada(cantidadOperada) {
}

bool Operaciones::guardarCompra() {
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

bool Operaciones::guardarVenta() {
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





