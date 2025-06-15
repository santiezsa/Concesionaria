#include <iostream>
#include "Menu.h"
#include "AutoNuevo.h"
#include "ArchivoAutoNuevo.h"
#include <cstring>
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
int AutoNuevo::getGarantia() {
    return _garantia;
}

/// Setter
void AutoNuevo::setGarantia(int garantia) {
    _garantia = garantia;
}


bool AutoNuevo::cargarAutoNuevo(){

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

    /// Carga NUMERO CHASIS (id)
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese el numero de chasis del auto 0km: ";
        cin.ignore();
        cin.getline(numeroChasis, sizeof(numeroChasis));

        if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 9)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error. Ingrese un numero de chasis valido." << endl;
            system("pause");
        }
        else if(archivoAutoNuevo.Buscar(numeroChasis) >= 0)  /// si encuentra el registro
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

        if(strlen(marca) == 0 || strlen(marca) > 49)
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
        if(strlen(modelo) == 0 || strlen(modelo) > 49)
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
        if(strlen(version) == 0 || strlen(version) > 49)
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
        if(strlen(color) == 0 || strlen(color) >49)
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
            cout << "El precio de venta del auto ingresado es " << precioVenta << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "El precio de venta del auto ingresado es " << precioVenta << ". Es correcto? (s/n) " << endl;
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
            cout << "Error: Ingrese anios de garantia valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Los anios de garantia ingresados es " << anio << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Los anios de garantia ingresados es " << anio << ". Es correcto? (s/n) " << endl;
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
    cout << "Patente: " << autoNuevo.getPatente().getNumeroChasis() << endl;
    cout << "Marca: " << autoNuevo.getMarca() << endl;
    cout << "Modelo: " << autoNuevo.getModelo() << endl;
    cout << "Version: " << autoNuevo.getVersion() << endl;
    cout << "Anio: " << autoNuevo.getAnio() << endl;
    cout << "Color: " << autoNuevo.getColor() << endl;
    cout << "Precio de venta: $" << autoNuevo.getPrecioDeVenta() << endl;
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

            int opcionModificar;
            cin >> opcionModificar;
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
                    if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 9)
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
                    if(strlen(marca) == 0 || strlen(marca) > 49)
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
                    if(strlen(modelo) == 0 || strlen(modelo) > 49)
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
                    if(strlen(version) == 0 || strlen(version) > 49)
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
                    if(strlen(color) == 0 || strlen(color) > 49)
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
