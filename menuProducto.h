#ifndef MENUPRODUCTO_H_INCLUDED
#define MENUPRODUCTO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"

///CONTAR PRODUCTOS
int ContarProductos(){
int cantidad=0;
Producto obj;
FILE *p;
p=fopen("Producto.dat","rb");
while(fread(&obj,sizeof obj,1,p)==1){
cantidad++;}
fclose(p);
return cantidad;
}
///CARGAR
void CargarProducto(){
Producto obj;
obj.Cargar();
FILE *p;
p=fopen("Producto.dat","ab");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
fwrite(&obj,sizeof obj,1,p);
fclose(p);
cout<<"PRODUCTO AGREGADO CON EXITO"<<endl;
system("pause");
}
///LISTAR
void ListarProductos(){
    int fila, cant,i=0;
    cant=ContarProductos();
    fila=7;
    Producto reg;
    FILE *p;
    p=fopen("Producto.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
    DibujarTablaListadoProductos(fila);
    while(fread(&reg,sizeof reg,1,p)==1){
            if(reg.getEstado()==true){
            AmpliarTablaProductos(fila);
            reg.MostrarProductoRecuadro(fila);
            fila++;
            if(i!=cant-1){fila++;}
            i++;}}
    hidecursor();
    anykey();
    showcursor();
    fclose(p);
}
///DAR DE BAJA PRODUCTO
void BajaProducto(){
int ID;
cout<<"INGRESE ID:";
cin>>ID;
Producto obj;
FILE *p;
p=fopen("Producto.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getID()){
        DibujarTablaListadoProductos(fila);
        AmpliarTablaProductos(fila);
        reg.MostrarProductoRecuadro(fila);
        cout<<endl;
        cout<<"DESEA DAR DE BAJA ESTE PRODUCTO? 1: SI 2:NO";
        int opcion;
        cin>>opcion;
        if(opcion==1){
        obj.setEstado(false);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"PRODUCTO DADO DE BAJA"<<endl;
        system("pause");
        return;}}}
cout<<"PRODUCTO INEXISTENTE!"<<endl;
system("pause");
}

///LISTAR POR CODIGO
void ListarIDProducto(int ID){
int fila=7;
Producto reg;
FILE *p;
p=fopen("Producto.dat","rb");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
DibujarTablaListadoProductos(fila);
while(fread(&reg,sizeof reg,1,p)==1){
        if(ID==reg.getID()){
        if(reg.getEstado()==true){
        AmpliarTablaProductos(fila);
        reg.MostrarProductoRecuadro(fila);
        fclose(p);
        hidecursor();
        anykey();
        showcursor();
        return;}}}
system("cls");
cout<<"PRODUCTO INEXISTENTE"<<endl;
system("pause");
}
///MODIFICAR PRECIO
void ModificarPrecio(){
int ID;
float Precio;
cout<<"INGRESE LA ID:";
cin>>ID;
Producto obj;
FILE *p;
p=fopen("Producto.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getID()&&obj.getEstado()==true){
        cout<<"INGRESE EL NUEVO PRECIO:";
        cin>>Precio;
        obj.setPrecio(Precio);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"PRECIO MODIFICADO CON EXITO"<<endl;
        system("pause");
        return;}}
cout<<"ID INEXISTENTE!"<<endl;
system("pause");
}
///AGREGAR STOCK
void AgregarStock(){
int ID,Stock;
cout<<"INGRESE LA ID:";
cin>>ID;
Producto obj;
FILE *p;
p=fopen("Producto.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getID()&&obj.getEstado()==true){
        cout<<"INGRESE STOCK:";
        cin>>Stock;
        obj.setStock(obj.getStock()+Stock);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"STOCK AGREGADO CON EXITO"<<endl;
        system("pause");
        return;}}
cout<<"ID INEXISTENTE!"<<endl;
system("pause");
}
///MENU
void menuProducto(){
setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 34;
const int ALTO_MENU = 11;
int key, opc, cursorX, cursorY;
while(true){
      cursorX=POSMENUX+1;
      cursorY=POSMENUY + 4;
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      opc=1;
      setColor(LETRA);
      setBackgroundColor(FONDO);
      recuadro(POSMENUX,POSMENUY, ANCHO_MENU,ALTO_MENU,LETRA,FONDO);
      separadorH(POSMENUX,POSMENUY+2,ANCHO_MENU,LETRA,FONDO);
      locate(POSMENUX+10,POSMENUY+1);
      cout << "MENU COMIDAS";
      locate(POSMENUX+1,POSMENUY+3);
      cout << "SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"AGREGAR PRODUCTO";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"DAR DE BAJA UN PRODUCTO";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"LISTAR TODOS LOS PRODUCTOS";
      locate(POSMENUX+3,POSMENUY+7);
      cout <<"LISTAR PRODUCTO POR CODIGO";
      locate(POSMENUX+3,POSMENUY+8);
      cout <<"MODIFICAR PRECIO";
      locate(POSMENUX+3,POSMENUY+9);
      cout <<"AGREGAR STOCK";
      locate(POSMENUX+3,POSMENUY+10);
      cout <<"VOLVER AL MENU PRINCIPAL";
      hidecursor();
      //cin>>opc;
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 6){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=6;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 10;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
switch(opc){
case 1:CargarProducto();
    break;
case 2:BajaProducto();
    break;
case 3:ListarProductos();
    break;
case 4:
    int ID;
    cout<<"INGRESE ID DEL PRODUCTO:";
    cin>>ID;
    ListarIDProducto(ID);
    break;
case 5:ModificarPrecio();
    break;
case 6:AgregarStock();
    break;
case 0:
    return;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}

#endif // MENUPRODUCTO_H_INCLUDED
