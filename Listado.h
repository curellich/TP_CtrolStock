
#ifndef TP_CTROLSTOCK_LISTADO_H
#define TP_CTROLSTOCK_LISTADO_H


#include <string>
#include "Operacion.h"

class Deposito;

class Listado {

private:
    ///@nota Nombre de los arhivos de tipo texto que van a ser generados
    static std::string nombreArchvioListadoExistencias;
    static std::string nombreArchvioListadoReposicion;
    static std::string nombreArchvioListadoCompras;
    static std::string nombreArchvioListadoVentas;
    static std::string nombreArchivoBinarioOperaciones;

    Deposito *miDeposito;

public:
    Listado(Deposito *miDeposito);
    //Listados todos tendran por salida archivos.
    ///@nota Lista las existencias de cada producto en un archivo txt
    bool generarListadoExistencias();
    ///@nota Lista los productos a reponer (exitencias menores al stockMin) en un archivo txt
    bool generarListadoProductosAReponer();
    ///@nota Lista las compras realizadas en un archivo txt
    bool generarListadoCompras();

    bool generarListadoVentas();

};


#endif //TP_CTROLSTOCK_LISTADO_H
