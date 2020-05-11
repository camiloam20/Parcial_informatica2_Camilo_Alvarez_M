#include "administrador.h"

Administrador::Administrador()
{

}

bool Administrador::Sesion()
{
    /*Esta funcion sirve para controlar el inicio de sesion del administrador del punto de venta del cine, si se verifica que la contraseña e usuario ingresados son
     * correctos, se retorna un 1 que ejecutara el menu de opciones del administrador del cine...
    */
    fstream archivo("admin.txt");//Archivo en el que se guardara el usuario y clave del administrador
    bool encontrado=false;
    int opcion;
    string clave,admin,adminD,claveD;
    do{
    system("CLS");
    cout<<"Bienvenido al menu de ingreso del sistema de cine como administrador:\n Presione (1) para ingresar.\n Presione (2) para salir.\n Que desea hacer?:";
    cin>>opcion;
    switch (opcion) {
    case 1:{
    cout<<"Por favor ingrese el nombre usuario del administrador: "<<endl;
    cin>>adminD;//Usuario ingresado
    cout<<"Por favor ingrese la clave de administrador: "<<endl;
    cin>>claveD;//Clave ingresada
    archivo>>admin;//En la variable admin se guardara la primera palabra que haya antes de un espacio
    while (!archivo.eof()){
        archivo>>clave;//En la variable clave se guardara la palabra que haya despues del usuario
        if(admin==adminD){//Si el usuario del admin y el usuario ingresado son los mismos se verificara si la contraseña es la misma
            if (clave==claveD){
                encontrado=true;//Si las contraseñas son las mismas, el ingreso es correcto y se podra acceder al menu de admin
                break;
            }
        }
    archivo>>admin;//Ahora se guarda en admin la primera palabra despues de un salto de linea
    }
    if (encontrado==true){
        cout<<"Su contraseña es correcta, sea bienvenido al sistema de administrador."<<endl;
        system("PAUSE");
        archivo.close();
        return 1;//Si la contraseña y usuarios son correctos se retorna un 1 que procedera a ejecutar el menu con las opciones disponibles para el administrador
    }
    else {
        cout<<"Usuario o contraseña incorrecta."<<endl;
        system("PAUSE");}
    }
    }
    }while(opcion!=2);
    return 0;
}

void Administrador::Crear_Cartelera()
{

}

void Administrador::Visualizar_Cartelera()
{

}

void Administrador::Ofertar_Asientos()
{

}

void Administrador::VentasxDia()
{

}
