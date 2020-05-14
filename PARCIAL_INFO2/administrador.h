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
    /*Decidi usar un vector que tuviera un tipo estructura adentro, ya que cada pelicula tiene muchos items de informacion, y usar un map para esto
     * seria un map muy complicado, considero que el vector<struct> tiene un facil manejo de datos y hace que todo sea mas secuencial y sencillo de
     * entender.
    */
    struct Pelicula{
        int id;
        string Nombre_peli;
        string Genero;
        string Duracion;
        string Sala_Hora;
        int asientosDis;
        int asientosT;
        string clas;
    };
    vector<Pelicula> cartelera;

    map<int,map<string,int>> Tipos_Asientos;
public:
    /* Implementacion de las funciones de la clase administrador:
     * Por ahora, estas son las funciones que creo que necesita el administrador del punto de venta del cine, estas funciones podran cambiar dependiendo de como se
     * desarrolle el programa.
    */

    bool Sesion();
    void Crear_Cartelera();
    void Ofertar_Asientos();
    void VentasxDia();
    void Guardar_Cartelera(int id,string nombre,string genero,string duracion,string salaYhora,int asientosTotal,string clasi);

};


