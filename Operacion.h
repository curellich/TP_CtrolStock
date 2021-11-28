
#ifndef TP_CTROLSTOCK_OPERACIONES_H
#define TP_CTROLSTOCK_OPERACIONES_H

#include <string>

class Deposito;

struct registro_operacion{
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
    int indiceProducto; //Aqui se almacena el indice del producto para saber que producto se opera
    //Atributos de una operacion
    char tipoOperacion;
    int cantidadOperada;
public:
    Operacion(Deposito *miDeposito, int indiceProducto, char tipoOperacion, int cantidadOperada);
    bool guardarCompraEnArchivoBinario();
    bool guardarVentaEnArchivoBinario();
    bool guardarCompraEnArchivoTexto();
    bool guardarVentaEnArchivoTexto();
};


#endif //TP_CTROLSTOCK_OPERACIONES_H
