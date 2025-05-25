#include "Auto.h"
#include <cstring>


Auto::Auto()
{
    _patente = Patente();
    strcpy(_marca, "");
    strcpy(_modelo, "");
    strcpy(_version, "");
    _anio = 0;
    strcpy(_color, "");
    _precioDeVenta = 0.0f;
}

Auto::Auto(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta)
{
    setPatente(patente);
    setMarca(marca);
    setModelo(modelo);
    setVersion(version);
    setAnio(anio);
    setColor(color);
    setPrecioDeVenta(precioDeVenta);
}

/// Getters
Patente Auto::getPatente()
{
    return _patente;
}

const char* Auto::getMarca()
{
    return _marca;
}

const char* Auto::getModelo()
{
    return _modelo;
}

const char* Auto::getVersion()
{
    return _version;
}

int Auto::getAnio()
{
    return _anio;
}

const char* Auto::getColor()
{
    return _color;
}

float Auto::getPrecioDeVenta()
{
    return _precioDeVenta;
}

/// Setters
/// TODO: Agregar validaciones
void Auto::setPatente(Patente patente)
{
    _patente = patente;
}

void Auto::setMarca(const char* marca)
{
    strcpy(_marca, marca);
}

void Auto::setModelo(const char* modelo)
{
    strcpy(_modelo, modelo);
}

void Auto::setVersion(const char* version)
{
    strcpy(_version, version);
}

void Auto::setAnio(int anio)
{
    _anio = anio;
}

void Auto::setColor(const char* color)
{
    strcpy(_color, color);
}

void Auto::setPrecioDeVenta(float precioDeVenta)
{
    _precioDeVenta = precioDeVenta;
}
