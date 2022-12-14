#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::exit;

void introduction();
void customerCheck();
void newUser_accountCreate();
void login();
void initialBalance();
void menuLoop_main();
void show_mainMenu();
void mainOption();
void ponePoints();
void show_pointsMenu(); 
void pointsMenu_options();
void pointsPurchase(); 
void pointsBalance();
void pointsRedeem();
void show_pointsMenu_redeem();
void menuLoop_points();
void pointsMenu_options_redeem();
void redeemTravel();
void travelDelta();
void travelAmerican();
void travelAlaska();
void travelSpirit();
void redeemDining();
void redeemShopping();

int mainOption_choice;
int pointsMenu_choice;
int pointsMenu_redeem_choice;
int pointsMenu_redeem_flight_choice;
long double balance = 0;
int total_points = 0; 
const double cents_per_point = 0.7;

int main(){
    introduction();
    customerCheck();
    initialBalance();
    menuLoop_main();
}
void introduction(){
    cout << "\n\n============================\n"
         << "WELCOME TO PONE'S ONLINE ATM\n" 
         << "============================\n" << endl; 
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
    const string numbers = "0123456789";
    const string specialchar = "!@#$%^&*?";
    string username, password, choice;
    int attempt = 0, restart, confirmationRepeat = 0;
    cout << "===================\n"
         << "CREATE YOUR ACCOUNT\n"
         << "===================\n" << endl;
        do {
        system("clear");
        if (attempt > 0){
            cout << "Username does not meet the specified requirements. Please try again.\n" << endl;
        }
        cout << "Please enter your new username:" << endl;
        cout << "<<< Username must have at least 5 characters, one number, and no special characters >>>" << endl;
        cin >> username;
        attempt++;
        } while (username.size()< 5); //still need to add number and special character restrictions.
    system("clear");
    cout << "Your new username is " << "<< " << username << " >>" << "\n" << endl;

    cout << "<<< Password must have at least 8 characters, one number, and a special character >>>\n" << endl;
    cout << "Please enter your new password:" << endl;
    cin >> password;
    system("clear");
    do{
    if (password.size() < 8){
        cout << "Your password did not meet the specified requirements. Please try again.\n" << endl;
    }
    else {
        cout << "Congratulations! You have successfully created an account.\n"
             << "Please see below for your new login information.\n\n"
             << "Username: " << username << "\n"
             << "Password: " << password << "\n" << endl;
             initialBalance();
            }           
        } while (password.size() < 8); //still need to add more restrictions.
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
    abort();

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
void show_mainMenu(){
       cout << "================= MENU ==================\n\n"
        << "        1) Check balance\n"
        << "        2) Make a deposit\n"
        << "        3) Initiate a withdrawl\n"
        << "        4) PONE Points\n"
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
                cout << "$" << deposit << " is deposited into your account." << endl;
                balance += deposit;
                cout << "Your new balance is " << "$" << balance << "\n" << endl;
                break;
        case 3: cout << "Enter amount to withdraw: " << endl;
                double withdraw;
                cin >> withdraw;
                system("clear");
                if (withdraw <= balance) {
                balance -= withdraw; 
                cout << "$" << withdraw << " is withdrawn from your account.\n" << endl;
                cout << "Your new balance is " << "$" << balance << "\n" << endl;
                }
                else
                    cout << "Your withdrawal amount cannot be more than your current balance.\n"
                        << "The withdrawl was not initiated. Please try again.\n" << endl;
                break;
        case 4: ponePoints();
                break;
    }
}
void ponePoints(){
    cout << "============\n"
         << " PONE Points\n"
         << "============\n" << endl; 
    cout << "With PONE points, you can redeem the points you've earned for dining, travel experiences, purchasing merchandise, and more!\n"
         << "<< One PONE point is worth " << cents_per_point << " cents >>\n"
         << "<< Visit bankwithpone.com for more information >>\n" << endl; 
    show_pointsMenu();
    pointsMenu_options(); 
}
void show_pointsMenu(){
     cout << "================= MENU ==================\n\n"
        << "        1) Purchase PONE points\n"
        << "        2) Check points balance\n"
        << "        3) Redeem PONE points\n"
        << "        4) Return to Main Menu\n\n"
        << "==========================================" << endl;
}
void pointsMenu_options(){
    cin >> pointsMenu_choice;
    switch (pointsMenu_choice) {
        case 1: system("clear");
                pointsPurchase();
                break;
        case 2: system("clear");
                pointsBalance();
                break; 
        case 3: system("clear");
                pointsRedeem();
                break;
        case 4: system("clear");
                menuLoop_main();
                break; 
    }
}
void pointsPurchase(){
    int points_selection, points, balance_deductable;
    do{
    cout << "Please select from the following packages:\n" 
         << "1) 100 PONE points\n"
         << "2) 500 PONE points\n"
         << "3) 1000 PONE points\n"
         << "4) 5000 PONE points\n"
         << "5) Return to Main Menu\n\n" << endl;
    cin >> points_selection;
    system("clear");
    if (points_selection == 1){
        points = 100;
        balance_deductable = 100 * cents_per_point;
        if (balance_deductable <= balance){
        balance -= balance_deductable; 
        total_points += points;
        system("clear");
        cout << "You have purchased " << points << " points.\n"
             << "Your total points balance is now " << total_points << ".\n" << endl; 
        cout << "$" << balance_deductable << " has been deducted from your account.\n"
             << "Your new total balance is " << "$" << balance << "\n" << endl;
        }
        else {
            cout << "You have insufficient balance to make this purchase.\n"
                 << "The purchase was not initiated.\n" << endl;
            
        }
    }
    else if (points_selection == 2){
        points = 500;
        balance_deductable = 500 * cents_per_point;
        if (balance_deductable <= balance){
        balance -= balance_deductable; 
        total_points += points;
        system("clear");
        cout << "You have purchased " << points << " points.\n"
             << "Your total points balance is now " << total_points << ".\n" << endl; 
        cout << "$" << balance_deductable << " has been deducted from your account.\n"
             << "Your new total balance is " << "$" << balance << "\n" << endl;
        }
        else {
            cout << "You have insufficient balance to make this purchase.\n"
                 << "The purchase was not initiated.\n" << endl;
        }
    }
    else if (points_selection == 3){
        points = 1000;
        balance_deductable = 1000 * cents_per_point;
        if (balance_deductable <= balance){
        balance -= balance_deductable; 
        total_points += points;
        system("clear");
        cout << "You have purchased " << points << " points.\n"
             << "Your total points balance is now " << total_points << ".\n" << endl; 
        cout << "$" << balance_deductable << " has been deducted from your account.\n"
             << "Your new total balance is " << "$" << balance << "\n" << endl;
        }
        else {
            cout << "You have insufficient balance to make this purchase.\n"
                 << "The purchase was not initiated.\n" << endl;
        }
    }
    else if (points_selection == 4){
        points = 5000;
        balance_deductable = 5000 * cents_per_point;
        if (balance_deductable <= balance){
        balance -= balance_deductable; 
        total_points += points;
        system("clear");
        cout << "You have purchased " << points << " points.\n"
             << "Your total points balance is now " << total_points << ".\n" << endl; 
        cout << "$" << balance_deductable << " has been deducted from your account.\n"
             << "Your new total balance is " << "$" << balance << "\n" << endl;
        }
        else {
            cout << "You have insufficient balance to make this purchase.\n"
                 << "The purchase was not initiated.\n" << endl;
        }
    }
    else if (points_selection == 5){
        system("clear");
        menuLoop_main();
    }
    else {
        cout << "Invalid selection. Please select an option from the list.\n" << endl;
    }
    } while (points_selection != 1 || points_selection != 2 || points_selection != 3 || points_selection != 4); 
}
void pointsBalance(){
    cout << "Your total points balance is " << total_points << ".\n" << endl;
}
void pointsRedeem(){
    cout << "===================\n"
         << " PONE Points Redeem\n"
         << "===================\n" << endl; 
    
    cout << "How would you like to redeem your points?\n" << endl;
    show_pointsMenu_redeem();
    pointsMenu_options_redeem();
}
void show_pointsMenu_redeem(){
   cout << "==================== MENU ====================\n\n"
        << "    1) Transfer Points to Partnered Airlines\n"
        << "    2) Redeem Points for Dining Experiences\n"
        << "    3) Redeem Points for Shopping Credits\n"
        << "    4) Redeem Points for Pone's Lovinnn\n"
        << "    5) Return to Main Menu\n\n"
        << "===============================================" << endl;
}
void pointsMenu_options_redeem(){
    cin >> pointsMenu_redeem_choice;
    switch (pointsMenu_redeem_choice){
        case 1: system("clear");
                redeemTravel();
                break;
        case 2: system("clear");
                redeemDining();
                break; 
        case 3: system("clear");
                redeemShopping();
                break;
        case 4: system("clear");
                // redeemLove();
                cout << "Testing" << endl;
                break; 
        case 5: system("clear");
                menuLoop_main();
                break; 
    }
}
void redeemTravel(){
    const double points_flight_american_rate = 1.0, points_flight_alaska_rate = 1.20, points_flight_spirit_rate = 1.5;
    do{
    cout << "Which airline would you like your points redeemed to?\n" << endl;
    cout << "================= MENU ==================\n\n"
         << "        1) Delta Airlines\n"
         << "        2) American Airlines\n"
         << "        3) Alaska Airlines\n"
         << "        4) Spirit Airlines\n"
         << "        5) Return to Main Menu\n\n"
         << "==========================================" << endl;
    cin >> pointsMenu_redeem_flight_choice;
    system("clear");
    if (pointsMenu_redeem_flight_choice == 1){
        travelDelta();
    }
    else if (pointsMenu_redeem_flight_choice == 2){
        travelAmerican();
    }
    else if (pointsMenu_redeem_flight_choice == 3){
        travelAlaska();
    }  
    else if (pointsMenu_redeem_flight_choice == 4){
        travelSpirit();
    }
    else if (pointsMenu_redeem_flight_choice == 5){
        system("clear");
        menuLoop_main();
    }
    else {
        cout << "Invalid selection. Please select an option from the list.\n" << endl;
    }
    } while (pointsMenu_redeem_flight_choice != 1 || pointsMenu_redeem_flight_choice != 2 || pointsMenu_redeem_flight_choice != 3 || pointsMenu_redeem_flight_choice != 4 || pointsMenu_redeem_flight_choice != 5); 
}

