#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

int indiceDatosUsuario(const char*,char);

class Usuario{
private:
    int tipo;// 1 - Adminstrador | 2 - Empleado
    char usuario[20];
    char contrasenia[10];
    bool estado;
public:
    Usuario(){
        tipo=-1;
        strcpy(usuario,"-");
        strcpy(contrasenia,"-");
        estado=false;
    }
    bool Cargar(int);
    void Mostrar(bool);
    void setTipo(int t){
        if(t==1 || t==2){ tipo=t; }
        else{ tipo=-1; }
    }
    void setUsuario(const char*u){ strcpy(usuario,u); }
    void setContrasenia(const char*c){ strcpy(contrasenia,c); }
    void setEstado(bool e){ estado=e; }
    int getTipo(){ return tipo; }
    const char*getUsuario(){ return usuario; }
    const char*getContrasenia(){ return contrasenia; }
    bool getEstado(){ return estado; }
};
bool Usuario::Cargar(int tipo){
    int x,y;
    char us[20];
    char con[10];
    x=9;
    y=8;
    gotoxy(x,y);
    rlutil::setColor(15);
    cout<<"Nombre de usuario";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(us,20);
    if(indiceDatosUsuario(us,'u')!=-1){
        gotoxy((x+17),++y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    gotoxy(x,++y);
    cout<<"Contrasenia";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(con,10);
    {// Pregunta si los datos son correctos
        char eleccion;
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(int_fast8_t)30;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<" LOS DATOS SON CORRECTOS? S/N: ";
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){ return false; }
    }
    {// mensaje final
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::hidecursor();
        rlutil::setColor(14);
        cout<<" DATOS INGRESADOS CORRECTAMENTE! "<<(int_fast8_t)2<<endl;
        rlutil::setColor(15);
        rlutil::anykey();
    }
    setTipo(tipo);
    setUsuario(us);
    setContrasenia(con);
    setEstado(true);
    return true;
}
void Usuario::Mostrar(bool soloActivos=true){
    if(soloActivos){
        if(estado){
            rlutil::setColor(14);
            cout<<"\n\t"<<((tipo==1)?"Administrador":"Empleado");
            rlutil::setColor(8);
            cout<<"\n\tNombre de usuario: ";
            rlutil::setColor(15);
            cout<<usuario;
            rlutil::setColor(8);
            cout<<"   contrasenia: ";
            rlutil::setColor(15);
            cout<<contrasenia;
        }
    }
    else{
        rlutil::setColor(14);
        cout<<"\n\t"<<((tipo==1)?"Administrador":"Empleado");
        rlutil::setColor(8);
        cout<<"\n\tNombre de usuario: ";
        rlutil::setColor(15);
        cout<<usuario;
        rlutil::setColor(8);
        cout<<"   contrasenia: ";
        rlutil::setColor(15);
        cout<<contrasenia;
    }
}

#endif // USUARIO_H_INCLUDED
