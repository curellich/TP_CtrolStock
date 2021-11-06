/**
* @file Utileria.cpp
* @nota Funciones de utiliaria para simplificar tareas
*
* Las funciones de este archivo son generales y no corresponden a ninguna clase específica
**/
#include "Utileria.h"
#include <string>

/**
* Funcion auxiliar para las utilizar en las comparaciones y busquedas de modo
* que no importe si los nombres estan en mayusculas o minusculas.
**/

void convertir_cadena_minusculas(std::string &cadena) {
    int i, c = cadena.size();
    for (i = 0; i < c; i++)
        cadena[i] = std::tolower(cadena[i]);
}
