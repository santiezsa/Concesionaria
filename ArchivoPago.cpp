#include "ArchivoPago.h"
#include "Pago.h"
#include <iostream>
#include <cstring>

ArchivoPago::ArchivoPago()
{
    _nombreArchivo = "pagos.dat";
}

ArchivoPago::ArchivoPago(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Pago al final del archivo
bool ArchivoPago::Guardar(Pago pago)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&pago, sizeof(Pago), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Guarda un registro de Pago en una posicion espec�fica (sobrescribe)
bool ArchivoPago::Guardar(Pago pago, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Pago) * posicion, SEEK_SET);
    bool ok = fwrite(&pago, sizeof(Pago), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un pago por su ID (de venta) y retorna la posicion de su registro en el archivo
int ArchivoPago::Buscar(int idVenta)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Pago pago;
    int i = 0;
    while(fread(&pago, sizeof(Pago), 1, pArchivo))
    {
        if(pago.getIdVenta() == idVenta)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Pago en una posicion especofica
Pago ArchivoPago::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Pago();
    }
    Pago pago;
    fseek(pArchivo, sizeof(Pago) * posicion, SEEK_SET);
    fread(&pago, sizeof(Pago), 1, pArchivo);
    fclose(pArchivo);
    return pago;
}

/// Calcula y retorna la cantidad total de registros de Pago en el archivo
int ArchivoPago::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Pago);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad especifica de registros en un vector de Pago
void ArchivoPago::Leer(int cantidadRegistros, Pago *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Pago), 1, pArchivo);
    }
    fclose(pArchivo);
}


