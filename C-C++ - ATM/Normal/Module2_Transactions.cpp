// Transaction //

#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<string>
#define MAX 8
#define p_Length 7

using namespace std;
// STRUCTURES //
typedef struct customer{

    string acc_num;
    char check_pin[p_Length];
    char pin[p_Length];
    char newpin[p_Length];
    char decrypt_pin[p_Length];
    int balance;
    int checker;
    int flag;
    int error;

}CUSTOMER;

CUSTOMER info;

// FUNCTIONS //

string findDriver();
void display_menu();
void card_queue();
void cha_pin();
void decrypt();
void transaction_menu();
void bal();
void withdraw();
void deposit();
void fund_transfer();
void claim_funds();
void printReceipt();
int  check_pin();
int  locate_drive();

// MAIN //
int main(){

    info.flag = 0;
    card_queue();

    return 0;

}

// DECLARATION OF FUNCTIONS //

void display_menu(){

    system("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t          TECHNOLOGICAL UNIVERSITY BANK               | ";
    cout << "\n\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\t          ACCOUNT NUMBER: " << info.acc_num << "                 ";
    cout << "\n\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t     Input your 6-digit pin:  ";

    decrypt();
    check_pin();

}

void card_queue(){

    info.error = 0;
    if(info.flag == 0)
    {
        while(locate_drive())
        {
            system("cls");
            Sleep(500);
            cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
            cout << "\n\t\t\t|\t                                                      | " << endl;
            cout << "\t\t\t|\t                INSERT ATM CARD                       | ";
            cout << "\n\t\t\t|\t                                                      | " << endl;
            cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            Sleep(500);
        }
    }else
    {
        while(!locate_drive())
        {
            system("cls");
            Sleep(500);
            cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
            cout << "\n\t\t\t|\t                                                      | " << endl;
            cout << "\t\t\t|\t       PLEASE WAIT FOR THE CARD TO EJECT              | ";
            cout << "\n\t\t\t|\t                                                      | " << endl;
            cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            Sleep(500);
        }
        info.flag = 0;
        card_queue();
    }
    display_menu();
}

void change_pin(){

    system ("cls");

        char newpass[p_Length];
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "\n\n\t\t\t  Enter old password: ";
        for(int i=0; i < p_Length - 1;i++){
            newpass[i] = getch();
            if(isdigit(newpass[i])){
                putch('*');
            }else{
                i-=1;
            }
        }
        if(strcmp(info.decrypt_pin,newpass)!= 0){
            Sleep(600);
            cout << "\n\n\t\t\t  Processing Password... ";
            Sleep(1000);
            cout << "\n\n\t\t\t\t Does not match old password, please try again" << endl;
            Sleep(1000);
            cout << "\n\n\t\t\t\t\t       Press [ENTER] to retry " << endl;
            cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            getch();
            change_pin();

        }else{

    system("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t\t  Processing Password... ";
    Sleep(1000);
    cout << "\n\n\t\t\t  Password Matched!  ";
    Sleep(1000);
    system("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t\t  Create new 6-digit PIN: ";
        for ( int i = 0 ; i < p_Length - 1 ; i++)
        {
            info.pin[i] = getch();
            if(isdigit(info.pin[i]))
            {
                info.pin[i] += 30;
                putch('*');
            }else{

                i -= 1;
            }
        }
        ofstream save (findDriver());
        save << info.acc_num << " " << info.pin << " " << info.balance ;

        cout << "\n\n\t\t\t   Please wait for a few seconds  ... " << endl;
        Sleep(1000);
        cout << "\n\n\t\t\t   Pin is being updated ... " << endl;
        Sleep(1500);
        cout << "\n\n\t\t\t   Pin has been successfully updated ... " << endl;
        Sleep(1000);
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "\n\n\n\t\t\t\t            [Press ENTER to return]                    " << endl;

        save.close();

        getch();
        transaction_menu();
    }
}

int locate_drive(){

   ifstream inFile;
    inFile.open(findDriver());
    if(!inFile){
        inFile.close();
        return 1;
    }else{
        inFile >> info.acc_num >> info.pin >> info.balance;
        inFile.close();
        return 0;
    }

}

void decrypt(){

    for(int i=0 ;i< p_Length - 1 ;i++){
        info.decrypt_pin[i] = info.pin[i] - 30;
    }
}

int check_pin(){

        while(info.error<3){

        char pass[p_Length];
        for(int i=0; i < p_Length - 1;i++){
            pass[i] = getch();
            if(isdigit(pass[i])){
                putch('*');
            }else{
                i-=1;
            }
        }
        if(strcmp(info.decrypt_pin,pass)!=0){

            cout << "\n\n\n\t\t\t\t Wrong Pin!";
            info.error++;
            cout << "\t\t [" << info.error << "]"  << " Error Attempt ";
            Sleep(1500);
            display_menu();

        }else{

            claim_funds();
            transaction_menu();

        }
    }

    cout << "\n\n\n\t\t\t\t     Multiple Attempts...";
    Sleep(600);
    info.flag = 1;
    Sleep(600);
    card_queue();

}

void transaction_menu(){

        system("cls");

        int ch;
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\t\t\t|\t                                                      | " << endl;
        cout << "\t\t\t|\t             : TRANSACTION MENU :                     | " << endl;
        cout << "\t\t\t|\t                                                      | " << endl;
        cout << "\t\t\t|\t             [1] Balance Inquiry                      | " << endl;
        cout << "\t\t\t|\t             [2] Deposit Money                        | " << endl;
        cout << "\t\t\t|\t             [3] Withdraw Money                       | " << endl;
        cout << "\t\t\t|\t             [4] Transfer Funds                       | " << endl;
        cout << "\t\t\t|\t             [5] Change PIN                           | " << endl;
        cout << "\t\t\t|\t             [6] Exit Machine                         | " << endl;
        cout << "\t\t\t|\t                                                      | " << endl;
        cout << "\t\t\t|\t                                                      | " << endl;
        cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\n\t\t             Please enter your choice:  ";
        cin>>ch;

        switch(ch){
        case 1: bal();break;
        case 2: deposit();break;
        case 3: withdraw();transaction_menu();break;
        case 4: fund_transfer();break;
        case 5: change_pin();break;
        case 6: exit(0);break;
        default:
            system("cls");
            cout << "\n\n\n\n\n\n\t\t             Please choose from 1-6 only ....  " << endl;
            getch();
            transaction_menu();
        }
 }

void bal(){

    system ("cls");
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t             : Balance Inquiry :                      | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\t              Balance:    P" << info.balance  << "                         " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t            [Press ENTER to return]                   | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    getch();
    transaction_menu();

 }

void withdraw(){

    system ("cls");
    int wth;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t             : Withdraw Option :                      | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\t\t\t   Enter the amount you want to withdraw:     ";
    cin >> wth;
    if(wth % 100 != 0){
        system("cls");
        cout << "\n\n\n\n\n\n\t\t             Minimum of 100 pesos only ....  " << endl;
        getch();
        withdraw();
    }else{
        info.balance -= wth;
        if(info.balance < 100){
           system("cls");
            cout << "\n\n\n\n\n\n\t\t             Minimum Withdraw must be above initial balance  ....  " << endl;
            getch();
            info.balance += wth;
            withdraw();
        }else{

        cout << "\n\n\t\t             Please wait ....  " << endl;
        Sleep(600);
        cout << "\n\n\t\t             Money is being process ....  " << endl;
        Sleep(2000);
        cout << "\n\n\t\t             Withdraw Successfully....  " << endl;
        Sleep(1500);

        ofstream save(findDriver());
        save << info.acc_num << " " << info.pin << " " << info.balance <<endl;
        cout << "\n\t\t\t\t             Press[ENTER] to see receipt               " << endl;
        getch();
        printReceipt();

        }
    }
    getch();
    system("cls");
    transaction_menu();
}

void deposit(){
    system("cls");
    int dp;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t|\t             : Deposit Option :                       | " << endl;
    cout << "\t\t\t|\t                                                      | " << endl;
    cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\t\t\t   Enter the amount you want to deposit:     ";
    cin>>dp;
    if(dp % 100 != 0){
        system("cls");
        cout << "\n\n\n\n\n\n\t\t             Minimum of 100 pesos only ....  " << endl;
        getch();
        deposit();

    }else{

        info.balance += dp;
        cout << "\n\n\t\t             Please wait ....  " << endl;
        Sleep(600);
        cout << "\n\n\t\t             Money is being process ....  " << endl;
        Sleep(2000);
        cout << "\n\n\t\t             Deposit Successfully....  " << endl;
        Sleep(1500);

        ofstream save(findDriver());
        save << info.acc_num << " " << info.pin << " " << info.balance <<endl;
        cout << "\n\t\t\t\t           [Press ENTER to check balance]                 " << endl;
        bal();

}
        system("cls");
        transaction_menu();
}

void fund_transfer()
{
        system("cls");
        string name;
        int amount,amount2;
            cout << "\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            cout << "\n\n\t\t\t   Enter account number:   ";
            cin >> name;
            cout << "\n\t\t\t   Enter the amount to transfer:  ";
            cin >> amount;
            cout << "\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
            cout << "\n\n\t\t\t     Press [ENTER] to proceed .. ";
            getch();

            ifstream accountFile ("D:\\Programming\\Project\\Fund Transfer\\" + name + ".txt");
            if (accountFile)
            {
                accountFile >> amount2;
                amount += amount2;
            }

            ofstream accountsave ("D:\\Programming\\Project\\Fund Transfer\\" + name + ".txt");
            accountsave << amount << endl;

            getch();
            accountFile.close();
            transaction_menu();

}

void claim_funds(){

    int temp_stor;
    string qwe ="D:\\Programming\\Project\\Fund Transfer\\" + info.acc_num + ".txt";
    ifstream regAcc ( "D:\\Programming\\Project\\Fund Transfer\\" + info.acc_num + ".txt");
    if(regAcc)
    {
        regAcc >> temp_stor;
        info.balance += temp_stor;
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
    }
}

string findDriver(){

    char drive = 'D';
    string path = ":\\data.txt";
    fstream driver;

    do{
        drive++;
        driver.open(drive + path, fstream::in | fstream::out | fstream::app);
        if(drive == 'H'){
        system("cls");
        drive = 'D';
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
        cout << "\n\n\t\t\t\t\t       Please Insert Card \n" << endl;
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;

        }

    }while(driver.fail());

    string file_path = drive + path;
    return file_path;

}

void printReceipt()
{
    system("cls");

    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t         THANKYOU FOR BANKING WITH TUB! \n" << endl;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    cout << "\n\n\t\t\t\t\t     : OFFICIAL RECEIPT : \n" << endl;
    cout << "\n\t\t\t\t\t     Current Balance: " << info.balance;
    cout << "\n\n\n\n\n\t\t\t\t           Press [ENTER] to exit....   " << endl;
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" << endl;
    getch();
    exit(0);
}
