#ifndef BASIC_H
#define BASIC_H

#include <vector>
#include <string>
#include <iostream>
#include <sqlite3.h>
#include <algorithm>

typedef std::vector<std::vector<std::string>> vvs;


const void ShowContact(const vvs temp);

class MyDatabase
{
    private:
    sqlite3 *db;
    char* ErrorMessage = 0;
    static int CallBack(void* data,int argc,char** argv,char** columns);
    public:
    MyDatabase ();
    vvs ExecuteCommand(const char *sql);
};




#endif