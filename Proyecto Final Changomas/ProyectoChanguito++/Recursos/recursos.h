#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include <cctype>

void changoPP(int,int);
int modificarDatos();
int modificarPrecio();
bool soloDigitos();
int parseInt(const char*);
void cargarCadena(char *pal, int tam);
int objetosEleccion(const char*);
bool posicionObjeto(int pos,int x,int y);
bool objetosRegitrados(int t,int x,int y);

void changoPP(int x,int y){
    /**
     _____ _
     /  __ \ |                             _     _
     | /  \/ |__   __ _ _ __   __ _  ___ _| |_ _| |_
     | |   | '_ \ / _` | '_ \ / _` |/ _ \_   _|_   _|
     | \__/\ | | | (_| | | | | (_| | (_) ||_|   |_|
     \_____/_| |_|\__,_|_| |_|\__, |\___/
                               __/ |
                              |___/
    */
rlutil::setColor(14);
gotoxy(x,y);
cout<<" _____ _";
gotoxy(x,++y);
cout<<"/  __ \\ |                             _     _";
gotoxy(x,++y);
cout<<"| /  \\/ |__   __ _ _ __   __ _  ___ _| |_ _| |_";
gotoxy(x,++y);
cout<<"| |   | '_ \\ / _` | '_ \\ / _` |/ _ \\_   _|_   _|";
gotoxy(x,++y);
cout<<"| \\__/\\ | | | (_| | | | | (_| | (_) ||_|   |_|";
gotoxy(x,++y);
cout<<"\\_____/_| |_|\\__,_|_| |_|\\__, |\\___/";
gotoxy(x,++y);
cout<<"                          __/ |";
gotoxy(x,++y);
cout<<"                         |___/";
rlutil::setColor(15);
}

int ingresoUsuario(){
    int x,y;
    char eleccion;
    x=56;
    y=34;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,16,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'T\' - Telefono");
    gotoxy(x,++y);
    textAnimation("\'D\' - Direccion");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌───────────────┐
    │ │'T' - Telefono │
    │ │'D' - Direccion│
    │ │Eleccion:      │
    │ └───────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 't': return -1;
        case 'd': return -2;
        default : break;
    }
    return 0;
}
int agrergarUsuario(){
    int x,y;
    char eleccion;
    x=56;
    y=28;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,20,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'A\' - Administrador");
    gotoxy(x,++y);
    textAnimation("\'E\' - Empleado");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌───────────────────┐
    │ │'A' - Administrador│
    │ │'E' - Empleado     │
    │ │Eleccion:          │
    │ └───────────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 'a': return 1;
        case 'e': return 2;
        default : break;
    }
    return 0;
}
int modificarDatos(){// cartel recuadrado para entrar a Telefono o Direccion
    int x,y;
    char eleccion;
    x=56;
    y=34;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,16,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'T\' - Telefono");
    gotoxy(x,++y);
    textAnimation("\'D\' - Direccion");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌───────────────┐
    │ │'T' - Telefono │
    │ │'D' - Direccion│
    │ │Eleccion:      │
    │ └───────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 't': return -1;
        case 'd': return -2;
        default : break;
    }
    return 0;
}
int modificarPrecio(){// cartel recuadrado para entrar a Telefono o Direccion
    int x,y;
    char eleccion;
    x=56;
    y=34;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,15,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'P\' - Precio");
    gotoxy(x,++y);
    textAnimation("\'C\' - Cantidad");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌──────────────┐
    │ │'P' - Precio  │
    │ │'C' - Cantidad│
    │ │Eleccion:     │
    │ └──────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 'p': return -1;
        case 'c': return -2;
        default : break;
    }
    return 0;
}
int objetosEleccion(const char*menu){// cartel recuadrado para copiar datos
    int x,y;
    char eleccion;
    x=54;
    if(strcmp(menu,"COPIA")==0){ y=28; }
    if(strcmp(menu,"RESTAURAR")==0){ y=30; }
    if(strcmp(menu,"ELEMENTOS ELIMINADOS")==0){
        x=56;
        y=28;
    }
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,17,6);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation(" 1 - Proveedores");
    gotoxy(x,++y);
    textAnimation(" 2 - Productos");
    gotoxy(x,++y);
    textAnimation(" 3 - Clientes");
    gotoxy(x,++y);
    textAnimation(" 4 - Ventas");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌────────────────┐
    │ │ 1 - Proveedores│
    │ │ 2 - Productos  │
    │ │ 3 - Clientes   │
    │ │ 4 - Ventas     │
    │ │Eleccion:       │
    │ └────────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        default : break;
    }
    return 0;
}
bool soloDigitos(const char*cadena){// Evalua si los caracteres ingresados son numeros
    for(int i=0;cadena[i]!='\0';i++){
        if(!isdigit(cadena[i])){
            return false;
        }
    }
    return true;
}
bool soloDigitosFloat(const char*cadena){// Evalua si los caracteres ingresados son numeros
    bool punto=false;
    bool coma=false;
    bool dobleCaracter=false;
    if(strlen(cadena)>5){
        dobleCaracter=true;
    }
    for(int i=0;cadena[i]!='\0';i++){
        if((!punto || !coma) && (cadena[i]=='.' || cadena[i]==',')){
            punto=true;
            coma=true;
            if(dobleCaracter){
                punto=false;
                coma=false;
                dobleCaracter=false;
            }
            continue;
        }
        if(!isdigit(cadena[i])){
            return false;
        }
    }
    return true;
}
int parseInt(const char*cadena){
    if(!soloDigitos(cadena)){ return -1; }
    int entero=atoi(cadena);
    return entero;
}
float parseFloat(const char*cadena){
    if(!soloDigitosFloat(cadena)){ return -1; }
    float flotante=stof(cadena);
    return flotante;
}
void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}
bool posicionObjeto(int pos,int x,int y){
//if(!posicionObjeto(pos)){ return false; }
    if(pos==-1){
        gotoxy(x,y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    return true;
}
bool objetosRegitrados(int t,int x=15,int y=8){
//if(!objetosRegitrados(t)){ return false; }
    if(t==0){
        gotoxy(x,y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    return true;
}

#endif // RECURSOS_H_INCLUDED
