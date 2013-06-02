#ifndef FORNECEDOR_H
#define FORNECEDOR_H

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "baseDAO.h"
#define clear "\e[H\e[2J"
using namespace std;

class Fornecedor
{
    int intTemp;
    string charTemp;
    BaseDAO dao;
    people fornecedor;

    public:

    //Telas
    void getTAll(){
        cout << clear << endl;
        cout.width(10);
        cout << right << "FORNECEDORES" << endl;
        cout << "____________________________________________________________________________" << endl;
        dao.getFornecedores();
        cout << "____________________________________________________________________________" << endl;
        cout << "\nInforme o ID para selecionar ou [x] para ir ao Menu" << endl;
        cout << ": ";
        cin >> charTemp;
        if(charTemp != "x"){
            Fornecedor::getTId(charTemp);
        }
    }

    void setTData(){
        cout << clear << endl;
        cout.width(10);
        cout << right << "CADASTO DE FORNECEDORES" << endl;
        cout << "____________________________________________________________________________" << endl;

        cout << "Nome: ";
        cin.getline(fornecedor.name,100);
        cin.getline(fornecedor.name,100);
        cout << "fone: ";
        cin.getline(fornecedor.fone,100);
        cout << "email: ";
        cin.getline(fornecedor.email,100);

        dao.setFornecedor(fornecedor.name, fornecedor.fone, fornecedor.email);
        cout << clear << endl;
        cout << "Seu registro foi inserido com sucesso" << endl;
        cout << "____________________________________________________________________________" << endl;
        cout << "\nVoltar [Enter]";
        cin.get();
    }

    void getTId(string id){
        if(id == ""){
            cout << clear << "Informe o ID";
            cout << "\n__________________________________________________________\n:";
            cin >> charTemp;
            Fornecedor::getTId(charTemp);
        } else{
            cout << clear << endl;
            cout.width(10);
            cout << right << "FORNECEDOR SELECIONADO" << endl;
            cout << "____________________________________________________________________________" << endl;
            dao.getFornecedor(id);
            cout << "____________________________________________________________________________" << endl;
            cout << "\nVoltar [1] | Excluir [2] | Editar [3]" << endl;
            cout << ": ";
            cin >> intTemp;

            switch (intTemp) {
            case 2:
                dao.deleteFornecedor(id);
                break;
            case 3:
                Fornecedor::getTPut(id);
                break;
            default:
                break;
            }
        }
    }

    void getTName(){
        cout << clear << "Informe o Nome";
        cout << "\n__________________________________________________________\n:";
        cin >> charTemp;

        cout << clear << endl;
        cout.width(10);
        cout << right << "RESULTADO" << endl;
        cout << "____________________________________________________________________________" << endl;
        dao.getFornecedorName(charTemp);
        cout << "____________________________________________________________________________" << endl;
        cout << "\nInforme o ID para selecionar ou [x] para ir ao Menu" << endl;
        cout << ": ";
        cin >> charTemp;
        if(charTemp != "x"){
            Fornecedor::getTId(charTemp);
        }
    }

    void getTPut(string id){
        cout << clear << endl;
        cout << "Qual coluna deseja editar: ";
        dao.getFornecedorCol();
        cout << "____________________________________________________________________________" << endl;
        cout << ": ";
        cin >> intTemp;
        cout << clear << endl;
        cout << right << "INFORME O NOVO VALOR" << endl;
        cout << "____________________________________________________________________________" << endl;
        cout << ": ";
        cin.getline(fornecedor.name,100);
        cin.getline(fornecedor.name,100);
        dao.putFornecedor(id,intTemp,fornecedor.name);
    }
};

#endif // FORNECEDOR_H
