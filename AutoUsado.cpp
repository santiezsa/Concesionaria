#include "AutoUsado.h"
#include <iostream>

AutoUsado::AutoUsado() : Auto()
{
    _kilometraje = 0;
}

AutoUsado::AutoUsado(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int kilometraje) : Auto(patente, marca, modelo, version, anio, color, precioDeVenta, true) // Llama al constructor de Auto
{
    setKilometraje(kilometraje);
}

/// Getter
int AutoUsado::getKilometraje()
{
    return _kilometraje;
}

/// Setter
void AutoUsado::setKilometraje(int kilometraje)
{
    _kilometraje = kilometraje;
}

void AutoUsado::mostrar()
{
    mostrar();
    std::cout << "Kilometraje: " << getKilometraje() << std::endl;

}
