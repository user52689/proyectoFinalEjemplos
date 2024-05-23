#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void cargarCadena(char *pal, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}

int buscarAutorPorId(int id){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int cantReg = archi.contarRegistros();
    int pos = 0;

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(pos);
        if(id == reg.getId() && reg.getEstado() == true){
            return pos;
        }
        pos++;
    }

    return -1;



}

bool buscarGenero(int id){
    Genero reg;
    ArchivoGenero archi("Generos.dat");
    int cantReg = archi.contarRegistros();

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);
        if( reg.getEstado() == true && reg.getIDgenero() == id){
            return true;
        }
    }
    return false;

}

bool buscarIdLibro(int id){
    Libro reg;
    ArchivoLibro archi("Libros.dat");
    int cantReg = archi.contarRegistros();

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);

        if(reg.getId() == id && reg.getEstado() == true){
            return true;
        }
    }
    return false;
}

bool buscarNombreAutor(const char *a){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int cantReg = archi.contarRegistros();

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);
        if(strcmp(reg.getNombre(), a) == 0 && reg.getEstado() == true){
            return true;
        }
    }
    return false;
}

bool buscarLibroPrestado(int id){
    Libro reg;
    ArchivoLibro archi("Libros.dat");
    int cantReg = archi.contarRegistros();

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);
        if(reg.getEstado() == true && reg.getId() == id){
            return true;
        }
    }
    return false;

}
#endif // FUNCIONESGLOBALES_H_INCLUDED
