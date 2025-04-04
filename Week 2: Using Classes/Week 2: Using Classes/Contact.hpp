//
//  Contact.hpp
//  Week 2: Using Classes
//
//  Created by Nels Buhrley  on 3/31/25.
//

#ifndef Contact_hpp
#define Contact_hpp

#include <stdio.h>
#include <string>

#endif /* Contact_hpp */

class Contact {
    private:
        std::string streetAdress;
        std::string city;
        std::string state;
        std::string zipCode;
        std::string phoneNumber;
    public:
        Contact();
        void SetInfo();
        void DisplayInfo();

};