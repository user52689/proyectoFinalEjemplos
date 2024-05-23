#include<iostream>
#include<cstdlib>

using namespace std;

#include "Recursos/rlutil.h"
#include "Recursos/rlutilPlusPlus.h"
#include "Recursos/recursos.h"
#include "claseDatos.h"
#include "Menus/MenuConfiguracion.h"
#include "Menus/subMenuProveedores.h"
#include "Menus/subMenuProductos.h"
#include "Menus/subMenuClientes.h"
#include "Menus/subMenuVentas.h"
#include "Menus/MenuReportes.h"
#include "Menus/MenuEmpleado.h"
#include "Menus/MenuAdmin.h"
#include "Menus/subMenuUsuarios.h"

bool evaluarUsuario(int);

int main(){

rlutil::setConsoleTitle("Chango++");
system("mode con cols=80 lines=45");
    int x,y, velocidad=0;
    bool menu=true;
    char eleccion;

    while(menu){
    {// Recuadro y Titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        /**
        ▄▄▄▄▄▄▄▄
        █┌────┐█
        █│    │█
        █└────┘█
        ▀▀▀▀▀▀▀▀
        */
        changoPP(15,7);
        x=34;
        y=20;
        textBoxAnimation(x,y,"INGRESAR",2,0);
        /**
        ╔════════╗
        ║INGRESAR║
        ╚════════╝
        */
    }
    {// Menu seleccion
        x=27;
        y=25;
        rlutil::setColor(8);
        boxAnimation(x,y,1,22,8,velocidad);
        rlutil::setColor(15);
        x+=2;
        rlutil::hidecursor();
        y=26;
        rlutil::locate(x,y);
        textAnimation("1 - ADMINISTRADOR",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - EMPLEADO",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - Salir",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("Eleccion: ");
        /**
        ┌───────────────────┐
        │1 - ADMINISTRADOR  │
        │                   │
        │2 - EMPLEADO       │
        │                   │
        │0 - Salir          │
        │                   │
        │Eleccion:          │
        └───────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : menuAdmin(); break;
            case '2' : menuEmpleado(); break;
            default: menu=false; break;
        }
    }
return 0;
}
bool evaluarUsuario(int tipo){// Evaluo si el usuario/contrasenia es correcto
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int t=archivo.contarRegistros();
    Usuario usuario;
    char nombre[20];
    char contrasenia[10];
    gotoxy(28,35);
    cout<<"Usuario: ";
    cargarCadena(nombre,20);
    bool correcto=false;
    for(int i=0;i<t;i++){
        usuario=archivo.leerRegistro(i);
        if(usuario.getEstado() && usuario.getTipo()==tipo
           && strcmp(usuario.getUsuario(),nombre)==0){
            correcto=true;
            break;
        }
    }
    if(!correcto){
        rlutil::setColor(4);
        gotoxy(37,35);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO");
        return false;
    }
    correcto=false;
    gotoxy(28,36);
    cout<<"Contrasenia: ";
    cargarCadena(contrasenia,10);
    for(int i=0;i<t;i++){
        usuario=archivo.leerRegistro(i);
        if(usuario.getEstado() && usuario.getTipo()==tipo
           && strcmp(usuario.getContrasenia(),contrasenia)==0){
            correcto=true;
            break;
        }
    }
    if(!correcto){
        rlutil::setColor(4);
        gotoxy(41,36);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO");
        return false;
    }
    return correcto;
}
