#include "administrador.h"


void Administrador::imprimir_Titulo(string titulo, const int &largo)
{
        /*Tuve que volver a crear la plantilla aqui como funcion de la clase debido a que no podia incluir en las dos clases la libreria plantillas.h
         *ya que esto generaba que las plantillas que habian adentro de el .h se redefiniera.
         *
         * La funcion imprimir_Titulo es una funcion que usaremos para organizar nuestros datos al momento de imprimirlos, haciendo uso de la libreria
         * iomanip haremos que nuestros datos leidos queden totalmente alineados al momento de almacenarlos en consola.
         * -setw() es encargada de asignar un ancho en el cual se van a ingresar los datos
         * -setfill() lo que hara es que al llenar nuestros datos, los espacios que sobran los llenara con un ' ' (espacio)
         * -left hara que los espacios que se agregaran queden a la derecha de nuestro titulo, sin el manipulador left el titulo se
         * agregaria de ultimo ej.(         Titulo:), Left nos permite invertir esto.
        */
        cout<<left<<setw(largo)<<setfill(' ')<<titulo;

}

bool Administrador::Sesion()
{
    /*Esta funcion sirve para controlar el inicio de sesion del administrador del punto de venta del cine, si se verifica que la contraseña e usuario ingresados son
     * correctos, se retorna un 1 que ejecutara el menu de opciones del administrador del cine...
    */
    bool encontrado=false;
    int opcion;
    string clave,admin,adminD,claveD;
    do{
    fstream archivo("../Archivos/administracion.txt");//Archivo en el que se guardara el usuario y clave del administrador
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
    /*Menu para añadir peliculas a la cartelera o la lista de proximos estrenos del cine*/
    int id,asientos=120;
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
            cout<<" Ingrese le nombre de la pelicula:(Por favor reemplaze los espacios por un _ )"<<endl;
            cin>>nombre;
            cout<<" Ingrese el genero de la pelicula: "<<endl;
            cin>>genero;
            cout<<" Ingrese la duracion en minutos de la pelicula (Por favor reemplaze los espacios por un _ ): "<<endl;
            cin>>duracion;
            cout<<" Ingrese la sala y hora de la pelicula (El formato es sala/hora): "<<endl;
            cin>>salaYhora;
            cout<<"Nuestro cine solo ofrece salas con 120 asientos(10 Filas,12 Columnas)"<<endl<<endl;
            cout<<" Ingrese la clasificacion de la pelicula: "<<endl;
            cin>>clasificacion;

            /*Despues de recibir todos los datos invoco la funcion Guardar_Cartelera a la cual le paso todos los datos que son guardados en una struct
            y posteriormente son guardados en un vector para ser escritos en la base de datos .txt*/
            Guardar_Cartelera(id,nombre,genero,duracion,salaYhora,asientos,clasificacion);
            cout<<"Informacion guardada."<<endl;
            system("PAUSE");
            break;
            }
        case 2:{
            int dia,mes,year;
            /**/
            fstream archivo("../Archivos/ProxEstrenos.txt",ios::app | ios::ate | ios::out);
            string idS,diaS,mesS,yearS;
            system("CLS");
            cout<<"Sistema de ingreso de peliculas a la lista de proximos estrenos"<<endl;
            cout<<" Recuerde que el formato es: |ID | Nombre | Fecha de estreno |\n (Por favor reemplaze los espacios por un _ )"<<endl;
            cout<<" Ingrese el ID de la pelicula:"<<endl;
            cin>>id;
            idS=std::to_string(id);
            cout<<" Ingrese le nombre de la pelicula: "<<endl;
            cin.ignore();
            getline(cin,nombre);
            do{
            cout<<"Ingrese dia de estreno valido:"<<endl;
            cin>>dia;
            }while(dia<1 and dia>31);//Verifico que el dia ingresado si corresponda a un dia valido(1 a 31)
            diaS=std::to_string(dia);//Convierto los ints a string
            do{
            cout<<"Ingrese mes de estreno valido:"<<endl;
            cin>>mes;
            }while(mes<1 and mes>12);//Verifico si el mes es valido
            mesS=std::to_string(mes);//Convierto los ints a string
            do{
            cout<<"Ingrese un (year) de estreno valido:"<<endl;
            cin>>year;
            }while(year<2020);//verifico si el año es valido
            yearS=std::to_string(year);//Convierto los ints a string

            archivo<<idS+" *"+nombre+"* "+diaS+"/"+mesS+"/"+yearS+'\n';//Guardo los string en el archivo.txt
            cout<<"Informacion Guardada"<<endl;
            archivo.close();
            break;
        }
        }
    }while(opcion!=3);
}
void Administrador::Ofertar_Asientos()
{
    string Sala_2DS,Sala_3DS,Sala_3DVS,PremiumS;
    int Sala_2D,Sala_3D,Sala_3DV,Premium;
   fstream Guardar("../Archivos/TiposASientos.txt",ios::ate | ios::out);//Esto me permite sobreescribir el archivo y borrar los datos antiguos
    system("CLS");
    cout<<"El cine ofrece 4 tipos diferentes de salas con sus asientos especiales."<<endl;
    cout<<" 1.Sala General 2D.\n 2.Sala General 3D.\n 3.Sala VibroSound 4D.\n 4.Sala Premium(Sala VibroSound 4D con servicios de lujo,,comida a domicilio, sofas comodos y licor)."<<endl;
    cout<<"Por favor ingrese los precios que desea que tengan estas salas: "<<endl;
    cout<<"Precio de la Sala General 2D: ";
    cin>>Sala_2D;
    Sala_2DS=std::to_string(Sala_2D);//Convierto los valores enteros a string
    cout<<"Precio de la Sala General 3D: ";
    cin>>Sala_3D;
    Sala_3DS=std::to_string(Sala_3D);//Convierto los valores enteros a string
    cout<<"Precio de la Sala Vibrasound 4D: ";
    cin>>Sala_3DV;
    Sala_3DVS=std::to_string(Sala_3DV);//Convierto los valores enteros a string
    cout<<"Precio de la Sala Premium: ";
    cin>>Premium;
    PremiumS=std::to_string(Premium);//Convierto los valores enteros a string
    //Escribo en el archivo los datos modificados;
    Guardar<<"1 Sala_General_2D "+Sala_2DS+"\n";
    Guardar<<"2 Sala_General_3D "+Sala_3DS+"\n";
    Guardar<<"3 Sala_VibroSound_3D "+Sala_3DVS+"\n";
    Guardar<<"4 Sala_Premium "+PremiumS+"\n";
    Guardar.close();
    cout<<"Informacion guardada"<<endl;
    system("PAUSE");
}

