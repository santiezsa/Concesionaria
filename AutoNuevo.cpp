#include "AutoNuevo.h"

AutoNuevo::AutoNuevo() : Auto()
{
    _garantia = 0;
}

AutoNuevo::AutoNuevo(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int garantia) : Auto(patente, marca, modelo, version, anio, color, precioDeVenta) // Llama al constructor de Auto
{
    setGarantia(garantia);
}

/// Getter
int AutoNuevo::getGarantia() {
    return _garantia;
}

/// Setter
void AutoNuevo::setGarantia(int garantia) {
    _garantia = garantia;
}
