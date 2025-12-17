#include <iostream>
#include "Library.h"
using namespace std;

int main()
{
    Library library;
    library.loadData();

    int role;
    cout << "===== Welcome to Library Management System =====\n";
    cout << "Select your role:\n";
    cout << "1. Admin\n";
    cout << "2. User\n";
    cout << "Enter choice: ";
    cin >> role;

    while (role != 1 && role != 2)
    {
        cout << "Invalid choice! Enter 1 for Admin or 2 for User: ";
        cin >> role;
    }

    if (role == 1)
    {
        cout << "\nLogged in as Admin\n";
    }
    else
    {
        cout << "\nLogged in as User\n";
    }

    int choice;
    if (role == 1)
    {
        do
        {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            cout << "\n===== Admin Menu =====\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Search Book\n";
            cout << "4. Add User\n";
            cout << "5. View Users\n";
            cout << "6. Borrow Book\n";
            cout << "7. Return Book\n";
            cout << "8. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();            // clear error flag
                cin.ignore(1000, '\n'); // discard invalid input
                cout << "Invalid input! Try again.\n";
                continue; // go back to the menu loop
            }

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
                library.addUser();
                break;
            case 5:
                library.viewUsers();
                break;
            case 6:
                library.borrowBook();
                break;
            case 7:
                library.returnBook();
                break;
            case 8:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 8);
    }

    else
    { // role == 2
        do
        {
#ifdef _WIN32
            system("cls");
#else
            system("clear");
#endif
            cout << "\n===== User Menu =====\n";
            cout << "1. View Books\n";
            cout << "2. Search Book\n";
            cout << "3. Borrow Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;
            if (cin.fail())
            {
                cin.clear();            // clear error flag
                cin.ignore(1000, '\n'); // discard invalid input
                cout << "Invalid input! Try again.\n";
                continue; // go back to the menu loop
            }

            switch (choice)
            {
            case 1:
                library.viewBooks();
                break;
            case 2:
                library.searchBook();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
            }
        } while (choice != 5);
    }

    return 0;
}
