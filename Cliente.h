#pragma once
#include "Persona.h"


class Cliente : public Persona
{
    public:
        Cliente();

        Cliente(int idCliente, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento);

        /// Getter
        int getIdCliente();

        /// Setter
        void setIdCliente(int idCliente);

    private:
        int _idCliente;
};

