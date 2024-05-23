#ifndef DATOSPERSONA_H_INCLUDED
#define DATOSPERSONA_H_INCLUDED

class DatosPersona{// super clase de Proveedor y Cliente
protected:
    char DNI[30];
    char nombre[30];
    char telefono[30];
    char direccion[30];
public:
    //set
    void setDNI(const char*d){ strcpy(DNI,d); }
    void setNombre(const char*n){ strcpy(nombre,n); }
    void setTelefono(const char*t){ strcpy(telefono,t); }
    void setDireccion(const char*d){ strcpy(direccion,d); }
    //get
    const char*getDNI(){ return DNI; }
    const char*getNombre(){ return nombre; }
    const char*getTelefono(){ return telefono; }
    const char*getDireccion(){ return direccion; }
};

#endif // DATOSPERSONA_H_INCLUDED
