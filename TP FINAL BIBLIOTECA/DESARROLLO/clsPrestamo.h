#ifndef CLASES_TP_FINAL_H_INCLUDED
#define CLASES_TP_FINAL_H_INCLUDED

#include "clsFECHA.h"

class Prestamo{
    private:
        int IDMiembro;
        int IDLibro;
        Fecha FechadePrestamo;
        Fecha FechaDevolucion;
        bool Estado;
    public:

        int getIDMiembro(){return IDMiembro;}
        int getIDLibro(){return IDLibro;}
        Fecha getFechaDePrestamo(){return FechadePrestamo;}
        Fecha getFechaDevolucion(){return FechaDevolucion;}
        bool getEstado(){return Estado;}

        void setIDMiembro(int idm){IDMiembro=idm;}
        bool setIDLibro(int idl){
            if(buscarLibroPrestado(idl)){
            IDLibro=idl;
            return true;
            }
            return false;
        }
        void setFechaDePrestamo(Fecha fp){FechadePrestamo=fp;}
        void setFechaDevolucion(Fecha fl){FechaDevolucion=fl;}
		void setEstado(bool e){Estado=e;}

        void Cargar(){
            Fecha aux;
            cout<<"ID MIEMBRO: ";cin>>IDMiembro;
            cout<<"ID LIBRO: ";cin>>IDLibro;
            if(!setIDLibro(IDLibro)){
                cout<< "DATOS MAL INGRESADOS"<<endl;
                Estado = false;
                return;
            }
            cout<<"FECHA PRESTAMO: ";aux.Cargar();
            setFechaDePrestamo(aux);
            aux+=15;
            cout<<"FECHA DEVOLUCION: ";setFechaDevolucion(aux);
            FechaDevolucion.MostrarFecha();
            Estado = true;


        }

        void Mostrar(){
            if(Estado){
                cout<<"ID MIEMBRO: "<<IDMiembro<<endl;
                cout<<"ID LIBRO: "<<IDLibro<<endl;
                cout<<"FECHA PRESTAMO: "<<endl;
                FechadePrestamo.MostrarFecha();
                cout<<"FECHA DEVOLUCION: "<<endl;
                FechaDevolucion.MostrarFecha();
                cout<<endl;
            }
        }
};

class ArchivoPrestamo{
private:
	char nombre[30];
public:

	ArchivoPrestamo(const char *n){
		strcpy(nombre, n);
	}

	Prestamo leerRegistro(int pos){
		Prestamo reg;
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
        return tam/sizeof(Prestamo);
    }

    bool grabarRegistro(Prestamo reg){
        FILE *p;
        p=fopen(nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

    bool mostrarPrestamo(){
          system("cls");
          FILE *p;
          Prestamo reg;
          p=fopen(nombre,"rb");
          if(p==NULL){
                cout<<"NO HAY REGISTROS CARGADOS"<<endl;
                return false;
          }
          while(fread(&reg,sizeof(Prestamo),1,p)==1){
            reg.Mostrar();
          }
          fclose(p);
          return true;
    }

    int buscarID(int id){
        Prestamo reg;
        FILE *p;
        p=fopen(nombre,"rb");
        if(p==NULL){
            cout<<"ERROR DE ARCHIVO"<<endl;
            return -2;
        }
        int posRegistro=0;
        while(fread(&reg,sizeof(Prestamo),1,p)==1){
            if(reg.getIDMiembro()==id && reg.getEstado()==true){
                fclose(p);
                return posRegistro;
            }
            posRegistro++;
        }
        fclose(p);
        return -1;
      }


};

void agregarPrestamo(){
    system("cls");
    Prestamo reg;
    ArchivoPrestamo archi("Prestamos.dat");
    reg.Cargar();
    if(reg.getEstado()){
        archi.grabarRegistro(reg);
        cout<<"-|PRESTAMO CARGADO EXITOSAMENTE|-"<<endl;
    }else{
        cout << "ERROR AL GRABAR EL REGISTRO" << endl;
    }
//    system("pause");
}

void listarPrestamoPorId(){
    system("cls");
    Prestamo reg;
    int id;
    int pos;
    cout<<"INGRESE EL ID DEL MIEMBRO DEL PRESTAMO A BUSCAR: "<<endl;
    cin>>id;
    ArchivoPrestamo archi("Prestamos.dat");
    pos = archi.buscarID(id);
    if(pos<0){
        cout<<"NO HAY PRESTAMO CON ESE ID"<<endl;
   //     system("pause");
        return;
    }
    reg = archi.leerRegistro(pos);
    reg.Mostrar();
}

void listarPrestamos(){
    ArchivoPrestamo archi("Prestamos.dat");
    archi.mostrarPrestamo();
 //   system("pause");
}

void eliminarPrestamo(){
    system("cls");
    ArchivoPrestamo archi("Prestamos.dat");
    int id;
    cout<<"INGRESE EL ID DEL MIEMBRO A DAR DE BAJA: "<<endl;
    cin>>id;
    int pos=archi.buscarID(id);
    if(pos==-1){
        cout<<"NO EXISTE REGISTRO CON ESE ID"<<endl;
   //     system("pause");
        return;
    }
    Prestamo reg;
    FILE *p;
    p=fopen("Prestamos.dat","rb+");
    fseek(p,sizeof reg*pos,0);
    reg=archi.leerRegistro(pos);
    reg.setEstado(false);
    fwrite(&reg,sizeof reg,1,p);
    fclose(p);
    cout<<"PRESTAMO ELIMINADO!"<<endl;
  //  system("pause");
}


#endif // CLASES_TP_FINAL_H_INCLUDED
