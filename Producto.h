/**
 * @archivo Producto.h
 * @nota Declaraciones de  lo necesario para trabajar con la clase Producto
 *
 * Este archivo define a la clase Producto, las funciones auxiliares para compararlos
 * y el struct necesario para hacer de intermediario al momento de guardar y leer en
 * archivos binarios.
 */
#ifndef INC_000_TP_CTROLSTOCK_PRODUCTO_H
#define INC_000_TP_CTROLSTOCK_PRODUCTO_H

#include <string>
#include <fstream>
#include "Utileria.h"


/**
 * @nota Estructura auxiliar para usar con archivos binarios
 * En archivos binarios no se debe guardar ni escribir objetos del tipo <string>,
 * porque al ser dinamicos contienen punteros y lo que en realidad se guadaria seria
 * una direccion de memoria. Esta estructura sirve para guardar y escribir los datos
 * de un producto con una estructura fija.
 */
struct registro_producto {
    int codigo;
    char descripcion[256];
    int existencias;
    int stockMin;
    int stockMax;
    double precio;
};

/**
 * @nota Clase que representa a un producto.
 * Contiene los atributos de un producto, y metodos como getters y setters, validacion de estos datos,
 * y metodos necesarios para escribir en archivos binarios.
 */
class Producto {

private:
    int codigo;
    std::string descripcion;
    int existencias;
    int stockMin;
    int stockMax;
    double precio;

public:
    ///Constructor de la clase Producto
    //Se establecen valores negativos por defecto para poder hacer la validacion de ingreso de datos por el usuario al
    //instanciar un producto.
    Producto(int codigo = -1, const std::string &descripcion = "", int existencias = -1, int stockMin = -1,
             int stockMax = -1, double precio = -1);

    ///Valida que los datos cargados sean coherentes y completos
    std::string validacionDeConsistenciaDatos();

    ///Validacion de operaciones de compra  de un producto donde se modifica su existencia
    std::string validacionOperacionesDeCompra();

    ///Validacion de operaciones de  venta de un producto donde se modifica su existencia
    std::string validacionOperacionesDeVenta();

    //getters
    int getCodigo() const;

    const std::string &getDescripcion() const;

    int getExistencias() const;

    int getStockMin() const;

    int getStockMax() const;

    double getPrecio() const;

    //setters
    void setCodigo(int codigo);

    void setDescripcion(const std::string &descripcion);

    void setExistencias(int existencias);

    void setStockMin(int stockMin);

    void setStockMax(int stockMax);

    void setPrecio(double precio);

    //Operacion con un producto (esto modifica sus existencias)
    ///@nota Vende un Producto existente
    void vender(int cantidadAVender);

    ///@nota Compra un Producto existente
    void comprar(int cantidadAComprar);


    ///Guarda un registro en un archivo Binario
    void guardarEnArchivoBinario(std::ofstream &archivo);

    ///Lee un registro desde un archivo Binario
    void leerDesdeUnArchivoBinario(std::ifstream &archivo);
};

//Criterios para comparar productos de

///@nota Funcion para compara dos productos por su codigo
bool criterio_comparacion_codigo(const Producto &producto1, const Producto &producto2);

///@nota Funcion para compara dos productos por su descripcion
bool criterio_comparacion_descripcion(const Producto &producto1, const Producto &producto2);

///@nota Funcion para compara dos productos por su existencia
bool criterio_comparacion_existencia(const Producto &producto1, const Producto &producto2);

///@nota Funcion para comparar dos productos por su precio de reposicion
bool criterio_comparacion_precio(const Producto &producto1, const Producto &producto2);

#endif //INC_000_TP_CTROLSTOCK_PRODUCTO_H
