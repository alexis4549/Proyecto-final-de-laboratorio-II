#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED
const int POSMENUX = 45;
const int POSMENUY = 10;
const int COLOR_PANTALLA =BLACK;
const int LETRA = WHITE;
const int FONDO = BLACK;
///OTRAS FUNCIONES
void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            locate(i, j);
            setColor(colorLinea);
            setBackgroundColor(colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                cout << (char) 201;
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                cout << (char) 187;
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                cout << (char) 200;
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                cout << (char) 188;
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                cout << (char) 205;
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                cout << (char) 186;
            }
            //Dentro del recuadro
            else{
                cout << " ";
            }
        }
    }
    setlocale(LC_ALL, "spanish");
}

void separadorH(short iniX, short iniY, short ancho, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)204;
    for(i=1; i<ancho; i++){
        cout<<(char)205;
    }
    cout<<(char)185;
    setlocale(LC_ALL, "spanish");
}

void separadorV(short iniX, short iniY, short alto, short colorLinea=WHITE, short colorFondo=BLACK){
    setlocale(LC_ALL, "C");
    int i;
    locate(iniX,iniY);
    cout<<(char)203;
    for(i=1; i<alto; i++){
        locate(iniX,iniY+i);
        cout<<(char)186;
    }
    locate(iniX,iniY+alto);
    cout<<(char)202;
    setlocale(LC_ALL, "spanish");
}

bool AjustarVentana(int Ancho, int Alto) {
	_COORD Coordenada;
	Coordenada.X = Ancho;
	Coordenada.Y = Alto;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Right = Ancho - 1;
	Rect.Bottom = Alto - 1;

	// Obtener el handle de la consola
	HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

	// Ajustar el buffer al nuevo tamaño
	SetConsoleScreenBufferSize(hConsola, Coordenada);

	// Cambiar tamaño de consola a lo especificado en el buffer
	SetConsoleWindowInfo(hConsola, TRUE, &Rect);
	return TRUE;
}
///FUNCIONES DE CLASE CLIENTE
void DibujarTablaListadoClientes(int fila){
    recuadro(5,fila-3,96,2,LETRA,FONDO);
    separadorV(10,fila-3,2,LETRA,FONDO);
    separadorV(21,fila-3,2,LETRA,FONDO);
    separadorV(37,fila-3,2,LETRA,FONDO);
    separadorV(54,fila-3,2,LETRA,FONDO);
    separadorV(90,fila-3,2,LETRA,FONDO);
    locate(6,fila-2);
    cout<<"ID";
    locate(11,fila-2);
    cout<<"TELEFONO";
    locate(22,fila-2);
    cout<<"NOMBRE";
    locate(38,fila-2);
    cout<<"APELLIDO";
    locate(55,fila-2);
    cout<<"DIRECCION";
    locate(91,fila-2);
    cout<<"F.NACI.";
}

