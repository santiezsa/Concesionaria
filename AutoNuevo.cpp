#include <iostream>
#include "Menu.h"
#include "AutoNuevo.h"
#include "ArchivoAutoNuevo.h"
using namespace std;


AutoNuevo::AutoNuevo() : Auto()
{
    _garantia = 0;
}

AutoNuevo::AutoNuevo(Patente patente, const char* marca, const char* modelo, const char* version, int anio, const char* color, float precioDeVenta, int garantia) : Auto(patente, marca, modelo, version, anio, color, precioDeVenta) // Llama al constructor de Auto
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

    char numeroChasis[20];
    char numeroPatente[10] = "ABC123";

    char marca[50] = "toyota";
    char modelo[50] = "modelo";
    char version[20] = "full";
    int anio = 2025;
    char color[20] = "blanco";
    float precioVenta = 15000;
    int garantia = 5;

    ArchivoAutoNuevo archivoAutoNuevo;

    /// Carga NUMERO CHASIS (id)
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese el numero de chasis del auto 0km: ";
        cin.getline(numeroChasis, sizeof(numeroChasis));

        /// TODO: Validar antes la cantidad de caracteres para una patente

        if(archivoAutoNuevo.Buscar(numeroChasis) >= 0)  /// si encuentra el registro
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
            else
            {
                cin.ignore();
            }
        }

    }
    Patente patente(numeroPatente, numeroChasis);

/*
 El chasis ingresado es " << numeroChasis << ". Es correcto? (s/n)

    /// Carga nombre
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese nombre: ";
        cin.getline(nombre, sizeof(nombre));

        if(strlen(nombre) == 0 || strlen(nombre) > 49)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un nombre valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El nombre ingresado es " << nombre << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    /// Carga apellido
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese apellido: ";
        cin.getline(apellido, sizeof(apellido));
        if(strlen(apellido) == 0 || strlen(apellido) > 49)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un apellido valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El apellido ingresado es " << apellido << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    /// Carga email
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese email: ";
        cin.getline(email, sizeof(email));
        if(strlen(email) == 0 || strlen(email) > 49)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un email valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El email ingresado es " << email << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    /// Carga direccion
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese calle: ";
        cin.getline(calle, sizeof(calle));
        if(strlen(calle) == 0 || strlen(calle) > 49)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese una calle valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La calle ingresada es " << calle << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    while(true)
    {
        while (true)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Ingrese altura: ";
            cin >> altura;
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
        if(altura <= 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: La altura debe ser mayor a cero" << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La altura ingresada es " << altura << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese localidad: ";
        cin.getline(localidad, sizeof(localidad));
        if(strlen(localidad) == 0 || strlen(localidad) >49)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese una localidad valida." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "La localidad ingresada es " << localidad << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    Direccion direccion(calle, altura, localidad);

    /// Carga telefono
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese numero de telefono: ";
        cin.getline(numeroTelefono, sizeof(numeroTelefono));
        if(strlen(numeroTelefono) == 0 || strlen(numeroTelefono) > 19)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un numero de telefono valido." << endl;
            system("pause");
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "El numero de telefono ingresado es " << numeroTelefono << ". Es correcto? (s/n) " << endl;
            cin >> confirmar;
            confirmar = tolower(confirmar);
            while(confirmar != 's' && confirmar != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea confirmar? (s/n)" << endl;
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

    /// Carga fecha de nacimiento
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "== Fecha de nacimiento ===" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        fechaNacimiento = Fecha(dia, mes, anio);
        if(!fechaNacimiento.esValida())
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Fecha de nacimiento invalida" << endl;
            system("pause");
        }
        else
        {
            break;
        }
    }

    /// Carga fecha de ingreso
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "== Fecha de ingreso ===" << endl;
        cout << "Dia: ";
        cin >> dia;
        cout << "Mes: ";
        cin >> mes;
        cout << "Anio: ";
        cin >> anio;

        fechaDeIngreso = Fecha(dia, mes, anio);
        if(!fechaDeIngreso.esValida())
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Fecha de ingreso invalida" << endl;
            system("pause");
        }
        else
        {
            break;
        }
    }
    */


    /// Guardo datos
    AutoNuevo autoNuevo(patente, marca, modelo, version, anio, color, precioVenta, garantia);


    /// Valido datos con el usuario
    /*
    if(!modificarVendedor(vendedor))
    {
        return false;
    }
    */

    if(archivoAutoNuevo.Guardar(autoNuevo))
    {
        cout << "Vendedor guardado exitosamente." << endl;
        return true;
    }
    else
    {
        cout << "No se pudo guardar el vendedor." << endl;
        return false;
    }
}
