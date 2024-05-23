#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void MenuReportes();
bool listarTodosLosProveedoresEliminados();
bool listarTodosLosProductosEliminados();
bool listarTodosLosClientesEliminados();
bool listarTodosLasVentasEliminadas();

void MenuReportes(){
    bool menu=true;
    char eleccion;
    int velocidad=0;
    int x,y;

    while(menu){
    {// Recuadros y titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        changoPP(15,7);
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE REPORTES",2,0);
    }
    {// Menu seleccion
        x=24;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,32,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1) MOSTRAR ELEMENTOS ELIMINADOS",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) REPORTES DE PROVEEDORES",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) REPORTES DE PRODUCTOS",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4) REPORTES DE CLIENTES",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5) REPORTES DE VENTAS",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0) VOLVER AL MENU PRINCIPAL",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case'1':
                switch(objetosEleccion("ELEMENTOS ELIMINADOS")){
                    case 1 : listarTodosLosProveedoresEliminados(); break;
                    case 2 : listarTodosLosProductosEliminados(); break;
                    case 3 : listarTodosLosClientesEliminados(); break;
                    case 4 : listarTodosLasVentasEliminadas(); break;
                    default: break;
                }
            break;
            case'2': MenuReportesProveedores(); break;
            case'3': MenuReportesProducto(); break;
            case'4': MenuReportesClientes(); break;
            case'5': MenuReportesVenta(); break;
            default: menu=false; break;
        }
    }
}
bool listarTodosLosProveedoresEliminados(){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=19;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS PROVEEDORES ELIMINADOS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Proveedor proveedor=archivo.leerRegistro(i);
        if(!proveedor.getEstado()){
            proveedor.Mostrar(false);
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLosProductosEliminados(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=19;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS PRODUCTOS ELIMINADOS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Producto producto=archivo.leerRegistro(i);
        if(!producto.getEstado()){
            producto.Mostrar(false);
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLosClientesEliminados(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=20;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS CLIENTES ELIMINADOS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Cliente cliente=archivo.leerRegistro(i);
        if(!cliente.getEstado()){
            cliente.Mostrar(false);
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLasVentasEliminadas(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=20;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODAS LAS VENTAS ELIMINADAS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Venta venta=archivo.leerRegistro(i);
        if(!venta.getEstado()){
            venta.Mostrar(false);
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // MENUREPORTES_H_INCLUDED
