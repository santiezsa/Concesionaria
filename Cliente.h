#pragma once
#include "Persona.h"
#include "Fecha.h"


class Cliente : public Persona
{
public:
    Cliente();

    Cliente(int idCliente, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento);

    /// Getter
    int getIdCliente();

    /// Setter
    void setIdCliente(int idCliente);

    bool cargarCliente();///Cliente duplicado
    void mostrarCliente(Cliente &cliente);
    bool modificarCliente(Cliente &cliente);

    /// Listados
    void listadoClientesPorDNI();
    void listadoClientesPorApellido();
    void listadoClientesPorFecha();

private:
    int _idCliente;
    bool fechaMayorQue(Fecha fecha1, Fecha fecha2);
};

