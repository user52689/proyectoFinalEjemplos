#ifndef FUNCIONESVENTAS_H_INCLUDED
#define FUNCIONESVENTAS_H_INCLUDED

int*vectorDeCodigosProductos();
int verificarIDPos(int);

int autonumericoVentaID(){ //funcion que genera id autonumerico
  ArchivoVenta archivo("dat\\Ventas.dat");
  int t=archivo.contarRegistros();
    if (t==0) return 1;
    Venta reg=archivo.leerRegistro(t-1);
    return reg.getID()+1;
}
int*vectorDeID_Ventas(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoVenta archivo("dat\\Ventas.dat");
    Venta reg;
    int t=archivo.contarRegistros();
    int*vectorID=new int[t]{0};
    if(vectorID==NULL){ exit(1); }
    int cont=0;
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getEstado()){
            vectorID[cont++]=reg.getID();
        }
    }
    return vectorID;
}
int verificarIDPos(int ID){//verifica la posicion de una venta por ID
    Venta reg;
    ArchivoVenta archivo("dat\\Ventas.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
       reg=archivo.leerRegistro(i);
        if(reg.getID()==ID && reg.getEstado()){
            return i;
        }
    }
    return -1;
}
float ImporteTotal(int cantidad){
  ArchivoVenta archivo("dat\\Ventas.dat");
  Venta reg;
  float total=0;
  int t=archivo.contarRegistros();
    if (t==0 || cantidad>t) return 0;
    for(int i=(t-cantidad);i<t;i++){
        reg=archivo.leerRegistro(i);
        total+=reg.getTotal();
    }
    return total;
}

#endif // FUNCIONESVENTAS_H_INCLUDED
