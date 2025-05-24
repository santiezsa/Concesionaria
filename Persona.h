#pragma once
#include "Fecha.h"
#include "Direccion.h"


class Persona
{
public:
    Persona();
    Persona(const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento);

    /// Getters
    const char* getDni();
    const char* getNombre();
    const char* getApellido();
    Direccion getDireccion();
    const char* getNumeroTelefono();
    const char* getEmail();
    Fecha getFechaNacimiento();

    /// Setters
    void setDni(const char* dni);
    void setNombre(const char* nombre);
    void setApellido(const char* apellido);
    void setDireccion(Direccion direccion);
    void setNumeroTelefono(const char* numeroTelefono);
    void setEmail(const char* email);
    void setFechaNacimiento(Fecha fechaNacimiento);

protected:
    char _dni[12];
    char _nombre[50];
    char _apellido[50];
    Direccion _direccion;
    char _numeroTelefono[20];
    char _email[50];
    Fecha _fechaNacimiento;
};
