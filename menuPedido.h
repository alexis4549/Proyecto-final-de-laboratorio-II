#ifndef MENUPEDIDO_H_INCLUDED
#define MENUPEDIDO_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
///OTRAS FUNCIONES///
///CONTAR REGISTROS DETALLE
int ContarDetalle(){
int cantidad=0;
Pedidos_Detalle obj;
FILE *p;
p=fopen("Pedidos_Detalle.dat","rb");
  if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  system("pause");}
while(fread(&obj,sizeof obj,1,p)==1){
cantidad++;}
fclose(p);
return cantidad;
}
int ContarDetalleID(int i){
int cantidad=0;
Pedidos_Detalle obj;
FILE *p;
p=fopen("Pedidos_Detalle.dat","rb");
  if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  system("pause");}
while(fread(&obj,sizeof obj,1,p)==1){
if(obj.getNumeroPedido()==i+1){
cantidad++;}}
fclose(p);
return cantidad;
}
///CONTAR REGISTROS CABECERA
int ContarCabecera(){
int cantidad=0;
Pedidos_Cabecera obj;
FILE *p;
p=fopen("Pedidos_Cabecera.dat","rb");
  if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  system("pause");}
while(fread(&obj,sizeof obj,1,p)==1){
cantidad++;}
fclose(p);
return cantidad;
}
///LEER REGISTRO CABECERA
Pedidos_Cabecera LeerCabecera(int pos){
  FILE *p;
  Pedidos_Cabecera reg;
  p=fopen("Pedidos_Cabecera.dat", "rb");
  if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  system("pause");}
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg, 1, p);
  fclose(p);
  return reg;
}
///LEER REGISTRO DETALLE
Pedidos_Detalle LeerDetalle(int pos){
  FILE *p;
  Pedidos_Detalle reg;
  p=fopen("Pedidos_Detalle.dat", "rb");
  if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
  system("pause");}
  fseek(p, sizeof reg*pos,0);
  fread(&reg, sizeof reg, 1, p);
  fclose(p);
  return reg;
}
///FUNCIONES MENU///
///NUEVO PEDIDO
void NuevoPedido(){
int ID,opcion,Total=0;
bool continuar=true;
Pedidos_Cabecera regCabecera;
Pedidos_Detalle regDetalle;
ID=(ContarCabecera()+1);
FILE *pCabecera,*pDetalle;
pCabecera=fopen("Pedidos_Cabecera.dat","ab");
pDetalle=fopen("Pedidos_Detalle.dat","ab");
if(pCabecera==NULL||pDetalle==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        fclose(pCabecera);
        fclose(pDetalle);
        system("pause");
        return;}
regCabecera.Cargar(ID);
while(continuar==true){
    regDetalle.Cargar(ID);
    Total+=regDetalle.getCantidad()*regDetalle.getPrecio();
    fwrite(&regDetalle,sizeof regDetalle,1,pDetalle);
    cout<<"DESEA AGREGAR MAS PRODUCTOS? 1-SI 2-NO"<<endl;
    cin>>opcion;
    if(opcion!=1){continuar=false;}}
if(regCabecera.getCumple()==true){
        cout<<"FELIZ CUMPLEAÑOS! DESCUENTO DEL 30%"<<endl;
        system("pause");
        Total=Total*0.7;}
regCabecera.setTotal(Total);
fwrite(&regCabecera,sizeof regCabecera,1,pCabecera);
fclose(pCabecera);
fclose(pDetalle);
cout<<"PEDIDO AGREGADO CON EXITO"<<endl;
system("pause");
}
///LISTAR TODOS v2.0
void ListarPedidos(){
    int cantCabecera,i,cantDetalle,ii,contDetalle,valor;
    cantCabecera=ContarCabecera();
    cantDetalle=ContarDetalle();
    Pedidos_Cabecera regCabecera;
    Pedidos_Detalle regDetalle;
    int fila=7;
    for(i=0;i<cantCabecera;i++){
    regCabecera=LeerCabecera(i);
    if(regCabecera.getEstado2()==true){
    DibujarTablaListadoCabecera(fila);
    AmpliarTablaCabecera(fila);
    regCabecera.MostrarCabeceraRecuadro(fila);
    fila+=5;
    contDetalle=0;
    valor=ContarDetalleID(i);
    for(ii=0;ii<cantDetalle;ii++){
        regDetalle=LeerDetalle(ii);
        if(regDetalle.getNumeroPedido()==i+1){
          if(contDetalle==0){DibujarTablaListadoDetalle(fila);}
          AmpliarTablaDetalle(fila);
          regDetalle.MostrarDetalleRecuadro(fila);
          contDetalle++;
          fila+=2;}}
          cout<<"\n"<<"\n";
          cout<<"========================================================================================================================"<<endl;
          fila+=5;}}
    hidecursor();
    anykey();
    showcursor();
}
///LISTAR POR NUMERO v2.0
void ListarNumero(){
    int cantCabecera,i,cantDetalle,ii,contDetalle,valor,num;
    cout<<"INGRESE EL NUMERO QUE DESEA: ";
    cin>>num;
    system("cls");
    cantCabecera=ContarCabecera();
    cantDetalle=ContarDetalle();
    Pedidos_Cabecera regCabecera;
    Pedidos_Detalle regDetalle;
    int fila=7;
    for(i=0;i<cantCabecera;i++){
    regCabecera=LeerCabecera(i);
    if(regCabecera.getNumeroPedido()==num&&regCabecera.getEstado2()==true){
    DibujarTablaListadoCabecera(fila);
    AmpliarTablaCabecera(fila);
    regCabecera.MostrarCabeceraRecuadro(fila);
    fila+=5;
    contDetalle=0;
    valor=ContarDetalleID(i);
    for(ii=0;ii<cantDetalle;ii++){
        regDetalle=LeerDetalle(ii);
        if(regDetalle.getNumeroPedido()==i+1){
          if(contDetalle==0){DibujarTablaListadoDetalle(fila);}
          AmpliarTablaDetalle(fila);
          regDetalle.MostrarDetalleRecuadro(fila);
          contDetalle++;
          fila+=2;}}
          hidecursor();
          anykey();
          showcursor();
          return;}}
    cout<<"NUMERO DE PEDIDO INEXISTENTE!"<<endl;
    system("pause");

}
///LISTAR PENDIENTES
void ListarPendientes(){
    int cantCabecera,i,cantDetalle,ii,contDetalle,valor;
    cantCabecera=ContarCabecera();
    cantDetalle=ContarDetalle();
    Pedidos_Cabecera regCabecera;
    Pedidos_Detalle regDetalle;
    int fila=7;
    for(i=0;i<cantCabecera;i++){
    regCabecera=LeerCabecera(i);
    if(regCabecera.getEstado()==true&&regCabecera.getEstado2()==true){
    DibujarTablaListadoCabecera(fila);
    AmpliarTablaCabecera(fila);
    regCabecera.MostrarCabeceraRecuadro(fila);
    fila+=5;
    contDetalle=0;
    valor=ContarDetalleID(i);
    for(ii=0;ii<cantDetalle;ii++){
        regDetalle=LeerDetalle(ii);
        if(regDetalle.getNumeroPedido()==i+1){
          if(contDetalle==0){DibujarTablaListadoDetalle(fila);}
          AmpliarTablaDetalle(fila);
          regDetalle.MostrarDetalleRecuadro(fila);
          contDetalle++;
          fila+=2;}}
          cout<<"\n"<<"\n";
          cout<<"========================================================================================================================"<<endl;
          fila+=5;}}
          hidecursor();
          anykey();
          showcursor();

}
///LISTAR POR FECHA
void ListarFecha(){
    int cantCabecera,i,cantDetalle,ii,contDetalle,valor,contador=0;
    Fecha FechaIngresada;
    cout<<"INGRESE LA FECHA: ";
    FechaIngresada.Cargar();
    system("cls");
    cantCabecera=ContarCabecera();
    cantDetalle=ContarDetalle();
    Pedidos_Cabecera regCabecera;
    Pedidos_Detalle regDetalle;
    int fila=7;
    for(i=0;i<cantCabecera;i++){
    regCabecera=LeerCabecera(i);
    if(regCabecera.getFechaPedido()==FechaIngresada&&regCabecera.getFechaPedido().getAnio()==FechaIngresada.getAnio()){
    if(regCabecera.getEstado2()==true){
    contador++;
    DibujarTablaListadoCabecera(fila);
    AmpliarTablaCabecera(fila);
    regCabecera.MostrarCabeceraRecuadro(fila);
    fila+=5;
    contDetalle=0;
    valor=ContarDetalleID(i);
    for(ii=0;ii<cantDetalle;ii++){
        regDetalle=LeerDetalle(ii);
        if(regDetalle.getNumeroPedido()==i+1){
          if(contDetalle==0){DibujarTablaListadoDetalle(fila);}
          AmpliarTablaDetalle(fila);
          regDetalle.MostrarDetalleRecuadro(fila);
          contDetalle++;
          fila+=2;}}
          cout<<"\n"<<"\n";
          cout<<"========================================================================================================================"<<endl;
          fila+=5;}}}
    if(contador==0){
    cout<<"NO HAY PEDIDOS QUE COINCIDAN CON LA FECHA!"<<endl;}
    hidecursor();
    anykey();
    showcursor();
}
///DAR DE BAJA(ES PARA ELIMINAR EL PEDIDO, LA OTRA OPCION ES PARA CAMBIAR DE PENDIENTE A ENTREGADO)
void BajaPedido(){
int ID;
cout<<"INGRESE ID:";
cin>>ID;
Pedidos_Cabecera obj;
FILE *p;
p=fopen("Pedidos_Cabecera.dat","rb+");
if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
        if(ID==obj.getNumeroPedido()){
        obj.setEstado2(false);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"PEDIDO DADO DE BAJA"<<endl;
        system("pause");
        return;}}
