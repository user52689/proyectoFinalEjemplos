#ifndef CLSMIEMBRO_H_INCLUDED
#define CLSMIEMBRO_H_INCLUDED



class Miembro{
private:
    int IDmiembro, dni, telefono;
    char nombre[30], email[30];
    bool estado;
    Fecha fechaNacimiento;
public:
    void setIDmiembro(int id){IDmiembro=id;}
    void setNombre(const char *n){strcpy(nombre,n);}
    void setDni(int d){dni=d;}
    void setTelefono(int t){telefono=t;}
    void setEmail(const char *e){strcpy(email,e);}
    void setFechaNacimiento(Fecha aux){fechaNacimiento=aux;}
    void setEstado(bool est){estado=est;}

    int getIDmiembro(){return IDmiembro;}
    const char *getNombre(){return nombre;}
    int getDni(){return dni;}
    int getTelefono(){return telefono;}
    const char *getEmail(){return email;}
    Fecha getFechaNacimiento(){return fechaNacimiento;}
    bool getEstado(){return estado;}

    void Cargar(int id=-1){
        int aux;
        char auxChar[30];
        if(id==-1){
            cout<<"ID: "<<endl;
            cin>>IDmiembro;
        }
        else{
            IDmiembro=id;
        }
        cout<<"DNI: "<<endl;
        cin>>aux;
        setDni(aux);
        if(dni<0){
            estado = false;
            return;
        }
        cout<<"NOMBRE: ";
        cargarCadena(auxChar,30);
        setNombre(auxChar);
        cout<<"TELEFONO: ";
        cin>>aux;
        setTelefono(aux);
        if(telefono<0){
            estado = false;
            cout<<"DATOS ERRONEOS"<<endl;
            return;
        }
        cout<<"FECHA DE NACIMIENTO: ";
        fechaNacimiento.Cargar();
        if(fechaNacimiento.getDia()==-1 || fechaNacimiento.getMes()==-1 || fechaNacimiento.getDia()==-1){
            estado = false;
            cout<<"DATOS ERRONEOS"<<endl;
            return;
        }
        cout<<"EMAIL: ";
        cargarCadena(auxChar,30);
        setEmail(auxChar);
        estado=true;
    }
    void Mostrar(){
        if(estado){
            cout << "ID MIEMBRO: ";
            cout <<  IDmiembro <<endl;
            cout << "NOMBRE: ";
            cout <<  nombre <<endl;
            cout << "DNI: ";
            cout <<  dni <<endl;
            cout << "TELEFONO: ";
            cout <<  telefono <<endl;
            cout << "FECHA DE NACIMIENTO: ";
            fechaNacimiento.MostrarFecha();
            cout << "EMAIL: ";
            cout <<  email ;
            cout << endl;
        }
    }
};

class ArchivoMiembro{
private:
    char nombre[30];
public:
    ArchivoMiembro(const char *n){
		strcpy(nombre, n);
	}
	Miembro leerRegistro(int pos){
        FILE *p;
        Miembro x;
        p=fopen(nombre,"rb");
        if(p==NULL) exit(1);
        fseek(p, pos* sizeof x,0);
        fread(&x, sizeof x, 1, p);
        fclose(p);
        return x;
    }
    int grabarRegistro(Miembro x){
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
        return tam/sizeof(Miembro);
    }
    bool mostrarMiembro(){
          system("cls");
          FILE *p;
          Miembro reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(Miembro),1,p)==1){
            reg.Mostrar();
            cout<<endl;
          }
          fclose(p);
          return true;
    }
    int buscarID(int id){
        Miembro reg;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&reg,sizeof(Miembro),1,p)==1){
            if(reg.getIDmiembro()==id){
                fclose(p);
                return posRegistro;
            }
            posRegistro++;
        }
        fclose(p);
        return -1;
      }
};

void agregarMiembro(){
    system("cls");
    Miembro reg;
    int id;
    cout<<"ID: "<<endl;
    cin>>id;
    ArchivoMiembro archi("Miembros.dat");
    int pos=archi.buscarID(id);
    if(pos==-1||pos==-2){
        reg.Cargar(id);

        if(reg.getEstado()==true){
            archi.grabarRegistro(reg);
            cout<<"-|MIEMBRO CARGADO EXITOSAMENTE|-"<<endl;
        }
        else cout<<"xX-NO SE PUDO CARGAR, DATOS ERRONEOS-Xx"<<endl;
    }
    else cout<<"YA EXISTE REGISTRO CON ESE ID"<<endl;
//    system("pause");
 //   system("cls");
}



void listarMiembroPorId(){
    system("cls");
    Miembro reg;
    int id;
    int pos;
    cout<<"INGRESE EL ID A BUSCAR: "<<endl;
    cin>>id;
    ArchivoMiembro archi("Miembros.dat");
    pos = archi.buscarID(id);
    if(pos != -1){
    reg = archi.leerRegistro(pos);
    reg.Mostrar();
    }else{
        cout << "ESE ID NO EXISTE" << endl;
    }
}

void listarMiembros(){
    ArchivoMiembro archi("Miembros.dat");
    archi.mostrarMiembro();
}

void eliminarMiembro(){
    system("cls");
    ArchivoMiembro archi("Miembros.dat");
    int id;
    cout<<"INGRESE EL ID DEL MIEMBRO A DAR DE BAJA: "<<endl;
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
      //  system("pause");
        return;
    }
    Miembro reg;
    FILE *p;
    p=fopen("Miembros.dat","rb+");
    fseek(p,sizeof reg*pos,0);
    reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    cout<<"MIEMBRO ELIMINADO!"<<endl;
 //   system("pause");
}

void modificarTelefono(){
    system("cls");
    ArchivoMiembro archi("Miembros.dat");
    Miembro reg;
    int id, tel;
    cout<<"INGRESE EL ID: "<<endl;
    cin>>id;
    cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO: "<<endl;
    cin>>tel;
    FILE *p;
    p=fopen("Miembros.dat","rb+");
    if(p==NULL){
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
    int posReg=archi.buscarID(id);
    if(posReg==-1) cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
    else{
        if(posReg>-1){
            fseek(p,sizeof reg*posReg,0);
            reg=archi.leerRegistro(posReg);
            reg.setTelefono(tel);
            fwrite(&reg,sizeof reg,1,p);
            fclose(p);
            cout<<"TELEFONO MODIFICADO!"<<endl;
        }
    }
}

#endif // CLSMIEMBRO_H_INCLUDED
