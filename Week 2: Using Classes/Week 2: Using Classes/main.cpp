//
//  main.cpp
//  Week 4: Using Classes
//
//  Created by Nels Buhrley  on 3/7/25.
//

#include <iostream>
#include "Account.hpp"
#include <list>
#include <thread>
#include <chrono>
#include <algorithm>
#include <numeric>

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

void pressAnyKey() {
    std::cout << "Press any key to continue...";
    std::cin.ignore();
    std::cin.get();
}

std::list<Account>::iterator find_account(std::list<Account>& accounts, int accountID) {
    std::list<Account>::iterator it;
    for (it = accounts.begin(); it != accounts.end(); it++) {
        if (it->getAccountID() == accountID) {
            return it;
        }
    }
    return accounts.end();
}

void access_account(std::list<Account>& accounts, int accountID) {
    auto account = find_account(accounts, accountID);
    if (account != accounts.end()) {
        account->AccountMenu();
    }
    else {
        std::cout << "Account not found" << std::endl;
    }
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
        std::cout << "5. Total Value in Bank" << std::endl;
        std::cout << "6. Pay Dividends" << std::endl;
        std::cout << "7. Exit" << std::endl;
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
                access_account(accounts, accountID);
                break;
            }
            case 3:{
                std::cout << "Removing an existing account" << std::endl;
                for (auto account : accounts) {
                    std::cout << "Account ID: " << account.getAccountID() << " Name: " << account.getName() << std::endl;
                }
                std::cout << "Enter account ID: ";
                std::cin >> accountID;
                auto remove_account = remove_if(accounts.begin(), accounts.end(), [accountID](Account& account) {
                    return account.getAccountID() == accountID;
                });
                if (remove_account != accounts.end()) {
                    remove_account->DisplayInfo();
                    accounts.erase(remove_account, accounts.end());
                    std::cout << "Account removed" << std::endl;
                }
                else {
                    std::cout << "Account not found" << std::endl;
                }
                break;
            }
            case 4:{
                std::cout << "Displaying all accounts\n" << std::endl;
                display_all_accounts(accounts);
                pressAnyKey();
                break;
            }
            case 5:{
                float total = accumulate(accounts.begin(), accounts.end(), 0.0f,[](auto accumulator, auto& accounts) {
                    return accumulator + accounts.getAccountBalance();
                });
                std::cout << "Total value in bank: " << total << std::endl;
                break;
            }
            case 6:{
                std::cout << "Paying dividends" << std::endl;
                std::cout << "Enter the dividend percentage: " << std::endl << ">";
                float dividend;
                std::cin >> dividend;
                transform(accounts.begin(), accounts.end(), accounts.begin(), [dividend](auto& account) {
                    account += account.getAccountBalance() * dividend * 0.01;
                    return account;
                });
                break;
            }
            case 7:{
                exit = true;
                std::cout << "Thank you for using the banking app" << std::endl;
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

    return 0;
}
