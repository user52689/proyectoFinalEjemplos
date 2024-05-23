#ifndef REPORTESCLIENTES_H_INCLUDED
#define REPORTESCLIENTES_H_INCLUDED

void MenuReportesClientes();
bool buscarClientePorNombre();
bool ordenarClientesPorNombre();
bool ordenarClientesPorApellido();

void MenuReportesClientes(){
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
        textBoxAnimation(x,y,"REPORTES DE CLIENTES",2,0);
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
        textAnimation("1) BUSCAR CLIENTE POR NOMBRE",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) ORDENAMIENTO POR NOMBRE",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) ORDENAMIENTO POR APELLIDO",velocidad);
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
            case'1': buscarClientePorNombre(); break;
            case'2': ordenarClientesPorNombre(); break;
            case'3': ordenarClientesPorApellido(); break;
            default: menu=false; break;
        }
    }
}
bool buscarClientePorNombre(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int x,y;
    x=25;
    y=4;
    textBoxAnimation(x,y,"BUSCAR CLIENTE POR NOMBRE");
        /**
        ╔═════════════════════════╗
        ║BUSCAR CLIENTE POR NOMBRE║
        ╚═════════════════════════╝
        */
    char nombre[30];
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Nombre a buscar: ");
    rlutil::setColor(14);
    cargarCadena(nombre,30);
    rlutil::setColor(15);
    /**
        averiguar si es un nombre valido
    */
    int pos=verificarNombreClientePos(nombre);
    if(!posicionObjeto(pos,26,y)){ return false; }
    Cliente cliente=archivo.leerRegistro(pos);
    cliente.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool ordenarClientesPorNombre(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int x,y;
    x=26;
    y=4;
    textBoxAnimation(x,y,"ORDENAMIENTO POR NOMBRE");
        /**
        ╔═══════════════════════╗
        ║ORDENAMIENTO POR NOMBRE║
        ╚═══════════════════════╝
        */
    int t=archivo.contarRegistros();
    if(!objetosRegitrados(t)){ return false; }
    int pos=0,i,j,posMin;
    Cliente reg,aux;
    Cliente*Creg=new Cliente[t];
    if(Creg==NULL){ return false; }
    for(i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
            Creg[pos++]=reg;
    }
    for(i=0;i<t-1;i++){
        posMin=i;
        for(j=i+1;j<t;j++){
            if(strcmp(Creg[j].getNombre(),Creg[posMin].getNombre())<0){
                posMin=j;
            }
        }
        aux=Creg[i];
        Creg[i]=Creg[posMin];
        Creg[posMin]=aux;
    }
    x=9;
    y=8;
    gotoxy(x,y);
    rlutil::setColor(14);
    textAnimation("REGISTROS ORDENADOS POR NOMBRE\n");
    rlutil::setColor(15);
    for(i=0;i<t;i++){
        Creg[i].Mostrar();
    }
    delete Creg;
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool ordenarClientesPorApellido(){
    rlutil::cls();
    ArchivoCliente archivo("dat\\Clientes.dat");
    int x,y;
    x=25;
    y=4;
    textBoxAnimation(x,y,"ORDENAMIENTO POR APELLIDO");
        /**
        ╔═════════════════════════╗
        ║ORDENAMIENTO POR APELLIDO║
        ╚═════════════════════════╝
        */
    int t=archivo.contarRegistros();
    if(!objetosRegitrados(t)){ return false; }
    int pos=0,i,j,posMin;
    Cliente reg,aux;
    Cliente*Creg=new Cliente[t];
    if(Creg==NULL){ return false; }
    for(i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
            Creg[pos++]=reg;
    }
    for(i=0;i<t-1;i++){
        posMin=i;
        for(j=i+1;j<t;j++){
            if(strcmp(Creg[j].getApellido(),Creg[posMin].getApellido())<0){
                posMin=j;
            }
        }
        aux=Creg[i];
        Creg[i]=Creg[posMin];
        Creg[posMin]=aux;
    }
    x=9;
    y=8;
    gotoxy(x,y);
    rlutil::setColor(14);
    textAnimation("REGISTROS ORDENADOS POR APELLIDO\n");
    rlutil::setColor(15);
    for(i=0;i<t;i++){
        Creg[i].Mostrar();
    }
    delete Creg;
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // REPORTESCLIENTES_H_INCLUDED
