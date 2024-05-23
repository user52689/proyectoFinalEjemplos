#ifndef CLSLIBRO_H_INCLUDED
#define CLSLIBRO_H_INCLUDED

class Libro{

    private:
    int id;
    int paginas;
    char titulo[30];
    bool prestado;
    bool estado;
    int genero;
    char autor[30];
    int ultimaEdicion;
    //char nombreAlquilado[30];

    public:
    //sets
    bool setId(int i){
        if(!buscarIdLibro(i) && i > 0){
        id = i;
        return true;
        }
        return false;
    }
    bool setPaginas(int p){
        if(p > 0){
        paginas = p;
        return true;
        }
        return false;
        }
    void setTitulo(const char *t){strcpy(titulo, t);}
    void setPrestado(bool p){prestado = p;}
    void setEstado(bool e){estado = e;}
    bool setGenero(int g){
        if(buscarGenero(g)){
        genero = g;
        return true;
        }
        return false;
        }
    bool setAutor(const char *a){
        if(buscarNombreAutor(a)){
            strcpy(autor, a);
            return true;
        }
        return false;
        }
    bool setUltimaEdicion(int u){
        if(u > 0){
        ultimaEdicion = u;
        return true;
        }
        return false;
        }
    //void setNombreAlquilado(const char *n){strcpy(nombreAlquilado, n);}
    //gets
    int getId(){return id;}
    int getPaginas(){return paginas;}
    const char *getTitulo(){return titulo;}
    bool getPrestado(){return prestado;}
    bool getEstado(){return estado;}
    int getGenero(){return genero;}
    const char *getAutor(){return autor;}
    int getUltimaEdicion(){return ultimaEdicion;}
   // const char *getNombreAlquilado(){return nombreAlquilado;}


    bool operator==(int Cantidad){
        if(paginas==Cantidad) return true;
        return false;
    }
    void Mostrar(){
        if(estado && prestado == false){
        cout << "ID: " << id << endl;
        cout << "PAGINAS: " << paginas << endl;
        cout << "TITULO: " << titulo << endl;
        cout << "GENERO: " << genero << endl;
        cout << "AUTOR: " << autor << endl;
        cout << "ULTIMA EDICION: " << ultimaEdicion << endl;
        cout<<endl;
        //if(prestado){
       //     cout << "NOMBRE ALQUILADO: " << nombreAlquilado << endl;
      //  }
       // }
    }
}

    void Cargar(){
        estado = true;
        cout << "ID: ";
        cin >> id;
        if(!setId(id)){
            cout<< "DATOS MAL INGRESADOS" << endl;
            cout<< "YA EXISTE UN LIBRO CON ESE ID"<<endl;
            estado = false;
            return;
        }
        cout << "PAGINAS: ";
        cin >> paginas;
        if(!setPaginas(paginas)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "TITULO: ";
        cargarCadena(titulo, 29);
        cout << "GENERO: ";
        cin >> genero;
        if(!setGenero(genero)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "AUTOR: ";
        cargarCadena(autor, 29);
        if(!setAutor(autor)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        cout << "ULTIMA EDICION: ";
        cin >> ultimaEdicion;
        if(!setUltimaEdicion(ultimaEdicion)){
            cout<< "DATOS MAL INGRESADOS"<<endl;
            estado = false;
            return;
        }
        estado = true;
        prestado = false;
    }
};

class ArchivoLibro{
private:
    char nombre[30];
public:
    ArchivoLibro(const char *n){
		strcpy(nombre, n);
	}
	Libro leerRegistro(int pos){
        FILE *p;
        Libro x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
    }
    int grabarRegistro(Libro x){
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
        return tam/sizeof(Libro);
    }
    bool mostrarLibro(){
          system("cls");
          FILE *p;
          Libro reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(Libro),1,p)==1){
            if(reg.getEstado()){
            reg.Mostrar();
            }
          }
          fclose(p);
          return true;
    }
    int buscarID(int id){
        Libro reg;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&reg,sizeof(Libro),1,p)==1){
            if(reg.getId()==id && reg.getEstado() == true){
                fclose(p);
                return posRegistro;
            }
            posRegistro++;
        }
        fclose(p);
        return -1;
      }
};

void agregarLibro(){
    system("cls");
    Libro reg;
    ArchivoLibro archi("Libros.dat");
    reg.Cargar();

    if(reg.getEstado()){
        archi.grabarRegistro(reg);
        cout<<"-|LIBRO CARGADO EXITOSAMENTE|-"<<endl;
    }else{
        cout << "ERROR AL GRABAR EL REGISTRO" << endl;
    }
  //  system("pause");
}

void listarLibroPorId(){
    system("cls");
    Libro reg;
    int id;
    int pos = 0;
    cout<<"INGRESE EL ID A BUSCAR: "<<endl;
    cin>>id;
    ArchivoLibro archi("Libros.dat");
    pos = archi.buscarID(id);
    if(pos != -1){
    reg = archi.leerRegistro(pos);
    reg.Mostrar();
    }else{
        cout << "ESE ID NO EXISTE" << endl;
        return;
    }
}

void listarLibros(){
    system("cls");
    ArchivoLibro archi("Libros.dat");
    archi.mostrarLibro();
  //  system("pause");
}

void listarLibrosAlquilados(){
    system("cls");
    Libro reg;
    ArchivoLibro archi("Libros.dat");
    int cantReg;
    cantReg = archi.contarRegistros();
    if(cantReg==0){
        cout<<"NO HAY LIBROS ALQUILADOS"<<endl;
        return;
    }
    for(int i=0;i<cantReg;i++){
        reg = archi.leerRegistro(i);
        if(reg.getPrestado()) reg.Mostrar();
    }
  //  system("pause");
}

void nuevoLibroAlquilado(bool pr){
    system("cls");
    ArchivoLibro archi("Libros.dat");
    Libro reg;
    int id;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    FILE *p;
    p=fopen("Liros.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    int posReg=archi.buscarID(id);
    if(posReg==-1) cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    else{
        if(posReg>-1){
            fseek(p,sizeof reg*posReg,0);
            reg=archi.leerRegistro(posReg);
            reg.setPrestado(pr);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            if(pr) cout<<"ALQUILER REGISTRADO CORRECTAMENTE!"<<endl;
            else cout<<"REGRESO DE LIBRO REGISTRADO!"<<endl;
        }
    }
 //   system("pause");
}

void modificarUltimaEdicion(){
    system("cls");
    ArchivoLibro archi("Libros.dat");
    Libro reg;
    int id, anio;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL NUEVO ANIO DE EDICION: "<<endl;
    cin>>anio;
    FILE *p;
    p=fopen("Libros.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    int posReg=archi.buscarID(id);
    if(posReg==-1) cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    else{
        if(posReg>-1){
            fseek(p,sizeof reg*posReg,0);
            reg=archi.leerRegistro(posReg);
            reg.setUltimaEdicion(anio);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            cout<<"ULTIMA EDICION MODIFICADA!"<<endl;
        }
    }
  //  system("pause");
}

void eliminarLibro(){
    system("cls");
    ArchivoLibro archi("Libros.dat");
    int id;
    cout<<"INGRESE EL ID DEL LIBRO A DAR DE BAJA: "<<endl;
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
        return;
    }
    Libro reg;
    FILE *p;
    p=fopen("Libros.dat","rb+");
    fseek(p,sizeof reg*pos,0);
    reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    cout<<"LIBRO ELIMINADO!"<<endl;
 //   system("pause");
}

#endif // CLSLIBRO_H_INCLUDED
