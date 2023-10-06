/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   funciones.h
 * Author: aml
 *
 * Created on 5 de octubre de 2023, 09:18 AM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <fstream>
using namespace std;
void leerStockProductos(int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int&cantProductos);
void pedirYProcesarFecha(int&fechaInicial,int&fechaFinal,int&d1,int&m1,int&a1,int&d2,int&m2,int&a2);
int convertirFecha(int d,int m,int a);
void procesarDatos(int fechaInicial,int fechaFinal,int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos,int*almacenesFiltrados,int*ingresos,int*salidas,int*enviados,int*recibidos,int*stocksFinales);
int buscarProducto(int codigoProducto,int*codigosProductos,int codigoAlmacen,int*codigosAlmacenes,int cantProductos);
bool estaEnAlmacenesFiltrados(int codigoAlmacen,int*almacenesFiltrados);
void ordenarAlmacenes(int*almacenesFiltrados);
void ordenarProductos(int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos,int*ingresos,int*salidas,int*enviados,int*recibidos);
void imprimirReporte(int*almacenesFiltrados,int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos,int d1,int m1,int a1,int d2,int m2,int a2,int*ingresos,int*salidas,int*enviados,int*recibidos,int*stocksFinales);






#endif /* FUNCIONES_H */

