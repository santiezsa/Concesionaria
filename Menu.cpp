#include <iostream>
#include <string>
#include "Menu.h"
#include "ConcesionariaManager.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoVendedor.h"
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
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Planes" << endl;
            cout << "2 - Clientes" << endl;
            cout << "3 - Vendedores" << endl;
            cout << "4 - Ventas" << endl;
            //cout << "5 - Configuracion" << endl;
            cout << "------------------------" << endl;
            cout << "0 - Salir" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcion;

            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }

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

        /*case 5:
            mostrarMenuConfiguracion();

            break;*/

        case 0:
            system("cls");
            mostrarLogo();
            cout << "Saliendo del programa." << endl;
            exit(0);

            break;

        default:            //VALIDAR QUE SEA SOLO NUMERO - - CAMBIAR SWITCH POR IF
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            break;
        }
    }
    while (true);
}

void Menu::mostrarLogo()
{
    cout << "                                                                     \t\t      ______________ " << endl;
    cout << "      _____         \t *****  *   *  *****  *****  *   *  *   *  ***** \t     /              \\ " << endl;
    cout << "  ___/__|__\\_____  \t |   |  |   |    |    |   |  |   |  |*  |  |   | \t    /                \\ " << endl;
    cout << " |  _     1   _  `. \t *****  *   *    *    *   *  *   *  * * *  *   * \t __|__________________|__ " << endl;
    cout << " '-(_)-------(_)-^  \t |   |  |   |    |    |   |  |   |  |  *|  |   | \t | _ |              | _ | " << endl;
    cout << "                    \t *   *  *****    *    *****  *****  *   *  ***** \t |(_)|   |AUT001|   |(_)| " << endl;
    cout << "                                                                     \t\t L___J==============L___J " << endl;
    cout << "                                                                     \t\t  !_!                !_! " << endl;

    cout << endl;



}

void Menu::mostrarMenuPlanes()
{
    int opcionPlanes;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar plan nuevo" << endl;
            cout << "2 - Modificar plan existente" << endl;
            cout << "3 - Buscar plan" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionPlanes;

            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }

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

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

        }
    }
    while (opcionPlanes != 4);
}

void Menu::mostrarMenuClientes()
{
    int opcionClientes;
    Cliente cliente;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar cliente nuevo" << endl;
            cout << "2 - Modificar cliente existente" << endl;
            cout << "3 - Buscar cliente" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionClientes;

            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }

        switch(opcionClientes)
        {
        case 1:
            cliente.cargarCliente();

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

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

        }
    }
    while (opcionClientes != 4);
}

void Menu::mostrarMenuVendedores()
{
    int opcionVendedor;
    Vendedor vendedor;
    ArchivoVendedor archivoVendedor;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar vendedor nuevo" << endl;
            cout << "2 - Modificar vendedor existente" << endl;
            cout << "3 - Mostrar vendedor" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionVendedor;

            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }

        switch(opcionVendedor)
        {
        case 1:
            vendedor.cargarVendedor();
            break;
        case 2:
            char dni[12];
            char confirmar;
            cin.ignore();

            while(true)
            {
                system("cls");
                mostrarLogo();
                cout << "Ingrese DNI del vendedor: ";
                cin.getline(dni, sizeof(dni));

                if(!(archivoVendedor.buscarVendedor(dni) >= 0))  /// si cuenta y NO encuentra el registro
                {
                    system("cls");
                    mostrarLogo();
                    cout << "Error: No existe un vendedor con ese DNI." << endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    mostrarLogo();
                    cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
                    cin >> confirmar;
                    confirmar = tolower(confirmar);
                    while(confirmar != 's' && confirmar != 'n')
                    {
                        system("cls");
                        mostrarLogo();
                        cout << "Error: Opcion incorrecta." << endl;
                        cout << "Desea confirmar? (s/n)" << endl;
                        cin >> confirmar;
                        confirmar = tolower(confirmar);
                    }
                    if (confirmar == 's')
                    {
                        cin.ignore();
                        int pos = archivoVendedor.buscarVendedor(dni); /// Busco la posicion del vendedor en base al DNI
                        Vendedor vendedor;
                        vendedor = archivoVendedor.Leer(pos);
                        vendedor.modificarVendedor(vendedor);
                        if(archivoVendedor.Guardar(vendedor, pos))
                        {
                            cout << "Vendedor modificado exitosamente." << endl;
                        }
                        else
                        {
                            cout << "No se pudo modificar el vendedor." << endl;
                        }
                        system("pause");
                        break;
                    }
                }
            }
            break;

        case 3:
            cin.ignore();
            while(true)
            {
                system("cls");
                mostrarLogo();
                cout << "Ingrese DNI del vendedor: ";
                cin.getline(dni, sizeof(dni));

                if(!(archivoVendedor.buscarVendedor(dni) >= 0))  /// si cuenta y NO encuentra el registro
                {
                    system("cls");
                    mostrarLogo();
                    cout << "Error: No existe un vendedor con ese DNI." << endl;
                    system("pause");
                }
                else
                {
                    system("cls");
                    mostrarLogo();
                    cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
                    cin >> confirmar;
                    confirmar = tolower(confirmar);
                    while(confirmar != 's' && confirmar != 'n')
                    {
                        system("cls");
                        mostrarLogo();
                        cout << "Error: Opcion incorrecta." << endl;
                        cout << "Desea confirmar? (s/n)" << endl;
                        cin >> confirmar;
                        confirmar = tolower(confirmar);
                    }
                    if (confirmar == 's')
                    {
                        cin.ignore();
                        int pos = archivoVendedor.buscarVendedor(dni); /// Busco la posicion del vendedor en base al DNI
                        Vendedor vendedor;
                        vendedor = archivoVendedor.Leer(pos);
                        vendedor.mostrarVendedor(vendedor);
                        system("pause");
                        break;
                    }
                }
            }
            break;

        case 4:
            //

            break;

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");
        }
    }
    while (opcionVendedor != 4);
}

void Menu::mostrarMenuVentas()
{

}

void Menu::mostrarMenuConfiguracion()
{

}
