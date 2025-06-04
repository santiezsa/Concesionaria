#include "ArchivoAutoUsado.h"
#include <string>
#include <cstring>

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


/// Busca un Auto por su ID y retorna la posición de su registro en el archivo
int ArchivoAutoUsado::Buscar(char idChasisAutoUsado[])/// IDAuto = NroChasis
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
        //if(autoUsado.getPatente().getNumeroChasis == idAutoUsado) /// TODO: IDAuto = NroChasis - VALIDAR QUE NO HAYAN DOS AUTOS CON NRO DE CHASIS IGUAL
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
