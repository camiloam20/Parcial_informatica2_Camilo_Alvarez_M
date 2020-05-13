#include "administrador.h"


bool Administrador::Sesion()
{
    /*Esta funcion sirve para controlar el inicio de sesion del administrador del punto de venta del cine, si se verifica que la contraseña e usuario ingresados son
     * correctos, se retorna un 1 que ejecutara el menu de opciones del administrador del cine...
    */
    bool encontrado=false;
    int opcion;
    string clave,admin,adminD,claveD;
    do{
    fstream archivo("administracion.txt");//Archivo en el que se guardara el usuario y clave del administrador
    system("CLS");
    cout<<"Bienvenido al menu de ingreso del sistema de cine como administrador:\n Presione (1) para ingresar.\n Presione (2) para salir.\n Que desea hacer?:";
    cin>>opcion;
    switch (opcion) {
    case 1:{
    system("CLS");
    cout<<" Por favor ingrese el nombre usuario del administrador: "<<endl;
    cin>>adminD;//Usuario ingresado
    cout<<" Por favor ingrese la clave de administrador: "<<endl;
    cin>>claveD;//Clave ingresada
    archivo>>admin;//En la variable admin se guardara la primera palabra que haya antes de un espacio
    while (!archivo.eof()){
        archivo>>clave;//En la variable clave se guardara la palabra que haya despues del usuario
        if(admin==adminD){//Si el usuario del admin y el usuario ingresado son los mismos se verificara si la contraseña es la misma
            if (clave==claveD){
                encontrado=true;//Si las contraseñas son las mismas, el ingreso es correcto y se podra acceder al menu de admin
                break;
            }
        }
    archivo>>admin;//Ahora se guarda en admin la primera palabra despues de un salto de linea
    }
    if (encontrado==true){
        cout<<"Su clave es correcta."<<endl;
        system("PAUSE");
        archivo.close();
        return 1;//Si la contraseña y usuarios son correctos se retorna un 1 que procedera a ejecutar el menu con las opciones disponibles para el administrador
    }
    else {
        cout<<"Usuario o clave incorrecta."<<endl;
        archivo.close();
        system("PAUSE");}
    }
    }
    }while(opcion!=2);
    return 0;
}

void Administrador::Crear_Cartelera()
{
    int id,asientos;
    string nombre,genero,duracion,salaYhora,clasificacion;
    int opcion;
    do{
        system("CLS");
        cout<<"Bienvenido administrador al menu de creacion de cartelera."<<endl;
        cout<<" Presione (1) si quiere agregar peliculas a la cartelera.\n Presione (2) si desea agregar peliculas a la lista de proximos estrenos.\n Presione (3) si desea salir.\nQue desea hacer?: "<<endl;
        cout<<" Ingrese la opcion: ";
        cin>>opcion;
        switch (opcion) {
        case 1:{
            system("CLS");
            cout<<"Sistema de ingreso de peliculas a la cartelera."<<endl;
            cout<<" Recuerde que el formato es: |ID | Nombre | Genero | Duracion | Sala/Hora | Asientos | Clasificacion |\n (Por favor reemplaze los espacios por un _ )"<<endl;
            cout<<" Ingrese el ID de la pelicula:"<<endl;
            cin>>id;
            cout<<" Ingrese le nombre de la pelicula(Por favor reemplaze los espacios por un _ ): "<<endl;
            cin>>nombre;
            cout<<" Ingrese el genero de la pelicula: "<<endl;
            cin>>genero;
            cout<<" Ingrese la duracion en minutos de la pelicula (Por favor reemplaze los espacios por un _ ): "<<endl;
            cin>>duracion;
            cout<<" Ingrese la sala y hora de la pelicula (El formato es sala/hora): "<<endl;
            cin>>salaYhora;
            cout<<" Ingrese la cantidad de asientos totales de la sala: "<<endl;
            cin>>asientos;
            cout<<" Ingrese la clasificacion de la pelicula: "<<endl;
            cin>>clasificacion;
            Guardar_Cartelera(id,nombre,genero,duracion,salaYhora,asientos,clasificacion);//Invoco la funcion que guardar todos los datos en un vector
//            vector<Pelicula>::iterator i;
//            for(i=cartelera.begin();i!=cartelera.end();i++){
//                cout<<i->id<<" "<<i->Nombre_peli<<" "<<i->Genero<<" "<<i->Duracion<<" "<<i->Sala_Hora<<" "<<i->asientosDis<<"/"<<i->asientosT<<" "<<i->clas<<endl;
//            }
            cout<<"Informacion guardada."<<endl;
            system("PAUSE");
            break;
            }
        }
    }while(opcion!=3);
}
void Administrador::Ofertar_Asientos()
{

}

void Administrador::VentasxDia()
{

}

void Administrador::Guardar_Cartelera(int id,string nombre,string genero,string duracion,string salaYhora,int asientosTotal,string clasi){
   Pelicula Nueva_pelicula;
   fstream guardar("Cartelera.txt",ios::app | ios::ate | ios::out);//Linea de codigo que me permite copiar en el archivo sin borrar lo que ya tengo escrito
   string Info_Pelicula, Id_String,asientdis_String,AsientT_String;
   //Creacion de la estructura y vector
   Nueva_pelicula.id=id;//Primer valor de la estructura
   Nueva_pelicula.Nombre_peli=nombre;//Segundo valor de la estructura
   Nueva_pelicula.Genero=genero;//Tercer valor de la estructura
   Nueva_pelicula.Duracion=duracion;//Cuarto valor de la estructura
   Nueva_pelicula.Sala_Hora=salaYhora;//Quinto valor de la estructura
   Nueva_pelicula.asientosDis=asientosTotal;//Sexto valor de la estructura
   Nueva_pelicula.asientosT=asientosTotal;//Septimo valor de la estructura
   Nueva_pelicula.clas=clasi;//Octavo valor de la estructura
   cartelera.push_back(Nueva_pelicula);//Añado la estructura completa al vector
   //Ciclo que guarda todo el vector en un string
   vector<Pelicula>::iterator i;//Creo el vector
   for(i=cartelera.begin();i!=cartelera.end();i++){//Ciclo que me recorrera todo el vector
       //Convierto todos los ints a strings
       Id_String=std::to_string(i->id);
       asientdis_String=std::to_string(i->asientosDis);
       AsientT_String=std::to_string(i->asientosT);
       //Añado todos los valores del vector
       Info_Pelicula=Info_Pelicula+Id_String+" "+nombre+" "+genero+" "+duracion+" "+salaYhora+" "+asientdis_String+"/"+AsientT_String+" "+clasi+"\n";
   }
   guardar<<Info_Pelicula;//Escribo todo el string en el archivo
   cartelera.clear();//Borro todo lo que hay en el vector para evitar una sobreescritura de datos
   guardar.close();//Cierro el archivo
}


