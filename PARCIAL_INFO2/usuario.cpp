#include "usuario.h"

void usuario::Registro_U()
{
    /*Sistema de registro de usuarios en el sistema del cine.
     * Considere que tendria mas sentido que en el cine, los mismo usuarios puedan registrarse a ellos mismos, sin necesidad de que el administrador
     * lo haga (Como lo era en la practica 3).
     * El usuario ingresara su cedula que tiene que ser menor que 10 digitos, y su contraseña que puede ser lo que sea que el usuario quiera.
     * Esta informacion sera guardado en el map User_Pass que definimos en private: en las implementaciones de la clase usuario.
     */
    int cedula,opcion;
    string clave;
    //fstream guardar;//Creamos una variable fstream para poder escribir o leer los datos guardados.
    //guardar.open("registro.txt",ios::app | ios::ate | ios::out);//Con esta linea podemos abrir el archivo y escribir sobre el sin borrar lo que ya estaba escrito
    do{
        system("CLS");
        cout<<"Bienvenido al menu de registro de usuarios.\n Presione (1) para registrarse.\n Presione (2) para salir."<<endl;
        cout<<"Ingrese la opcion que quiere realizar: ";
        cin>>opcion;
        switch (opcion) {
        case 1:{
            system("CLS");
            cout<<"Sistema de registro de usuarios. El formato de registro es: cedula, clave."<<endl;
            do{cout<<"Ingrese una cedula valida:";
            cin>>cedula;}while(cedula<=10);//verificamos que la cedula sea menor o igual a 10 digitos
            cout<<"Ingrese una clave: ";
            cin>>clave;
            guardado_registro(cedula,clave);//Funcion para el guardado de mapa
            User_pass.erase(cedula);/*Despues de guardar el mapa en el archivo txt, procedo a borrarlo para que asi si creo otro mapa
            mientras el codigo se encuentre en ejecucion, no se vuelva a guardar el mismo mapa mas de una vez.*/
            cout<<"Informacion guardada."<<endl;
            system("PAUSE");
            break;
            }
        }
    }while(opcion!=2);
}

