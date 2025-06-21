#pragma once
#include "AutoNuevo.h"
#include "AutoUsado.h"

class ConcesionariaManager
{
public:

    /// Seccion Clientes
    void modificarCliente();
    void buscarClientePorDNI();
    void buscarClientePorID();

    /// Seccion Vendedores
    void modificarVendedor();
    void buscarVendedorPorDNI();
    void buscarVendedorPorID();

    /// Seccion Ventas
    bool modificarVentaAutoNuevo();
    bool modificarVentaAutoUsado();

    void buscarVentaAutoNuevoPorNumeroChasis();
    void buscarVentaAutoNuevoPorIDVenta();
    void buscarVentaAutoUsadoPorNumeroChasis();
    void buscarVentaAutoUsadoPorIDVenta();

    /// Seccion Autos
    void buscarAutoNuevoPorNumeroDeChasis();
    void modificarAutoNuevo();

    void buscarAutoUsadoPorNumeroDeChasis();
    void buscarAutoUsadoPorNumeroDePatente();
    void modificarAutoUsado();

private:
};