cout<<"PEDIDO INEXISTENTE!"<<endl;
system("pause");
}
///CAMBIAR ESTADO DE UN PEDIDO(A ENTREGADO)
void CambiarEstado(){
int Numero;
Pedidos_Cabecera obj;
FILE *p;
p=fopen("Pedidos_Cabecera.dat","rb+");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
cout<<"INGRESE NUMERO DE PEDIDO:";
cin>>Numero;
while(fread(&obj,sizeof obj,1,p)==1){
    if(obj.getNumeroPedido()==Numero&&obj.getEstado2()==true){
        obj.setEstado(false);
        fseek(p,-1*(sizeof obj),1);
        fwrite(&obj,sizeof obj,1,p);
        fclose(p);
        cout<<"ESTADO MODIFICADO CON EXITO"<<endl;
        system("pause");
        return;}}
cout<<"PEDIDO INEXISTENTE"<<endl;
system("pause");
}
///CALCULAR GANACIAS TOTALES
void GananciasTotales(){
Fecha FechaHoy;
FechaHoy.FechaActual();
int Total=0;
Pedidos_Cabecera obj;
FILE *p;
p=fopen("Pedidos_Cabecera.dat","rb");
if(p==NULL){cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
while(fread(&obj,sizeof obj,1,p)==1){
    if(obj.getFechaPedido()==FechaHoy&&obj.getEstado2()==true&&obj.getEstado()==false){
        Total=Total+obj.getTotal();}}
cout<<"TOTAL DE HOY:";
cout<<Total<<endl;
system("pause");
fclose(p);
}
///MENU
void menuPedido(){
setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 36;
const int ALTO_MENU = 13;
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
      cout <<"MENU PEDIDOS";
      locate(POSMENUX+1,POSMENUY+3);
      cout <<"SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"NUEVO PEDIDO";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"LISTAR TODOS LOS PEDIDOS";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"LISTAR PEDIDO POR NUMERO";
      locate(POSMENUX+3,POSMENUY+7);
      cout <<"LISTAR PEDIDOS PENDIENTES";
      locate(POSMENUX+3,POSMENUY+8);
      cout <<"LISTAR PEDIDOS POR FECHA";
      locate(POSMENUX+3,POSMENUY+9);
      cout <<"ELIMINAR PEDIDO";
      locate(POSMENUX+3,POSMENUY+10);
      cout <<"CAMBIAR ESTADO DE UN PEDIDO";
      locate(POSMENUX+3,POSMENUY+11);
      cout <<"CALCULAR GANANCIAS TOTALES DE HOY";
      locate(POSMENUX+3,POSMENUY+12);
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
            if(opc < 8){
                opc++;
            }else{
                opc=0;
            }
            break;
        case KEY_UP:
            if(opc > 0){
                opc--;
            }else{
                opc=8;
            }
            break;
        }
        if(opc != 0){
            cursorY = opc + POSMENUY + 3;
        }else{
            cursorY = POSMENUY + 12;
        }
        locate(cursorX,cursorY);
        cout<<">";
        key = getkey();
      }
      setBackgroundColor(COLOR_PANTALLA);
      cls();
      showcursor();
switch(opc){
case 1:NuevoPedido();
    break;
case 2:ListarPedidos();
    break;
case 3:ListarNumero();
    break;
case 4:ListarPendientes();
    break;
case 5:ListarFecha();
    break;
case 6:BajaPedido();
    break;
case 7:CambiarEstado();
    break;
case 8:GananciasTotales();
    break;
case 0:
    return;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}


#endif // MENUPEDIDO_H_INCLUDED
