#include <iostream>
#include<fstream>

using namespace std;


// Class Description of books

class books
{
    int book_no;
    string book_name;
    string author_name;
    string genre;
    int copies;
    char book_status;

public:

    void book_getdata(books i[]);
    void book_display(void);
    void book_display(int a);
    friend class user;
    friend class management;
}b[10];


class user
{
    int user_no;
    string user_name;
    string user_password;
    int fine;
    int book_taken[3];
    int day1[3], day2[3], month1[3], month2[3], year1[3], year2[3];

public:

    void user_getdata(user i[]);
    void user_display(void);
    int search_user(string a, string b);
    friend class management;


}u[4];

class admin
{
    string admin_username;
    string admin_password;
public:
    void admin_getdata(admin i[]);
    void search_admin(string a, string b, admin v[]);
}a[2];

// class Definition for admin get data

void admin :: admin_getdata(admin i[])
{
     fstream f;

    f.open("Admin.txt", ios :: in);

    if(!f)
    {
        cout << "No such file" << endl;
    }
    int j;

    for(j=0; j<2 ; j++)
    {

        f >> i[j].admin_username;
        f >> i[j].admin_password;
    }
}

//Class definition Search Admin

void admin :: search_admin(string a, string b, admin v[])
{
    {
    int j=0, cnt=0;

    for(j=0; j<2; j++)
    {
        if (v[j].admin_username == a)
        {
            if(v[j].admin_password == b)
            {
                cout << "Login Successful" << endl;
            }
            else
            {
                cnt ++;
                if(cnt == 5)
                {
                    cout << "Too many wrong attempt" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Wrong password!!!" << endl;
                    cout << "Please try Again" << endl;
                    cout << endl;
                    cout << "State your name: " << endl;
                    cin >> a;
                    cout << "State your password: " << endl;
                    cin >> b;
                    j=0;
                    continue;
                }
            }
        }

        else if(j == 2)
        {
            cnt ++;
            if(cnt == 5)
            {
                cout << "Too many wrong attempt" << endl;
            }
            else
            {
                cout << endl;
                cout << "Wrong Name!!!" << endl;
                cout << "Please try Again" << endl;
                cout << endl;
                cout << "State your name: " << endl;
                cin >> a;
                cout << "State your password: " << endl;
                cin >> b;
                j=0;
                continue;
            }
        }
    }
}
}
//class declaration  of management

class management
{
public:

    void search_book(string b);
    void borrow_book(string b, user &i);
    void return_book(user &i);
    void renew_book(user &i);
}m;

//Function definition for book renew

void management :: renew_book(user &i)
{
    cout << "The name of the book to be renew" << endl;
    cout << "1. Book 1" << endl;
    cout << "2. Book 2" << endl;
    cout << "3. Book 3" << endl;
    int x;
    cin >> x;
    i.day2[x-1] = i.day2[x-1] +7;
}

//Function Definition for return book

void management :: return_book(user &i)
{
    cout << "The name of the book to be returned" << endl;
    cout << "1. Book 1" << endl;
    cout << "2. Book 2" << endl;
    cout << "3. Book 3" << endl;
    int x;
    cin >> x;
    i.book_taken[x-1] = 0;
}

//Function Definition for search user
int user :: search_user(string a, string b)

    {
    int j=0, cnt=0;

    for(j=0; j<10; j++)
    {
        if (u[j].user_name == a)
        {
            if(u[j].user_password == b)
            {
                u[j].user_display();
                return j;
            }
            else
            {
                cnt ++;
                if(cnt == 5)
                {
                    cout << "Too many wrong attempt" << endl;
                }
                else
                {
                    cout << endl;
                    cout << "Wrong password!!!" << endl;
                    cout << "Please try Again" << endl;
                    cout << endl;
                    cout << "State your name: " << endl;
                    cin >> a;
                    cout << "State your password: " << endl;
                    cin >> b;
                    j=0;
                    continue;
                }
            }
        }

        else if(j == 9)
        {
            cnt ++;
            if(cnt == 5)
            {
                cout << "Too many wrong attempt" << endl;
            }
            else
            {
                cout << endl;
                cout << "Wrong Name!!!" << endl;
                cout << "Please try Again" << endl;
                cout << endl;
                cout << "State your name: " << endl;
                cin >> a;
                cout << "State your password: " << endl;
                cin >> b;
                j=0;
                continue;
            }
        }
    }
}


// Function Definition for Search book

void management :: borrow_book(string c, user &i)
{
    int j,k, cnt=0;
    for(j=0; j<10; j++)
    {
        if(b[j].book_name == c)
        {
            for(k=0; k<3; k++)
            {
                if(i.book_taken[k] == 0)
                {
                    i.book_taken[k] = b[j].book_no;
                    cout << "book borrowed" << endl;
                    b[j].copies--;
                    i.day1[k] = 6;
                    i.month1[k] = 8;
                    i.year1[k] = 2023;
                    i.day2[k] = 6+7;
                    i.month2[k] = 8;
                    i.year2[k] = 2023;
                    break;
                }
                else
                {
                    cnt++;
                }
            }
        }
    }
    if(cnt == 3)
    {
        cout << "Can not borrow anymore books" << endl;
    }
}

// Function definition for search book

void management :: search_book(string c)
{
    int j=0;
    for(j=0; j < 10; j++)
    {
        if(c == b[j].book_name)
        {
            b[j].book_display();
        }
        else if(c == b[j].author_name)
        {
            b[j].book_display();
        }
        else if(c == b[j].genre)
        {
            b[j].book_display();
        }
    }
}
// user get data function declaration

