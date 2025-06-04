#pragma once
#include "Fecha.h"

class Venta
{

public:
    Venta();

    Venta(int idVenta, float monto, Fecha fechaDePago, int idVendedor);

    /// Getters
    int getIdVenta();
    float getMonto();
    Fecha getFechaDePago();
    int getIdVendedor();

    /// Setters
    void setIdVenta(int idVenta);
    void setMonto(float monto);
    void setFechaDePago(Fecha fechaDePago);
    void setIdVendedor(int idVendedor);

    bool cargarPlanes(); ///Auto duplicado
    void mostrarPlanes();

private:
    int _idVenta;
    float _monto;
    Fecha _fechaDePago;
    int _idVendedor; // atributo agregado

};

