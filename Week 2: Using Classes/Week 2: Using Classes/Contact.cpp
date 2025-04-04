//
//  Contact.cpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/31/25.
//

#include "Contact.hpp"
#include <iostream>

using std::string, std::cout, std::endl, std::cin, std::getline, std::numeric_limits, std::streamsize;



Contact::Contact() {
    streetAdress = "";
    city = "";
    state = "";
    zipCode = "";
    phoneNumber = "";
}

void Contact::SetInfo() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    cout << "Enter street address: (eg. 1234 Main St) ";
    getline(cin, streetAdress);
    
    cout << "Enter city: ";
    getline(cin, city);
    
    cout << "Enter state: ";
    getline(cin, state);
    
    cout << "Enter zip code: ";
    getline(cin, zipCode);
    
    cout << "Enter phone number: ";
    getline(cin, phoneNumber);
}

void Contact::DisplayInfo() {
    cout << "  Contact Information:" << endl;
    cout << "    Street Address: " << streetAdress << endl;
    cout << "    City: " << city << endl;
    cout << "    State: " << state << endl;
    cout << "    Zip Code: " << zipCode << endl;
    cout << "    Phone Number: " << phoneNumber << endl;
}
    
