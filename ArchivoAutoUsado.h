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
    ///int Buscar(char idAutoUsado[]); ///IDAuto = NroChasis
    int BuscarAutoUsadoPorNumeroDeChasis(char idChasisAutoUsado[]);
    int BuscarAutoUsadoPorNumeroDePatente(char idPatenteAutoUsado[]);
    AutoUsado Leer(int posicion);
    int CantidadRegistros();
    void Leer(int CantidadRegistros, AutoUsado *vec);

    void mostrarAutosUsados();
    void mostrarAutosUsadosDisponibles(); // Solo autos con estado = true

    /// Listados
    void listadoAutosUsadosPorMarca();
    void listadoAutosUsadosPorModelo();
    void listadoAutosUsadosPorAnio();

private:
    std::string _nombreArchivo;
};
