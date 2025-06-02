#pragma once
#include <string>
#include "AutoUsado.h"

class ArchivoAutoUsado
{
    public:
        ArchivoAutoUsado(std::string nombreArchivo);
        bool Guardar(AutoUsado autoUsado);
        bool Guardar(AutoUsado autoUsado, int posicion);
        int Buscar(int idAutoUsado); ///IDAuto = NroChasis
        AutoUsado Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, AutoUsado *vec);

    private:
        std::string _nombreArchivo;
};
