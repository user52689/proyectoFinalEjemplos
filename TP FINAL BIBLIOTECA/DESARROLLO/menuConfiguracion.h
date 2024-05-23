#ifndef MENUCONFIGURACION_H_INCLUDED
#define MENUCONFIGURACION_H_INCLUDED

void menuConfiguracion(){
    int y = 0;
    while(true){
        rlutil::locate(50,3);
        rlutil::setColor(rlutil::WHITE);
        cout << "MENU CONFIGURACION" << endl;
        rlutil::setColor(rlutil::BLACK);
        mostrarItem("COPIA DE SEGURIDAD DEL ARCHIVO DE LIBROS",50,5,y==0);
        mostrarItem("COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS",50,7,y==1);
        mostrarItem("COPIA DE SEGURIDAD DEL ARCHIVO DE AUTORES",50,9,y==2);
        mostrarItem("COPIA DE SEGURIDAD DEL ARCHIVO DE  DE MIEMBROS",50,11,y==3);
        mostrarItem("COPIA DE SEGURIDAD DEL ARCHIVO DE  DE PRESTAMOS",50,13,y==4);
        mostrarItem("RESTAURAR EL ARCHIVO DE LIBROS",50,15,y==5);
        mostrarItem("RESTAURAR EL ARCHIVO DE GENEROS",50,17,y==6);
        mostrarItem("RESTAURAR EL ARCHIVO DE AUTORES",50,19,y==7);
        mostrarItem("RESTAURAR EL ARCHIVO DE MIEMBROS",50,21,y==8);
        mostrarItem("RESTAURAR EL ARCHIVO DE MIEMBROS",50,23,y==9);
        mostrarItem("ESTABLECER DATOS DE INICIO",50,25,y==10);
        mostrarItem("VOLVER AL MENU PRINCIPAL",50,27,y==11);
        int key = rlutil::getkey();
        switch(key){
            case 14: //SUBIR
                y --;
                if(y<0) y = 0;
                break;
            case 15: //BAJAR
                y ++;
                if(y>11) y = 11;
                break;
            case 1: //ENTER
            system("cls");
                switch(y){
                case 0:
                    system("copy Libros.dat Libros_backup.bak");
                    cout<<"Copia de seguridad creada"<<endl;
                    system("pause");
                    break;
                case 1:
                    system("copy Genero.dat Genero_backup.bak");
                    cout<<"Copia de seguridad creada"<<endl;
                    system("pause");
                    break;
                case 2:
                    system("copy Autores.dat Autores_backup.bak");
                    cout<<"Copia de seguridad creada"<<endl;
                    system("pause");
                    break;
                case 3:
                    system("copy Miembros.dat Miembros_backup.bak");
                    cout<<"Copia de seguridad creada"<<endl;
                    system("pause");
                    break;
                case 4:
                    system("copy Prestamos.dat Prestamos_backup.bak");
                    cout<<"Copia de seguridad creada"<<endl;
                    system("pause");
                    break;
                case 5:
                    system("copy Libros_backup.bak Libros.dat");
                    cout<<"Archivo restaurado"<<endl;
                    system("pause");
                    break;
                case 6:
                    system("copy Genero_backup.bak Genero.dat");
                    cout<<"Archivo restaurado"<<endl;
                    system("pause");
                    break;
                case 7:
                    system("copy Autores_backup.bak Autores.dat");
                    cout<<"Archivo restaurado"<<endl;
                    system("pause");
                    break;
                case 8:
                    system("copy Miembros_backup.bak Miembros.dat");
                    cout<<"Archivo restaurado"<<endl;
                    system("pause");
                    break;
                case 9:
                    system("copy Prestamos_backup.bak Prestamos.dat");
                    cout<<"Archivo restaurado"<<endl;
                    system("pause");
                    break;
                case 10:
                    system("copy Libros_inicio.dat Libros.dat");
                    system("copy Genero_inicio.dat Genero.dat");
                    system("copy Autores_inicio.dat Autores.dat");
                    system("copy Miembros_inicio.dat Miembros.dat");
                    system("copy Prestamos_inicio.dat Prestamos.dat");
                    cout<<"DATOS REINICIADOS CORRECTAMENTE!"<<endl;
                    break;
                case 11:
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

#endif // MENUCONFIGURACION_H_INCLUDED
