#pragma once
#include <string>
#include "AutoUsado.h"

class ArchivoAutoUsado
{
    public:
        ArchivoAutoUsado();
        ArchivoAutoUsado(std::string nombreArchivo);
        bool Guardar(AutoUsado autoUsado);
        bool Guardar(AutoUsado autoUsado, int posicion);
        int Buscar(char idAutoUsado[]); ///IDAuto = NroChasis
        AutoUsado Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, AutoUsado *vec);

        void mostrarAutosUsados();

    private:
        std::string _nombreArchivo;
};
