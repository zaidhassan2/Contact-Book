#include "ContactsBook.h"
#include <fstream>
#include <iostream>

ContactsBook::ContactsBook(int maxSize): maxSize(maxSize), currentSize(0) 
{
    contacts = new Contact[maxSize];
    for (int i = 0; i < maxSize; ++i)
    {
        contacts[i] = Contact();
    }
}

ContactsBook::~ContactsBook() 
{
    delete[] contacts;
}

void ContactsBook::addContact(const Contact& contact)
{
    if (currentSize < maxSize)
    {
        contacts[currentSize++] = contact;
    }
    else {
        cout << "Contacts list is full. Cannot add more contacts." << endl;
    }
}

void ContactsBook::mergeDuplicates() 
{
    for (int i = 0; i < currentSize - 1; ++i) 
    {
        for (int j = i + 1; j < currentSize; ++j)
        {
            if (contacts[i].getFirstName() == contacts[j].getFirstName() &&contacts[i].getLastName() == contacts[j].getLastName()) 
            {
                // Duplicate found, merge the two contacts (for simplicity, let's just remove the duplicate)
                for (int k = j; k < currentSize - 1; ++k) {
                    contacts[k] = contacts[k + 1];
                }
                currentSize--;
            }
        }
    }
}

void ContactsBook::storeToFile()
{
    
    ofstream outFile;
    outFile.open("contact.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < currentSize; ++i) 
        {
            outFile << "\nName : " << contacts[i].getFirstName() << "  " << contacts[i].getLastName() << "\nHome :  " << contacts[i].getAddress().getHome() << "\nStreet :  " << contacts[i].getAddress().getStreet() << "\n";
        }
        outFile.close();
        cout << "Contacts stored to file successfully." << endl;
    }
    else 
    {
        cout << "Unable to open file." << endl;
    }
}

void ContactsBook::loadFromFile() 
{
    ifstream inFile;
    inFile.open("contact.txt");
    if (inFile.is_open()) 
    {
        string firstName, lastName, home, street;
        while (inFile >> firstName >> lastName >> home >> street) 
        {
            Address address(home, street);
            Contact contact(firstName, lastName, address);
            addContact(contact);
        }
        inFile.close();
        cout << "Contacts loaded from file successfully." << endl;
    }
    else 
    {
        cout << "Unable to open file." << endl;
    }
}

void ContactsBook::printSortedContacts(const string& choice) 
{
    if (choice == "first_name") 
    {
        // Sort contacts by first name
        for (int i = 0; i < currentSize - 1; ++i)
        {
            for (int j = i + 1; j < currentSize; ++j)
            {
                if (contacts[i].getFirstName() > contacts[j].getFirstName()) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    else if (choice == "last_name") 
    {
        // Sort contacts by last name
        for (int i = 0; i < currentSize - 1; ++i) 
        {
            for (int j = i + 1; j < currentSize; ++j)
            {
                if (contacts[i].getLastName() > contacts[j].getLastName()) {
                    Contact temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    else 
    {
        cout << "Invalid choice for sorting." << endl;
        return;
    }

    // Print sorted contacts
    cout << "Sorted Contacts:\n";
    for (int i = 0; i < currentSize; ++i) 
    {
        cout << "-------------------- Contact : " << i + 1 << " ------------------------------" << endl;
        cout << "Name : " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << "\n"
            << "Address : " << contacts[i].getAddress().getHome() << "\nStreet" << contacts[i].getAddress().getStreet() << endl;
    }
}

void ContactsBook::printContacts()
{
    for (int i = 0; i < currentSize; ++i) 
    {
        cout << "-------------------- Contact : " << i + 1 <<" ------------------------------" << endl;
        cout << "Name : " << contacts[i].getFirstName() << " "
            << contacts[i].getLastName() 
            << "\nAddress : " << contacts[i].getAddress().getHome() << "\nStreet :  "
            << contacts[i].getAddress().getStreet() << endl;
    }
}

void ContactsBook::searchContacts(const string& searchTerm) 
{
    bool found = false;
    for (int i = 0; i < currentSize; ++i) 
    {
        if (contacts[i].getFirstName() == searchTerm || contacts[i].getLastName() == searchTerm)
        {
            cout << "Contact found :\n";
            cout << "Name : " << contacts[i].getFirstName() << " " << contacts[i].getLastName() << "\n"
                << "Address : " << contacts[i].getAddress().getHome() << "\nStreet :  " << contacts[i].getAddress().getStreet() << endl;
            found = true;
        }
    }
    if (!found) 
    {
        cout << "Contact not found." << endl;
    }
}

void ContactsBook::displayContactCount() 
{
    cout << "Total contacts: " << currentSize << endl;
}

void ContactsBook::addContactWithUserInput() 
{
    string firstName, lastName, home, street;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;
    cout << "Enter home: ";
    cin >> home;
    cout << "Enter street: ";
    cin >> street;

    Address address(home, street);
    Contact newContact(firstName, lastName, address);
    addContact(newContact);
}