#pragma once
#include "rlutil.h"

class Menu
{
    public:
        void mostrarPantallaPrincipal();
        void mostrarMenuPrincipal();
        void mostrarLogo();
        void mostrarLogoAnimado();
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

    protected:

    private:
};


