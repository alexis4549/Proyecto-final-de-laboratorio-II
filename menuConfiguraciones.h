#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include"classFecha.h"
#include"classCliente.h"
#include"classProducto.h"
#include"classPedidos_Cabecera.h"
#include"classPedidos_Detalle.h"
#include"menuCliente.h"
#include"menuProducto.h"
#include"menuPedido.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
///BACKUPS
int BackupCliente(){
FILE *p,*pBackup;
Cliente reg;
p=fopen("Cliente.dat","rb");
pBackup=fopen("Cliente.bkp","wb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
return 0;
}
int BackupProducto(){
FILE *p,*pBackup;
Producto reg;
p=fopen("Producto.dat","rb");
pBackup=fopen("Producto.bkp","wb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
return 0;
}
int BackupPedidos_Cabecera(){
FILE *p,*pBackup;
Pedidos_Cabecera reg;
p=fopen("Pedidos_Cabecera.dat","rb");
pBackup=fopen("Pedidos_Cabecera.bkp","wb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
return 0;
}
int BackupPedidos_Detalle(){
FILE *p,*pBackup;
Pedidos_Detalle reg;
p=fopen("Pedidos_Detalle.dat","rb");
pBackup=fopen("Pedidos_Detalle.bkp","wb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,p)==1){
    fwrite(&reg,sizeof reg,1,pBackup);}
fclose(p);
fclose(pBackup);
return 0;
}
///CARGAR BACKUPS
int RestaurarCliente(){
FILE *p,*pBackup;
Cliente reg;
p=fopen("Cliente.dat","wb");
pBackup=fopen("Cliente.bkp","rb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
return 0;
}
int RestaurarProducto(){
FILE *p,*pBackup;
Producto reg;
p=fopen("Producto.dat","wb");
pBackup=fopen("Producto.bkp","rb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
return 0;
}
int RestaurarPedidos_Cabecera(){
FILE *p,*pBackup;
Pedidos_Cabecera reg;
p=fopen("Pedidos_Cabecera.dat","wb");
pBackup=fopen("Pedidos_Cabecera.bkp","rb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
return 0;
}
int RestaurarPedidos_Detalle(){
FILE *p,*pBackup;
Pedidos_Detalle reg;
p=fopen("Pedidos_Detalle.dat","wb");
pBackup=fopen("Pedidos_Detalle.bkp","rb");
if(p==NULL||pBackup==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
while(fread(&reg,sizeof reg,1,pBackup)==1){
    fwrite(&reg,sizeof reg,1,p);}
fclose(p);
fclose(pBackup);
return 0;
}
///ELIMINAR
int EliminarCliente(){
FILE *p;
p=fopen("Cliente.dat","wb");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
fclose(p);
return 0;
}
int EliminarProducto(){
FILE *p;
p=fopen("Producto.dat","wb");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
fclose(p);
return 0;
}
int EliminarPedidos_Cabecera(){
FILE *p;
p=fopen("Pedidos_Cabecera.dat","wb");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
fclose(p);
return 0;
}
int EliminarPedidos_Detalle(){
FILE *p;
p=fopen("Pedidos_Detalle.dat","wb");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  return 1;}
fclose(p);
return 0;
}
///CREAR BACKUPS DE TODOS LOS DATOS
void BackupTodos(){
    int conteo=0;
    conteo+=BackupCliente();
    conteo+=BackupProducto();
    conteo+=BackupPedidos_Cabecera();
    conteo+=BackupPedidos_Detalle();
    if(conteo==0){
    cout<<"EXITO AL CREAR COPIA DE SEGURIDAD"<<endl;}
    system("pause");
}
///CARGAR BACKUPS DE TODOS LOS DATOS
void RestaurarTodos(){
    int conteo=0;
    conteo+=RestaurarCliente();
    conteo+=RestaurarProducto();
    conteo+=RestaurarPedidos_Cabecera();
    conteo+=RestaurarPedidos_Detalle();
    if(conteo==0){
    cout<<"EXITO AL RESTAURAR DATOS"<<endl;}
    system("pause");
}
///ELIMINAR DATOS
void EliminarDatos(){
    int conteo=0,opcion;
    cout<<"ESTA SEGURO QUE DESEA ELIMINAR TODOS LOS DATOS!?"<<endl;
    cout<<"OPCION 1: SI!"<<endl;
    cout<<"OPCION 2: NO!"<<endl;
    cin>>opcion;
    if(opcion==1){
    conteo+=EliminarCliente();
    conteo+=EliminarProducto();
    conteo+=EliminarPedidos_Cabecera();
    conteo+=EliminarPedidos_Detalle();
    if(conteo==0){
    cout<<"EXITO AL ELIMINAR DATOS"<<endl;}
    system("pause");}
    else{cout<<"PROCESO ABORTADO!"<<endl;
    system("pause");}
}
///MENU
void menuConfiguraciones(){
setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 29;
const int ALTO_MENU = 8;
int key, opc, cursorX, cursorY;
hidecursor();
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
      cout << "MENÚ CONFIGURACIONES";
      locate(POSMENUX+1,POSMENUY+3);
      cout << "SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"CREAR COPIAS DE SEGURIDAD ";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"RESTAURAR ARCHIVOS ";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"ELIMINAR TODOS LOS DATOS ";
      locate(POSMENUX+3,POSMENUY+7);
      cout<<"VOLVER AL MENU PRINCIPAL ";
      //cin>>opc;
      hidecursor();
      locate(cursorX,cursorY);
      cout<<">";
      key = getkey();
      while(key != KEY_ENTER){
        locate(cursorX,cursorY);
        cout<<" ";
        switch(key){
        case KEY_DOWN:
            if(opc < 3){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=3;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 7;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
switch(opc){
case 1:BackupTodos();
    break;
case 2:RestaurarTodos();
    break;
case 3:EliminarDatos();
    break;
case 0:
    return;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}
#endif // MENUCONFIGURACIONES_H_INCLUDED
