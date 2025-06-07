#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Menu.h"
#include<iostream>
using namespace std;

Cliente::Cliente() : Persona()
{
    _idCliente = 0;
}

Cliente::Cliente(int idCliente, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento) : Persona(dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento)
{
    setIdCliente(idCliente);
}

/// Getter
int Cliente::getIdCliente()
{
    return _idCliente;
}

/// Setter
/// TODO: Agregar validacion
void Cliente::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

bool Cliente::cargarCliente()
{
    Menu menu;
    char confirmar;
    int idCliente;
    char dni[12];
    char nombre[50];
    char apellido[50];
    char numeroTelefono[20];
    char email[50];
    char calle[50];
    int altura;
    char localidad[50];
    int dia, mes, anio;
    Fecha fechaNacimiento;

    ArchivoCliente archivoCliente;

    /// Carga DNI
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese DNI del cliente: ";
        cin.ignore();
        cin.getline(dni, sizeof(dni));

        if(archivoCliente.buscarCliente(dni) >= 0)  /// si cuenta y encuentra el registro
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ya existe un cliente con ese DNI." << endl;
            cout << "Desea cargar un cliente nuevo? (s/n)" << endl;
            cin >> cargarOtro;
            cargarOtro = tolower(cargarOtro);
            while(cargarOtro != 's' && cargarOtro != 'n')
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Opcion incorrecta." << endl;
                cout << "Desea cargar un cliente nuevo? (s/n)" << endl;
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
            cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
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
        }
    }

    /// Carga nombre
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese nombre: ";
        cin.getline(nombre, sizeof(nombre));
        if(strlen(nombre) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: El nombre no puede estar vacio." << endl;
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
        if(strlen(apellido) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: El apellido no puede estar vacio." << endl;
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
        if(strlen(email) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: el email no puede estar vacio." << endl;
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
        if(strlen(calle) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: La calle no puede estar vacia" << endl;
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
        if(strlen(localidad) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: La localidad no puede estar vacia" << endl;
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
        if(strlen(numeroTelefono) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: el numero de telefono no puede estar vacio" << endl;
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


    /// Genero ID del cliente (automatico)
    idCliente = archivoCliente.generarIdCliente();

    /// Guardo datos
    Cliente cliente(idCliente, dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento);

    mostrarCliente(cliente);

    system("pause");

    if(archivoCliente.Guardar(cliente))
    {
        cout << "Cliente guardado exitosamente." << endl;
        return true;
    }
    else
    {
        cout << "No se pudo guardar el cliente." << endl;
        return false;
    }
}



void Cliente::mostrarCliente(Cliente &cliente)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "DNI: " << cliente.getDni() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Apellido: " << cliente.getApellido() << endl;
    cout << "Direccion: " << cliente.getDireccion().getCalle() << " " << cliente.getDireccion().getAltura() << ", " << cliente.getDireccion().getLocalidad() << endl;
    cout << "Telefono: " << cliente.getNumeroTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Fecha de Nacimiento: " << cliente.getFechaNacimiento().toString() << endl;
}
