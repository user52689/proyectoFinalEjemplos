#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

class GenerosNuevo{
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
            if(buscarGenero(id) && id > 0){
            IDgenero=id;
            return true;
            }
            return false;
            }

        bool setAnioDeOrigen(int a){
            if(a>0 && a<2023){
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

class ArchivoGeneroNuevo{
private:
	char nombre[30];
public:

	ArchivoGeneroNuevo(const char *n){
		strcpy(nombre, n);
	}

	GenerosNuevo leerRegistro(int pos){
		GenerosNuevo reg;
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
        return tam/sizeof(GenerosNuevo);
    }

    bool grabarRegistro(GenerosNuevo reg){
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
          GenerosNuevo reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(GenerosNuevo),1,p)==1){
            reg.Mostrar();
          }
          fclose(p);
          return true;
    }

    int buscarID(int id){
        GenerosNuevo reg;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&reg,sizeof(GenerosNuevo),1,p)==1){
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

void mostrarArchivoGeneroNuevo(){
    GenerosNuevo regGen;
    FILE *pCom=fopen("GenerosNuevo.dat","rb");
    if(pCom==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
        return;
    }
    while(fread(&regGen, sizeof regGen,1,pCom)==1){
        regGen.Mostrar();
        cout<<endl;
    }
    fclose(pCom);
}

void Punto4(){
ArchivoGenero ArchiG ("Generos.dat");
ArchivoGeneroNuevo ArchiNuevo ("GenerosNuevo.dat");

Genero Obj;
GenerosNuevo Aux;
int cantreg=ArchiG.contarRegistros();

for(int i=0;i<cantreg;i++){
        Obj=ArchiG.leerRegistro(i);
        if(Obj.getEstado()==true && Obj.getAnioDeOrigen()<1800){
                Aux.setIDgenero(Obj.getIDgenero());
                Aux.setAnioDeOrigen(Obj.getAnioDeOrigen());
                Aux.setAutorOrigenGenero(Obj.getAutorOrigenGenero());
                Aux.setNombreDelGenero(Obj.getNombreDelGenero());
                Aux.setDescripcion(Obj.getDescripcion());
                Aux.setEstado(Obj.getEstado());
                if(ArchiNuevo.grabarRegistro(Aux)){
                cout<<"SE HA GRABADO CORRECTAMENTE"<<endl;
                }
                else {cout<<"ERROR"<<endl;}
        }
    }
}

int ContarRegistrosLibros(){
FILE *p;
p=fopen("Libros.dat","rb");
if(p==NULL)return 0;
fseek(p,0,2);
int tam=ftell(p);
fclose(p);
return tam/sizeof(Libro);
}

void CargarArchivoEnVector(Libro *vec, int Cantreg){
    FILE *p;
    p=fopen("Libros.dat","rb");
    if(p==NULL)return;
    fread(vec, sizeof(Libro),Cantreg,p);
    fclose(p);
}

void MostrarVectorMateriales(Libro *vec, int Cantreg, char *Autor){
    int i;
    for(i=0;i<Cantreg;i++){
        if(vec[i].getEstado()==true && strcmp(vec[i].getAutor(),Autor)==0){
            vec[i].Mostrar();
            cout<<endl;
            }
        }
}

int Punto6(){
Libro *vec;
char Autor[30];

int Cantreg=ContarRegistrosLibros();

if(Cantreg==0){
    cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
    return -1;
    }

vec=new Libro[Cantreg];

if(vec==NULL){
    cout<<"PROBLEMAS DE ASIGNACION DE MEMORIA"<<endl;
    return -1;
}

CargarArchivoEnVector(vec, Cantreg);

cout<<"INGRESE EL NOMBRE DEL AUTOR: "<<endl;
cargarCadena(Autor,29);

MostrarVectorMateriales(vec,Cantreg,Autor);
delete vec;

system("pause");
return 0;

}

void punto1();
Libro buscarLibro(const char *autor);
void listarVector(Libro *v, int tam);
void punto2();
Libro buscarLibroGenero(int idLibro);
void punto3();

/*bool operator==(int Cantidad){
        if(paginas==Cantidad) return true;
        return false;
}*/

void Punto7(){
ArchivoLibro ArchiL("Libros.dat");
Libro Obj;
int cantreg=ArchiL.contarRegistros();
int Cantidad;

cout<<"INGRESE LA CANTIDAD DE PAGINAS: ";
cin>>Cantidad;

for(int i=0;i<cantreg;i++){
    Obj=ArchiL.leerRegistro(i);
    Obj.Mostrar();
        if(Cantidad==Obj.getPaginas()){
            cout<<"TIENE LA MISMA CANTIDAD DE PAGINAS"<<endl;
            cout<<"/////////////////////"<<endl;
            }
        else{
            cout<<"NO TIENE LA MISMA CANTIDAD DE PAGINAS"<<endl;
            cout<<"/////////////////////"<<endl;
        }
    }
}

void Punto8(){
    ArchivoAutor archiA("Autores.dat");
    int cantReg=archiA.contarRegistros();
    int contIni=0, contador=0;
    Autor obj, *vec;

    for(int i=0;i<cantReg;i++){
        obj=archiA.leerRegistro(i);
        if(obj.getAnioNacimiento()>1805){
            contIni++;
        }
    }

    vec = new Autor[contIni];
    for(int a=0;a<cantReg;a++){
        obj=archiA.leerRegistro(a);
        if(obj.getAnioNacimiento()>1805){
            vec[contador]=obj;
            vec[contador].mostrar();
            contador++;
        }
    }
    delete vec;

    system("pause");
    return ;

}

class LibrosAutor{

    private:
    char nombre[30];
    char nacionalidad[30];
    int cantLibros;
    bool estado;

    public:
    void setNombre(const char *n){strcpy(nombre, n);}
    void setNacionalidad(const char *n){strcpy(nacionalidad, n);}
    void setCantLibros(int c){cantLibros = c;}
    void setEstado(bool e){estado = e;}

    void mostrar(){
        cout << "NOMBRE: " << nombre << endl;
        cout << "NACIONALIDAD: " << nacionalidad << endl;
        cout << "CANTIDAD DE LIBROS: " << cantLibros << endl;
        cout << endl;
    }

int leerDeDisco(int pos){
   FILE *p;
    p=fopen("LibrosAutor.dat","rb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");

        return false;
    }
    fseek(p,pos*sizeof (LibrosAutor),0);
    bool leyo=fread(this, sizeof (LibrosAutor), 1,p);
    fclose(p);
    return leyo;
}

bool grabarEnDisco(){
     FILE *p;
    p=fopen("LibrosAutor.dat","ab");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
        return false;
    }
    bool escribio=fwrite(this, sizeof (LibrosAutor), 1,p);
    fclose(p);
    return escribio;
}
};

