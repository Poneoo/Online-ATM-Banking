#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using std::string;

void introduction();
void customerCheck();
void newUser_accountCreate();
void login();
void initialBalance();
void menuLoop();
void showMenu();
void mainOption();

int mainOption_choice;
long double balance = 0;

int main(){
    introduction();
    customerCheck();
    initialBalance();
    menuLoop();
}
void introduction(){
    cout << "\n\n====================================\n"
         << "WELCOME TO PONE'S ONLINE ATM MACHINE\n" 
         << "====================================\n" << endl; 
}
void customerCheck(){
    int startOption;
    do {cout << "Are you a new customer or an existing customer?\n"
         << "1) New Customer\n"
         << "2) Existing Customer\n";
    cin >> startOption;
    system("clear");
    if (startOption == 1){
        newUser_accountCreate();
        break;
    }
    else if (startOption == 2){
        login();
        break;
    }
    else {
        cout << "Invalid selection. Please select an option from the list.\n" << endl;
    }
    } while (startOption != 1 || startOption != 2);
}

void newUser_accountCreate(){
    // NEEDS WORK
    string username, password;
    cout << "===================\n"
         << "CREATE YOUR ACCOUNT\n"
         << "===================\n" << endl;
    cout << "Please enter your new username: " << endl;
    cin >> username;
    system("clear");
    cout << "Please enter your new password: " << endl;
    // cout << "<<< Password must have at least one number and a special character >>>" << endl;
    cin >> password;
    system("clear");
    cout << "Congratulations! You have successfully created an account.\n"
         << "Please see below for your new login information.\n\n"
         << "Username: " << username << "\n"
         << "Password: " << password << "\n" << endl;
    // cout << "Press Enter to continue." << endl;
    // cin.ignore();
    return;

}
void login(){
    string existingUsername = "Dummy", existingPassword = "404", username, password;
    int attempts = 3;
    while (attempts > 0){
    cout << "=======\n"
         << " LOGIN\n"
         << "=======\n" << endl; 
    cout << "Please enter your username. " << endl;
    cin >> username;
    cout << "Please enter your password. " << endl; 
    cin >> password;
    if (username == existingUsername && password == existingPassword){
        system("clear");
        cout << "You are now logged in.\n" << endl;
        return;
    }
    else if (attempts == 2){
        //singular "attempt" in cout 
        system("clear");
        attempts--;
        cout << "Incorrect username or password. You have " << attempts << " attempt remaining." << endl; 
    }
    else {
        system("clear");
        attempts--;
        cout << "Incorrect username or password. You have " << attempts << " attempts remaining." << endl;
    }
    }
    cout << "Too many failed attempts. Please try logging in again in an hour. " << endl;
    abort(); // program terminates here

}
void initialBalance(){
    int startOption;
    if (startOption == 1) {
        cout << "Welcome! Please enter the amount you would be depositing today." << endl;
        cin >> balance;
        system("clear");
        cout << "You have deposited " << "$" << balance << "\n" << endl;
    }
    else if (startOption == 2) {
        balance += 2000;
        cout << "Welcome back!" << endl;
        cout << "Your current balace is " << "$" << balance << "\n" << endl;
    }
}
void menuLoop(){
    do {
    cout << "Please select one of the following options displayed in the menu.\n\n";
    showMenu();
    mainOption();
    } while(mainOption_choice != 5);
    if (mainOption_choice == 5){
        cout << "Thank you for banking with Pone.\n" << "Have a wonderful day!" << endl;
        abort();
    }
}
void showMenu(){
       cout << "================= MENU ==================\n\n"
        << "        1) Check balance\n"
        << "        2) Make a deposit\n"
        << "        3) Initiate a withdrawl\n"
        << "        4) Purchase PONE Points\n"
        << "        5) Exit\n\n"
        << "==========================================" << endl;
}
void mainOption(){
    cin >> mainOption_choice;
    system("clear");
    switch(mainOption_choice){
        case 1: cout << "Total Balance: " << "$" << balance << "\n" << endl; 
                break;
        case 2: cout << "Enter amount to deposit: " << endl;
                double deposit;
                cin >> deposit;
                system("clear");
                cout << deposit << " is deposited into your account." << endl;
                balance += deposit;
                cout << "Your new balance is " << "$" << balance << "\n" << endl;
                break;
        case 3: cout << "Enter amount to withdraw: " << endl;
                double withdraw;
                cin >> withdraw;
                system("clear");
                if (withdraw <= balance) {
                balance -= withdraw; 
                cout <<  withdraw << " is withdrawn from your account.\n" << endl;
                cout << "Your new balance is " << "$" << balance << "\n" << endl;
                }
                else
                    cout << "Your withdrawal amount cannot be more than your current balance.\n"
                        << "Please try again.\n" << endl;
                break;
    }
}