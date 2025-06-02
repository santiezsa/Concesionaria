#include "Pago.h"

Pago::Pago()
{
    _idVenta = 0;
    _monto = 0.0f;
    _fechaDePago = Fecha();
}

Pago::Pago(int idVenta, float monto, Fecha fechaDePago)
{
    setIdVenta(idVenta);
    setMonto(monto);
    setFechaDePago(fechaDePago);
}

/// Getters
int Pago::getIdVenta()
{
    return _idVenta;
}

float Pago::getMonto()
{
    return _monto;
}

Fecha Pago::getFechaDePago()
{
    return _fechaDePago;
}

/// Setters
/// TODO: Agregar validaciones
void Pago::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void Pago::setMonto(float monto)
{
    _monto = monto;
}

void Pago::setFechaDePago(Fecha fechaDePago)
{
    _fechaDePago = fechaDePago;
}


