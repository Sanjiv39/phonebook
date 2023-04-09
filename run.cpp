// #include<iostream>
#include <string.h>
#include <windows.h>
// #include<cctype>
// #include<fstream>
#include <bits/stdc++.h>
using namespace std;

// a class that will store data in its members of its object
class contact
{
public:
    int cid = 0;
    string fname;
    string lname;
    string phone;
    string place;
    contact()
    {
        fname = "";
        lname = "";
        phone = "";
        place = "";
    }
    ~contact() {}
};

// pre declare all functions
void gotoxy(int, int);
void liner(int);
void menu();
void color(string);
void menu();
void update();
void upfname();
void uplname();
void upphone();
void upplace();
void add();
void del();
void show();
void showall();

void exit()
{
    system("cls");
    color("purple");
    liner(7);
    gotoxy(20, 8);
    cout << "You have exited !!!";
    liner(9);
    Sleep(2000);
    exit(0);
}
void liner(int y)
{
    int x = 0;
    while (x != 108)
    {
        gotoxy(x, y);
        cout << "=";
        x++;
    }
}
void color(string str)
{
    if (str.compare("blue") == 0)
    {
        system("Color 37");
    }
    else if (str.compare("green") == 0)
    {
        system("Color 20");
    }
    else if (str.compare("red") == 0)
    {
        system("Color 47");
    }
    else if (str.compare("black") == 0)
    {
        system("Color 07");
    }
    else if (str.compare("white") == 0)
    {
        system("Color 70");
    }
    else if (str.compare("aqua") == 0)
    {
        system("Color 17");
    }
    else if (str.compare("purple") == 0)
    {
        system("Color 57");
    }
    else if (str.compare("yellow") == 0)
    {
        system("Color 60");
    }
}

void load()
{
    int a = 4, b = 5, c = 14, d = 7;
    int count = 0;
    int i, j;
    system("cls");
    gotoxy(a + 2, b + 1);
    cout << "LOADING";
    while (count != 3)
    {
        color("white");
        for (i = 1; i <= 3; i++)
        {
            a = a + 1;
            gotoxy(a, b);
            putchar('=');
            c = c - 1;
            gotoxy(c, d);
            putchar('=');
        }
        color("black");
        Sleep(300);
        count++;
    }
}

// goto particular coordinatw
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x; // max 111
    c.Y = y; // no limit
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// this function checks if the string has digits
int checkdigit(string arr)
{
    int flag = 0;
    for (char ch : arr)
    {
        for (int i = 0; i < arr.length(); i++)
        {
            if (isdigit(ch) == true)
            {
                flag = 1;
            }
        }
    }
    return flag;
}

// this function checks if the string has only characters
int checkstring(string arr)
{
    int flag = 0;
    int l = 1;
    for (char ch : arr)
    {
        if(l==1)
        {
            if(!isupper(ch))
            {
                flag = 1;
            }
        }
        else
        {
            for (int i = 0; i < arr.length(); i++)
            {
                if (isdigit(ch) == true)
                {
                    flag = 1;
                }
                else if (!((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122)))
                {
                    flag = 1;
                }
                else if(!islower(ch))
                {
                    flag = 1;
                }
            }
        }
        l++;
    }
    return flag;
}

// this function returns the trimmed version of the string
string trim(string arr)
{
    string repl = "";
    int j = 0;
    for (char ch : arr)
    {
        if (ch == ' ')
        {
        }
        else
        {
            repl += ch;
        }
    }
    // cout<<repl;
    return repl;
}

// this function returns latest contact id
int getid()
{
    int x = 0;
    char read[100], skip[100];
    fstream rfile("main.txt", ios::in);
    while (!rfile.eof())
    {
        for (int i = 1; i <= 5; i++)
        {
            if (i == 1)
            {
                rfile >> read;
                // cout<<read;
            }
            else
            {
                rfile >> skip;
            }
        }
        // cout<<endl;
    }
    rfile.close();
    x = stoi(read);
    // cout<<x;
    return x + 1;
}

