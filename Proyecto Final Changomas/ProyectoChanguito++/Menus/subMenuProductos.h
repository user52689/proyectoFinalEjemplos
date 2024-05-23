#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED

void menuProductos();
bool agregarProducto();
bool listarProductoPorCodigo();
bool listarTodosLosProductos();
bool modificarProductoPorCodigo(const char*);
bool eliminarProductoPorCodigo();

bool codigosProductos(int&x,int&y,int&y2,int&t);

void menuProductos(){
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
        /**
        ▄▄▄▄▄▄▄▄
        █┌────┐█
        █│    │█
        █└────┘█
        ▀▀▀▀▀▀▀▀
        */
        changoPP(15,7);
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE PRODUCTOS",2,0);
        /**
        ╔═════════════════╗
        ║MENU DE PRODUCTOS║
        ╚═════════════════╝
        */
    }
    {// Menu seleccion
        x=21;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,35,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar producto por codigo",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los productos",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - ELiminar un producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu principal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
        ┌──────────────────────────────────┐
        │1 - Agregar producto              │
        │                                  │
        │2 - Listar producto por codigo    │
        │                                  │
        │3 - Listar todos los productos    │
        │                                  │
        │4 - Modificar datos de un producto│
        │                                  │
        │5 - ELiminar un producto          │
        │                                  │
        │0 - volver al menu principal      │
        │                                  │
        │   Eleccion:                      │
        └──────────────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProducto(); break;
            case '2' : listarProductoPorCodigo(); break;
            case '3' : listarTodosLosProductos(); break;
            case '4' :
                switch(modificarPrecio()){
                    case -1: modificarProductoPorCodigo("Precio"); break;
                    case -2: modificarProductoPorCodigo("Cantidad"); break;
                    default: break;
                }
                break;
            case '5' : eliminarProductoPorCodigo(); break;
            default: menu=false; break;
        }
    }
}
bool agregarProducto(){
    rlutil::cls();
    int x,y;
    ArchivoProducto archivo("dat\\Productos.dat");
    {// Titulo y recuadros con flechas
        textBoxAnimation(28,4,"AGREGAR PRODUCTOS");
        /**
        ╔═════════════════╗
        ║AGREGAR PRODUCTOS║
        ╚═════════════════╝
        */
        textBoxAnimation(10,8,"Producto",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌────────┐
        │Producto│
        └────────┤
                 └───►
        */
    }
    archivo.agregarProducto();
    return true;
}
bool listarProductoPorCodigo(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=24;
    y=4;
    tituloPrincipal(x,y,"LISTAR PRODUCTO POR CODIGO",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!codigosProductos(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarCodigoPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Producto producto=archivo.leerRegistro(pos);
    producto.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLosProductos(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS PRODUCTOS",2,velocidad);
    x=16;
    y=8;
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Producto producto=archivo.leerRegistro(i);
        producto.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool modificarProductoPorCodigo(const char*campo){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=22;
    y=4;
    tituloPrincipal(x,y,"MODIFICAR PRODUCTO POR CODIGO",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!codigosProductos(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarCodigoPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Producto producto=archivo.leerRegistro(pos);
    producto.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    if(strcmp(campo,"Precio")==0){// Modifico el precio del producto
        gotoxy((x+4),(y+2));
        int precioNuevo;
        cout<<"Nuevo precio: ";
        cin>>precioNuevo;
        producto.setPrecio(precioNuevo);
        archivo.modificarProducto(producto,pos);
        producto=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        producto.Mostrar();
    }
    if(strcmp(campo,"Cantidad")==0){// Modifico el precio del producto
        gotoxy((x+4),(y+2));
        int cantidadNuevo;
        cout<<"Nuevo cantidad: ";
        cin>>cantidadNuevo;
        producto.setCantidad(cantidadNuevo);
        archivo.modificarProducto(producto,pos);
        producto=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        producto.Mostrar();
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarProductoPorCodigo(){
    rlutil::cls();
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=22;
    y=4;
    tituloPrincipal(x,y,"ELIMINAR PRODUCTOS POR CODIGO",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!codigosProductos(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarCodigoPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Producto producto=archivo.leerRegistro(pos);
    producto.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    producto.setEstado(false);
    archivo.modificarProducto(producto,pos);
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool codigosProductos(int&x,int&y,int&y2,int&t){
    int*vectorCodigos=new int[t]{0};
    if(vectorCodigos==NULL){ return false; }
    vectorCodigos=vectorDeCodigosProductos();
    rlutil::setColor(15);
    for(int i=0;i<t;i++){
        cout<<"| ";
        if(vectorCodigos[i]!=0){
            cout<<vectorCodigos[i]<<" |";
            if(i%9==0&&i!=0){
                gotoxy(21,++y);
                y2++;
            }
        }
    }
    delete vectorCodigos;
    /**
    ─► | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 |
       | 11 || 12 || 13 || 14 || 15 || 16 |
    */
    y+=y2;//Si incremente una fila, entonces la sumo al posicionador de filas
    {
        x=16;
        y=10;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)197;
        gotoxy(x,++y);
        cout<<(char)179;
        if(y2>0){
            for(int i=0;i<y2;i++){// para agrandar el bracito...
                gotoxy(x,++y);
                cout<<(char)179;
            }
        }
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<"Codigo";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
    }
    return true;
}

#endif // SUBMENUPRODUCTOS_H_INCLUDED
