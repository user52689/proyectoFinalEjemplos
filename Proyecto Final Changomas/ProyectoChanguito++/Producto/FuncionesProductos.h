#ifndef FUNCIONESPRODUCTOS_H_INCLUDED
#define FUNCIONESPRODUCTOS_H_INCLUDED

int verificarCodigoPos(int codigo);
int*vectorDeCodigosProductos();
bool setCantidadEnDisco(Producto);

int verificarCodigoPos(int codigo){//verifica la posicion de un producto por codigo
    Producto reg;
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
       reg = archivo.leerRegistro(i);
        if(reg.getCodigo() == codigo && reg.getEstado()){
            return i;
        }
    }
    return -1;
}
Producto obtenerProducto(int codigo){
    Producto reg;
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getCodigo()==codigo && reg.getEstado()){
            return reg;
        }
    }
    return reg;
}
bool verificarCodigoProducto(int codigo){//verifica si existe un producto con ese codigo
    Producto reg;
    ArchivoProducto archivo("dat\\Productos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg = archivo.leerRegistro(i);
        if(reg.getCodigo()==codigo && reg.getEstado()){
            return true;
        }
    }
    return false;
}
int*vectorDeCodigosProductos(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoProducto archivo("dat\\Productos.dat");
    Producto reg;
    int t=archivo.contarRegistros();
    int*vectorCodigos=new int[t]{0};
    int cont=0;
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getEstado()){
            vectorCodigos[cont++]=reg.getCodigo();
        }
    }
    return vectorCodigos;
}
bool setCantidadEnDisco(Producto producto){
    ArchivoProducto archivo("dat\\Productos.dat");
    return archivo.modificarProducto(producto,verificarCodigoPos(producto.getCodigo()));
}


#endif // FUNCIONESPRODUCTOS_H_INCLUDED
