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

void Menu::mostrarLogoAnimado()
{
    system("cls");

    // Posición inicial del auto
    int x = 5;
    int y = 3;

    // Animación del auto moviéndose
    for(int i = 0; i < 40; i++) {
        rlutil::locate(x + i, y);
        cout << "    ______       ";
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
    while (opcionBuscarAutoUsado != 2);
}

void Menu::mostrarMenuListados()
{

}

void Menu::mostrarMenuConsultas()
{

}


