#ifndef MENUAUTORES_H_INCLUDED
#define MENUAUTORES_H_INCLUDED

#include "clsAutor.h"

void menuAutores(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU AUTORES" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("AGREGAR AUTOR",50,5,y==0);
        mostrarItem("LISTAR AUTOR POR ID",50,7,y==1);
        mostrarItem("LISTAR TODOS LOS AUTORES",50,9,y==2);
        mostrarItem("MODIFICAR CANTIDAD DE OBRAS PUBLICADAS",50,11,y==3);
        mostrarItem("ELIMINAR AUTOR",50,13,y==4);
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
                        agregarAutor();
                        system("pause");
                        system("cls");
                        break;
                    case 1:
                        listarAutorPorId();
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        listarTodosLosAutores();
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        modificarObrasPublicadas();
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        eliminarAutor();
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        system("cls");
                        return;
                    default: cout<<"OPCION INCORRECTA"<<endl;
                        break;
                }
                break;
        }
    system("cls");
    }
}

#endif // MENUAUTORES_H_INCLUDED
