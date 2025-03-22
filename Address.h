#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

class Address
{
private:
    string home;
    string street;

public:
    Address();
    Address(const string& home, const string& street);
    string getHome() const;
    string getStreet() const;
    void setHome(const string& home);
    void setStreet(const string& street);
};

#endif // ADDRESS_H
#pragma once
#pragma once
