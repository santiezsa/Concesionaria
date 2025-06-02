#pragma once
#include "Fecha.h"


class Pago
{
    public:
        Pago();
        Pago(int idVenta, float monto, Fecha fechaDePago);

        /// Getters
        int getIdVenta();
        float getMonto();
        Fecha getFechaDePago();

        void setIdVenta(int idVenta);
        void setMonto(float monto);
        void setFechaDePago(Fecha fechaDePago);

    private:
        int _idVenta;
        float _monto;
        Fecha _fechaDePago;
};
