#include<iostream>
#include<string>
#include "ConcesionariaManager.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Venta.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "ArchivoAutoNuevo.h"
#include "ArchivoAutoUsado.h"
#include "Menu.h"

using namespace std;

Menu menu;
ArchivoCliente archivoCliente;
Cliente cliente;
ArchivoVendedor archivoVendedor;
Vendedor vendedor;

void ConcesionariaManager::modificarCliente()
{
    char dni[12];
    char confirmar;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del cliente: ";
        cin.getline(dni, sizeof(dni));

        if(!(archivoCliente.buscarClientePorDNI(dni) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un cliente con ese DNI." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta. " << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if(confirmar == 's')
            {
                cin.ignore();
                int pos = archivoCliente.buscarClientePorDNI(dni);
                Cliente cliente;
                cliente = archivoCliente.Leer(pos);
                cliente.modificarCliente(cliente);
                if(archivoCliente.Guardar(cliente, pos))
                {
                    cout << "Cliente modificado exitosamente." << endl;
                }
                else
                {
                    cout << "No se pudo modificar el cliente." << endl;
                }
                system("pause");
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
}

void ConcesionariaManager::buscarClientePorDNI()
{
    char dni[12];
    char confirmar;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del cliente: ";
        cin.getline(dni, sizeof(dni));

        if(!(archivoCliente.buscarClientePorDNI(dni) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un cliente con ese DNI." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoCliente.buscarClientePorDNI(dni); /// Busco la posicion del cliente en base al DNI
                cliente = archivoCliente.Leer(pos);
                cliente.mostrarCliente(cliente);
                system("pause");
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
}

void ConcesionariaManager::buscarClientePorID()
{
    int idCliente;
    char confirmar;
    while(true)
    {

        while (true) // Bucle infinito hasta que se ingrese un valor v�lido
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del cliente: ";
            cin >> idCliente;

            if (cin.fail()) // Si la entrada es inv�lida
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es v�lida, salir del bucle
            }
        }

        if(!(archivoCliente.buscarClientePorID(idCliente) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un cliente con ese ID." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El ID ingresado es " << idCliente << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoCliente.buscarClientePorID(idCliente); /// Busco la posicion del cliente en base al ID
                cliente = archivoCliente.Leer(pos);
                cliente.mostrarCliente(cliente);
                system("pause");
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
}

void ConcesionariaManager::modificarVendedor()
{
    char dni[12];
    char confirmar;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del vendedor: ";
        cin.getline(dni, sizeof(dni));

        if(!(archivoVendedor.buscarVendedorPorDNI(dni) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vendedor con ese DNI." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoVendedor.buscarVendedorPorDNI(dni); /// Busco la posicion del vendedor en base al DNI
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
            else
            {
                cin.ignore();
            }
        }
    }
}

void ConcesionariaManager::buscarVendedorPorDNI()
{
    char dni[12];
    char confirmar;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del vendedor: ";
        cin.getline(dni, sizeof(dni));

        if(!(archivoVendedor.buscarVendedorPorDNI(dni) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vendedor con ese DNI." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoVendedor.buscarVendedorPorDNI(dni); /// Busco la posicion del vendedor en base al DNI
                Vendedor vendedor;
                vendedor = archivoVendedor.Leer(pos);
                vendedor.mostrarVendedor(vendedor);
                system("pause");
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
}

void ConcesionariaManager::buscarVendedorPorID()
{
    int idVendedor;
    char confirmar;
    while(true)
    {

        while (true) // Bucle infinito hasta que se ingrese un valor v�lido
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del vendedor: ";
            cin >> idVendedor;

            if (cin.fail()) // Si la entrada es inv�lida
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es v�lida, salir del bucle
            }
        }

        if(!(archivoVendedor.buscarVendedorPorID(idVendedor) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vendedor con ese ID." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El ID ingresado es " << idVendedor << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoVendedor.buscarVendedorPorID(idVendedor); /// Busco la posicion del vendedor en base al DNI
                vendedor = archivoVendedor.Leer(pos);
                vendedor.mostrarVendedor(vendedor);
                system("pause");
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
}

