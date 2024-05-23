#ifndef CLSAUTOR_H_INCLUDED
#define CLSAUTOR_H_INCLUDED

//int buscarAutorPorId(int i);
//bool buscarGenero(int g);

class Autor{

    private:
    int id; //
    char nombre[30]; //
    int anioNacimiento; //
    int obrasPublicadas; //
    int generoIdentificado; //
    char nacionalidad[30]; //
    bool estado; //

    public:
    //sets
    bool setId(int i){
        if(buscarAutorPorId(i) == -1 && i > 0){
        id = i;
        return true;
        }
        return false;
        }
    void setNombre(const char *n){strcpy(nombre, n);}
    bool setAnioNacimiento(int a){
        if(a <= 2023){
        anioNacimiento = a;
        return true;
        }
        return false;
        }
    bool setObrasPublicadas(int o){
        if(o > 0){
        obrasPublicadas = o;
        return true;
        }
        return false;
        }
    bool setGeneroIdentificado(int g){
        if(buscarGenero(g)){
            generoIdentificado = g;
            return true;
        }
        return false;
    }
    void setNacionalidad(const char *n){strcpy(nacionalidad, n);}
    void setEstado(bool e){estado = e;}
    //gets
    int getId(){return id;}
    const char *getNombre(){return nombre;}
    int getAnioNacimiento(){return anioNacimiento;}
    int getObrasPublicadas(){return obrasPublicadas;}
    int getGeneroIdentificado(){return generoIdentificado;}
    const char *getNacionalidad(){return nacionalidad;}
    bool getEstado(){return estado;}

    bool operator==(const char *n){
        if(strcmp(nombre, n) == 0){
            return true;
        }
        return false;
    }

    void mostrar(){
        if(estado){
        cout << "ID: " << id << endl;
        cout << "NOMBRE: " << nombre << endl;
        cout << "ANIO NACIMIENTO: " << anioNacimiento << endl;
        cout << "OBRAS PUBLICADAS: " << obrasPublicadas << endl;
        cout << "GENERO IDENTIFICADO: " << generoIdentificado << endl;
        cout << "NACIONALIDAD: " << nacionalidad << endl;
        }
    }

    void cargar(){
        estado = true;
        cout << "ID: ";
        cin >> id;
        if(!setId(id)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "NOMBRE: ";
        cargarCadena(nombre, 29);
        cout << "ANIO NACIMIENTO: ";
        cin >> anioNacimiento;
        if(!setAnioNacimiento(anioNacimiento)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "OBRAS PUBLICADAS: ";
        cin >> obrasPublicadas;
        if(!setObrasPublicadas(obrasPublicadas)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "GENERO IDENTIFICADO: ";
        cin >> generoIdentificado;
        if(!setGeneroIdentificado(generoIdentificado)){
            cout<< "DATOS MAL INGRESADOS NO EXISTE ESE GENERO"<<endl;
            estado = false;
            return;
        }
        cout << "NACIONALIDAD: ";
        cargarCadena(nacionalidad, 29);

    }


};



class ArchivoAutor{
private:
    char nombre[30];
public:
    ArchivoAutor(const char *n){
		strcpy(nombre, n);
	}
	Autor leerRegistro(int pos){
        FILE *p;
        Autor x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
    }
    int grabarRegistro(Autor x){
        FILE *p;
        p=fopen(nombre,"ab");
        if(p==NULL) return -1;
        int escribio=fwrite(&x, sizeof x, 1, p);
        fclose(p);
        return escribio;
    }
    int contarRegistros(){
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Autor);
    }
    bool mostrarAutor(){
          system("cls");
          FILE *p;
          Autor reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(Autor),1,p)==1){
            reg.mostrar();
          }
          fclose(p);
          return true;
    }
};


////////////////////////////////////
void agregarAutor(){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    reg.cargar();
    if(reg.getEstado()){
        archi.grabarRegistro(reg);
    cout << "-|AUTOR CARGADO EXITOSAMENTE|-" << endl;

    }
    else{
        cout << "ERROR AL GRABAR EL REGISTRO" << endl;
    }
}

void listarAutorPorId(){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int id = 0, pos = 0;
    cout << "INGRESE EL ID A BUSCAR: "; cin >> id;
    pos = buscarAutorPorId(id);
    if(pos != -1){
    reg = archi.leerRegistro(pos);
    reg.mostrar();
    system("pause");
    system("cls");
    }else{
        cout<< "ESE ID NO EXISTE";
        cout<<endl;
   //     system("pause");
    //    system("cls");
        return;
    }
}

void listarTodosLosAutores(){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int cantReg = archi.contarRegistros();

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);
        if(reg.getEstado()) reg.mostrar();
    }
    cout<<endl;

}

void modificarObrasPublicadas(){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int id = 0, obras = 0;

    cout << "INGRESE EL ID A MODIFICAR: "; cin >> id;
    int pos = buscarAutorPorId(id);
    if(pos != -1){
    cout << "INGRESE OBRAS PUBLICADAS: "; cin >> obras;
    reg = archi.leerRegistro(pos);
    if(reg.setObrasPublicadas(obras)){
    FILE *p;
    p=fopen("Autores.dat","rb+");
    fseek(p,sizeof reg*pos,0);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    cout << "REGISTRO MODIFICADO!";
    cout<<endl;
    }else{
        cout<< "DATOS MAL INGRESADOS";
        cout<<endl;
    }
    }else{
        cout << "ESE ID NO EXISTE" << endl;
    }
}

void eliminarAutor(){
    Autor reg;
    ArchivoAutor archi("Autores.dat");
    int id = 0, pos = 0;

    cout << "INGRESE ID A ELIMINAR: "; cin >> id;
    pos = buscarAutorPorId(id);

    if(pos != -1){
        reg = archi.leerRegistro(pos);
        reg.setEstado(false);
        FILE *p;
        p=fopen("Autores.dat","rb+");
        fseek(p,sizeof reg*pos,0);
        fwrite(&reg,sizeof reg,1,p);
        fclose(p);

    }else{
        cout<< "ESE ID NO EXISTE";
        cout<<endl;
            return;
    }

}














#endif // CLSAUTOR_H_INCLUDED
