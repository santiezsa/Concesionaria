#pragma once
#include "Patente.h"


class Auto
{
    public:
        Auto();
        Auto(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, bool estado);

        /// Getters
        Patente getPatente();
        const char* getMarca();
        const char* getModelo();
        const char* getVersion();
        int getAnio();
        const char* getColor();
        float getPrecioDeVenta();
        bool getEstado();

        /// Setters
        void setPatente(Patente patente);
        void setMarca(const char* marca);
        void setModelo(const char* modelo);
        void setVersion(const char* version);
        void setAnio(int anio);
        void setColor(const char* color);
        void setPrecioDeVenta(float precioDeVenta);
        void setEstado(bool estado);

        void mostrar();

    protected:
        Patente _patente;
        char _marca[50];
        char _modelo[50];
        char _version[50];
        int _anio;
        char _color[20];
        float _precioDeVenta;
        bool _estado;
};


