//
//  main.cpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/7/25.
//

#include <iostream>
#include "Account.hpp"

int main(int argc, const char * argv[]) {
    int accountID;
    int choice;
    int accountIDCount = 0;
    bool exit = false;
    bool found = false;
    std::vector<Account> accounts;
    std::cout << "Welcome to the banking App" << std::endl << std::endl;
    do {
        std::cout << "" << std::endl;
        std::cout << "Chose one of the folowing" << std::endl;
        std::cout << "1. Create a new account" << std::endl;
        std::cout << "2. Access an existing account" << std::endl;
        std::cout << "3. Close an account" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cin >> choice;
        switch (choice) {
            case 1: {
                std::cout << "Creating a new account" << std::endl;
                Account newAccount;
                newAccount.EstablishAccount(accountIDCount);
                accounts.push_back(newAccount);
                accountIDCount++;
                break;
            }
            case 2: {
                std::cout << "Accessing an existing account" << std::endl;
                std::cout << "Enter account ID: ";
                std::cin >> accountID;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountID() == accountID) {
                        accounts[i].AccountMenu();
                        found = true;
                        break;
                    }   
                    else {
                        found = false;
                    }
                }
                if (!found) {
                    std::cout << "Account not found" << std::endl;
                }
                break;
            }
            case 3:{
                std::cout << "Removing an existing account" << std::endl;
                std::cout << "Enter account ID: ";
                std::cin >> accountID;
                for (size_t i = 0; i < accounts.size(); i++) {
                    if (accounts[i].getAccountID() == accountID) {
                        accounts.erase(accounts.begin() + i);
                        found = true;
                        break;
                    }
                    else {
                        found = false;
                    }
                }
                if (!found) {
                    std::cout << "Account not found" << std::endl;
                }
                break;
            }
            case 4:{
                exit = true;
                break;
            }
            default:{
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    } while(!exit);    
}
