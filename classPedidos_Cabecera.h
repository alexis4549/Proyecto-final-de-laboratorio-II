#ifndef CLASSPEDIDOS_CABECERA_H_INCLUDED
#define CLASSPEDIDOS_CABECERA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <ctime>
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"
///CLASE HORARIO
class Horario{
private:
    int Horas,Minutos;
public:
    void HoraActual();
    bool operator==(Horario n);
    Horario CalcularDemora();
    void Mostrar();
    ///SETS/GETS
    void setHoras(int n){Horas=n;}
    void setMinutos(int n){Minutos=n;}
    int getHoras(){return Horas;}
    int getMinutos(){return Minutos;}
};
///HORA ACTUAL
void Horario::HoraActual(){
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
	Horas=timePtr->tm_hour;
	Minutos=timePtr->tm_min;
}
///COMPARAR HORARIOS(SOBRECARGA DE OPERADOR)
bool Horario:: operator==(Horario n){
if(Horas!=n.Horas){return false;}
if(Minutos!=n.Minutos){return false;}
return true;
}
void Horario::Mostrar(){
if(Horas>9&&Minutos>9){
cout<<Horas<<":"<<Minutos<<endl;}
if(Horas<=9&&Minutos<=9){
cout<<"0"<<Horas<<":"<<"0"<<Minutos<<endl;}
if(Horas>9&&Minutos<=9){
cout<<Horas<<":"<<"0"<<Minutos<<endl;}
if(Horas<=9&&Minutos>9){
cout<<"0"<<Horas<<":"<<Minutos<<endl;}
}
///CLASE PEDIDOS_CABECERA
class Pedidos_Cabecera{
private:
    int NumeroPedido,IDCliente;
    Horario HoraPedido;
    Fecha FechaPedido;
    float Total;
    bool Estado=true,Cumple=false,Estado2=true;///ESTADO ES PARA PENDIENTE O ENTREGADO, ESTADO2 ES PARA ELIMINAR UN PEDIDO
public:
    void Cargar(int n);
    void Mostrar();
    void MostrarCabeceraRecuadro(int fila);
    Horario getHoraPedido(){return HoraPedido;}
    int getIDCliente(){return IDCliente;}
    Fecha getFechaPedido(){return FechaPedido;}
    int getTotal(){return Total;}
    int getNumeroPedido(){return NumeroPedido;}
    bool getCumple(){return Cumple;}
    bool getEstado(){return Estado;}
    bool getEstado2(){return Estado2;}
    void setEstado(bool n){Estado=n;}
    void setEstado2(bool n){Estado2=n;}
    void setTotal(int n){Total=n;}
};
///CARGAR
void Pedidos_Cabecera::Cargar(int n){
    NumeroPedido=n;
    int contador;
    FILE *pCliente;
    Cliente regCliente;
    pCliente=fopen("Cliente.dat","rb");
    FechaPedido.FechaActual();
    bool continuar=true;
    while (continuar==true){
    contador=0;
    cout<<"ID DEL CLIENTE:";
    cin>>IDCliente;
    while(fread(&regCliente,sizeof regCliente,1,pCliente)==1){
        if(regCliente.getIDCliente()==IDCliente){
                if(regCliente.getEstado()==true){
                if(FechaPedido==regCliente.getNacimiento()){Cumple=true;}
                contador++;
                fclose(pCliente);
                continuar=false;}}}
        if(contador==0){
        fseek(pCliente,0,0);
        cout<<"CLIENTE INEXISTENTE"<<endl;}}
        HoraPedido.HoraActual();
}
///MOSTRAR
void Pedidos_Cabecera::Mostrar(){
    cout<<"NUMERO DE PEDIDO:";
    cout<<NumeroPedido<<endl;
    cout<<"ID DEL CLIENTE:";
    cout<<IDCliente<<endl;
    cout<<"HORARIO ";
    HoraPedido.Mostrar();
    cout<<"FECHA:";
    FechaPedido.Mostrar();
    cout<<"TOTAL A PAGAR:";
    cout<<Total<<endl;
    cout<<"ESTADO:";
    if(Estado==true){cout<<"PEDIDO PENDIENTE";}
    else{cout<<"PEDIDO ENTREGADO";}
    cout<<endl;
}
void Pedidos_Cabecera::MostrarCabeceraRecuadro(int fila){
    setlocale(LC_ALL, "C");
    locate(6,fila);
    cout<<NumeroPedido;
    locate(14,fila);
    cout<<IDCliente;
    locate(21,fila);
    HoraPedido.Mostrar();
    locate(27,fila);
    FechaPedido.Mostrar();
    locate(38,fila);
    cout<<Total;
    locate(45,fila);
    if(Estado==true){cout<<"PENDIENTE";}
    else{cout<<"ENTREGADO";}
    setlocale(LC_ALL, "spanish");
}

#endif // CLASSPEDIDOS_CABECERA_H_INCLUDED
