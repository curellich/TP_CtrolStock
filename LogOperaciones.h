
#ifndef TP_CTROLSTOCK_OPERACIONES_H
#define TP_CTROLSTOCK_OPERACIONES_H

#include <string>

class Deposito;

class Operaciones {
private:
    Deposito *miDeposito;
    int indiceProducto; //Aqui se almacena el indice del producto para saber que producto se opera
    char tipoOperacion;
    int cantidadOperada;
public:
    Operaciones(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada);

    bool guardarCompra();
    bool guardarVenta();
};


#endif //TP_CTROLSTOCK_OPERACIONES_H
