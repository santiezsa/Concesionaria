#pragma once
#include "Fecha.h"
#include "Patente.h"

class Venta
{
public:
    Venta();

    Venta(int idVenta, Patente patente, float monto, Fecha fechaDeVenta, int idCliente, int idVendedor);

    /// Getters
    int getIdVenta();
    Patente getPatente();
    float getMonto();
    Fecha getFechaDeVenta();
    int getIdCliente();
    int getIdVendedor();

    /// Setters
    void setIdVenta(int idVenta);
    void setPatente(Patente patente);
    void setMonto(float monto);
    void setFechaDeVenta(Fecha fechaDeVenta);
    void setIdCliente(int idCliente);
    void setIdVendedor(int idVendedor);

    bool cargarVentaAutoNuevo();
    bool cargarVentaAutoUsado();


private:
    int _idVenta;
    Patente _patente;
    float _monto;
    Fecha _fechaDeVenta;
    int _idCliente;
    int _idVendedor;
};
