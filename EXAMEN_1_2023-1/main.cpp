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
    int cantProductos,almacenesFiltrados[10]{};
    int fechaInicial,fechaFinal;
    int d1,m1,a1,d2,m2,a2;
    int ingresos[300]{},salidas[300]{};
    int enviados[300]{},recibidos[300]{};
    int stocksFinales[300];
    leerStockProductos(codigosProductos,codigosAlmacenes,stockProductos,cantProductos);
    pedirYProcesarFecha(fechaInicial,fechaFinal,d1,m1,a1,d2,m2,a2);
    procesarDatos(fechaInicial,fechaFinal,codigosProductos,codigosAlmacenes,stockProductos,cantProductos,almacenesFiltrados,ingresos,salidas,enviados,recibidos,stocksFinales);
    imprimirReporte(almacenesFiltrados,codigosProductos,codigosAlmacenes,stockProductos,cantProductos,d1,m1,a1,d2,m2,a2,ingresos,salidas,enviados,recibidos,stocksFinales);



    return 0;
}