void Administrador::VentasxDia()
{

}

void Administrador::Guardar_Cartelera(int id,string nombre,string genero,string duracion,string salaYhora,int asientosTotal,string clasi){
   Pelicula Nueva_pelicula;
   fstream guardar("../Archivos/Cartelera.txt",ios::app | ios::ate | ios::out);//Linea de codigo que me permite copiar en el archivo sin borrar lo que ya tengo escrito
   string Info_Pelicula, Id_String,AsientT_String;

   //Creacion de la estructura y vector
   Nueva_pelicula.id=id;//Primer valor de la estructura
   Nueva_pelicula.Nombre_peli=nombre;//Segundo valor de la estructura
   Nueva_pelicula.Genero=genero;//Tercer valor de la estructura
   Nueva_pelicula.Duracion=duracion;//Cuarto valor de la estructura
   Nueva_pelicula.Sala_Hora=salaYhora;//Quinto valor de la estructura
   Nueva_pelicula.asientosT=asientosTotal;//Septimo valor de la estructura
   Nueva_pelicula.clas=clasi;//Octavo valor de la estructura
   cartelera.push_back(Nueva_pelicula);//Añado la estructura completa al vector
   //Ciclo que guarda todo el vector en un string
   vector<Pelicula>::iterator i;//Creo el vector
   for(i=cartelera.begin();i!=cartelera.end();i++){//Ciclo que me recorrera todo el vector
       //Convierto todos los ints a strings
       Id_String=std::to_string(i->id);

       AsientT_String=std::to_string(i->asientosT);
       //Añado todos los valores del vector
       Info_Pelicula=Id_String+" "+Nueva_pelicula.Nombre_peli+" "+Nueva_pelicula.Genero+" "+Nueva_pelicula.Duracion+" "+Nueva_pelicula.Sala_Hora+" "+AsientT_String+" "+Nueva_pelicula.clas+"\n";
       }
   guardar<<Info_Pelicula;//Escribo todo el string en el archivo
   cartelera.clear();//Borro todo lo que hay en el vector para evitar una sobreescritura de datos
   guardar.close();//Cierro el archivo
}


