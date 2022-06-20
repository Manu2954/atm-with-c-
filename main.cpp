#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>

using namespace std;

  string name, pswdd;
  int opt,dup,acctBalance=500,withDraw,deposit,chk=10;
  string paswd[24]={"2459","2495","2549","2594","2954","2945","4259","4295","4529","4592","4925","4952","5249","5294","5429","5492","5924","5942","9254","9245","9425","9452","9524","9542"};
  char pin[4];

string passwrdEnter(){

    cout<< "Enter your 4 digit pin to continue : ";
    for(int i=0; i<5;i++){
        pin[i]=getch();
        cout<<"*";
        if(pin[i]=='\r')
            break;
        else if(pin[i]=='\b'){
            if(i==0)
                cout<<"\b"<<" "<<"\b";
            else if(i>=1){
                pin[i-1]='\0';
                i=i-2;
                cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
            }
         }
    }
    pin[4]='\0';

    string pswd=pin;
    return pswd;
}

void runLoop();

void welcome(){
    cout<<"\n\n\n\n\n\                                             WELCOME TO MY_BANK !!!\n";
    Sleep(2500);
    system("cls");
}

void intro(){
    cout<< "Enter the account holder's name : ";
    cin>>name;
    while(chk!=11){
        pswdd=passwrdEnter();
        for(int i=0;i<24;i++){
            if(pswdd==paswd[i]){
                chk=11;
                break;
            }
            else chk=10;
        }
        if(chk==10){
            system("cls");
            cout<<"Wrong password TRY AGAIN!!! \n";
        }
    }
    system("cls");
    if(chk==11)
    cout<< "Hello "<<name<<endl;

}

void menu(){
    cout<<endl;
    cout<< "  ********************MENU************************\n";
    cout<< "  *                                              *\n";
    cout<< "  *  1.View Account Balance                      *\n";
    cout<< "  *  2.Deposit Money                             *\n";
    cout<< "  *  3.WithDraw Money                            *\n";
    cout<< "  *  4.Exit                                      *\n";
    cout<< "  *  5.Leave the Bank                            *\n";
    cout<< "  *                                              *\n";
    cout<< "  ************************************************\n";
    cout<<endl;
}

void switchLoop(){
switch(opt){
        case 1: cout<< "Account Balance = "<<acctBalance<<endl;
        break;

        case 2: cout<< "Enter the amount you want to deposit = ";
                cin>> deposit;
                acctBalance += deposit;
                dup = acctBalance;
        break;

        case 3: cout<< "Enter the amount you want to withdraw = ";
                cin>> withDraw;
                if(acctBalance>=withDraw){
                        acctBalance-=withDraw;
                        dup = acctBalance;
                cout<< "Your money of " << withDraw << " withdrawn you can take from the casher\n";}
                else{ cout<< "you don't have enough money , you have only "<< dup <<endl;}
        break;

        case 4: chk=10; runLoop();
        break;

        default: if(opt!=5)cout<< "\n\n***Enter an option from 1 to 5 ***\n";}
}

void mainLoop(){
  do{
        cout<< "\n\n choose one of the below options to proceed further\n";
        menu();
        cout<<"Enter the option to avail service from the MENU : ";
        cin>>opt;
        system("cls");
        switchLoop();
        cout<<endl;
        if(opt==5)break;

    }while(opt!=4);
}

void runLoop(){
    do{
        if(opt==5)break;
        welcome();
        intro();
        if(chk==11){
            mainLoop();
            switchLoop();
        }
        else {break;}
    }while(opt!=4||opt!=5);
}

int main()
{
    dup = acctBalance;
    runLoop();
    cout<< "\n\nThank you :) visit Again!!"<<endl;
    cout<<endl;
    cout<<endl;

    return 0;
}
