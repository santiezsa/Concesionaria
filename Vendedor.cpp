#include "Vendedor.h"
#include "ArchivoVendedor.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include "Menu.h"
using namespace std;
Menu menu;

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

        if(strlen(dni) == 0 || strlen(dni) > 11)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Ingrese un DNI valido." << endl;
            system("pause");
        }
        else
        {
            if(archivoVendedor.buscarVendedor(dni) >= 0)  /// si cuenta y encuentra el registro
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
    system("cls");
    menu.mostrarLogo();
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

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DEL VENDEDOR ===" << endl;
        mostrarVendedor(vendedor);
        cout << endl;
        cout << "Los datos son correctos? (s/n)";
        cin >> opcion;
        opcion = tolower(opcion);


        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << "Desea cargar un vendedor nuevo? (s/n)" << endl;
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
            cout << "1 - DNI" << endl;
            cout << "2 - Nombre" << endl;
            cout << "3 - Apellido" << endl;
            cout << "4 - Email" << endl;
            cout << "5 - Direccion" << endl;
            cout << "6 - Telefono" << endl;
            cout << "7 - Fecha de Nacimiento" << endl;
            cout << "8 - Fecha de Ingreso" << endl;
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
                    cout << "Ingrese nuevo DNI: ";
                    cin.getline(dni, sizeof(dni));
                    if(archivoVendedor.buscarVendedor(dni) >= 0 && strcmp(dni, vendedor.getDni()) != 0)
                    {
                        cout << "Error: Ya existe un vendedor con ese DNI." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedor.setDni(dni);
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
                    if(strlen(nombre) == 0 || strlen(nombre) > 49)
                    {
                        cout << "Error: Ingrese un nombre valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedor.setNombre(nombre);
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
                    if(strlen(apellido) == 0 || strlen(apellido) > 49)
                    {
                        cout << "Error: Ingrese un apellido valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedor.setApellido(apellido);
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
                    if(strlen(email) == 0|| strlen(email) > 49)
                    {
                        cout << "Error: Ingrese un email valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedor.setEmail(email);
                        break;
                    }
                }
                break;
            case 5:
                while(true)
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Ingrese nueva calle: ";
                    cin.getline(calle, sizeof(calle));
                    if(strlen(calle) == 0 || strlen(calle) > 49)
                    {
                        cout << "Error: Ingrese una calle valida." << endl;
                        system("pause");
                        continue;
                    }

                    cout << "Ingrese nueva altura: ";
                    cin >> altura;
                    if(cin.fail() || altura <= 0)
                    {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Error: La altura debe ser un numero positivo." << endl;
                        system("pause");
                        continue;
                    }
                    cin.ignore();

                    cout << "Ingrese nueva localidad: ";
                    cin.getline(localidad, sizeof(localidad));
                    if(strlen(localidad) == 0 || strlen(localidad) > 49)
                    {
                        cout << "Error: Ingrese una localidad valida." << endl;
                        system("pause");
                        continue;
                    }

                    Direccion nuevaDireccion(calle, altura, localidad);
                    vendedor.setDireccion(nuevaDireccion);
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
                    if(strlen(numeroTelefono) == 0 || strlen(numeroTelefono) > 19)
                    {
                        cout << "Error: Ingrese un numero de telefono valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        vendedor.setNumeroTelefono(numeroTelefono);
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
                    else
                    {
                        vendedor.setFechaNacimiento(nuevaFechaNacimiento);
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
                    else
                    {
                        vendedor.setFechaDeIngreso(nuevaFechaIngreso);
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




