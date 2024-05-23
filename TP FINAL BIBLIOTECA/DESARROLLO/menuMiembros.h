#ifndef MENUMIEMBROS_H_INCLUDED
#define MENUMIEMBROS_H_INCLUDED

#include"clsMiembro.h"

void menuMiembros(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU MIEMBROS" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("AGREGAR MIEMBRO",50,5,y==0);
        mostrarItem("LISTAR MIEMBRO POR ID",50,7,y==1);
        mostrarItem("LISTAR TODOS LOS MIEMBROS",50,9,y==2);
        mostrarItem("MODIFICAR TELEFONO DE MIEMBRO",50,11,y==3);
        mostrarItem("ELIMINAR MIEMBRO",50,13,y==4);
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
                switch(y){
                case 0:
                    agregarMiembro();
                    system("pause");
                    system("cls");
                    break;
                case 1:
                    listarMiembroPorId();
                    system("pause");
                    system("cls");
                    break;
                case 2:
                    listarMiembros();
                    system("pause");
                    system("cls");
                    break;
                case 3:
                    modificarTelefono();
                    system("pause");
                    system("cls");
                    break;
                case 4:
                    eliminarMiembro();
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

    }
}

#endif // MENUMIEMBROS_H_INCLUDED
