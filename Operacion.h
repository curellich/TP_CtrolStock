
#ifndef TP_CTROLSTOCK_OPERACIONES_H
#define TP_CTROLSTOCK_OPERACIONES_H

#include <string>
#include "Deposito.h"

/**
 * Estructura empleada para almacenar una operacion en una archivo binario.
 */
struct registro_operacion {
    char tipoOperacion;
    int codigoProductoOperacion;
    char descripcionProcutoOperacion[256];
    int cantidadOperada;
};

class Operacion {
private:
    ///@nota Nombre del archivo binario donde se reqistran todas las operaciones
    static std::string nombreArchivo;

    Deposito *miDeposito;
    int indiceProducto; //Aqui se almacena el indice del producto para saber con que producto se realiza la operacion

    //Atributos de una operacion
    int codigoOperacion;
    std::string descripcionProdutoOperacion;
    char tipoOperacion;
    int cantidadOperada;

public:

    Operacion(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada);

    ///@nota Funcion que se encarga de almacenar una compra en un archivo binario
    bool guardarCompraEnArchivoBinario();

    ///@nota funcion que se encarga de almacenar una venta en un archivo binario
    bool guardarVentaEnArchivoBinario();

};


#endif //TP_CTROLSTOCK_OPERACIONES_H
