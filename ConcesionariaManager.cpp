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

        if(!(archivoCliente.buscarCliente(dni) >= 0))
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
                int pos = archivoCliente.buscarCliente(dni);
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
        }
    }
}

void ConcesionariaManager::buscarCliente()
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

        if(!(archivoCliente.buscarCliente(dni) >= 0))
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
            cout << "Error: Opcion incorrecta" << endl;
            cout << "Desea confirmar? (s/n)" << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
        }
        if(confirmar == 's')
        {
            cin.ignore();
            int pos = archivoCliente.buscarCliente(dni);
            Cliente cliente;
            cliente = archivoCliente.Leer(pos);
            cliente.mostrarCliente(cliente);
            system("pause");
            break;
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

        if(!(archivoVendedor.buscarVendedor(dni) >= 0))  /// si cuenta y NO encuentra el registro
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
}

void ConcesionariaManager::buscarVendedor()
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

        if(!(archivoVendedor.buscarVendedor(dni) >= 0))  /// si cuenta y NO encuentra el registro
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
                int pos = archivoVendedor.buscarVendedor(dni); /// Busco la posicion del vendedor en base al DNI
                Vendedor vendedor;
                vendedor = archivoVendedor.Leer(pos);
                vendedor.mostrarVendedor(vendedor);
                system("pause");
                break;
            }
        }
    }
}
