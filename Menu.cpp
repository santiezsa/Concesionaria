#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

void Menu::mostrarPantallaPrincipal()
{

    string user;
    string password;
    string usuario[4] = {"sergio", "santiago", "lautaro", "dario"};
    string contrasenia[4] = {"1234", "4321", "4444", "1111"};
    bool primerIngreso = true;
    bool ingresoCorrecto = false;

    cout << "Bienvenidos!" << endl << endl;
    do
    {
        if (!primerIngreso)
        {
            cout << "Usuario o contrasenia incorrectos. Intente nuevamente." << endl;
            system("pause");
            system("cls");
            ingresoCorrecto = false;
            //contraseniaCorrecta = false;
        }
        cout << "Ingrese usuario: " << endl;
        cin >> user;

        cout << "Ingrese contrasenia: " << endl;
        cin >> password;

        primerIngreso = false;
        for (int i =0; i <4 ; i++)
        {
            if (user == usuario[i] && password == contrasenia[i])
            {
                ingresoCorrecto = true;
            }
        }

    }
    while(ingresoCorrecto == false);
    system("cls");
    cout << "Ingreso exitoso." << endl;
}

void Menu::mostrarMenuPrincipal()
{
    /*cout << "1 - Cargar plan nuevo" << endl;
    cout << "2 - Modificar plan existente" << endl;
    cout << "3 - Buscar plan" << endl;*/
    cout << "1 - Planes" << endl;
    /*cout << "4 - Cargar cliente nuevo" << endl;
    cout << "5 - Modificar cliente existente" << endl;
    cout << "6 - Buscar cliente" << endl;*/
    cout << "2 - Clientes" << endl;
    cout << "3 - Vendedores" << endl;
    cout << "4 - Ventas" << endl;
    cout << "5 - Configuracion" << endl;
    cout << "0 - Salir" << endl;
}
