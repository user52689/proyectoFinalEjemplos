#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void MenuConfiguracion();
bool copiarJugadores();
bool copiarDeportes();
bool RestaurarJugadores();
bool RestaurarDeportes();
bool DatosInicio();
bool copiarProveedores();
bool copiarProductos();
bool copiarClientes();
bool copiarVentas();
bool restaurarProveedores();
bool restaurarProductos();
bool restaurarClientes();
bool restaurarVentas();
bool DatosInicio();

void MenuConfiguracion(){
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
        x=28;
        y=20;
        textBoxAnimation(x,y,"MENU DE CONFIGURACION",2,0);
    }
    {// Menu seleccion
        x=24;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,30,10,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1) COPIA DE SEGURIDAD",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) RESTAURAR ARCHIVO",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) ESTABLECER DATOS DE INICIO",velocidad);
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
                switch(objetosEleccion("COPIA")){
                    case 1 : copiarProveedores(); break;
                    case 2 : copiarProductos(); break;
                    case 3 : copiarClientes(); break;
                    case 4 : copiarVentas(); break;
                    default: break;
                }
            break;
            case'2':
                switch(objetosEleccion("RESTAURAR")){
                    case 1 : restaurarProveedores(); break;
                    case 2 : restaurarProductos(); break;
                    case 3 : restaurarClientes(); break;
                    case 4 : restaurarVentas(); break;
                    default: break;
                }
            break;
            case'3': DatosInicio(); break;
            default: menu=false; break;
        }
    }
}
bool copiarProveedores(){
    rlutil::cls();
    ArchivoProveedor archivo[2]{"dat\\Proveedores.dat","bak\\Proveedores.bak"};
    int x,y;
    x=28;
    y=4;
    int t=archivo[0].contarRegistros();
    textBoxAnimation(x,y,"COPIAR PROVEEDORES");
        /**
        ╔══════════════════╗
        ║COPIAR PROVEEDORES║
        ╚══════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea copiar tambien los elementos inactivos? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Proveedor proveedor=archivo[0].leerRegistro(i);
        proveedor.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea hacer una copia de seguridad? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[1].borrarDatos();
        for(int i=0;i<t;i++){
            Proveedor proveedor=archivo[0].leerRegistro(i);
            if(proveedor.getEstado()){
                archivo[1].agregarProveedor(proveedor);
            }
        }
    }
    else{
        cout<<"\n\t\t";
        system("copy dat\\Proveedores.dat bak\\Proveedores.bak");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\t\tCopia exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool copiarProductos(){
    rlutil::cls();
    ArchivoProducto archivo[2]{"dat\\Productos.dat","bak\\Productos.bak"};
    int x,y;
    x=29;
    y=4;
    int t=archivo[0].contarRegistros();
    textBoxAnimation(x,y,"COPIAR PRODUCTOS");
        /**
        ╔════════════════╗
        ║COPIAR PRODUCTOS║
        ╚════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea copiar tambien los elementos inactivos? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Producto producto=archivo[0].leerRegistro(i);
        producto.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea hacer una copia de seguridad? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[1].borrarDatos();
        for(int i=0;i<t;i++){
            Producto producto=archivo[0].leerRegistro(i);
            if(producto.getEstado()){
                archivo[1].agregarProducto(producto);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy dat\\Productos.dat bak\\Productos.bak");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\t\tCopia exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool copiarClientes(){
    rlutil::cls();
    ArchivoCliente archivo[2]{"dat\\Clientes.dat","bak\\Clientes.bak"};
    int x,y;
    x=30;
    y=4;
    int t=archivo[0].contarRegistros();
    textBoxAnimation(x,y,"COPIAR CLIENTES");
        /**
        ╔═══════════════╗
        ║COPIAR CLIENTES║
        ╚═══════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea copiar tambien los elementos inactivos? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Cliente cliente=archivo[0].leerRegistro(i);
        cliente.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea hacer una copia de seguridad? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[1].borrarDatos();
        for(int i=0;i<t;i++){
            Cliente cliente=archivo[0].leerRegistro(i);
            if(cliente.getEstado()){
                archivo[1].agregarCliente(cliente);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy dat\\Clientes.dat bak\\Clientes.bak");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\t\tCopia exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool copiarVentas(){
    rlutil::cls();
    ArchivoVenta archivo[2]{"dat\\Ventas.dat","bak\\Ventas.bak"};
    int x,y;
    x=31;
    y=4;
    int t=archivo[0].contarRegistros();
    textBoxAnimation(x,y,"COPIAR VENTAS");
        /**
        ╔═════════════╗
        ║COPIAR VENTAS║
        ╚═════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea copiar tambien los elementos inactivos? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Venta venta=archivo[0].leerRegistro(i);
        venta.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea hacer una copia de seguridad? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[1].borrarDatos();
        for(int i=0;i<t;i++){
            Venta venta=archivo[0].leerRegistro(i);
            if(venta.getEstado()){
                archivo[1].agregarVenta(venta);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy dat\\Ventas.dat bak\\Ventas.bak");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\t\tCopia exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool restaurarProveedores(){
    rlutil::cls();
    ArchivoProveedor archivo[2]{"dat\\Proveedores.dat","bak\\Proveedores.bak"};
    int x,y;
    x=27;
    y=4;
    int t=archivo[1].contarRegistros();
    textBoxAnimation(x,y,"RESTAURAR PROVEEDORES");
        /**
        ╔═════════════════════╗
        ║RESTAURAR PROVEEDORES║
        ╚═════════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea restaurar tambien los elementos inactivos, si los hay? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Proveedor proveedor=archivo[1].leerRegistro(i);
        proveedor.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea restaurar estos datos? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[0].borrarDatos();
        for(int i=0;i<t;i++){
            Proveedor proveedor=archivo[1].leerRegistro(i);
            if(proveedor.getEstado()){
                archivo[0].agregarProveedor(proveedor);
            }
        }
    }
    else{
        cout<<"\n\t\t";
        system("copy bak\\Proveedores.bak dat\\Proveedores.dat");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\tRestauracion exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool restaurarProductos(){
    rlutil::cls();
    ArchivoProducto archivo[2]{"dat\\Productos.dat","bak\\Productos.bak"};
    int x,y;
    x=28;
    y=4;
    int t=archivo[1].contarRegistros();
    textBoxAnimation(x,y,"RESTAURAR PRODUCTOS");
        /**
        ╔═══════════════════╗
        ║RESTAURAR PRODUCTOS║
        ╚═══════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea restaurar tambien los elementos inactivos, si los hay? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Producto producto=archivo[1].leerRegistro(i);
        producto.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea restaurar estos datos? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[0].borrarDatos();
        for(int i=0;i<t;i++){
            Producto producto=archivo[1].leerRegistro(i);
            if(producto.getEstado()){
                archivo[0].agregarProducto(producto);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy bak\\Producto.bak dat\\Producto.dat");
    }

    rlutil::setColor(14);
    cout<<"\n\n\t\t\tRestauracion exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool restaurarClientes(){
    rlutil::cls();
    ArchivoCliente archivo[2]{"dat\\Clientes.dat","bak\\Clientes.bak"};
    int x,y;
    x=31;
    y=4;
    int t=archivo[1].contarRegistros();
    textBoxAnimation(x,y,"RESTAURAR CLIENTES");
        /**
        ╔══════════════════╗
        ║RESTAURAR CLIENTES║
        ╚══════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea restaurar tambien los elementos inactivos, si los hay? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Cliente cliente=archivo[1].leerRegistro(i);
        cliente.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea restaurar estos datos? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[0].borrarDatos();
        for(int i=0;i<t;i++){
            Cliente cliente=archivo[1].leerRegistro(i);
            if(cliente.getEstado()){
                archivo[0].agregarCliente(cliente);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy bak\\Clientes.bak dat\\Clientes.dat");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\tRestauracion exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool restaurarVentas(){
    rlutil::cls();
    ArchivoVenta archivo[2]{"bak\\Ventas.dat","dat\\Ventas.bak"};
    int x,y;
    x=32;
    y=4;
    int t=archivo[1].contarRegistros();
    textBoxAnimation(x,y,"RESTAURAR VENTAS");
        /**
        ╔════════════════╗
        ║RESTAURAR VENTAS║
        ╚════════════════╝
        */
    char eleccion;
    bool soloActivos=true;
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea restaurar tambien los elementos inactivos, si los hay? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){ soloActivos=false; }
    for(int i=0;i<t;i++){
        Venta venta=archivo[1].leerRegistro(i);
        venta.Mostrar(soloActivos);
    }
    cout<<"\n\n\t\tDesea restaurar estos datos? (S/N) ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }
    if(soloActivos){
        archivo[0].borrarDatos();
        for(int i=0;i<t;i++){
            Venta venta=archivo[1].leerRegistro(i);
            if(venta.getEstado()){
                archivo[0].agregarVenta(venta);
            }
        }
    }
    else{
        cout<<"\n\t\t\t";
        system("copy bak\\Ventas.bak dat\\Ventas.dat");
    }
    rlutil::setColor(14);
    cout<<"\n\n\t\t\t\tCopia exitosa!";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool DatosInicio(){
    rlutil::cls();
    int x,y;
    x=27;
    y=4;
    textBoxAnimation(x,y,"ESTABLECER DATOS DE INICIO");
        /**
        ╔══════════════════════════╗
        ║ESTABLECER DATOS DE INICIO║
        ╚══════════════════════════╝
        */
    char eleccion;
    x=13;
    y=8;
    gotoxy(x,y);
    textAnimation("Desea establecer los datos por defecto? (S/N): ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='n'){ return false; }

    cout<<"\n\t\t";
    system("copy DatosInicio\\Proveedores.dat dat\\Proveedores.dat");
    cout<<"\t\t";
    system("copy DatosInicio\\Productos.dat dat\\Productos.dat");
    cout<<"\t\t";
    system("copy DatosInicio\\Clientes.dat dat\\Clientes.dat");
    cout<<"\t\t";
    system("copy DatosInicio\\Ventas.dat dat\\Ventas.dat");
    cout<<"\t\t";
    system("copy DatosInicio\\Usuarios.dat dat\\Usuarios.dat");
    rlutil::setColor(14);
    cout<<"\n\t\t\t\tCopia exitosa!\n";
    rlutil::setColor(15);
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // MENUCONFIGURACION_H_INCLUDED
