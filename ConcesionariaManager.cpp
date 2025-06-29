#include<iostream>
#include<string>
#include "ConcesionariaManager.h"
#include "Cliente.h"
#include "Vendedor.h"
#include "Venta.h"
#include "ArchivoVenta.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "ArchivoAutoNuevo.h"
#include "ArchivoAutoUsado.h"
#include "Menu.h"
#include "iomanip"
#include <limits>

using namespace std;


/* ------------------ Seccion CLIENTES & VENDEDORES ------------------ */

Menu menu;
ArchivoCliente archivoCliente;
Cliente cliente;
ArchivoVendedor archivoVendedor;
Vendedor vendedor;

void ConcesionariaManager::modificarCliente()
{
    char dni[12];
    char confirmar;
    char volverAtras;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del cliente: ";
        cin.getline(dni, sizeof(dni));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if(!(archivoCliente.buscarClientePorDNI(dni) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un cliente con ese DNI." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
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
                cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if(confirmar == 's')
            {
                cin.ignore();
                int pos = archivoCliente.buscarClientePorDNI(dni);
                Cliente cliente;
                cliente = archivoCliente.Leer(pos);

                // Capturo el resultado de la modificación
                bool modificado = cliente.modificarCliente(cliente);

                if(modificado)
                {
                    if(archivoCliente.Guardar(cliente, pos))
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Cliente modificado exitosamente." << endl;
                    }
                    else
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "No se pudo modificar el cliente. Intente nuevamente." << endl;
                    }
                }
                else
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Modificacion cancelada. No se realizaron cambios." << endl;
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
    char volverAtras;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del cliente: ";
        cin.getline(dni, sizeof(dni));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(!(archivoCliente.buscarClientePorDNI(dni) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un cliente con ese DNI." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
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
                cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
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
    char volverAtras;
    while(true)
    {

        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del cliente: ";
            cin >> idCliente;

            if (cin.fail())
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> volverAtras;
                if(volverAtras == 'q')
                {
                    break;
                }
                else
                {
                    cin.ignore();
                }
            }
            else
            {
                break;
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
                cout << "El ID ingresado es " << idCliente << ". Es correcto? (s/n) " << endl;
                //cout << "Desea confirmar? (s/n)" << endl;
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
    char volverAtras;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del vendedor: ";
        cin.getline(dni, sizeof(dni));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(!(archivoVendedor.buscarVendedorPorDNI(dni) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vendedor con ese DNI." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
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
                cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoVendedor.buscarVendedorPorDNI(dni); /// Busco la posicion del vendedor en base al DNI
                vendedor = archivoVendedor.Leer(pos);

                // Capturo el resultado de la modificación
                bool modificado = vendedor.modificarVendedor(vendedor);

                if(modificado)
                {
                    if(archivoVendedor.Guardar(vendedor, pos))
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Vendedor modificado exitosamente." << endl;
                    }
                    else
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "No se pudo modificar el vendedor. Intente nuevamente." << endl;
                    }
                }
                else
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Modificacion cancelada. No se realizaron cambios." << endl;
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
    char volverAtras;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese DNI del vendedor: ";
        cin.getline(dni, sizeof(dni));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(!(archivoVendedor.buscarVendedorPorDNI(dni) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vendedor con ese DNI." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
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
                cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
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
    char volverAtras;
    while(true)
    {

        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del vendedor: ";
            cin >> idVendedor;

            if (cin.fail())
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Entrada invalida. Intente nuevamente." << endl;
                rlutil::setColor(rlutil::LIGHTRED);
                cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> volverAtras;
                if(volverAtras == 'q')
                {
                    break;
                }
                else
                {
                    cin.ignore();
                }
            }
            else
            {
                break;
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
                cout << "El ID ingresado es " << idVendedor << ". Es correcto? (s/n) " << endl;
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

/* ------------------ Seccion VENTAS ------------------ */

/* ****************** AUTOS NUEVOS ****************** */

bool ConcesionariaManager::modificarVentaAutoNuevo()
{
    Menu menu;
    char opcion;
    bool confirmarTodo = false;
    int idVenta;
    ArchivoVenta archivoVenta;
    ArchivoAutoNuevo archivoAutoNuevo;
    Venta venta;
    char volverAtras;
    int pos;
    AutoNuevo autoNuevo;

    // Pedir ID de la venta
    while(true)
    {
        while(true)
        {

            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese el ID de la venta a modificar: ";
            cin >> idVenta;

            if(cin.fail())
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break;
            }
        }

        pos = archivoVenta.Buscar(idVenta);
        if(pos == -1)
        {
            cout << "Error: No existe una venta con ese ID." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                return false;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            venta = archivoVenta.Leer(pos);
            break;
        }
    }

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DE LA VENTA ===" << endl;   /// TODO: Funcion para mostrarVenta
        cout << "ID Venta: " << venta.getIdVenta() << endl;
        cout << "Monto: $" << fixed << setprecision(2) << venta.getMonto() << endl;
        cout << "Fecha: " << venta.getFechaDeVenta().toString() << endl;
        cout << "ID Cliente: " << venta.getIdCliente() << endl;
        cout << "ID Vendedor: " << venta.getIdVendedor() << endl;
        cout << endl;
        if(venta.getEstado() == true)
        {
            cout << "Estado actual de la venta: ACTIVA" << endl;
        }
        else
        {
            cout << "Estado actual de la venta: INACTIVA" << endl;
        }
        cout << endl;
        cout << "Desea cambiar el estado de la venta? (s/n): ";
        cin >> opcion;
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << "Desea cambiar el estado de la venta? (s/n): " << endl;
            cin >> opcion;
            opcion = tolower(opcion);
        }

        if(opcion == 's')
        {
            /// Busco el auto en el archivo usando el numero de chasis de la venta
            char numeroDeChasis[10];
            strcpy(numeroDeChasis, venta.getPatente().getNumeroChasis());
            int posAuto = archivoAutoNuevo.Buscar(numeroDeChasis);

            if(posAuto != -1)
            {
                /// Lee el auto nuevo del archivo
                autoNuevo = archivoAutoNuevo.Leer(posAuto);

                if(venta.getEstado())
                {
                    venta.setEstado(false);
                    cout << "Estado de la venta actualizado a INACTIVA." << endl;
                    // Se desactiva la venta -> El auto vuelve a estar disponible
                    cout << "El auto involucrado en la venta vuelve a estar disponible." << endl;
                    autoNuevo.setEstado(true);
                }
                else
                {
                    venta.setEstado(true);
                    cout << "Estado de la venta actualizado a ACTIVA." << endl;
                    // Se activa la venta -> El auto se marca como vendido
                    autoNuevo.setEstado(false);
                }

                /// Guardo los cambios en los dos archivos
                archivoVenta.Guardar(venta, pos);
                archivoAutoNuevo.Guardar(autoNuevo, posAuto);
                system("pause");
                confirmarTodo = true;
            }
            else
            {
                rlutil::setColor(rlutil::RED);
                cout << "Error: No se pudo encontrar el auto asociado a esta venta. Verifique que quiera modificar la venta de un auto nuevo." << endl;
                rlutil::setColor(rlutil::WHITE);
                system("pause");
                confirmarTodo = true;
            }
        }
        else
        {
            confirmarTodo = true;
        }
    }
    return true;
}

bool ConcesionariaManager::modificarVentaAutoUsado()
{
    Menu menu;
    char opcion;
    bool confirmarTodo = false;
    int idVenta;
    ArchivoVenta archivoVenta;
    ArchivoAutoUsado archivoAutoUsado;
    Venta venta;
    char volverAtras;
    int pos;
    AutoUsado autoUsado;

    // Pedir ID de la venta
    while(true)
    {
        while(true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese el ID de la venta a modificar: ";
            cin >> idVenta;

            if(cin.fail())
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break;
            }
        }

        pos = archivoVenta.Buscar(idVenta);
        if(pos == -1)
        {
            cout << "Error: No existe una venta con ese ID." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                return false;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            venta = archivoVenta.Leer(pos);
            break;
        }
    }

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DE LA VENTA ===" << endl;
        cout << "ID Venta: " << venta.getIdVenta() << endl;
        cout << "Monto: $" << fixed << setprecision(2) << venta.getMonto() << endl;
        cout << "Fecha: " << venta.getFechaDeVenta().toString() << endl;
        cout << "ID Cliente: " << venta.getIdCliente() << endl;
        cout << "ID Vendedor: " << venta.getIdVendedor() << endl;
        cout << endl;
        if(venta.getEstado() == true)
        {
            cout << "Estado actual de la venta: ACTIVA" << endl;
        }
        else
        {
            cout << "Estado actual de la venta: INACTIVA" << endl;
        }
        cout << endl;
        cout << "Desea cambiar el estado de la venta? (s/n): ";
        cin >> opcion;
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << "Desea cambiar el estado de la venta? (s/n): " << endl;
            cin >> opcion;
            opcion = tolower(opcion);
        }

        if(opcion == 's')
        {
            char numeroDeChasis[10];
            strcpy(numeroDeChasis, venta.getPatente().getNumeroChasis());
            int posAuto = archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis);

            if(posAuto != -1)
            {
                /// Lee el auto usado del archivo
                autoUsado = archivoAutoUsado.Leer(posAuto);

                if(venta.getEstado())
                {
                    venta.setEstado(false);
                    cout << "Estado de la venta actualizado a INACTIVA." << endl;
                    // Se desactiva la venta -> El auto vuelve a estar disponible
                    cout << "El auto involucrado en la venta vuelve a estar disponible." << endl;
                    autoUsado.setEstado(true);
                }
                else
                {
                    venta.setEstado(true);
                    cout << "Estado de la venta actualizado a ACTIVA" << endl;
                    // Se activa la venta -> El auto se marca como vendido
                    autoUsado.setEstado(false);
                }

                /// Guardo cambios en los dos archivos
                archivoVenta.Guardar(venta, pos);
                archivoAutoUsado.Guardar(autoUsado, posAuto);
                system("pause");
                confirmarTodo = true;
            }
            else
            {
                rlutil::setColor(rlutil::RED);
                cout << "Error: No se pudo encontrar el auto asociado a esta venta. Verifique que quiera modificar la venta de un auto nuevo." << endl;
                rlutil::setColor(rlutil::WHITE);
                system("pause");
                confirmarTodo = true;
            }
        }
        else
        {
            confirmarTodo = true;
        }
    }
    return true;
}

void ConcesionariaManager::buscarVentaAutoNuevoPorNumeroChasis()
{

}

void ConcesionariaManager::buscarVentaAutoNuevoPorIDVenta()
{

}

void ConcesionariaManager::modificarAutoNuevo()
{
    char numeroDeChasis[10];
    char confirmar;
    AutoNuevo autoNuevo;
    ArchivoAutoNuevo archivoAutoNuevo;
    char volverAtras;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del auto a modificar: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(!(archivoAutoNuevo.Buscar(numeroDeChasis) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un auto con ese numero de chasis." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoAutoNuevo.Buscar(numeroDeChasis); /// Busco la posicion del auto en base al numero de chasis
                autoNuevo = archivoAutoNuevo.Leer(pos);
                autoNuevo.modificarAutoNuevo(autoNuevo);
                if(archivoAutoNuevo.Guardar(autoNuevo, pos))
                {
                    cout << "Auto modificado exitosamente." << endl;
                }
                else
                {
                    cout << "No se pudo modificar el auto." << endl;
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


void ConcesionariaManager::buscarAutoNuevoPorNumeroDeChasis()
{
    char numeroDeChasis[10];
    char confirmar;
    char volverAtras;
    ArchivoAutoNuevo archivoAutoNuevo;
    AutoNuevo autoNuevo;

    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del vehiculo: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if((archivoAutoNuevo.Buscar(numeroDeChasis) < 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;

            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);

            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }

            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoAutoNuevo.Buscar(numeroDeChasis); /// Busco la posicion del auto en base al numero de chasis
                autoNuevo = archivoAutoNuevo.Leer(pos);
                autoNuevo.mostrarAutoNuevo(autoNuevo);
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

/* ****************** AUTOS USADOS ****************** */

void ConcesionariaManager::modificarAutoUsado()
{
    char numeroDeChasis[10];
    char confirmar;
    AutoUsado autoUsado;
    ArchivoAutoUsado ArchivoAutoUsado;
    char volverAtras;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del auto a modificar: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(!(ArchivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un auto con ese numero de chasis." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;
            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                int pos = ArchivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis); /// Busco la posicion del auto en base al numero de chasis
                autoUsado = ArchivoAutoUsado.Leer(pos);
                autoUsado.modificarAutoUsado(autoUsado);
                if(ArchivoAutoUsado.Guardar(autoUsado, pos))
                {
                    cout << "Auto modificado exitosamente." << endl;
                }
                else
                {
                    cout << "No se pudo modificar el auto." << endl;
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

void ConcesionariaManager::buscarAutoUsadoPorNumeroDeChasis()
{
    char numeroDeChasis[10];
    char confirmar;
    char volverAtras;
    ArchivoAutoUsado archivoAutoUsado;
    AutoUsado autoUsado;

    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del vehiculo: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if((archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis) < 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;

            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);

            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El numero de chasis ingresado es " << numeroDeChasis << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }

            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis); /// Busco la posicion del auto en base al numero de chasis
                autoUsado = archivoAutoUsado.Leer(pos);
                autoUsado.mostrarAutoUsado(autoUsado);
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

void ConcesionariaManager::buscarAutoUsadoPorNumeroDePatente()
{
    char numeroDePatente[10];
    char confirmar;
    ArchivoAutoUsado archivoAutoUsado;
    AutoUsado autoUsado;
    char volverAtras;
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de patente del vehiculo: ";
        cin.getline(numeroDePatente, sizeof(numeroDePatente));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if((archivoAutoUsado.BuscarAutoUsadoPorNumeroDePatente(numeroDePatente) < 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de patente." << endl;
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "\nSi desea volver atras ingrese la tecla 'q'" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> volverAtras;

            if(volverAtras == 'q')
            {
                break;
            }
            else
            {
                cin.ignore();
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de pantente ingresado es " << numeroDePatente << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);

            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El numero de patente ingresado es " << numeroDePatente << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }

            if (confirmar == 's')
            {
                cin.ignore();
                int pos = archivoAutoUsado.BuscarAutoUsadoPorNumeroDePatente(numeroDePatente); /// Busco la posicion del auto en base al numero de patente
                autoUsado = archivoAutoUsado.Leer(pos);
                autoUsado.mostrarAutoUsado(autoUsado);
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

void ConcesionariaManager::buscarVentaAutoUsadoPorNumeroChasis()
{

}

void ConcesionariaManager::buscarVentaAutoUsadoPorIDVenta()
{

}

/* ------------------ Seccion CONSULTAS ------------------ */

void ConcesionariaManager::consultaAutosPorMarca()
{
    Menu menu;
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    ArchivoAutoUsado archivoAutoUsado("autousado.dat");
    AutoNuevo autoNuevo;
    AutoUsado autoUsado;
    AutoNuevo *vecAutosNuevos = nullptr;
    AutoUsado *vecAutosUsados = nullptr;

    char marcaConsulta[50];
    int cantidadAutosNuevos = 0;
    int cantidadAutosUsados = 0;
    int cantidadRegistrosNuevos = archivoAutoNuevo.CantidadRegistros();
    int cantidadRegistrosUsados = archivoAutoUsado.CantidadRegistros();

    if(cantidadRegistrosNuevos == 0 && cantidadRegistrosUsados == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay autos registrados para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar marca de consulta
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE AUTOS POR MARCA ===" << endl;
    cout << "===================================" << endl;
    cout << endl;

    cin.ignore();
    cout << "Ingrese la marca para consultar los autos: ";
    cin.getline(marcaConsulta, sizeof(marcaConsulta));
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        menu.mostrarLogo();
        cout << "Error: Ingreso demasiados caracteres." << endl;
        system("pause");
        return;
    }

    /// Contar cuantos autos nuevos hay de esa marca
    for(int i = 0; i < cantidadRegistrosNuevos; i++)
    {
        autoNuevo = archivoAutoNuevo.Leer(i);
        if(strcmp(autoNuevo.getMarca(), marcaConsulta) == 0)
        {
            cantidadAutosNuevos++;
        }
    }

    /// Contar cuantos autos usados hay de esa marca
    for(int i = 0; i < cantidadRegistrosUsados; i++)
    {
        autoUsado = archivoAutoUsado.Leer(i);
        if(strcmp(autoUsado.getMarca(), marcaConsulta) == 0)
        {
            cantidadAutosUsados++;
        }
    }

    if(cantidadAutosNuevos == 0 && cantidadAutosUsados == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se encontraron autos registrados de la marca " << marcaConsulta << "." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vectores para almacenar los autos de esa marca
    if(cantidadAutosNuevos > 0)
    {
        vecAutosNuevos = new AutoNuevo[cantidadAutosNuevos];
        if(vecAutosNuevos == nullptr)
        {
            cout << "Error: No se pudo asignar memoria." << endl;
            system("pause");
            return;
        }
    }

    if(cantidadAutosUsados > 0)
    {
        vecAutosUsados = new AutoUsado[cantidadAutosUsados];
        if(vecAutosUsados == nullptr)
        {
            cout << "Error: No se pudo asignar memoria." << endl;
            if(vecAutosNuevos) delete[] vecAutosNuevos;
            system("pause");
            return;
        }
    }

    /// Cargar los autos nuevos de esa marca en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistrosNuevos; i++)
    {
        autoNuevo = archivoAutoNuevo.Leer(i);
        if(strcmp(autoNuevo.getMarca(), marcaConsulta) == 0)
        {
            vecAutosNuevos[j] = autoNuevo;
            j++;
        }
    }

    /// Cargar los autos usados de esa marca en el vector
    int k = 0;
    for(int i = 0; i < cantidadRegistrosUsados; i++)
    {
        autoUsado = archivoAutoUsado.Leer(i);
        if(strcmp(autoUsado.getMarca(), marcaConsulta) == 0)
        {
            vecAutosUsados[k] = autoUsado;
            k++;
        }
    }

    /// Mostrar los autos de esa marca
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion de la consulta
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== AUTOS DE LA MARCA " << marcaConsulta << " ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===============================";

    int fila = 11;
    float totalPrecioNuevos = 0.0f;
    float totalPrecioUsados = 0.0f;

    /// Mostrar autos nuevos
    if(cantidadAutosNuevos > 0)
    {
        rlutil::locate(5, fila);
        rlutil::setColor(rlutil::YELLOW);
        cout << "AUTOS NUEVOS:";
        fila++;

        for(int i = 0; i < cantidadAutosNuevos; i++)
        {
            /// Alternar colores para las filas
            if(i % 2 == 0)
            {
                rlutil::setColor(rlutil::WHITE);
            }
            else
            {
                rlutil::setColor(rlutil::GREY);
            }

            rlutil::locate(5, fila);
            cout << "Chasis: " << vecAutosNuevos[i].getPatente().getNumeroChasis();
            rlutil::locate(25, fila);
            cout << "Patente: " << vecAutosNuevos[i].getPatente().getNumeroPatente();
            rlutil::locate(45, fila);
            cout << "Modelo: " << vecAutosNuevos[i].getModelo();
            rlutil::locate(65, fila);
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "$" << fixed << setprecision(2) << vecAutosNuevos[i].getPrecioDeVenta();
            totalPrecioNuevos += vecAutosNuevos[i].getPrecioDeVenta();

            fila++;
        }
        fila++;
    }

    /// Mostrar autos usados
    if(cantidadAutosUsados > 0)
    {
        rlutil::locate(5, fila);
        rlutil::setColor(rlutil::YELLOW);
        cout << "AUTOS USADOS:";
        fila++;

        for(int i = 0; i < cantidadAutosUsados; i++)
        {
            /// Alternar colores para las filas
            if(i % 2 == 0)
            {
                rlutil::setColor(rlutil::WHITE);
            }
            else
            {
                rlutil::setColor(rlutil::GREY);
            }

            rlutil::locate(5, fila);
            cout << "Chasis: " << vecAutosUsados[i].getPatente().getNumeroChasis();
            rlutil::locate(25, fila);
            cout << "Patente: " << vecAutosUsados[i].getPatente().getNumeroPatente();
            rlutil::locate(45, fila);
            cout << "Modelo: " << vecAutosUsados[i].getModelo();
            rlutil::locate(65, fila);
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "$" << fixed << setprecision(2) << vecAutosUsados[i].getPrecioDeVenta();
            totalPrecioUsados += vecAutosUsados[i].getPrecioDeVenta();

            fila++;
        }
        fila++;
    }

    /// Resumen
    rlutil::locate(5, fila + 1);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de autos de " << marcaConsulta << ": " << (cantidadAutosNuevos + cantidadAutosUsados);

    rlutil::locate(5, fila + 2);
    cout << "Autos nuevos: " << cantidadAutosNuevos << " - Total: $" << fixed << setprecision(2) << totalPrecioNuevos;

    rlutil::locate(5, fila + 3);
    cout << "Autos usados: " << cantidadAutosUsados << " - Total: $" << fixed << setprecision(2) << totalPrecioUsados;

    rlutil::locate(5, fila + 4);
    cout << "Precio total: $" << fixed << setprecision(2) << (totalPrecioNuevos + totalPrecioUsados);

    /// Mensaje de espera
    rlutil::locate(5, fila + 6);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    /// Liberar memoria
    if(vecAutosNuevos) delete[] vecAutosNuevos;
    if(vecAutosUsados) delete[] vecAutosUsados;
}

void ConcesionariaManager::consultaAutosPorRangoDePrecios()
{
    Menu menu;
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    ArchivoAutoUsado archivoAutoUsado("autousado.dat");
    AutoNuevo autoNuevo;
    AutoUsado autoUsado;
    AutoNuevo *vecAutosNuevos = nullptr;
    AutoUsado *vecAutosUsados = nullptr;

    float precioMinimo, precioMaximo;
    int cantidadAutosNuevos = 0;
    int cantidadAutosUsados = 0;
    int cantidadRegistrosNuevos = archivoAutoNuevo.CantidadRegistros();
    int cantidadRegistrosUsados = archivoAutoUsado.CantidadRegistros();

    if(cantidadRegistrosNuevos == 0 && cantidadRegistrosUsados == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay autos registrados para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar rango de precios
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE AUTOS POR RANGO DE PRECIOS ===" << endl;
    cout << "==============================================" << endl;
    cout << endl;

    /// Solicitar precio minimo
    cout << "Ingrese el precio minimo: $";
    cin >> precioMinimo;
    if(cin.fail() || precioMinimo < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Ingrese un precio minimo valido." << endl;
        system("pause");
        return;
    }

    /// Solicitar precio maximo
    cout << "Ingrese el precio maximo: $";
    cin >> precioMaximo;
    if(cin.fail() || precioMaximo < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Ingrese un precio maximo valido." << endl;
        system("pause");
        return;
    }

    /// Validar que el precio maximo sea mayor al minimo
    if(precioMaximo < precioMinimo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Error: El precio maximo debe ser mayor o igual al precio minimo." << endl;
        system("pause");
        return;
    }

    /// Contar cuantos autos nuevos hay en ese rango
    for(int i = 0; i < cantidadRegistrosNuevos; i++)
    {
        autoNuevo = archivoAutoNuevo.Leer(i);
        if(autoNuevo.getPrecioDeVenta() >= precioMinimo && autoNuevo.getPrecioDeVenta() <= precioMaximo)
        {
            cantidadAutosNuevos++;
        }
    }

    /// Contar cuantos autos usados hay en ese rango
    for(int i = 0; i < cantidadRegistrosUsados; i++)
    {
        autoUsado = archivoAutoUsado.Leer(i);
        if(autoUsado.getPrecioDeVenta() >= precioMinimo && autoUsado.getPrecioDeVenta() <= precioMaximo)
        {
            cantidadAutosUsados++;
        }
    }

    if(cantidadAutosNuevos == 0 && cantidadAutosUsados == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se encontraron autos registrados entre $" << fixed << setprecision(2) << precioMinimo << " y $" << precioMaximo << "." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vectores para almacenar los autos del rango
    if(cantidadAutosNuevos > 0)
    {
        vecAutosNuevos = new AutoNuevo[cantidadAutosNuevos];
        if(vecAutosNuevos == nullptr)
        {
            cout << "Error: No se pudo asignar memoria." << endl;
            system("pause");
            return;
        }
    }

    if(cantidadAutosUsados > 0)
    {
        vecAutosUsados = new AutoUsado[cantidadAutosUsados];
        if(vecAutosUsados == nullptr)
        {
            cout << "Error: No se pudo asignar memoria." << endl;
            if(vecAutosNuevos) delete[] vecAutosNuevos;
            system("pause");
            return;
        }
    }

    /// Cargar los autos nuevos del rango en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistrosNuevos; i++)
    {
        autoNuevo = archivoAutoNuevo.Leer(i);
        if(autoNuevo.getPrecioDeVenta() >= precioMinimo && autoNuevo.getPrecioDeVenta() <= precioMaximo)
        {
            vecAutosNuevos[j] = autoNuevo;
            j++;
        }
    }

    /// Cargar los autos usados del rango en el vector
    int k = 0;
    for(int i = 0; i < cantidadRegistrosUsados; i++)
    {
        autoUsado = archivoAutoUsado.Leer(i);
        if(autoUsado.getPrecioDeVenta() >= precioMinimo && autoUsado.getPrecioDeVenta() <= precioMaximo)
        {
            vecAutosUsados[k] = autoUsado;
            k++;
        }
    }

    /// Mostrar los autos del rango
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion de la consulta
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== AUTOS ENTRE $" << fixed << setprecision(2) << precioMinimo << " Y $" << precioMaximo << " ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "=============================================";

    int fila = 11;
    float totalPrecioNuevos = 0.0f;
    float totalPrecioUsados = 0.0f;

    /// Mostrar autos nuevos
    if(cantidadAutosNuevos > 0)
    {
        rlutil::locate(5, fila);
        rlutil::setColor(rlutil::YELLOW);
        cout << "AUTOS NUEVOS:";
        fila++;

        for(int i = 0; i < cantidadAutosNuevos; i++)
        {
            /// Alternar colores para las filas
            if(i % 2 == 0)
            {
                rlutil::setColor(rlutil::WHITE);
            }
            else
            {
                rlutil::setColor(rlutil::GREY);
            }

            rlutil::locate(5, fila);
            cout << "Chasis: " << vecAutosNuevos[i].getPatente().getNumeroChasis();
            rlutil::locate(25, fila);
            cout << "Patente: " << vecAutosNuevos[i].getPatente().getNumeroPatente();
            rlutil::locate(45, fila);
            cout << "Marca: " << vecAutosNuevos[i].getMarca();
            rlutil::locate(65, fila);
            cout << "Modelo: " << vecAutosNuevos[i].getModelo();
            rlutil::locate(85, fila);
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "$" << fixed << setprecision(2) << vecAutosNuevos[i].getPrecioDeVenta();
            totalPrecioNuevos += vecAutosNuevos[i].getPrecioDeVenta();

            fila++;
        }
        fila++;
    }

    /// Mostrar autos usados
    if(cantidadAutosUsados > 0)
    {
        rlutil::locate(5, fila);
        rlutil::setColor(rlutil::YELLOW);
        cout << "AUTOS USADOS:";
        fila++;

        for(int i = 0; i < cantidadAutosUsados; i++)
        {
            /// Alternar colores para las filas
            if(i % 2 == 0)
            {
                rlutil::setColor(rlutil::WHITE);
            }
            else
            {
                rlutil::setColor(rlutil::GREY);
            }

            rlutil::locate(5, fila);
            cout << "Chasis: " << vecAutosUsados[i].getPatente().getNumeroChasis();
            rlutil::locate(25, fila);
            cout << "Patente: " << vecAutosUsados[i].getPatente().getNumeroPatente();
            rlutil::locate(45, fila);
            cout << "Marca: " << vecAutosUsados[i].getMarca();
            rlutil::locate(65, fila);
            cout << "Modelo: " << vecAutosUsados[i].getModelo();
            rlutil::locate(85, fila);
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "$" << fixed << setprecision(2) << vecAutosUsados[i].getPrecioDeVenta();
            totalPrecioUsados += vecAutosUsados[i].getPrecioDeVenta();

            fila++;
        }
        fila++;
    }

    /// Resumen
    rlutil::locate(5, fila + 1);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de autos en el rango: " << (cantidadAutosNuevos + cantidadAutosUsados);

    rlutil::locate(5, fila + 2);
    cout << "Autos nuevos: " << cantidadAutosNuevos << " - Total: $" << fixed << setprecision(2) << totalPrecioNuevos;

    rlutil::locate(5, fila + 3);
    cout << "Autos usados: " << cantidadAutosUsados << " - Total: $" << fixed << setprecision(2) << totalPrecioUsados;

    rlutil::locate(5, fila + 4);
    cout << "Precio total: $" << fixed << setprecision(2) << (totalPrecioNuevos + totalPrecioUsados);

    /// Mensaje de espera
    rlutil::locate(5, fila + 6);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    /// Liberar memoria
    if(vecAutosNuevos) delete[] vecAutosNuevos;
    if(vecAutosUsados) delete[] vecAutosUsados;
}


