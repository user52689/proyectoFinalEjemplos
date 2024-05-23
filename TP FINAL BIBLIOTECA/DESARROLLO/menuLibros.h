#ifndef MENULIBROS_H_INCLUDED
#define MENULIBROS_H_INCLUDED

#include"clsLibro.h"

void menuLibros(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU LIBROS" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("AGREGAR LIBRO",50,5,y==0);
        mostrarItem("LISTAR LIBRO POR ID",50,7,y==1);
        mostrarItem("LISTAR TODOS LOS LIBROS",50,9,y==2);
        mostrarItem("MODIFICAR ANIO DE EDICION",50,11,y==3);
        mostrarItem("ELIMINAR LIBRO",50,13,y==4);
        mostrarItem("VOLVER AL MENU PRINCIPAL",50,15,y==5);
        int key = rlutil::getkey();
        switch(key){
            case 14: //SUBIR
                y --;
                if(y<0) y = 0;
                break;
            case 15: //BAJAR
                y ++;
                if(y>5) y = 5;
                break;
            case 1: //ENTER
            system("cls");
                switch(y){
                        case 0:
                            agregarLibro();
                            system("pause");
                            system("cls");
                            break;
                        case 1:
                            listarLibroPorId();
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            listarLibros();
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            modificarUltimaEdicion();
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            eliminarLibro();
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            system("cls");
                            return;
                            break;
                        default: cout<<"OPCION INCORRECTA"<<endl;
                        break;
                }
                break;
        }

    }
}

#endif // MENULIBROS_H_INCLUDED
