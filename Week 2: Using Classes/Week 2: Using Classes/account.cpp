//
//  account.cpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/7/25.
//
//#include <stdio.h>
//#include <string>
//class Account {
//private:
//    int accountID;
//    std::string name;
//    float accountBalance;
//public:
//    Account()
//    void EstablishAccount()
//    void DisplayInfo()
//    void Deposit(float amount)
//    void Withdrawl(float amount)
//    Account& operator+= (float amount)
//    Account& operator-= (float amount)
//    std::ostream& display(std::ostream& out) const;
//};


#include "Account.hpp"
#include <iostream>
#include <string>

Account::Account() {
    accountID = 0;
    name = "";
    accountBalance = 0.0;
}

int Account::getAccountID() const {
    return accountID;
}

void Account::EstablishAccount(int AccountID) {
    accountID = AccountID;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter account balance: ";
    std::cin >> accountBalance;
}

void Account::AccountMenu() {
    int choice;
    bool exit = false;
    do {
        std::cout << "Account Menu" << std::endl;
        std::cout << "1. Display account info" << std::endl;
        std::cout << "2. Deposit" << std::endl;
        std::cout << "3. Withdrawl" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                DisplayInfo();
                break;
            }
            case 2: {
                float amount;
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                Deposit(amount);
                break;
            }
            case 3: {
                float amount;
                std::cout << "Enter amount to withdrawl: ";
                std::cin >> amount;
                Withdrawl(amount);
                break;
            }
            case 4: {
                exit = true;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    } while (!exit);
}

void Account::DisplayInfo() {
    std::cout << "Account ID: " << accountID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Account balance: " << accountBalance << std::endl;
}

void Account::Deposit(float amount) {
    accountBalance += amount;
}

void Account::Withdrawl(float amount) {
    accountBalance -= amount;
}

Account& Account::operator+= (float amount) {
    accountBalance += amount;
    return *this;
}   

Account& Account::operator-=(float ammount) {
    accountBalance -= ammount;
    return *this;
}

std::ostream& Account::display(std::ostream& out) const {
    out << "Account ID: " << accountID << std::endl;
    out << "Name: " << name << std::endl;
    out << "Account balance: " << accountBalance << std::endl;
    return out;
}