#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <stdlib.h>
#include "cliente.h"
#include "fornecedor.h"
#define clear "\e[H\e[2J"

using namespace std;

class Menu
{
    int menu;
    int intTemp;

    public:
    static int opcMenu;
    static int opcSubMenu;

    void getMenu(){
        cout << clear << "Cliente [1] | Fornecedor [2] | Sair [9]" << endl;
        cout << "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n__________________________________________________________\n:";
        cin >> intTemp;
        if(intTemp > 2){
            cout << clear;
        } else{
            setOpcMenu(intTemp);
            startMenu();
        }
    }

    void getSubMenu(){
        cout << clear << "Consulta ID [1] | Consulta Nome [2] | Cadastro [3] | Listar [4] | Voltar [5]" << endl;
        cout << "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n__________________________________________________________\n:";
    }

    void setOpcMenu(int opc){
        opcMenu = opc;
        menu = 1;
    }

    void setOpcSubMenu(int opc){
        opcSubMenu = opc;
        menu = 2;
    }

    void startMenu(){
        if(menu == 1){
            getSubMenu();
            cin >> intTemp;
            setOpcSubMenu(intTemp);
            startMenu();
        } else{

            if(opcMenu == 1){
                Cliente tContent;

                switch (opcSubMenu) {
                case 1:
                    tContent.getTId("");
                    getMenu();
                    break;
                case 2:
                    tContent.getTName();
                    getMenu();
                    break;
                case 3:
                    tContent.setTData();
                    getMenu();
                    break;
                case 4:
                    tContent.getTAll();
                    getMenu();
                    break;
                default:
                    getMenu();
                    break;
                }
            }

            if(opcMenu == 2){
                Fornecedor tContent;

                switch (opcSubMenu) {
                case 1:
                    tContent.getTId("");
                    getMenu();
                    break;
                case 2:
                    tContent.getTName();
                    getMenu();
                    break;
                case 3:
                    tContent.setTData();
                    getMenu();
                    break;
                case 4:
                    tContent.getTAll();
                    getMenu();
                    break;
                default:
                    getMenu();
                    break;
                }
            }
        }
    }

};

#endif // MENU_H
