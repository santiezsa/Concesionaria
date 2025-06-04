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

        bool cargarCliente(char* _nuevoDni = (char*) "Vacio");///Cliente duplicado
        void mostrarCliente();

    private:
        int _idCliente;
};

