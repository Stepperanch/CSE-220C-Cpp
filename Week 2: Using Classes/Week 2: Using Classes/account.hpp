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

class Account {
private:
    static int nextAccountID;
    int accountID;
    std::string name;
    float accountBalance;
public:
    Account();
    int getAccountID() const;
    std::string getName() const;
    float getAccountBalance() const;
    void EstablishAccount();
    void AccountMenu();
    void DisplayInfo();
    void Deposit(float amount);
    void Withdrawl(float amount);
    Account& operator+= (float amount);
    Account& operator-= (float amount);
    std::ostream& display(std::ostream& out) const;
};
#endif /* account_hpp */

