#include "Venta.h"
#include "Menu.h"
#include "ArchivoVenta.h"
#include "ArchivoAutoUsado.h"
#include "ArchivoAutoNuevo.h"
#include "ArchivoVendedor.h"
#include "ArchivoCliente.h"
#include "ArchivoVenta.h"
#include <iostream>
#include <cstring>
#include <iomanip>
#include <limits>
#include "rlutil.h"

using namespace std;


Venta::Venta()
{
    _idVenta = 0;
    _patente = Patente();
    _monto = 0.0f;
    _fechaDeVenta = Fecha();
    _idCliente = 0;
    _idVendedor = 0;
}

///TODO: Agregar ID Cliente, numero de chasis
Venta::Venta(int idVenta, Patente patente, float monto, Fecha fechaDeVenta, int idCliente, int idVendedor, bool estado)
{
    setIdVenta(idVenta);
    setPatente(patente);
    setMonto(monto);
    setFechaDeVenta(fechaDeVenta);
    setIdCliente(idCliente);
    setIdVendedor(idVendedor);
    setEstado(true);
}

/// Getters
int Venta::getIdVenta()
{
    return _idVenta;
}

Patente Venta::getPatente()
{
    return _patente;
}

float Venta::getMonto()
{
    return _monto;
}

Fecha Venta::getFechaDeVenta()
{
    return _fechaDeVenta;
}

int Venta::getIdCliente()
{
    return _idCliente;
}

int Venta::getIdVendedor()
{
    return _idVendedor;
}

bool Venta::getEstado()
{
    return _estado;
}

/// Setters
/// TODO: Agregar validaciones
void Venta::setIdVenta(int idVenta)
{
    _idVenta = idVenta;
}

void Venta::setPatente(Patente patente)
{
    _patente = patente;
}

void Venta::setMonto(float monto)
{
    _monto = monto;
}

void Venta::setFechaDeVenta(Fecha fechaDeVenta)
{
    _fechaDeVenta = fechaDeVenta;
}

void Venta::setIdCliente(int idCliente)
{
    _idCliente = idCliente;
}

void Venta::setIdVendedor(int idVendedor)
{
    _idVendedor = idVendedor;
}

void Venta::setEstado(bool estado)
{
    _estado = estado;
}

