#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define MAX 10
#define p_Length 6

using namespace std;

typedef struct information
{
    string fullname, lName, fName, age, address, pin, acc_no;
    string decrypt_pin;
    int balance;
}INFO;

typedef struct list
{
    INFO info[MAX];
    int last;
    fstream data;

}LIST;

LIST list;

void makeNull();
void insert(INFO* x);
void display();
string makePin();
string gen_accNo();
string findDriver();
void menu();
void decrypt();
void save();
void retrieve();
void ex();
bool card();
int checkATM();

int main(void){
    makeNull();
    checkATM();
    retrieve();

}

void makeNull(){
    list.last = -1;
}

void insert(INFO* x){

    list.last++;
    cout << "First Name: ";
    getline(cin, x[list.last].fName);
    cout << "Last Name: ";
    getline(cin, x[list.last].lName);
    x[list.last].fullname = x[list.last].fName + " " + x[list.last].lName;
    cout << "Age: ";
    getline(cin, x[list.last].age);
    cout << "Address: ";
    getline(cin, x[list.last].address);
    cout << "Balance: ";
    cin >> x[list.last].balance;
    x[list.last].pin = makePin();
    x[list.last].acc_no = gen_accNo();
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

string gen_accNo(){

   string account_No;

    if(list.last < 10){

        account_No = "TUPATM-010" + to_string(list.last + 1);
    }else{
        account_No = "TUPATM-01" + to_string(list.last + 1);
    }

    return account_No;
}

void display(){

    system("cls");
    cout << "\t No. \t\t\t Full Name: \t\t\t\t Acc.No \t\t\t Balance: \n" << endl;
    for (int i = 0; i < list.last + 1; i++){
        cout << "\t [" << i + 1 << "]\t\t\t" << list.info[i].fullname << "\t\t\t\t" << list.info[i].acc_no << "\t\t\t" << list.info[i].balance << endl;
    }
    system("pause");
    menu();

}

void menu(){

    system("cls");

    cout << "'\t\t\tTECHNOlOGICAL UNIVERSITY BANK" << endl;
    cout << "\n\t\t[1] Register" << endl;
    cout << "\n\t\t[2] Display Accounts" << endl;
    cout << "\n\t\t[3] Exit" << endl;

    int choice;
    cout << "\n\t\tEnter choice: ";
    choice = getch();
    if(isdigit(choice)){
        choice -= '0';
    }else{
        menu();
    }
    switch(choice){
        case 1:system("cls");insert(list.info);break;
        case 2:display();break;
        case 3:ex();break;
        default:menu();break;
    }
}

void save(){

    ofstream database("database.txt", ios::app);
    remove("database.txt");
    if(card() != true) {

    }
    else {
        for (int i = 0; i < list.last + 1; i++){
            database << list.info[i].fName << "-" << list.info[i].lName << "-" << list.info[i].address << "-" << list.info[i].age << "-" << list.info[i].pin << "|" << list.info[i].acc_no << "|" << list.info[i].balance << endl;

            list.data << list.info[list.last].acc_no << "|" << list.info[list.last].pin << "|" << list.info[list.last].balance << endl;
        }
    }

}

void retrieve(){

    ifstream database("database.txt");
    string holder, balance;
    int i = 0;

    while(getline(database, holder)){

        stringstream datastream(holder);

        getline(datastream, list.info[i].fName, '-');
        getline(datastream, list.info[i].lName, '-');
        list.info[i].fullname = list.info[i].fName + " " + list.info[i].lName;
        getline(datastream, list.info[i].address, '-');
        getline(datastream, list.info[i].age, '-');
        getline(datastream, list.info[i].pin, '|');
        getline(datastream, list.info[i].acc_no, '|');
        getline(datastream, balance);
        list.info[i].balance = stoi(balance);
        list.last++;
        i++;
    }
    menu();
}

void ex(){
    save();
    system("cls");
    system("pause");
    system("Module2_Transactions.exe");
}

int checkATM(){

    fstream check;

    do{

        check.open(findDriver(), fstream::in | fstream::out | fstream::app);

    }while(check.fail());

    system("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t\t      ATM Card Inserted! \n" << endl;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    Sleep(600);

    string atm_card;
    int count = 0;

    while(getline(check,atm_card)){
        count++;
    }

    if(count == 1){
        system("cls");
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\n\n\t\t\t\t      Processing ATM Card .. Please wait ... " << endl;
        Sleep(3000);
        cout << "\n\n\t\t\t\t      Done processing ATM Card ....      " << endl;
        Sleep(1500);
        cout << "\n\n\t\t\t\t      ATM Card has an account already! \n" << endl;
        Sleep(1500);
        cout << "\n\t\t\t\t      Proceeding to Transaction ...... \n" << endl;
        Sleep(1500);
        cout << "\n\n\t\t\t\t      Press any key to continue ...... \n" << endl;
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        getch();
        system("cls");
        system("Module2_Transactions.exe");
}
}

bool card(){

    char drive = 'D';
    string path = ":\\data.txt";

    do{
        drive++;
        list.data.open(drive + path, fstream::in | fstream::out | fstream::app);
        if(drive == 'H'){
            drive = 'D';
        }
        system("cls");
        cout << "Please Insert Card";
    }while(list.data.fail());

    return true;
}

string findDriver(){

    char drive = 'D';
    string path = ":\\data.txt";
    ifstream driver;

    do{
        drive++;
        driver.open(drive + path, fstream::in | fstream::out | fstream::app);
        if(drive == 'H'){
            drive = 'D';
        system("cls");
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\n\n\t\t\t\t\t     Please Insert Card \n" << endl;
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;

        }

    }while(driver.fail());

    string file_path = drive + path;
    return file_path;
}
