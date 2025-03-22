#ifndef CONTACTSBOOK_H
#define CONTACTSBOOK_H

#include "Contact.h"
#include <iostream>
using namespace std;

class ContactsBook 
{
private:
    Contact* contacts;
    int maxSize;
    int currentSize;

public:
    ContactsBook(int maxSize);
    ~ContactsBook();
    void addContact(const Contact& contact);
    void mergeDuplicates();
    void storeToFile();
    void loadFromFile();
    void printSortedContacts(const string& choice);
    void printContacts();
    void searchContacts(const string& searchTerm);
    void displayContactCount();
    void addContactWithUserInput();
    void searchContactsByUserInput();
};

#endif // CONTACTSBOOK_H
#pragma once
#pragma once
