#include "basic.h"

const void ShowContact(const vvs temp)
{
  std::string phonebook[3]={"First Name: ","Last Name: ","Phone Number: "};  
  for (int i=0;i<temp.size();i++)
        {
            for (int j=0;j<3;j++) std::cout <<phonebook[j]<<temp[i][j]<<"\n";
            std::cout <<"\n";
        }
  std::cin.get();
  std::cin.ignore();
  
}

MyDatabase::MyDatabase()
{
    auto rc = sqlite3_open("phone-book.db",&db);
    if( rc ) 
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    } 
    else 
    {
        fprintf(stderr, "Opened database successfully\n");
    }
}


int MyDatabase::CallBack(void* data,int argc,char** argv,char** columns)
{
    vvs* MyVec=(vvs*)data;
    std::vector<std::string> temp;
    for (int i=0;i<argc;i++)
    {
        if (argv[i]!=NULL)
        {
            temp.push_back(argv[i]);
        }
        else
        {
            temp.push_back("");
        }
    }
    MyVec->push_back(temp);
    return 0;
}

vvs MyDatabase::ExecuteCommand(const char *sql)
{
    vvs str_vec;
    auto rc = sqlite3_exec(db, sql, CallBack, (void*) &str_vec, &ErrorMessage);
    if( rc != SQLITE_OK ){
      fprintf(stderr, "SQL error: %s\n", ErrorMessage);
      sqlite3_free(ErrorMessage);
    } 
    return str_vec;
}