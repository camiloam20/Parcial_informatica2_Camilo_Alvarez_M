#include "usuario.h"

usuario::usuario()
{

}

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
    fstream guardar;//Creamos una variable fstream para poder escribir o leer los datos guardados.
    guardar.open("registro.txt",ios::app | ios::ate | ios::out);//Con esta linea podemos abrir el archivo y escribir sobre el sin borrar lo que ya estaba escrito
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
            User_pass.insert(pair<int,string>(cedula,clave));//la funcion .insert introduce al mapa User_Pass los datos que el usuario acaba de ingresar
            map<int,string>::iterator r;//mapa iterador
            for(r=User_pass.begin();r!=User_pass.end();r++){//for que itera sobre el mapa
                cout<<r->first<<" "<<r->second<<endl;//Imprime lo guardado en el mapa para verificar
            }
            cout<<"Informacion guardada."<<endl;
            system("PAUSE");
            break;
            }
        }
    }while(opcion!=2);
}

void usuario::Sesion_U()
{

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
