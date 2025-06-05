#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include <iostream>
#include <cstring>

using namespace std;

Vendedor::Vendedor()
{
    _idVendedor = 0;
    _fechaDeIngreso = Fecha();
}

Vendedor::Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento, Fecha fechaDeIngreso) : Persona(dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento)
{
    setIdVendedor(idVendedor);
    setFechaDeIngreso(fechaDeIngreso);
}

/// Getter
int Vendedor::getIdVendedor()
{
    return _idVendedor;
}

Fecha Vendedor::getFechaDeIngreso()
{
    return _fechaDeIngreso;
}

/// Setters
/// TODO: Agregar validacion
void Vendedor::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

void Vendedor::setFechaDeIngreso(Fecha fechaDeIngreso)
{
    _fechaDeIngreso = fechaDeIngreso;
}

bool Vendedor::cargarVendedor()
{
    int idVendedor;
    char dni[12];
    char nombre[50];
    char apellido[50];
    char numeroTelefono[20];
    char email[50];
    char calle[50];
    int altura;
    char localidad[50];
    int dia, mes, anio;
    Fecha fechaNacimiento, fechaDeIngreso;

    ArchivoVendedor archivoVendedor;

    /// Carga DNI
    while(true)
    {
        cout << "Ingrese DNI del vendedor: ";
        cin.ignore();
        cin.getline(dni, sizeof(dni));

        if(archivoVendedor.buscarVendedor(dni) >= 0)  /// si cuenta y encuentra el registro
        {
            cout << "Error: Ya existe un vendedor con ese DNI." << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga nombre
    while(true)
    {
        cout << "Ingrese nombre: ";
        cin.getline(nombre, sizeof(nombre));
        if(strlen(nombre) == 0)
        {
            cout << "Error: El nombre no puede estar vacio." << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga apellido
    while(true)
    {
        cout << "Ingrese apellido: ";
        cin.getline(apellido, sizeof(apellido));
        if(strlen(apellido) == 0)
        {
            cout << "Error: El apellido no puede estar vacio." << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga email
    while(true)
    {
        cout << "Ingrese email: ";
        cin.getline(email, sizeof(email));
        if(strlen(email) == 0)
        {
            cout << "Error: el email no puede estar vacio." << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga direccion
    while(true)
    {
        cout << "Ingrese calle: ";
        cin.getline(calle, sizeof(calle));
        if(strlen(calle) == 0)
        {
            cout << "Error: La calle no puede estar vacia" << endl;
        }
        else
        {
            break;
        }
    }

    while(true)
    {
        cout << "Ingrese altura: ";
        cin >> altura;
        if(altura <= 0)
        {
            cout << "Error: La altura debe ser mayor a cero" << endl;
        }
        else
        {
            break;
        }
    }

    while(true)
    {
        cout << "Ingrese localidad: ";
        cin.ignore();
        cin.getline(localidad, sizeof(localidad));
        if(strlen(localidad) == 0)
        {
            cout << "Error: La localidad no puede estar vacia" << endl;
        }
        else
        {
            break;
        }
    }

    Direccion direccion(calle, altura, localidad);

    /// Carga telefono
    while(true)
    {
        cout << "Ingrese numero de telefono: ";
        cin.getline(numeroTelefono, sizeof(numeroTelefono));
        if(strlen(numeroTelefono) == 0)
        {
            cout << "Error: el numero de telefono no puede estar vacio" << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga fecha de nacimiento
    while(true)
    {
        cout << "== Fecha de nacimiento ===" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        fechaNacimiento = Fecha(dia, mes, anio);
        if(!fechaNacimiento.esValida())
        {
            cout << "Error: Fecha de nacimiento invalida" << endl;
        }
        else
        {
            break;
        }
    }

    /// Carga fecha de ingreso
       while(true)
    {
        cout << "== Fecha de ingreso ===" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        fechaDeIngreso = Fecha(dia, mes, anio);
        if(!fechaDeIngreso.esValida())
        {
            cout << "Error: Fecha de ingreso invalida" << endl;
        }
        else
        {
            break;
        }
    }

    /// Genero ID del vendedor (automatico)
    idVendedor = archivoVendedor.generarIdVendedor();

    /// Guardo datos
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setDireccion(direccion);
    setNumeroTelefono(numeroTelefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
    setIdVendedor(idVendedor);
    setFechaDeIngreso(fechaDeIngreso);

    return true;
}


    void Vendedor::mostrarVendedor()
{

}