// this function will check if already a number is existing
int checknumber(string arr)
{
    int flag = 0;
    char read[100], skip[100];
    fstream rfile("main.txt", ios::in);
    while (!rfile.eof())
    {
        for (int i = 1; i <= 5; i++)
            if (i == 4)
            { // cout << "In file loop";
                rfile >> read;
                // cout << read;
                if (arr.compare(read) == 0)
                {
                    flag = 1;
                }
            }
            else
            {
                rfile >> skip;
            }
    }
    rfile.close();
    return flag;
}

// this function will get the cid where the phone no is
int checkforid(string str)
{
    int x = 0;
    char read[100], skip[100], store[100] = "";
    fstream rfile("main.txt", ios::in);
    while (!rfile.eof())
    {
        for (int i = 1; i <= 5; i++)
        {
            if (i == 1)
            {
                rfile >> read;
                // cout<<read;
            }
            else
            {
                rfile >> skip;
                if (str.compare(skip) == 0)
                {
                    strcpy(store, read);
                }
            }
        }
    }
    rfile.close();
    x = stoi(store);
    // cout << x;
    return x;
}

// this will read lines in the file
int getlines(string str)
{
    int x = 0;
    char read[100], skip[100];
    fstream rfile(str, ios::in);
    while (!rfile.eof())
    {
        for (int i = 1; i <= 5; i++)
        {
            if (i == 1)
            {
                rfile >> read;
                // cout<<read;
            }
            else
            {
                rfile >> skip;
            }
        }
        // cout<<endl;
    }
    rfile.close();
    x = stoi(read);
    // cout<<x;
    return x + 1;
}

// this will copy from main to temp
void createtemp(int id, int col, string str)
{
    fstream rfile("main.txt", ios::in);
    fstream wtemp("temp.txt", ios::out);
    char read[100], skip[100];
    int i = 1;
    while (!rfile.eof())
    {
        if (i < getlines("main.txt"))
        {
            if (i == id)
            {
                for (int j = 1; j <= 5; j++)
                {
                    rfile >> read;
                    if (j == col)
                    {
                        wtemp << str << " ";
                    }
                    else
                    {
                        wtemp << read << " ";
                    }
                }
            }
            else
            {
                for (int j = 1; j <= 5; j++)
                {
                    rfile >> read;
                    wtemp << read << " ";
                }
            }
            wtemp << endl;
        }
        else
        {
            rfile >> skip;
        }
        i++; // line
    }
    rfile.close();
    wtemp.close();
}

// this will skip a contact
void skip(int id)
{
    fstream rfile("main.txt", ios::in);
    fstream wtemp("temp.txt", ios::out);
    char read[100], skip[100];
    int i = 1;
    while (!rfile.eof())
    {
        if (i < getlines("main.txt"))
        {
            if (i == id)
            {
                for (int j = 1; j <= 5; j++)
                {
                    rfile >> skip;
                }
            }
            else if (i == id + 1)
            {
                for (int j = 1; j <= 5; j++)
                {
                    if (j == 1)
                    {
                        rfile >> skip;
                        wtemp << i - 1 << " ";
                    }
                    else
                    {
                        rfile >> read;
                        wtemp << read << " ";
                    }
                }
                wtemp << endl;
            }
            else if (i > id)
            {
                for (int j = 1; j <= 5; j++)
                {
                    if (j == 1)
                    {
                        rfile >> skip;
                        wtemp << i - 1 << " ";
                    }
                    else
                    {
                        rfile >> read;
                        wtemp << read << " ";
                    }
                }
                wtemp << endl;
            }
            else
            {
                for (int j = 1; j <= 5; j++)
                {
                    rfile >> read;
                    wtemp << read << " ";
                }
                wtemp << endl;
            }
        }
        else
        {
            rfile >> skip;
        }
        i++; // line
    }
    wtemp << endl;
    rfile.close();
    wtemp.close();
}

