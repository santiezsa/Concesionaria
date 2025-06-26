#include "Fecha.h"

Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

std::string Fecha::toString()
{
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}

bool Fecha::esBisiesto(int anio)
{
    if(anio % 4 != 0)
    {
        return false;
    }
    if(anio % 100 != 0)
    {
        return true;
    }
    if(anio % 400 != 0)
    {
        return false;
    }
    return true;
}


bool Fecha::esValida()
{
    if(_anio < 1900 || _anio > 2026)
    {
        return false;
    }
    if(_mes < 1 || _mes > 12)
    {
        return false;
    }
    if(_dia < 1 || _dia > 31)
    {
        return false;
    }

    switch(_mes)
    {
    case 4:
    case 6:
    case 9:
    case 11:
        return _dia <= 30;
    case 2:
        if (esBisiesto(_anio))
            return _dia <= 29;
        else
            return _dia <= 28;
    default:
        return _dia <= 31;
    }
}
