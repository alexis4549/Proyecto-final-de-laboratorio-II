#ifndef CLASSPEDIDOS_DETALLE_H_INCLUDED
#define CLASSPEDIDOS_DETALLE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
CheckStock(int ID){
    FILE *p;
    Producto reg;
    p=fopen("Producto.dat","rb");
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==ID){
            return reg.getStock();
            fclose(p);}}
        return -1;}
int BuscarPrecio(int ID){
    FILE *p;
    Producto reg;
    p=fopen("Producto.dat","rb");
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==ID){
                if(reg.getEstado()==true){
                return reg.getPrecio();
                fclose(p);}}}
        return -1;}
char* BuscarDescripcion(int ID){
    FILE *p;
    Producto reg;
    p=fopen("Producto.dat","rb");
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==ID){
                return reg.getDescripcion();
                fclose(p);}}}

bool BajaStock(int ID,int cantidad2){
    int cantidad1,pos=0;
    cantidad1=CheckStock(ID);
    if(cantidad1<cantidad2){
            return false;}
    else{
    FILE *p;
    Producto reg;
    p=fopen("Producto.dat","rb+");
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getID()==ID){
            reg.setStock(reg.getStock()-cantidad2);
            fseek(p,pos*sizeof reg,0);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);}
            pos++;}
        return true;}
}

///CLASE
class Pedidos_Detalle{
private:
    int NumeroPedido,ID,Cantidad;
    char Descripcion[30];
    float Precio;
public:
    void Cargar(int n);
    void Mostrar();
    void MostrarDetalleRecuadro(int fila);
    int getNumeroPedido(){return NumeroPedido;}
    float getPrecio(){return Precio;}
    int getCantidad(){return Cantidad;}
    int getID(){return ID;}
};
///CARGAR
void Pedidos_Detalle::Cargar(int n){
    bool continuar=true,baja;
    NumeroPedido=n;
    while(continuar==true){
    cout<<"ID DE PRODUCTO:";
    cin>>ID;
    Precio=BuscarPrecio(ID);
    if(Precio==-1){cout<<"ID INEXISTENTE"<<endl;}
    else{continuar=false;}}
    strcpy(Descripcion,BuscarDescripcion(ID));
    continuar=true;
    while(continuar==true){
    cout<<"CANTIDAD:";
    cin>>Cantidad;
    baja=BajaStock(ID,Cantidad);
    if(baja==false){cout<<"STOCK INSUFICIENTE!"<<endl;}
    else{continuar=false;}}
}
///MOSTRAR
void Pedidos_Detalle::Mostrar(){
cout<<"ID DE PRODUCTO:";
cout<<ID<<endl;
cout<<"DESCRIPCION:";
cout<<Descripcion<<endl;
cout<<"CANTIDAD:";
cout<<Cantidad<<endl;
cout<<"PRECIO:";
cout<<Precio<<endl;
cout<<"SUBTOTAL:";
cout<<Precio*Cantidad<<endl;
}
void Pedidos_Detalle::MostrarDetalleRecuadro(int fila){
    setlocale(LC_ALL, "C");
    locate(6,fila);
    cout<<NumeroPedido;
    locate(14,fila);
    cout<<ID;
    locate(22,fila);
    cout<<Descripcion;
    locate(53,fila);
    cout<<Cantidad;
    locate(62,fila);
    cout<<Precio;
    locate(71,fila);
    cout<<Precio*Cantidad;
    setlocale(LC_ALL, "spanish");
}

#endif // CLASSPEDIDOS_DETALLE_H_INCLUDED
