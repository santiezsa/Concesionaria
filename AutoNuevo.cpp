#include <iostream>
#include "Menu.h"
#include "AutoNuevo.h"
#include "ArchivoAutoNuevo.h"
#include "ArchivoAutoUsado.h"
#include <cstring>
#include <iomanip>
#include <limits>
using namespace std;


AutoNuevo::AutoNuevo() : Auto()
{
    _garantia = 0;
}

AutoNuevo::AutoNuevo(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int garantia) : Auto(patente, marca, modelo, version, anio, color, precioDeVenta, true) // Llama al constructor de Auto
{
    setGarantia(garantia);
}

/// Getter
int AutoNuevo::getGarantia()
{
    return _garantia;
}

/// Setter
void AutoNuevo::setGarantia(int garantia)
{
    _garantia = garantia;
}


bool AutoNuevo::cargarAutoNuevo()
{

    Menu menu;
    char confirmar;
    char numeroChasis[10];
    char numeroPatente[10];
    strcpy(numeroPatente, "");
    char marca[50];
    char modelo[50];
    char version[50];
    int anio;
    char color[20];
    float precioVenta;
    int garantia;

    ArchivoAutoNuevo archivoAutoNuevo;
    ArchivoAutoUsado archivoAutoUsado;

    /// Carga NUMERO CHASIS (id)
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese el numero de chasis del auto 0km: ";
        cin.getline(numeroChasis, sizeof(numeroChasis));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(numeroChasis) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error. Ingrese un numero de chasis valido." << endl;
            system("pause");
        }
        else if(archivoAutoNuevo.Buscar(numeroChasis) >= 0 || archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis) >= 0)  /// Valida chasis tanto en archivo auto nuevo y archivo auto usado
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ya existe un auto con ese numero de chasis." << endl;
            cout << "Desea cargar un auto nuevo? (s/n)" << endl;
            cin >> cargarOtro;
            cargarOtro = tolower(cargarOtro);
            while(cargarOtro != 's' && cargarOtro != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea cargar un auto nuevo? (s/n)" << endl;
                cin >> cargarOtro;
                cargarOtro = tolower(cargarOtro);
            }

            switch(cargarOtro)
            {
            case 's':
                cin.ignore();
                break;
            case 'n':
                return false;

            default:
                cout << "No deberia esta aca." << endl;
                system("pause");
            }
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El chasis ingresado es " << numeroChasis << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El chasis ingresado es " << numeroChasis << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }
    Patente patente(numeroPatente, numeroChasis);

    /// Carga marca
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese marca: ";
        cin.getline(marca, sizeof(marca));
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(marca) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese una marca valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La marca ingresada es " << marca << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "La marca ingresada es " << marca << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Carga modelo
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese modelo: ";
        cin.getline(modelo, sizeof(modelo));
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if(strlen(modelo) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un modelo valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El modelo ingresado es " << modelo << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El modelo ingresado es " << modelo << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Carga version
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese version: ";
        cin.getline(version, sizeof(version));
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if(strlen(version) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese una version valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La version ingresada es " << version << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "La version ingresada es " << version << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Carga anio
    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese anio: ";
            cin >> anio;
            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }
        if(anio < 1900 || anio > 2025)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un anio valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El anio ingresado es " << anio << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El anio ingresado es " << anio << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    ///Carga color
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese color: ";
        cin.getline(color, sizeof(color));
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }

        else if(strlen(color) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un color valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El color ingresado es " << color << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El color ingresado es " << color << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Carga precio de venta
    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese el precio de venta del auto: ";
            cin >> precioVenta;
            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }
        if(precioVenta < 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: El precio de venta debe ser mayor a cero." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El precio de venta del auto ingresado es $" << fixed << setprecision(2) << precioVenta << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El precio de venta del auto ingresado es $" << fixed << setprecision(2) << precioVenta << ". Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Carga garantia
    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese anios de garantia: ";
            cin >> garantia;
            if (cin.fail()) // Si la entrada es inválida
            {
                system("cls");
                menu.mostrarLogo();
                cin.clear(); // Limpia el estado de error
                cin.ignore(1000, '\n'); // Descartar caracteres incorrectos
                cout << "Entrada invalida. Intente nuevamente." << endl;
                system("pause");
            }
            else
            {
                break; // Si la entrada es válida, salir del bucle
            }
        }
        if(garantia < 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese anios de garantia validos." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Los anios de garantia ingresados son: " << garantia << " anios. Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Los anios de garantia ingresados es " << garantia << "anios. Es correcto? (s/n) " << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
            }
            if (confirmar == 's')
            {
                cin.ignore();
                break;
            }
            else
            {
                cin.ignore();
            }
        }
    }

    /// Guardo datos
    AutoNuevo autoNuevo(patente, marca, modelo, version, anio, color, precioVenta, garantia);


    /// Valido datos con el usuario

    if(!modificarAutoNuevo(autoNuevo))
    {
        return false;
    }


    if(archivoAutoNuevo.Guardar(autoNuevo))
    {
        cout << "Auto registrado exitosamente." << endl;
        return true;
    }
    else
    {
        cout << "No se pudo registrar el auto." << endl;
        return false;
    }
}

