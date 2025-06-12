#include <iostream>
#include <string>
#include "Menu.h"
#include "ConcesionariaManager.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
using namespace std;

/// TODO: Pendiente agregar validaciones en inputs de modificarVendedor y modificarCliente

ConcesionariaManager concesionariaManager;


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
            cout << "1 - Ventas" << endl;
            cout << "2 - Clientes" << endl;
            cout << "3 - Vendedores" << endl;
            cout << "4 - Autos" << endl;
            cout << "5 - Listados" << endl;
            cout << "6 - Consultas" << endl;
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
            mostrarMenuVentas();

            break;

        case 2:
            mostrarMenuClientes();

            break;

        case 3:
            mostrarMenuVendedores();

            break;

        case 4:
            mostrarMenuAutos();

            break;

        case 5:
            mostrarMenuListados();

            break;

        case 6:
            mostrarMenuConsultas();

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

void Menu::mostrarMenuVentas()
{
    int opcionVentas;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar venta nueva" << endl;
            cout << "2 - Modificar venta existente" << endl;
            cout << "3 - Buscar venta" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionVentas;

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

        switch(opcionVentas)
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
    while (opcionVentas != 4);
}

void Menu::mostrarMenuClientes()
{
    int opcionClientes;
    Cliente cliente;
    ArchivoCliente archivoCliente;

    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor valido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar cliente nuevo" << endl;
            cout << "2 - Modificar cliente existente" << endl;
            cout << "3 - Buscar cliente" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionClientes;

            if (cin.fail()) // Si la entrada es invalida
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
                break; // Si la entrada es valida, salir del bucle
            }
        }

        switch(opcionClientes)
        {
        case 1:
            cliente.cargarCliente();

            break;
        case 2:
            concesionariaManager.modificarCliente();

            break;
        case 3:
            subMenuBuscarCliente();

            break;

        case 4:

            break;

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

            break;

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
            concesionariaManager.modificarVendedor();

            break;

        case 3:
            subMenuBuscarVendedor();

            break;

        case 4:

            break;

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

            break;
        }
    }
    while (opcionVendedor != 4);
}

void Menu::subMenuBuscarVendedor()
{
    int opcionBuscarVendedor;
    Vendedor vendedor;
    ArchivoVendedor archivoVendedor;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Buscar vendedor por ID" << endl;
            cout << "2 - Buscar vendedor por DNI" << endl;
            cout << "3 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionBuscarVendedor;

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

        switch(opcionBuscarVendedor)
        {
        case 1:
            concesionariaManager.buscarVendedorPorID();

            break;

        case 2:
            concesionariaManager.buscarVendedorPorDNI();

            break;

        case 3:

            break;

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

            break;
        }
    }
    while (opcionBuscarVendedor != 3);

}

void Menu::subMenuBuscarCliente()
{
    Cliente cliente;
    ArchivoCliente archivoCliente;
    int opcionBuscarCliente;
            do
            {
                while (true) // Bucle infinito hasta que se ingrese un valor válido
                {
                    system("cls");
                    mostrarLogo();
                    cout << "1 - Buscar cliente por ID" << endl;
                    cout << "2 - Buscar cliente por DNI" << endl;
                    cout << "3 - Volver al menu anterior" << endl;

                    cout << "Ingrese una opcion: " << endl;
                    cin >> opcionBuscarCliente;

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

                switch(opcionBuscarCliente)
                {
                case 1:
                    concesionariaManager.buscarClientePorID();

                    break;

                case 2:
                    concesionariaManager.buscarClientePorDNI();

                    break;

                case 3:

                    break;

                default:
                    system("cls");
                    mostrarLogo();
                    cout << "Entrada invalida. Intente nuevamente." << endl;
                    system("pause");
                    system("cls");

                    break;
                }
            }
            while (opcionBuscarCliente != 3);
}

void Menu::mostrarMenuAutos()
{

}

void Menu::mostrarMenuListados()
{

}

void Menu::mostrarMenuConsultas()
{

}