bool Venta::cargarVentaAutoUsado()
{
    /// TODO: Agregar validaciones
    Menu menu;
    Venta venta;
    AutoUsado autoUsado;
    int idVenta;
    //char numeroPatente[10];
    char numeroChasis[10];
    Patente patente;
    float monto;
    int dia, mes, anio;
    Fecha fechaDeVenta;
    int idCliente;
    int idVendedor;

    char confirmar;
    char confirmarCarga;

    ArchivoVenta archivoVenta;
    ArchivoAutoUsado archivoAutoUsado;
    ArchivoVendedor archivoVendedor;
    ArchivoCliente archivoCliente;

    /// Preguntar que existan clientes, vendedores y autos antes de realizar la carga
    if(archivoAutoUsado.CantidadRegistros() == 0)
    {

        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un auto antes de realizar una venta." << endl;
        system("pause");
        return false;
    }
    else if(archivoVendedor.CantidadRegistros() == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un vendedor antes de realizar una venta." << endl;
        system("pause");
        return false;
    }
    else if(archivoCliente.CantidadRegistros() == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un cliente antes de realizar una venta." << endl;
        system("pause");
        return false;
    }

    /// Genero ID de venta
    idVenta = archivoVenta.generarIdVenta();

    /// TODO: Verificar que no haya patentes iguales -> Tener en cuenta que los vehiculos vendidos se desactivan (estado: false)
    /// TODO: Validar que el auto a vender tenga estado true (para no vender un auto ya vendido)

    if(archivoAutoUsado.CantidadRegistros() != 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== LISTADO DE AUTOS USADOS DISPONIBLES ===" << endl;
        archivoAutoUsado.mostrarAutosUsadosDisponibles();
        cout << "===========================================" << endl;
        cout << endl;

        cin.ignore();
        while(true)
        {
            cout << "Ingrese el numero de chasis deseado: ";
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
            else if(!(archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis) >= 0))
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
                cout << "Desea cargar un auto nuevo? (s/n)" << endl;
                cin >> confirmarCarga;
                confirmarCarga = tolower(confirmarCarga);
                while(confirmarCarga != 's' && confirmarCarga != 'n')
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Error: opcion incorrecta." << endl;
                    cout << "Desea cargar un auto nuevo? (s/n)" << endl;
                    cin >> confirmarCarga;
                    confirmarCarga = tolower(confirmarCarga);
                }
                if(confirmarCarga == 's')
                {
                    autoUsado.cargarAutoUsado();
                    cin.ignore();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                system("cls");
                menu.mostrarLogo();
                cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);
                while(confirmar != 's' && confirmar != 'n')
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Error: opcion incorrecta." << endl;
                    cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
                    cin >> confirmar;
                    confirmar = tolower(confirmar);
                }
                if(confirmar == 's')
                {
                    cin.ignore();
                    /// Busco informacion del auto en base al numero de chasis
                    int pos = archivoAutoUsado.BuscarAutoUsadoPorNumeroDeChasis(numeroChasis);
                    autoUsado = archivoAutoUsado.Leer(pos); /// Devuelve el objeto auto usado

                    /// Valido que el auto este disponible para la venta
                    if(!autoUsado.getEstado())
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Este vehiculo ya fue vendido y no esta disponible." << endl;
                        system("pause");
                        return false;
                    }
                    autoUsado.mostrar();
                    cout << endl;
                    cout << "Confirma que este es el auto que desea vender? (s/n): ";
                    cin >> confirmar;
                    confirmar = tolower(confirmar);

                    while(confirmar != 's' && confirmar != 'n')
                    {
                        cout << "Error: opcion incorrecta." << endl;
                        cout << "Confirma que este es el auto que desea vender? (s/n): ";
                        cin >> confirmar;
                        confirmar = tolower(confirmar);
                    }
                    if(confirmar == 'n')
                    {
                        cout << "Operacion cancelada." << endl;
                        system("pause");
                        return false;
                    }

                    system("cls");
                    menu.mostrarLogo();
                    /// Obtengo el monto
                    monto = autoUsado.getPrecioDeVenta();
                    cout << endl;
                    cout << "---------------------------" << endl;
                    cout << "Monto a cobrar: $" << monto << endl;
                    cout << "---------------------------" << endl;
                    cout << endl;

                    /// Pido el ID al vendedor
                    while(true)
                    {
                        while(true)
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Ingrese ID de vendedor: ";
                            cin >> idVendedor;
                            if(cin.fail())
                            {
                                system("cls");
                                menu.mostrarLogo();
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                                system("pause");
                            }
                            else
                            {
                                /// Si valida la entrada salgo del while
                                break;
                            }
                        }

                        /// Valido que el vendedor exista
                        if(archivoVendedor.buscarVendedorPorID(idVendedor) == -1) /// No encuentra el registro
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: No existe un vendedor con ese ID." << endl;
                            cout << "Intente con un vendedor valido o cargue un nuevo vendedor." << endl;
                            system("pause");
                        }
                        else
                        {
                            // Si el vendedor existe, salgo del bucle
                            break;
                        }
                    }

                    /// Pido el ID del cliente
                    while(true)
                    {
                        while(true)
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Ingrese ID del cliente: ";
                            cin >> idCliente;
                            if(cin.fail())
                            {
                                system("cls");
                                menu.mostrarLogo();
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                                system("pause");
                            }
                            else
                            {
                                /// Si valida la entrada salgo del while
                                break;
                            }
                        }

                        /// Valido que el cliente exista
                        if(archivoCliente.buscarClientePorID(idCliente) == -1) /// No encuentra el registro
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: No existe un cliente con ese ID." << endl;
                            system("pause");
                        }
                        else
                        {
                            // Si el cliente existe, salgo del bucle
                            break;
                        }
                    }


                    /// Ingresa la fecha de la venta
                    while(true)
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "=== Fecha de venta ===" << endl;
                        cout << "Dia: ";
                        cin >> dia;
                        cout << "Mes: ";
                        cin >> mes;
                        cout << "Anio: ";
                        cin >> anio;

                        fechaDeVenta = Fecha(dia, mes, anio);
                        if(!fechaDeVenta.esValida())
                        {
                            cout << "Error: Fecha invalida." << endl;
                            system("pause");
                        }
                        else
                        {
                            break;
                        }
                    }

                    venta = Venta(idVenta, autoUsado.getPatente(), monto, fechaDeVenta, idCliente, idVendedor, true);

                    if(archivoVenta.Guardar(venta))
                    {
                        cout << "Venta registrada exitosamente." << endl;
                        /// Marca el auto como vendido
                        autoUsado.setEstado(false);
                        archivoAutoUsado.Guardar(autoUsado, pos);
                        system("pause");
                        return true;
                    }
                    else
                    {
                        cout << "Error al guardar la venta." << endl;
                        system("pause");
                        return false;
                    }
                    break;
                }
                else
                {
                    cin.ignore();
                }
            }
        }
    }
    else
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se registraron autos usados." << endl;
        system("pause");
        return false;
    }
}

