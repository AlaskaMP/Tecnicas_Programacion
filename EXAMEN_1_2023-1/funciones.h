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
void procesarDatos(int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos);
void pedirYProcesarFecha(int&fechaInicial,int&fechaFinal);
int convertirFecha(int d,int m,int a);
void procesarDatos(int fechaInicial,int fechaFinal,int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos);
int buscarProducto(int codigoProducto,int*codigosProductos,int cantProductos);




#endif /* FUNCIONES_H */