void AutoNuevo::mostrarAutoNuevo(AutoNuevo &autoNuevo)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "Numero de chasis: " << autoNuevo.getPatente().getNumeroChasis() << endl;
    cout << "Patente: " << autoNuevo.getPatente().getNumeroPatente() << endl;
    cout << "Marca: " << autoNuevo.getMarca() << endl;
    cout << "Modelo: " << autoNuevo.getModelo() << endl;
    cout << "Version: " << autoNuevo.getVersion() << endl;
    cout << "Anio: " << autoNuevo.getAnio() << endl;
    cout << "Color: " << autoNuevo.getColor() << endl;
    cout << "Precio de venta: $" << fixed << setprecision(0) << autoNuevo.getPrecioDeVenta() << endl;
    cout << "Garantia: " << autoNuevo.getGarantia() << " anios" << endl;
}

bool AutoNuevo::modificarAutoNuevo(AutoNuevo &autoNuevo)
{
    Menu menu;
    Patente patente;
    char opcion;
    bool confirmarTodo = false;
    char numeroChasis[10];
    char numeroPatente[10];
    strcpy(numeroPatente, "");
    char marca[50];
    char modelo[50];
    char version[50];
    int anio;
    char color[20];
    float precioVenta;
    int garantia;

    ArchivoAutoNuevo archivoAutoNuevo;

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DEL AUTO ===" << endl;
        mostrarAutoNuevo(autoNuevo);
        cout << endl;
        cout << "Los datos son correctos? (s/n): ";
        cin >> opcion;
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << "=== DATOS DEL AUTO ===" << endl;
            mostrarAutoNuevo(autoNuevo);
            cout << endl;
            cout << "Los datos son correctos? (s/n): " << endl;
            cin >> opcion;
            opcion = tolower(opcion);
        }

        if(opcion == 's')
        {
            confirmarTodo = true;
        }
        else if(opcion == 'n')
        {
            int opcionModificar;
            while(true)
            {
                cout << endl;
                cout << "Que campo desea modificar?" << endl;
                cout << "1 - Numero de chasis" << endl;
                cout << "2 - Marca" << endl;
                cout << "3 - Modelo" << endl;
                cout << "4 - Version" << endl;
                cout << "5 - Anio" << endl;
                cout << "6 - Color" << endl;
                cout << "7 - Precio de venta" << endl;
                cout << "8 - Garantia" << endl;
                cout << "9 - Cancelar y volver a cargar todo" << endl;

                cin >> opcionModificar;
                if (cin.fail())
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "=== DATOS DEL AUTO ===" << endl;
                    mostrarAutoNuevo(autoNuevo);
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Entrada invalida. Intente nuevamente." << endl;
                    system("pause");
                }
                else
                {
                    break;
                }
            }

            cin.ignore();

            switch(opcionModificar)
            {
            case 1:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo Numero de chasis: ";
                    cin.getline(numeroChasis, sizeof(numeroChasis));
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }

                    else if(strlen(numeroChasis) == 0)
                    {
                        cout << "Error: Ingrese un Numero de chasis valido." << endl;
                        system("pause");
                    }
                    else if(archivoAutoNuevo.Buscar(numeroChasis) >= 0 && strcmp(numeroChasis, autoNuevo.getPatente().getNumeroChasis()) != 0)
                    {
                        cout << "Error: Ya existe un auto con ese Numero de chasis." << endl;
                        system("pause");
                    }
                    else
                    {
                        patente.setNumeroChasis(numeroChasis);
                        autoNuevo.setPatente(patente);
                        break;
                    }
                }
                break;
            case 2:

                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nueva Marca: ";
                    cin.getline(marca, sizeof(marca));
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(marca) == 0)
                    {
                        cout << "Error: Ingrese una marca valida." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoNuevo.setMarca(marca);
                        break;
                    }
                }
                break;
            case 3:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo modelo: ";
                    cin.getline(modelo, sizeof(modelo));
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    if(strlen(modelo) == 0)
                    {
                        cout << "Error: Ingrese un modelo valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoNuevo.setModelo(modelo);
                        break;
                    }
                }
                break;
            case 4:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nueva version: ";
                    cin.getline(version, sizeof(version));
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    if(strlen(version) == 0)
                    {
                        cout << "Error: Ingrese una version valida." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoNuevo.setVersion(version);
                        break;
                    }
                }
                break;
            case 5:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();

                    cout << "Ingrese nuevo anio: ";
                    cin >> anio;

                    if(cin.fail() || anio < 1900 || anio > 2025)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error: Ingrese un anio valido." << endl;
                        system("pause");
                        continue;
                    }

                    autoNuevo.setAnio(anio);
                    break;
                }
                break;
            case 6:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo color: ";
                    cin.getline(color, sizeof(color));
                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    if(strlen(color) == 0)
                    {
                        cout << "Error: Ingrese un color valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoNuevo.setColor(color);
                        break;
                    }
                }
                break;
            case 7:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();

                    cout << "Ingrese nuevo precio de venta: ";
                    cin >> precioVenta;
                    if(cin.fail() || precioVenta <= 0)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error: Ingrese un precio de venta valido." << endl;
                        system("pause");
                        continue;
                    }

                    autoNuevo.setPrecioDeVenta(precioVenta);
                    break;
                }
                break;
            case 8:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();

                    cout << "Ingrese nuevos anios de garantia: ";
                    cin >> garantia;
                    if(cin.fail() || garantia <= 0)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error: Ingrese anios de garantia validos." << endl;
                        system("pause");
                        continue;
                    }

                    autoNuevo.setGarantia(garantia);
                    break;
                }
                break;
            case 9:
                return false; /// para cargar desde el inicio
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
            }
        }
    }
    return true;
}