void punto9(){
    //Se reinicia el archivo para que no se repitan registros
    FILE *p;
    p=fopen("LibrosAutor.dat","wb");
    if(p==NULL){
        cout<<"no se encuentra"<<endl;
        system("pause");
        return;
    }

    Autor regAut;
    ArchivoAutor archiAut("Autores.dat");
    Libro regLib;
    ArchivoLibro archiLib("Libros.dat");
    int cantRegAut = archiAut.contarRegistros();
    int cantRegLib = archiLib.contarRegistros();
    int cont = 0, pos = 0;

    LibrosAutor obj;

    for(int i = 0; i < cantRegAut; i++){
        regAut = archiAut.leerRegistro(i);

        if(regAut.getEstado()){
        for(int j = 0; j < cantRegLib; j++){
            regLib=archiLib.leerRegistro(j);
            if(regAut==regLib.getAutor()){
                cont++;
            }
        }
        if(cont >= 2){
            obj.setNombre(regAut.getNombre());
            obj.setNacionalidad(regAut.getNacionalidad());
            obj.setCantLibros(cont);
            obj.setEstado(true);
            obj.grabarEnDisco();
        }
        cont = 0;
        }

    }

    while(obj.leerDeDisco(pos)){
        obj.mostrar();
        pos++;
    }

}

