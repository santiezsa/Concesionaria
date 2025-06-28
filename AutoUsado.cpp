#include "AutoUsado.h"
#include <iostream>
#include "Menu.h"
#include "ArchivoAutoUsado.h"
#include "ArchivoAutoNuevo.h"
#include <cstring>
#include <iomanip>
#include <limits>
using namespace std;

AutoUsado::AutoUsado() : Auto()
{
    _kilometraje = 0;
}

AutoUsado::AutoUsado(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int kilometraje) : Auto(patente, marca, modelo, version, anio, color, precioDeVenta, true) // Llama al constructor de Auto
{
    setKilometraje(kilometraje);
}

/// Getter
int AutoUsado::getKilometraje()
{
    return _kilometraje;
}

/// Setter
void AutoUsado::setKilometraje(int kilometraje)
{
    _kilometraje = kilometraje;
}

void AutoUsado::mostrar()
{
    cout << "Numero de chasis: " << getPatente().getNumeroChasis() << endl;
    cout << "Patente: " << getPatente().getNumeroPatente() << endl;
    cout << "Marca: " << getMarca() << endl;
    cout << "Modelo: " << getModelo() << endl;
    cout << "Version: " << getVersion() << endl;
    cout << "Anio: " << getAnio() << endl;
    cout << "Color: " << getColor() << endl;
    cout << "Precio de venta: $" << fixed << setprecision(2) << getPrecioDeVenta() << endl;
    cout << "Kilometraje: " << getKilometraje() << endl;
    cout << "Estado: ";
    if(getEstado())
    {
        cout << "Disponible";
    }
    else
    {
        cout << "Vendido";
    }
    cout << endl;


}

