#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED

void menuClientes();
bool agregarCliente();
bool listarClientePorID();
bool listarTodosClientes();
bool MOdificarClientePorID(const char*);
bool eliminarClientePorID();

bool ID_Clientes(int&x,int&y,int&y2,int t);

void menuClientes(){
    bool menu=true;
    char eleccion;
    int velocidad=0;
    int x,y;

    while(menu){
    {// recuadro y Titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        changoPP(15,7);
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE CLIENTES",2,0);
        /**
        ╔════════════════╗
        ║MENU DE CLIENTES║
        ╚════════════════╝
        */
    }
    {// Menu seleccion
        x=21;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,34,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar cliente por ID",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los clientes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - ELiminar datos de un cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarCliente(); break;
            case '2' : listarClientePorID(); break;
            case '3' : listarTodosClientes(); break;
            case '4' :
                switch(modificarDatos()){
                    case -1: MOdificarClientePorID("Telefono"); break;
                    case -2: MOdificarClientePorID("Direccion"); break;
                    default: break;
                }
                break;
            case '5' : eliminarClientePorID(); break;
            default: menu=false; break;
        }
    }
}
bool agregarCliente(){
    rlutil::cls();
    int x,y;
    ArchivoCliente archivo("dat\\Clientes.dat");
    {// Recuadros y titulo con flechas
        textBoxAnimation(29,4,"AGREGAR CLIENTE");
        /**
        ╔═══════════════╗
        ║AGREGAR CLIENTE║
        ╚═══════════════╝
        */
        textBoxAnimation(11,8,"CLIENTE",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌───────┐
        │CLIENTE│
        └───────┤
                └───►
        */
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,13,0);
        gotoxy(++x,++y);
    }
    archivo.agregarCliente();
    return true;
}
bool listarClientePorID(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=26;
    y=4;
    tituloPrincipal(x,y,"LISTAR CLIENTES POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Clientes(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdClientePos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Cliente cliente=archivo.leerRegistro(pos);
    cliente.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosClientes(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS CLIENTES",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Cliente cliente=archivo.leerRegistro(i);
        cliente.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool MOdificarClientePorID(const char*campo){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=25;
    y=4;
    tituloPrincipal(x,y,"MODIFICAR CLIENTE POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Clientes(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdClientePos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Cliente cliente=archivo.leerRegistro(pos);
    cliente.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    if(strcmp(campo,"Telefono")==0){// Modifico el telefono del cliente
        gotoxy((x+4),(y+2));
        char telefonoClienteNuevo[30];
        cout<<"Nuevo telefono: ";
        cargarCadena(telefonoClienteNuevo,29);
        cliente.setTelefono(telefonoClienteNuevo);
        archivo.modificarCliente(cliente,pos);
        cliente=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        cliente.Mostrar();
    }
    if(strcmp(campo,"Direccion")==0){// Modifico la direccion del cliente
        gotoxy((x+4),(y+2));
        char direccionClienteNuevo[30];
        cout<<"Nueva direccion: ";
        cargarCadena(direccionClienteNuevo,29);
        cliente.setDireccion(direccionClienteNuevo);
        archivo.modificarCliente(cliente,pos);
        cliente=archivo.leerRegistro(pos);
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        cliente.Mostrar();
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarClientePorID(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=25;
    y=4;
    tituloPrincipal(x,y,"ELIMINAR CLIENTE POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Clientes(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIdClientePos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Cliente cliente=archivo.leerRegistro(pos);
    cliente.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    cliente.setEstado(false);
    archivo.modificarCliente(cliente,pos);
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool ID_Clientes(int&x,int&y,int&y2,int t){
    int*vectorID=new int[t]{0};
    if(vectorID==NULL){ return false; }
    vectorID=vectorDeID_clientes();
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
    y+=y2;//Si incremente una fila, entonces la sumo al posicionador de filas
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
    cout<<"ID del cliente";
    gotoxy((x+8),++y);
    cout<<(int_fast8_t)26<<" ";
    return true;
}

#endif // SUBMENUCLIENTES_H_INCLUDED
