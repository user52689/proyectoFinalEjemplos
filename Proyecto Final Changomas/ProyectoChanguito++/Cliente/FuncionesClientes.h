#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

int autonumericoClienteID();
int verificarIdClientePos(int ID);
int verificarDniClientePos(const char*);
int*vectorDeID_clientes();

int autonumericoClienteID(){//funcion que genera id autonumerico
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    if(t==0) return 1;
    Cliente reg=archivo.leerRegistro(t-1);
    return reg.getID()+1;
}
int verificarIdClientePos(int id){// revisa la posicion del cliente segun ID
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
       reg=archivo.leerRegistro(i);
        if(reg.getID()==id && reg.getEstado()){
            return i;
        }
    }
    return -1;
}
int verificarDniClientePos(const char*dni){//verifica la posicion del cliente segun DNI
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
       reg=archivo.leerRegistro(i);
        if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()){
            return i;
        }
    }
    return -1;
}
int verificarNombreClientePos(const char*nombre){//verifica la posicion del cliente segun el nombre
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
       reg=archivo.leerRegistro(i);
        if(strcmp(reg.getNombre(),nombre)==0 && reg.getEstado()){
            return i;
        }
    }
    return -1;
}
bool verificarDNIcliente(const char*dni){//verifica si existe cliente con ese DNI
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
            return true;
        }
    }
    return false;
}
int*vectorDeID_clientes(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoCliente archivo("dat\\Clientes.dat");
    Cliente reg;
    int t=archivo.contarRegistros();
    int*vectorID=new int[t]{0};
    int cont=0;
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getEstado()){
            vectorID[cont++]=reg.getID();
        }
    }
    return vectorID;
}
Cliente obtenerCliente(const char*dni){
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
            return reg;
        }
    }
    return reg;
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
