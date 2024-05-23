#ifndef ARCHIVOITEMCARRITO_H_INCLUDED
#define ARCHIVOITEMCARRITO_H_INCLUDED

class ArchivoItemCarrito{
private:
    char nombre[30];
public:
    ArchivoItemCarrito (const char*n){ strcpy(nombre,n); }
    itemCarrito leerRegistro(int pos){
        itemCarrito reg;
        FILE*p;
        p=fopen(nombre,"rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(itemCarrito)*pos,0);
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
        return tam/sizeof(itemCarrito);
    }
    bool agregarItemCarrito(itemCarrito reg){
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        bool modifico=fwrite(&reg,sizeof(itemCarrito),1,p);
        fclose(p);
        return modifico;
    }
    bool modificarItemCarrito(itemCarrito reg,int pos){
        FILE*p;
        p=fopen(nombre,"rb+");
        if(p==NULL) return false;
        fseek(p,sizeof(itemCarrito)*pos,0);
        bool modifico=fwrite(&reg,sizeof(itemCarrito),1,p);
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

#endif // ARCHIVOITEMCARRITO_H_INCLUDED
