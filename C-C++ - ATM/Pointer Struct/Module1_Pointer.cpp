#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX 10

using namespace std;

typedef struct List{
    string fullname, lName, fName, age, address, pin, acc_no;
    int balance;
    List* next;
}List;

typedef struct User{
    string pin, acc_no;
    int balance;
}User;

int last = -1;
List* list;
List* user;
fstream data;

void makeNull();
void insert(string lName, string fName, string age, string address, string acc_no, string pin, int balance);
void display();
string makePin();
string gen_number();
void menu();
void save();
void retrieve();
bool card();

int main(){
    makeNull();
    retrieve();
}

void makeNull(){list = NULL;}

void display(){
    system("cls");
    int i = 1;
    List *p = list;
    cout << "\t No. \t\t\t Full Name: \t\t\t\t Acc.No \t\t\t Balance: \n" << endl;
    while(p != NULL){
        cout << "\t[" << i++ << "]" << " \t\t\t" << p->fullname << " \t\t\t\t " << p->acc_no << " \t\t\t " << p->balance << endl;
        p = p->next;
    }
    system("pause");
    menu();
}

string makePin(){

    srand(time(NULL));
    string pin;

    for (int i = 0; i < 6; ++i)
    {
        int randNumber = rand() % 9 + 1;
        pin.push_back(randNumber + '0');
    }

    return pin;
}

string gen_number(){

    string account_No;

    if( last < 10){

        account_No = "TUPATM-010" + to_string(last + 1);
    }else{
        account_No = "TUPATM-01" + to_string(last + 1);
    }

    return account_No;

}

void insert(string lName, string fName, string age, string address, string acc_no, string pin, int balance){

    List *tail = new List();
    List *body = list;

    tail->lName = lName;
    tail->fName = fName;
    tail->fullname = fName + " " + lName;
    tail->age = age;
    tail->address = address;
    tail->balance = balance;
    tail->acc_no = acc_no;
    tail->pin = pin;

    tail->next = NULL;

    if(list == NULL){
        list = tail;
        return;
    }

    while(body->next != NULL){
        body = body->next;
    }

    body->next = tail;

    return;
}

bool card(){

    char drive = 'D';
    string path = ":\\data.txt";

    do{
        drive++;
        data.open(drive + path, fstream::in | fstream::out | fstream::app);
        if(drive == 'H'){
            drive = 'D';
        }
        system("cls");
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\n\n\t\t\t\t\t     Please Insert Card \n" << endl;
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;

    }while(data.fail());

    system("cls");
    return true;
}

void save(){

    ofstream database("database.txt", ios::app);
    List* p = list;
    List* q = list;
    card();

    while(q != NULL){
        database << q->fName << "-" << q->lName << "-" << q->address << "-" << q->age << "-" << q->pin << "|" << q->acc_no << "|" << q->balance << endl;
        q = q->next;
    }

    for(int x = 0; x < 6; x++){
        p->pin[x] += 30;
    }

    data << p->acc_no << " " << p->pin << " " << p->balance << endl;

    database.close();
    data.close();
}

void menu(){
    system("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t\t   TECHNOLOGICAL UNIVERSITY BANK " << endl;
    cout << "\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t\t  [1] Register" << endl;
    cout << "\n\n\t\t\t\t\t  [2] Display Accounts" << endl;
    cout << "\n\n\t\t\t\t\t  [3] Exit" << endl;
    cout << "\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;


    int choice, balance = 0;
    string lName, fName, age, address, xpin, xacc_no;
    cout << "\n\t\t\t\t\t  Enter choice: ";
    choice = getch();
    if(isdigit(choice)){
        choice -= '0';
    }else{
        menu();
    }

    switch(choice){
        case 1:
            system("cls");
            cout << "\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            last++;
            cout << "\n\n\t\t\t\t\t       REGISTRATION: " << endl;
            cout << "\n\n\t\t\t\t  Enter first name: ";getline(cin, fName);
            cout << "\n\n\t\t\t\t  Enter last name: ";getline(cin, lName);
            cout << "\n\n\t\t\t\t  Enter age: ";getline(cin, age);
            cout << "\n\n\t\t\t\t  Enter address: ";getline(cin, address);
            while(balance < 100){
            cout << "\n\n\t\t\t\t  Enter balance(Minimum 100): ";cin >> balance;
            }
            xacc_no = gen_number();
            xpin = makePin();
            cin.ignore(100, '\n');
            cout << "\n\n\t\t\t\t  Your Generated PIN is: " << xpin << endl;
            cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            cout << "\n\n\t\t\t\t           PRESS [ENTER] to return " << endl;getch();
            insert(lName, fName, age, address, xacc_no, xpin, balance);
            menu();
            break;
        case 2:display();break;
        case 3:save();system("cls");system("Module2_Pointer.exe");exit(0);
        default:menu();break;
    }
}

void retrieve(){
    ifstream database("database.txt");
    string dummy, balance, f, l, age, add, pin, acc;
    int i = 0;
    while(getline(database, dummy)){
        stringstream datastream(dummy);

        getline(datastream, f, ' ');
        getline(datastream, l, ' ');
        getline(datastream, add, ' ');
        getline(datastream, age, ' ');
        getline(datastream, pin, ' ');
        getline(datastream, acc, ' ');
        getline(datastream, balance);
        i = atoi(balance.c_str());
        last++;
        insert(l, f, age, add, acc, pin, i);
    }
    database.close();
    string x = "database.txt";
    remove(x.c_str());
    menu();
}
