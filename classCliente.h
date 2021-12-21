#ifndef CLASSCLIENTE_H_INCLUDED
#define CLASSCLIENTE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include"classFecha.h"
#include "funciones.h"
#include "rlutil.h"
using namespace std;
using namespace rlutil;
#include "utilidades.h"

class Cliente{
private:
    int Telefono,IDCliente;
    char Nombre[15],Apellido[15],Direccion[36];
    Fecha Nacimiento;
    bool Estado=true;
public:
    void Cargar(int ID);
    void Mostrar();
    void MostrarClienteRecuadro(int fila);
    void setIDCliente(int n){IDCliente=n;}
    void setNombre(char* n){strcpy(Nombre,n);}
    void setApellido(char* n){strcpy(Apellido,n);}
    void setDireccion(char* n){strcpy(Direccion,n);}
    void setTelefono(int n){Telefono=n;}
    void setNacimiento(Fecha n){Nacimiento=n;}
    void setEstado(bool n){Estado=n;}
    int getIDCliente(){return IDCliente;}
    char* getNombre(){return Nombre;}
    char* getApellido(){return Apellido;}
    char* getDireccion(){return Direccion;}
    int getTelefono(){return Telefono;}
    Fecha getNacimiento(){return Nacimiento;}
    bool getEstado(){return Estado;}
};
///CARGAR
void Cliente::Cargar(int ID){
    IDCliente=ID;
    cout<<"TELEFONO:";
    cin>>Telefono;
    cout<<"NOMBRE:";
    CargarCadena(Nombre,15);
    cout<<"APELLIDO:";
    CargarCadena(Apellido,15);
    cout<<"DIRECCION:";
    CargarCadena(Direccion,35);
    cout<<"NACIMIENTO: "<<endl;
    Nacimiento.Cargar();
}
///MOSTRAR
void Cliente::Mostrar(){
    cout<<"ID:";
    cout<<IDCliente<<endl;
    cout<<"TELEFONO:";
    cout<<Telefono<<endl;
    cout<<"NOMBRE:";
    cout<<Nombre<<endl;
    cout<<"APELLIDO:";
    cout<<Apellido<<endl;
    cout<<"DIRECCION:";
    cout<<Direccion<<endl;
    cout<<"NACIMIENTO:";
    Nacimiento.Mostrar();}
///MOSTRAR EN CUADRO
void Cliente::MostrarClienteRecuadro(int fila){
    setlocale(LC_ALL, "C");
    locate(6, fila);
    cout<<IDCliente;
    locate(11, fila);
    cout<<Telefono;
    locate(22, fila);
    cout<<Nombre;
    locate(38, fila);
    cout<<Apellido;
    locate(55,fila);
    cout<<Direccion;
    locate(91,fila);
    Nacimiento.Mostrar();
    setlocale(LC_ALL, "spanish");
}
#endif // CLASSCLIENTE_H_INCLUDED