bool AutoUsado::cargarAutoUsado()
{

    Menu menu;
    char confirmar;
    char numeroChasis[10];
    char numeroPatente[10];
    char marca[50];
    char modelo[50];
    char version[50];
    int anio;
    char color[20];
    float precioVenta;
    int kilometraje;

    ArchivoAutoUsado archivoAutoUsado;
    ArchivoAutoNuevo archivoAutoNuevo;

    /// Carga NUMERO CHASIS (id)
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese el numero de chasis del auto usado: ";
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
        else if(archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis) >= 0 || archivoAutoNuevo.Buscar(numeroChasis) >= 0)  /// Valida chasis tanto en archivo auto nuevo y archivo auto usado
        {
            /// Verifico si el auto encontrado esta vendido o disponible
            int pos = archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis);
            AutoUsado autoExistente = archivoAutoUsado.Leer(pos);

            if(autoExistente.getEstado())   /// Si esta disponible
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Ya existe un auto con ese numero de chasis." << endl;
                cout << "Desea cargar un auto usado? (s/n)" << endl;
                cin >> cargarOtro;
                cargarOtro = tolower(cargarOtro);
                while(cargarOtro != 's' && cargarOtro != 'n')
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Error: Opcion incorrecta." << endl;
                    cout << "Desea cargar un auto usado? (s/n)" << endl;
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
            else  /// Si el auto esta vendido, permito reingreso
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Se encontro un auto con ese numero de chasis que fue vendido anteriormente." << endl;
                cout << "Se permitira reingresar el auto al sistema." << endl;
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

    /// Carga patente
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de patente: ";
        cin.getline(numeroPatente, sizeof(numeroPatente));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(numeroPatente) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese una patente valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La patente ingresada es " << numeroPatente << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "La patente ingresada es " << numeroPatente << ". Es correcto? (s/n) " << endl;
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
            cout << "Ingrese el precio de venta: ";
            cin >> precioVenta;
            if (cin.fail())
            {
                system("cls");
                menu.mostrarLogo();
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

/// Carga kilometraje
    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese los kilometros actuales del auto: ";
            cin >> kilometraje;
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
        if(kilometraje < 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Los kilometros no pueden ser menores a 0." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El kilometraje ingresado es " << fixed << setprecision(2) << kilometraje << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El kilometraje ingresado es " << fixed << setprecision(2) << kilometraje << ". Es correcto? (s/n) " << endl;
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
    AutoUsado autoUsado(patente, marca, modelo, version, anio, color, precioVenta, kilometraje);


/// Valido datos con el usuario
    if(!modificarAutoUsado(autoUsado))
    {
        return false;
    }


    if(archivoAutoUsado.Guardar(autoUsado))
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

bool AutoUsado::modificarAutoUsado(AutoUsado &autoUsado)
{
    Menu menu;
    Patente patente;
    char opcion;
    bool confirmarTodo = false;
    char numeroChasis[10];
    char numeroPatente[10];
    char marca[50];
    char modelo[50];
    char version[50];
    int anio;
    char color[20];
    float precioVenta;
    int kilometraje;

    ArchivoAutoUsado archivoAutoUsado;

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DEL AUTO ===" << endl;
        mostrarAutoUsado(autoUsado);
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
            mostrarAutoUsado(autoUsado);
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
                cout << "2 - Patente" << endl;
                cout << "3 - Marca" << endl;
                cout << "4 - Modelo" << endl;
                cout << "5 - Version" << endl;
                cout << "6 - Anio" << endl;
                cout << "7 - Color" << endl;
                cout << "8 - Precio de venta" << endl;
                cout << "9 - Kilometraje" << endl;
                cout << "10 - Cancelar y volver a cargar todo" << endl;

                cin >> opcionModificar;
                if (cin.fail())
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "=== DATOS DEL AUTO ===" << endl;
                    mostrarAutoUsado(autoUsado);
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
                    cout << "Ingrese nuevo numero de chasis: ";
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
                    else if(archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis) >= 0 && strcmp(numeroChasis, autoUsado.getPatente().getNumeroChasis()) != 0)
                    {
                        cout << "Error: Ya existe un auto con ese numero de chasis." << endl;
                        system("pause");
                    }
                    else
                    {
                        patente.setNumeroChasis(numeroChasis);
                        autoUsado.setPatente(patente);
                        break;
                    }
                }
                break;
            case 2:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo numero de patente: ";
                    cin.getline(numeroPatente, sizeof(numeroPatente));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(numeroPatente) == 0)
                    {
                        cout << "Error: Ingrese un numero de patente valido." << endl;
                        system("pause");
                    }
                    else if(archivoAutoUsado.BuscarAutoUsadoPorNumeroDePatente(numeroPatente) >= 0 && strcmp(numeroPatente, autoUsado.getPatente().getNumeroPatente()) != 0)
                    {
                        patente.setNumeroPatente(numeroPatente);
                        autoUsado.setPatente(patente);
                        break;
                    }
                }
                break;
            case 3:

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
                        autoUsado.setMarca(marca);
                        break;
                    }
                }
                break;
            case 4:
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
                    else if(strlen(modelo) == 0)
                    {
                        cout << "Error: Ingrese un modelo valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoUsado.setModelo(modelo);
                        break;
                    }
                }
                break;
            case 5:
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
                    else if(strlen(version) == 0)
                    {
                        cout << "Error: Ingrese una version valida." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoUsado.setVersion(version);
                        break;
                    }
                }
                break;
            case 6:
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

                    autoUsado.setAnio(anio);
                    break;
                }
                break;
            case 7:
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
                    else if(strlen(color) == 0)
                    {
                        cout << "Error: Ingrese un color valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        autoUsado.setColor(color);
                        break;
                    }
                }
                break;
            case 8:
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

                    autoUsado.setPrecioDeVenta(precioVenta);
                    break;
                }
                break;
            case 9:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();

                    cout << "Ingrese kilometraje del auto: ";
                    cin >> kilometraje;
                    if(cin.fail() || kilometraje <= 0)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error: Ingrese un numero de kilometraje valido." << endl;
                        system("pause");
                        continue;
                    }

                    autoUsado.setKilometraje(kilometraje);
                    break;
                }
                break;
            case 10:
                return false; /// para cargar desde el inicio
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
            }
        }
    }
    return true;
}

void AutoUsado::mostrarAutoUsado(AutoUsado &autoUsado)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "Numero de chasis: " << autoUsado.getPatente().getNumeroChasis() << endl;
    cout << "Patente: " << autoUsado.getPatente().getNumeroPatente() << endl;
    cout << "Marca: " << autoUsado.getMarca() << endl;
    cout << "Modelo: " << autoUsado.getModelo() << endl;
    cout << "Version: " << autoUsado.getVersion() << endl;
    cout << "Anio: " << autoUsado.getAnio() << endl;
    cout << "Color: " << autoUsado.getColor() << endl;
    cout << "Precio de venta: $" << fixed << setprecision(0) << autoUsado.getPrecioDeVenta() << endl;
    cout << "Kilometraje: " << autoUsado.getKilometraje() << " kilometros." << endl;
    cout << "Estado: ";
    if(autoUsado.getEstado())
    {
        cout << "Disponible";
    }
    else
    {
        cout << "Vendido";
    }
    cout << endl;
}


