#include "Vendedor.h"

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
