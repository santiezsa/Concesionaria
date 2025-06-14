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
    int dia, mes, anio;
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
                autoUsado.mostrar();
                cout << endl;
                cout << "Confirma que este es el auto que desea vender? (s/n): ";
                cin >> confirmar;
                confirmar = tolower(confirmar);

                while(confirmar != 's' && confirmar != 'n')
                {
                    cout << "Error: opcion incorrecta." << endl;
                    cout << "Confirma que este es el auto que desea vender? (s/n): ";
                    cin >> confirmar;
                    confirmar = tolower(confirmar);
                }
                if(confirmar == 'n')
                {
                    cout << "Operacion cancelada." << endl;
                    system("pause");
                    return false;
                }

                /// Obtengo el monto
                monto = autoUsado.getPrecioDeVenta();     /// TODO: Pendiente el monto de auto <---------------------------------- PRIORIDAD
                cout << endl;
                cout << "Monto a cobrar: $" << monto << endl;

                /// Pido el ID al vendedor
                cout << "Ingrese ID de vendedor: ";  /// TODO: Mostrar todos los vendedores cuando se pide el ID
                cin >> idVendedor;

                /// Pido el ID del cliente
                cout << "Ingrese ID del cliente: ";  /// TODO: Mostrar todos los clientes cuando se pide el ID
                cin >> idCliente;


                /// Ingresa la fecha de la venta
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "=== Fecha de venta ===" << endl;
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Anio: ";
                    cin >> anio;

                    fechaDeVenta = Fecha(dia, mes, anio);
                    if(!fechaDeVenta.esValida())
                    {
                        cout << "Error: Fecha invalida." << endl;
                        system("pause");
                    }
                    else
                    {
                        break;
                    }
                }

                venta = Venta(idVenta, autoUsado.getPatente(), monto, fechaDeVenta, idCliente, idVendedor);

                if(archivoVenta.Guardar(venta))
                {
                    cout << "Venta registrada exitosamente." << endl;
                    /// Marca el auto como vendido
                    autoUsado.setEstado(false);
                    archivoAutoUsado.Guardar(autoUsado, pos);
                    system("pause");
                    return true;
                }
                else
                {
                    cout << "Error al guardar la venta." << endl;
                    system("pause");
                    return false;
                }
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
}

bool Venta::cargarVentaAutoNuevo()
{

    return true;
}


