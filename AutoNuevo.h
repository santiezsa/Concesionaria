#pragma once
#include "Auto.h"

class AutoNuevo : public Auto
{
public:
    AutoNuevo();

    AutoNuevo(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int garantia);

    /// Getter
    int getGarantia();

    /// Setter
    void setGarantia(int garantia);

private:
    int _garantia;
};
