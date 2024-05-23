#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

int autonumericoVentaID();
float ImporteTotal(int);

class Venta{
private:
    int ID;
    char DNI_cliente[30];
    itemCarrito items;
    float total;
    bool estado;
public:
    Venta();
    Venta(const char*,int,int,float);
    int Cargar(const char*);
    void Mostrar(bool);
    //set
    void setDNI_cliente(const char*c){ strcpy(DNI_cliente,c); }
    void setTotal(float t){
        if(t>=0){ total=t; }
        else{ total=-1; }
    }
    void setEstado(bool e){ estado=e; }
    //get
    int getID(){ return ID; }
    const char*getCliente(){ return DNI_cliente; }
    float getTotal(){ return total; }
    bool getEstado(){ return estado; }
};
Venta::Venta(){
    setEstado(false);
}
int Venta::Cargar(const char*DNI){
    ID=autonumericoVentaID();
    int x,y;
    char continuar;
    strcpy(DNI_cliente,DNI);
    {// Bloque de carga de ventas
        x=24;
        y=15;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        boxAnimation(27,16,1,35,5,0);
    }
    int nuevaLinea=28;
    while(items.Cargar(total)){
        guardarItems(items);
        gotoxy(10,24);
        estado=true;
        {// Valor total
            gotoxy(30,37);
            rlutil::setColor(5);
            cout<<"Total : ";
            rlutil::setColor(9);
            cout<<"$ ";
            rlutil::setColor(15);
            cout<<total<<endl;
        }
        rlutil::setColor(8);
        x=9;
        y=28;
        gotoxy(x,y);
        cout<<"ID de venta: ";
        rlutil::setColor(14);
        cout<<ID;
        rlutil::setColor(15);
        gotoxy(x,++nuevaLinea);
        cout<<"\n\tItems del carrito";
        items.Mostrar();
        rlutil::setColor(14);
        gotoxy(20,40);
        cout<<"Presione \'+\' para agregar productos: ";
        rlutil::hidecursor();
        rlutil::setColor(15);
        cin>>continuar;
        cls(57,40,5);
        if(continuar!='+'){
            cls(10,40,60);
            gotoxy(29,40);
            rlutil::anykey("Venta finalizada!");
            break;
        }
        rlutil::showcursor();
    }
    return true;
}
void Venta::Mostrar(bool soloActivos=true){
    if(soloActivos){
        if(estado){
            rlutil::setColor(8);
            cout<<"\n\tID de venta: ";
            rlutil::setColor(14);
            cout<<ID;
            rlutil::setColor(8);
            cout<<"  DNI Cliente: ";
            rlutil::setColor(15);
            cout<<DNI_cliente;
            rlutil::setColor(8);
            cout<<" Total: ";
            rlutil::setColor(15);
            cout<<total;
        }
    }
    else{
        rlutil::setColor(8);
        cout<<"\n\tID de venta: ";
        rlutil::setColor(14);
        cout<<ID;
        rlutil::setColor(8);
        cout<<"  DNI Cliente: ";
        rlutil::setColor(15);
        cout<<DNI_cliente;
        rlutil::setColor(8);
        cout<<" Total: ";
        rlutil::setColor(15);
        cout<<total;
    }
}


#endif // VENTA_H_INCLUDED
