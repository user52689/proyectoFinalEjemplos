#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

class ArchivoCliente{
private:
    char nombre[30];
public:
    ArchivoCliente(const char* n){strcpy(nombre,n);}
        Cliente leerRegistro(int pos){
        Cliente reg;
        FILE*p;
        p=fopen(nombre,"rb");
        if(p==NULL) return reg;
        fseek(p,sizeof(Cliente)*pos,0);
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
        return tam/sizeof(Cliente);
    }
    bool agregarCliente(Cliente reg){
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        bool modifico=fwrite(&reg,sizeof(Cliente),1,p);
        fclose(p);
        return modifico;
    }
    bool agregarCliente(){
        Cliente reg;
        bool cargo, modifico;
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        cargo=reg.Cargar();
        if(cargo){
            modifico=fwrite(&reg, sizeof(Cliente), 1, p);
            fclose(p);
            return modifico;
        }
        return cargo;
    }

    bool modificarCliente(Cliente reg,int pos){
        FILE*p;
        p=fopen(nombre,"rb+");
        if(p==NULL) return false;
        fseek(p,sizeof(Cliente)*pos,0);
        bool modifico=fwrite(&reg,sizeof(Cliente),1,p);
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

#endif // ARCHIVOCLIENTE_H_INCLUDED
