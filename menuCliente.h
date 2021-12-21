#ifndef MENUCLIENTE_H_INCLUDED
#define MENUCLIENTE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
///RECUPERAR ID CLIENTE (AUTONUMERICO)
int IDAutonumericoCliente(){
int cantidad=0;
Cliente obj;
FILE *p;
p=fopen("Cliente.dat","rb");
while(fread(&obj,sizeof obj,1,p)==1){
cantidad++;}
fclose(p);
return cantidad;
}
///CARGAR
void CargarCliente(){
int ID;
ID=(IDAutonumericoCliente()+1);
Cliente obj;
obj.Cargar(ID);
FILE *p;
p=fopen("Cliente.dat","ab");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
fwrite(&obj,sizeof obj,1,p);
fclose(p);
cout<<"CLIENTE AGREGADO CON EXITO"<<endl;
system("pause");
}
///LISTAR TODOS
void ListarClientes(){
    int fila, cant,i=0;
    cant=IDAutonumericoCliente();
    fila=7;
    Cliente reg;
    FILE *p;
    p=fopen("Cliente.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
    DibujarTablaListadoClientes(fila);
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getEstado()==true){
            AmpliarTablaClientes(fila);
            reg.MostrarClienteRecuadro(fila);
            fila++;
            if(i!=cant-1){fila++;}
            i++;}}
    hidecursor();
    anykey();
    showcursor();
    fclose(p);
}
///LISTAR POR ID
void ListarIDCliente(){
int ID;
int fila=7;
cout<<"INGRESE LA ID DE CLIENTE:";
cin>>ID;
Cliente reg;
FILE *p;
p=fopen("Cliente.dat","rb");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
DibujarTablaListadoClientes(fila);
while(fread(&reg,sizeof reg,1,p)==1){
        if(ID==reg.getIDCliente()){
        if(reg.getEstado()==true){
            AmpliarTablaClientes(fila);
            reg.MostrarClienteRecuadro(fila);
        fclose(p);
        hidecursor();
        anykey();
        showcursor();
        return;}}}
system("cls");
cout<<"CLIENTE INEXISTENTE"<<endl;
system("pause");
}
///MODIFICAR DIRECCION
void ModificarDireccion(){
int ID;
char Direccion[50];
cout<<"INGRESE ID:";
cin>>ID;
Cliente obj;
FILE *p;
p=fopen("Cliente.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getIDCliente()){
        if(obj.getEstado()==true){
        cout<<"INGRESE LA NUEVA DIRECCION:";
        CargarCadena(Direccion,50);
        obj.setDireccion(Direccion);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"DIRECCION MODIFICADA CON EXITO"<<endl;
        system("pause");
        return;}}}
cout<<"CLIENTE INEXISTENTE!"<<endl;
system("pause");
}
///DAR DE BAJA
void BajaCliente(){
int ID;
cout<<"INGRESE ID:";
cin>>ID;
Cliente obj;
FILE *p;
p=fopen("Cliente.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getIDCliente()){
        if(obj.getEstado()==true){
        obj.setEstado(false);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"CLIENTE DADO DE BAJA"<<endl;
        system("pause");
        return;}}}
cout<<"CLIENTE INEXISTENTE!"<<endl;
system("pause");
}

///MENU
void menuCliente(){
setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 28;
const int ALTO_MENU = 10;
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
      locate(POSMENUX+6,POSMENUY+1);
      cout << "MENÚ CLIENTES";
      locate(POSMENUX+1,POSMENUY+3);
      cout << "SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"AGREGAR CLIENTE ";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"LISTAR CLIENTE POR ID ";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"LISTAR TODOS LOS CLIENTES";
      locate(POSMENUX+3,POSMENUY+7);
      cout <<"MODIFICAR DIRECCION";
      locate(POSMENUX+3,POSMENUY+8);
      cout <<"DAR DE BAJA";
      locate(POSMENUX+3,POSMENUY+9);
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
            if(opc < 5){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=5;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 9;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
switch(opc){
case 1:CargarCliente();
    break;
case 2:ListarIDCliente();
    break;
case 3:ListarClientes();
    break;
case 4:ModificarDireccion();
    break;
case 5:BajaCliente();
    break;
case 0:
    return;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}

#endif // MENUCLIENTE_H_INCLUDED
