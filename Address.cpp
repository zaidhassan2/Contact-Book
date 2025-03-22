#include "Address.h"
Address::Address() {}

Address::Address(const string& home, const string& street) : home(home), street(street) {}

string Address::getHome() const
{
    return home;
}

string Address::getStreet() const
{
    return street;
}

void Address::setHome(const string& home)
{
    this->home = home;
}

void Address::setStreet(const string& street) 
{
    this->street = street;
}