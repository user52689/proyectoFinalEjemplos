#ifndef MENUEMPLEADO_H_INCLUDED
#define MENUEMPLEADO_H_INCLUDED

bool evaluarUsuario(int);
bool menuEmpleado();

bool menuEmpleado(){
    if(!evaluarUsuario(2)){ return false; }
    int x,y,velocidad=0;
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
        x=33;
        y=20;
        textBoxAnimation(x,y,"MENU EMPLEADO",2,0);
        /**
        ╔═════════════╗
        ║MENU EMPLEADO║
        ╚═════════════╝
        */
    }
    {// Menu seleccion
/**
De ser empleado podrá :
-Cargar productos;
-Registrar clientes(cargar,mostrar, buscar);
-Generar registros de ventas;
*/
        x=29;
        y=24;
        rlutil::setColor(8);
        boxAnimation(x,y,1,22,10,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y++;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar productos",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Menu de clientes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Menu de ventas",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - Salir",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
        ┌─────────────────────┐
        │1 - Agregar productos│
        │                     │
        │2 - Menu de clientes │
        │                     │
        │3 - Menu de ventas   │
        │                     │
        │0 - Salir            │
        │                     │
        │      Eleccion:      │
        └─────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProducto(); break;
            case '2' : menuClientes(); break;
            case '3' : menuVentas(); break;
            default: menu=false; break;
        }
    }
    return true;
}


#endif // MENUEMPLEADO_H_INCLUDED
