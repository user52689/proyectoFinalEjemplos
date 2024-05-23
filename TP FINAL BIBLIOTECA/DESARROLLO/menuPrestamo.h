#ifndef MENUPRESTAMO_H_INCLUDED
#define MENUPRESTAMO_H_INCLUDED

#include "clsPrestamo.h"

void menuPrestamo(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU GENEROS" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("AGREGAR PRESTAMO",50,5,y==0);
        mostrarItem("LISTAR PRESTAMO POR ID",50,7,y==1);
        mostrarItem("LISTAR TODOS LOS PRESTAMOS",50,9,y==2);
        mostrarItem("ELIMINAR PRESTAMO",50,11,y==3);
        mostrarItem("VOLVER AL MENU PRINCIPAL",50,13,y==4);
        int key = rlutil::getkey();
        switch(key){
            case 14: //SUBIR
                y --;
                if(y<0) y = 0;
                break;
            case 15: //BAJAR
                y ++;
                if(y>4) y = 4;
                break;
            case 1: //ENTER
                switch(y){
                case 0:
                    agregarPrestamo();
                    system("pause");
                    system("cls");
                    break;
                case 1:
                    listarPrestamoPorId();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    listarPrestamos();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    eliminarPrestamo();
                    system("pause");
                    system("cls");
                    break;
                case 4:
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


#endif // MENUPRESTAMO_H_INCLUDED
