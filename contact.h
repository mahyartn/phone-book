#ifndef CONTACT_H
#define CONTACT_H

#include "basic.h"

class Contact
{
    private:
    MyDatabase db;
    vvs contact_list;
    void LoadContacts();
    public:
    Contact();
    bool AddContact(std::string fname,std::string lname,std::string phone);
    vvs ShowContacts();
    vvs SearchContacts(std::string fname,std::string lname);
    void SortByFName();
    void SortByLName();
    void SortByPhone();
};

class ContactCLI
{
    private:
    Contact cnts;
    public:
    ContactCLI();
    void ViewContacts();
    void SortContacts();
    void SearchContacts();
    void AddContact();
};

#endif