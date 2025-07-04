#pragma once
#include "rlutil.h"

class Menu
{
    public:
        void mostrarPantallaPrincipal();
        void mostrarMenuPrincipal();
        void mostrarLogo();
        void mostrarLogoAnimado();
        void mostrarLogoSalida();
        void mostrarMenuClientes();
        void mostrarMenuVendedores();
        void mostrarMenuVentas();
        void mostrarMenuListados();
        void mostrarMenuConsultas();
        void subMenuBuscarVendedor();
        void subMenuBuscarCliente();


        void mostrarMenuAutos();

        /// Autos nuevos
        void menuAutosNuevos();
        void subMenuBuscarAutoNuevo();

        /// Autos usados
        void menuAutosUsados();
        void subMenuBuscarAutoUsado();

        /// Listados
        void mostrarMenuListadosVentas();
        void mostrarMenuListadosClientes();
        void mostrarMenuListadosVendedores();
        void mostrarMenuListadosAutosNuevos();
        void mostrarMenuListadosAutosUsados();

        /// Consultas
        void mostrarMenuConsultasVentas();
        void mostrarMenuConsultasAutos();

    private:
};


