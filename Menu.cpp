#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

void Menu::mostrarPantallaPrincipal()
{
    mostrarLogo();
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
    mostrarLogo();
    cout << endl << "Ingreso exitoso." << endl;
    system("pause");
    system("cls");
}

void Menu::mostrarMenuPrincipal()
{
    int opcion;
    do
    {
        mostrarLogo();
        cout << "1 - Planes" << endl;
        cout << "2 - Clientes" << endl;
        cout << "3 - Vendedores" << endl;
        cout << "4 - Ventas" << endl;
        cout << "5 - Configuracion" << endl;
        cout << "------------------------" << endl;
        cout << "0 - Salir" << endl;

        cout << "Ingrese una opcion: " << endl;
        cin >> opcion;
        /*while (opcion<0 || opcion>5)
        {
            system("cls");
            mostrarLogo();
            cout << "Opcion incorrecta. " << endl;
            system("pause");
            system("cls");
        }*/

        /*if (opcion == 1)
        {
            mostrarMenuPlanes();
        }
        else
        {
            if (opcion == 2)
            {
                mostrarMenuClientes();
            }
            else
            {
                if (opcion == 3)
                {
                    mostrarMenuVendedores();
                }
                else
                {
                    system("cls");
                    mostrarLogo();
                    cout << "Opcion incorrecta. " << endl;
                    opcion = -1;
                }
            }
        }*/


        switch (opcion)
        {
        case 1:
            mostrarMenuPlanes();

            break;

        case 2:
            mostrarMenuClientes();

            break;

        case 3:
            mostrarMenuVendedores();

            break;

        case 4:
            mostrarMenuVentas();

            break;

        case 5:
            mostrarMenuConfiguracion();

            break;

        case 0:
            system("cls");
            mostrarLogo();
            cout << "Saliendo del programa." << endl;
            exit(0);

            break;

        default:            //VALIDAR QUE SEA SOLO NUMERO - - CAMBIAR SWITCH POR IF
            system("cls");
            mostrarLogo();
            cout << "Opcion incorrecta. " << endl;
            system("pause");
            system("cls");
            cin.ignore();
            break;
        }
    }
    while (true);
}

void Menu::mostrarLogo()
{
    cout << "      _____         \t *****  *   *  *****  *****  *   *  *   *  *****" << endl;
    cout << "  ___/__|__\\_____  \t |   |  |   |    |    |   |  |   |  |*  |  |   |" << endl;
    cout << " |  _     1   _  `. \t *****  *   *    *    *   *  *   *  * * *  *   *" << endl;
    cout << " '-(_)-------(_)-^  \t |   |  |   |    |    |   |  |   |  |  *|  |   |" << endl;
    cout << "                    \t *   *  *****    *    *****  *****  *   *  *****" << endl;
    cout << endl;
}

void Menu::mostrarMenuPlanes()
{
    int opcionPlanes;
    do
    {
        system("cls");
        mostrarLogo();
        cout << "1 - Cargar plan nuevo" << endl;
        cout << "2 - Modificar plan existente" << endl;
        cout << "3 - Buscar plan" << endl;
        cout << "4 - Volver al menu anterior" << endl;

        cout << "Ingrese una opcion: " << endl;
        cin >> opcionPlanes;

        switch(opcionPlanes)
        {
        case 1:
            //

            break;

        case 2:
            //

            break;

        case 3:
            //

            break;

        case 4:
            //

            break;

        default:            //VALIDAR QUE SEA SOLO NUMERO
            system("cls");
            mostrarLogo();
            cout << "Opcion incorrecta. " << endl;
            system("pause");
            system("cls");

        }
    }
    while (opcionPlanes != 4);
}

void Menu::mostrarMenuClientes()
{
    int opcionClientes;
    system("cls");
    mostrarLogo();
    cout << "1 - Cargar cliente nuevo" << endl;
    cout << "2 - Modificar cliente existente" << endl;
    cout << "3 - Buscar cliente" << endl;
    cout << "4 - Volver al menu anterior" << endl;

    cout << "Ingrese una opcion: " << endl;
    cin >> opcionClientes;

    switch(opcionClientes)
    {
    case 1:
        //

        break;

    case 2:
        //

        break;

    case 3:
        //

        break;

    case 4:
        //

        break;

    default:                //VALIDAR QUE SEA SOLO NUMERO
        system("cls");
        mostrarLogo();
        cout << "Opcion incorrecta. " << endl;
        system("pause");
        system("cls");

    }
}

void Menu::mostrarMenuVendedores()
{
    int opcionVendedor;
    system("cls");
    mostrarLogo();
    cout << "1 - Cargar vendedor nuevo" << endl;
    cout << "2 - Modificar vendedor existente" << endl;
    cout << "3 - Buscar vendedor" << endl;
    cout << "4 - Volver al menu anterior" << endl;

    cout << "Ingrese una opcion: " << endl;
    cin >> opcionVendedor;

    switch(opcionVendedor)
    {
    case 1:
        //

        break;

    case 2:
        //

        break;

    case 3:
        //

        break;

    case 4:
        //

        break;

    default:                //VALIDAR QUE SEA SOLO NUMERO
        system("cls");
        mostrarLogo();
        cout << "Opcion incorrecta. " << endl;
        system("pause");
        system("cls");

    }
}

void Menu::mostrarMenuVentas()
{

}

void Menu::mostrarMenuConfiguracion()
{

}
