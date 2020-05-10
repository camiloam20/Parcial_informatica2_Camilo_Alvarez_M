#include <iostream>
#include <stdlib.h>

 using namespace std;

/* Parcial informatica 2- Desafio Evaluativo "Yo vine porque quise"
 * Camilo Alvarez Muñoz - CC.1000874557
*/
template <typename Save>
Save Guardar_Datos(){
   /* Plantilla para guardar los datos de las operaciones realizadas.
    * Considero que deberia usarlo como una plantilla, para asi resivir cualquier tipo de dato o contenedor y guardarlo sin ningun problema.
    */
}
template <typename Read>
Read Leer_Datos(){
    /* Plantilla para leer los datos de los archivos.
     * Considero que deberia usarlo como una plantilla, para asi poder llamar la funcion cada que quiera, y que pueda almacenar los datos a mi gusto.
     */
}
template <typename Money>
Money Devolver_Dinero(){
    /*Plantilla de la funcion para la devuelva de dinero despues de cada pago.
     * Para esta función se usara el problema 1 de la practica 2, se invocara esta funcion cada que se le necesite, y trabajara con cualquier tipo de dato.
    */
}
int main()
{
    /*Este es el menu del sistema de cine; mediante un switch la persona que esta ejecutando el programa podra elegir si quiere acceder como Administrador o como
     * usuario comun del cine.
    */
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
        break;
    }
    }
    }while(opcion!=3);
}
