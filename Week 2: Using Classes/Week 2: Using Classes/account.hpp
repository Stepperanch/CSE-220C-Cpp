//
//  account.hpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/7/25.
//

#ifndef account_hpp
#define account_hpp


#include <stdio.h>
#include <string>
#include <list>
#include "Contact.hpp"
#include <memory>

using std::shared_ptr;
using std::string;
using std::ostream;

class Account {
private:
    static int nextAccountID;
    int accountID;
    string name;
    float accountBalance;
    shared_ptr<Contact> contact;
public:
    Account();
    void AddContact();
    int getAccountID() const;
    string getName() const;
    float getAccountBalance() const;
    void EstablishAccount();
    void AccountMenu();
    void DisplayInfo();
    void Deposit(float amount);
    void Withdrawl(float amount);
    Account& operator+= (float amount);
    Account& operator-= (float amount);
    ostream& display(ostream& out) const;
};
#endif /* account_hpp */

