#include "ArchivoVenta.h"

ArchivoVenta::ArchivoVenta()
{
    _nombreArchivo = "ventas.dat";
}

ArchivoVenta::ArchivoVenta(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Vendedor al final del archivo
bool ArchivoVenta::Guardar(Venta venta)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Guarda un registro de Venta en una posicion especifica (sobrescribe)
bool ArchivoVenta::Guardar(Venta venta, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    bool ok = fwrite(&venta, sizeof(venta), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un vendedor por su ID y retorna la posicion de su registro en el archivo
int ArchivoVenta::Buscar(int idVenta)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Venta venta;
    int i = 0;
    while(fread(&venta, sizeof(Venta), 1, pArchivo))
    {
        if(venta.getIdVenta() == idVenta)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Venta en una posicion especifica
Venta ArchivoVenta::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Venta();
    }
    Venta venta;
    fseek(pArchivo, sizeof(Venta) * posicion, SEEK_SET);
    fread(&venta, sizeof(Venta), 1, pArchivo);
    fclose(pArchivo);
    return venta;
}

/// Calcula y retorna la cantidad total de registros de Venta en el archivo
int ArchivoVenta::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Venta);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad especifica de registros en un vector de Venta
void ArchivoVenta::Leer(int cantidadRegistros, Venta *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Venta), 1, pArchivo);
    }
    fclose(pArchivo);
}

int ArchivoVenta::generarIdVenta()
{
    int cantidad = CantidadRegistros();
    int maxId = 0;
    Venta venta;

    for(int i = 0; i < cantidad; i++)
    {
        venta = Leer(i);
        if(venta.getIdVenta() > maxId)
        {
            maxId = venta.getIdVenta();
        }
    }

    return maxId + 1; /// Devuelve el siguiente ID
}