void punto10(){
    Libro reg;
    ArchivoLibro archi("Libros.dat");
    int cantReg = archi.contarRegistros();
    int cont = 0, tipo = 0, pos = 0;

    cout << "INGRESE ID DEL GENERO A BUSCAR: "; cin >> tipo;

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);

        if(reg.getGenero() == tipo){
            cont++;
        }
    }



    Libro *vec;
    vec = new Libro[cont];
    if(vec == NULL){
        cout << "ERROR AL ASIGNAR MEMORIA" << endl;
        system("pause");
        return;
        }

    for(int i = 0; i < cantReg; i++){
        reg = archi.leerRegistro(i);

        if(reg.getGenero() == tipo){
            vec[pos] = archi.leerRegistro(i);
            pos++;
        }
    }

    for(int i = 0; i < cont; i++){
        vec[i].Mostrar();
        cout << endl;
    }

delete vec;

}

void menuReportes(){
    int opc;
    cout<<"1-Generar un archivo con los libros escritos por autores "<<endl;
    cout<<"  argentinos. Los registros deben tener el mismo formato que el"<<endl;
    cout<<"  archivo Libros.dat"<<endl;
    cout<<"2-Generar un vector dinamico con los libros que tengan menos de 200 paginas"<<endl;
    cout<<"3-Listar por pantalla el genero que tenga mas libros alquilados"<<endl;
    cout<<"  al momento de la consulta."<<endl;
    cout<<"4-Generar un archivo con los generos que hayan sido creados antes del anio 1800."<<endl;
    cout<<"5-Mostrar el archivo nuevo."<<endl;
    cout<<"6-Generar un vector dinamico con todos los libros y listar luego los libros del"<<endl;
    cout<<"vector que pertenezcan a un autor que se ingresa por teclado."<<endl;
    cout<<"7-Sobrecargar el operador == para la clase Libro de manera tal que sea verdadero cuando el objeto que"<<endl;
    cout<<"llama al metodo tenga un valor de paginas igual a un valor de tipo int que se recibe como parametro."<<endl;
    cout<<"8-Generar un vector dinámico con los autores nacidos despues de 1805. Mostrar el vector."<<endl;
    cout<<"9-Generar un archivo con los autores que tengan mas de un libro registrado. El archivo debe contener 'nombre del autor', 'nacionalidad', y"<<endl;
    cout<<"  'numero de libros registrados'."<<endl;
    cout<<"10-Generar un vector dinamico con los libros de un genero que se ingresa por teclado. Mostrar el vector"<<endl;
    cout<<"0-Volver al MENU PRINCIPAL"<<endl;
    cout<<"INGRESE UNA OPCION: ";
    cin>>opc;
    system("cls");
    switch(opc){
    case 1: punto1();
        system("pause");
        system("cls");
        break;
    case 2: punto2();
        system("pause");
        system("cls");
        break;
    case 3: punto3();
        system("pause");
        system("cls");
        break;
    case 4: Punto4();
        system("pause");
        system("cls");
        break;
    case 5: mostrarArchivoGeneroNuevo();
        system("pause");
        system("cls");
        break;
    case 6: Punto6();
        system("pause");
        system("cls");
        break;
    case 7: Punto7();
        system("pause");
        system("cls");
        break;
    case 8: Punto8();
        system("pause");
        system("cls");
        break;
    case 9: punto9();
        system("pause");
        system("cls");
        break;
    case 10: punto10();
        system("pause");
        system("cls");
        break;
    case 0:
        system("cls");
        return;
        break;
    default:
        cout<<"OPCION INCORRECTA"<<endl;
        system("pause");
        system("cls");
        return;
    }
}


