#include "Venta.h"

Venta::Venta()
{
    _idVenta = 0;
    _monto = 0.0f;
    _fechaDePago = Fecha();
    _idVendedor = 0;
}

Venta::Venta(int idVenta, float monto, Fecha fechaDePago, int idVendedor)
{
    setIdVenta(idVenta);
    setMonto(monto);
    setFechaDePago(fechaDePago);
    setIdVendedor(idVendedor);
}

/// Getters
int Venta::getIdVenta()
{
    return _idVenta;
}

float Venta::getMonto()
{
    return _monto;
}

Fecha Venta::getFechaDePago()
{
    return _fechaDePago;
}

int Venta::getIdVendedor()
{
    return _idVendedor;
}

/// Setters
/// TODO: Agregar validaciones
void Venta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void Venta::setMonto(float monto)
{
    _monto = monto;
}

void Venta::setFechaDePago(Fecha fechaDePago)
{
    _fechaDePago = fechaDePago;
}

void Venta::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}






