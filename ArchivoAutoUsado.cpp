#include "ArchivoAutoUsado.h"
#include <string>
#include <cstring>
#include <iostream>

ArchivoAutoUsado::ArchivoAutoUsado()
{
    _nombreArchivo = "autousado.dat";
}

ArchivoAutoUsado::ArchivoAutoUsado(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Auto al final del archivo
bool ArchivoAutoUsado::Guardar(AutoUsado autoUsado)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&autoUsado, sizeof(AutoUsado), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Guarda un registro de Auto en una posición específica (sobrescribe)
bool ArchivoAutoUsado::Guardar(AutoUsado autoUsado, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(AutoUsado) * posicion, SEEK_SET);
    bool ok = fwrite(&autoUsado, sizeof(AutoUsado), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un Auto por su numero de chasis y retorna la posición de su registro en el archivo
int ArchivoAutoUsado::BuscarAutoUsadoPorNumeroDeChasis(char idChasisAutoUsado[])
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    AutoUsado autoUsado;
    int i = 0;
    while(fread(&autoUsado, sizeof(AutoUsado), 1, pArchivo))
    {
        if (strcmp(autoUsado.getPatente().getNumeroChasis(), idChasisAutoUsado) == 0)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Busca un Auto por su numero de patente y retorna la posición de su registro en el archivo
int ArchivoAutoUsado::BuscarAutoUsadoPorNumeroDePatente(char idPatenteAutoUsado[])
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    AutoUsado autoUsado;
    int i = 0;
    while(fread(&autoUsado, sizeof(AutoUsado), 1, pArchivo))
    {
        if (strcmp(autoUsado.getPatente().getNumeroPatente(), idPatenteAutoUsado) == 0)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Auto en una posición específica
AutoUsado ArchivoAutoUsado::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return AutoUsado();
    }
    AutoUsado autoUsado;
    fseek(pArchivo, sizeof(AutoUsado) * posicion, SEEK_SET);
    fread(&autoUsado, sizeof(AutoUsado), 1, pArchivo);
    fclose(pArchivo);
    return autoUsado;
}

/// Calcula y retorna la cantidad total de registros de Auto en el archivo
int ArchivoAutoUsado::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(AutoUsado);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad específica de registros en un vector de Auto
void ArchivoAutoUsado::Leer(int cantidadRegistros, AutoUsado *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(AutoUsado), 1, pArchivo);
    }
    fclose(pArchivo);
}

/// Listar todos los autos usados
void ArchivoAutoUsado::mostrarAutosUsados()
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if (pArchivo == NULL)
    {
        return;
    }

    AutoUsado autoUsado;
    int i = 0;
    std::cout << "=== Listado de Autos Usados ===" << std::endl;
    while (fread(&autoUsado, sizeof(AutoUsado), 1, pArchivo))
    {
        std::cout << "Registro #" << i + 1 << std::endl;
        autoUsado.mostrar();
        std::cout << "-------------------------------" << std::endl;
        i++;
    }

    if (i == 0) {
        std::cout << "No hay autos usados registrados en el archivo." << std::endl;
    }
    fclose(pArchivo);
}
