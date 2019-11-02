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
ifstream rt;

typedef struct information
{
    string fullname, lName, fName, age, address, pin, acc_no;
    int balance;
}INFO;

typedef struct list
{
    INFO info[MAX];
    INFO user;
    int last;
    fstream data;
}LIST;

LIST list;

void makeNull();
void menu();
void bal_inq();
void retrieve();
void deposit();
void withdraw();
void saveinfo();
void change_pin();
string check_path();
void fund_transfer();
void check_card();
void claim_funds();
void show_menu();
string findDriver();
string input_pin();

int main(){

   check_card();
   show_menu();

}
void makeNull(){

    list.last = -1;
}

void menu()
{
    system ( "cls" );
    cout << "\n\t\t\t\t TRANSACTION: \n" << endl;
    cout << "\t [1] Deposit\t\t\t\t [2] Withdraw\n " << endl;
    cout << "\t [3] Balance Inquiry \t\t\t [4] Change PIN \n" << endl;
    cout << "\t [5] Fund Transfer \t\t\t [6]Exit" << endl;
    int choice;
    cout << "\n\t\t\t Enter choice: ";
    choice = getch();
    if(isdigit(choice)){
        choice -= '0';
    }else{
        menu();
    }

    switch(choice){
        case 1:system("cls");deposit();break;
        case 2:system("cls");withdraw();break;
        case 3:system("cls");bal_inq();break;
        case 4:system("cls");change_pin();break;
        case 5:system("cls");fund_transfer();break;
        case 6:exit(0);
        default:menu();break;
    }

}

void deposit()
{
    system("cls");
    int i,amount;
    cout << "\n\n\t\tEnter amount of money you want to deposit : ";
    cin >> amount;
    if(amount < 100)
    {
        cout << "\n\t\t Cannot deposit below 100! Please try again..." << endl;
        getch();
        deposit();
    }else{

    list.info[list.last].balance += amount;

    saveinfo();
    }
    menu();

}

void withdraw()
{
    system("cls");
    int i,amount;
    cout << "\n\n\t\tEnter amount of money you want to withdraw : ";
    cin >> amount;
    if(amount < list.info[list.last].balance)
    {
        cout << "\n\n\t\t Cannot withdraw below initial balance! Please try again ... " << endl;
        getch();
        withdraw();
    }else{

    list.info[list.last].balance -= amount;

    saveinfo();
    }
    menu();
}

void bal_inq()
{
     system("cls");
        for (int i = 0; i < list.last + 1 ; i++){
        cout << "\n\n\t\t Balance: " << list.info[i].balance << "\n" << endl;
    }
    getch();
    menu();
}

void change_pin(){

    cout << "Enter new pin:  ";
    string np = input_pin();
    cout << " \n\nRe-Enter pin:  ";
    string cnp = input_pin();

    if(np == cnp){
        cnp >> list.info[list.last].pin;
        saveinfo();
    }else{
        cout << "Pin mismatched... Please try again";
        getch();
        change_pin();
    }
        cout << "\nPin successfully changed." <<endl;
        cout << "Press enter to go back...\n";

        getch();
        system("cls");

        menu();
}

void saveinfo()
{
    ofstream save_d("E:\\data.txt");
    save_d << list.info[list.last].acc_no << " " << list.info[list.last].pin << " " << list.info[list.last].balance << endl;
}
void retrieve()
{
    ifstream database("E:\\data.txt");
    string dummy, balance;
    int i = 0;

    while(getline(database, dummy)){

        stringstream datastream(dummy);

        getline(datastream, list.info[i].acc_no, '|');
        getline(datastream, list.info[i].pin, '|');
        getline(datastream, balance);
        list.info[i].balance = stoi(balance);
        list.last++;
        i++;
    }
    menu();
}

void fund_transfer()
{
        claim_funds();
        system("cls");
        string name;
        int amount,amount2;
            cout << "\n\n\t\t\t   Enter account number:   ";
            cin >> name;
            cout << "\n\t\t\t   Enter the amount to transfer:  ";
            cin >> amount;
            cout << "\n\n\t\t\t     Press [ENTER] to proceed .. ";
            getch();

            ifstream accountFile ("D:\\Projects\\Project 1A\\Fund Transfer\\" + name + ".txt");
            if (accountFile)
            {
                accountFile >> amount2;
                amount += amount2;
            }

            ofstream accountsave ("D:\\Projects\\Project 1A\\Fund Transfer\\" + name + ".txt");
            accountsave << amount << endl;

            getch();
            accountFile.close();
            menu();

}

void claim_funds(){

    int temp_stor;
    string qwe ="D:\\Projects\\Project 1A\\Fund Transfer\\" + list.info[list.last].acc_no + ".txt";
    ifstream regAcc ( "D:\\Projects\\Project 1A\\Fund Transfer\\" + list.info[list.last].acc_no + ".txt");
    if(regAcc)
    {
        regAcc >> temp_stor;
        list.info[list.last].balance += temp_stor;
        cout << "\n\n\n\t\t\t     Please wait for a second ....  ";
        Sleep(1000);
        cout << "\n\n\t\t\t     Claiming Transfered Funds ....   ";
        Sleep(1500);
        cout << "\n\n\t\t\t     Successfully Claimed funds .... ";
        Sleep(1000);
        cout << "\n\n\t\t\t     Press [ENTER] to proceed ....   ";
        getch();
        regAcc.close();
        remove(qwe.c_str());
        saveinfo();

    }
}

void check_card(){

    fstream sData("E:\\data.txt", fstream::in | fstream::out | fstream::app);

    while(sData.fail()){
        sData.open("E:\\data.txt", fstream::in | fstream::out | fstream::app);
        system("cls");
        cout <<"Please Insert Card ";
    }

    sData >> list.info[list.last].acc_no >> list.info[list.last].pin >> list.info[list.last].balance;

}

string input_pin(){
    char pn;
    string newPin = "";
     int i = 0;
     while(i < 6){
        pn = getch();
        if(isdigit(pn)){
            i++;
            newPin.push_back(pn);
            putch('*');
        }
        else if(pn==8){
            i--;
            newPin.erase(newPin.length()-1);
            cout << "\b \b";

         }
        else{
            i--;
        }
    }
    return newPin;
        int amnt1=0;

        getch();
        system("cls");


    menu();
}

string check_path()
                        {
    char drive = 'D';
    string file = ":\\data.txt";
    string file_path;
    fstream check;

    do{
        drive++;
        file_path = drive + file;
        check.open(file_path, fstream::in | fstream::out | fstream::app);
        if(drive == 'H'){
            drive = 'D';
        }
        cout << "Please Insert Card";

        system("cls");
    }while(check.fail());

    return file_path;
}

void show_menu(){
    system("cls");
    cout << "\t\t\tTECHNOLOGICAL UNIVERSITY BANK " << endl;
    cout << "\t\tAccount number: " << list.info[list.last].acc_no << endl;
    cout << "\t\tInput your 6-digit pin: ";

    string vpin = input_pin();

    if(vpin == list.info[list.last].pin){
        system("cls");
        menu();
    }
    else{
        cout << "Pin mismatched... Please try again";
        getch();
        show_menu();
    }
}
