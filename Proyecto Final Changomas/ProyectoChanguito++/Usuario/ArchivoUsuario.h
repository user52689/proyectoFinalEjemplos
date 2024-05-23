#ifndef ARCHIVOUSUARIO_H_INCLUDED
#define ARCHIVOUSUARIO_H_INCLUDED

class ArchivoUsuario{
private:
    char nombre[30];
public:
    ArchivoUsuario (const char* n) {strcpy(nombre,n);}
    Usuario leerRegistro(int pos){
       Usuario reg;
       FILE*p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Usuario)*pos,0);
       fread(&reg,sizeof(reg),1,p);
       fclose(p);
       return reg;
   }
   int contarRegistros(){
        FILE*p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Usuario);
    }
    bool agregarUsuario(Usuario reg){
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        bool cargo=fwrite(&reg,sizeof(Usuario),1,p);
        fclose(p);
        return cargo;
    }
    bool modificarUsuario(Usuario reg,int pos){
        FILE*p;
        p=fopen(nombre,"rb+");
        if(p==NULL) return false;
        fseek(p,sizeof(Usuario)*pos,0);
        bool modifico=fwrite(&reg, sizeof(Usuario), 1, p);
        fclose(p);
        return modifico;
    }
    bool borrarDatos(){
        FILE*p=fopen(nombre,"wb");
        if(p==NULL){ return false; }
        fclose(p);
        return true;
    }
};

#endif // ARCHIVOUSUARIO_H_INCLUDED
