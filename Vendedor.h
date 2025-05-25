#pragma once
#include "Persona.h"

class Vendedor : public Persona
{
    public:
        Vendedor();
        Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento);

        /// Getter
        int getIdVendedor();

        /// Setter
        void setIdVendedor(int idVendedor);
    private:
        int _idVendedor;
};
