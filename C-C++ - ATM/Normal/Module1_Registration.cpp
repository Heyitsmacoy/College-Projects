#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <windows.h>
#include <string>
#define MAX 6

using namespace std;
// Structure //
typedef struct INFO
{
    string fname,lname,address,birthday,accNo,age,gender;
    char pin_Code[MAX];
    int balance;

}INFO;

INFO i;

// Declaration of Functions //

void menu();
int checkATM();
void saveInfo();
string account_number();
string findDriver();

int main(void)
{
    checkATM();
    menu();
}

// Functions //
void menu()
{
    system ("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\t\t\t\t\t     REGISTRATION FORM: \n" << endl;
    cout << "\n\t\t\t Enter first name: ";
    getline (cin, i.fname);
    cout << "\n\t\t\t Enter last name: ";
    getline (cin, i.lname);
    cout << "\n\t\t\t Enter city address: ";
    getline (cin,i.address);
    cout << "\n\t\t\t Enter Birthday [MM/DD/YY]: ";
    getline (cin,i.birthday);
    cout << "\n\t\t\t Enter Gender [M/F]:  ";
    getline (cin,i.gender);
    cout << "\n\t\t\t Enter Age: ";
    getline (cin,i.age);

    while(i.balance < 100){

    cout << "\n\t\t\t Input initial balance (Minimum of 100): ";
    cin >> i.balance;

    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
}

    i.accNo = account_number();

    //checkATM();

    system("pause");
    system("cls");
    system("Module2_Transactions.exe");
}

string account_number(){

    int account_counter = 0;
    ifstream account_count("ATM.txt");
    string account_number;
    while(getline(account_count, account_number)){
        account_counter++;
    }

    string account_No;

    if(account_counter < 10){

        account_No = "TUPATM-010" + to_string(account_counter + 1);
    }else{
        account_No = "TUPATM-01" + to_string(account_counter + 1);
    }

    return account_No;
}

void saveInfo(){

    ofstream saveFile(findDriver());
    ofstream databaseFile("ATM.txt", ios::app);
    string str_PIN(i.pin_Code);
    string acc_num = account_number();

    saveFile << acc_num << " " << str_PIN << " " << i.balance << endl;

    databaseFile << acc_num << " " << str_PIN << " " << i.balance << " " << i.fname << " " << i.lname << " " << i.gender << " " << i.birthday << " " << i.address << endl;

    saveFile.close();
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

    }else{

        cout << "\n\t\t         Create your 6-digit Pin: ";

        for(int x = 0; x < 6; x++){

            i.pin_Code[x] = getch();
            if(isdigit(i.pin_Code[x])){

                i.pin_Code[x] += 30;
                putch('*');
            }else{
                x -= 1;
            }

        }
        cout << "\n\n\t\t         Encrypting password .. Please wait .... "    << endl;
        Sleep(1500);
        cout << "\n\t\t         Your Encrypted-Password is:  " << i.pin_Code << endl;
        Sleep(1500);
        cout << "\n\t\t         Account Successfully Created!  " << endl;
        Sleep(2000);
        cout << "\n\t\t         Compiling data into the database...   " << endl;
        Sleep(1500);
        cout << "\n\t\t         Press any key to continue.....   " << endl;
        getch();
        system("cls");
        saveInfo();

    }

    return 1;
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
