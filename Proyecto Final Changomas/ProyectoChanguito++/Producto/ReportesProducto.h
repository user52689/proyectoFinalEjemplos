#ifndef REPORTESPRODUCTO_H_INCLUDED
#define REPORTESPRODUCTO_H_INCLUDED

void MenuReportesProducto();
bool buscarProductosPorValor();
bool productosMasMenosVendidos();
bool productosMasMenosStock();

void MenuReportesProducto(){
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
        x=29;
        y=20;
        textBoxAnimation(x,y,"REPORTES DE PRODUCTOS",2,0);
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
        textAnimation("1) PRODUCTOS POR VALOR",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) PRODUCTO MAS/MENOS VENDIDO",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) PRODUCTO MAS/MENOS STOCK",velocidad);
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
            case'1': buscarProductosPorValor(); break;
            case'2': productosMasMenosVendidos(); break;
            case'3': productosMasMenosStock(); break;
            default: menu=false; break;
        }
    }
}
bool buscarProductosPorValor(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int x,y;
    x=24;
    y=4;
    int t=archivo.contarRegistros();
    textBoxAnimation(x,y,"BUSCAR PRODUCTOS POR PRECIO");
        /**
        ╔═══════════════════════════╗
        ║BUSCAR PRODUCTOS POR PRECIO║
        ╚═══════════════════════════╝
        */
    if(!objetosRegitrados(t)){ return false; }
    float precio;
    char numero[10];
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Productos con precio mayor o igual a (ingrese un valor): ");
    rlutil::setColor(14);
    cin>>numero;
    precio=parseFloat(numero);
    rlutil::setColor(15);
    /**
        averiguar si es un precio valido
    */
    if(precio<1){
        gotoxy((x+17),(y+2));
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Producto producto;
    for(int i=0;i<t;i++){
        producto=archivo.leerRegistro(i);
        if(producto.getPrecio()>=precio){
            producto.Mostrar();
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool productosMasMenosVendidos(){
    rlutil::cls();
    ArchivoItemCarrito archivo("dat\\ItemCarritos.dat");
    int t=archivo.contarRegistros();
    int x,y;
    x=23;
    y=4;
    textBoxAnimation(x,y,"PRODUCTOS MAS Y MENOS VENDIDOS");
        /**
        ╔══════════════════════════════╗
        ║PRODUCTOS MAS Y MENOS VENDIDOS║
        ╚══════════════════════════════╝
        */
    x=9;
    y=8;
    gotoxy(x,y);
    if(!objetosRegitrados(t)){ return false; }
    int mas=0,menos;
    itemCarrito itemCarrito,itemCarritoMas,itemCarritoMenos;
    Producto producto;
    for(int i=0;i<t;i++){
        itemCarrito=archivo.leerRegistro(i);
        if(itemCarrito.getcantidad()>mas && itemCarrito.getEstado()){
            mas=itemCarrito.getcantidad();
            itemCarritoMas=itemCarrito;
        }
    }
    menos=mas;
    for(int i=0;i<t;i++){
        itemCarrito=archivo.leerRegistro(i);
        if(itemCarrito.getcantidad()<menos && itemCarrito.getEstado()){
            menos=itemCarrito.getcantidad();
            itemCarritoMenos=itemCarrito;
        }
    }
    rlutil::setColor(14);
    if(itemCarritoMas.getCodigoArticulo()==itemCarritoMenos.getCodigoArticulo()){
        textAnimation("Producto mas vendido: ");
        producto=obtenerProducto(itemCarritoMas.getCodigoArticulo());
        producto.Mostrar();
        rlutil::setColor(15);
        rlutil::hidecursor();
        rlutil::anykey();
        return true;
    }
    textAnimation("Producto mas vendido: ");
    cout<<mas;
    producto=obtenerProducto(itemCarritoMas.getCodigoArticulo());
    producto.Mostrar();
    if(t>1){// Si hay mas de un item:
        gotoxy(x,(y+3));
        rlutil::setColor(14);
        textAnimation("Producto menos vendido: ");
        cout<<menos;
        producto=obtenerProducto(itemCarritoMenos.getCodigoArticulo());
        producto.Mostrar();
    }
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool productosMasMenosStock(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    int x,y;
    x=22;
    y=4;
    textBoxAnimation(x,y,"PRODUCTOS CON MAS Y MENOS STOCK");
        /**
        ╔═══════════════════════════════╗
        ║PRODUCTOS CON MAS Y MENOS STOCK║
        ╚═══════════════════════════════╝
        */
    x=9;
    y=8;
    gotoxy(x,y);
    if(!objetosRegitrados(t)){ return false; }
    int mas=0,menos;
    Producto producto,productoMas,productoMenos;
    for(int i=0;i<t;i++){
        producto=archivo.leerRegistro(i);
        if(producto.getCantidad()>mas && producto.getEstado()){
            mas=producto.getCantidad();
            productoMas=producto;
        }
    }
    menos=mas;
    for(int i=0;i<t;i++){
        producto=archivo.leerRegistro(i);
        if(producto.getCantidad()<menos && producto.getEstado()){
            menos=producto.getCantidad();
            productoMenos=producto;
        }
    }
    rlutil::setColor(14);
    if(productoMas.getCodigo()==productoMenos.getCodigo()){
        textAnimation("Producto con mayor stock: ");
        productoMas.Mostrar();
        rlutil::setColor(15);
        rlutil::hidecursor();
        rlutil::anykey();
        return true;
    }
    textAnimation("Producto con mayor stock: ");
    cout<<mas;
    productoMas.Mostrar();
    if(t>1){// Si hay mas de un item:
        gotoxy(x,(y+3));
        rlutil::setColor(14);
        textAnimation("Producto con menor stock: ");
        cout<<menos;
        productoMenos.Mostrar();
    }
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}


#endif // REPORTESPRODUCTO_H_INCLUDED
