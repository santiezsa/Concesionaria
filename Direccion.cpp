#include "Direccion.h"
#include <cstring>

Direccion::Direccion()
{
    strcpy(_calle, "");
    _altura = 0;
    strcpy(_localidad, "");
}

Direccion::Direccion(const char* calle, int altura, const char* localidad)
{
    setCalle(calle);
    setAltura(altura);
    setLocalidad(localidad);
}

/// Getters
const char* Direccion::getCalle()
{
    return _calle;
}

int Direccion::getAltura()
{
    return _altura;
}

const char* Direccion::getLocalidad()
{
    return _localidad;
}

/// Setters
/// TODO: Agregar validaciones
void Direccion::setCalle(const char* calle)
{
    strcpy(_calle, calle);
}

void Direccion::setAltura(int altura)
{
    _altura = altura;
}

void Direccion::setLocalidad(const char* localidad)
{
    strcpy(_localidad, localidad);
}
