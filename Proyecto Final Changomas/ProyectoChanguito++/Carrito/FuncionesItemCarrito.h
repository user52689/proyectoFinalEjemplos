#ifndef FUNCIONESITEMCARRITO_H_INCLUDED
#define FUNCIONESITEMCARRITO_H_INCLUDED

bool guardarItems(itemCarrito);
int verificarCodigoItemCarritoPos(int);
itemCarrito obtenerItemCarrito(int);

bool guardarItems(itemCarrito itemCarrito){
    ArchivoItemCarrito archivo("dat\\ItemCarritos.dat");
    int pos=verificarCodigoItemCarritoPos(itemCarrito.getCodigoArticulo());
    if(pos!=-1){// Si el producto ya registro venta:
        int aux=itemCarrito.getcantidad(), aux2;// guardo la cantidad actual
        itemCarrito=obtenerItemCarrito(itemCarrito.getCodigoArticulo());//traigo el item de .dat
        aux2=itemCarrito.getcantidad();
        itemCarrito.setCantidad((aux+aux2));// le acumulo la cantidad existente con la nueva
        archivo.modificarItemCarrito(itemCarrito,pos);// guardo en .dat
    }
    // sino entonces registro un nuevo item
    archivo.agregarItemCarrito(itemCarrito);
    return true;
}
int verificarCodigoItemCarritoPos(int codigo){
    itemCarrito reg;
    ArchivoItemCarrito archivo("dat\\ItemCarritos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getCodigoArticulo()==codigo && reg.getEstado()) {
            return i;
        }
    }
    return -1;
}
itemCarrito obtenerItemCarrito(int codigo){
    itemCarrito reg;
    ArchivoItemCarrito archivo("dat\\ItemCarritos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getCodigoArticulo()==codigo && reg.getEstado()) {
            return reg;
        }
    }
    return reg;
}

#endif // FUNCIONESITEMCARRITO_H_INCLUDED
