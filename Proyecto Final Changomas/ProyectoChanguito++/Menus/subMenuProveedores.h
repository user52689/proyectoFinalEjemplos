#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED

void menuProveedores();
bool agregarProveedor();
bool listarProveedorPorID();
bool listarTodosLosProveedores();
bool MOdificarProveedorPorID(const char*);
bool eliminarProveedorPorID();

void tituloPrincipal(int&x,int&y,const char*titulo,int velocidad);
bool objetosRegitrados(int x,int y,int t);
bool posicionObjeto(int x,int y,int pos);
bool losDatosSonCorrectos(int&x,int&y);
bool ID_Proveedores(int&x,int&y,int&y2,int&t);

void menuProveedores(){
    ArchivoProveedor archivoProveedor("Proveedores.dat");
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
        x=28;
        y=20;
        textBoxAnimation(x,y,"MENU DE PROVEEDORES",2,0);
        /**
        ╔═══════════════════╗
        ║MENU DE PROVEEDORES║
        ╚═══════════════════╝
        */
    }
    {// Menu de seleccion
        x=20;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,36,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar proveedor por ID",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los proveedores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - Eliminar datos de un proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
         ┌───────────────────────────────────┐
         │1 - Agregar proveedor              │
         │                                   │
         │2 - Listar proveedor por ID        │
         │                                   │
         │3 - Listar todos los proveedores   │
         │                                   │
         │4 - Modificar datos de un proveedor│
         │                                   │
         │5 - Eliminar datos de un proveedor │
         │                                   │
         │0 - volver al menu proncipal       │
         │                                   │
         │    Eleccion:                      │
         └───────────────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProveedor(); break;
            case '2' : listarProveedorPorID(); break;
            case '3' : listarTodosLosProveedores(); break;
            case '4' :
                switch(modificarDatos()){
                    case -1: MOdificarProveedorPorID("Telefono"); break;
                    case -2: MOdificarProveedorPorID("Direccion"); break;
                    default: break;
                }
                break;
            case '5' : eliminarProveedorPorID(); break;
            default: menu=false; break;
        }
    }
}
bool agregarProveedor(){
    rlutil::cls();
    int x,y;
    ArchivoProveedor archivoProveedor("dat\\Proveedores.dat");
    {// Recuadros y titulo con flechas
        textBoxAnimation(28,4,"AGREGAR PROVEEDOR");
        /**
        ╔═════════════════╗
        ║AGREGAR PROVEEDOR║
        ╚═════════════════╝
        */
        textBoxAnimation(9,8,"PROVEEDOR",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌─────────┐
        │PROVEEDOR│
        └─────────┤
                  └───►
        */
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,11,0);
        gotoxy(++x,++y);
    }
    archivoProveedor.agregarProveedor();
    return true;
}
bool listarProveedorPorID(){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    Proveedor proveedor;
    x=26;
    y=4;
    gotoxy((x+5),y);
    tituloPrincipal(x,y,"LISTAR PROVEEDOR POR ID",velocidad);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Proveedores(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    proveedor=archivo.leerRegistro(pos);
    proveedor.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLosProveedores(){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS PROVEEDORES",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Proveedor proveedor=archivo.leerRegistro(i);
        proveedor.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool MOdificarProveedorPorID(const char*campo){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    Proveedor proveedor;
    x=24;
    y=4;
    tituloPrincipal(x,y,"MODIFICAR PROVEEDOR POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Proveedores(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    proveedor=archivo.leerRegistro(pos);
    proveedor.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    if(strcmp(campo,"Telefono")==0){// Modifico el telefono del proveedor
        gotoxy((x+4),(y+2));
        char telefonoProveedorNuevo[30];
        cout<<"Nuevo telefono: ";
        cargarCadena(telefonoProveedorNuevo,29);
        proveedor.setTelefono(telefonoProveedorNuevo);
        archivo.modificarProveedor(proveedor,pos);
        proveedor=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        proveedor.Mostrar();
    }
    if(strcmp(campo,"Direccion")==0){// Modifico la direccion del proveedor
        gotoxy((x+4),(y+2));
        char direccionProveedorNuevo[30];
        cout<<"Nueva Direccion: ";
        cargarCadena(direccionProveedorNuevo,29);
        proveedor.setDireccion(direccionProveedorNuevo);
        archivo.modificarProveedor(proveedor,pos);
        proveedor=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!          \n";
        rlutil::setColor(15);
        proveedor.Mostrar();
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarProveedorPorID(){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=24;
    y=4;
    tituloPrincipal(x,y,"ELIMINAR PROVEEDOR POR ID",velocidad);
    if(!objetosRegitrados(t)){ return false; }
    x=24;
    y=4;
    if(!ID_Proveedores(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Proveedor proveedor=archivo.leerRegistro(pos);
    proveedor.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    proveedor.setEstado(false);
    archivo.modificarProveedor(proveedor,pos);
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
void tituloPrincipal(int&x,int&y,const char*titulo,int velocidad){
    {// Titulo y recuadros con flechas
        textBoxAnimation(x,y,titulo,2,velocidad);
        /**
        ╔══════════════╗
        ║TITULO ENVIADO║
        ╚══════════════╝
        */
        textBoxAnimation(4,8,"Disponibles",1,velocidad);
        y=10;
        x=23;
        gotoxy(x,y);
        rlutil::setColor(8);
        x=16;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)193<<(char)196<<(char)196<<(int_fast8_t)16;// flecha de "codigos disponibles"
        /**┌───────────┐
           │Disponibles│
           └───────────┴──► | 1 | 2 | 3 | 4 | 5 | ...
        */
    }
}
bool ID_Proveedores(int&x,int&y,int&y2,int&t){
    {// Imprimo los ID de proveedor existentes
        int*vectorID=new int[t]{0};
        vectorID=vectorDeID_proveedores();
        if(vectorID==NULL){ return false; }
        rlutil::setColor(15);
        for(int i=0;i<t;i++){
            cout<<"| ";
            if(vectorID[i]!=0){
                cout<<vectorID[i]<<" |";
                if(i%9==0&&i!=0){
                    gotoxy(21,++y);
                    y2++;
                }
            }
        }
        delete vectorID;
        /**
        ─► | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 |
           | 11 || 12 || 13 || 14 || 15 || 16 |
        */
    }
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
        cout<<"ID del proveedor";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del proveedor
                    →
        */
    }
    return true;
}
bool losDatosSonCorrectos(int&x,int&y){// Pregunta si los datos son correctos
    char eleccion;
    y+=4;
    rlutil::setColor(8);
    gotoxy(--x,y);
    cout<<(char)218;
    for(int i=0;i<35;i++){ cout<<(char)196; }
    gotoxy(x,++y);
    cout<<(char)179;
    gotoxy(x,++y);
    cout<<(char)192<<(char)196<<(int_fast8_t)16;
    rlutil::setColor(15);
    cout<<" LOS DATOS SON CORRECTOS? S/N: ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion!='s'){ return false; }
    return true;
}


#endif // SUBMENUPROVEEDORES_H_INCLUDED
