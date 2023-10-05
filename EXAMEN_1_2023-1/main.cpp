/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: aml
 *
 * Created on 5 de octubre de 2023, 09:16 AM
 */

#include <iostream>
#include <fstream>
using namespace std;
#include "funciones.h"
/*
 * 
 */
int main(int argc, char** argv) {
    int codigosProductos[300],codigosAlmacenes[300],stockProductos[300];
    int cantProductos;
    int fechaInicial,fechaFinal;
    leerStockProductos(codigosProductos,codigosAlmacenes,stockProductos,cantProductos);
    pedirYProcesarFecha(fechaInicial,fechaFinal);
    procesarDatos(fechaInicial,fechaFinal,codigosProductos,codigosAlmacenes,stockProductos,cantProductos);


    return 0;
}

