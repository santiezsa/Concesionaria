#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include "Menu.h"
#include <limits>
#include "rlutil.h"
using namespace std;

Vendedor::Vendedor()
{
    _idVendedor = 0;
    _fechaDeIngreso = Fecha();
}

Vendedor::Vendedor(int idVendedor, const char* dni, const char* nombre, const char* apellido, Direccion direccion, const char* numeroTelefono, const char* email, Fecha fechaNacimiento, Fecha fechaDeIngreso) : Persona(dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento)
{
    setIdVendedor(idVendedor);
    setFechaDeIngreso(fechaDeIngreso);
}

/// Getter
int Vendedor::getIdVendedor()
{
    return _idVendedor;
}

Fecha Vendedor::getFechaDeIngreso()
{
    return _fechaDeIngreso;
}

/// Setters
/// TODO: Agregar validacion
void Vendedor::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

void Vendedor::setFechaDeIngreso(Fecha fechaDeIngreso)
{
    _fechaDeIngreso = fechaDeIngreso;
}

bool Vendedor::cargarVendedor()
{
    Menu menu;
    char confirmar;
    int idVendedor;
    char dni[12];
    char nombre[50];
    char apellido[50];
    char numeroTelefono[20];
    char email[50];
    char calle[50];
    int altura;
    char localidad[50];
    int dia, mes, anio;
    Fecha fechaNacimiento, fechaDeIngreso;

    ArchivoVendedor archivoVendedor;

    /// Carga DNI
    cin.ignore();
    while(true)
    {
        system("cls");
        menu.mostrarLogo();
        char cargarOtro;
        cout << "Ingrese DNI del vendedor: ";
        cin.getline(dni, sizeof(dni));

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(dni) == 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un DNI valido." << endl;
            system("pause");
        }
        else
        {
            if(archivoVendedor.buscarVendedorPorDNI(dni) >= 0)  /// si cuenta y encuentra el registro
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: Ya existe un vendedor con ese DNI." << endl;
                cout << "Desea cargar un vendedor nuevo? (s/n)" << endl;
                cin >> cargarOtro;
                cargarOtro = tolower(cargarOtro);
                while(cargarOtro != 's' && cargarOtro != 'n')
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Error: Opcion incorrecta." << endl;
                    cout << "Desea cargar un vendedor nuevo? (s/n)" << endl;
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
                else
                {
                    cin.ignore();
                }
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(nombre) == 0)
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(apellido) == 0)
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(email) == 0)
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(calle) == 0)
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(localidad) == 0)
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

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingreso demasiados caracteres." << endl;
            system("pause");
        }
        else if(strlen(numeroTelefono) == 0)
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
        if(esMayor(fechaDeIngreso, fechaNacimiento)==true)
        {
            break;
        }

    }

    /// Genero ID del vendedor (automatico)
    idVendedor = archivoVendedor.generarIdVendedor();

    /// Guardo datos
    Vendedor vendedor(idVendedor, dni, nombre, apellido, direccion, numeroTelefono, email, fechaNacimiento, fechaDeIngreso);


    /// Valido datos con el usuario
    if(!modificarVendedor(vendedor))
    {
        return false;
    }

    if(archivoVendedor.Guardar(vendedor))
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

void Vendedor::mostrarVendedor(Vendedor &vendedor)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "=== DATOS DEL VENDEDOR ===" << endl;
    cout << "ID Vendedor: " << vendedor.getIdVendedor() << endl;
    cout << "DNI: " << vendedor.getDni() << endl;
    cout << "Nombre: " << vendedor.getNombre() << endl;
    cout << "Apellido: " << vendedor.getApellido() << endl;
    cout << "Direccion: " << vendedor.getDireccion().getCalle() << " " << vendedor.getDireccion().getAltura() << ", " << vendedor.getDireccion().getLocalidad() << endl;
    cout << "Telefono: " << vendedor.getNumeroTelefono() << endl;
    cout << "Email: " << vendedor.getEmail() << endl;
    cout << "Fecha de Nacimiento: " << vendedor.getFechaNacimiento().toString() << endl;
    cout << "Fecha de Ingreso: " << vendedor.getFechaDeIngreso().toString() << endl;
}

