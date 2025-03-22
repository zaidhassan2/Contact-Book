#include <iostream>
#include<cstring>
#include<string>
#include "ContactsBook.h" 
using namespace std;
int main()
{
    ContactsBook contactsBook(5); // Create a ContactsBook object with size 5

    int choice;
    do 
    {
        cout << "\n------------------------------------------ MENU : ----------------------------------------\n"<<"Enter\n"
            << " 1. Create contacts list from given size\n"
            << " 2. Add New Contact\n"
            << " 3. Merge Duplicates\n"
            << " 4. Store To File\n"
            << " 5. Load From File\n"
            << " 6. Print Contacts Sorted\n"
            << " 7. Print Contacts Unsoretd\n"
            << " 8. Search contacts\n"
            << " 9. Display Count of Contacts\n"<<" 10. Add 5 contacts\n"
            << " 0. Exit\n"
            << "Enter your choice :  ";
        cin >> choice;

        switch (choice) 
        {
        case 1: 
        {
            int size;
            cout << "Enter size of contacts list: ";
            cin >> size;
            contactsBook = ContactsBook(size);
            cout << "\n==================================================================================\n";
            break;
        }
        case 2: 
        {
            contactsBook.addContactWithUserInput();
            cout << "\n===================================================================================\n";
            break;
        }
        case 3: 
        {

            contactsBook.mergeDuplicates();
            cout << "\n===================================================================================\n";
            break;
        }
        case 4: 
        {
            
            contactsBook.storeToFile();
            cout << "\n===================================================================================\n";
            break;
        }
        case 5: 
        {
          
            contactsBook.loadFromFile();
            cout << "\n===================================================================================\n";
            break;
        }
        case 6: 
        {
            string choice;
            cout << "Enter choice for sorting (first_name/last_name): ";
            cin >> choice;
            contactsBook.printSortedContacts(choice);
            cout << "\n===================================================================================\n";
            break;
        }
        case 7: 
        {
            contactsBook.printContacts();
            cout << "\n===================================================================================\n";
            break;
        }
        case 8: 
        {
            string searchTerm;
            cout << "Enter search term: ";
            cin >> searchTerm;
            contactsBook.searchContacts(searchTerm);
            cout << "\n===================================================================================\n";
            break;
        }
        case 9: 
        {
            contactsBook.displayContactCount();
            cout << "\n===================================================================================\n";
            break;
        }
        case 10:
        {
            cout << "Adding 5 contacts:\n";
            for (int i = 0; i < 5; ++i) {
                cout << "Contact " << i + 1 << ":\n";
                contactsBook.addContactWithUserInput();
            }
            break;
        }
        case 0: 
        {
            cout << "Exiting program.\n";
            cout << "\n===================================================================================\n";
            break;
        }
        default:
        {
            cout << "Invalid choice. Please enter a number between 0 and 9.\n";
            cout << "\n===================================================================================\n";
            break;
        }
        }
    } while (choice != 0);

    system("pause");
    return 0;
}