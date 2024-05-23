#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

int validarIDproveedor(int id);
bool verificarCodigoProducto(int codigo);

class Producto{
private:
    int codigo;
    int tipo;
    int ID_proveedor;///ESTÁ VERIFICADO EN EL CARGAR
    char nombre[30];
    float precio;
    int cantidad;
    bool estado;
public:
    Producto(int cd=0,int tip=0 ,int idp=0, const char* n="0",float pre=0,int cant=0){
        codigo=cd;
        tipo=tip;
        ID_proveedor=idp;
        strcpy(nombre,n);
        precio=pre;
        cantidad=cant;
    }
    //métodos
    bool Cargar();
    void Mostrar(bool);
    //set
    void setCodigo(int cd){codigo=cd;}
    void setTipo(int tip){tipo=tip;}
    void setID_proveedor(int idp){ ID_proveedor=idp; }
    void setNombre(const char*n){ strcpy(nombre,n); }
    void setPrecio(float pre){precio=pre;}
    void setCantidad(int cant){cantidad= cant;}
    void setCantidadMenosIgual(int cant){cantidad-=cant;}
    void setEstado(bool e){ estado=e; }

    //get
    int getCodigo(){return codigo;}
    int getTipo(){ return tipo; }
    int getID_porveedor(){ return ID_proveedor; }
    const char*getNombre(){return nombre;}
    float getPrecio(){return precio;}
    int getCantidad(){ return cantidad; }
    bool getEstado(){return estado;}
};

