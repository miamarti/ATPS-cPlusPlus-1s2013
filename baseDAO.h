#ifndef BASEDAO_H
#define BASEDAO_H
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#define clear "\e[H\e[2J"
using namespace std;

class BaseDAO
{
    string createQuery;
    int status;
    int intTemp = 1;

    public:

    //Cliente

    void getClientes(){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM clientes WHERE enable = 1";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                switch (col) {
                case 0:
                    cout.width(3);
                    break;
                case 1:
                    cout.width(20);
                    break;
                case 2:
                    cout.width(15);
                    break;
                case 3:
                    cout.width(30);
                    break;
                }

                cout << left << sqlite3_column_name(createStmt,col);
                cout << " | ";
            }
            cout << endl;

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {

                        const char *val = (const char*)sqlite3_column_text(createStmt,col);

                        switch (col) {
                        case 0:
                            cout.width(3);
                            break;
                        case 1:
                            cout.width(20);
                            break;
                        case 2:
                            cout.width(15);
                            break;
                        case 3:
                            cout.width(30);
                            break;
                        }

                        cout << val;
                        cout << " | ";
                    }
                    cout << endl;
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    int setCliente(string name, string fone, string email){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "INSERT INTO 'clientes' ('name', 'fone', 'email', 'enable') VALUES ('" + name + "', '" + fone + "', '" + email + "', '1');";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao inserir Cliente" << endl;
            sqlite3_close(db);
            return 1;
        } else{
            return 0;
        }
    }

    void getCliente(string id){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM clientes WHERE enable = 1 AND id = " + id + ";";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {
                        const char *val = (const char*)sqlite3_column_text(createStmt,col);
                        cout << sqlite3_column_name(createStmt,col) << ": " << val << endl;
                    }
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    void getClienteName(string name){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM clientes WHERE enable = 1 AND name like '%" + name + "%'";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                switch (col) {
                case 0:
                    cout.width(3);
                    break;
                case 1:
                    cout.width(20);
                    break;
                case 2:
                    cout.width(15);
                    break;
                case 3:
                    cout.width(30);
                    break;
                }

                cout << left << sqlite3_column_name(createStmt,col);
                cout << " | ";
            }
            cout << endl;

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {

                        const char *val = (const char*)sqlite3_column_text(createStmt,col);

                        switch (col) {
                        case 0:
                            cout.width(3);
                            break;
                        case 1:
                            cout.width(20);
                            break;
                        case 2:
                            cout.width(15);
                            break;
                        case 3:
                            cout.width(30);
                            break;
                        }

                        cout << val;
                        cout << " | ";
                    }
                    cout << endl;
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    int deleteCliente(string id){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            //createQuery = "DELETE FROM clientes WHERE id=" + id + ";";
            createQuery = "UPDATE clientes SET enable='0' WHERE id=" + id + ";";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao remover Cliente" << endl;
            sqlite3_close(db);
            return 1;
        } else{
            return 0;
        }
    }

    int putCliente(string id, int col, char val[100]){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT name, fone, email FROM clientes WHERE enable = 1";
            sqlite3_stmt *createStmt;

            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            string colname = sqlite3_column_name(createStmt,col);

            createQuery = "UPDATE clientes SET " + colname + "='" + val + "' WHERE id=" + id + ";";
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao atualizar Cliente" << endl;
            sqlite3_close(db);

            return 1;
        } else{
            return 0;
        }
    }

    void getClienteCol(){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT name, fone, email FROM clientes WHERE enable = 1";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                cout << left << sqlite3_column_name(createStmt,col) << "[" << col << "]";
                cout << " | ";
            }
            cout << endl;
        }
        sqlite3_close(db);
    }


    //Fornecedores

    void getFornecedores(){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM fornecedores WHERE enable = 1";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                switch (col) {
                case 0:
                    cout.width(3);
                    break;
                case 1:
                    cout.width(20);
                    break;
                case 2:
                    cout.width(15);
                    break;
                case 3:
                    cout.width(30);
                    break;
                }

                cout << left << sqlite3_column_name(createStmt,col);
                cout << " | ";
            }
            cout << endl;

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {

                        const char *val = (const char*)sqlite3_column_text(createStmt,col);

                        switch (col) {
                        case 0:
                            cout.width(3);
                            break;
                        case 1:
                            cout.width(20);
                            break;
                        case 2:
                            cout.width(15);
                            break;
                        case 3:
                            cout.width(30);
                            break;
                        }

                        cout << val;
                        cout << " | ";
                    }
                    cout << endl;
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    int setFornecedor(string name, string fone, string email){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "INSERT INTO 'fornecedores' ('name', 'fone', 'email', 'enable') VALUES ('" + name + "', '" + fone + "', '" + email + "', '1');";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao inserir Fornecedores" << endl;
            sqlite3_close(db);
            return 1;
        } else{
            return 0;
        }
    }

    void getFornecedor(string id){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM fornecedores WHERE enable = 1 AND id = " + id + ";";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {
                        const char *val = (const char*)sqlite3_column_text(createStmt,col);
                        cout << sqlite3_column_name(createStmt,col) << ": " << val << endl;
                    }
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    void getFornecedorName(string name){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT id, name, fone, email FROM fornecedores WHERE enable = 1 AND name like '%" + name + "%'";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                switch (col) {
                case 0:
                    cout.width(3);
                    break;
                case 1:
                    cout.width(20);
                    break;
                case 2:
                    cout.width(15);
                    break;
                case 3:
                    cout.width(30);
                    break;
                }

                cout << left << sqlite3_column_name(createStmt,col);
                cout << " | ";
            }
            cout << endl;

            while(1){
                status = sqlite3_step(createStmt);
                if(status == SQLITE_ROW){
                    for(int col=0 ; col < cols; col++) {

                        const char *val = (const char*)sqlite3_column_text(createStmt,col);

                        switch (col) {
                        case 0:
                            cout.width(3);
                            break;
                        case 1:
                            cout.width(20);
                            break;
                        case 2:
                            cout.width(15);
                            break;
                        case 3:
                            cout.width(30);
                            break;
                        }

                        cout << val;
                        cout << " | ";
                    }
                    cout << endl;
                } else {
                    break;
                }
            }

        } else{
            cout << "Problemas na conexao!" << endl;
        }
        sqlite3_close(db);
        cin.get();
    }

    int deleteFornecedor(string id){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            //createQuery = "DELETE FROM fornecedores WHERE id=" + id + ";";
            createQuery = "UPDATE fornecedores SET enable='0' WHERE id=" + id + ";";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao remover Fornecedores" << endl;
            sqlite3_close(db);
            return 1;
        } else{
            return 0;
        }
    }

    int putFornecedor(string id, int col, char val[100]){
        sqlite3 *db;
        if (sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT name, fone, email FROM fornecedores WHERE enable = 1";
            sqlite3_stmt *createStmt;

            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            string colname = sqlite3_column_name(createStmt,col);

            createQuery = "UPDATE fornecedores SET " + colname + "='" + val + "' WHERE id=" + id + ";";
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            if (sqlite3_step(createStmt) != SQLITE_DONE) cout << "ERRO ao atualizar Fornecedores" << endl;
            sqlite3_close(db);

            return 1;
        } else{
            return 0;
        }
    }

    void getFornecedorCol(){
        sqlite3 *db;
        if(sqlite3_open("atps.db", &db) == SQLITE_OK){
            createQuery = "SELECT name, fone, email FROM fornecedores WHERE enable = 1";
            sqlite3_stmt *createStmt;
            sqlite3_prepare_v2(db, createQuery.c_str(), createQuery.size(), &createStmt, NULL);
            int cols = sqlite3_column_count(createStmt);

            for(int col=0 ; col < cols; col++) {
                cout << left << sqlite3_column_name(createStmt,col) << "[" << col << "]";
                cout << " | ";
            }
            cout << endl;
        }
        sqlite3_close(db);
    }
};

#endif // BASEDAO_H
