#ifndef SUBMENUUSUARIOS_H_INCLUDED
#define SUBMENUUSUARIOS_H_INCLUDED

bool agregarUsuario(int);
bool listarAdministradores();
bool listarEmpleados();
bool listarUsuarios();
bool eliminarDatosUsuario();

void menuUsuario(){
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
        textBoxAnimation(x,y,"MENU DE USUARIOS",2,0);
        /**
        ╔════════════════╗
        ║MENU DE USUARIOS║
        ╚════════════════╝
        */
    }
    {// Menu seleccion
        x=22;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,34,14,velocidad);
        rlutil::setColor(15);
        rlutil::hidecursor();
        rlutil::locate(++x,++y);
        textAnimation("1 - Agregar usuario",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar administradores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar empleados",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Listar todos los usuarios",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - ELiminar datos de un usuario",velocidad);
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
            case '1' :
                switch(agrergarUsuario()){
                    case 1: agregarUsuario(1); break;
                    case 2: agregarUsuario(2); break;
                    default: break;
                }
                break;
            case '2' : listarAdministradores(); break;
            case '3' : listarEmpleados(); break;
            case '4' : listarUsuarios(); break;
            case '5' : eliminarDatosUsuario(); break;
            default: menu=false; break;
        }
    }
}
bool agregarUsuario(int tipo){
    rlutil::cls();
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    {// Recuadros y titulo con flechas
        textBoxAnimation(29,4,"AGREGAR USUARIO");
        /**
        ╔═══════════════╗
        ║AGREGAR USUARIO║
        ╚═══════════════╝
        */
    }
    Usuario usuario;
    if(usuario.Cargar(tipo)){
        archivo.agregarUsuario(usuario);
    }
    usuario.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarAdministradores(){
    rlutil::cls();
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=22;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS ADMINISTRADORES",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Usuario usuario=archivo.leerRegistro(i);
        if(usuario.getEstado() && usuario.getTipo()==1){
            usuario.Mostrar();
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarEmpleados(){
    rlutil::cls();
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS EMPLEADOS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Usuario usuario=archivo.leerRegistro(i);
        if(usuario.getEstado() && usuario.getTipo()==2){
            usuario.Mostrar();
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarUsuarios(){
    rlutil::cls();
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS USUARIOS",2,velocidad);
    if(!objetosRegitrados(t)){ return false; }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Usuario usuario=archivo.leerRegistro(i);
        if(usuario.getEstado()){
            usuario.Mostrar();
            cout<<endl;
        }
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarDatosUsuario(){
    rlutil::cls();
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int t=archivo.contarRegistros();
    int velocidad=0;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"ELIMINAR DATOS DE USUARIO",2,velocidad);
        /**
        ╔═════════════════════════╗
        ║ELIMINAR DATOS DE USUARIO║
        ╚═════════════════════════╝
        */
    }
    if(!objetosRegitrados(t)){ return false; }
    Usuario usuario;
    gotoxy(9,8);
    for(int i=0;i<t;i++){
        usuario=archivo.leerRegistro(i);
        if(usuario.getEstado()){
            usuario.Mostrar();
        }
    }
    char nombre[20];
    rlutil::setColor(15);
    cout<<"\n\n Nombre de usuario a ";
    rlutil::setColor(4);
    cout<<"ELIMINAR";
    rlutil::setColor(15);
    cout<<": ";
    cargarCadena(nombre,20);
    int pos=indiceDatosUsuario(nombre,'u');
    if(pos==-1){
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("\n\t\tINCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    usuario=archivo.leerRegistro(pos);
    usuario.Mostrar();
    {// Pregunta si los datos son correctos
        char eleccion;
        rlutil::setColor(8);
        cout<<"\n\t"<<(int_fast8_t)30;
        cout<<"\n\t"<<(char)179;
        cout<<"\n\t"<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<" LOS DATOS SON CORRECTOS? S/N: ";
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){ return false; }
    }
    usuario.setEstado(false);
    archivo.modificarUsuario(usuario,pos);
    {// mensaje final
        rlutil::setColor(8);
        cout<<"\n\t"<<(int_fast8_t)30;
        cout<<"\n\t"<<(char)179;
        cout<<"\n\t"<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::hidecursor();
        rlutil::setColor(14);
        cout<<" DATOS ";
        rlutil::setColor(4);
        cout<<"ELIMINADOS";
        rlutil::setColor(14);
        cout<<" CORRECTAMENTE! "<<(int_fast8_t)2<<endl;
        rlutil::setColor(15);
        rlutil::hidecursor();
        rlutil::anykey();
    }
    return true;
}

#endif // SUBMENUUSUARIOS_H_INCLUDED
