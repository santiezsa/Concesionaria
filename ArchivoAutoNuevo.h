#pragma once
#include <string>
#include "AutoNuevo.h"

class ArchivoAutoNuevo
{
    public:
        ArchivoAutoNuevo();
        ArchivoAutoNuevo(std::string nombreArchivo);
        bool Guardar(AutoNuevo autoNuevo);
        bool Guardar(AutoNuevo autoNuevo, int posicion);
        int Buscar(char idAutoNuevo[]); ///IDAuto = NroChasis
        AutoNuevo Leer(int posicion);
        int CantidadRegistros();
        void Leer(int CantidadRegistros, AutoNuevo *vec);
        void mostrarAutosNuevos();

    private:
        std::string _nombreArchivo;
};