bool Venta::cargarVentaAutoNuevo()
{
    Menu menu;
    Venta venta;
    AutoNuevo autoNuevo;
    int idVenta;
    char numeroChasis[10];
    Patente patente;
    float monto;
    int dia, mes, anio;
    Fecha fechaDeVenta;
    int idCliente;
    int idVendedor;
    char confirmar;

    ArchivoVenta archivoVenta;
    ArchivoAutoNuevo archivoAutoNuevo;
    ArchivoVendedor archivoVendedor;
    ArchivoCliente archivoCliente;


    /// Preguntar que existan clientes, vendedores y autos antes de realizar la carga
    if(archivoAutoNuevo.CantidadRegistros() == 0)
    {

        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un auto antes de realizar una venta." << endl;
        system("pause");
        return false;
    }
    else if(archivoVendedor.CantidadRegistros() == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un vendedor antes de realizar una venta." << endl;
        system("pause");
        return false;
    }
    else if(archivoCliente.CantidadRegistros() == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Por favor, cargue un cliente antes de realizar una venta." << endl;
        system("pause");
        return false;
    }

    /// Genero ID de venta
    idVenta = archivoVenta.generarIdVenta();

    /// TODO: Verificar que no haya patentes iguales -> Tener en cuenta que los vehiculos vendidos se desactivan (estado: false)
    /// TODO: Validar que el auto a vender tenga estado true (para no vender un auto ya vendido)


    if(archivoAutoNuevo.CantidadRegistros() != 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "=== LISTADO DE AUTOS NUEVOS DISPONIBLES ===" << endl;
        archivoAutoNuevo.mostrarAutosNuevosDisponibles();
        cout << "===========================================" << endl;
        cout << endl;

        cin.ignore();
        while(true)
        {
            cout << "Ingrese el numero de chasis deseado: ";
            cin.getline(numeroChasis, sizeof(numeroChasis));

            if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 11)
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error. Ingrese un numero de chasis valido." << endl;
                system("pause");
            }
            else if (!(archivoAutoNuevo.Buscar(numeroChasis) >= 0))
            {
                system("cls");
                menu.mostrarLogo();
                cout << "Error: No existe un vehiculo con ese numero de chasis." << endl;
            }
            else
            {
                system("cls");
                menu.mostrarLogo();
                cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
                cin >> confirmar;
                confirmar = tolower(confirmar);

                while (confirmar != 's' && confirmar != 'n')
                {
                    system("cls");
                    menu.mostrarLogo();
                    cout << "Error: opcion incorrecta." << endl;
                    cout << "El numero de chasis ingresado es: " << numeroChasis << ". Es correcto? (s/n)" << endl;
                    cin >> confirmar;
                    confirmar = tolower(confirmar);
                }

                if(confirmar == 's')
                {
                    cin.ignore();
                    /// Busco informacion del auto en base al numero de chasis
                    int pos = archivoAutoNuevo.Buscar(numeroChasis);
                    autoNuevo = archivoAutoNuevo.Leer(pos); /// Devuelve el objeto auto nuevo

                    /// Valido que el auto este disponible para la venta
                    if(!autoNuevo.getEstado())
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: Este vehiculo ya fue vendido y no esta disponible." << endl;
                        system("pause");
                        return false;
                    }

                    autoNuevo.mostrar();
                    cout << endl;

                    cout << "Confirma que este es el auto que desea vender? (s/n): ";
                    cin >> confirmar;
                    confirmar = tolower(confirmar);

                    while (confirmar != 's' && confirmar != 'n')
                    {
                        cout << "Error: opcion incorrecta." << endl;
                        cout << "Confirma que este es el auto que desea vender? (s/n): ";
                        cin >> confirmar;
                        confirmar = tolower(confirmar);
                    }

                    if (confirmar == 'n')
                    {
                        cout << "Operacion cancelada." << endl;
                        system("pause");
                        return false;
                    }

                    /// Obtengo el monto
                    monto = autoNuevo.getPrecioDeVenta();
                    cout << endl;
                    cout << "Monto a cobrar: $" << monto << endl;

                    /// Pido el ID al vendedor
                    while(true)
                    {
                        while(true)
                        {
                            cout << "Ingrese ID de vendedor: ";
                            cin >> idVendedor;
                            if(cin.fail())
                            {
                                system("cls");
                                menu.mostrarLogo();
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                                system("pause");
                            }
                            else
                            {
                                break;
                            }
                        }

                        /// Valido que el vendedor exista
                        if(archivoVendedor.buscarVendedorPorID(idVendedor) == -1)
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: No existe un vendedor con ese ID." << endl;
                            cout << "Intente con un vendedor valido o cargue un nuevo vendedor." << endl;
                            system("pause");
                        }
                        else
                        {
                            // Si el vendedor existe, salir del bucle
                            break;
                        }
                    }

                    /// Pido el ID del cliente
                    while(true)
                    {
                        while(true)
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Ingrese ID del cliente: ";
                            cin >> idCliente;
                            if(cin.fail())
                            {
                                system("cls");
                                menu.mostrarLogo();
                                cin.clear();
                                cin.ignore(1000,'\n');
                                cout << "Error: Entrada invalida. Intente nuevamente." << endl;
                                system("pause");
                            }
                            else
                            {
                                /// Si valida la entrada salgo del while
                                break;
                            }
                        }

                        /// Valido que el cliente exista
                        if(archivoCliente.buscarClientePorID(idCliente) == -1) /// No encuentra el registro
                        {
                            system("cls");
                            menu.mostrarLogo();
                            cout << "Error: No existe un cliente con ese ID." << endl;
                            system("pause");
                        }
                        else
                        {
                            // Si el cliente existe, salgo del bucle
                            break;
                        }
                    }

                    /// Ingresa la fecha de la venta
                    while (true)
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "=== Fecha de venta ===" << endl;
                        cout << "Dia: ";
                        cin >> dia;
                        cout << "Mes: ";
                        cin >> mes;
                        cout << "Ao: ";
                        cin >> anio;

                        fechaDeVenta = Fecha(dia, mes, anio);
                        if (!fechaDeVenta.esValida())
                        {
                            cout << "Error: Fecha invalida." << endl;
                            system("pause");
                        }
                        else
                        {
                            break;
                        }
                    }

                    venta = Venta(idVenta, autoNuevo.getPatente(), monto, fechaDeVenta, idCliente, idVendedor, true);

                    /// Valido datos con el usuario
                    system("cls");
                    menu.mostrarLogo();
                    cout << "La venta a cargar es la siguiente: ";
                    mostrarVenta(venta);
                    cout << endl;
                    cout << "Confirma la venta? (s/n)";
                    cin >> confirmar;
                    confirmar = tolower(confirmar);

                    while(confirmar != 's' && confirmar != 'n')
                    {
                        system("cls");
                        menu.mostrarLogo();
                        cout << "Error: opcion incorrecta." << endl;
                        cout << "La venta a cargar es la siguiente: " << endl;
                        mostrarVenta(venta);
                        cout << endl;
                        cout << "Confirma la venta? (s/n)";
                        cin >> confirmar;
                        confirmar = tolower(confirmar);
                    }
                    if(confirmar == 'n')
                    {
                        cout << "Operacion de venta cancelada." << endl;
                        system("pause");
                        return false;
                    }

                    if (archivoVenta.Guardar(venta))
                    {
                        cout << "Venta registrada exitosamente." << endl;
                        /// Marca el auto como vendido
                        autoNuevo.setEstado(false);
                        archivoAutoNuevo.Guardar(autoNuevo, pos);
                        system("pause");
                        return true;
                    }
                    else
                    {
                        cout << "Error al guardar la venta." << endl;
                        system("pause");
                        return false;
                    }
                }
                else
                {
                    cin.ignore();
                }
            }
        }
    }
    else
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se registraron autos nuevos." << endl;
        system("pause");
        return false;
    }
}

