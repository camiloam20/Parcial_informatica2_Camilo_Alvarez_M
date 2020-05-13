#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "map"
#include "vector"
#include <string>
using namespace std;
class usuario
{
private:
    /*La informacion del registro de los usuarios se hara en un map, usea un map debido a que su uso me parece mas facil, disponemos de diferentes funciones
     * que nos permiten una mejor organizacion de los datos, y con la clave que sera la cedula, podremos buscar facilmente al usuario.
    */
    map<int,string>User_pass;
public:
    /* Implementacion de las funciones de la clase usuario:
     * Por ahora, estas son las funciones que creo que necesita el usuario que quiere hacer uso del cine, estas funciones podran cambiar dependiendo de como se
     * desarrolle el programa.
    */
    usuario();
    void Registro_U();
    void Sesion_U();
    void Ver_Funciones();
    void Ver_ProxEstrenos();
    void Ver_AsientosDis();
    void Comprar_Boleto();
    void Actualizar_Datos();
};


