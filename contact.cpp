#include "Contact.h"

Contact::Contact() {}

Contact::Contact(const string& firstName, const string& lastName, const Address& address): firstName(firstName), lastName(lastName), address(address) {}

string Contact::getFirstName() const
{
    return firstName;
}

string Contact::getLastName() const
{
    return lastName;
}

Address Contact::getAddress() const
{
    return address;
}

void Contact::setFirstName(const string& firstName) {
    this->firstName = firstName;

}

void Contact::setLastName(const string& lastName)
{
    this->lastName = lastName;
}

void Contact::setAddress(const Address& address) 
{
    this->address = address;
}