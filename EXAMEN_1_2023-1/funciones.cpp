/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
#include "funciones.h"

void leerStockProductos(int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int&cantProductos){
    ifstream archStock("StockProductos.txt",ios::in);
    if(!archStock.is_open()){
        cout<<"Error al abrir el archivo StockProductos.txt"<<endl;
        exit(1);
    }
    cantProductos=0;
    int codigoP,codigoA,stock;
    while(1){
        archStock>>codigoP;
        if(archStock.eof())break;
        archStock>>codigoA;
        archStock>>stock;
        codigosProductos[cantProductos]=codigoP;
        codigosAlmacenes[cantProductos]=codigoA;
        stockProductos[cantProductos]=stock;
    }
    
}
void pedirYProcesarFecha(int&fechaInicial,int&fechaFinal){
    int d1,m1,a1,d2,m2,a2;
    cout<<"Ingrese fecha inicial: "<<endl;
    cin>>d1>>m1>>a1;
    cout<<"Ingrese fecha final: "<<endl;
    cin>>d2>>m2>>a2;
    fechaInicial=convertirFecha(d1,m1,a1);
    fechaFinal=convertirFecha(d2,m2,a2);
}
int convertirFecha(int d,int m,int a){
    return a*10000+m*100+d;
}
void procesarDatos(int fechaInicial,int fechaFinal,int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos){
    ifstream archTransacciones("Transacciones.txt",ios::in);
    if(!archTransacciones.is_open()){
        cout<<"Error al abrir el archivo Transacciones.txt"<<endl;
        exit(1);
    }
    int codigoAlmacen,d,m,a,codigoProducto,catidadProducto;
    char caracter;
    char tipoMovimiento;
    int fechaEvaluando;
    int indiceProducto;
    while(1){
        archTransacciones>>codigoAlmacen;
        if(archTransacciones.eof())break;
        archTransacciones>>d>>caracter>>m>>caracter>>a;
        fechaEvaluando=convertirFecha(d,m,a);
        if(fechaEvaluando>=fechaInicial&&fechaEvaluando<=fechaFinal){
            archTransacciones>>ws;
            while(archTransacciones.get()!=' ');
            archTransacciones>>codigoProducto;
            archTransacciones>>cantProductos;
            indiceProducto=buscarProducto(codigoProducto,codigosProductos,cantProductos);
            archTransacciones>>tipoMovimiento;
            if(tipoMovimiento=='I'){

            }
        }
    }

}
int buscarProducto(int codigoProducto,int*codigosProductos,int cantProductos){
    for(int i=0;i<cantProductos;i++){
        if(codigoProducto==codigosProductos[i]){
            return i;
        }
    }
    return -1;
}


