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
#include"menuReportes.h"
#include"menuConfiguraciones.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"

int main(){
//setlocale(LC_ALL, "spanish");
setConsoleTitle("");
//AjustarVentana(120,30);
const int ANCHO_MENU = 25;
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
      cout << "MENÚ PRINCIPAL";
      locate(POSMENUX+1,POSMENUY+3);
      cout << "SELECCIONE UNA OPCION: ";
      locate(POSMENUX+3,POSMENUY+4);
      cout<<"MENU CLIENTES ";
      locate(POSMENUX+3,POSMENUY+5);
      cout<<"MENU COMIDAS ";
      locate(POSMENUX+3,POSMENUY+6);
      cout<<"MENU PEDIDOS ";
      locate(POSMENUX+3,POSMENUY+7);
      cout<<"MENU REPORTES ";
      locate(POSMENUX+3,POSMENUY+8);
      cout<<"MENU CONFIGURACIONES ";
      locate(POSMENUX+3,POSMENUY+9);
      cout <<"FINALIZAR EL PROGRAMA ";
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
case 1:menuCliente();
    break;
case 2:menuProducto();
    break;
case 3:menuPedido();
    break;
case 4:menuReportes();
    break;
case 5:menuConfiguraciones();
    break;
case 0:
    return 0;
    break;
default:
    cout<<"OPCION INCORRECTA!"<<endl;
    system("pause");
    break;}}
}
