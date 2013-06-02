// ATPS 2013 - ANHANGUERA
// Miller Augusto S Martins
// RA: 5663130672

// Dependencias:
// sudo apt-get install sqlite3 libsqlite3-dev
// sudo add-apt-repository ppa:canonical-qt5-edgers/qt5-proper && sudo add-apt-repository ppa:ubuntu-sdk-team/ppa && sudo apt-get update && sudo apt-get install ubuntu-sdk
// Para compilar utilize :~$ g++ main.cpp -lsqlite3

#include <iostream>
#include <stdlib.h>
#include "people.h"
#include "menu.h"
#define clear "\e[H\e[2J"

using namespace std;
int Menu::opcMenu = 0;
int Menu::opcSubMenu = 0;

int main()
{
    Menu menuSys;
    menuSys.getMenu();
    return 0;
}
