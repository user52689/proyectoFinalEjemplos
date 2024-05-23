#ifndef ARCHIVOPROVEEDOR_H_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED

class ArchivoProveedor{
private:
    char nombre[30];
public:
    ArchivoProveedor (const char*n){strcpy(nombre,n);}
    Proveedor leerRegistro(int pos){
       Proveedor reg;
       FILE*p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Proveedor)*pos,0);
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
        return tam/sizeof(Proveedor);
    }
    bool agregarProveedor(){
        Proveedor reg;
        bool cargo,modifico;
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        cargo=reg.Cargar();
        if(cargo){
            modifico=fwrite(&reg,sizeof(Proveedor),1,p);
            fclose(p);
            return modifico;
        }
        else return cargo;
    }
    bool agregarProveedor(Proveedor reg){
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        bool modifico=fwrite(&reg,sizeof(Proveedor),1,p);
        fclose(p);
        return modifico;
    }
    bool modificarProveedor(Proveedor reg,int pos){
        FILE *p;
        p=fopen(nombre,"rb+");
        if(p==NULL) return false;
        fseek(p,sizeof(Proveedor)*pos,0);
        bool modifico=fwrite(&reg,sizeof(Proveedor),1,p);
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

#endif // ARCHIVOPROVEEDOR_H_INCLUDED
