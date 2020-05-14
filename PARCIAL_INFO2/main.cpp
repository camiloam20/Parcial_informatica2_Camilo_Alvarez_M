#include "administrador.h"
#include "usuario.h"

/* Parcial informatica 2- Desafio Evaluativo "Yo vine porque quise"
 * Camilo Alvarez Muñoz - CC.1000874557
 * Version 2.Realice la gestion del sistema de atencion de un cine para automatizar el proceso de compra de asientos para una pelicula
 */

int main()
{

//    /*Este es el menu del sistema de cine; mediante un switch la persona que esta ejecutando el programa podra elegir si quiere acceder como Administrador o como
//     * usuario comun del cine.*/
    Administrador admin;
    usuario User;
//    User.Comprar_Boleto();
    int opcion;
    do{
    system("CLS");
    cout<<"Sea Bienvenido al sistema de nuestro cine!!!"<<endl;
    cout<<" Ingrese (1) para ingresar como un usuario normal,\n Ingrese (2) para ingresar como administrador.\n Ingrese (3) para salir.\nOpcion: ";
    cin>>opcion;
    switch (opcion) {
    case 1:{
        int op;
        do{
            //Menu de opciones del usuario.
            system("CLS");
            cout<<"Sea bienvenido al sistema de Usuario de nuestro cine"<<endl;
            cout<<" Si desea registrarce en el sistema de nuestro cine presione (1)."<<endl;
            cout<<" Si desea iniciar sesion presione (2)."<<endl;
            cout<<" Si desea salir presione (3)."<<endl;
            cout<<"Ingrese la opcion que desea realizar:";
            cin>>op;
            switch (op) {
            case 1:{
                User.Registro_U();//La opcion 1 invoca la funcion que permitira los usuarios registrarse en el sistema de cine.
                break;
            }
            case 2:{
                if(User.Sesion_U()){//Si User.Sesion devuelve un 1, se ejecutara el menu de opciones del usuario
                    int op;
                    do{
                    system("CLS");
                    cout<<"Si desea ver las funciones disponibles presione (1)."<<endl;
                    cout<<"Si desea ver los proximos estrenos presione (2)."<<endl;
                    cout<<"Si desea comprar una entrada presione (3)."<<endl;
                    cout<<" Si desea salir presione (4)."<<endl;
                    cin>>op;
                    switch(op){
                    case 1:{
                        User.Ver_Funciones();
                        break;
                    }
                    case 2:{
                        User.Ver_ProxEstrenos();
                        break;
                    }
                    case 3:{
                        User.Comprar_Boleto();
                        break;
                    }
                    }
                    }while(op!=4);//Se ejecutara el menu mientras que el usuario no presione el numero destinado para salir
                }
                break;
            }
            }

        }while(op!=3);//Se ejecutara el menu mientras que el usuario no presione el numero destinado para salir
        break;
    }
    case 2:{
        if(admin.Sesion()){
            /*Ya que la funcion Sesion retorna un booleano, si se retorna un 1,eso equivale a un true asi que se ejecutara todo lo que esta en el if
             Si se retorna un 0, esto contara como un false, entonces se ejecutara lo que esta en el else.
            */
            int op;
            do{
                //Menu de opciones del administrador.
                system("CLS");
                cout<<"Sea bienvenido al sistema de administrador del punto de venta de nuestro cine."<<endl;
                cout<<" Si desea agregar peliculas a la cartelera o a la lista de proximos estrenos presione: (1)."<<endl;
                cout<<" Si desea ver y modificar los precios de los tipos de asientos de las sala de cine: (2)."<<endl;
                cout<<" Si desea ver las ventar realizadas en el dia presione: (3)."<<endl;
                cout<<" Si desea salir presione: (4)."<<endl;
                cout<<"Ingrese la opcion que desea realizar:";
                cin>>op;
                switch (op) {
                case 1:{
                    admin.Crear_Cartelera();//La opcion 1 invoca la funcion que creara la cartelera de cine y los proximos estrenos.
                    break;
                }
                case 2:{
                    admin.Ofertar_Asientos();
                    break;
                }
                case 3:{
                    admin.VentasxDia();
                    break;
                }
                }
            }while(op!=4);//Se ejecutara el menu mientras que el usuario no presione el numero destinado para salir
        }
        break;
    }
    }
    }while(opcion!=3);//Se ejecutara el menu mientras que el usuario no presione el numero destinado para salir
}
