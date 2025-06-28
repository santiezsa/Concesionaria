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

            if(strlen(numeroChasis) == 0 || strlen(numeroChasis) > 11)
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
        // Buscar y mostrar la marca del auto
        const char* marca = nullptr;
        char numeroPatente[10];
        strcpy(numeroPatente, vecVentas[i].getPatente().getNumeroPatente());
        
        int pos = archivoAutoNuevo.Buscar(numeroPatente);
        if(pos >= 0)
        {
            autoNuevo = archivoAutoNuevo.Leer(pos);
            marca = autoNuevo.getMarca();
        }
        else
        {
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





