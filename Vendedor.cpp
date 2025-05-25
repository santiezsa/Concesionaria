#include "Vendedor.h"

Vendedor::Vendedor()
{
    _idVendedor = 0;
}

Vendedor::Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento) : Persona(dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento)
{
    setIdVendedor(idVendedor);
}

/// Getter
int Vendedor::getIdVendedor()
{
    return _idVendedor;
}

/// Setter
/// TODO: Agregar validacion
void Vendedor::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}
