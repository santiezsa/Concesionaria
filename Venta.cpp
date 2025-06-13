#include "Venta.h"
#include "Menu.h"
#include "ArchivoVenta.h"
#include "ArchivoAutoUsado.h"
#include <iostream>
#include <cstring>

using namespace std;


Venta::Venta()
{
    _idVenta = 0;
    _patente = Patente();
    _monto = 0.0f;
    _fechaDeVenta = Fecha();
    _idCliente = 0;
    _idVendedor = 0;
}

///TODO: Agregar ID Cliente, numero de chasis
Venta::Venta(int idVenta, Patente patente, float monto, Fecha fechaDeVenta, int idCliente, int idVendedor)
{
    setIdVenta(idVenta);
    setPatente(patente);
    setMonto(monto);
    setFechaDeVenta(fechaDeVenta);
    setIdCliente(idCliente);
    setIdVendedor(idVendedor);
}

/// Getters
int Venta::getIdVenta()
{
    return _idVenta;
}

Patente Venta::getPatente()
{
    return _patente;
}

float Venta::getMonto()
{
    return _monto;
}

Fecha Venta::getFechaDeVenta()
{
    return _fechaDeVenta;
}

int Venta::getIdCliente()
{
    return _idCliente;
}

int Venta::getIdVendedor()
{
    return _idVendedor;
}

/// Setters
/// TODO: Agregar validaciones
void Venta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void Venta::setPatente(Patente patente)
{
    _patente = patente;
}

void Venta::setMonto(float monto)
{
    _monto = monto;
}

void Venta::setFechaDeVenta(Fecha fechaDeVenta)
{
    _fechaDeVenta = fechaDeVenta;
}

void Venta::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Venta::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

bool Venta::cargarVentaAutoUsado()
{
    Menu menu;
    Venta venta;
    AutoUsado autoUsado;
    int idVenta;
    //char numeroPatente[10];
    char numeroChasis[10];
    Patente patente;
    float monto;
    Fecha fechaDeVenta;
    int idCliente;
    int idVendedor;

    char confirmar;

    ArchivoVenta archivoVenta;
    ArchivoAutoUsado archivoAutoUsado;

    /// Genero ID de venta
    idVenta = archivoVenta.generarIdVenta();


    /// TODO: Desactivar autos ya vendidos (de manera automatica)
    /// Verificar que no haya patentes iguales -> No deberia suceder si se cumple lo anterior

    if(archivoAutoUsado.CantidadRegistros() != 0)
    {
    cout << "=== LISTADO DE AUTOS USADOS DISPONIBLES ===" << endl;
    archivoAutoUsado.mostrarAutosUsados();
    cout << "===========================================" << endl;
    cout << endl;

    cin.ignore();
    while(true)
    {
        cout << "Ingrese el numero de chasis deseado: ";
        cin.getline(numeroChasis, sizeof(numeroChasis));

        if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 11)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error. Ingrese un numero de chasis valido." << endl;
            system("pause");
        }
        else if(!(archivoAutoUsado.Buscar(numeroChasis) >= 0))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: opcion incorrecta." << endl;
                cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if(confirmar == 's')
            {
                cin.ignore();
                /// Busco informacion del auto en base al numero de chasis
                int pos = archivoAutoUsado.Buscar(numeroChasis);
                autoUsado = archivoAutoUsado.Leer(pos); /// Devuelve el objeto auto usado
                ///monto = getAutoUsado(); /// TODO: Pendiente el monto de auto <---------------------------------- PRIORIDAD

                /// Pido el ID al vendedor:

                /// Busco el ID del cliente:

                /// Ingresa la fecha de la operacion

                /// Muestro el monto a cobrar

                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
    }
    else
    {
        cout << "No se registraron autos usados." << endl;
        system("pause");
        return false;
    }
    ///Venta(int idVenta, Patente patente, float monto, Fecha fechaDeVenta, int idCliente, int idVendedor)
    ///return true;
}

bool Venta::cargarVentaAutoNuevo()
{

    return true;
}


