#include "Persona.h"
#include <cstring> // para usar strcpy

Persona::Persona()
{
    strcpy(_dni, "");
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    _direccion = Direccion();
    strcpy(_numeroTelefono, "");
    strcpy(_email, "");
    _fechaNacimiento = Fecha();
}

Persona::Persona(const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento)
{
    setDni(dni);
    setNombre(nombre);
    setApellido(apellido);
    setDireccion(direccion);
    setNumeroTelefono(numeroTelefono);
    setEmail(email);
    setFechaNacimiento(fechaNacimiento);
}

/// Getters
const char* Persona::getDni()
{
    return _dni;
}

const char* Persona::getNombre()
{
    return _nombre;
}

const char* Persona::getApellido()
{
    return _apellido;
}

Direccion Persona::getDireccion()
{
    return _direccion;
}

const char* Persona::getNumeroTelefono()
{
    return _numeroTelefono;
}

const char* Persona::getEmail()
{
    return _email;
}

Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}

/// Setters
/// TODO: Pendiente agregar validaciones
void Persona::setDni(const char* dni)
{
    strcpy(_dni, dni);
}

void Persona::setNombre(const char* nombre)
{
    strcpy(_nombre, nombre);
}

void Persona::setApellido(const char* apellido)
{
    strcpy(_apellido, apellido);
}

void Persona::setDireccion(Direccion direccion)
{
    _direccion = direccion;
}

void Persona::setNumeroTelefono(const char* numeroTelefono)
{
    strcpy(_numeroTelefono, numeroTelefono);
}

void Persona::setEmail(const char* email)
{
    strcpy(_email, email);
}

void Persona::setFechaNacimiento(Fecha fechaNacimiento)
{
    _fechaNacimiento = fechaNacimiento;
}

