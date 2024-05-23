#ifndef MENUADMIN_H_INCLUDED
#define MENUADMIN_H_INCLUDED

bool evaluarUsuario(int);
void menuUsuario();

bool menuAdmin(){
    //if(!evaluarUsuario(1)){ return false; }
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
        x=29;
        y=20;
        textBoxAnimation(x,y,"MENU ADMINISTRADOR",2,0);
        /**
        ╔══════════════════╗
        ║MENU ADMINISTRADOR║
        ╚══════════════════╝
        */
    }
    {// Menu seleccion
        x=26;
        y=24;
        rlutil::setColor(8);
        boxAnimation(x,y,1,28,18,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y++;
        rlutil::locate(x,y);
        textAnimation("1 - Menu de proveedores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Menu de productos",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Menu de clientes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Menu de ventas",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - Reportes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("6 - Menu de configuracion",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("7 - Menu de usuarios",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - Salir",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
        ┌─────────────────────────┐
        │1 - Menu de proveedores  │
        │                         │
        │2 - Menu de productos    │
        │                         │
        │3 - Menu de clientes     │
        │                         │
        │4 - Menu de ventas       │
        │                         │
        │5 - Reportes             │
        │                         │
        │6 - Menu de configuracion│
        │                         │
        │7 - Menu de usuarios     │
        │                         │
        │0 - Salir                │
        │                         │
        │      Eleccion:          │
        └─────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : menuProveedores(); break;
            case '2' : menuProductos(); break;
            case '3' : menuClientes(); break;
            case '4' : menuVentas(); break;
            case '5' : MenuReportes(); break;
            case '6' : MenuConfiguracion(); break;
            case '7' : menuUsuario(); break;
            default: menu=false; break;
        }
    }
    return true;
}


#endif // MENUADMIN_H_INCLUDED