bool Vendedor::modificarVendedor(Vendedor &vendedor)
{
    Menu menu;
    char opcion;
    bool confirmarTodo = false;
    char dni[12];
    char nombre[50];
    char apellido[50];
    char numeroTelefono[20];
    char email[50];
    char calle[50];
    int altura;
    char localidad[50];
    int dia, mes, anio;
    Fecha fechaNacimiento, fechaDeIngreso;

    ArchivoVendedor archivoVendedor;

    Vendedor vendedorTemporal = vendedor; /// Copia temporal del vendedor para modificar

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        mostrarVendedor(vendedorTemporal);
        cout << endl;
        cout << "Los datos son correctos? (s/n)";
        cin >> opcion;
        opcion = tolower(opcion);


        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << endl;
            mostrarVendedor(vendedorTemporal);
            cout << "Los datos son correctos? (s/n)" << endl;
            cin >> opcion;
            opcion = tolower(opcion);
        }

        if(opcion == 's')
        {
            vendedor = vendedorTemporal; // Copio datos modificados al vendedor original
            confirmarTodo = true;
        }
        else if(opcion == 'n')
        {
            int opcionModificar;
            while (true)
            {
                cout << endl;
                cout << "Que campo desea modificar?" << endl;
                cout << "1 - DNI" << endl;
                cout << "2 - Nombre" << endl;
                cout << "3 - Apellido" << endl;
                cout << "4 - Email" << endl;
                cout << "5 - Direccion" << endl;
                cout << "6 - Telefono" << endl;
                cout << "7 - Fecha de Nacimiento" << endl;
                cout << "8 - Fecha de Ingreso" << endl;
                cout << "9 - Cancelar y volver a cargar todo" << endl;

                cin >> opcionModificar;
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

            cin.ignore();

            switch(opcionModificar)
            {
            case 1:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo DNI: ";
                    cin.getline(dni, sizeof(dni));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(archivoVendedor.buscarVendedorPorDNI(dni) >= 0 && strcmp(dni, vendedor.getDni()) != 0)
                    {
                        cout << "Error: Ya existe un vendedor con ese DNI." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedorTemporal.setDni(dni);
                        break;
                    }
                }
                break;
            case 2:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo nombre: ";
                    cin.getline(nombre, sizeof(nombre));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(nombre) == 0)
                    {
                        cout << "Error: Ingrese un nombre valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedorTemporal.setNombre(nombre);
                        break;
                    }
                }
                break;
            case 3:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo apellido: ";
                    cin.getline(apellido, sizeof(apellido));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(apellido) == 0)
                    {
                        cout << "Error: Ingrese un apellido valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedorTemporal.setApellido(apellido);
                        break;
                    }
                }
                break;
            case 4:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo email: ";
                    cin.getline(email, sizeof(email));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(email) == 0)
                    {
                        cout << "Error: Ingrese un email valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedorTemporal.setEmail(email);
                        break;
                    }
                }
                break;
            case 5:
                while(true)
                {
                    while(true)
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Ingrese nueva calle: ";
                        cin.getline(calle, sizeof(calle));

                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: Ingreso demasiados caracteres." << endl;
                            system("pause");
                        }
                        else if(strlen(calle) == 0)
                        {
                            cout << "Error: Ingrese una calle valida." << endl;
                            system("pause");
                        }
                        else
                        {
                            break;
                        }
                    }

                    while(true)
                    {
                        cout << "Ingrese nueva altura: ";
                        cin >> altura;
                        if(cin.fail() || altura <= 0)
                        {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            cout << "Error: La altura debe ser un numero positivo." << endl;
                            system("pause");
                        }
                        else
                        {
                            break;
                        }
                    }
                    cin.ignore();

                    while(true)
                    {
                        cout << "Ingrese nueva localidad: ";
                        cin.getline(localidad, sizeof(localidad));
                        if (cin.fail())
                        {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: Ingreso demasiados caracteres." << endl;
                            system("pause");
                        }
                        else if(strlen(localidad) == 0 || strlen(localidad) > 49)
                        {
                            cout << "Error: Ingrese una localidad valida." << endl;
                            system("pause");
                        }
                        else
                        {
                            break;
                        }
                    }

                    Direccion nuevaDireccion(calle, altura, localidad);
                    vendedorTemporal.setDireccion(nuevaDireccion);
                    break;
                }
                break;
            case 6:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nuevo telefono: ";
                    cin.getline(numeroTelefono, sizeof(numeroTelefono));

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingreso demasiados caracteres." << endl;
                        system("pause");
                    }
                    else if(strlen(numeroTelefono) == 0)
                    {
                        cout << "Error: Ingrese un numero de telefono valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedorTemporal.setNumeroTelefono(numeroTelefono);
                        break;
                    }
                }
                break;
            case 7:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nueva fecha de nacimiento:" << endl;
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Anio: ";
                    cin >> anio;
                    Fecha nuevaFechaNacimiento(dia, mes, anio);
                    if(!nuevaFechaNacimiento.esValida())
                    {
                        cout << "Error: Fecha invalida." << endl;
                        system("pause");
                    }
                    else if (vendedorTemporal.esMayor(vendedorTemporal.getFechaDeIngreso(),nuevaFechaNacimiento))
                    {
                        vendedorTemporal.setFechaNacimiento(nuevaFechaNacimiento);
                        break;
                    }
                }
                break;
            case 8:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nueva fecha de ingreso:" << endl;
                    cout << "Dia: ";
                    cin >> dia;
                    cout << "Mes: ";
                    cin >> mes;
                    cout << "Anio: ";
                    cin >> anio;
                    Fecha nuevaFechaIngreso(dia, mes, anio);
                    if(!nuevaFechaIngreso.esValida())
                    {
                        cout << "Error: Fecha invalida." << endl;
                        system("pause");
                    }
                    else if (vendedorTemporal.esMayor(nuevaFechaIngreso,vendedorTemporal.getFechaNacimiento()))
                    {
                        vendedorTemporal.setFechaDeIngreso(nuevaFechaIngreso);
                        break;
                    }
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