void punto1(){
    ArchivoAutor archiAutor("Autores.dat");
    ArchivoLibro archiLibro("Libros.dat"), archiArgentino("Libros_Argentinos.dat");
    Autor regAutor;
    Libro regLibro;
    bool bandera = false;
    int cantReg = archiAutor.contarRegistros();
    for(int i=0;i<cantReg;i++){
        regAutor = archiAutor.leerRegistro(i);
        if(strcmp(regAutor.getNacionalidad(),"Argentino")==0){
            regLibro = buscarLibro(regAutor.getNombre());
            archiArgentino.grabarRegistro(regLibro);
            bandera = true;
        }
    }
    if(!bandera) cout<<"NO HAY LIBROS DE AUTORES ARGENTINOS"<<endl;
}

Libro buscarLibro(const char *autor){
    ArchivoLibro archi("Libros.dat");
    Libro reg;
    int cantReg = archi.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg = archi.leerRegistro(i);
        if(strcmp(reg.getAutor(),autor) == 0){
           return reg;
        }
    }
    reg.setEstado(false);
    return reg;
}

void listarVector(Libro *v, int tam){
    for(int i=0;i<tam;i++){
        v[i].Mostrar();
        cout<<endl;
    }
}

void punto2(){
     ArchivoLibro archiLibro("Libros.dat");
     Libro regLibro, *v;
     int menos200 = 0;
     int cantReg = archiLibro.contarRegistros();
     for(int i=0;i<cantReg;i++){
        regLibro = archiLibro.leerRegistro(i);
        if(regLibro.getPaginas()<200) menos200++;
     }
     if(menos200==0) cout<<"No hay libros que tengan menos de 200 paginas."<<endl;
     else{
        int contador = 0;
        v = new Libro[menos200];
        for(int i=0;i<cantReg;i++){
            regLibro = archiLibro.leerRegistro(i);
            if(regLibro.getPaginas()<200 && regLibro.getEstado()){
                v[contador] = regLibro;
                contador++;
            }
        }
        listarVector(v,contador);
        delete v;
     }
}

int buscarMaximo(int *v, int tam){
    int maximo = v[0];
    int pos = 0;
    for(int i=1;i<tam;i++){
        if(v[i]>maximo){
            maximo = v[i];
            pos = i;
        }
    }
    return pos;
}

void punto3(){
    ArchivoPrestamo archiPrestamo("Prestamos.dat");
    ArchivoGenero archiGenero("Generos.dat");
    Genero regGenero;
    Libro regLibro;
    Prestamo regPrestamo;
    int mayorGenero;
    int cantGen = archiGenero.contarRegistros();
    int *v;
    v = new int[cantGen];
    for(int i=0;i<cantGen;i++) v[i] = 0;
    int cantPres = archiPrestamo.contarRegistros();
    for(int i=0;i<cantPres;i++){
        regPrestamo = archiPrestamo.leerRegistro(i);
        regLibro = buscarLibroGenero(regPrestamo.getIDLibro());
        v[regLibro.getGenero()-1]++;
    }
    mayorGenero = buscarMaximo(v,cantGen);
    for(int i=0;i<cantGen;i++){
        regGenero = archiGenero.leerRegistro(i);
        if(regGenero.getIDgenero() == mayorGenero){
            regGenero.Mostrar();
            i+=cantGen;
        }
    }

    delete v;
}

Libro buscarLibroGenero(int idLibro){
    ArchivoLibro archi("Libros.dat");
    Libro reg;
    int cantReg = archi.contarRegistros();
    for(int i=0;i<cantReg;i++){
        reg = archi.leerRegistro(i);
        if(reg.getId()==idLibro){
           return reg;
        }
    }
    reg.setEstado(false);
    return reg;
}

#endif // REPORTES_H_INCLUDED
