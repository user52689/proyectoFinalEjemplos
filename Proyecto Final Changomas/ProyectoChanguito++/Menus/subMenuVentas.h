#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

void menuVentas();
void carteInicio(int);
bool agregarVenta();
bool listarVentaPorID();
bool listarTodasLasVentas();
bool eliminarVentaPorID();

bool ID_Ventas(int&x,int&y,int&y2,int t);

void menuVentas(){
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
        textBoxAnimation(x,y,"MENU DE VENTAS",2,0);
    }
    {// Menu seleccion
        x=24;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,29,12,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Cargar venta",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar Venta POR ID",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todas las ventas",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Eliminar venta",velocidad);
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
            case '1' : agregarVenta(); break;
            case '2' : listarVentaPorID(); break;
            case '3' : listarTodasLasVentas(); break;
            case '4' : eliminarVentaPorID(); break;
            default: menu=false; break;
        }
    }
}
void carteInicio(int velocidad){// Recuadros y titulo
    rlutil::cls();
    textBoxAnimation(30,4,"AGREGAR VENTA",1,velocidad);
    textBoxAnimation(13,8,"VENTA",1,velocidad);
    int x=19;
    int y=10;
    gotoxy(x,y);
    rlutil::setColor(8);
    cout<<(char)180;
    gotoxy(x,++y);
    cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
    rlutil::setColor(15);
}
bool agregarVenta(){
    rlutil::cls();
    int x,y;
    int velocidad=1;
    carteInicio(velocidad);
    {// Recuadro de cargar venta
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,4,0);
        gotoxy(++x,++y);
    }
    char eleccion;
    char DNI[30];
    x=25;
    y=12;
    rlutil::setColor(15);
    cout<<"Es cliente? (S/N): ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){
        gotoxy(x,++y);
        cout<<"DNI ";
        rlutil::setColor(8);
        cout<<"(Numerico, sin \'.\')";
        gotoxy((x+4),++y);
        rlutil::setColor(15);
        cout<<(int_fast8_t)26<<" ";
        cin>>DNI;
        while(verificarDniClientePos(DNI)==-1 || !verificarDNIcliente(DNI)){
            gotoxy(35,18);
            rlutil::setColor(4);
            cout<<"DNI incorrecto";
            gotoxy(27,19);
            cout<<"ingrese nuevamente (0 para salir)";
            gotoxy(30,20);
            cout<<"ingrese -1 si no es cliente";
            rlutil::setColor(15);
            cls(31,y,25);
            gotoxy(31,y);
            cin>>DNI;
            if(strcmp(DNI,"0")==0){ return false; }
            if(strcmp(DNI,"-1")==0){
                gotoxy(35,14);
                strcpy(DNI,"-1");
                cls(31,18,25);// Borra "DNI incorrecto"
                cls(25,19,35);// Borra ingrese nuevamente (0 para salir)"
                cls(25,20,35);// Borra ingrese -1 si no es cliente"
                break;
            }
            verificarDniClientePos(DNI);
            cls(31,18,25);// Borra "DNI incorrecto"
            cls(25,19,35);// Borra ingrese nuevamente (0 para salir)"
            cls(25,20,35);// Borra ingrese -1 si no es cliente"
        }
    }
    else{
        gotoxy(35,14);
        strcpy(DNI,"-1");
        cout<<"Cliente = "<<DNI;
    }
    ArchivoVenta archivo("dat\\Ventas.dat");
    archivo.agregarVenta(DNI);
    return true;
}
bool listarVentaPorID(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=27;
    y=4;
    tituloPrincipal(x,y,"LISTAR VENTA POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Ventas(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIDPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Venta venta=archivo.leerRegistro(pos);
    venta.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodasLasVentas(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODAS LAS VENTAS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Venta venta=archivo.leerRegistro(i);
        venta.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarVentaPorID(){
    rlutil::cls();
    ArchivoVenta archivo("dat\\Ventas.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    x=26;
    y=4;
    tituloPrincipal(x,y,"ELIMINAR VENTAS POR ID",velocidad);
    gotoxy((x+5),y);
    if(!objetosRegitrados(t)){ return false; }
    if(!ID_Ventas(x,y,y2,t)){ return false; }
    char id[4];
    cin>>id;
    int pos=verificarIDPos(parseInt(id));
    if(!posicionObjeto(pos,(x+10),y)){ return false; }
    Venta venta=archivo.leerRegistro(pos);
    venta.Mostrar();
    if(!losDatosSonCorrectos(x,y)){ return false; }
    venta.setEstado(false);
    archivo.modificarVenta(venta,pos);
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool ID_Ventas(int&x,int&y,int&y2,int t){
    int*vectorID=new int[t]{0};
    vectorID=vectorDeID_Ventas();
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
    cout<<"ID de venta";
    gotoxy((x+8),++y);
    cout<<(int_fast8_t)26<<" ";
    return true;
}


#endif // SUBMENUVENTAS_H_INCLUDED
