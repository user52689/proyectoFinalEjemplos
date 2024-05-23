#ifndef FUNCIONESUSUARIO_H_INCLUDED
#define FUNCIONESUSUARIO_H_INCLUDED

int indiceDatosUsuario(const char*dato,char tipo){
    Usuario reg;
    ArchivoUsuario archivo("dat\\Usuarios.dat");
    int t=archivo.contarRegistros();
    switch(tipo){
    case 'u':
        for(int i=0;i<t;i++){
            reg=archivo.leerRegistro(i);
            if(strcmp(reg.getUsuario(),dato)==0 && reg.getEstado()){
                return i;
            }
        }
        break;
    case 'c':
        for(int i=0;i<t;i++){
            reg=archivo.leerRegistro(i);
            if(strcmp(reg.getContrasenia(),dato)==0 && reg.getEstado()){
                return i;
            }
        }
        break;
    default: break;
    }
    return -1;
}


#endif // FUNCIONESUSUARIO_H_INCLUDED
