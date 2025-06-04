#include "Cliente.h"
#include "ArchivoCliente.h"
#include<iostream>
using namespace std;

Cliente::Cliente() : Persona()
{
    _idCliente = 0;
}

Cliente::Cliente(int idCliente, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento) : Persona(dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento)
{
    setIdCliente(idCliente);
}

/// Getter
int Cliente::getIdCliente()
{
    return _idCliente;
}

/// Setter
/// TODO: Agregar validacion
void Cliente::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

bool Cliente::cargarCliente(char* _nuevoDNI)
{
    //////TODO: Ver como hacer el IDCLIENTE automatico e incremental

    ArchivoCliente archivoCliente;
    Cliente cliente;
    char *dni;///Revisar

    if(strcmp(_nuevoDNI,"Vacio")==0)
    {
        cout << "Ingrese DNI del cliente." << endl;
        cin>>dni;
        if(archivoCliente.Buscar(dni)>=0)
        {
            cout<<"Ya existe el usuario."<<endl;
            return false;
        }
    }
    else
    {
        strcpy(dni,_nuevoDNI);
    }
    cout<<"Ingrese Apellido del cliente: ";
//    cin>>apellido;
    cout<<"Ingrese nombre del cliente: ";
//    cin>>nombre;
    cout<<"Ingrese Celular del cliente: ";
//    cin>>celular;
    return true;
}


/*if (existeDNI)
{
    cout << "Cliente existente." << endl;
    return false;
}
cout << "Ingrese nombre del cliente: " << endl;
}*/

void Cliente::mostrarCliente()
{

}
