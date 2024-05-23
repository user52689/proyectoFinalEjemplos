#ifndef MENUGENEROS_H_INCLUDED
#define MENUGENEROS_H_INCLUDED

#include "clsGenero.h"

void menuGeneros(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU GENEROS" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("AGREGAR GENERO",50,5,y==0);
        mostrarItem("LISTAR GENERO POR ID",50,7,y==1);
        mostrarItem("LISTAR TODOS LOS GENEROS",50,9,y==2);
        mostrarItem("MODIFICAR ANIO DE CREACION DEL GENERO",50,11,y==3);
        mostrarItem("ELIMINAR GENERO",50,13,y==4);
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
                    agregarGenero();
                    system("pause");
                    system("cls");
                    break;
                case 1:
                    listarGeneroPorId();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    listarGeneros();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    modificarAnio();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    eliminarGenero();
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
        system("pause");
        system("cls");
        }
    }
}

#endif // MENUGENEROS_H_INCLUDED
