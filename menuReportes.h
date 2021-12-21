#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
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
int ComprobarEstadoPedido(int n){
    Pedidos_Cabecera reg;
    FILE *p;
    p=fopen("Pedidos_Cabecera.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return 0;}
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getNumeroPedido()==n){
            if(reg.getEstado2()==true){
                    fclose(p);
                    return 1;}
            else{
                fclose(p);
                return 0;}}}
}
int ClienteExistente(int ID){
    Cliente reg;
    FILE *p;
    p=fopen("Cliente.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return 0;}
    while(fread(&reg,sizeof reg,1,p)==1){
        if(reg.getIDCliente()==ID&&reg.getEstado()==true){
                fclose(p);
                return 1;}}
    fclose(p);
    return 0;
}
///LISTAR TODOS LOS PEDIDOS PARA UN NUMERO DE CLIENTE
void PedidosCliente(){
    int ID,cantCabecera,i,cantDetalle,ii,contDetalle,num,valor,contador=0;
    cout<<"INGRESE ID DE CLIENTE: ";
    cin>>ID;
    valor=ClienteExistente(ID);
    if(valor==1){
    system("cls");
    cantCabecera=ContarCabecera();
    cantDetalle=ContarDetalle();
    Pedidos_Cabecera regCabecera;
    Pedidos_Detalle regDetalle;
    int fila=7;
    for(i=0;i<cantCabecera;i++){
    regCabecera=LeerCabecera(i);
    if(regCabecera.getIDCliente()==ID&&regCabecera.getEstado2()==true){
    contador++;
    DibujarTablaListadoCabecera(fila);
    AmpliarTablaCabecera(fila);
    regCabecera.MostrarCabeceraRecuadro(fila);
    fila+=5;
    contDetalle=0;
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
          if(contador==0){cout<<"EL CLIENTE AUN NO TIENE PEDIDOS HECHOS!"<<endl;
          cout<<"PRESIONE UNA TECLA PARA CONTINUAR";}
          hidecursor();
          anykey();
          showcursor();
          return;}
    cout<<"CLIENTE INEXISTENTE!"<<endl;
    system("pause");
}
///LISTAR PRODUCTO MAS VENDIDO
void ProductoMasVendido(){
    int idMAX=0,cantMAX=0,cant;
    Producto regProducto;
    Pedidos_Detalle regDetalle;
    FILE *pProducto,*pDetalle;
    pProducto=fopen("Producto.dat","rb");
    pDetalle=fopen("Pedidos_Detalle.dat","rb");
    if(pProducto==NULL||pDetalle==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
    while(fread(&regProducto,sizeof regProducto,1,pProducto)==1){
        fseek(pDetalle,0,0);
        cant=0;
        if(regProducto.getEstado()==true){
        while(fread(&regDetalle,sizeof regDetalle,1,pDetalle)==1){
        if(regProducto.getID()==regDetalle.getID()){
            if(ComprobarEstadoPedido(regDetalle.getNumeroPedido())==1){
            cant+=regDetalle.getCantidad();}}}
         if(idMAX==0){
            idMAX=regProducto.getID();
            cantMAX=cant;}
        else{if(cant>cantMAX){
            idMAX=regProducto.getID();
            cantMAX=cant;}}}}
    cout<<"PRODUCTO MAS VENDIDO CON UN TOTAL DE "<<cantMAX<<" UNIDADES VENDIDAS!";
    ListarIDProducto(idMAX);
    fclose(pProducto);
    fclose(pDetalle);
}
///GANANCIAS TOTALES SEGUN UNA FECHA INGRESADA
void GananciasFecha(){
    int total=0;
    Fecha f;
    Pedidos_Cabecera reg;
    FILE *p;
    p=fopen("Pedidos_Cabecera.dat","rb");
    if(p==NULL){
        cout<<"ERROR DE LECTURA DEL ARCHIVO!"<<endl;
        system("pause");
        return;}
    cout<<"INGRESE LA FECHA: ";
    f.Cargar();
    while(fread(&reg,sizeof reg,1,p)==1){
       if(reg.getFechaPedido()==f&&f.getAnio()==reg.getFechaPedido().getAnio()){
        if(reg.getEstado2()==true&&reg.getEstado()==false){
        total+=reg.getTotal();}}}
    cout<<"TOTAL RECAUDADO EN LA FECHA INGRESADA: $"<<total<<endl;
    system("pause");
    fclose(p);
}
///MENU
void menuReportes(){
setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 31;
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
      cout << "MENÚ REPORTES";
      locate(POSMENUX+1,POSMENUY+3);
      cout << "SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"LISTAR PEDIDOS POR CLIENTE ";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"PRODUCTO MAS VENDIDO ";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"GANANCIAS TOTALES POR FECHA ";
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
case 1:PedidosCliente();
    break;
case 2:ProductoMasVendido();
    break;
case 3:GananciasFecha();
    break;
case 0:
    return;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}
#endif // MENUREPORTES_H_INCLUDED
