#ifndef CLASE_GENERO_H_INCLUDED
#define CLASE_GENERO_H_INCLUDED

class Genero{
    private:
        int IDgenero;
        int AnioDeOrigen;
        char AutorOrigenGenero[30];
        char NombreGenero[30];
        char Descripcion[200];
        bool Estado;
    public:

        int getIDgenero(){return IDgenero;}
        int getAnioDeOrigen(){return AnioDeOrigen;}
        const char *getAutorOrigenGenero(){return AutorOrigenGenero;}
        const char *getNombreDelGenero(){return NombreGenero;}
        const char *getDescripcion(){return Descripcion;}
        bool getEstado(){return Estado;}

        bool setIDgenero(int id){
            if(!buscarGenero(id) && id > 0){
            IDgenero=id;
            return true;
            }
            return false;
            }

        bool setAnioDeOrigen(int a){
            if(a > 0 && a < 2023){
                AnioDeOrigen=a;
                    return true;
                }else{
                    return false;
                }
            }
        void setAutorOrigenGenero(const char *au){strcpy(AutorOrigenGenero,au);}
        void setNombreDelGenero(const char *n){strcpy(NombreGenero,n);}
        void setDescripcion(const char *d){strcpy(Descripcion,d);}
		void setEstado(bool e){Estado=e;}


        void Cargar(){
            Estado=true;
            cout<<"ID GENERO: ";
            cin>>IDgenero;
                if(!setIDgenero(IDgenero)){
                cout<< "DATOS MAL INGRESADOS"<<endl;
                Estado=false;
                return;
            }
            cout<<"ANIO DE ORIGEN DEL GENERO: ";cin>>AnioDeOrigen;
            if(!setAnioDeOrigen(AnioDeOrigen)){
                cout<<"DATOS MAL INGRESADOS"<<endl;
                cout<<"EL ANIO DE ORIGEN TIENE QUE SER MENOR AL ACTUAL."<<endl;
                cout<<"EL ANIO DE ORIGEN NO PUEDE SER NEGATIVO."<<endl;
                    //   system("pause");
                Estado=false;
                return;
            }
            cout<<"AUTOR QUE LE DIO ORIGEN AL GENERO: ";cargarCadena(AutorOrigenGenero,39);
            cout<<"NOMBRE DEL GENERO: ";cargarCadena(NombreGenero,39);
            cout<<"DESCRIPCION: ";cargarCadena(Descripcion,199);
        }

        void Mostrar(){
            if(Estado==true){
            cout<<"ID GENERO: "<<IDgenero<<endl;
            cout<<"ANIO DE ORIGEN DEL GENERO: "<<AnioDeOrigen<<endl;
            cout<<"AUTOR QUE LE DIO ORIGEN AL GENERO: "<<AutorOrigenGenero<<endl;
            cout<<"NOMBRE DEL GENERO: "<<NombreGenero<<endl;
            cout<<"DESCRIPCION: "<<Descripcion<<endl;
            }
        }


};

class ArchivoGenero{
private:
	char nombre[30];
public:

	ArchivoGenero(const char *n){
		strcpy(nombre, n);
	}

	Genero leerRegistro(int pos){
		Genero reg;
		reg.setEstado(false);
		FILE *p;
		p=fopen(nombre, "rb");
		if(p==NULL) return reg;
		fseek(p, sizeof reg*pos,0);
		fread(&reg, sizeof reg,1, p);
		fclose(p);
		return reg;
	}

    int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Genero);
    }

    bool grabarRegistro(Genero reg){
        if(reg.getEstado()==true){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
        }
    }

    bool mostrarGenero(){
          system("cls");
          FILE *p;
          Genero reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(Genero),1,p)==1){
            reg.Mostrar();
          }
          fclose(p);
          return true;
    }

    int buscarID(int id){
        Genero reg;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&reg,sizeof(Genero),1,p)==1){
            if(reg.getIDgenero()==id){
                fclose(p);
                return posRegistro;
            }
            posRegistro++;
        }
        fclose(p);
        return -1;
      }

};

void agregarGenero(){
    system("cls");
    Genero reg;
    ArchivoGenero archi("Generos.dat");
    reg.Cargar();
    
    if(reg.getEstado()){
        archi.grabarRegistro(reg);
        cout<<"-|GENERO CARGADO EXITOSAMENTE|-"<<endl;
    }else{
        cout<<"-|ERROR AL GRABAR EL REGISTRO|-"<<endl;
    }
}

void listarGeneroPorId(){
    system("cls");
    Genero reg;
    int id;
    int pos;
    cout<<"INGRESE EL ID A BUSCAR: "<<endl;
    cin>>id;
    ArchivoGenero archi("Generos.dat");
    pos = archi.buscarID(id);
    reg = archi.leerRegistro(pos);
    reg.Mostrar();
    cout<<endl;
}

void listarGeneros(){
    ArchivoGenero archi("Generos.dat");
    archi.mostrarGenero();
}

void modificarAnio(){
    system("cls");
    ArchivoGenero archi("Generos.dat");
    Genero reg;
    int id, anio;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL NUEVO ANIO DE CREACION: "<<endl;
    cin>>anio;
    FILE *p;
    p=fopen("Generos.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    int posReg=archi.buscarID(id);
    if(posReg==-1) cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    else{
        if(posReg>-1){
            fseek(p,sizeof reg*posReg,0);
            reg=archi.leerRegistro(posReg);
            reg.setAnioDeOrigen(anio);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            cout<<"ANIO MODIFICADO!"<<endl;
        }
    }
}

void eliminarGenero(){
    system("cls");
    ArchivoGenero archi("Generos.dat");
    int id;
    cout<<"INGRESE EL ID DEL GENERO A DAR DE BAJA: "<<endl;
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
        return;
    }
    Genero reg;
    FILE *p;
    p=fopen("Generos.dat","rb+");
    fseek(p,sizeof reg*pos,0);
    reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    cout<<"GENERO ELIMINADO!"<<endl;
}


#endif // CLASE_GENERO_H_INCLUDED
