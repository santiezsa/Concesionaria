#pragma once
#include "Patente.h"


class Auto
{
    public:
        Auto();
        Auto(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta);

        /// Getters
        Patente getPatente();
        const char* getMarca();
        const char* getModelo();
        const char* getVersion();
        int getAnio();
        const char* getColor();
        float getPrecioDeVenta();

        /// Setters
        void setPatente(Patente patente);
        void setMarca(const char* marca);
        void setModelo(const char* modelo);
        void setVersion(const char* version);
        void setAnio(int anio);
        void setColor(const char* color);
        void setPrecioDeVenta(float precioDeVenta);

    protected:
        Patente _patente;
        char _marca[50];
        char _modelo[50];
        char _version[50];
        int _anio;
        char _color[20];
        float _precioDeVenta;
};


