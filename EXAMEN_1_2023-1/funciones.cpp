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
        cantProductos++;
    }
    
}
void pedirYProcesarFecha(int&fechaInicial,int&fechaFinal,int&d1,int&m1,int&a1,int&d2,int&m2,int&a2){
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
void procesarDatos(int fechaInicial,int fechaFinal,int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos,int*almacenesFiltrados,int*ingresos,int*salidas,int*enviados,int*recibidos,int*stocksFinales){
    ifstream archTransacciones("Transacciones.txt",ios::in);
    if(!archTransacciones.is_open()){
        cout<<"Error al abrir el archivo Transacciones.txt"<<endl;
        exit(1);
    }
    int codigoAlmacen,codigoAlmacen2,d,m,a,codigoProducto,catidadProducto;
    char caracter;
    char tipoMovimiento;
    int fechaEvaluando;
    int indiceProducto,indiceProducto2;
    int cantidadDeTransacciones;
    int i=0;
    while(1){
        archTransacciones>>codigoAlmacen;
        if(archTransacciones.eof())break;
        archTransacciones>>d>>caracter>>m>>caracter>>a;
        fechaEvaluando=convertirFecha(d,m,a);
        if(fechaEvaluando>=fechaInicial&&fechaEvaluando<=fechaFinal){
            if(!estaEnAlmacenesFiltrados(codigoAlmacen,almacenesFiltrados)){
                almacenesFiltrados[i]=codigoAlmacen;
                i++;
            } 
            
            while(1){
                archTransacciones>>ws;
                while(archTransacciones.get()!=' ');
                archTransacciones>>codigoProducto;
                archTransacciones>>cantidadDeTransacciones;
                indiceProducto=buscarProducto(codigoProducto,codigosProductos,codigoAlmacen,codigosAlmacenes,cantProductos);
                archTransacciones>>tipoMovimiento;
                if(tipoMovimiento=='I'){
                    ingresos[indiceProducto]+=cantidadDeTransacciones;
                }else if(tipoMovimiento=='S'){
                    salidas[indiceProducto]+=cantidadDeTransacciones;
                }else if(tipoMovimiento=='T'){
                    archTransacciones>>codigoAlmacen2;
                    if(!estaEnAlmacenesFiltrados(codigoAlmacen2,almacenesFiltrados)){
                    almacenesFiltrados[i]=codigoAlmacen2;
                    i++;
                    }
                    enviados[indiceProducto]+=cantidadDeTransacciones;
                    indiceProducto2=buscarProducto(codigoProducto,codigosProductos,codigoAlmacen2,codigosAlmacenes,cantProductos);
                    recibidos[indiceProducto2]+=cantidadDeTransacciones;             
                }
                if(archTransacciones.get()=='\n')break;
            }
        }
        else{
            while(archTransacciones.get()!='\n');
        }
    }
    ordenarAlmacenes(almacenesFiltrados);
    ordenarProductos(codigosProductos,codigosAlmacenes,stockProductos,cantProductos,ingresos,salidas,enviados,recibidos);
    int z=0;
    while(1){
        if(z==cantProductos)break;
        stocksFinales[z]=stockProductos[z]+ingresos[z]-salidas[z]+recibidos[z]-enviados[z];
        z++;
    }
}
int buscarProducto(int codigoProducto,int*codigosProductos,int codigoAlmacen,int*codigosAlmacenes,int cantProductos){
    for(int i=0;i<cantProductos;i++){
        if(codigoProducto==codigosProductos[i] and codigoAlmacen==codigosAlmacenes[i]){
            return i;
        }
    }
    return -1;
}
bool estaEnAlmacenesFiltrados(int codigoAlmacen,int*almacenesFiltrados){
   for(int i=0;i<10;i++){
        if(codigoAlmacen==almacenesFiltrados[i]){
            return true;
        }
   }
  return false;
}
void ordenarAlmacenes(int*almacenesFiltrados){
    for(int i=0;i<9;i++){
        for(int j=i+1;j<10;j++){
            if(almacenesFiltrados[i]>almacenesFiltrados[j]){
                int aux=almacenesFiltrados[i];
                almacenesFiltrados[i]=almacenesFiltrados[j];
                almacenesFiltrados[j]=aux;
            }
        }
    }
}
void ordenarProductos(int*codigosProductos,int*codigosAlmacenes,int*stockProductos,int cantProductos,int*ingresos,int*salidas,int*enviados,int*recibidos){
    for(int i=0;i<cantProductos-1;i++){
        for(int j=i+1;j<cantProductos;j++){
            if(codigosProductos[i]<codigosProductos[j]){
                int aux=codigosProductos[i];
                codigosProductos[i]=codigosProductos[j];
                codigosProductos[j]=aux;
                
                aux=codigosAlmacenes[i];
                codigosAlmacenes[i]=codigosAlmacenes[j];
                codigosAlmacenes[j]=aux;
                
                aux=stockProductos[i];
                stockProductos[i]=stockProductos[j];
                stockProductos[j]=aux;

                aux=ingresos[i];
                ingresos[i]=ingresos[j];
                ingresos[j]=aux;

                aux=salidas[i];
                salidas[i]=salidas[j];
                salidas[j]=aux;

                aux=enviados[i];
                enviados[i]=enviados[j];
                enviados[j]=aux;

                aux=recibidos[i];
                recibidos[i]=recibidos[j];
                recibidos[j]=aux;
            }
        }
    }
}
void imprimirReporte(int*almacenesFiltrados,int*codigosProductos,int*codigosAlmacenes,int*stockProductos
,int cantProductos,int d1,int m1,int a1,int d2,int m2,int a2,int*ingresos,int*salidas,int*enviados,int*recibidos,int*stocksFinales){
    cout<<setw(70)<<"CONSOLIDADO DE STOCKS DE PRODUCTOS POR ALMACEN"<<endl;
    cout<<setw(40)<<"DEL "<<setw(2)<<setfill('0')<<d1<<"/"<<setw(2)<<setfill('0')<<m1<<"/"<<setw(4)<<setfill('0')<<a1<<" AL "<<setw(2)<<setfill('0')<<d2<<"/"<<setw(2)<<setfill('0')<<m2<<"/"<<setw(2)<<setfill('0')<<a2<<endl<<setfill(' ')<<endl;
    cout<<setw(90)<<setfill('=')<<' '<<endl;
    for(int i=0;i<10;i++){
        if(almacenesFiltrados[i]!=0){
            cout<<"ALMACEN: "<<almacenesFiltrados[i]<<endl;
            cout<<setw(140)<<setfill('-')<<' '<<endl<<setfill(' ');
            cout<<"PRODUCTO"<<setw(20)<<"STOCK INICIAL"<<setw(20)<<"INGRESOS"<<setw(20)<<"SALIDAS"<<setw(20)<<"ENVIADOS"<<setw(20)<<"RECIBIDOS"<<setw(20)<<"STOCK FINAL"<<setw(20)<<"OBSERVACION"<<endl;
            cout<<setw(140)<<setfill('-')<<' '<<endl<<setfill(' ');
            for(int j=0;j<cantProductos;j++){
                //codigosProductos codigosAlmacenes
                //
                if(codigosAlmacenes[j]==almacenesFiltrados[i] and(ingresos[j]!=0 or salidas[j]!=0 or enviados[j]!=0 or recibidos[j]!=0)){
                    cout<<codigosProductos[j]<<setw(20)<<stockProductos[j]<<setw(20)<<ingresos[j]<<setw(20)<<salidas[j]<<setw(20)<<enviados[j]<<setw(20)<<recibidos[j]<<setw(20)<<stocksFinales[j];
                    if(stocksFinales[j]<0){
                        cout<<setw(20)<<"Tras. Incorrectas"<<endl;
                    
                    }else{
                        cout<<endl;
                    }
                
                }
            }
        } 
    }
}



