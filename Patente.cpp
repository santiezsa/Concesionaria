#include "Patente.h"
#include <cstring>

Patente::Patente()
{
    strcpy(_numeroPatente, "");
    strcpy(_numeroChasis, "");
}

Patente::Patente(const char* numeroPatente, const char* numeroChasis)
{
    setNumeroPatente(numeroPatente);
    setNumeroChasis(numeroChasis);
}

/// Getters
const char* Patente::getNumeroPatente()
{
    return _numeroPatente;
}

const char* Patente::getNumeroChasis()
{
    return _numeroChasis;
}

/// Setters
/// TODO: Agregar validaciones
void Patente::setNumeroPatente(const char* numeroPatente)
{
    strcpy(_numeroPatente, numeroPatente);
}

void Patente::setNumeroChasis(const char* numeroChasis)
{
    strcpy(_numeroChasis, numeroChasis);
}
