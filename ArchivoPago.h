#pragma once
#include <cstring>
#include "Pago.h"


class ArchivoPago
{
    public:
        ArchivoPago();
        ArchivoPago(std::string nombreArchivo);

        bool Guardar(Pago pago);
        bool Guardar(Pago pago, int posicion);
        int Buscar(int idVenta);
        Pago Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, Pago *vec);

    private:
        std::string _nombreArchivo;
};
