#pragma once
#include "Persona.h"
#include "Fecha.h" // Se necesita porque Vendedor tiene un miembro Fecha

class Vendedor : public Persona
{

public:
    Vendedor();

    Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento, Fecha fechaDeIngreso);

    /// Getters
    int getIdVendedor();
    Fecha getFechaDeIngreso();

    /// Setters
    void setIdVendedor(int idVendedor);
    void setFechaDeIngreso(Fecha fechaDeIngreso);
    bool cargarVendedor();///Vendedor duplicado
    void mostrarVendedor();

private:
    int _idVendedor;
    Fecha _fechaDeIngreso;
};
