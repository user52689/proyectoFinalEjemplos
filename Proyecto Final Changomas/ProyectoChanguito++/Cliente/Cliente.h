#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

int autonumericoClienteID();
bool verificarDNIcliente(const char*dni);

class Cliente:public DatosPersona{
private:
    int ID;
    char apellido[30];
    bool estado;
public:
    Cliente(){
        setEstado(false);
    }
    //métodos
    bool Cargar();
    void Mostrar(bool);
    //set
    void setApellido(const char*a){ strcpy(apellido,a); }
    void setEstado(bool e){ estado=e; }
    //get
    int getID(){ return ID; };
    const char* getApellido(){ return apellido; }
    bool getEstado(){ return estado; }
};
bool Cliente::Cargar(){
    int x,y;
    bool verifico;
    ID=autonumericoClienteID();// genera el ID autonumérico
    x=25;
    y=12;
    gotoxy(x,y);
    rlutil::setColor(15);
    cout<<"ID ";
    rlutil::setColor(8);
    cout<<"generado automaticamente";
    rlutil::setColor(15);
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" "<<ID;
    gotoxy(x,++y);
    cout<<"DNI";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>DNI;
    verifico=verificarDNIcliente(DNI);
    while(verifico){
        gotoxy(31,17);
        rlutil::setColor(4);
        cout<< "El DNI ya esta registrado";
        gotoxy(28,18);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,30);
        gotoxy(31,y);
        cin>>DNI;
    verifico=verificarDNIproveedor(DNI);
        if(strcmp(DNI,"0")==0){ return false; }
        cls(31,17,30);
        cls(28,18,34);
    }
    gotoxy(x,++y);
    cout<<"Nombre";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(nombre,29);

    gotoxy(x,++y);
    cout<<"Apellido";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(apellido,29);

    gotoxy(x,++y);
    cout<<"Telefono";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(telefono,29);

    gotoxy(x,++y);
    cout<<"Direccion";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(direccion,29);
    {// Pregunta si los datos son correctos
        char eleccion;
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
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
        cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
        rlutil::setColor(15);
        rlutil::anykey();
    }
    estado=true;
    return true;
}

void Cliente::Mostrar(bool soloActivos=true){
    if(soloActivos){
        if(estado){
            rlutil::setColor(8);
            cout<<"\n\tID: ";
            rlutil::setColor(15);
            cout<<ID;
            rlutil::setColor(8);
            cout<<"   DNI: ";
            rlutil::setColor(15);
            cout<<DNI;
            rlutil::setColor(8);
            cout<<" NOMBRE: ";
            rlutil::setColor(15);
            cout<<nombre;
            rlutil::setColor(8);
            cout<<" APELLIDO: ";
            rlutil::setColor(15);
            cout<<apellido;
            rlutil::setColor(8);
            cout<<"\n\t\tTELEFONO: ";
            rlutil::setColor(15);
            cout<<telefono;
            rlutil::setColor(8);
            cout<<" DIRECCION: ";
            rlutil::setColor(15);
            cout<<direccion;
        }
    }
    else{
        rlutil::setColor(8);
        cout<<"\n\tID: ";
        rlutil::setColor(15);
        cout<<ID;
        rlutil::setColor(8);
        cout<<"   DNI: ";
        rlutil::setColor(15);
        cout<<DNI;
        rlutil::setColor(8);
        cout<<" NOMBRE: ";
        rlutil::setColor(15);
        cout<<nombre;
        rlutil::setColor(8);
        cout<<" APELLIDO: ";
        rlutil::setColor(15);
        cout<<apellido;
        rlutil::setColor(8);
        cout<<"\n\t\tTELEFONO: ";
        rlutil::setColor(15);
        cout<<telefono;
        rlutil::setColor(8);
        cout<<" DIRECCION: ";
        rlutil::setColor(15);
        cout<<direccion;
    }
}

#endif // CLIENTE_H_INCLUDED
