#pragma once

class Direccion
{

public:
    Direccion();

    Direccion(const char* calle, int altura, const char* localidad);

    /// Getters
    const char* getCalle();
    int getAltura();
    const char* getLocalidad();

    /// Setters
    void setCalle(const char* calle);
    void setAltura(int altura);
    void setLocalidad(const char* localidad);

private:
    char _calle[50];
    int _altura;
    char _localidad[50];
};
