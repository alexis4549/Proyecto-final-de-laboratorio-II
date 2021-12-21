#ifndef CLASSFECHA_H_INCLUDED
#define CLASSFECHA_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;
class Fecha{
    private:
        int dia, mes, anio;
    public:
        void Cargar();
        void Mostrar();
        void FechaActual();
        bool operator==(Fecha n);
        ///SETS, GETS
        void setDia(int d){dia=d;}
        void setMes(int m){mes=m;}
        void setAnio(int a){anio=a;}
        int getDia(){return dia;}
        int getMes(){return mes;}
        int getAnio(){return anio;}
};
///CARGAR
void Fecha::Cargar(){
    bool continuar=true;
    while(continuar==true){
    cout<<"DIA:";
    cin>>dia;
    if(dia<1||dia>31){
    cout<<"DIA NO VALIDO INTENTE NUEVAMENTE"<<endl;}
    else{continuar=false;}}
    continuar=true;
    while(continuar==true){
    cout<<"MES:";
    cin>>mes;
    if(mes<1||mes>12){
    cout<<"MES NO VALIDO INTENTE NUEVAMENTE"<<endl;}
    else{continuar=false;}}
    continuar=true;
    while(continuar==true){
    cout<<"ANIO:";
    cin>>anio;
    if(anio<1900){
    cout<<"ANIO NO VALIDO INTENTE NUEVAMENTE"<<endl;}
    else{continuar=false;}}
    }
///MOSTRAR
void Fecha::Mostrar(){
    cout<<dia<<"/"<<mes<<"/"<<anio<<endl;}

///CARGAR FECHA ACTUAL
void Fecha::FechaActual(){
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	dia=timePtr->tm_mday;
    mes=timePtr->tm_mon+1;
    anio=timePtr->tm_year+1900;
}

///CUMPLEAÑOS(SOBRECARGA DE OPERADOR)
bool Fecha:: operator==(Fecha n){
    if(dia!=n.dia){return false;}
    if(mes!=n.mes){return false;}
return true;
}


#endif // CLASSFECHA_H_INCLUDED
