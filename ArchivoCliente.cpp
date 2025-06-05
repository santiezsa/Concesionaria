#include "ArchivoCliente.h"

ArchivoCliente::ArchivoCliente()
{
    _nombreArchivo = "clientes.dat";
}

ArchivoCliente::ArchivoCliente(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

/// Guarda un registro de Cliente al final del archivo
bool ArchivoCliente::Guardar(Cliente cliente)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == NULL)
    {
        return false;
    }
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}

/// Guarda un registro de Cliente en una posición específica (sobrescribe)
bool ArchivoCliente::Guardar(Cliente cliente, int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == NULL)
    {
        return false;
    }
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    bool ok = fwrite(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return ok;
}


/// Busca un cliente por su ID y retorna la posición de su registro en el archivo
int ArchivoCliente::Buscar(int idCliente)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -1;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, pArchivo))
    {
        if(cliente.getIdCliente() == idCliente)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

/// Lee un registro de Cliente en una posición específica
Cliente ArchivoCliente::Leer(int posicion)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return Cliente();
    }
    Cliente cliente;
    fseek(pArchivo, sizeof(Cliente) * posicion, SEEK_SET);
    fread(&cliente, sizeof(Cliente), 1, pArchivo);
    fclose(pArchivo);
    return cliente;
}

/// Calcula y retorna la cantidad total de registros de Cliente en el archivo
int ArchivoCliente::CantidadRegistros(){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return 0;
    }
    fseek(pArchivo, 0, SEEK_END);
    int cantidadRegistros = ftell(pArchivo) / sizeof(Cliente);
    fclose(pArchivo);
    return cantidadRegistros;
}

/// Lee una cantidad específica de registros en un vector de Cliente
void ArchivoCliente::Leer(int cantidadRegistros, Cliente *vector){
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL){
        return;
    }
    for(int i = 0; i < cantidadRegistros; i++){
        fread(&vector[i], sizeof(Cliente), 1, pArchivo);
    }
    fclose(pArchivo);
}

/// Busca un cliente por su DNI y retorna la posición de su registro en el archivo
int ArchivoCliente::Buscar(char* _dniCliente)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == NULL)
    {
        return -2;
    }
    Cliente cliente;
    int i = 0;
    while(fread(&cliente, sizeof(Cliente), 1, pArchivo))
    {
        if(strcmp(cliente.getDni(),_dniCliente)==0)
        {
            fclose(pArchivo);
            return i;
        }
        i++;
    }
    fclose(pArchivo);
    return -1;
}

int ArchivoCliente::generarIdCliente()
{
    int cantidad = CantidadRegistros();
    int maxId = 0;
    Cliente cliente;

    for(int i = 0; i < cantidad; i++)
    {
        cliente = Leer(i);
        if(cliente.getIdCliente() > maxId)
        {
            maxId = vendedor.getIdCliente();
        }
    }

    return maxId + 1; /// Devuelve el siguiente ID
}
