#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED

void mostrarItem(const char *texto, int posx, int posy, bool seleccion);
#include"declaraciones.h"
#include"menuGeneros.h"
#include"menuAutores.h"
#include"menuLibros.h"
#include"menuMiembros.h"
#include"menuPrestamo.h"
#include"menuConfiguracion.h"
#include"reportes.h"
#include"funcionesGlobales.h"

void menuPrincipal(){
    rlutil::hidecursor();
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU PRINCIPAL" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("MENU LIBROS",50,5,y==0);
        mostrarItem("MENU GENEROS",50,7,y==1);
        mostrarItem("MENU AUTORES",50,9,y==2);
        mostrarItem("MENU MIEMBROS",50,11,y==3);
        mostrarItem("MENU PRESTAMO",50,13,y==4);
        mostrarItem("CONFIGURACION",50,15,y==5);
        mostrarItem("REPORTES",50,17,y==6);
        mostrarItem("SALIR DEL PROGRAMA",50,19,y==7);
        int key = rlutil::getkey();
        switch(key){
            case 14: //SUBIR
                y --;
                if(y<0) y = 0;
                break;
            case 15: //BAJAR
                y ++;
                if(y>7) y = 7;
                break;
            case 1: //ENTER
                switch(y){
                    case 0:
                        system("cls");
                        menuLibros();
                        break;
                    case 1:
                        system("cls");
                        menuGeneros();
                        break;
                    case 2:
                        system("cls");
                        menuAutores();
                        break;
                    case 3:
                        system("cls");
                        menuMiembros();
                        break;
                    case 4:
                        system("cls");
                        menuPrestamo();
                        break;
                    case 5:
                        system("cls");
                        menuConfiguracion();
                        break;
                    case 6:
                        system("cls");
                        menuReportes();
                        break;
                    case 7:
                        system("cls");
                        return;
                }
                break;
        }

    }
}

void mostrarItem(const char *texto, int posx, int posy, bool seleccion){
    if(seleccion){
        rlutil::setBackgroundColor(rlutil::WHITE);
    }
    else {
        rlutil::setBackgroundColor(rlutil::CYAN);
    }
    rlutil::locate(posx, posy);
    cout<< texto <<endl;
    rlutil::setBackgroundColor(rlutil::CYAN);
}

#endif // MENUPRINCIPAL_H_INCLUDED
