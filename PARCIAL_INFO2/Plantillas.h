#include <iostream>
#include <iomanip>//Iomanip significa Input Output Manipulation
using namespace std;

template <typename Money>
void Devolver_Dinero(Money Pago,Money precio){
    /*Plantilla de la funcion para la devuelva de dinero despues de cada pago.
     * Para esta función se usara el problema 1 de la practica 2, se invocara esta funcion cada que se le necesite, y trabajara con cualquier tipo de dato.
    */
    int Devuelta;
    int Billetes_Monedas[11]={100000,50000,20000,10000,5000,2000,1000,500,200,100,50};
    int Contador[11]={0,0,0,0,0,0,0,0,0,0,0};
    Devuelta=Pago-precio;
    for (int i=0;i<11;i++){
        for (int j=0;Devuelta>=Billetes_Monedas[i];j++){
           Devuelta-=Billetes_Monedas[i];
           Contador[i]+=1;
        }
    }
    cout<<"Billetes de $100.000:"<<Contador[0]<<endl;
    cout<<"Billetes de $50.000:"<<Contador[1]<<endl;
    cout<<"Billetes de $20.000:"<<Contador[2]<<endl;
    cout<<"Billetes de $10.000:"<<Contador[3]<<endl;
    cout<<"Billetes de $5.000:"<<Contador[4]<<endl;
    cout<<"Billetes de $2.000:"<<Contador[5]<<endl;
    cout<<"Billetes de $1.000:"<<Contador[6]<<endl;
    cout<<"Monedas de $500:"<<Contador[7]<<endl;
    cout<<"Monedas de $200:"<<Contador[8]<<endl;
    cout<<"Monedas de $100:"<<Contador[9]<<endl;
    cout<<"Monedas de $50:"<<Contador[10]<<endl;
    cout<<"Sobraron en total:"<<Devuelta<<endl;
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
