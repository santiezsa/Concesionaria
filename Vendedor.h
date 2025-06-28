#pragma once
#include "Persona.h"
#include "Fecha.h"

class Vendedor : public Persona
{

public:
    Vendedor();

    Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento, Fecha fechaDeIngreso);

    /// Getters
    int getIdVendedor();
    Fecha getFechaDeIngreso();
    bool esMayor(Fecha fechaIngreso, Fecha fechaNacimiento);

    /// Setters
    void setIdVendedor(int idVendedor);
    void setFechaDeIngreso(Fecha fechaDeIngreso);

    bool cargarVendedor();///Vendedor duplicado
    void mostrarVendedor(Vendedor &vendedor);
    bool modificarVendedor(Vendedor &vendedor);

    /// Listados
    void listadoVendedoresPorDNI();
    void listadoVendedoresPorApellido();
    bool fechaMayorQue(Fecha fecha1, Fecha fecha2);
    void listadoVendedoresPorFechaIngreso();

private:
    int _idVendedor;
    Fecha _fechaDeIngreso;
};
