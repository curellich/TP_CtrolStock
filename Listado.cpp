
#include "Listado.h"
#include <iostream>
#include <fstream>
#include "Deposito.h"
#include "Operacion.h"
#include <vector>

std::string Listado::nombreArchvioListadoReposicion = "Listado de Productos a reponer.txt";
std::string Listado::nombreArchvioListadoExistencias = "Listado Existencias.txt";
std::string Listado::nombreArchvioListadoVentas = "Listado Ventas.txt";
std::string Listado::nombreArchvioListadoCompras = "Listado Compras.txt";
std::string Listado::nombreArchivoBinarioOperaciones = "Operaciones.dat";


Listado::Listado(Deposito *miDeposito) : miDeposito(miDeposito) {
}

bool Listado::generarListadoExistencias() {

    std::ofstream archivo(nombreArchvioListadoExistencias.c_str(), std::ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < miDeposito->cantidadProductos(); ++i) {
            archivo << std::fixed << std::left << "- Codigo: " << std::setw(5)
                    << miDeposito->getListaProductos()[i].getCodigo()
                    << " Descripcion: " << std::setw(15) << miDeposito->getListaProductos()[i].getDescripcion()
                    << " Existencias: " << std::setw(5) << miDeposito->getListaProductos()[i].getExistencias()
                    << std::endl;
        }
        archivo.close();
        return true;
    } else {
        return false;
    }
}

bool Listado::generarListadoProductosAReponer() {
    std::ofstream archivo(nombreArchvioListadoReposicion.c_str(), std::ios::out);
    if (archivo.is_open()) {
        for (int i = 0; i < miDeposito->cantidadProductos(); ++i) {
            if (miDeposito->getListaProductos()[i].getExistencias() <
                miDeposito->getListaProductos()[i].getStockMin()) {
                archivo << std::fixed << std::left << "- Codigo: " << std::setw(5)
                        << miDeposito->getListaProductos()[i].getCodigo()
                        << " Descripcion: " << std::setw(15) << miDeposito->getListaProductos()[i].getDescripcion()
                        << " Cantidad a reponer: "
                        << std::setw(5) << (miDeposito->getListaProductos()[i].getStockMin() -
                                            miDeposito->getListaProductos()[i].getExistencias())
                        << " Precio de reposicion: "
                        << std::setprecision(02) << std::setw(10)
                        << (miDeposito->getListaProductos()[i].getStockMin() -
                            miDeposito->getListaProductos()[i].getExistencias()) *
                           miDeposito->getListaProductos()[i].getPrecio()
                        << std::endl;
            }
        }
        archivo.close();
        return true;
    } else {
        return false;
    }
}

bool Listado::generarListadoCompras() {
    registro_operacion registro;
    std::vector<registro_operacion> listaOperaciones;
    std::ifstream archivoLecturaOperaciones(nombreArchivoBinarioOperaciones.c_str(), std::ios::binary | std::ios::ate);

    if (archivoLecturaOperaciones.is_open()) {
        int tamanioArchivo = (int) (archivoLecturaOperaciones.tellg());
        int cantidadOperaciones = (int) (tamanioArchivo / sizeof(registro_operacion));

        listaOperaciones.resize(cantidadOperaciones);
        archivoLecturaOperaciones.seekg(0, std::ios::beg);

        for (int i = 0; i < cantidadOperaciones; ++i) {
            archivoLecturaOperaciones.read((char *) &registro, sizeof(registro));
            listaOperaciones[i].tipoOperacion = registro.tipoOperacion;
            listaOperaciones[i].codigoProductoOperacion = registro.codigoProductoOperacion;
            strcpy(listaOperaciones[i].descripcionProcutoOperacion, registro.descripcionProcutoOperacion);
            listaOperaciones[i].cantidadOperada = registro.cantidadOperada;
        }
        archivoLecturaOperaciones.close();
    } else {
        std::cout << "Hubo un error al intentar abrir el archivo" << std::endl;
    }


    std::ofstream archivoCompras(nombreArchvioListadoCompras.c_str(), std::ios::out);
    if (archivoCompras.is_open()) {
        for (int i = 0; i < listaOperaciones.size(); ++i) {
            if (listaOperaciones[i].tipoOperacion == 'c') {
                archivoCompras << listaOperaciones[i].tipoOperacion << ","
                               << listaOperaciones[i].codigoProductoOperacion << ","
                               << listaOperaciones[i].descripcionProcutoOperacion << ","
                               << listaOperaciones[i].cantidadOperada << std::endl;
            }
        }
        archivoCompras.close();
    } else {
        std::cout << "Hubo un error al abrir el archivo" << std::endl;
    }
}

bool Listado::generarListadoVentas() {
    registro_operacion registro;
    std::vector<registro_operacion> listaOperaciones;
    std::ifstream archivoLecturaOperaciones(nombreArchivoBinarioOperaciones.c_str(), std::ios::binary | std::ios::ate);

    if (archivoLecturaOperaciones.is_open()) {
        int tamanioArchivo = (int) (archivoLecturaOperaciones.tellg());
        int cantidadOperaciones = (int) (tamanioArchivo / sizeof(registro_operacion));

        listaOperaciones.resize(cantidadOperaciones);
        archivoLecturaOperaciones.seekg(0, std::ios::beg);

        for (int i = 0; i < cantidadOperaciones; ++i) {
            archivoLecturaOperaciones.read((char *) &registro, sizeof(registro));
            listaOperaciones[i].tipoOperacion = registro.tipoOperacion;
            listaOperaciones[i].codigoProductoOperacion = registro.codigoProductoOperacion;
            strcpy(listaOperaciones[i].descripcionProcutoOperacion, registro.descripcionProcutoOperacion);
            listaOperaciones[i].cantidadOperada = registro.cantidadOperada;
        }
        archivoLecturaOperaciones.close();
    } else {
        std::cout << "Hubo un error al intentar abrir el archivo" << std::endl;
    }


    std::ofstream archivoVentas(nombreArchvioListadoVentas.c_str(), std::ios::out);
    if (archivoVentas.is_open()) {
        for (int i = 0; i < listaOperaciones.size(); ++i) {
            if (listaOperaciones[i].tipoOperacion == 'c') {
                archivoVentas << listaOperaciones[i].tipoOperacion << ","
                              << listaOperaciones[i].codigoProductoOperacion << ","
                              << listaOperaciones[i].descripcionProcutoOperacion << ","
                              << listaOperaciones[i].cantidadOperada << std::endl;
            }
        }
        archivoVentas.close();
    } else {
        std::cout << "Hubo un error al abrir el archivo" << std::endl;
    }
}