void travelDelta(){
    const double points_flight_delta_rate = 0.80;
    int points, choice;
    cout << "How many points would you like to redeem?" << endl;
    cin >> points;
    system("clear");
    if (points <= total_points) {
        double points_flight_delta = points * points_flight_delta_rate;
        total_points -= points;
        cout << "You have successfully redeemed " << points << " PONE points!" << endl; 
        cout << "Your total points balance is now " << total_points << ".\n" << endl;
        cout << "Congratulations! You have transferred your PONE points!\n" 
             << "You have gained " << static_cast<double>(points_flight_delta) << " Delta SkyMiles.\n\n" << endl; 
        cout << "Would you like to transfer more PONE points?\n"
             << "1) Yes\n"
             << "2) No\n" << endl;
             cin >> choice;
        if (choice == 1){
            system("clear");
            redeemTravel();
        }
        else if (choice == 2){
            system("clear");
            menuLoop_main(); 
        }
        else {
            cout << "Invalid selection. Please select an option from the list.\n" << endl;
        }
    }
    else {
        cout << "You have insufficient points.\n"
             << "The redemption was not initiated.\n\n"
             << "To purchase PONE points, please visit PONE points menu." << endl;
    }
}
void travelAmerican(){
    const double points_flight_american_rate = 1.00;
    int points, choice;
    cout << "How many points would you like to redeem?" << endl;
    cin >> points;
    system("clear");
    if (points <= total_points) {
        double points_flight_american = points * points_flight_american_rate;
        total_points -= points;
        cout << "You have successfully redeemed " << points << " PONE points!" << endl; 
        cout << "Your total points balance is now " << total_points << ".\n" << endl;
        cout << "Congratulations! You have transferred your PONE points!\n" 
             << "You have gained " << static_cast<double>(points_flight_american) << " AAdvantage miles.\n\n" << endl;
        cout << "Would you like to transfer more PONE points?\n"
             << "1) Yes\n"
             << "2) No\n" << endl;
             cin >> choice;
        if (choice == 1){
            system("clear");
            redeemTravel();
        }
        else if (choice == 2){
            system("clear");
            menuLoop_main(); 
        }
        else {
            cout << "Invalid selection. Please select an option from the list.\n" << endl;
        } 
    }
    else{
        cout << "You have insufficient points.\n"
             << "The redemption was not initiated.\n\n"
             << "To purchase PONE points, please visit PONE points menu." << endl;
    }
}
void travelAlaska(){
    const double points_flight_alaska_rate = 1.20;
    int points, choice; 
    cout << "How many points would you like to redeem?" << endl;
    cin >> points;
    system("clear");
    if (points <= total_points) {
        double points_flight_alaska = points * points_flight_alaska_rate;
        total_points -= points;
        cout << "You have successfully redeemed " << points << " PONE points!" << endl; 
        cout << "Your total points balance is now " << total_points << ".\n" << endl;
        cout << "Congratulations! You have transferred your PONE points!\n" 
             << "You have gained " << static_cast<double>(points_flight_alaska) << " Alaska miles.\n\n" << endl;
        cout << "Would you like to transfer more PONE points?\n"
             << "1) Yes\n"
             << "2) No\n" << endl;
             cin >> choice;
        if (choice == 1){
            system("clear");
            redeemTravel();
        }
        else if (choice == 2){
            system("clear");
            menuLoop_main(); 
        }
        else {
            cout << "Invalid selection. Please select an option from the list.\n" << endl;
        } 
    }
    else{
        cout << "You have insufficient points.\n"
             << "The redemption was not initiated.\n\n"
             << "To purchase PONE points, please visit PONE points menu." << endl;
    }
}
void travelSpirit(){
    const double points_flight_spirit_rate = 1.50;
    int points, choice; 
    cout << "How many points would you like to redeem?" << endl;
    cin >> points;
    system("clear");
    if (points <= total_points) {
        double points_flight_spirit = points * points_flight_spirit_rate;
        total_points -= points;
        cout << "You have successfully redeemed " << points << " PONE points!" << endl; 
        cout << "Your total points balance is now " << total_points << ".\n" << endl;
        cout << "Congratulations! You have transferred your PONE points!\n" 
             << "You have gained " << static_cast<double>(points_flight_spirit) << " Free Spirit miles.\n\n" << endl;
        cout << "Would you like to transfer more PONE points?\n"
             << "1) Yes\n"
             << "2) No\n" << endl;
             cin >> choice;
        if (choice == 1){
            system("clear");
            redeemTravel();
        }
        else if (choice == 2){
            system("clear");
            menuLoop_main(); 
        }
        else {
            cout << "Invalid selection. Please select an option from the list.\n" << endl;
        } 
    }
    else {
        cout << "You have insufficient points.\n"
             << "The redemption was not initiated.\n\n"
             << "To purchase PONE points, please visit PONE points menu." << endl;
    }
}
void redeemDining(){
 cout << "Please select a dining experience you like your points redeemed for.\n" << endl; 
 cout << "================= MENU ==================\n\n"
      << "        1) Chick-fil-a Special\n"
      << "        2) Full course meal at a nice restaurant\n"
      << "        3) Dining at Hell's Kitchen in Las Vegas\n"
      << "        4) One on one with Pone himself\n"
      << "        5) Return to Main Menu\n\n"
      << "==========================================" << endl;
}
void redeemShopping(){
 cout << "Please select a store you like your points redeemed for.\n" << endl; 
 cout << "================= MENU ==================\n\n"
      << "        1) Zara\n"
      << "        2) Macy's \n"
      << "        3) Toys-R-Us\n"
      << "        4) Return to Main Menu\n\n"
      << "==========================================" << endl;
}
void menuLoop_main(){
    do {
    cout << "Please select one of the following options displayed in the menu.\n\n";
    show_mainMenu();
    mainOption();
    } while(mainOption_choice != 5);
    if (mainOption_choice == 5){
        cout << "Thank you for banking with PONE.\n" << "Have a wonderful day!" << endl;
        abort();
    }
}
void menuLoop_points(){
    do {
    cout << "Please select one of the following options displayed in the menu.\n\n";
    show_pointsMenu();
    pointsMenu_options();
    } while(pointsMenu_choice != 4);
    if (pointsMenu_choice == 4){
        cout << "===============================\n"
             << "Thank you for banking with PONE\n" 
             << "    Have a wonderful day!\n"
             << "===============================" << endl;
        abort();
    }
}