void Venta::cancelarVenta()
{
    setEstado(false);
}

void Venta::mostrarVenta(Venta &venta)
{
    Menu menu;
    system("cls");
    menu.mostrarLogo();
    cout << "=== DATOS DE LA VENTA ===" << endl;
    cout << "ID Venta: " << venta.getIdVenta() << endl;
    cout << "Monto: $" << venta.getMonto() << endl;
    cout << "Fecha: " << venta.getFechaDeVenta().toString() << endl;
    cout << "ID Cliente: " << venta.getIdCliente() << endl;
    cout << "ID Vendedor: " << venta.getIdVendedor() << endl;
    if(getEstado())
    {
        cout << "Estado actual de la venta: ACTIVA" << endl;
    }
    else
    {
        cout << "Estado actual de la venta: INACTIVA" << endl;
    }
}

bool Venta::fechaMayorQue(Fecha fecha1, Fecha fecha2) // si fecha1 es mayor que fecha2 = true
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
}


/// --------------------------------------------------------- LISTADOS --------------------------------------------------------- ///

void Venta::listadoVentasPorFecha()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    Venta aux;
    Venta *vecVentas = nullptr;

    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {

        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para mostrar." << endl;
        system("pause");
        return;
    }

    vecVentas = new Venta[cantidadRegistros];

    if(vecVentas == nullptr)
    {
        return;
    }

    /// Cargo las ventas en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVenta.Leer(i);
        vecVentas[i] = aux;
    }

    /// Bubble sort (menor a mayor fecha)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(fechaMayorQue(vecVentas[j].getFechaDeVenta(), vecVentas[j+1].getFechaDeVenta()))
            {
                aux = vecVentas[j];
                vecVentas[j] = vecVentas[j+1];
                vecVentas[j+1] = aux;
            }
        }
    }

    /// Muestro las ventas ya ordenadas
    rlutil::cls();
    menu.mostrarLogo();

    // Posicionar el titulo
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== LISTADO DE VENTAS ORDENADAS POR FECHA ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "=============================================";

    // Encabezado de la tabla con colores
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Monto";
    rlutil::locate(42, 11);
    cout << "Fecha";
    rlutil::locate(55, 11);
    cout << "Cliente";
    rlutil::locate(65, 11);
    cout << "Vendedor";
    rlutil::locate(75, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    // Mostrar las ventas
    int fila = 13;
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

        // Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        // Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(65, fila);
        cout << vecVentas[i].getIdVendedor();

        rlutil::locate(75, fila);
        // Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    // Línea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    // Total de ventas
    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas: " << cantidadRegistros;

    // Mensaje de espera
    rlutil::locate(5, fila + 4);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::listadoVentasPorVendedor()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    ArchivoVendedor archivoVendedor("vendedor.dat");
    Venta aux;
    Venta *vecVentas = nullptr;
    Vendedor vendedor;

    int cantidadRegistros = archivoVenta.CantidadRegistros();
    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para mostrar." << endl;
        system("pause");
        return;
    }

    vecVentas = new Venta[cantidadRegistros];

    if(vecVentas == nullptr)
    {
        return;
    }

    /// Cargo las ventas en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVenta.Leer(i);
        vecVentas[i] = aux;
    }

    /// Bubble sort (ordenar por ID de vendedor)
    for(int i = 0; i < cantidadRegistros; i++)
    {
        for(int j = 0; j < cantidadRegistros - i - 1; j++)
        {
            if(vecVentas[j].getIdVendedor() > vecVentas[j+1].getIdVendedor())
            {
                aux = vecVentas[j];
                vecVentas[j] = vecVentas[j+1];
                vecVentas[j+1] = aux;
            }
        }
    }

    /// Muestro las ventas ya ordenadas
    rlutil::cls();
    menu.mostrarLogo();

    // Posicionar el titulo
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== LISTADO DE VENTAS ORDENADAS POR VENDEDOR ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===============================================";

    // Encabezado de la tabla con colores
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Monto";
    rlutil::locate(42, 11);
    cout << "Fecha";
    rlutil::locate(55, 11);
    cout << "Cliente";
    rlutil::locate(65, 11);
    cout << "Vendedor";
    rlutil::locate(85, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "---------------------------------------------------------------------------------------";

    // Mostrar las ventas
    int fila = 13;
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

        // Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        // Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(65, fila);
        // Buscar y mostrar el nombre del vendedor
        int posVendedor = archivoVendedor.buscarVendedorPorID(vecVentas[i].getIdVendedor());
        if(posVendedor >= 0)
        {
            vendedor = archivoVendedor.Leer(posVendedor);
            cout << vendedor.getNombre() << " " << vendedor.getApellido();
        }
        else
        {
            cout << "ID: " << vecVentas[i].getIdVendedor() << " (No encontrado)";
        }

        rlutil::locate(85, fila);
        // Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    // Línea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "---------------------------------------------------------------------------------------";

    // Total de ventas
    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas: " << cantidadRegistros;

    // Mensaje de espera
    rlutil::locate(5, fila + 4);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::listadoVentasPorMarca()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    ArchivoAutoUsado archivoAutoUsado("autousado.dat");
    Venta aux;
    Venta *vecVentas = nullptr;
    AutoNuevo autoNuevo;
    AutoUsado autoUsado;

    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para mostrar." << endl;
        system("pause");
        return;
    }

    vecVentas = new Venta[cantidadRegistros];

    if(vecVentas == nullptr)
    {
        return;
    }

    /// Cargo las ventas en el vector
    for(int i = 0; i < cantidadRegistros; i++)
    {
        aux = archivoVenta.Leer(i);
        vecVentas[i] = aux;
    }

    /// Muestro las ventas con marca incluida
    rlutil::cls();
    menu.mostrarLogo();

    // Posicionar el titulo
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== LISTADO DE VENTAS CON MARCA ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===================================";

    // Encabezado de la tabla con colores
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Marca";
    rlutil::locate(40, 11);
    cout << "Monto";
    rlutil::locate(57, 11);
    cout << "Fecha";
    rlutil::locate(70, 11);
    cout << "Cliente";
    rlutil::locate(80, 11);
    cout << "Vendedor";
    rlutil::locate(90, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------";

    // Mostrar las ventas
    int fila = 13;
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

        // Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        /// Buscar y mostrar la marca del auto
        const char* marca = nullptr;
        char numeroPatente[10];
        char numeroChasis[10];
        strcpy(numeroPatente, vecVentas[i].getPatente().getNumeroPatente());
        strcpy(numeroChasis, vecVentas[i].getPatente().getNumeroChasis());

        /// Primero buscar en autos nuevos por numero de chasis
        int pos = archivoAutoNuevo.Buscar(numeroChasis);
        if(pos >= 0)
        {
            autoNuevo = archivoAutoNuevo.Leer(pos);
            marca = autoNuevo.getMarca();
        }
        else
        {
            /// Si no se encuentra en autos nuevos, buscar en autos usados por patente
            pos = archivoAutoUsado.BuscarAutoUsadoPorNumeroDePatente(numeroPatente);
            if(pos >= 0)
            {
                autoUsado = archivoAutoUsado.Leer(pos);
                marca = autoUsado.getMarca();
            }
        }

        if(marca)
        {
            cout << marca;
        }
        else
        {
            cout << "N/A";
        }

        rlutil::locate(40, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();

        rlutil::locate(57, fila);
        // Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(70, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(80, fila);
        cout << vecVentas[i].getIdVendedor();

        rlutil::locate(90, fila);
        // Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    // Línea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------";

    // Total de ventas
    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas: " << cantidadRegistros;

    // Mensaje de espera
    rlutil::locate(5, fila + 4);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}


/// --------------------------------------------------------- CONSULTAS --------------------------------------------------------- ///


void Venta::consultaVentasPorCliente()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    ArchivoCliente archivoCliente("clientes.dat");
    Venta venta;
    Cliente cliente;
    Venta *vecVentas = nullptr;

    char dniCliente[12];
    int idCliente = -1;
    int cantidadVentas = 0;
    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar DNI del cliente
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE VENTAS POR CLIENTE ===" << endl;
    cout << "======================================" << endl;
    cout << endl;

    cin.ignore();
    cout << "Ingrese el DNI del cliente: ";
    cin.getline(dniCliente, sizeof(dniCliente));
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        menu.mostrarLogo();
        cout << "Error: Ingreso demasiados caracteres." << endl;
        system("pause");
    }

    // Buscar el cliente por DNI
    int posCliente = archivoCliente.buscarClientePorDNI(dniCliente);
    if(posCliente == -1)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Error: No se encontro un cliente con el DNI " << dniCliente << endl;
        system("pause");
        return;
    }

    /// Obtener informacion del cliente
    cliente = archivoCliente.Leer(posCliente);
    idCliente = cliente.getIdCliente();

    /// Contar cuantas ventas tiene este cliente
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getIdCliente() == idCliente && venta.getEstado() == true)
        {
            cantidadVentas++;
        }
    }

    if(cantidadVentas == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "El cliente " << cliente.getNombre() << " " << cliente.getApellido() << " (DNI: " << dniCliente << ") no tiene ventas registradas." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vector para almacenar las ventas del cliente
    vecVentas = new Venta[cantidadVentas];

    if(vecVentas == nullptr)
    {
        cout << "Error: No se pudo asignar memoria." << endl;
        system("pause");
        return;
    }

    /// Cargar las ventas del cliente en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getIdCliente() == idCliente && venta.getEstado() == true)
        {
            vecVentas[j] = venta;
            j++;
        }
    }

    /// Mostrar las ventas del cliente
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion del cliente
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== VENTAS DEL CLIENTE ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "==========================";

    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Cliente: " << cliente.getNombre() << " " << cliente.getApellido();
    rlutil::locate(5, 12);
    cout << "DNI: " << cliente.getDni();
    rlutil::locate(5, 13);
    cout << "Telefono: " << cliente.getNumeroTelefono();
    rlutil::locate(5, 14);
    cout << "Email: " << cliente.getEmail();

    rlutil::locate(5, 16);
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "Total de ventas: " << cantidadVentas;

    // Encabezado de la tabla
    rlutil::locate(5, 18);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 18);
    cout << "Patente";
    rlutil::locate(25, 18);
    cout << "Monto";
    rlutil::locate(42, 18);
    cout << "Fecha";
    rlutil::locate(55, 18);
    cout << "Vendedor";
    rlutil::locate(75, 18);
    cout << "Estado";

    rlutil::locate(5, 19);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    // Mostrar las ventas
    int fila = 20;
    float totalMonto = 0.0f;

    for(int i = 0; i < cantidadVentas; i++)
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

        /// Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();
        totalMonto += vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        // Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << "ID: " << vecVentas[i].getIdVendedor();

        rlutil::locate(75, fila);
        // Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    // Línea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    // Resumen
    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas: " << cantidadVentas;

    rlutil::locate(5, fila + 3);
    cout << "Monto total: $" << fixed << setprecision(2) << totalMonto;

    // Mensaje de espera
    rlutil::locate(5, fila + 5);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::consultaVentasPorVendedor()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    ArchivoVendedor archivoVendedor("vendedor.dat");
    Venta venta;
    Vendedor vendedor;
    Venta *vecVentas = nullptr;

    char dniVendedor[12];
    int idVendedor = -1;
    int cantidadVentas = 0;
    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar DNI del vendedor
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE VENTAS POR VENDEDOR ===" << endl;
    cout << "=======================================" << endl;
    cout << endl;

    cin.ignore();
    cout << "Ingrese el DNI del vendedor: ";
    cin.getline(dniVendedor, sizeof(dniVendedor));
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        menu.mostrarLogo();
        cout << "Error: Ingreso demasiados caracteres." << endl;
        system("pause");
        return;
    }

    /// Buscar el vendedor por DNI
    int posVendedor = archivoVendedor.buscarVendedorPorDNI(dniVendedor);
    if(posVendedor == -1)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Error: No se encontro un vendedor con el DNI " << dniVendedor << endl;
        system("pause");
        return;
    }

    /// Obtener informacion del vendedor
    vendedor = archivoVendedor.Leer(posVendedor);
    idVendedor = vendedor.getIdVendedor();

    /// Contar cuantas ventas tiene este vendedor
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getIdVendedor() == idVendedor && venta.getEstado() == true)
        {
            cantidadVentas++;
        }
    }

    if(cantidadVentas == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "El vendedor " << vendedor.getNombre() << " " << vendedor.getApellido() << " (DNI: " << dniVendedor << ") no tiene ventas registradas." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vector para almacenar las ventas del vendedor
    vecVentas = new Venta[cantidadVentas];

    if(vecVentas == nullptr)
    {
        cout << "Error: No se pudo asignar memoria." << endl;
        system("pause");
        return;
    }

    /// Cargar las ventas del vendedor en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getIdVendedor() == idVendedor && venta.getEstado() == true)
        {
            vecVentas[j] = venta;
            j++;
        }
    }

    /// Mostrar las ventas del vendedor
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion del vendedor
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== VENTAS DEL VENDEDOR ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===========================";

    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Vendedor: " << vendedor.getNombre() << " " << vendedor.getApellido();
    rlutil::locate(5, 12);
    cout << "DNI: " << vendedor.getDni();
    rlutil::locate(5, 13);
    cout << "Telefono: " << vendedor.getNumeroTelefono();
    rlutil::locate(5, 14);
    cout << "Email: " << vendedor.getEmail();

    /// Encabezado de la tabla
    rlutil::locate(5, 18);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 18);
    cout << "Patente";
    rlutil::locate(25, 18);
    cout << "Monto";
    rlutil::locate(42, 18);
    cout << "Fecha";
    rlutil::locate(55, 18);
    cout << "Cliente";
    rlutil::locate(75, 18);
    cout << "Estado";

    rlutil::locate(5, 19);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    /// Mostrar las ventas
    int fila = 20;
    float totalMonto = 0.0f;

    for(int i = 0; i < cantidadVentas; i++)
    {
        /// Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        /// Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();
        totalMonto += vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        /// Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << "ID: " << vecVentas[i].getIdCliente();

        rlutil::locate(75, fila);
        /// Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    /// Linea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    /// Resumen
    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas: " << cantidadVentas;

    rlutil::locate(5, fila + 3);
    cout << "Monto total: $" << fixed << setprecision(2) << totalMonto;

    /// Mensaje de espera
    rlutil::locate(5, fila + 5);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::consultaVentasPorFecha()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    Venta venta;
    Venta *vecVentas = nullptr;

    int anioConsulta;
    int cantidadVentas = 0;
    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar año de consulta

    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE VENTAS POR FECHA ===" << endl;
    cout << "====================================" << endl;
    cout << endl;

    cout << "Ingrese el anio para consultar las ventas: ";
    cin >> anioConsulta;
    if(cin.fail() || anioConsulta < 1900 || anioConsulta > 2025)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Ingrese un anio valido." << endl;
        system("pause");
        return;
    }


    /// Contar cuantas ventas hay en ese año
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getFechaDeVenta().getAnio() == anioConsulta && venta.getEstado() == true)
        {
            cantidadVentas++;
        }
    }

    if(cantidadVentas == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se encontraron ventas registradas en el anio " << anioConsulta << "." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vector para almacenar las ventas del año
    vecVentas = new Venta[cantidadVentas];

    if(vecVentas == nullptr)
    {
        cout << "Error: No se pudo asignar memoria." << endl;
        system("pause");
        return;
    }

    /// Cargar las ventas del año en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getFechaDeVenta().getAnio() == anioConsulta && venta.getEstado() == true)
        {
            vecVentas[j] = venta;
            j++;
        }
    }

    /// Mostrar las ventas del año
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion de la consulta
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== VENTAS DEL ANIO " << anioConsulta << " ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===============================";

    /// Encabezado de la tabla
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Monto";
    rlutil::locate(42, 11);
    cout << "Fecha";
    rlutil::locate(55, 11);
    cout << "Cliente";
    rlutil::locate(65, 11);
    cout << "Vendedor";
    rlutil::locate(75, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    /// Mostrar las ventas
    int fila = 13;
    float totalMonto = 0.0f;

    for(int i = 0; i < cantidadVentas; i++)
    {
        /// Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        /// Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();
        totalMonto += vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        /// Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(65, fila);
        cout << vecVentas[i].getIdVendedor();

        rlutil::locate(75, fila);
        /// Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas en " << anioConsulta << ": " << cantidadVentas;

    rlutil::locate(5, fila + 3);
    cout << "Monto total: $" << fixed << setprecision(2) << totalMonto;

    rlutil::locate(5, fila + 5);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::consultaVentasPorMarca()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    ArchivoAutoNuevo archivoAutoNuevo("autonuevo.dat");
    ArchivoAutoUsado archivoAutoUsado("autousado.dat");
    Venta venta;
    Venta *vecVentas = nullptr;
    AutoNuevo autoNuevo;
    AutoUsado autoUsado;

    char marcaConsulta[50];
    int cantidadVentas = 0;
    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar marca de consulta
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE VENTAS POR MARCA ===" << endl;
    cout << "====================================" << endl;
    cout << endl;

    cin.ignore();
    cout << "Ingrese la marca para consultar las ventas: ";
    cin.getline(marcaConsulta, sizeof(marcaConsulta));
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        menu.mostrarLogo();
        cout << "Error: Ingreso demasiados caracteres." << endl;
        system("pause");
        return;
    }

    /// Contar cuantas ventas hay de esa marca
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getEstado() == true)
        {
            /// Buscar la marca del auto en esta venta
            bool marcaEncontrada = false;

            /// Buscar en autos nuevos
            int cantidadAutosNuevos = archivoAutoNuevo.CantidadRegistros();
            for(int j = 0; j < cantidadAutosNuevos; j++)
            {
                autoNuevo = archivoAutoNuevo.Leer(j);
                if(strcmp(autoNuevo.getMarca(), marcaConsulta) == 0)
                {
                    marcaEncontrada = true;
                    break;
                }
            }

            /// Buscar en autos usados
            int cantidadAutosUsados = archivoAutoUsado.CantidadRegistros();
            for(int k = 0; k < cantidadAutosUsados; k++)
            {
                autoUsado = archivoAutoUsado.Leer(k);
                if(strcmp(autoUsado.getMarca(), marcaConsulta) == 0)
                {
                    marcaEncontrada = true;
                    break;
                }
            }

            /// Si la marca coincide, contar la venta
            if(marcaEncontrada)
            {
                cantidadVentas++;
            }
        }
    }

    if(cantidadVentas == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se encontraron ventas registradas de la marca " << marcaConsulta << "." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vector para almacenar las ventas de esa marca
    vecVentas = new Venta[cantidadVentas];
    if(vecVentas == nullptr)
    {
        cout << "Error: No se pudo asignar memoria." << endl;
        system("pause");
        return;
    }

    /// Cargar las ventas de esa marca en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getEstado() == true)
        {
            /// Buscar la marca del auto en esta venta
            bool marcaEncontrada = false;

            /// Buscar en autos nuevos
            int cantidadAutosNuevos = archivoAutoNuevo.CantidadRegistros();
            for(int k = 0; k < cantidadAutosNuevos; k++)
            {
                autoNuevo = archivoAutoNuevo.Leer(k);
                if(strcmp(autoNuevo.getMarca(), marcaConsulta) == 0)
                {
                    marcaEncontrada = true;
                    break;
                }
            }

            /// Buscar en autos usados
            int cantidadAutosUsados = archivoAutoUsado.CantidadRegistros();
            for(int l = 0; l < cantidadAutosUsados; l++)
            {
                autoUsado = archivoAutoUsado.Leer(l);
                if(strcmp(autoUsado.getMarca(), marcaConsulta) == 0)
                {
                    marcaEncontrada = true;
                    break;
                }
            }

            /// Si la marca coincide, agregar la venta al vector
            if(marcaEncontrada)
            {
                vecVentas[j] = venta;
                j++;
            }
        }
    }

    /// Mostrar las ventas de esa marca
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion de la consulta
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== VENTAS DE LA MARCA " << marcaConsulta << " ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "=================================";

    /// Encabezado de la tabla
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Marca";
    rlutil::locate(40, 11);
    cout << "Monto";
    rlutil::locate(57, 11);
    cout << "Fecha";
    rlutil::locate(70, 11);
    cout << "Cliente";
    rlutil::locate(80, 11);
    cout << "Vendedor";
    rlutil::locate(90, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------";

    /// Mostrar las ventas
    int fila = 13;
    float totalMonto = 0.0f;

    for(int i = 0; i < cantidadVentas; i++)
    {
        /// Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        /// Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        cout << marcaConsulta;

        rlutil::locate(40, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();
        totalMonto += vecVentas[i].getMonto();

        rlutil::locate(57, fila);
        /// Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(70, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(80, fila);
        cout << vecVentas[i].getIdVendedor();

        rlutil::locate(90, fila);
        /// Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "-------------------------------------------------------------------------------------------";

    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas de " << marcaConsulta << ": " << cantidadVentas;

    rlutil::locate(5, fila + 3);
    cout << "Monto total: $" << fixed << setprecision(2) << totalMonto;

    rlutil::locate(5, fila + 5);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}

void Venta::consultaVentasPorRangoDePrecios()
{
    Menu menu;
    ArchivoVenta archivoVenta("ventas.dat");
    Venta venta;
    Venta *vecVentas = nullptr;

    float precioMinimo, precioMaximo;
    int cantidadVentas = 0;
    int cantidadRegistros = archivoVenta.CantidadRegistros();

    if(cantidadRegistros == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No hay ventas registradas para consultar." << endl;
        system("pause");
        return;
    }

    /// Solicitar rango de precios
    system("cls");
    menu.mostrarLogo();
    cout << "=== CONSULTA DE VENTAS POR RANGO DE PRECIOS ===" << endl;
    cout << "===============================================" << endl;
    cout << endl;

    /// Solicitar precio minimo
    cout << "Ingrese el precio minimo: $";
    cin >> precioMinimo;
    if(cin.fail() || precioMinimo < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Ingrese un precio minimo valido." << endl;
        system("pause");
        return;
    }

    /// Solicitar precio maximo
    cout << "Ingrese el precio maximo: $";
    cin >> precioMaximo;
    if(cin.fail() || precioMaximo < 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Error: Ingrese un precio maximo valido." << endl;
        system("pause");
        return;
    }

    /// Validar que el precio maximo sea mayor al minimo
    if(precioMaximo < precioMinimo)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "Error: El precio maximo debe ser mayor o igual al precio minimo." << endl;
        system("pause");
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getEstado() == true && venta.getMonto() >= precioMinimo && venta.getMonto() <= precioMaximo)
        {
            cantidadVentas++;
        }
    }

    if(cantidadVentas == 0)
    {
        system("cls");
        menu.mostrarLogo();
        cout << "No se encontraron ventas registradas entre $" << fixed << setprecision(2) << precioMinimo << " y $" << precioMaximo << "." << endl;
        cout << endl;
        system("pause");
        return;
    }

    /// Crear vector para almacenar las ventas del rango
    vecVentas = new Venta[cantidadVentas];
    if(vecVentas == nullptr)
    {
        cout << "Error: No se pudo asignar memoria." << endl;
        system("pause");
        return;
    }

    /// Cargar las ventas del rango en el vector
    int j = 0;
    for(int i = 0; i < cantidadRegistros; i++)
    {
        venta = archivoVenta.Leer(i);
        if(venta.getEstado() == true && venta.getMonto() >= precioMinimo && venta.getMonto() <= precioMaximo)
        {
            vecVentas[j] = venta;
            j++;
        }
    }

    /// Mostrar las ventas del rango
    rlutil::cls();
    menu.mostrarLogo();

    /// Informacion de la consulta
    rlutil::locate(5, 8);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "=== VENTAS ENTRE $" << fixed << setprecision(2) << precioMinimo << " Y $" << precioMaximo << " ===";
    rlutil::locate(5, 9);
    rlutil::setColor(rlutil::WHITE);
    cout << "===============================================";

    /// Encabezado de la tabla
    rlutil::locate(5, 11);
    rlutil::setColor(rlutil::YELLOW);
    cout << "ID";
    rlutil::locate(12, 11);
    cout << "Patente";
    rlutil::locate(25, 11);
    cout << "Monto";
    rlutil::locate(42, 11);
    cout << "Fecha";
    rlutil::locate(55, 11);
    cout << "Cliente";
    rlutil::locate(65, 11);
    cout << "Vendedor";
    rlutil::locate(75, 11);
    cout << "Estado";

    rlutil::locate(5, 12);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    /// Mostrar las ventas
    int fila = 13;
    float totalMonto = 0.0f;

    for(int i = 0; i < cantidadVentas; i++)
    {
        /// Alternar colores para las filas
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }

        /// Posicionar cada columna individualmente
        rlutil::locate(5, fila);
        cout << vecVentas[i].getIdVenta();

        rlutil::locate(12, fila);
        cout << vecVentas[i].getPatente().getNumeroPatente();

        rlutil::locate(25, fila);
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << "$" << fixed << setprecision(2) << vecVentas[i].getMonto();
        totalMonto += vecVentas[i].getMonto();

        rlutil::locate(42, fila);
        /// Volver al color de la fila
        if(i % 2 == 0)
        {
            rlutil::setColor(rlutil::WHITE);
        }
        else
        {
            rlutil::setColor(rlutil::GREY);
        }
        cout << vecVentas[i].getFechaDeVenta().toString();

        rlutil::locate(55, fila);
        cout << vecVentas[i].getIdCliente();

        rlutil::locate(65, fila);
        cout << vecVentas[i].getIdVendedor();

        rlutil::locate(75, fila);
        /// Color especial para el estado
        if(vecVentas[i].getEstado())
        {
            rlutil::setColor(rlutil::LIGHTGREEN);
            cout << "ACTIVA";
        }
        else
        {
            rlutil::setColor(rlutil::LIGHTRED);
            cout << "INACTIVA";
        }

        fila++;
    }

    /// Linea final de la tabla
    rlutil::locate(5, fila);
    rlutil::setColor(rlutil::WHITE);
    cout << "--------------------------------------------------------------------------------";

    rlutil::locate(5, fila + 2);
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Total de ventas en el rango: " << cantidadVentas;

    rlutil::locate(5, fila + 5);
    rlutil::setColor(rlutil::WHITE);
    system("pause");

    rlutil::setColor(rlutil::WHITE);

    delete[] vecVentas;
}




