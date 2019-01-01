#include "basic.h"
#include "contact.h"

std::string FunctionMenu="what do you want to do?(type in lower case)\n"\
"    a- Show all Contacts\n"\
"    b- Add a new contact\n"\
"    c- search for contact(s)\n"\
"    d- Sort contacts\n"\
"    z- Logout\n\n"\
"your choice: ";



int main()
{
    ContactCLI phonebook;
    bool RunningProgram=true;
    while (RunningProgram)
    {
        system ("clear");
        std::cout<<FunctionMenu;
        char choice;
        std::cin >> choice;  
        switch (choice) 
        {
            case 'a':
            phonebook.ViewContacts();
            break;
            case 'b':
            phonebook.AddContact();
            break;
            case 'c':
            phonebook.SearchContacts();
            break;
            case 'd':
            phonebook.SortContacts();
            break;
            case 'z':
            RunningProgram=false;
            break;
            default:
            break;
        }

    }
}
