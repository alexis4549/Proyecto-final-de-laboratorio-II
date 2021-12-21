#ifndef CLASSPRODUCTO_H_INCLUDED
#define CLASSPRODUCTO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "funciones.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
class Producto{
private:
    int ID, Stock;
    char Descripcion[30];
    float Precio;
    bool Estado=true;
public:
    void Cargar();
    void Mostrar();
    void MostrarProductoRecuadro(int fila);
    ///SETS/GETS
    void setID(int n){ID=n;}
    void setStock(int n){Stock=n;}
    void setDescripcion(const char* n){strcpy(Descripcion,n);}
    void setPrecio(float n){Precio=n;}
    void setEstado(bool n){Estado=n;}
    int getID(){return ID;}
    int getStock(){return Stock;}
    char* getDescripcion(){return Descripcion;}
    float getPrecio(){return Precio;}
    bool getEstado(){return Estado;}
};
///CARGAR
void Producto::Cargar(){
    int contador;
    FILE *p;
    Producto reg;
    p=fopen("Producto.dat","rb");
    bool continuar=true;
    while (continuar==true){
    contador=0;
    cout<<"ID DE PRODUCTO:";
    cin>>ID;
    if(ID<9999){
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==ID){
            contador++;
            cout<<"ID YA EXISTENTE!"<<endl;
            fseek(p,0,2);}}
            fseek(p,0,0);
            if(contador==0){
            continuar=false;
            fclose(p);}}
            else{cout<<"NUMERO SUPERA LAS 4 CIFRAS!"<<endl;}
            }
    cout<<"DESCRIPCION:";
    CargarCadena(Descripcion,30);
    cout<<"STOCK:";
    cin>>Stock;
    continuar=true;
    while(continuar==true){
    cout<<"PRECIO UNITARIO:";
    cin>>Precio;
    if(Precio<=0){
        cout<<"PRECIO NO VALIDO!"<<endl;}
    else{continuar=false;}}
}
///MOSTRAR
void Producto::Mostrar(){
    cout<<"ID DE PRODUCTO:";
    cout<<ID<<endl;
    cout<<"STOCK:";
    cout<<Stock<<endl;
    cout<<"DESCRIPCION:";
    cout<<Descripcion<<endl;
    cout<<"PRECIO UNITARIO:";
    cout<<Precio<<endl;
}
void Producto::MostrarProductoRecuadro(int fila){
    setlocale(LC_ALL, "C");
    locate(6,fila);
    cout<<ID;
    locate(11,fila);
    cout<<Stock;
    locate(18,fila);
    cout<<Descripcion;
    locate(49,fila);
    cout<<Precio;
    setlocale(LC_ALL, "spanish");
}

#endif // CLASSPRODUCTO_H_INCLUDED
