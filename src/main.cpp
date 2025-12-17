#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.addBook();
            break;
        case 2:
            library.viewBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
