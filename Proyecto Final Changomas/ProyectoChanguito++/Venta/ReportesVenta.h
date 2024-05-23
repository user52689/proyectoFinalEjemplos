#ifndef REPORTESVENTA_H_INCLUDED
#define REPORTESVENTA_H_INCLUDED

void MenuReportesVenta();
bool buscarVentasPorValor();
bool clienteConMayorCompra();
bool clienteMenosUnoConMayorCompra();

void MenuReportesVenta(){
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
        x=31;
        y=20;
        textBoxAnimation(x,y,"REPORTES DE VENTAS",2,0);
    }
    {// Menu seleccion
        x=24;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,32,10,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1) VENTAS POR VALOR",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) CLIENTE CON MAS COMPRAS",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) MAYOR COMPRA CLIENTE = -1",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0) VOLVER AL MENU DE REPORTES",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case'1': buscarVentasPorValor(); break;
            case'2': clienteConMayorCompra(); break;
            case'3': clienteMenosUnoConMayorCompra(); break;
            default: menu=false; break;
        }
    }
}
bool buscarVentasPorValor(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int x,y;
    x=26;
    y=4;
    int t=archivo.contarRegistros();
    textBoxAnimation(x,y,"BUSCAR VENTAS POR VALOR");
        /**
        ╔═══════════════════════╗
        ║BUSCAR VENTAS POR VALOR║
        ╚═══════════════════════╝
        */
    if(!objetosRegitrados(t)){ return false; }
    float valor;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Ventas con valor mayor o igual a (ingrese un valor): ");
    rlutil::setColor(14);
    cin>>valor;
    rlutil::setColor(15);
    /**
        averiguar si es un valor valido
    */
    if(valor<1){
        gotoxy((x+17),(y+2));
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Venta venta;
    for(int i=0;i<t;i++){
        venta=archivo.leerRegistro(i);
        if(venta.getTotal()>=valor){
            venta.Mostrar();
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool clienteConMayorCompra(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int t=archivo.contarRegistros();
    int x,y;
    x=26;
    y=4;
    textBoxAnimation(x,y,"CLIENTE CON MAYOR COMPRA");
        /**
        ╔════════════════════════╗
        ║CLIENTE CON MAYOR COMPRA║
        ╚════════════════════════╝
        */
    if(!objetosRegitrados(t)){ return false; }
    x=9;
    y=8;
    gotoxy(x,y);
    if(t==0){
        gotoxy((x+17),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    int mas=0;
    Venta venta, ventaMas;
    for(int i=0;i<t;i++){
        venta=archivo.leerRegistro(i);
        if(strcmp(venta.getCliente(),"-1")!=0 && venta.getTotal()>mas && venta.getEstado()){
            mas=venta.getTotal();
            ventaMas=venta;
        }
    }
    if(strcmp(ventaMas.getCliente(),"-1")==0){
        gotoxy((x+12),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("NO HAY VENTAS REGISTRADAS CON CLIENTES");
        rlutil::setColor(15);
        return false;
    }

    rlutil::setColor(14);
    textAnimation("Cliente: ");
    Cliente cliente=obtenerCliente(ventaMas.getCliente());
    cliente.Mostrar();
    rlutil::setColor(14);
    gotoxy(x,(y+3));
    textAnimation("Venta: ");
    ventaMas.Mostrar();
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool clienteMenosUnoConMayorCompra(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int t=archivo.contarRegistros();
    int x,y;
    x=23;
    y=4;
    textBoxAnimation(x,y,"CLIENTE (-1) CON MAYOR COMPRA");
        /**
        ╔═════════════════════════════╗
        ║CLIENTE (-1) CON MAYOR COMPRA║
        ╚═════════════════════════════╝
        */
    if(!objetosRegitrados(t)){ return false; }
    x=9;
    y=8;
    gotoxy(x,y);
    if(t==0){
        gotoxy((x+17),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    int mas=0;
    Venta venta, ventaMas;
    for(int i=0;i<t;i++){
        venta=archivo.leerRegistro(i);
        if(venta.getTotal()>mas && venta.getEstado()){
            mas=venta.getTotal();
            ventaMas=venta;
        }
    }
    rlutil::setColor(14);
    textAnimation("Venta: ");
    ventaMas.Mostrar();
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}


#endif // REPORTESVENTA_H_INCLUDED
