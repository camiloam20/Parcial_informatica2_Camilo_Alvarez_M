#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "map"
#include "vector"
#include <string>
#include <iomanip>

using namespace std;

class Administrador
{
private:
    /*Decidi usar un vector que tuviera un tipo estructura adentro, ya que cada pelicula tiene muchos items de informacion, y usar un map para esto
     * seria muy complicado y largo, considero que el vector<struct> tiene un facil manejo de datos y hace que todo sea mas secuencial y sencillo de
     * entender.
    */
    struct Pelicula{
        int id;
        string Nombre_peli;
        string Genero;
        string Duracion;
        string Sala_Hora;
        int asientosT;
        string clas;
    };
    //Vector en el que se guardara la estructura pelicula
    vector<Pelicula> cartelera;
public:
    /* Implementacion de las funciones de la clase administrador:
     * Por ahora, estas son las funciones que creo que necesita el administrador del punto de venta del cine, estas funciones podran cambiar dependiendo de como se
     * desarrolle el programa.
    */

    void imprimir_Titulo(string titulo, const int& largo);
    bool Sesion();
    void Crear_Cartelera();
    void Ofertar_Asientos();
    void VentasxDia();
    void Guardar_Cartelera(int id,string nombre,string genero,string duracion,string salaYhora,int asientosTotal,string clasi);

};