bool Producto::Cargar(){
    int x,y,validoID;
    bool codigoRepetido;
    x=25;
    y=12;
    rlutil::setColor(8);
    boxAnimation(--x,--y,1,38,17,0);
    gotoxy(++x,++y);
    rlutil::setColor(15);
    cout<<"Codigo";
    rlutil::setColor(8);
    cout<<" - Numerico (1~9999) -";
    rlutil::setColor(15);
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    char numero[10];
    cin>>numero;
    codigo=parseInt(numero);
    while(codigo<1 || codigo>9999){
        gotoxy(31,14);
        rlutil::setColor(4);
        cout<< "Codigo incorrecto";
        gotoxy(25,15);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        codigo=parseInt(numero);
        if(codigo==0){ return false; }
        cls(31,14,25);// Borra "Codigo incorrecto"
        cls(25,15,33);// Borra ingrese nuevamente (0 para salir)"
        gotoxy(25,14);
    }
    codigoRepetido=verificarCodigoProducto(codigo);// verifica que el codigo no esté ingresado
    while(codigoRepetido){
        gotoxy(31,14);
        rlutil::setColor(4);
        cout<< "Codigo ya registrado";
        gotoxy(25,15);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        codigo=parseInt(numero);
        if(codigo==0){ return false; }
        cls(31,14,25);// Borra "Codigo ya registrado"
        cls(25,15,33);// Borra ingrese nuevamente (0 para salir)"
        codigoRepetido=verificarCodigoProducto(codigo);
    }
    x=25;
    y=14;
    gotoxy(x,y);
    rlutil::setColor(15);
    cout<<"Tipo de producto";
    rlutil::setColor(8);
    gotoxy(x,++y);
    cout<<"(-1 alimentos, 2 bebidas, 3 P. Hogar,";
    gotoxy(x,++y);
    cout<<"(-4 Higiene, 5 electronica, 6 otros-)";
    rlutil::setColor(15);
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>numero;
    tipo=parseInt(numero);
    while(tipo<1 || tipo>6){
        gotoxy(31,18);
        rlutil::setColor(4);
        cout<< "Tipo incorrecto";
        gotoxy(25,19);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        tipo=parseInt(numero);
        if(tipo==0){ return false; }
        cls(31,18,25);// Borra "Tipo incorrecto"
        cls(25,19,33);// Borra ingrese nuevamente (0 para salir)"
    }
    x=25;
    y=18;
    gotoxy(x,y);
    cout<<"ID de proveedor"; //falta validar
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>numero;
    ID_proveedor=parseInt(numero);
    validoID=validarIDproveedor(ID_proveedor);
    while(validoID == -1){
        gotoxy(31,20);
        rlutil::setColor(4);
        cout<< "Proveedor inexistente";
        gotoxy(25,21);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        ID_proveedor=parseInt(numero);
        if(ID_proveedor==0){ return false; }
        cls(31,20,25);// Borra "Proveedor inexistente"
        cls(25,21,33);// Borra ingrese nuevamente (0 para salir)"
        validoID=validarIDproveedor(ID_proveedor);
    }
    x=25;
    y=20;
    gotoxy(x,y);
    cout<<"Nombre";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(nombre,29);

    gotoxy(x,++y);
    cout<<"Precio";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>numero;
    precio=parseFloat(numero);
    while(precio<1){
        gotoxy(31,24);
        rlutil::setColor(4);
        cout<< "Valor invalido";
        gotoxy(25,25);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        precio=parseFloat(numero);
        if(precio==0){ return false; }
        cls(31,24,25);// Borra "Valor invalido"
        cls(25,25,33);// Borra ingrese nuevamente (0 para salir)"
    }

    gotoxy(x,++y);
    cout<<"Cantidad";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>numero;
    cantidad=parseInt(numero);
    while(cantidad<1){
        gotoxy(31,26);
        rlutil::setColor(4);
        cout<< "Valor invalido";
        gotoxy(25,27);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,25);
        gotoxy(31,y);
        cin>>numero;
        cantidad=parseInt(numero);
        if(cantidad==0){ return false; }
        cls(31,26,25);// Borra "Valor invalido"
        cls(25,27,33);// Borra ingrese nuevamente (0 para salir)"
    }
    {
        y+=2;
        char eleccion;
        gotoxy((x+4),y);
        rlutil::setColor(4);
        cout<<"Los datos son correctos? S/N: ";
        rlutil::setColor(15);
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){ return false; }
    }
    {// mensaje final
        rlutil::setColor(8);
        gotoxy(--x,++y);
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

void Producto::Mostrar(bool soloActivos=true){
    if(soloActivos){
        if(estado){
            rlutil::setColor(8);
            cout<<"\n\tCodigo: ";
            rlutil::setColor(14);
            cout<<codigo;
            rlutil::setColor(8);
            cout<<"   Tipo: ";
            rlutil::setColor(15);
            cout<<tipo;
            rlutil::setColor(8);
            cout<<" ID de proveedor: ";
            rlutil::setColor(15);
            cout<<ID_proveedor;
            rlutil::setColor(8);
            cout<<"\n\t\t\tNombre: ";
            rlutil::setColor(15);
            cout<<nombre;
            rlutil::setColor(8);
            cout<<" Precio: ";
            rlutil::setColor(15);
            cout<<precio;
            rlutil::setColor(8);
            cout<<" Cantidad: ";
            rlutil::setColor(15);
            cout<<cantidad<<"              ";
        }
    }
    else{
        rlutil::setColor(8);
        cout<<"\n\tCodigo: ";
        rlutil::setColor(14);
        cout<<codigo;
        rlutil::setColor(8);
        cout<<"   Tipo: ";
        rlutil::setColor(15);
        cout<<tipo;
        rlutil::setColor(8);
        cout<<" ID de proveedor: ";
        rlutil::setColor(15);
        cout<<ID_proveedor;
        rlutil::setColor(8);
        cout<<"\n\t\t\tNombre: ";
        rlutil::setColor(15);
        cout<<nombre;
        rlutil::setColor(8);
        cout<<" Precio: ";
        rlutil::setColor(15);
        cout<<precio;
        rlutil::setColor(8);
        cout<<" Cantidad: ";
        rlutil::setColor(15);
        cout<<cantidad<<"    ";
    }
}


#endif // PRODUCTO_H_INCLUDED
