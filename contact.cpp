#include "contact.h"

Contact::Contact()
{
    MyDatabase db;
    std::string sql = "SELECT * FROM contact";
    contact_list = db.ExecuteCommand(sql.c_str());

}


void Contact::LoadContacts()
{
    std::string sql = "SELECT * FROM contact";
    contact_list = db.ExecuteCommand(sql.c_str());
}
bool Contact::AddContact(std::string fname, std::string lname, std::string phone)
{
    std::string sql = "SELECT * FROM contact WHERE FirstName ='" + fname + "'AND LastName ='" + lname + "' AND PhoneNumber ='" + phone + "';";
    vvs temp = db.ExecuteCommand(sql.c_str());
    if (temp.size() > 0)
    {
        return 0;
    }
    sql = "INSERT INTO contact (FirstName,LastName,PhoneNumber) values('" + fname + "','" + lname + "','" + phone + "')";
    db.ExecuteCommand(sql.c_str());
    LoadContacts();
    return 1;
}

vvs Contact::ShowContacts()
{
    return contact_list;
}


vvs Contact::SearchContacts(std::string fname, std::string lname)
{
    std::string sql;
    if (fname == "")
    {
        if (lname == "")
        {
            sql = "SELECT * FROM contact";
        }
        else
        {
            sql = "SELECT * FROM contact WHERE LastName ='" + lname + "';";
        }
    }
    else if (lname == "")
    {
        sql = "SELECT * FROM contact WHERE FirstName ='" + fname + "';";
    }
    else
    {
        sql = "SELECT * FROM contact WHERE FirstName ='" + fname + "'AND LastName ='" + lname + "';";
    }
    vvs temp = db.ExecuteCommand(sql.c_str());
    return temp;
}

bool sortcol1(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
    return v1[0] < v2[0];
}
bool sortcol2(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
    return v1[1] < v2[1];
}
bool sortcol3(const std::vector<std::string> &v1, const std::vector<std::string> &v2)
{
    return v1[2] < v2[2];
}

void Contact::SortByFName()
{
    std::sort(std::begin(contact_list), std::end(contact_list), sortcol1);
}
void Contact::SortByLName()
{
    std::sort(std::begin(contact_list), std::end(contact_list), sortcol2);
}
void Contact::SortByPhone()
{
    std::sort(std::begin(contact_list), std::end(contact_list), sortcol3);
}


/////////////////////////////////////////
//////////////////////////////////////////

ContactCLI::ContactCLI()
{
    Contact cnts;
    system ("clear");
}

void ContactCLI::ViewContacts()
{
    const vvs tmp=cnts.ShowContacts();
    ShowContact(tmp);
}
void ContactCLI::SortContacts()
{
    bool x=true;
    char i;
    while (x==true)
    {
    std::cout <<"How do you want to sort the Phonebook?\n"<<
    "1-firstname  2-lastname  3-Phone number  0-Exit \n";
    std::cin>>i;
    switch (i)
    {
        case '1':
        cnts.SortByFName();
        x=false;
        break;
        case '2':
        cnts.SortByLName();
        x=false;
        break;
        case '3':
        cnts.SortByPhone();
        x=false;
        break;
        case '0':
        x=false;
        break;
        default:
        break;
    }
    }

}
void ContactCLI::SearchContacts()
{
    std::string fname;
    std::string lname;
    std::cout<<"please type the firstname you are looking for(PRESS ENTER TO LEAVE EMPTY): ";
    std::cin>>fname;
    std::cout<<"please type the lastname you are looking for(PRESS ENTER TO LEAVE EMPTY): ";
    std::cin>>lname;
    cnts.SearchContacts(fname,lname);

}
void ContactCLI::AddContact()
{
    std::string fname;
    std::string lname;
    std::string phone;
    std::cout<<"please type the firstname: ";
    std::cin>>fname;
    std::cout<<"please type the lastname: ";
    std::cin>>lname;
    std::cout<<"please type the phonenumber: ";
    std::cin>>phone;
    bool stat=cnts.AddContact(fname,lname,phone);
    if (stat==0)
    {
        std::cout<<"Already Exists!!!\n";
    }
}