// this will copy from temp to main
void storefile()
{
    fstream wfile("main.txt", ios::out);
    fstream rtemp("temp.txt", ios::in);
    char read[100], skip[100];
    int i = 1;
    while (!rtemp.eof())
    {
        if (i < getlines("temp.txt"))
        {

            for (int j = 1; j <= 5; j++)
            {
                rtemp >> read;
                wfile << read << " ";
            }
            wfile << endl;
        }
        else
        {
            rtemp >> skip;
        }
        i++; // line
    }
    // cout<<"Out";
    rtemp.close();
    wfile.close();
}

// this functions decides at the last
void back(function<void()> func)
{
    color("aqua");
    string c;
    cout << "\n\n\t\tWant to repeat?";
    cout << "\n\n\t\tEnter y or Y for yes || any other for back to main menu......also hit ENTER <---: ";
    getline(cin, c, '\n');
    Sleep(1000);
    if (c == "y" || c == "Y")
    {
        func();
    }
    else
    {
        menu();
    }
}

// ADD A NEW CONTACT ---------------------------------------------------------------------------------
void add()
{
    load();
    contact o;
    system("cls");
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "Add details for new contact......";
    liner(8);
    gotoxy(15, 10);
    cout << "Contact id : " << getid();
    // Now enter first name
    gotoxy(15, 12);
    cout << "Enter first name : ";
    // fflush(stdin);

    if (o.fname.length() > 0)
    {
        cout << o.fname;
    }
    else
    {
        color("green");
        getline(cin, o.fname, '\n');
        // while ((getchar()) != '\n');
        // cout << o.fname;
        // cout << o.fname;
        if (checkstring(o.fname) == 1)
        {
            color("red");
            gotoxy(10, 22);
            cout << "No digits/symbols/spaces allowed & first letter should be in capital";
            o.fname = "";
            o.~contact();
            Sleep(3000);
            add();
        }
        else
        {
            o.fname = trim(o.fname);
            // while ((getchar()) != '\n');
            // Now enter last name
            gotoxy(15, 14);
            cout << "Enter last name : ";
            // fflush(stdin);
            if (o.lname.length() > 0)
            {
                cout << o.lname;
            }
            else
            {
                fflush(stdin);
                color("green");
                getline(cin, o.lname, '\n');
                fflush(stdin);
                // while ((getchar()) !='\n');
                if (checkstring(o.lname) == 1)
                {
                    color("red");
                    gotoxy(10, 22);
                    cout << "No digits/symbols/spaces allowed & first letter should be in capital";
                    o.lname = "";
                    o.~contact();
                    Sleep(3000);
                    add();
                }
                else
                {
                    o.lname = trim(o.lname);
                    // Now enter phone no
                    gotoxy(15, 16);
                    cout << "Enter your phone number : ";
                    // fflush(stdin);

                    if (o.phone.length() == 10)
                    {
                        cout << o.phone;
                    }
                    else
                    {
                        fflush(stdin);
                        color("green");
                        getline(cin, o.phone, '\n');
                        fflush(stdin);

                        // while ((getchar()) != '\n')

                        if (checkdigit(o.phone) == 0)
                        {
                            color("red");
                            gotoxy(10, 22);
                            cout << "Enter only digits";
                            o.phone = "";
                            o.~contact();
                            Sleep(3000);
                            add();
                        }
                        else if (o.phone.length() != 10)
                        {
                            color("red");
                            gotoxy(10, 22);
                            cout << "Enter 10 digits only";
                            o.phone = "";
                            o.~contact();
                            Sleep(3000);
                            add();
                        }
                        else if (checknumber(o.phone) == 1)
                        {
                            color("red");
                            gotoxy(10, 22);
                            cout << "Number already exists";
                            o.phone = "";
                            o.~contact();
                            Sleep(3000);
                            add();
                        }
                        else
                        {
                            o.phone = trim(o.phone);
                            // Now enter place
                            gotoxy(15, 18);
                            cout << "Enter place : ";
                            // fflush(stdin);
                            if (o.place.length() > 0)
                            {
                                cout << o.place;
                                // while ((getchar()) != '\n')
                            }
                            else
                            {
                                fflush(stdin);
                                color("green");
                                getline(cin, o.place, '\n');
                                fflush(stdin);
                                // while ((getchar()) != '\n');
                                if (checkstring(o.place) == 1)
                                {
                                    color("red");
                                    gotoxy(10, 22);
                                    cout << "No digits/symbols/spaces allowed & first letter should be in capital";
                                    o.place = "";
                                    o.~contact();
                                    Sleep(3000);
                                    add();
                                }
                                else
                                {
                                    o.place = trim(o.place);
                                    fflush(stdin);
                                    fstream wfile("main.txt", ios::app);
                                    wfile << getid() << " " << o.fname << " " << o.lname << " " << o.phone << " " << o.place << endl;
                                    wfile.close();
                                    o.~contact();
                                    fflush(stdin);
                                    Sleep(3000);
                                    // option
                                    back(&add);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

// UPDATE SECTION----------------------------------------------------------------------------------
void update();

// update first name
void upfname()
{
    load();
    system("cls");
    string name = "";
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are updating first name......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        upfname();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        upfname();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        upfname();
    }
    else
    {
        // Now enter new name
        gotoxy(15, 12);
        cout << "Enter new first name : ";
        // fflush(stdin);

        if (name.length() > 0)
        {
            cout << name;
        }
        else
        {
            color("green");
            getline(cin, name, '\n');
            fflush(stdin);
            // while ((getchar()) != '\n');
            // cout << o.fname;
            // cout << o.fname;
            if (checkstring(name) == 1)
            {
                color("red");
                gotoxy(10, 22);
                cout << "No digits/symbols/spaces allowed & first letter should be in capital";
                name = "";
                Sleep(3000);
                upfname();
            }
            else
            {
                name = trim(name);
                // while ((getchar()) != '\n');
                // Now enter new last name
                // while ((getchar()) !='\n');
                phone = trim(phone);
                int id = checkforid(phone);
                // Now open main as read and temp as write mode
                createtemp(id, 2, name);
                storefile();
                // cout<<"Out";
                // fflush(stdin);
                // fflush(stdout);
                // Sleep(500);
                // contact o;
                // system("pause");
                // createtemp(id, 3, name2);
                // storefile();
                // fflush(stdin);
                Sleep(1000);
                // option
                back(&upfname);
            }
        }
    }
}

// update last name
void uplname()
{
    load();
    system("cls");
    string name = "";
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are updating last name......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        uplname();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        uplname();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        uplname();
    }
    else
    {
        // Now enter new name
        gotoxy(15, 12);
        cout << "Enter new last name : ";
        // fflush(stdin);
        if (name.length() > 0)
        {
            cout << name;
        }
        else
        {
            color("green");
            getline(cin, name, '\n');
            fflush(stdin);
            // while ((getchar()) != '\n');
            // cout << o.fname;
            // cout << o.fname;
            if (checkstring(name) == 1)
            {
                color("red");
                gotoxy(10, 22);
                cout << "No digits/symbols/spaces allowed & first letter should be in capital";
                name = "";
                Sleep(3000);
                uplname();
            }
            else
            {
                name = trim(name);
                // while ((getchar()) != '\n');
                // Now enter new last name
                // while ((getchar()) !='\n');
                phone = trim(phone);
                int id = checkforid(phone);
                // Now open main as read and temp as write mode
                createtemp(id, 3, name);
                storefile();
                // cout<<"Out";
                // fflush(stdin);
                // fflush(stdout);
                // Sleep(500);
                // contact o;
                // system("pause");
                // createtemp(id, 3, name2);
                // storefile();
                // fflush(stdin);
                Sleep(1000);
                // option
                back(&uplname);
            }
        }
    }
}

// update phone no
void upphone()
{
    load();
    system("cls");
    string name = "";
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are updating phone number......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        upphone();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        upphone();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        upphone();
    }
    else
    {
        // Now enter new name
        gotoxy(15, 12);
        cout << "Enter new phone number : ";
        // fflush(stdin);
        if (name.length() > 0)
        {
            cout << name;
        }
        else
        {
            color("green");
            getline(cin, name, '\n');
            fflush(stdin);
            // while ((getchar()) != '\n');
            // cout << o.fname;
            // cout << o.fname;
            if (checkdigit(name) == 0)
            {
                color("red");
                gotoxy(10, 22);
                cout << "Enter only digits";
                name = "";
                Sleep(3000);
                upphone();
            }
            else if (name.length() != 10)
            {
                color("red");
                gotoxy(10, 22);
                cout << "Enter 10 digits only";
                name = "";
                Sleep(3000);
                upphone();
            }
            else if (checknumber(name) == 1)
            {
                color("red");
                gotoxy(10, 22);
                cout << "Number already exists";
                phone = "";
                Sleep(3000);
                upfname();
            }
            else
            {

                name = trim(name);
                // while ((getchar()) != '\n');
                // Now enter new last name
                // while ((getchar()) !='\n');
                phone = trim(phone);
                int id = checkforid(phone);
                // Now open main as read and temp as write mode
                createtemp(id, 4, name);
                storefile();
                // cout<<"Out";
                // fflush(stdin);
                // fflush(stdout);
                // Sleep(500);
                // contact o;
                // system("pause");
                // createtemp(id, 3, name2);
                // storefile();
                // fflush(stdin);
                Sleep(1000);
                // option
                back(&upphone);
            }
        }
    }
}

// update place
void upplace()
{
    load();
    system("cls");
    string name = "";
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are updating place......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        upplace();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        upplace();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        upplace();
    }
    else
    {
        // Now enter new name
        gotoxy(15, 12);
        cout << "Enter new place : ";
        // fflush(stdin);
        if (name.length() > 0)
        {
            cout << name;
        }
        else
        {
            color("green");
            getline(cin, name, '\n');
            fflush(stdin);
            // while ((getchar()) != '\n');
            // cout << o.fname;
            // cout << o.fname;
            if (checkstring(name) == 1)
            {
                color("red");
                gotoxy(10, 22);
                cout << "No digits/symbols/spaces allowed & first letter should be in capital";
                name = "";
                Sleep(3000);
                upplace();
            }
            else
            {
                name = trim(name);
                // while ((getchar()) != '\n');
                // Now enter new last name
                // while ((getchar()) !='\n');
                phone = trim(phone);
                int id = checkforid(phone);
                // Now open main as read and temp as write mode
                createtemp(id, 3, name);
                storefile();
                // cout<<"Out";
                // fflush(stdin);
                // fflush(stdout);
                // Sleep(500);
                // contact o;
                // system("pause");
                // createtemp(id, 3, name2);
                // storefile();
                // fflush(stdin);
                Sleep(1000);
                // option
                back(&upplace);
            }
        }
    }
}

// delete a contact
void del()
{
    load();
    system("cls");
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are deleting a contact......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        del();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        del();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        del();
    }
    else
    {
        // while ((getchar()) != '\n');
        // Now enter new last name
        // while ((getchar()) !='\n');
        phone = trim(phone);
        int id = checkforid(phone);
        // Now open main as read and temp as write mode
        skip(id);
        storefile();
        // cout<<"Out";
        // fflush(stdin);
        // fflush(stdout);
        // Sleep(500);
        // contact o;
        // system("pause");
        // createtemp(id, 3, name2);
        // storefile();
        // fflush(stdin);
        Sleep(3000);
        // option
        back(&del);
    }
}

// shows a record
void show()
{
    load();
    system("cls");
    string phone = "";
    color("blue");
    liner(6);
    gotoxy(10, 7);
    cout << "You are searching a contact......";
    liner(8);
    gotoxy(15, 10);
    // Enter the phone number
    cout << "Enter phone number : ";
    getline(cin, phone, '\n');
    fflush(stdin);
    if (checkdigit(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter only digits";
        phone = "";
        Sleep(3000);
        del();
    }
    else if (phone.length() != 10)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Enter 10 digits only";
        phone = "";
        Sleep(3000);
        del();
    }
    else if (checknumber(phone) == 0)
    {
        color("red");
        gotoxy(10, 22);
        cout << "Number does not exists";
        phone = "";
        Sleep(3000);
        del();
    }
    else
    {
        // while ((getchar()) != '\n');
        // Now enter new last name
        // while ((getchar()) !='\n');
        phone = trim(phone);
        int id = checkforid(phone);
        fstream rfile("main.txt", ios::in);
        char read[100], skip[100];
        int i = 1;
        system("cls");
        color("yellow");
        liner(8);
        gotoxy(20, 10);
        cout << "Contact Details";
        liner(12);
        while (!rfile.eof())
        {
            if (i < getlines("main.txt"))
            {
                if (i == id)
                {
                    rfile >> read;
                    gotoxy(10, 15);
                    cout << "Contact id";
                    gotoxy(30, 15);
                    cout << ":";
                    gotoxy(35, 15);
                    cout << read;
                    rfile >> read;
                    gotoxy(10, 17);
                    cout << "First name";
                    gotoxy(30, 17);
                    cout << ":";
                    gotoxy(35, 17);
                    cout << read;
                    rfile >> read;
                    gotoxy(10, 19);
                    cout << "Last name";
                    gotoxy(30, 19);
                    cout << ":";
                    gotoxy(35, 19);
                    cout << read;
                    rfile >> read;
                    gotoxy(10, 21);
                    cout << "Phone number";
                    gotoxy(30, 21);
                    cout << ":";
                    gotoxy(35, 21);
                    cout << read;
                    rfile >> read;
                    gotoxy(10, 23);
                    cout << "Place";
                    gotoxy(30, 23);
                    cout << ":";
                    gotoxy(35, 23);
                    cout << read;
                }
                else
                {
                    for (int j = 1; j <= 5; j++)
                    {
                        rfile >> skip;
                    }
                }
            }
            else
            {
                rfile >> skip;
            }
            i++; // line
        }
        rfile.close();
        // option
        back(&show);
    }
}

// shows all records
void showall()
{
    load();
    fflush(stdin);
    fflush(stdout);
    system("cls");
    color("yellow");
    int id;
    liner(4);
    gotoxy(5, 5);
    cout << "ID";
    gotoxy(15, 5);
    cout << "First name";
    gotoxy(35, 5);
    cout << "Last name";
    gotoxy(55, 5);
    cout << "Phone number";
    gotoxy(75, 5);
    cout << "Place";
    liner(6);
    int y = 7;
    fstream rfile("main.txt", ios::in);
    char read[100], skip[100];
    int i = 1;
    while (!rfile.eof())
    {

        if (i < getlines("main.txt"))
        {
            y = y + 2;
            rfile >> read;
            gotoxy(5, y);
            cout << read;
            rfile >> read;
            gotoxy(16, y);
            cout << read;
            rfile >> read;
            gotoxy(36, y);
            cout << read;
            rfile >> read;
            gotoxy(56, y);
            cout << read;
            rfile >> read;
            gotoxy(76, y);
            cout << read;
            y = y + 2;
            liner(y);
        }
        else
        {
            rfile >> skip;
        }
        i++; // line
    }
    // cout<<"Out";
    rfile.close();
    // option
    back(&showall);
}

// THE UPDATE MENU
void update()
{
    load();
    system("cls");
    color("blue");
    liner(4);
    gotoxy(10, 5);
    cout << "You are in the update menu:";
    liner(6);
    gotoxy(15, 9);
    cout << "1. Update first name ";
    gotoxy(15, 11);
    cout << "2. Update last name ";
    gotoxy(15, 13);
    cout << "3. Update number ";
    gotoxy(15, 15);
    cout << "4. Update place ";
    gotoxy(15, 17);
    cout << "5. Delete contact";
    gotoxy(15, 19);
    cout << "6. Show all contacts before updating";
    gotoxy(15, 21);
    cout << "7. Go to main menu";
    gotoxy(15, 23);
    cout << "8. EXIT ";
    string x;
    gotoxy(10, 25);
    cout << "Enter your choice - ";
    color("green");
    getline(cin, x, '\n');
    if (checkdigit(x) == 0)
    {
        color("red");
        gotoxy(15, 29);
        cout << "Only one digit number is allowed";
        Sleep(3000);
        menu();
    }
    else
    {

        if (x.length() == 1)
        {
            for (char ch : x)
            {
                switch (ch)
                {
                case '1':
                    upfname();
                    break;
                case '2':
                    uplname();
                    break;
                case '3':
                    upphone();
                    break;
                case '4':
                    upplace();
                    break;
                case '5':
                    del();
                    break;
                case '6':
                    showall();
                    break;
                case '7':
                    menu();
                    break;
                case '8':
                    exit();
                    break;
                default:
                    color("red");
                    gotoxy(15, 29);
                    cout << "No such input try again......";
                    Sleep(3000);
                    menu();
                    break;
                }
            }
        }
        else
        {
            color("red");
            gotoxy(15, 29);
            cout << "Only one digit number is allowed";
            Sleep(3000);
            menu();
        }
    }
}

// THE MAIN MENU
void menu()
{
    load();
    system("cls");
    color("blue");
    liner(4);
    gotoxy(10, 5);
    cout << "PHONE BOOK:";
    liner(6);
    gotoxy(15, 9);
    cout << "1. Add a contact ";
    gotoxy(15, 11);
    cout << "2. Update a contact ";
    gotoxy(15, 13);
    cout << "3. Delete a contact ";
    gotoxy(15, 15);
    cout << "4. Show a contact ";
    gotoxy(15, 17);
    cout << "5. Show all contacts ";
    gotoxy(15, 19);
    cout << "6. EXIT ";
    gotoxy(15, 21);
    string x;
    gotoxy(10, 25);
    cout << "Enter your choice - ";
    color("green");
    getline(cin, x, '\n');
    if (checkdigit(x) == 0)
    {
        color("red");
        gotoxy(15, 29);
        cout << "Only one digit number is allowed";
        Sleep(3000);
        menu();
    }
    else
    {

        if (x.length() == 1)
        {
            for (char ch : x)
            {
                switch (ch)
                {
                case '1':
                    add();
                    break;
                case '2':
                    update();
                    break;
                case '3':
                    del();
                    break;
                case '4':
                    show();
                    break;
                case '5':
                    showall();
                    break;
                case '6':
                    exit();
                    break;
                default:
                    color("red");
                    gotoxy(15, 29);
                    cout << "No such input try again......";
                    Sleep(3000);
                    menu();
                    break;
                }
            }
        }
        else
        {
            color("red");
            gotoxy(15, 29);
            cout << "Only one digit number is allowed";
            Sleep(3000);
            menu();
        }
    }
}

int main()
{
    // string str = "Hi";
    // system("cls");
    // system("Color 75");
    // cout<<str;
    // load();
    menu();
    // back(&update);
    // checkforid("55");
    // getid();
    // char c[100] = "Th";
    // strcpy(c, trim("Hi there").c_str());
    // cout<<c;
    // storefile();
    // cout<<getlines("temp.txt");
    return 0;
}
