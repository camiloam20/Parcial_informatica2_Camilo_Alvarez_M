#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "map"
#include "vector"
#include "Plantillas.h"

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

    void Registro_U();
    bool Sesion_U();
    void Ver_Funciones();
    void Ver_ProxEstrenos();
    void Ver_AsientosDis();
    void Comprar_Boleto();
    void Guardar_SalaCine(char Asientos[10][12],string id);
    void Actualizar_Datos();
    void guardado_registro(int cedula,string clave);
};


