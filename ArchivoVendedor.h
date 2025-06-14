#pragma once
#include <string>
#include "Vendedor.h"

class ArchivoVendedor
{
    public:
        ArchivoVendedor();
        ArchivoVendedor(std::string nombreArchivo);

        bool Guardar(Vendedor vendedor);
        bool Guardar(Vendedor vendedor, int posicion);
        int Buscar(int idVendedor);
        Vendedor Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Vendedor *vec);
        int buscarVendedorPorDNI(const char* _dniVendedor);
        int generarIdVendedor();
        int buscarVendedorPorID(int _idVendedor);

    private:
        std::string _nombreArchivo;
};
