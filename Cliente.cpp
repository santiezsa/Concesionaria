#include "Cliente.h"
#include "ArchivoCliente.h"
#include "Menu.h"
#include<iostream>
#include <cstring>
#include <iomanip>
#include "rlutil.h"
#include "limits"
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
        system("cls");
        menu.mostrarLogo();
        cout << "Ingrese altura: ";
        cin >> altura;

        if(cin.fail() || altura <= 0)
        {
            system("cls");
            menu.mostrarLogo();
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: La altura debe ser un numero positivo." << endl;
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
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Debe ingresar un numero valido para el día." << endl;
            system("pause");
            continue;
        }
        cout << "Mes: ";
        cin >> mes;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Debe ingresar un numero valido para el mes." << endl;
            system("pause");
            continue;
        }
        cout << "Anio: ";
        cin >> anio;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Debe ingresar un numero valido para el anio." << endl;
            system("pause");
            continue;
        }

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
    bool confirmacionUser = modificarCliente(cliente);

    if(confirmacionUser)
    {
        if(archivoCliente.Guardar(cliente))
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Cliente guardado exitosamente." << endl;
            system("pause");
            return true;
        }
        else
        {
            system("cls");
            menu.mostrarLogo();
            cout << "No se pudo guardar el cliente." << endl;
            system("pause");
            return false;
        }
    }
    else
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Modificacion cancelada. No se realizaron cambios." << endl;
        system("pause");
        return false;
    }
}

void Cliente::mostrarCliente(Cliente &cliente)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "=== DATOS DEL CLIENTE ===" << endl;
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

    Cliente clienteTemporal = cliente;  /// Copia temporal del cliente para modificar

    while(!confirmarTodo)
    {
        system("cls");
        menu.mostrarLogo();
        mostrarCliente(clienteTemporal);
        cout << endl;
        cout << "Los datos son correctos? (s/n): ";
        cin >> opcion;
        opcion = tolower(opcion);

        while(opcion != 's' && opcion != 'n')
        {
            system("cls");
            menu.mostrarLogo();
            cout << "Error: Opcion incorrecta." << endl;
            cout << endl;
            mostrarCliente(clienteTemporal);
            cout << "Desea confirmar? (s/n): " << endl;
            cin >> opcion;
            opcion = tolower(opcion);
        }

        if(opcion == 's')
        {
            cliente = clienteTemporal; // <-- Copio los datos modificados al cliente original
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
                cout << "8 - Cancelar y regresar al menu anterior" << endl;

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
                    else if(strlen(dni) == 0)
                    {
                        system("cls");
                        menu.mostrarLogo();
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
                        clienteTemporal.setDni(dni);
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
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingrese un nombre valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        clienteTemporal.setNombre(nombre);
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
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingrese un apellido valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        clienteTemporal.setApellido(apellido);
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
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Ingrese un email valido." << endl;
                        system("pause");
                    }
                    else
                    {
                        clienteTemporal.setEmail(email);
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
                        else if(strlen(localidad) == 0)
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
                    clienteTemporal.setDireccion(nuevaDireccion);
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
                        clienteTemporal.setNumeroTelefono(numeroTelefono);
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
                    
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Debe ingresar un numero valido para el dia." << endl;
                        system("pause");
                        continue;
                    }
                    
                    cout << "Mes: ";
                    cin >> mes;
                    
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Debe ingresar un numero valido para el mes." << endl;
                        system("pause");
                        continue;
                    }
                    
                    cout << "Anio: ";
                    cin >> anio;
                    
                    if(cin.fail())
                    {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Debe ingresar un numero valido para el anio." << endl;
                        system("pause");
                        continue;
                    }
                    
                    Fecha nuevaFechaNacimiento(dia, mes, anio);
                    if(!nuevaFechaNacimiento.esValida())
                    {
                        cout << "Error: Fecha invalida." << endl;
                        system("pause");
                    }
                    else
                    {
                        clienteTemporal.setFechaNacimiento(nuevaFechaNacimiento);
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


void Cliente::listadoClientesPorDNI()
{
    Menu menu;
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente aux;
    Cliente *vecClientes = nullptr;

    int cantidadRegistros = archivoCliente.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay clientes registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecClientes = new Cliente[cantidadRegistros];

    if(vecClientes == nullptr)
    {
        return;
    }

    /// Cargo los clientes en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoCliente.Leer(i);
        vecClientes[i] = aux;
    }

    /// Bubble sort (ordenar por DNI)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecClientes[j].getDni(), vecClientes[j+1].getDni()) > 0)
            {
                aux = vecClientes[j];
                vecClientes[j] = vecClientes[j+1];
                vecClientes[j+1] = aux;
            }
        }
    }

    /// Muestro los clientes ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE CLIENTES ORDENADOS POR DNI ===" << endl;
    cout << "=============================================" << endl;
    cout << endl;

    // Mostrar los clientes
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

        // Mostrar cada cliente con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Cliente #" << vecClientes[i].getIdCliente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDireccion().getCalle() << " " << vecClientes[i].getDireccion().getAltura() << ", " << vecClientes[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de clientes
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de clientes: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecClientes;
}

