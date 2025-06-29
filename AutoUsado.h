#pragma once
#include "Auto.h"

class AutoUsado : public Auto
{
public:
    AutoUsado();

    AutoUsado(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int kilometraje);

    /// Getter
    int getKilometraje();

    /// Setter
    void setKilometraje(int kilometraje);

    void mostrar();

    bool cargarAutoUsado();

    void mostrarAutoUsado(AutoUsado &autoUsado);

    bool modificarAutoUsado(AutoUsado &autoUsado);

    /// Listados
    void listadoAutosUsadosPorMarca();
    void listadoAutosUsadosPorModelo();
    void listadoAutosUsadosPorAnio();

private:
    int _kilometraje;
};