bool usuario::Sesion_U()
{
    bool encontrado=false;
    int opcion;
    string clave,cedula,cedulaC,claveC;
    do{
    fstream archivo("../Archivos/Registro_U.txt");//Archivo en el que se guardara el usuario y clave del administrador
    system("CLS");
    cout<<"Bienvenido al menu de ingreso de usuario:\n Presione (1) para ingresar.\n Presione (2) para salir.\n Que desea hacer?:";
    cin>>opcion;
    switch (opcion) {
    case 1:{
    system("CLS");
    cout<<" Por favor ingrese su cedula: "<<endl;
    cin>>cedulaC;//Usuario ingresado
    cout<<" Por favor ingrese su clave: "<<endl;
    cin>>claveC;//Clave ingresada
    archivo>>cedula;//En la variable cedula se guardara la primera palabra que haya antes de un espacio(Esta sera la cedula del usuario)
    while (!archivo.eof()){
        archivo>>clave;//En la variable clave se guardara la palabra que haya despues del usuario
        if(cedula==cedulaC){//Si el usuario correcto y el usuario ingresado son los mismos se verificara si la contraseña es la misma
            if (clave==claveC){
                encontrado=true;//Si las contraseñas son las mismas, el ingreso es correcto y se podra acceder al menu de usuario del cine
                break;
            }
        }
    archivo>>cedula;//Ahora se guarda en admin la primera palabra despues de un salto de linea
    }
    if (encontrado==true){
        cout<<"Su clave es correcta."<<endl;
        system("PAUSE");
        archivo.close();
        return 1;//Si la contraseña y usuarios son correctos se retorna un 1 que procedera a ejecutar el menu con las opciones disponibles para el usuario
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

void usuario::Ver_Funciones()
{
    /*Funcion que nos permite visualisar las funciones que ofrece el cine hoy
     * Haremos uso de la plantilla imprimir_Titulo(); que trabajar con la libreria iomanip para una mejor organizacion de los datos,
     * esta plantilla se encuentra incluida en el archivo Plantillas.h
    */
    fstream Lectura("../Archivos/Cartelera.txt");//Abrimos el archivo en el que se guardaron las peliculas del cine
    string id,nombre,genero,duracion,salayhora,asientos,clasif,Prox_A_Estreno;
    system("CLS");
    cout<<"Estas son las funciones del dia:"<<endl;

    //Con la funcion imprimir_Titulo, imprimiremos con mayor organizacion los titulos.
    imprimir_Titulo("ID:",5);
    imprimir_Titulo("Nombre:",35);
    imprimir_Titulo("Genero:",15);
    imprimir_Titulo("Duracion:",15);
    imprimir_Titulo("Sala/Hora:",15);
    imprimir_Titulo("Asientos:",15);
    imprimir_Titulo("Clasificacion:",14);
    cout<<'\n';

    Lectura>>id;//Situacion en la variable id el primer string que hay en el archivo
    while(!Lectura.eof()){//Recorremos todo el archivo

        //Almacenamos en todas las variables los datos que se encuentran separados por espacios en el archivo Cartelera.txt
        Lectura>>nombre;
        Lectura>>genero;
        Lectura>>duracion;
        Lectura>>salayhora;
        Lectura>>asientos;
        Lectura>>clasif;

        //Imprimiremos las variables anteriormente guardadas con la funcion imprimir_Titulo que nos permitira que todos los elementos queden alineados
        imprimir_Titulo(id,5);
        imprimir_Titulo(nombre,35);
        imprimir_Titulo(genero,15);
        imprimir_Titulo(duracion,15);
        imprimir_Titulo(salayhora,15);
        imprimir_Titulo(asientos,15);
        imprimir_Titulo(clasif,14);
        cout<<'\n';
        Lectura>>id;//Situamos en la variable id la siguiente variable despues de un salto de linea, asi imprimiremos en su totalidad el archivo
    }
    Lectura.close();
    system("PAUSE");
}

void usuario::Ver_ProxEstrenos()
{
    fstream Lectura("../Archivos/ProxEstrenos.txt");//Abrimos el archivo en el que se guardo la lista de los proximos estrenos
    string id,nombre,fecha;
    system("CLS");
    cout<<"Esta es la lista de los proximos estrenos en nuestros cines:"<<endl;
    //Con la plantilla imprimir_Titulo imprimimos los datos de una forma mas organizada
    imprimir_Titulo("ID:",5);
    imprimir_Titulo("Nombre:",30);
    imprimir_Titulo("Fecha de estreno:",25);
    cout<<'\n';
    Lectura>>id;//Situamos el primer string dentro del archivo en la variable id
    while(!Lectura.eof()){
        Lectura>>nombre;//Situamos los siguientes valores en las variables nombre,fecha
        Lectura>>fecha;
        //Con la plantilla imprimir_Titulo imprimimos los datos de una forma mas organizada
        imprimir_Titulo(id,5);
        imprimir_Titulo(nombre,30);
        imprimir_Titulo(fecha,25);
        cout<<'\n';

        Lectura>>id;//Situamos en id el siguiente dato despues de un salto de linea para asi recorrer todo el archivo
    }
    Lectura.close();
    system("PAUSE");
}

void usuario::Ver_AsientosDis()
{

}

void usuario::Comprar_Boleto()
{
    system("CLS");
    cout<<"Bienvenido a la interfaz de compra de su entrada, seleccione una de las peliculas en nuestra cartelera:"<<endl;
    system("PAUSE");
    Ver_Funciones();
}

void usuario::Actualizar_Datos()
{

}

void usuario::guardado_registro(int cedula,string clave){
    fstream guardar("../Archivos/Registro_U.txt",ios::app | ios::ate | ios::out);//Linea de codigo que me permite copiar en el archivo sin borrar lo que ya tengo escrito
    string GuardadoString,CedulaString;
    User_pass.insert(pair<int,string>(cedula,clave));//la funcion .insert introduce al mapa User_Pass los datos que el usuario acaba de ingresar
    map<int,string>::iterator i;//Iterador encargado de recorrer el mapa
    for(i=User_pass.begin();i!=User_pass.end();i++){//Ciclo for que recorrera el mapa por completo
        CedulaString=std::to_string(i->first);//En cada mapa, el primer valor que es la cedula sera convertido a string
        GuardadoString=CedulaString+" "+i->second+"\n";//se guarda toda la informacion en un string
    }
    guardar<<GuardadoString;//Escribo el string en el archivo
    guardar.close();
}
