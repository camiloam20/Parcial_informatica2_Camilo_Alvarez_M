#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>
#include "map"
#include "vector"
#include <string>

using namespace std;

class Administrador
{
private:

public:
    /* Implementacion de las funciones de la clase administrador:
     * Por ahora, estas son las funciones que creo que necesita el administrador del punto de venta del cine, estas funciones podran cambiar dependiendo de como se
     * desarrolle el programa.
    */
    Administrador();
    bool Sesion();
    void Crear_Cartelera();
    void Visualizar_Cartelera();
    void Ofertar_Asientos();
    void VentasxDia();

};


