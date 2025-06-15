#include "AutoUsado.h"
#include <iostream>
#include "Menu.h"
#include "ArchivoAutoUsado.h"
#include <cstring>
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
    mostrar();
    std::cout << "Kilometraje: " << getKilometraje() << std::endl;

}

bool AutoUsado::cargarAutoUsado(){

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
    int kilometraje;

    ArchivoAutoUsado archivoAutoUsado;

    /// Carga NUMERO CHASIS (id)
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese el numero de chasis del auto usado: ";
        cin.ignore();
        cin.getline(numeroChasis, sizeof(numeroChasis));

        if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 9)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error. Ingrese un numero de chasis valido." << endl;
            system("pause");
        }
        else if(archivoAutoUsado.Buscar(numeroChasis) >= 0)  /// si encuentra el registro
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
            cout << "Ingrese el precio de venta: ";
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

    /// Carga kilometraje
    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese los kilometros actual del auto: ";
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
            cout << "Los kilometros ingresados es " << kilometraje << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Los kilometros ingresados es " << kilometraje << ". Es correcto? (s/n) " << endl;
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
/*
    if(!modificarAutoNuevo(autoNuevo))
    {
        return false;
    }
*/


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
