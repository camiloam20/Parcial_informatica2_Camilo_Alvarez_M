#include <iostream>
#include <iomanip>//Iomanip significa Input Output Manipulation
using namespace std;

template <typename Money>
void Devolver_Dinero(Money Pago,Money precio){
    /*Plantilla de la funcion para la devuelva de dinero despues de cada pago.
     * Para esta función se usara el problema 1 de la practica 2, se invocara esta funcion cada que se le necesite, y trabajara con cualquier tipo de dato.
    */
}

template<typename Variable>
void imprimir_Titulo(Variable titulo, const int& largo)
{
    /*La funcion imprimir_Titulo es una plantilla que usaremos para organizar nuestros datos al momento de imprimirlos, haciendo uso de la libreria
     * iomanip haremos que nuestros datos leidos queden totalmente alineados al momento de almacenarlos en consola.
     * -setw() es encargada de asignar un ancho en el cual se van a ingresar los datos
     * -setfill() lo que hara es que al llenar nuestros datos, los espacios que sobran los llenara con un ' ' (espacio)
     * -left hara que los espacios que se agregaran queden a la derecha de nuestro titulo, sin el manipulador left el titulo se
     * agregaria de ultimo ej.(         Titulo:), Left nos permite invertir esto.
    */
    cout<<left<<setw(largo)<<setfill(' ')<<titulo;
}
