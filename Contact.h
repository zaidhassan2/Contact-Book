#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include "Address.h"
using namespace std;

class Contact
{
private:
    string firstName;
    string lastName;
    Address address;

public:
    Contact();
    Contact(const string& firstName, const string& lastName, const Address& address);
    string getFirstName() const;
    string getLastName() const;
    Address getAddress() const;
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setAddress(const Address& address);
};

#endif // CONTACT_H
#pragma once
