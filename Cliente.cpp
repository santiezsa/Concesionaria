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

        if(strlen(dni) == 0 || strlen(dni) > 11)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error. Ingrese un DNI valido." << endl;
            system("pause");
        }
        else if(archivoCliente.buscarClientePorDNI(dni) >= 0)  /// si busca y encuentra el registro
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
                cout << "El DNI ingresado es " << dni << ". Es correcto? (s/n) " << endl;
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
                cout << "El nombre ingresado es " << nombre << ". Es correcto? (s/n) " << endl;
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
                cout << "El apellido ingresado es " << apellido << ". Es correcto? (s/n) " << endl;
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
                cout << "El email ingresado es " << email << ". Es correcto? (s/n) " << endl;
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
                cout << "La calle ingresada es " << calle << ". Es correcto? (s/n) " << endl;
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
            if (cin.fail()) // Si la entrada es invalida
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
                break; // Si la entrada es valida, salir del bucle
            }
        }
        if(altura <= 0)
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: La altura debe ser mayor a cero." << endl;
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
                cout << "La altura ingresada es " << altura << ". Es correcto? (s/n) " << endl;
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
        if(strlen(localidad) == 0 || strlen(localidad) > 49)
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
                cout << "La localidad ingresada es " << localidad << ". Es correcto? (s/n) " << endl;
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
                cout << "El numero de telefono ingresado es " << numeroTelefono << ". Es correcto? (s/n) " << endl;
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

    /// Valido datos con el usuario
    if(!modificarCliente(cliente))
    {
        return false;
    }


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
    cout << "ID Cliente: " << cliente.getIdCliente() << endl;
    cout << "DNI: " << cliente.getDni() << endl;
    cout << "Nombre: " << cliente.getNombre() << endl;
    cout << "Apellido: " << cliente.getApellido() << endl;
    cout << "Direccion: " << cliente.getDireccion().getCalle() << " " << cliente.getDireccion().getAltura() << ", " << cliente.getDireccion().getLocalidad() << endl;
    cout << "Telefono: " << cliente.getNumeroTelefono() << endl;
    cout << "Email: " << cliente.getEmail() << endl;
    cout << "Fecha de Nacimiento: " << cliente.getFechaNacimiento().toString() << endl;
}

bool Cliente::modificarCliente(Cliente &cliente)
{
    Menu menu;
    char opcion;
    bool confirmarTodo = false;
    char dni[12];
    char nombre[50];
    char apellido[50];
    char numeroTelefono[50];
    char email[50];
    char calle[50];
    int altura;
    char localidad[50];
    int dia, mes, anio;
    Fecha fechaNacimiento;

    ArchivoCliente archivoCliente;

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== DATOS DEL CLIENTE ===" << endl;
        mostrarCliente(cliente);
        cout << endl;
        cout << "Los datos son correctos? (s/n): ";
        cin >> opcion;
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << "Desea confirmar? (s/n): " << endl;
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
            cout << "8 - Cancelar y volver a cargar todo" << endl;

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
                    if(strlen(dni) == 0 || strlen(dni) > 11)
                    {
                        cout << "Error: Ingrese un DNI valido." << endl;
                        system("pause");
                    }
                    else if(archivoCliente.buscarClientePorDNI(dni) >= 0 && strcmp(dni, cliente.getDni()) != 0)
                    {
                        cout << "Error: Ya existe un cliente con ese DNI." << endl;
                        system("pause");
                    }
                    else
                    {
                        cliente.setDni(dni);
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
                        cliente.setNombre(nombre);
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
                        cliente.setApellido(apellido);
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
                    if(strlen(email) == 0 || strlen(email) > 49)
                    {
                        cout << "Error: Ingrese un email valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        cliente.setEmail(email);
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
                    cliente.setDireccion(nuevaDireccion);
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
                        cliente.setNumeroTelefono(numeroTelefono);
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
                        cliente.setFechaNacimiento(nuevaFechaNacimiento);
                        break;
                    }
                }
                break;
            case 8:
                return false; /// para cargar desde el inicio
            default:
                cout << "Opcion invalida." << endl;
                system("pause");
            }
        }
    }
    return true;
}
