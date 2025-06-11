#include "ArchivoVendedor.h"
#include "Vendedor.h"
#include <iostream>
#include <cstring>

ArchivoVendedor::ArchivoVendedor()
{
    _nombreArchivo = "vendedor.dat";
}

ArchivoVendedor::ArchivoVendedor(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Vendedor al final del archivo
bool ArchivoVendedor::Guardar(Vendedor vendedor)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Guarda un registro de Vendedor en una posicion especifica (sobrescribe)
bool ArchivoVendedor::Guardar(Vendedor vendedor, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    bool ok = fwrite(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un vendedor por su ID y retorna la posicion de su registro en el archivo
int ArchivoVendedor::Buscar(int idVendedor)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Vendedor vendedor;
    int i = 0;
    while(fread(&vendedor, sizeof(Vendedor), 1, pArchivo))
    {
        if(vendedor.getIdVendedor() == idVendedor)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Vendedor en una posicion especifica
Vendedor ArchivoVendedor::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Vendedor();
    }
    Vendedor vendedor;
    fseek(pArchivo, sizeof(Vendedor) * posicion, SEEK_SET);
    fread(&vendedor, sizeof(Vendedor), 1, pArchivo);
    fclose(pArchivo);
    return vendedor;
}

/// Calcula y retorna la cantidad total de registros de Vendedor en el archivo
int ArchivoVendedor::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Vendedor);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad espec�fica de registros en un vector de Vendedor
void ArchivoVendedor::Leer(int cantidadRegistros, Vendedor *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(Vendedor), 1, pArchivo);
    }
    fclose(pArchivo);
}


int ArchivoVendedor::buscarVendedorPorDNI(const char* _dniVendedor)
{
    Vendedor vendedor;
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(),"rb");

    if(pArchivo==nullptr)   ///NULL
    {
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&vendedor, sizeof(Vendedor),1,pArchivo)==1)
    {
        if(strcmp(vendedor.getDni(),_dniVendedor)==0)
        {
            return pos;
        }
        pos++;
    }

    fclose(pArchivo);
    return -1;
}

int ArchivoVendedor::generarIdVendedor()
{
    int cantidad = CantidadRegistros();
    int maxId = 0;
    Vendedor vendedor;

    for(int i = 0; i < cantidad; i++)
    {
        vendedor = Leer(i);
        if(vendedor.getIdVendedor() > maxId)
        {
            maxId = vendedor.getIdVendedor();
        }
    }

    return maxId + 1; /// Devuelve el siguiente ID
}

int ArchivoVendedor::buscarVendedorPorID(int _idVendedor) ///
{
    Vendedor vendedor;
    FILE *pArchivo;
    pArchivo=fopen(_nombreArchivo.c_str(),"rb");

    if(pArchivo==nullptr)   ///NULL
    {
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&vendedor, sizeof(Vendedor),1,pArchivo)==1)
    {
        if(vendedor.getIdVendedor() == _idVendedor)
        {
            return pos;
        }
        pos++;
    }

    fclose(pArchivo);
    return -1;
}
