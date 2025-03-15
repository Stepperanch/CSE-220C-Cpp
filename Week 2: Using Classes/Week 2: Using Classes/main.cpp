//
//  main.cpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/7/25.
//

#include <iostream>
#include "Account.hpp"
#include <list>
#include <thread>
#include <chrono>

std::list<Account>::iterator find_account(std::list<Account>& accounts, int accountID) {
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (it->getAccountID() == accountID) {
            return it;
        }
    }
    return accounts.end();
}

void display_all_accounts(std::list<Account>& accounts) {
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        it->DisplayInfo();
        std::cout << std::endl;
    }
}

void clear() {
    std::cout << std::string(100, '\n');
}

int main(int argc, const char * argv[]) {
    clear();
    int accountID;
    bool exit = false;
    std::list<Account> accounts;
    std::cout << "Welcome to the banking App" << std::endl << std::endl;
    do {
        int choice;
        std::cout << "\nChose one of the following" << std::endl;
        std::cout << "1. Create a new account" << std::endl;
        std::cout << "2. Access an existing account (Deposit, Withdrawl, View Info)" << std::endl;
        std::cout << "3. Close an account" << std::endl;
        std::cout << "4. Display all accounts" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> choice;
        clear();
        std::cout << "Choice: " << choice << std::endl;
        switch (choice) {
            case 1: {
                std::cout << "Creating a new account" << std::endl;
                Account newAccount;
                newAccount.EstablishAccount();
                accounts.push_back(newAccount);
                break;
            }
            case 2: {
                std::cout << "Accessing an existing account" << std::endl;
                std::cout << "Enter account ID: ";
                std::cin >> accountID;
                std::list<Account>::iterator it = find_account(accounts, accountID);
                if (it != accounts.end()) {
                    clear();
                    it->AccountMenu();
                } else {
                    std::cout << "Account not found" << std::endl;
                }
                break;
            }
            case 3:{
                std::cout << "Removing an existing account" << std::endl;
                std::cout << "Enter account ID: ";
                std::cin >> accountID;
                std::list<Account>::iterator it = find_account(accounts, accountID);
                if (it != accounts.end()) {
                    std::cout << "Removing: " << std::endl;
                    it->DisplayInfo();
                    accounts.erase(it);
                    std::cout << "\nPress any key to continue...";
                    std::cin.ignore();
                    std::cin.get();
                } else {
                    std::cout << "Account not found" << std::endl;
                }
                break;
            }
            case 4:{
                std::cout << "Displaying all accounts\n" << std::endl;
                display_all_accounts(accounts);
                std::cout << "Press any key to continue...";
                std::cin.ignore();
                std::cin.get();
                break;
            }
            case 5:{
                exit = true;
                break;
            }
            default:{
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
        
        if (!exit) {
            std::cout << "\nReturning to main menu..." << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            clear();
        }
    } while(!exit);    
}