bool Vendedor::esMayor(Fecha fechaIngreso, Fecha fechaNacimiento)
{
    int edad = fechaIngreso.getAnio()-fechaNacimiento.getAnio();

    if(edad<18)
    {
        cout << "Error: El ingresante es menor de edad." << endl;
        system("pause");
        return false;
    }
    else if(edad == 18)
    {
        if(fechaIngreso.getMes() == fechaNacimiento.getMes())
        {
            if(fechaIngreso.getDia() < fechaNacimiento.getDia())
            {
                cout << "Error: El ingresante es menor de edad." << endl;
                system("pause");
                return false;
            }
        }
        else if ((fechaIngreso.getMes() < fechaNacimiento.getMes()))
        {
            cout << "Error: El ingresante es menor de edad." << endl;
            system("pause");
            return false;
        }
    }
    return true;
}

void Vendedor::listadoVendedoresPorDNI()
{
    Menu menu;
    ArchivoVendedor archivoVendedor("vendedor.dat");
    Vendedor aux;
    Vendedor *vecVendedores = nullptr;

    int cantidadRegistros = archivoVendedor.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay vendedores registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecVendedores = new Vendedor[cantidadRegistros];

    if(vecVendedores == nullptr)
    {
        return;
    }

    /// Cargo los vendedores en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVendedor.Leer(i);
        vecVendedores[i] = aux;
    }

    /// Bubble sort (ordenar por DNI)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecVendedores[j].getDni(), vecVendedores[j+1].getDni()) > 0)
            {
                aux = vecVendedores[j];
                vecVendedores[j] = vecVendedores[j+1];
                vecVendedores[j+1] = aux;
            }
        }
    }

    /// Muestro los vendedores ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE VENDEDORES ORDENADOS POR DNI ===" << endl;
    cout << "=============================================" << endl;
    cout << endl;

    // Mostrar los vendedores
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

        // Mostrar cada vendedor con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Vendedor #" << vecVendedores[i].getIdVendedor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Ingreso: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getFechaDeIngreso().toString() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDireccion().getCalle() << " " << vecVendedores[i].getDireccion().getAltura() << ", " << vecVendedores[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de vendedores
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de vendedores: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVendedores;
}