void AutoNuevo::listadoAutosNuevosPorMarca()
{
    Menu menu;
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    AutoNuevo aux;
    AutoNuevo *vecAutosNuevos = nullptr;

    int cantidadRegistros = archivoAutoNuevo.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay autos nuevos registrados para mostrar" << endl;
        system("pause");
        return;
    }

    vecAutosNuevos = new AutoNuevo[cantidadRegistros];

    if(vecAutosNuevos == nullptr)
    {
        return;
    }

    /// Cargo los autos nuevos en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoAutoNuevo.Leer(i);
        vecAutosNuevos[i] = aux;
    }

    /// Bubble sort (ordenar por marca)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecAutosNuevos[j].getMarca(), vecAutosNuevos[j+1].getMarca()) > 0)
            {
                aux = vecAutosNuevos[j];
                vecAutosNuevos[j] = vecAutosNuevos[j+1];
                vecAutosNuevos[j+1] = aux;
            }
        }
    }

    /// Muestro los autos nuevos ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE AUTOS NUEVOS ORDENADOS POR MARCA ===" << endl;
    cout << "==================================================" << endl;
    cout << endl;

    // Mostrar los autos nuevos
    for(int i = 0; i < cantidadRegistros; i++)
    {
        // Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        // Mostrar cada auto nuevo con sus datos uno abajo del otro
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Numero de Chasis: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroChasis() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Patente: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroPatente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Marca: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getMarca() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Modelo: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getModelo() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Version: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getVersion() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Anio: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getAnio() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Color: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getColor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Precio: ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecAutosNuevos[i].getPrecioDeVenta() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Garantia: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getGarantia() << " anios" << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Estado: ";
        if(vecAutosNuevos[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "DISPONIBLE" << endl;
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "VENDIDO" << endl;
        }

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de autos nuevos
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de autos nuevos: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecAutosNuevos;
}

void AutoNuevo::listadoAutosNuevosPorModelo()
{
    Menu menu;
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    AutoNuevo aux;
    AutoNuevo *vecAutosNuevos = nullptr;

    int cantidadRegistros = archivoAutoNuevo.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay autos nuevos registrados para mostrar" << endl;
        system("pause");
        return;
    }

    vecAutosNuevos = new AutoNuevo[cantidadRegistros];

    if(vecAutosNuevos == nullptr)
    {
        return;
    }

    /// Cargo los autos nuevos en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoAutoNuevo.Leer(i);
        vecAutosNuevos[i] = aux;
    }

    /// Bubble sort (ordenar por modelo)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecAutosNuevos[j].getModelo(), vecAutosNuevos[j+1].getModelo()) > 0)
            {
                aux = vecAutosNuevos[j];
                vecAutosNuevos[j] = vecAutosNuevos[j+1];
                vecAutosNuevos[j+1] = aux;
            }
        }
    }

    /// Muestro los autos nuevos ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE AUTOS NUEVOS ORDENADOS POR MODELO ===" << endl;
    cout << "===================================================" << endl;
    cout << endl;

    // Mostrar los autos nuevos
    for(int i = 0; i < cantidadRegistros; i++)
    {
        // Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        // Mostrar cada auto nuevo con sus datos uno abajo del otro
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Numero de Chasis: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroChasis() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Patente: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroPatente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Marca: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getMarca() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Modelo: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getModelo() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Version: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getVersion() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Anio: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getAnio() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Color: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getColor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Precio: ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecAutosNuevos[i].getPrecioDeVenta() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Garantia: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getGarantia() << " anios" << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Estado: ";
        if(vecAutosNuevos[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "DISPONIBLE" << endl;
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "VENDIDO" << endl;
        }

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de autos nuevos
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de autos nuevos: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecAutosNuevos;
}

void AutoNuevo::listadoAutosNuevosPorAnio()
{
    Menu menu;
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    AutoNuevo aux;
    AutoNuevo *vecAutosNuevos = nullptr;

    int cantidadRegistros = archivoAutoNuevo.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay autos nuevos registrados para mostrar" << endl;
        system("pause");
        return;
    }

    vecAutosNuevos = new AutoNuevo[cantidadRegistros];

    if(vecAutosNuevos == nullptr)
    {
        return;
    }

    /// Cargo los autos nuevos en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoAutoNuevo.Leer(i);
        vecAutosNuevos[i] = aux;
    }

    /// Bubble sort (ordenar por año)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(vecAutosNuevos[j].getAnio() > vecAutosNuevos[j+1].getAnio())
            {
                aux = vecAutosNuevos[j];
                vecAutosNuevos[j] = vecAutosNuevos[j+1];
                vecAutosNuevos[j+1] = aux;
            }
        }
    }

    /// Muestro los autos nuevos ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE AUTOS NUEVOS ORDENADOS POR ANIO ===" << endl;
    cout << "==================================================" << endl;
    cout << endl;

    // Mostrar los autos nuevos
    for(int i = 0; i < cantidadRegistros; i++)
    {
        // Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        // Mostrar cada auto nuevo con sus datos uno abajo del otro
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Numero de Chasis: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroChasis() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Patente: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getPatente().getNumeroPatente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Marca: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getMarca() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Modelo: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getModelo() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Version: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getVersion() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Anio: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getAnio() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Color: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getColor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Precio: ";
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecAutosNuevos[i].getPrecioDeVenta() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Garantia: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecAutosNuevos[i].getGarantia() << " anios" << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Estado: ";
        if(vecAutosNuevos[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "DISPONIBLE" << endl;
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "VENDIDO" << endl;
        }

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de autos nuevos
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de autos nuevos: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecAutosNuevos;
}





