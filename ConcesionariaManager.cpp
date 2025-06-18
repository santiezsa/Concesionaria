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

        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del cliente: ";
            cin >> idCliente;

            if (cin.fail()) // Si la entrada es inválida
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
                break; // Si la entrada es válida, salir del bucle
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

        while (true) // Bucle infinito hasta que se ingrese un valor válido
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese ID del vendedor: ";
            cin >> idVendedor;

            if (cin.fail()) // Si la entrada es inválida
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
                break; // Si la entrada es válida, salir del bucle
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

/* ------------------ Seccion VENTAS ------------------ */

/* ****************** AUTOS NUEVOS ****************** */

bool ConcesionariaManager::modificarVentaAutoNuevo()
{
    Menu menu;
    char opcion;
    bool confirmarTodo = false;
    int idVenta;
    ArchivoVenta archivoVenta;
    Venta venta;
    int pos;
    AutoNuevo autoNuevo;

    // Pedir ID de la venta
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese el ID de la venta a modificar: ";
        cin >> idVenta;

        pos = archivoVenta.Buscar(idVenta);
        if(pos == -1)
        {
            cout << "Error: No existe una venta con ese ID." << endl;
            system("pause");
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
        cout << "Monto: $" << venta.getMonto() << endl;
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
            if(venta.getEstado() == true)
            {
                venta.setEstado(false);
                cout << "Estado de la venta actualizado a: INACTIVA" << endl;
                // Si la venta se desactiva, el auto vuelve a estar disponible
                autoNuevo.setEstado(true);
            }
            else
            {
                venta.setEstado(true);
                cout << "Estado de la venta actualizado a: ACTIVA" << endl;
                // Si la venta se activa, el auto se marca como vendido
                autoNuevo.setEstado(false);
            }
            // Guardar los cambios
            archivoVenta.Guardar(venta, pos);
            system("pause");
            confirmarTodo = true;
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
    Venta venta;
    int pos;
    AutoUsado autoUsado;

    // Pedir ID de la venta
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese el ID de la venta a modificar: ";
        cin >> idVenta;

        pos = archivoVenta.Buscar(idVenta);
        if(pos == -1)
        {
            cout << "Error: No existe una venta con ese ID." << endl;
            system("pause");
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
        cout << "Monto: $" << venta.getMonto() << endl;
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
            if(venta.getEstado() == true)
            {
                venta.setEstado(false);
                cout << "Estado de la venta actualizado a: INACTIVA" << endl;
                // Si la venta se desactiva, el auto vuelve a estar disponible
                autoUsado.setEstado(true);
            }
            else
            {
                venta.setEstado(true);
                cout << "Estado de la venta actualizado a: ACTIVA" << endl;
                // Si la venta se activa, el auto se marca como vendido
                autoUsado.setEstado(false);
            }
            // Guardar los cambios
            archivoVenta.Guardar(venta, pos);
            system("pause");
            confirmarTodo = true;
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
    cin.ignore();

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del auto a modificar: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if(!(archivoAutoNuevo.Buscar(numeroDeChasis) >= 0))  /// si cuenta y NO encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un auto con ese numero de chasis." << endl;
            system("pause");
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
                cout << "Desea confirmar? (s/n)" << endl;
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
    ArchivoAutoNuevo archivoAutoNuevo;
    AutoNuevo autoNuevo;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del vehiculo: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if(!(archivoAutoNuevo.Buscar(numeroDeChasis) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
            system("pause");
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
        break;
    }

}

/* ****************** AUTOS USADOS ****************** */


void ConcesionariaManager::modificarAutoUsado()
{

}

void ConcesionariaManager::buscarAutoUsadoPorNumeroDeChasis()
{
    char numeroDeChasis[10];
    char confirmar;
    ArchivoAutoUsado archivoAutoUsado;
    AutoUsado autoUsado;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de chasis del vehiculo: ";
        cin.getline(numeroDeChasis, sizeof(numeroDeChasis));

        if(!(archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroDeChasis) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
            system("pause");
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
        break;
    }

}

void ConcesionariaManager::buscarAutoUsadoPorNumeroDePatente()
{
    char numeroDePatente[10];
    char confirmar;
    ArchivoAutoUsado archivoAutoUsado;
    AutoUsado autoUsado;
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de patente del vehiculo: ";
        cin.getline(numeroDePatente, sizeof(numeroDePatente));

        if(!(archivoAutoUsado.BuscarAutoUsadoPorNumeroDePatente(numeroDePatente) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de patente." << endl;
            system("pause");
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
                cout << "El numero de patente ingresado es " << numeroDePatente << ". Es correcto? (s/n) " << endl;s
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
        break;
    }

}

void ConcesionariaManager::buscarVentaAutoUsadoPorNumeroChasis()
{

}

void ConcesionariaManager::buscarVentaAutoUsadoPorIDVenta()
{

}














