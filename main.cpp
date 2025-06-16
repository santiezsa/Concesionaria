#include <iostream>
#include <string>
#include "Menu.h"

using namespace std;

int main()
{
    Menu menu;
    //menu.mostrarPantallaPrincipal();
    //rlutil::setBackgroundColor(rlutil::LIGHTRED);
    //rlutil::setColor(rlutil::WHITE);

    rlutil::cls();
    menu.mostrarMenuPrincipal();
    return 0;
}
