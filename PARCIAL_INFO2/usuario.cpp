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
        cout<<"Bienvenido al menu de registro de usuarios.\n Presione (1) para registrar usuarios.\n Presione (2) para salir."<<endl;
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

void usuario::Sesion_U()
{
    fstream archivo("Registro_U.txt");
    int opcion,saldo, cedula, Ccedula,clave,Cclave;
    do{
        system("CLS");
        cout << "Si desea iniciar sesion presione (1), si desea salir presione (2): ";
        cin>>opcion;
        switch (opcion) {
        case 1:{
        bool encontrado=false;
        cout<<"///Inicio de sesion///"<<endl;
        cout << "Introduce la cedula: ";
        cin>>Ccedula;
        cout << "Introduce la clave: ";
        cin>>Cclave;
        archivo>>cedula;
        while (!archivo.eof()) {
            archivo>>clave>>saldo;
            if(cedula==Ccedula){
                if(clave==Cclave){
                encontrado=true;
                system("PAUSE");
                break;
            }
            }
           archivo>>cedula;
        }
        if (encontrado==false){
            cout<<"Usuario o contraseña incorrecta"<<endl;
            system("PAUSE");
        }
        archivo.close();
        break;
        }
    }
    }while(opcion!=2);
}

void usuario::Ver_Funciones()
{
    cout<<"Estas son las funciones del dia:"<<endl;
}

void usuario::Ver_ProxEstrenos()
{
    cout<<"Esta es la lista de los proximos estrenos en nuestros cines:"<<endl;
}

void usuario::Ver_AsientosDis()
{

}

void usuario::Comprar_Boleto()
{

}

void usuario::Actualizar_Datos()
{

}

void usuario::guardado_registro(int cedula,string clave){
    fstream guardar("Registro_U.txt",ios::app | ios::ate | ios::out);//Linea de codigo que me permite copiar en el archivo sin borrar lo que ya tengo escrito
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
