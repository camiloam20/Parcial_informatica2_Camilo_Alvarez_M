#include "administrador.h"
#include "usuario.h"

/* Parcial informatica 2- Desafio Evaluativo "Yo vine porque quise"
 * Camilo Alvarez Muñoz - CC.1000874557
*/

int main()
{
    /*Este es el menu del sistema de cine; mediante un switch la persona que esta ejecutando el programa podra elegir si quiere acceder como Administrador o como
     * usuario comun del cine.
    */
    Administrador admin;
    int opcion;
    do{
    system("CLS");
    cout<<" Sea Bienvenido al sistema de nuestro cine!!!"<<endl;
    cout<<"Ingrese (1) para ingresar como un usuario normal,"<<endl<<"Ingrese (2) para ingresar como administrador."<<endl<<"Ingrese (3) para salir."<<endl<<"Opcion: ";
    cin>>opcion;
    switch (opcion) {
    case 1:{
        break;
    }
    case 2:{
        if(admin.Sesion()){
            /*Ya que la funcion Sesion retorna un booleano, si se retorna un 1,eso equivale a un true asi que se ejecutara todo lo que esta en el if
             Si se retorna un 0, esto contara como un false, entonces se ejecutara lo que esta en el else.
            */
        }
        break;
    }
    }
    }while(opcion!=3);
}

template <class Save>
Save Guardar_Datos(){
   /* Plantilla para guardar los datos de las operaciones realizadas.
    * Considero que deberia usarlo como una plantilla, para asi resivir cualquier tipo de dato o contenedor y guardarlo sin ningun problema.
    */
}
template <class Read>
void Leer_Datos(){
    /* Plantilla para leer los datos de los archivos.
     * Considero que deberia usarlo como una plantilla, para asi poder llamar la funcion cada que quiera, y que pueda almacenar los datos a mi gusto.
     */

}
template <class Money>
Money Devolver_Dinero(){
    /*Plantilla de la funcion para la devuelva de dinero despues de cada pago.
     * Para esta función se usara el problema 1 de la practica 2, se invocara esta funcion cada que se le necesite, y trabajara con cualquier tipo de dato.
    */
}
