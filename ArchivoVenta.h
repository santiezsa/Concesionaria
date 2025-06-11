#pragma once
#include <string>
#include "Venta.h"

class ArchivoVenta
{
    public:
        ArchivoVenta();
        ArchivoVenta(std::string nombreArchivo);

        bool Guardar(Venta venta);
        bool Guardar(Venta venta, int posicion);
        int Buscar(int idVenta);
        Venta Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Venta *vec);
        int generarIdVenta();

    private:
        std::string _nombreArchivo;
};

