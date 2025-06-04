#include "Venta.h"
#include <iostream>

Venta::Venta()
{
    _idVenta = 0;
    _monto = 0.0f;
    _fechaDePago = Fecha();
    _idVendedor = 0;
}
///TODO: Agregar ID Cliente, numero de chasis
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

bool Venta::cargarPlanes()///Numero de chasis
{
    ///TODO: Ver como hacer el IDVENTA automatico e incremental
//    cout << "Ingrese numero de chasis: " << endl;
    //cin >>

}

void Venta::mostrarPlanes()
{

}


