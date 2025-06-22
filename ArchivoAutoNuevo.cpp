#include "ArchivoAutoNuevo.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

ArchivoAutoNuevo::ArchivoAutoNuevo()
{
    _nombreArchivo = "autonuevo.dat";
}

ArchivoAutoNuevo::ArchivoAutoNuevo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Auto al final del archivo
bool ArchivoAutoNuevo::Guardar(AutoNuevo autoNuevo)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Guarda un registro de Auto en una posici�n espec�fica (sobrescribe)
bool ArchivoAutoNuevo::Guardar(AutoNuevo autoNuevo, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(AutoNuevo) * posicion, SEEK_SET);
    bool ok = fwrite(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un Auto por su ID y retorna la posici�n de su registro en el archivo
int ArchivoAutoNuevo::Buscar(char idChasisAutoNuevo[])/// IDAuto = NroChasis
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    AutoNuevo autoNuevo;
    int i = 0;
    while(fread(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo))
    {
        if (strcmp(autoNuevo.getPatente().getNumeroChasis(), idChasisAutoNuevo) == 0)
            //if(autoNuevo.getPatente().getNumeroChasis() == idAutoNuevo) /// TODO: IDAuto = NroChasis - VALIDAR QUE NO HAYAN DOS AUTOS CON NRO DE CHASIS IGUAL
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Auto en una posici�n espec�fica
AutoNuevo ArchivoAutoNuevo::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return AutoNuevo();
    }
    AutoNuevo autoNuevo;
    fseek(pArchivo, sizeof(AutoNuevo) * posicion, SEEK_SET);
    fread(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo);
    fclose(pArchivo);
    return autoNuevo;
}

/// Calcula y retorna la cantidad total de registros de Auto en el archivo
int ArchivoAutoNuevo::CantidadRegistros()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(AutoNuevo);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad espec�fica de registros en un vector de Auto
void ArchivoAutoNuevo::Leer(int cantidadRegistros, AutoNuevo *vector)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vector[i], sizeof(AutoNuevo), 1, pArchivo);
    }
    fclose(pArchivo);
}

/// Listar todos los autos nuevos
void ArchivoAutoNuevo::mostrarAutosNuevos()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL)
    {
        return;
    }

    AutoNuevo autoNuevo;
    int i = 0;
    while (fread(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo))
    {
        std::cout << "Registro #" << i + 1 << std::endl;
        autoNuevo.mostrar();
        std::cout << "-------------------------------" << std::endl;
        i++;
    }

    if (i == 0)
    {
        std::cout << "No hay autos nuevos (0 kilometro) registrados en el archivo." << std::endl;
    }
    fclose(pArchivo);
}

void ArchivoAutoNuevo::mostrarAutosNuevosDisponibles()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return;
    }

    AutoNuevo autoNuevo;
    int i = 0;
    int contadorDisponibles = 0;

    while(fread(&autoNuevo, sizeof(AutoNuevo), 1, pArchivo))
    {
        if(autoNuevo.getEstado()) /// Si es "true" (entonces no fue vendido)
        {
            cout << "Registro #" << i + 1 << endl;
            autoNuevo.mostrar();
            cout << "-------------------------------" << endl;
            contadorDisponibles++;
        }
        i++;
    }

    if(contadorDisponibles == 0)
    {
        cout << "No hay autos nuevos disponibles para la venta." << endl;
    }
    fclose(pArchivo);
}