void AmpliarTablaClientes(int fila){
    recuadro(5, fila-1,96, 2, LETRA, FONDO);
    separadorV(10,fila-1,2,LETRA,FONDO);
    separadorV(21,fila-1,2,LETRA,FONDO);
    separadorV(37,fila-1,2,LETRA,FONDO);
    separadorV(54,fila-1,2,LETRA,FONDO);
    separadorV(90,fila-1,2,LETRA,FONDO);
    separadorH(5,fila-1,96,LETRA,FONDO);
    setlocale(LC_ALL,"C");
    locate(10, fila-1);
    cout<<(char)206;
    locate(21, fila-1);
    cout<<(char)206;
    locate(37, fila-1);
    cout<<(char)206;
    locate(54, fila-1);
    cout<<(char)206;
    locate(90, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}
///FUNCIONES DE CLASE PRODUCTO
void DibujarTablaListadoProductos(int fila){
    recuadro(5,fila-3,55,2,LETRA,FONDO);
    separadorV(10,fila-3,2,LETRA,FONDO);
    separadorV(17,fila-3,2,LETRA,FONDO);
    separadorV(48,fila-3,2,LETRA,FONDO);
    locate(6,fila-2);
    cout<<"ID";
    locate(11,fila-2);
    cout<<"STOCK";
    locate(18,fila-2);
    cout<<"DESCRIPCION";
    locate(49,fila-2);
    cout<<"PRECIO";
}

void AmpliarTablaProductos(int fila){
    recuadro(5, fila-1,55, 2, LETRA, FONDO);
    separadorV(10,fila-1,2,LETRA,FONDO);
    separadorV(17,fila-1,2,LETRA,FONDO);
    separadorV(48,fila-1,2,LETRA,FONDO);
    separadorH(5,fila-1,55,LETRA,FONDO);
    setlocale(LC_ALL,"C");
    locate(10, fila-1);
    cout<<(char)206;
    locate(17, fila-1);
    cout<<(char)206;
    locate(48, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}
///FUNCIONES CLASE CABECERA
void DibujarTablaListadoCabecera(int fila){
    recuadro(5,fila-3,50,2,LETRA,FONDO);
    separadorV(13,fila-3,2,LETRA,FONDO);
    separadorV(20,fila-3,2,LETRA,FONDO);
    separadorV(26,fila-3,2,LETRA,FONDO);
    separadorV(37,fila-3,2,LETRA,FONDO);
    separadorV(44,fila-3,2,LETRA,FONDO);
    locate(6,fila-2);
    cout<<"NUM PED";
    locate(14,fila-2);
    cout<<"ID CLI";
    locate(21,fila-2);
    cout<<"HORA";
    locate(27,fila-2);
    cout<<"FECHA";
    locate(38,fila-2);
    cout<<"TOTAL";
    locate(45,fila-2);
    cout<<"ESTADO";
}

void AmpliarTablaCabecera(int fila){
    recuadro(5, fila-1,50, 2, LETRA, FONDO);
    separadorV(13,fila-1,2,LETRA,FONDO);
    separadorV(20,fila-1,2,LETRA,FONDO);
    separadorV(26,fila-1,2,LETRA,FONDO);
    separadorV(37,fila-1,2,LETRA,FONDO);
    separadorV(44,fila-1,2,LETRA,FONDO);
    separadorH(5,fila-1,50,LETRA,FONDO);
    setlocale(LC_ALL,"C");
    locate(13, fila-1);
    cout<<(char)206;
    locate(20, fila-1);
    cout<<(char)206;
    locate(26, fila-1);
    cout<<(char)206;
    locate(37, fila-1);
    cout<<(char)206;
    locate(44, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}
///FUNCIONES DE CLASE DETALLE
void DibujarTablaListadoDetalle(int fila){
    recuadro(5,fila-3,74,2,LETRA,FONDO);
    separadorV(13,fila-3,2,LETRA,FONDO);
    separadorV(21,fila-3,2,LETRA,FONDO);
    separadorV(52,fila-3,2,LETRA,FONDO);
    separadorV(61,fila-3,2,LETRA,FONDO);
    separadorV(70,fila-3,2,LETRA,FONDO);
    locate(6,fila-2);
    cout<<"NUM PED";
    locate(14,fila-2);
    cout<<"ID PROD";
    locate(22,fila-2);
    cout<<"DESCRIPCION";
    locate(53,fila-2);
    cout<<"CANTIDAD";
    locate(62,fila-2);
    cout<<"PRECIO";
    locate(71,fila-2);
    cout<<"SUBTOTAL";
}

void AmpliarTablaDetalle(int fila){
    recuadro(5, fila-1,74, 2, LETRA, FONDO);
    separadorV(13,fila-1,2,LETRA,FONDO);
    separadorV(21,fila-1,2,LETRA,FONDO);
    separadorV(52,fila-1,2,LETRA,FONDO);
    separadorV(61,fila-1,2,LETRA,FONDO);
    separadorV(70,fila-1,2,LETRA,FONDO);
    separadorH(5,fila-1,74,LETRA,FONDO);
    setlocale(LC_ALL,"C");
    locate(13, fila-1);
    cout<<(char)206;
    locate(21, fila-1);
    cout<<(char)206;
    locate(52, fila-1);
    cout<<(char)206;
    locate(61, fila-1);
    cout<<(char)206;
    locate(70, fila-1);
    cout<<(char)206;
    setlocale(LC_ALL,"spanish");
}
#endif // UTILIDADES_H_INCLUDED
