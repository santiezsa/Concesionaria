#include <iostream>
#include <string>
#include "Venta.h"
#include "Menu.h"
#include "ConcesionariaManager.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "AutoNuevo.h"
#include "ArchivoAutoNuevo.h"
#include "ArchivoAutoUsado.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "rlutil.h"
#include <iomanip>
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
        while (true) // Bucle infinito hasta que se ingrese un valor valido
        {
            system("cls");
            //mostrarLogoAnimado();
            mostrarLogo();

            // Configurar colores
            rlutil::setColor(rlutil::LIGHTBLUE);

            // Dibujar borde superior
            rlutil::locate(10, 10);
            cout << "+--------------------------------------------------------------------------------+" << endl;

            // Título del menu
            rlutil::locate(10, 11);
            cout << "|";
            rlutil::locate(45, 11);
            cout << "MENU PRINCIPAL";
            rlutil::locate(91, 11);
            cout << "|" << endl;

            rlutil::locate(10, 12);
            cout << "+--------------------------------------------------------------------------------+" << endl;

            // Opciones del menu
            rlutil::locate(10, 13);
            cout << "|";
            rlutil::locate(45, 13);
            cout << "1 - Ventas";
            rlutil::locate(91, 13);
            cout << "|" << endl;

            rlutil::locate(10, 14);
            cout << "|";
            rlutil::locate(45, 14);
            cout << "2 - Clientes";
            rlutil::locate(91, 14);
            cout << "|" << endl;

            rlutil::locate(10, 15);
            cout << "|";
            rlutil::locate(45, 15);
            cout << "3 - Vendedores";
            rlutil::locate(91, 15);
            cout << "|" << endl;

            rlutil::locate(10, 16);
            cout << "|";
            rlutil::locate(45, 16);
            cout << "4 - Autos";
            rlutil::locate(91, 16);
            cout << "|" << endl;

            rlutil::locate(10, 17);
            cout << "|";
            rlutil::locate(45, 17);
            cout << "5 - Listados";
            rlutil::locate(91, 17);
            cout << "|" << endl;

            rlutil::locate(10, 18);
            cout << "|";
            rlutil::locate(45, 18);
            cout << "6 - Consultas";
            rlutil::locate(91, 18);
            cout << "|" << endl;

            // Linea separadora
            rlutil::locate(10, 19);
            cout << "+--------------------------------------------------------------------------------+" << endl;

            // Opcion de salir
            rlutil::locate(10, 20);
            cout << "|";
            rlutil::locate(45, 20);
            cout << "0 - Salir";
            rlutil::locate(91, 20);
            cout << "|" << endl;

            // Borde inferior
            rlutil::locate(10, 21);
            cout << "+--------------------------------------------------------------------------------+" << endl;

            // Cambiar color para la entrada
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(45, 23);
            cout << "Ingrese una opcion: ";
            cin >> opcion;

            if (cin.fail()) // Si la entrada es invalida
            {
                system("cls");
                mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                rlutil::setColor(rlutil::LIGHTRED);
                rlutil::locate(35, 25);
                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::WHITE);
                system("pause");
            }
            else
            {
                break; // Si la entrada es valida, salir del bucle
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
            mostrarLogoSalida();
            //mostrarLogo();
            exit(0);
            break;
        default:
            system("cls");
            mostrarLogo();
            rlutil::setColor(rlutil::LIGHTRED);
            rlutil::locate(35, 25);
            cout << "Error: Opcion invalida. Intente nuevamente." << endl;
            rlutil::setColor(rlutil::WHITE);
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

void Menu::mostrarLogoAnimado()
{
    system("cls");
    rlutil::hidecursor();


    // Posición inicial del auto
    int x = 5;
    int y = 3;

    // Animación del auto moviéndose
    for(int i = 0; i < 60; i++)
    {
        rlutil::locate(x + i, y);
        cout << "     _____       ";
        rlutil::locate(x + i, y + 1);
        cout << " ___/__|__\\_____";
        rlutil::locate(x + i, y + 2);
        cout << "|  _     1   _  `.";
        rlutil::locate(x + i, y + 3);
        cout << "'-(_)-------(_)-^";

        // Pequeña pausa para la animación
        rlutil::msleep(50);

        // Borrar el auto en la posición actual
        rlutil::locate(x + i, y);
        cout << "                ";
        rlutil::locate(x + i, y + 1);
        cout << "                ";
        rlutil::locate(x + i, y + 2);
        cout << "                ";
        rlutil::locate(x + i, y + 3);
        cout << "                ";
    }

    // Limpiar la pantalla antes de mostrar el logo final
    system("cls");

    // Pequeña pausa antes de mostrar el logo
    rlutil::msleep(200);

    // Mostrar el logo completo
    cout << endl;
    cout << "                                                                     \t\t      ______________ " << endl;
    cout << "      _____         \t *****  *   *  *****  *****  *   *  *   *  ***** \t     /              \\ " << endl;
    cout << "  ___/__|__\\_____  \t |   |  |   |    |    |   |  |   |  |*  |  |   | \t    /                \\ " << endl;
    cout << " |  _     1   _  `. \t *****  *   *    *    *   *  *   *  * * *  *   * \t __|__________________|__ " << endl;
    cout << " '-(_)-------(_)-^  \t |   |  |   |    |    |   |  |   |  |  *|  |   | \t | _ |              | _ | " << endl;
    cout << "                    \t *   *  *****    *    *****  *****  *   *  ***** \t |(_)|   |AUT001|   |(_)| " << endl;
    cout << "                                                                     \t\t L___J==============L___J " << endl;
    cout << "                                                                     \t\t  !_!                !_! " << endl;
    cout << endl;
    rlutil::showcursor();
}

void Menu::mostrarLogoSalida()
{
    system("cls");
    rlutil::hidecursor();


    // Posición inicial del auto
    int x = 40;
    int y = 3;

    // Animación del auto moviéndose
    for(int i = 0; i < 10; i++)
    {
        rlutil::locate(x, y + i);
        cout << "      ______________      " << endl;
        rlutil::locate(x, y + 1 + i);
        cout << "     /              \\    " << endl;
        rlutil::locate(x, y + 2 + i);
        cout << "    /                \\   " << endl;
        rlutil::locate(x, y + 3 + i);
        cout << " __|__________________|__ " << endl;
        rlutil::locate(x, y + 4 + i);
        cout << " | _ |              | _ | " << endl;
        rlutil::locate(x, y + 5 + i);
        cout << " |(_)|   |AUT001|   |(_)| " << endl;
        rlutil::locate(x, y + 6 + i);
        cout << " L___J==============L___J " << endl;
        rlutil::locate(x, y + 7 + i);
        cout << "  !_!                !_!  " << endl;


        // Pequeña pausa para la animación
        rlutil::msleep(50);

        // Borrar el auto en la posición actual
        rlutil::locate(x, y + i);
        cout << "                              ";
        rlutil::locate(x, y + i);
        cout << "                              ";
        rlutil::locate(x, y + i);
        cout << "                              ";
        rlutil::locate(x, y + i);
        cout << "                              ";
    }

    // Limpiar la pantalla antes de mostrar el logo final
    system("cls");

    // Pequeña pausa antes de mostrar el logo
    rlutil::msleep(50);

    // Mostrar el logo completo
    cout << endl;
    cout << "                                                                     \t\t      ______________ " << endl;
    cout << "      _____         \t *****  *   *  *****  *****  *   *  *   *  ***** \t     /              \\ " << endl;
    cout << "  ___/__|__\\_____  \t |   |  |   |    |    |   |  |   |  |*  |  |   | \t    /                \\ " << endl;
    cout << " |  _     1   _  `. \t *****  *   *    *    *   *  *   *  * * *  *   * \t __|__________________|__ " << endl;
    cout << " '-(_)-------(_)-^  \t |   |  |   |    |    |   |  |   |  |  *|  |   | \t | _ |              | _ | " << endl;
    cout << "                    \t *   *  *****    *    *****  *****  *   *  ***** \t |(_)|   |AUT001|   |(_)| " << endl;
    cout << "                                                                     \t\t L___J==============L___J " << endl;
    cout << "                                                                     \t\t  !_!                !_! " << endl;
    cout << endl;

    rlutil::locate(40, 12);
    cout << "      ______________      " << endl;
    rlutil::locate(40, 13);
    cout << "     /              \\    " << endl;
    rlutil::locate(40, 14);
    cout << "    /                \\   " << endl;
    rlutil::locate(40, 15);
    cout << " __|__________________|__ " << endl;
    rlutil::locate(40, 16);
    cout << " | _ |              | _ | " << endl;
    rlutil::locate(40, 17);
    cout << " |(_)|   |AUT001|   |(_)| " << endl;
    rlutil::locate(40, 18);
    cout << " L___J==============L___J " << endl;
    rlutil::locate(40, 19);
    cout << "  !_!                !_!  " << endl;

    for(int j = 0; j < 8; j++)
    {
        if(j%2==0)
        {
            rlutil::msleep(200);
            rlutil::setColor(rlutil::YELLOW);
            rlutil::locate(42, 17);
            cout << "(0)" << endl;
            rlutil::locate(61, 17);
            cout << "(0)" << endl;
        }
        else
        {
            rlutil::msleep(200);
            rlutil::setColor(rlutil::WHITE);
            rlutil::locate(40, 17);
            cout << " |(_)|   |AUT001|   |(_)| " << endl;
        }
    }
    rlutil::showcursor();

    rlutil::setColor(rlutil::LIGHTGREEN);
    rlutil::locate(40, 22);
    cout << "Gracias por usar el sistema!" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void Menu::mostrarMenuVentas()
{
    Venta ventas;
    ConcesionariaManager concesionariaManager;
    int opcionVentas;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar venta auto nuevo (0 Kilometro)" << endl;
            cout << "2 - Cargar venta auto usado" << endl;
            cout << "3 - Modificar venta auto nuevo existente " << endl;
            cout << "4 - Modificar venta auto usado existente " << endl;
            cout << "5 - Buscar venta de auto nuevo" << endl;
            cout << "6 - Buscar venta de auto usado" << endl;
            cout << "7 - Volver al menu anterior" << endl;

            cout << "\nIngrese una opcion: ";
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
            ventas.cargarVentaAutoNuevo();
            break;
        case 2:
            ventas.cargarVentaAutoUsado();
            break;
        case 3:
            concesionariaManager.modificarVentaAutoNuevo();
            break;
        case 4:
            concesionariaManager.modificarVentaAutoUsado();
            break;
        case 5:
            ///concesionariaManager.buscarVentaAutoNuevo();
            break;
        case 6:
            ///concesionariaManager.buscarVentaAutoUsado();
            break;
        case 7:
            ///Break solo para terminar el ciclo

            break;

        default:
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");

        }
    }
    while (opcionVentas != 7);
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
            ///Break solo para terminar el ciclo

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
            ///Break solo para terminar ciclo

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
    int opcionTipoAuto;

    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Auto nuevo" << endl;
            cout << "2 - Auto usado" << endl;
            cout << "3 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionTipoAuto;

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

        switch(opcionTipoAuto)
        {
        case 1:
            menuAutosNuevos();
            break;
        case 2:
            menuAutosUsados();
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
    while(opcionTipoAuto != 3);

}

void Menu::menuAutosNuevos()
{
    int opcionAutoNuevo;
    AutoNuevo autoNuevo;
    ConcesionariaManager concesionariaManager;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar auto 0km" << endl; // Queda bien 0km? o dejamos auto nuevo siempre?
            cout << "2 - Modificar auto 0km existente" << endl;
            cout << "3 - Mostrar auto 0km" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionAutoNuevo;

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

        switch(opcionAutoNuevo)
        {
        case 1:
            autoNuevo.cargarAutoNuevo();
            break;
        case 2:
            concesionariaManager.modificarAutoNuevo();
            break;
        case 3:
            subMenuBuscarAutoNuevo();
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
    while (opcionAutoNuevo != 4);
}

void Menu::menuAutosUsados()
{
    int opcionAutoUsado;
    AutoUsado autoUsado;
    ConcesionariaManager concesionariaManager;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Cargar auto usado" << endl;
            cout << "2 - Modificar auto usado existente" << endl;
            cout << "3 - Mostrar auto usado" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionAutoUsado;

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

        switch(opcionAutoUsado)
        {
        case 1:
            autoUsado.cargarAutoUsado();
            break;
        case 2:
            concesionariaManager.modificarAutoUsado();
            break;
        case 3:
            subMenuBuscarAutoUsado();
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
    while (opcionAutoUsado != 4);

}

void Menu::subMenuBuscarAutoNuevo()
{
    int opcionBuscarAutoNuevo;
    AutoNuevo autoNuevo;
    ArchivoAutoNuevo archivoAutoNuevo;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Buscar auto (0 km) por numero de chasis" << endl;
            cout << "2 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionBuscarAutoNuevo;

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

        if(opcionBuscarAutoNuevo == 1)
        {
            concesionariaManager.buscarAutoNuevoPorNumeroDeChasis();
        }
        else if(opcionBuscarAutoNuevo == 2)
        {
            break;
        }
        else
        {
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while (opcionBuscarAutoNuevo != 2);
}

void Menu::subMenuBuscarAutoUsado()
{
    int opcionBuscarAutoUsado;
    AutoUsado autoUsado;
    ArchivoAutoUsado archivoAutoUsado;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Buscar auto usado por numero de chasis" << endl;
            cout << "2 - Buscar auto usado por numero de patente" << endl;
            cout << "3 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionBuscarAutoUsado;

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

        if(opcionBuscarAutoUsado == 1)
        {
            concesionariaManager.buscarAutoUsadoPorNumeroDeChasis();
        }
        else if(opcionBuscarAutoUsado == 2)
        {
            concesionariaManager.buscarAutoUsadoPorNumeroDePatente();
        }
        else if(opcionBuscarAutoUsado == 3)
        {
            break;
        }
        else
        {
            system("cls");
            mostrarLogo();
            cout << "Entrada invalida. Intente nuevamente." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    while (opcionBuscarAutoUsado != 3);
}

void Menu::mostrarMenuListados()
{
    int opcionListados;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de ventas" << endl;
            cout << "2 - Listado de clientes" << endl;
            cout << "3 - Listado de vendedores" << endl;
            cout << "4 - Listado de autos nuevos" << endl;
            cout << "5 - Listado de autos usados" << endl;
            cout << "6 - Volver al menu anterior" << endl;


            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListados;

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

        switch(opcionListados)
        {
        case 1:
            mostrarMenuListadosVentas();
            break;
        case 2:
            mostrarMenuListadosClientes();
            break;
        case 3:
            mostrarMenuListadosVendedores();
            break;
        case 4:
            mostrarMenuListadosAutosNuevos();
            break;
        case 5:
            mostrarMenuListadosAutosUsados();
            break;
        case 6:
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
    while (opcionListados != 6);
}

void Menu::mostrarMenuListadosVentas()
{
    int opcionListadosVentas;
    Venta venta;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de ventas por fecha" << endl;
            cout << "2 - Listado de ventas por vendedor" << endl;
            cout << "3 - Listado de ventas por marca" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListadosVentas;

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

        switch(opcionListadosVentas)
        {
        case 1:
            venta.listadoVentasPorFecha();
            break;
        case 2:
            venta.listadoVentasPorVendedor();
            break;
        case 3:
            venta.listadoVentasPorMarca();
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
    while (opcionListadosVentas != 4);
}

void Menu::mostrarMenuListadosClientes()
{
    Cliente cliente;
    int opcionListadosClientes;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de clientes por DNI" << endl;
            cout << "2 - Listado de clientes por apellido" << endl;
            cout << "3 - Listado de clientes por fecha de nacimiento" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListadosClientes;

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

        switch(opcionListadosClientes)
        {
        case 1:
            cliente.listadoClientesPorDNI();
            break;
        case 2:
            cliente.listadoClientesPorApellido();
            break;
        case 3:
            cliente.listadoClientesPorFecha();
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
    while (opcionListadosClientes != 4);
}

void Menu::mostrarMenuListadosVendedores()
{
    int opcionListadosVendedores;
    Vendedor vendedor;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de vendedores por DNI" << endl;
            cout << "2 - Listado de vendedores por apellido" << endl;
            cout << "3 - Listado de vendedores por fecha de ingreso" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListadosVendedores;

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

        switch(opcionListadosVendedores)
        {
        case 1:
            vendedor.listadoVendedoresPorDNI();
            break;
        case 2:
            vendedor.listadoVendedoresPorApellido();
            break;
        case 3:
            vendedor.listadoVendedoresPorFechaIngreso();
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
    while (opcionListadosVendedores != 4);
}

void Menu::mostrarMenuListadosAutosNuevos()
{
    int opcionListadosAutosNuevos;
    AutoNuevo autoNuevo;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de auto por marca" << endl;
            cout << "2 - Listado de auto por modelo" << endl;
            cout << "3 - Listado de auto por anio" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListadosAutosNuevos;

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

        switch(opcionListadosAutosNuevos)
        {
        case 1:
            ///Marca
            autoNuevo.listadoAutosNuevosPorMarca();
            break;
        case 2:
            ///Modelo
            autoNuevo.listadoAutosNuevosPorModelo();
            break;
        case 3:
            ///Anio
            autoNuevo.listadoAutosNuevosPorAnio();
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
    while (opcionListadosAutosNuevos != 4);
}

void Menu::mostrarMenuListadosAutosUsados()
{
    AutoUsado autoUsado;
    int opcionListadosAutosUsados;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Listado de auto por marca" << endl;
            cout << "2 - Listado de auto por modelo" << endl;
            cout << "3 - Listado de auto por anio" << endl;
            cout << "4 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionListadosAutosUsados;

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

        switch(opcionListadosAutosUsados)
        {
        case 1:
            ///Marca
            autoUsado.listadoAutosUsadosPorMarca();
            break;
        case 2:
            ///Modelo
            autoUsado.listadoAutosUsadosPorModelo();
            break;
        case 3:
            ///Anio
            autoUsado.listadoAutosUsadosPorAnio();
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
    while (opcionListadosAutosUsados != 4);
}


void Menu::mostrarMenuConsultas()
{
    int opcionConsultas;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Consulta de ventas" << endl;
            cout << "2 - Consulta de autos" << endl;
            cout << "3 - Volver al menu anterior" << endl;


            cout << "Ingrese una opcion: " << endl;
            cin >> opcionConsultas;

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

        switch(opcionConsultas)
        {
        case 1:
            mostrarMenuConsultasVentas();
            break;
        case 2:
            mostrarMenuConsultasAutos();
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
    while (opcionConsultas != 3);
}

void Menu::mostrarMenuConsultasVentas()
{
    Venta venta;
    int opcionConsultasVentas;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Consulta de ventas por cliente" << endl;
            cout << "2 - Consulta de ventas por vendedor" << endl;
            cout << "3 - Consulta de ventas por fecha" << endl;
            cout << "4 - Consulta de ventas por marca" << endl;
            cout << "5 - Consulta de ventas por rango de precios" << endl;
            cout << "6 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionConsultasVentas;

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

        switch(opcionConsultasVentas)
        {
        case 1:
            venta.consultaVentasPorCliente();
            break;
        case 2:
            venta.consultaVentasPorVendedor();
            break;
        case 3:
            venta.consultaVentasPorFecha();
            break;
        case 4:
            venta.consultaVentasPorMarca();
            break;
        case 5:
            venta.consultaVentasPorRangoDePrecios();
            break;
        case 6:
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
    while (opcionConsultasVentas != 6);
}


void Menu::mostrarMenuConsultasAutos()
{
    ConcesionariaManager concesionariaManager;
    int opcionConsultasAutos;
    do
    {
        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            mostrarLogo();
            cout << "1 - Consulta de autos por marca" << endl;
            cout << "2 - Consulta de autos por rango de precios" << endl;
            cout << "3 - Volver al menu anterior" << endl;

            cout << "Ingrese una opcion: " << endl;
            cin >> opcionConsultasAutos;

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

        switch(opcionConsultasAutos)
        {
        case 1:
            concesionariaManager.consultaAutosPorMarca();
            break;
        case 2:
            concesionariaManager.consultaAutosPorRangoDePrecios();
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
    while (opcionConsultasAutos != 3);
}