void Vendedor::listadoVendedoresPorApellido()
{
    Menu menu;
    ArchivoVendedor archivoVendedor("vendedor.dat");
    Vendedor aux;
    Vendedor *vecVendedores = nullptr;

    int cantidadRegistros = archivoVendedor.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay vendedores registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecVendedores = new Vendedor[cantidadRegistros];

    if(vecVendedores == nullptr)
    {
        return;
    }

    /// Cargo los vendedores en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVendedor.Leer(i);
        vecVendedores[i] = aux;
    }

    /// Bubble sort (ordenar alfabéticamente por apellido)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecVendedores[j].getApellido(), vecVendedores[j+1].getApellido()) > 0)
            {
                aux = vecVendedores[j];
                vecVendedores[j] = vecVendedores[j+1];
                vecVendedores[j+1] = aux;
            }
        }
    }

    /// Muestro los vendedores ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE VENDEDORES ORDENADOS POR APELLIDO ===" << endl;
    cout << "===================================================" << endl;
    cout << endl;

    // Mostrar los vendedores
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

        // Mostrar cada vendedor con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Vendedor #" << vecVendedores[i].getIdVendedor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Ingreso: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getFechaDeIngreso().toString() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDireccion().getCalle() << " " << vecVendedores[i].getDireccion().getAltura() << ", " << vecVendedores[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de vendedores
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de vendedores: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVendedores;
}

void Vendedor::listadoVendedoresPorFechaIngreso()
{
    Menu menu;
    ArchivoVendedor archivoVendedor("vendedor.dat");
    Vendedor aux;
    Vendedor *vecVendedores = nullptr;

    int cantidadRegistros = archivoVendedor.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay vendedores registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecVendedores = new Vendedor[cantidadRegistros];

    if(vecVendedores == nullptr)
    {
        return;
    }

    /// Cargo los vendedores en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVendedor.Leer(i);
        vecVendedores[i] = aux;
    }

    /// Bubble sort (ordenar por fecha de ingreso)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(fechaMayorQue(vecVendedores[j].getFechaDeIngreso(), vecVendedores[j+1].getFechaDeIngreso()))
            {
                aux = vecVendedores[j];
                vecVendedores[j] = vecVendedores[j+1];
                vecVendedores[j+1] = aux;
            }
        }
    }

    /// Muestro los vendedores ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE VENDEDORES ORDENADOS POR FECHA DE INGRESO ===" << endl;
    cout << "===========================================================" << endl;
    cout << endl;

    // Mostrar los vendedores
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

        // Mostrar cada vendedor con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Vendedor #" << vecVendedores[i].getIdVendedor() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Ingreso: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getFechaDeIngreso().toString() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecVendedores[i].getDireccion().getCalle() << " " << vecVendedores[i].getDireccion().getAltura() << ", " << vecVendedores[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de vendedores
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de vendedores: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVendedores;
}

bool Vendedor::fechaMayorQue(Fecha fecha1, Fecha fecha2) // si fecha1 es mayor que fecha2 = true
{
    /// Comparo anios
    if(fecha1.getAnio() > fecha2.getAnio())
    {
        return true;
    }
    if(fecha1.getAnio() < fecha2.getAnio())
    {
        return false;
    }

    /// Comparo meses
    if(fecha1.getMes() > fecha2.getMes())
    {
        return true;
    }
    if(fecha1.getMes() < fecha2.getMes())
    {
        return false;
    }

    /// Comparo dias
    if(fecha1.getDia() > fecha2.getDia())
    {
        return true;
    }
    if(fecha1.getDia() < fecha2.getDia())
    {
        return false;
    }

    return false; // Si son iguales
}
