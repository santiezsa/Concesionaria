#pragma once
#include <cstring>
#include "Cliente.h"

class ArchivoCliente
{
    public:
        ArchivoCliente();
        ArchivoCliente(std::string nombreArchivo);
        bool Guardar(Cliente cliente);
        bool Guardar(Cliente cliente, int posicion);
        int Buscar(int idCliente);
        Cliente Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Cliente *vec);
        int buscarClientePorDNI(const char* _dniCliente);
        int generarIdCliente();
        int buscarClientePorID(int _idCliente);

    private:
        std::string _nombreArchivo;
};

