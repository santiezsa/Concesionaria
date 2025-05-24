#include "Cliente.h"

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