void user :: user_getdata(user i[])
{
    fstream f;

    f.open("user.txt", ios :: in);

    if(!f)
    {
        cout << "No such file" << endl;
    }
    int j;

    for(j=0; j<4 ; j++)
    {

        f >> i[j].user_no;
        f >> i[j].user_name;
        f >> i[j].user_password;
        f >> i[j].fine;
        f >> i[j].book_taken[0];
        f >> i[j].book_taken[1];
        f >> i[j].book_taken[1];

    }

}

// books get data function declaration


void books :: book_getdata(books i[])
{
    fstream f;

    f.open("book.txt", ios :: in);

    if(!f)
    {
        cout << "No such file" << endl;
    }
    int j;

    for(j=0; j<10 ; j++)
    {

        f >> i[j].book_no;
        f >> i[j].book_name;
        f >> i[j].author_name;
        f >> i[j].genre;
        f >> i[j].copies;
        f >> i[j].book_status;

    }

}

//book display function declaration


void books :: book_display(void)
    {
        cout << endl;
        cout << endl;
        cout << "Book name: " << book_name << "     Author Name: " << author_name << endl;
        cout << "Copies: " << copies << "       Book Status: " << book_status << endl;
        cout << endl;
        cout << endl;
    }


void books :: book_display(int a)
{
    for(int k=0; k<10;  k++)
    {
        if(b[k].book_no ==  a)
        {
            b[k].book_display();
        }
    }
}

// user display function

void user :: user_display(void)
{

    cout << endl;
    cout << endl;
    cout << "User No: " << user_no << "     User name: " << user_name << endl;
    cout << "fine: " << fine;

    int j=0;
    int cnt = 0;
    for(j; j<3; j++)
    {
        if(book_taken[j]!=0)
        {
            b[0].book_display(book_taken[j]);
            cout << "Borrowed: " << day1[j] << "." << month1[j] << "." <<year1[j] << endl;
            cout << "Return Date: " << day2[j] << "." << month2[j] << "." <<year2[j] << endl;
        }
        else
        {
            cnt++;
        }
    }
    if(cnt == 3)
    {
        cout << endl;
        cout << endl;
        cout << "No Books have been checked out" << endl;
    }
}

// clear function declaration

void clr (void)
{
    cout << endl;
    cout << "_____________________________________________________________________________________________________________________" << endl;
    cout << endl;
}


int main()
{
    a[0].admin_getdata(a);
    b[0].book_getdata(b);
    u[0].user_getdata(u);

    char z;

    do
    {
        clr();
        cout << "_____________________________Welcome to Library System !!!_______________________________________________" << endl;
        cout << "(a) Login as a User" << endl;
        cout << "(b) Login as a Admin" << endl;
        char z1;
        cin >> z1;
        if(z1 == 'a')
        {
            do
            {
                string z2,z3;
                cout << "State your User name: " << endl;
                cin >> z2;
                cout << "State Your Password: " << endl;
                cin >> z3;
                int z4;
                do
                {
                    z4 = u[0].search_user(z2,z3);
                    cout << "What do you want to do?" << endl;
                    cout << "(a)Search Books" << endl;
                    cout << "(b)Borrow Books" << endl;
                    cout << "(c)Return Books" << endl;
                    cout << "(d)Renew Books" << endl;
                    cout << "(e)Display Profile" << endl;
                    char z5;
                    cin >> z5;
                    if(z5 == 'a')
                    {
                        cout << "Enter book name, author name or genre name" << endl;
                        string z6;
                        cin >> z6;
                        m.search_book(z6);

                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else if(z5 == 'b')
                    {
                        cout << "Enter book name" << endl;
                        string z6;
                        cin >> z6;
                        m.borrow_book(z6, u[z4]);

                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else if(z5 == 'e')
                    {
                        u[z4].user_display();

                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else if(z5 == 'c')
                    {
                        m.return_book(u[z4]);
                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else if(z5 == 'd')
                    {
                        m.renew_book(u[z4]);
                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else
                    {
                        cout << "Wrong input" << endl;
                        z = 'b';
                    }

                }
                while(z == 'b');
            }
            while(z == 'a');

        }
        else if(z1 == 'b')
        {
            do
            {
                string z2,z3;
                cout << "State your Admin name: " << endl;
                cin >> z2;
                cout << "State Your Password: " << endl;
                cin >> z3;
                int z4;

                do
                {
                    a[0].search_admin(z2, z3, a);
                    cout << "What do you want to do?" << endl;
                    cout << "(a)Display All Books" << endl;
                    cout << "(b)Display All user" << endl;

                    char z5;
                    cin >> z5;

                    if(z5 == 'b')
                    {
                        int l;

                        for(l=0; l<4; l++)
                        {
                            u[l].user_display();
                        }

                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }
                    else if(z5 == 'a')
                    {
                        int l;

                        for(l=0; l<10; l++)
                        {
                            b[l].book_display();
                        }

                        cout << "What do you want to do?" << endl;
                        cout << "(a)Login with new account"<< endl;
                        cout << "(b)Go to Options" << endl;
                        cout << "(c)Log out" << endl;
                        cin >> z;
                    }

                }
                while(z == 'b');
            }
            while(z == 'a');
        }
        else
        {
            cout << "Wrong input" << endl;
            z = 'c';
        }
    }
    while(z = 'c');
}
