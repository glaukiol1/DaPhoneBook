#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string r1;
string r2;

void split(string toSplit, char splitter)
{
    bool lcl_done = false;
    for (char l : toSplit)
    {
        if (l != splitter)
        {
            if (lcl_done == false)
            {
                r1.push_back(l);
            }
            else
            {
                r2.push_back(l);
            }
        }
        else
        {
            lcl_done = true;
        }
    }
}

void formatContactOutput()
{
    string cnt = "|\n| Contact: ";
    string phn = "\n| Phone: ";
    string end_ = "\n|\n ------";
    cout << cnt << r1 << phn << r2 << end_ << endl;
}

int readAllContacts()
{
    string line;
    ifstream myfile("_phonebook_.txt");
    cout << "| Contacts |" << endl
         << endl;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            auto data = line.c_str();
            split(data, '=');
            formatContactOutput();
            r1 = "";
            r2 = "";
        }
        myfile.close();
    }

    else
        cout << "Unable to open file";

    return 0;
}

int addContact()
{
    ofstream myfile;
    myfile.open("_phonebook_.txt", std::ios_base::app);
    cout << "| New Contact |" << endl;
    string name;
    string phone;
    cout << "New Contact Name: (No Spaces)  ";
    cin >> name;
    cout << "New Contact Phone: (No Spaces)  ";
    cin >> phone;
    name.append("=").append(phone);
    myfile << "\n"
           << name.c_str();
    cout << "Contact " << name << " successfully added to the system." << endl;
    myfile.close();
    return 0;
}

int getContact()
{
    cout << "| Get Contact |" << endl;
    string line;
    ifstream myfile("_phonebook_.txt");
    string name;
    cout << "Contact Name: (Case Sensitive)  ";
    cin >> name;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            auto data = line.c_str();
            split(data, '=');
            if (r1 == name)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n";
                cout << "Contact Found!\n------\n";
                formatContactOutput();
                return 0;
            }
            else
            {
                r1 = "";
                r2 = "";
            }
        }
        cout << "Contact Not Found" << endl;
        myfile.close();
    }
    else
        cout << "Cant open file!";

    return 0;
};

int modifyContact()
{
    cout << "| Modify Contact |" << endl;
    string line;
    ifstream myfile("_phonebook_.txt");
    string name;
    string newname;
    string newphone;
    string fn_;
    cout << "Contact Name: (Case Sensitive)  ";
    cin >> name;
    cout << "New Contact Name: (Case Sensitive)  ";
    cin >> newname;
    cout << "New Contact Phone:  ";
    cin >> newphone;
    bool didfind = false;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (line.length() >= 3)
            {
                auto data = line.c_str();
                split(data, '=');
                if (r1 == name)
                {
                    cout << "\n\n\n\n\n\n\n\n\n\n";
                    didfind = true;
                    string rplc = newname + "=" + newphone + "\n";
                    fn_ = fn_ + rplc;
                }
                else
                {
                    fn_ = fn_ + line + "\n";
                    r1 = "";
                    r2 = "";
                }
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Cant open file!";
    };
    ofstream wmyfile("_phonebook_.txt");
    wmyfile.write(fn_.c_str(), fn_.length());
    if (!didfind)
        cout << "Could not find contact, the data file has not been modified." << endl;
    else
        cout << "Sucessfully modified the data file." << endl;
    return 0;
}

int deleteContact()
{
    cout << "| Delete Contact |" << endl;
    string line;
    ifstream myfile("_phonebook_.txt");
    string name;
    string n;
    string fn_;
    cout << "Contact Name: (Case Sensitive)  ";
    cin >> name;
    cout << "Are you sure you want to delete " << name << " from your contact book? (y/n)  ";
    cin >> n;
    if (n != "y")
    {
        cout << "Quiting...";
        return 0;
    }

    bool didfind = false;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            auto data = line.c_str();
            split(data, '=');
            if (r1 == name)
            {
                cout << "\n\n\n\n\n\n\n\n\n\n";
                didfind = true;
            }
            else
            {
                fn_ = fn_ + line + "\n";
                r1 = "";
                r2 = "";
            }
        }
        myfile.close();
    }
    else
    {
        cout << "Cant open file!";
    };
    ofstream wmyfile("_phonebook_.txt");
    wmyfile.write(fn_.c_str(), fn_.length());
    if (!didfind)
        cout << "Could not find contact, the data file has not been modified." << endl;
    else
        cout << "Sucessfully modified the data file." << endl;
    return 0;
};

int mainMenu()
{
    cout << "\t 1) Get All Contacts" << endl;
    cout << "\t 2) Get Contact By Name" << endl;
    cout << "\t 3) Create Contact" << endl;
    cout << "\t 4) Modify Contact" << endl;
    cout << "\t 5) Delete Contact" << endl;
    cout << endl
         << "\t Menu to enter: (1-5)  ";
    int type;
    cin >> type;
    if (type < 1 || type > 5)
    {
        cout << "Out of range :: 1 min - 5 max. Quiting...";
        return 1;
    }
    else
    {
        if (type == 1)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            readAllContacts();
            return 0;
        }
        else if (type == 2)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            getContact();
        }
        else if (type == 3)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            addContact();
        }
        else if (type == 4)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            modifyContact();
        }
        else if (type == 5)
        {
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            deleteContact();
        };
    };
    return 0;
};

int main()
{
    bool first_time = true;
    while (true)
    {
        if (first_time == true)
        {
            cout << "\n\n";
            mainMenu();
            first_time = false;
        }
        else
        {
            cout << "Quit DaPhoneBook? (y/n) ";
            string yn;
            cin >> yn;
            if (yn == "n")
            {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                mainMenu();
            }
            else
            {
                return 0;
            }
        }
    }
    return 0;
}