void Cliente::listadoClientesPorApellido()
{
    Menu menu;
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente aux;
    Cliente *vecClientes = nullptr;

    int cantidadRegistros = archivoCliente.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay clientes registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecClientes = new Cliente[cantidadRegistros];

    if(vecClientes == nullptr)
    {
        return;
    }

    /// Cargo los clientes en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoCliente.Leer(i);
        vecClientes[i] = aux;
    }

    /// Bubble sort (ordenar alfabéticamente por apellido)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(strcmp(vecClientes[j].getApellido(), vecClientes[j+1].getApellido()) > 0)
            {
                aux = vecClientes[j];
                vecClientes[j] = vecClientes[j+1];
                vecClientes[j+1] = aux;
            }
        }
    }

    /// Muestro los clientes ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE CLIENTES ORDENADOS POR APELLIDO ===" << endl;
    cout << "=================================================" << endl;
    cout << endl;

    // Mostrar los clientes
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

        // Mostrar cada cliente con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Cliente #" << vecClientes[i].getIdCliente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDireccion().getCalle() << " " << vecClientes[i].getDireccion().getAltura() << ", " << vecClientes[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de clientes
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de clientes: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecClientes;
}

bool Cliente::fechaMayorQue(Fecha fecha1, Fecha fecha2) // si fecha1 es mayor que fecha2 = true
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

void Cliente::listadoClientesPorFecha()
{
    Menu menu;
    ArchivoCliente archivoCliente("clientes.dat");
    Cliente aux;
    Cliente *vecClientes = nullptr;

    int cantidadRegistros = archivoCliente.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay clientes registrados para mostrar." << endl;
        system("pause");
        return;
    }

    vecClientes = new Cliente[cantidadRegistros];

    if(vecClientes == nullptr)
    {
        return;
    }

    /// Cargo los clientes en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoCliente.Leer(i);
        vecClientes[i] = aux;
    }

    /// Bubble sort (ordenar por fecha de nacimiento)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(fechaMayorQue(vecClientes[j].getFechaNacimiento(), vecClientes[j+1].getFechaNacimiento()))
            {
                aux = vecClientes[j];
                vecClientes[j] = vecClientes[j+1];
                vecClientes[j+1] = aux;
            }
        }
    }

    /// Muestro los clientes ya ordenados
    system("cls");
    menu.mostrarLogo();

    cout << endl;
    cout << "=== LISTADO DE CLIENTES ORDENADOS POR FECHA DE NACIMIENTO ===" << endl;
    cout << "============================================================" << endl;
    cout << endl;

    // Mostrar los clientes
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

        // Mostrar cada cliente con sus datos uno abajo del otro
        rlutil::setColor(rlutil::YELLOW);
        cout << "Cliente #" << vecClientes[i].getIdCliente() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "DNI: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDni() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Nombre: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNombre() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Apellido: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getApellido() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Fecha de Nacimiento: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getFechaNacimiento().toString() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Email: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getEmail() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Telefono: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getNumeroTelefono() << endl;

        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Direccion: ";
        rlutil::setColor(rlutil::WHITE);
        cout << vecClientes[i].getDireccion().getCalle() << " " << vecClientes[i].getDireccion().getAltura() << ", " << vecClientes[i].getDireccion().getLocalidad() << endl;

        // Línea separadora
        rlutil::setColor(rlutil::GREY);
        cout << "--------------------------------------------------------" << endl;
        cout << endl;
    }

    // Total de clientes
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de clientes: " << cantidadRegistros << endl;

    // Mensaje de espera
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecClientes;
}



